#!/usr/bin/env python3
import re
import sys


RTL_RE = re.compile(r"pc=0x([0-9a-fA-F]+)\s+instr=0x([0-9a-fA-F]+)(?:\s+rd=x(\d+)\s+data=0x([0-9a-fA-F]+))?")
SPIKE_PC_RE = re.compile(r"core\s+\d+:\s+0x([0-9a-fA-F]+)\s+\(0x([0-9a-fA-F]+)\)")
SPIKE_RD_RE = re.compile(r"core\s+\d+:\s+3\s+0x([0-9a-fA-F]+)\s+\(0x([0-9a-fA-F]+)\)\s+x(\d+)\s+0x([0-9a-fA-F]+)")
EBREAK = 0x00100073


def parse_rtl(path):
    events = []
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            m = RTL_RE.search(line)
            if not m:
                continue
            pc = int(m.group(1), 16)
            instr = int(m.group(2), 16)
            rd = int(m.group(3)) if m.group(3) else 0
            data = int(m.group(4), 16) if m.group(4) else 0
            events.append((pc, instr, rd, data))
            if instr == EBREAK:
                break
    return events


def parse_spike(path):
    events = []
    pending = None
    with open(path, "r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            m_pc = SPIKE_PC_RE.search(line)
            if m_pc:
                if pending is not None:
                    events.append(pending)
                    if pending[1] == EBREAK:
                        return [tuple(x) for x in events]
                pending = [int(m_pc.group(1), 16), int(m_pc.group(2), 16), 0, 0]
                continue

            m_rd = SPIKE_RD_RE.search(line)
            if m_rd and pending is not None:
                pending[2] = int(m_rd.group(3))
                pending[3] = int(m_rd.group(4), 16) & 0xFFFFFFFF

    if pending is not None:
        events.append(tuple(pending))
    return [tuple(x) for x in events]


def main():
    if len(sys.argv) != 3:
        print("Usage: compare_trace.py <rtl_trace.log> <spike_trace.log>")
        return 1

    rtl = parse_rtl(sys.argv[1])
    spike = parse_spike(sys.argv[2])

    if not rtl:
        print("RTL trace is empty")
        return 4
    if not spike:
        print("Spike trace is empty")
        return 5

    start = -1
    key_pc, key_instr = rtl[0][0], rtl[0][1]
    for i, evt in enumerate(spike):
        if evt[0] == key_pc and evt[1] == key_instr:
            start = i
            break
    if start < 0:
        print("Unable to align traces: first RTL retire not found in Spike trace")
        return 6

    spike_aligned = spike[start:]
    n = min(len(rtl), len(spike_aligned))
    for i in range(n):
        if rtl[i] != spike_aligned[i]:
            print(f"Mismatch at retire index {i}:")
            print(f"  RTL  : pc=0x{rtl[i][0]:08x} instr=0x{rtl[i][1]:08x} rd=x{rtl[i][2]} data=0x{rtl[i][3]:08x}")
            print(f"  Spike: pc=0x{spike_aligned[i][0]:08x} instr=0x{spike_aligned[i][1]:08x} rd=x{spike_aligned[i][2]} data=0x{spike_aligned[i][3]:08x}")
            return 2

    if len(rtl) != len(spike_aligned):
        print(f"Length mismatch: rtl={len(rtl)} spike_aligned={len(spike_aligned)}")
        return 3

    print(f"Trace match OK: {len(rtl)} retired instructions")
    return 0


if __name__ == "__main__":
    sys.exit(main())
