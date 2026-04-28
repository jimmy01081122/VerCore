.section .text
.globl _start

_start:
    addi x1, x0, 5
    addi x2, x0, 7
    add  x3, x1, x2
    add  x4, x3, x1
    add  x5, x4, x3

    lui  x10, 0x80000
    addi x10, x10, 0x100
    sw   x5, 0(x10)
    lw   x6, 0(x10)
    add  x7, x6, x1

    beq  x7, x0, branch_fail
    addi x8, x0, 1
    beq  x8, x8, branch_pass

branch_fail:
    addi x9, x0, 0x55
    j done

branch_pass:
    addi x9, x0, 0x2a

done:
    ebreak
