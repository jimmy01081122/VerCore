// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvercore_top.h for the primary calling header

#include "Vvercore_top.h"
#include "Vvercore_top__Syms.h"

//==========

void Vvercore_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vvercore_top::eval\n"); );
    Vvercore_top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vvercore_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/a/agentcore/vercore_sandbox/rtl/vercore_top.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vvercore_top::_eval_initial_loop(Vvercore_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/a/agentcore/vercore_sandbox/rtl/vercore_top.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vvercore_top::_sequent__TOP__2(Vvercore_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvercore_top::_sequent__TOP__2\n"); );
    Vvercore_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__vercore_top__DOT__drop_icache_resp;
    CData/*4:0*/ __Vdlyvdim0__vercore_top__DOT__u_regfile__DOT__regs__v0;
    CData/*0:0*/ __Vdlyvset__vercore_top__DOT__u_regfile__DOT__regs__v0;
    CData/*0:0*/ __Vdlyvset__vercore_top__DOT__u_regfile__DOT__regs__v1;
    IData/*31:0*/ __Vdlyvval__vercore_top__DOT__u_regfile__DOT__regs__v0;
    WData/*127:0*/ __Vtemp3[4];
    WData/*191:0*/ __Vtemp9[6];
    WData/*95:0*/ __Vtemp10[3];
    WData/*223:0*/ __Vtemp14[7];
    // Body
    __Vdly__vercore_top__DOT__drop_icache_resp = vlTOPp->vercore_top__DOT__drop_icache_resp;
    __Vdlyvset__vercore_top__DOT__u_regfile__DOT__regs__v0 = 0U;
    __Vdlyvset__vercore_top__DOT__u_regfile__DOT__regs__v1 = 0U;
    if (vlTOPp->rst_n) {
        if (vlTOPp->vercore_top__DOT__branch_taken_e) {
            __Vdly__vercore_top__DOT__drop_icache_resp = 1U;
        } else {
            if (((IData)(vlTOPp->vercore_top__DOT__drop_icache_resp) 
                 & (IData)(vlTOPp->icache_valid))) {
                __Vdly__vercore_top__DOT__drop_icache_resp = 0U;
            }
        }
    } else {
        __Vdly__vercore_top__DOT__drop_icache_resp = 0U;
    }
    if (vlTOPp->rst_n) {
        if (vlTOPp->vercore_top__DOT__flush_d) {
            vlTOPp->vercore_top__DOT__ifid_q[0U] = 0U;
            vlTOPp->vercore_top__DOT__ifid_q[1U] = 0U;
            vlTOPp->vercore_top__DOT__ifid_q[2U] = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->vercore_top__DOT__stall_d)))) {
                vlTOPp->vercore_top__DOT__ifid_q[0U] 
                    = (IData)((((QData)((IData)(vlTOPp->vercore_top__DOT__pc_f)) 
                                << 0x20U) | (QData)((IData)(vlTOPp->icache_rdata))));
                vlTOPp->vercore_top__DOT__ifid_q[1U] 
                    = (IData)(((((QData)((IData)(vlTOPp->vercore_top__DOT__pc_f)) 
                                 << 0x20U) | (QData)((IData)(vlTOPp->icache_rdata))) 
                               >> 0x20U));
                vlTOPp->vercore_top__DOT__ifid_q[2U] 
                    = vlTOPp->vercore_top__DOT__icache_accept_valid;
            }
        }
    } else {
        vlTOPp->vercore_top__DOT__ifid_q[0U] = 0U;
        vlTOPp->vercore_top__DOT__ifid_q[1U] = 0U;
        vlTOPp->vercore_top__DOT__ifid_q[2U] = 0U;
    }
    if (vlTOPp->rst_n) {
        if (((IData)(vlTOPp->vercore_top__DOT____Vcellinp__u_regfile__rd_we) 
             & (0U != (0x1fU & ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                                 << 0x1eU) | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                              >> 2U)))))) {
            __Vdlyvval__vercore_top__DOT__u_regfile__DOT__regs__v0 
                = ((vlTOPp->vercore_top__DOT__memwb_q[3U] 
                    << 0x19U) | (vlTOPp->vercore_top__DOT__memwb_q[2U] 
                                 >> 7U));
            __Vdlyvset__vercore_top__DOT__u_regfile__DOT__regs__v0 = 1U;
            __Vdlyvdim0__vercore_top__DOT__u_regfile__DOT__regs__v0 
                = (0x1fU & ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                             << 0x1eU) | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                          >> 2U)));
        }
    } else {
        __Vdlyvset__vercore_top__DOT__u_regfile__DOT__regs__v1 = 1U;
    }
    vlTOPp->vercore_top__DOT__drop_icache_resp = __Vdly__vercore_top__DOT__drop_icache_resp;
    if (__Vdlyvset__vercore_top__DOT__u_regfile__DOT__regs__v0) {
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[__Vdlyvdim0__vercore_top__DOT__u_regfile__DOT__regs__v0] 
            = __Vdlyvval__vercore_top__DOT__u_regfile__DOT__regs__v0;
    }
    if (__Vdlyvset__vercore_top__DOT__u_regfile__DOT__regs__v1) {
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[1U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[2U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[3U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[4U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[5U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[6U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[7U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[8U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[9U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0xaU] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0xbU] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0xcU] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0xdU] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0xeU] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0xfU] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x10U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x11U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x12U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x13U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x14U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x15U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x16U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x17U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x18U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x19U] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x1aU] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x1bU] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x1cU] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x1dU] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x1eU] = 0U;
        vlTOPp->vercore_top__DOT__u_regfile__DOT__regs[0x1fU] = 0U;
    }
    if (vlTOPp->rst_n) {
        if (vlTOPp->vercore_top__DOT__branch_taken_e) {
            vlTOPp->vercore_top__DOT__pc_f = vlTOPp->vercore_top__DOT__branch_target_e;
        } else {
            if ((1U & (~ (IData)(vlTOPp->vercore_top__DOT__stall_f)))) {
                vlTOPp->vercore_top__DOT__pc_f = vlTOPp->vercore_top__DOT__pc_next_f;
            }
        }
    } else {
        vlTOPp->vercore_top__DOT__pc_f = 0x80000000U;
    }
    vlTOPp->vercore_top__DOT__imm_d = ((((((- (IData)(
                                                      (((0x13U 
                                                         == 
                                                         (0x7fU 
                                                          & vlTOPp->vercore_top__DOT__ifid_q[0U])) 
                                                        | (3U 
                                                           == 
                                                           (0x7fU 
                                                            & vlTOPp->vercore_top__DOT__ifid_q[0U]))) 
                                                       | (0x67U 
                                                          == 
                                                          (0x7fU 
                                                           & vlTOPp->vercore_top__DOT__ifid_q[0U]))))) 
                                           & ((0xfffff000U 
                                               & ((- (IData)(
                                                             (1U 
                                                              & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                 >> 0x1fU)))) 
                                                  << 0xcU)) 
                                              | (0xfffU 
                                                 & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                     << 0xcU) 
                                                    | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                       >> 0x14U))))) 
                                          | ((- (IData)(
                                                        (0x23U 
                                                         == 
                                                         (0x7fU 
                                                          & vlTOPp->vercore_top__DOT__ifid_q[0U])))) 
                                             & ((0xfffff000U 
                                                 & ((- (IData)(
                                                               (1U 
                                                                & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                   >> 0x1fU)))) 
                                                    << 0xcU)) 
                                                | ((0xfe0U 
                                                    & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                        << 0xcU) 
                                                       | (0xfe0U 
                                                          & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                             >> 0x14U)))) 
                                                   | (0x1fU 
                                                      & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                          << 0x19U) 
                                                         | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                            >> 7U))))))) 
                                         | ((- (IData)(
                                                       (0x63U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->vercore_top__DOT__ifid_q[0U])))) 
                                            & ((0xffffe000U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                  >> 0x1fU)))) 
                                                   << 0xdU)) 
                                               | ((0x1000U 
                                                   & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                      >> 0x13U)) 
                                                  | ((0x800U 
                                                      & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                         << 4U)) 
                                                     | ((0x7e0U 
                                                         & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                             << 0xcU) 
                                                            | (0xfe0U 
                                                               & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                  >> 0x14U)))) 
                                                        | (0x1eU 
                                                           & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                               << 0x19U) 
                                                              | (0x1fffffeU 
                                                                 & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                    >> 7U)))))))))) 
                                        | (0xfffff000U 
                                           & ((- (IData)(
                                                         ((0x37U 
                                                           == 
                                                           (0x7fU 
                                                            & vlTOPp->vercore_top__DOT__ifid_q[0U])) 
                                                          | (0x17U 
                                                             == 
                                                             (0x7fU 
                                                              & vlTOPp->vercore_top__DOT__ifid_q[0U]))))) 
                                              & vlTOPp->vercore_top__DOT__ifid_q[0U]))) 
                                       | ((- (IData)(
                                                     (0x6fU 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->vercore_top__DOT__ifid_q[0U])))) 
                                          & ((0xffe00000U 
                                              & ((- (IData)(
                                                            (1U 
                                                             & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                >> 0x1fU)))) 
                                                 << 0x15U)) 
                                             | ((0x100000U 
                                                 & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                    >> 0xbU)) 
                                                | ((0xff000U 
                                                    & vlTOPp->vercore_top__DOT__ifid_q[0U]) 
                                                   | ((0x800U 
                                                       & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                          >> 9U)) 
                                                      | (0x7feU 
                                                         & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                             << 0xcU) 
                                                            | (0xffeU 
                                                               & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                  >> 0x14U))))))))));
    vlTOPp->vercore_top__DOT__regwrite_d = 0U;
    if ((0x40U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
        if ((0x20U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
            if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                          >> 4U)))) {
                if ((8U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__regwrite_d = 1U;
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__regwrite_d = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
            if ((0x10U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__regwrite_d = 1U;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__regwrite_d = 1U;
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__regwrite_d = 1U;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__regwrite_d = 1U;
                            }
                        }
                    }
                }
            } else {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__regwrite_d = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->vercore_top__DOT__memread_d = 0U;
    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__memread_d = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->vercore_top__DOT__memwrite_d = 0U;
    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
            if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__memwrite_d = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->vercore_top__DOT__mem_size_d = 2U;
    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
            if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__mem_size_d 
                                    = ((0U == (7U & 
                                               ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                 << 0x14U) 
                                                | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                   >> 0xcU))))
                                        ? 0U : ((1U 
                                                 == 
                                                 (7U 
                                                  & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                      << 0x14U) 
                                                     | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                        >> 0xcU))))
                                                 ? 1U
                                                 : 2U));
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__mem_size_d 
                                    = ((0U == (7U & 
                                               ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                 << 0x14U) 
                                                | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                   >> 0xcU))))
                                        ? 0U : ((1U 
                                                 == 
                                                 (7U 
                                                  & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                      << 0x14U) 
                                                     | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                        >> 0xcU))))
                                                 ? 1U
                                                 : 2U));
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->vercore_top__DOT__alu_src_d = 0U;
    if ((0x40U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
        if ((0x20U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
            if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_src_d = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
            if ((0x10U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_src_d = 1U;
                            }
                        }
                    }
                }
            } else {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_src_d = 1U;
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_src_d = 1U;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_src_d = 1U;
                            }
                        }
                    }
                }
            } else {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_src_d = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->vercore_top__DOT__wb_sel_d = 0U;
    if ((0x40U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
        if ((0x20U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
            if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                          >> 4U)))) {
                if ((8U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__wb_sel_d = 2U;
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__wb_sel_d = 2U;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
            if ((0x10U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__wb_sel_d = 0U;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__wb_sel_d = 0U;
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__wb_sel_d = 0U;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__wb_sel_d = 0U;
                            }
                        }
                    }
                }
            } else {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__wb_sel_d = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->vercore_top__DOT__alu_op_d = 0U;
    if ((0x40U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
        if ((0x20U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
            if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_op_d = 0U;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_op_d = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
            if ((0x10U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_op_d = 0xaU;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_op_d 
                                    = ((0x4000U & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                        ? ((0x2000U 
                                            & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                            ? ((0x1000U 
                                                & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                                ? 2U
                                                : 3U)
                                            : ((0x1000U 
                                                & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                                ? (
                                                   (0x20U 
                                                    == 
                                                    (0x7fU 
                                                     & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                         << 7U) 
                                                        | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                           >> 0x19U))))
                                                    ? 9U
                                                    : 8U)
                                                : (
                                                   (1U 
                                                    == 
                                                    (0x7fU 
                                                     & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                         << 7U) 
                                                        | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                           >> 0x19U))))
                                                    ? 0xdU
                                                    : 4U)))
                                        : ((0x2000U 
                                            & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                            ? ((0x1000U 
                                                & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                                ? (
                                                   (1U 
                                                    == 
                                                    (0x7fU 
                                                     & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                         << 7U) 
                                                        | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                           >> 0x19U))))
                                                    ? 0xeU
                                                    : 6U)
                                                : 5U)
                                            : ((0x1000U 
                                                & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                                ? (
                                                   (1U 
                                                    == 
                                                    (0x7fU 
                                                     & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                         << 7U) 
                                                        | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                           >> 0x19U))))
                                                    ? 0xcU
                                                    : 7U)
                                                : (
                                                   (0x20U 
                                                    == 
                                                    (0x7fU 
                                                     & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                         << 7U) 
                                                        | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                           >> 0x19U))))
                                                    ? 1U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0x7fU 
                                                      & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                          << 7U) 
                                                         | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                            >> 0x19U))))
                                                     ? 0xbU
                                                     : 0U)))));
                            }
                        }
                    }
                }
            } else {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_op_d = 0U;
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_op_d = 0U;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_op_d 
                                    = ((0x4000U & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                        ? ((0x2000U 
                                            & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                            ? ((0x1000U 
                                                & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                                ? 2U
                                                : 3U)
                                            : ((0x1000U 
                                                & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                                ? (
                                                   (0x40000000U 
                                                    & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                                    ? 9U
                                                    : 8U)
                                                : 4U))
                                        : ((0x2000U 
                                            & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                            ? ((0x1000U 
                                                & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                                ? 6U
                                                : 5U)
                                            : ((0x1000U 
                                                & vlTOPp->vercore_top__DOT__ifid_q[0U])
                                                ? 7U
                                                : 0U)));
                            }
                        }
                    }
                }
            } else {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__alu_op_d = 0U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->vercore_top__DOT__branch_d = 0U;
    if ((0x40U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
        if ((0x20U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
            if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__branch_d = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->vercore_top__DOT__jump_d = 0U;
    if ((0x40U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
        if ((0x20U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
            if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                          >> 4U)))) {
                if ((8U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__jump_d = 1U;
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__jump_d = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->vercore_top__DOT__jump_reg_d = 0U;
    if ((0x40U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
        if ((0x20U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
            if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                              >> 3U)))) {
                    if ((4U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                        if ((2U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                            if ((1U & vlTOPp->vercore_top__DOT__ifid_q[0U])) {
                                vlTOPp->vercore_top__DOT__jump_reg_d = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    __Vtemp3[1U] = ((0x7fU & (vlTOPp->vercore_top__DOT__exmem_q[1U] 
                              >> 9U)) | (0xffffff80U 
                                         & ((IData)(
                                                    (((QData)((IData)(
                                                                      ((0U 
                                                                        == 
                                                                        (3U 
                                                                         & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                                             << 0x1cU) 
                                                                            | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                                               >> 4U))))
                                                                        ? 
                                                                       ((vlTOPp->vercore_top__DOT__exmem_q[5U] 
                                                                         << 0x10U) 
                                                                        | (vlTOPp->vercore_top__DOT__exmem_q[4U] 
                                                                           >> 0x10U))
                                                                        : 
                                                                       ((1U 
                                                                         == 
                                                                         (3U 
                                                                          & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                                              << 0x1cU) 
                                                                             | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                                                >> 4U))))
                                                                         ? vlTOPp->vercore_top__DOT__load_data_m
                                                                         : 
                                                                        ((vlTOPp->vercore_top__DOT__exmem_q[2U] 
                                                                          << 0x10U) 
                                                                         | (vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                                            >> 0x10U)))))) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       ((vlTOPp->vercore_top__DOT__exmem_q[3U] 
                                                                         << 0x10U) 
                                                                        | (vlTOPp->vercore_top__DOT__exmem_q[2U] 
                                                                           >> 0x10U)))))) 
                                            << 7U)));
    __Vtemp3[2U] = ((0x7fU & ((IData)((((QData)((IData)(
                                                        ((0U 
                                                          == 
                                                          (3U 
                                                           & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                               << 0x1cU) 
                                                              | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                                 >> 4U))))
                                                          ? 
                                                         ((vlTOPp->vercore_top__DOT__exmem_q[5U] 
                                                           << 0x10U) 
                                                          | (vlTOPp->vercore_top__DOT__exmem_q[4U] 
                                                             >> 0x10U))
                                                          : 
                                                         ((1U 
                                                           == 
                                                           (3U 
                                                            & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                                << 0x1cU) 
                                                               | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                                  >> 4U))))
                                                           ? vlTOPp->vercore_top__DOT__load_data_m
                                                           : 
                                                          ((vlTOPp->vercore_top__DOT__exmem_q[2U] 
                                                            << 0x10U) 
                                                           | (vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                              >> 0x10U)))))) 
                                        << 0x20U) | (QData)((IData)(
                                                                    ((vlTOPp->vercore_top__DOT__exmem_q[3U] 
                                                                      << 0x10U) 
                                                                     | (vlTOPp->vercore_top__DOT__exmem_q[2U] 
                                                                        >> 0x10U)))))) 
                              >> 0x19U)) | (0xffffff80U 
                                            & ((IData)(
                                                       ((((QData)((IData)(
                                                                          ((0U 
                                                                            == 
                                                                            (3U 
                                                                             & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                                                << 0x1cU) 
                                                                                | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                                                >> 4U))))
                                                                            ? 
                                                                           ((vlTOPp->vercore_top__DOT__exmem_q[5U] 
                                                                             << 0x10U) 
                                                                            | (vlTOPp->vercore_top__DOT__exmem_q[4U] 
                                                                               >> 0x10U))
                                                                            : 
                                                                           ((1U 
                                                                             == 
                                                                             (3U 
                                                                              & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                                                << 0x1cU) 
                                                                                | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                                                >> 4U))))
                                                                             ? vlTOPp->vercore_top__DOT__load_data_m
                                                                             : 
                                                                            ((vlTOPp->vercore_top__DOT__exmem_q[2U] 
                                                                              << 0x10U) 
                                                                             | (vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                                                >> 0x10U)))))) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           ((vlTOPp->vercore_top__DOT__exmem_q[3U] 
                                                                             << 0x10U) 
                                                                            | (vlTOPp->vercore_top__DOT__exmem_q[2U] 
                                                                               >> 0x10U))))) 
                                                        >> 0x20U)) 
                                               << 7U)));
    if (vlTOPp->rst_n) {
        vlTOPp->vercore_top__DOT__memwb_q[0U] = ((0xffffff80U 
                                                  & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                      << 0x17U) 
                                                     | (0x7fff80U 
                                                        & (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                           >> 9U)))) 
                                                 | ((0x7cU 
                                                     & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                         << 0x17U) 
                                                        | (0x7ffffcU 
                                                           & (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                              >> 9U)))) 
                                                    | ((2U 
                                                        & (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                           >> 2U)) 
                                                       | (1U 
                                                          & (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                             & (~ (IData)(vlTOPp->vercore_top__DOT__mem_busy_m)))))));
        vlTOPp->vercore_top__DOT__memwb_q[1U] = __Vtemp3[1U];
        vlTOPp->vercore_top__DOT__memwb_q[2U] = __Vtemp3[2U];
        vlTOPp->vercore_top__DOT__memwb_q[3U] = (0x7fU 
                                                 & ((IData)(
                                                            ((((QData)((IData)(
                                                                               ((0U 
                                                                                == 
                                                                                (3U 
                                                                                & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                                                << 0x1cU) 
                                                                                | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                                                >> 4U))))
                                                                                 ? 
                                                                                ((vlTOPp->vercore_top__DOT__exmem_q[5U] 
                                                                                << 0x10U) 
                                                                                | (vlTOPp->vercore_top__DOT__exmem_q[4U] 
                                                                                >> 0x10U))
                                                                                 : 
                                                                                ((1U 
                                                                                == 
                                                                                (3U 
                                                                                & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                                                << 0x1cU) 
                                                                                | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                                                >> 4U))))
                                                                                 ? vlTOPp->vercore_top__DOT__load_data_m
                                                                                 : 
                                                                                ((vlTOPp->vercore_top__DOT__exmem_q[2U] 
                                                                                << 0x10U) 
                                                                                | (vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                                                                >> 0x10U)))))) 
                                                               << 0x20U) 
                                                              | (QData)((IData)(
                                                                                ((vlTOPp->vercore_top__DOT__exmem_q[3U] 
                                                                                << 0x10U) 
                                                                                | (vlTOPp->vercore_top__DOT__exmem_q[2U] 
                                                                                >> 0x10U))))) 
                                                             >> 0x20U)) 
                                                    >> 0x19U));
    } else {
        vlTOPp->vercore_top__DOT__memwb_q[0U] = 0U;
        vlTOPp->vercore_top__DOT__memwb_q[1U] = 0U;
        vlTOPp->vercore_top__DOT__memwb_q[2U] = 0U;
        vlTOPp->vercore_top__DOT__memwb_q[3U] = 0U;
    }
    vlTOPp->icache_addr = vlTOPp->vercore_top__DOT__pc_f;
    vlTOPp->dbg_retire_valid = (1U & vlTOPp->vercore_top__DOT__memwb_q[0U]);
    vlTOPp->dbg_retire_pc = ((vlTOPp->vercore_top__DOT__memwb_q[2U] 
                              << 0x19U) | (vlTOPp->vercore_top__DOT__memwb_q[1U] 
                                           >> 7U));
    vlTOPp->dbg_retire_instr = ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                                 << 0x19U) | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                              >> 7U));
    vlTOPp->dbg_retire_rd_we = ((vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                 >> 1U) & (0U != (0x1fU 
                                                  & ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                                                      << 0x1eU) 
                                                     | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                                        >> 2U)))));
    vlTOPp->dbg_retire_rd_addr = (0x1fU & ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                                            << 0x1eU) 
                                           | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                              >> 2U)));
    vlTOPp->dbg_retire_rd_data = ((vlTOPp->vercore_top__DOT__memwb_q[3U] 
                                   << 0x19U) | (vlTOPp->vercore_top__DOT__memwb_q[2U] 
                                                >> 7U));
    vlTOPp->vercore_top__DOT____Vcellinp__u_regfile__rd_we 
        = (1U & ((vlTOPp->vercore_top__DOT__memwb_q[0U] 
                  >> 1U) & vlTOPp->vercore_top__DOT__memwb_q[0U]));
    if (vlTOPp->rst_n) {
        if ((1U & (~ (IData)(vlTOPp->vercore_top__DOT__stall_m)))) {
            __Vtemp9[0U] = ((0xffff0000U & (vlTOPp->vercore_top__DOT__idex_q[1U] 
                                            << 0xdU)) 
                            | ((0xf800U & ((vlTOPp->vercore_top__DOT__idex_q[1U] 
                                            << 0x17U) 
                                           | (0x7ff800U 
                                              & (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                 >> 9U)))) 
                               | ((0x700U & ((vlTOPp->vercore_top__DOT__idex_q[1U] 
                                              << 0x1cU) 
                                             | (0xfffff00U 
                                                & (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                   >> 4U)))) 
                                  | ((0xc0U & ((vlTOPp->vercore_top__DOT__idex_q[1U] 
                                                << 0x1cU) 
                                               | (0xfffffc0U 
                                                  & (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                     >> 4U)))) 
                                     | ((0x30U & ((
                                                   vlTOPp->vercore_top__DOT__idex_q[1U] 
                                                   << 0x1cU) 
                                                  | (0xffffff0U 
                                                     & (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                        >> 4U)))) 
                                        | ((8U & (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                  >> 4U)) 
                                           | ((4U & 
                                               (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                >> 4U)) 
                                              | ((2U 
                                                  & (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                     >> 4U)) 
                                                 | (1U 
                                                    & vlTOPp->vercore_top__DOT__idex_q[0U])))))))));
            vlTOPp->vercore_top__DOT__exmem_q[0U] = 
                __Vtemp9[0U];
            vlTOPp->vercore_top__DOT__exmem_q[1U] = 
                ((0xffffU & ((0xe000U & (vlTOPp->vercore_top__DOT__idex_q[2U] 
                                         << 0xdU)) 
                             | (vlTOPp->vercore_top__DOT__idex_q[1U] 
                                >> 0x13U))) | (0xffff0000U 
                                               & (((IData)(4U) 
                                                   + 
                                                   ((vlTOPp->vercore_top__DOT__idex_q[6U] 
                                                     << 0x1dU) 
                                                    | (vlTOPp->vercore_top__DOT__idex_q[5U] 
                                                       >> 3U))) 
                                                  << 0x10U)));
            vlTOPp->vercore_top__DOT__exmem_q[2U] = 
                ((0xffffU & (((IData)(4U) + ((vlTOPp->vercore_top__DOT__idex_q[6U] 
                                              << 0x1dU) 
                                             | (vlTOPp->vercore_top__DOT__idex_q[5U] 
                                                >> 3U))) 
                             >> 0x10U)) | (0xffff0000U 
                                           & (vlTOPp->vercore_top__DOT__idex_q[5U] 
                                              << 0xdU)));
            vlTOPp->vercore_top__DOT__exmem_q[3U] = 
                ((0xffffU & ((0xe000U & (vlTOPp->vercore_top__DOT__idex_q[6U] 
                                         << 0xdU)) 
                             | (vlTOPp->vercore_top__DOT__idex_q[5U] 
                                >> 0x13U))) | (0xffff0000U 
                                               & ((IData)(
                                                          (((QData)((IData)(vlTOPp->vercore_top__DOT__alu_y_e)) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(vlTOPp->vercore_top__DOT__op_b_e_fwd)))) 
                                                  << 0x10U)));
            vlTOPp->vercore_top__DOT__exmem_q[4U] = 
                ((0xffffU & ((IData)((((QData)((IData)(vlTOPp->vercore_top__DOT__alu_y_e)) 
                                       << 0x20U) | (QData)((IData)(vlTOPp->vercore_top__DOT__op_b_e_fwd)))) 
                             >> 0x10U)) | (0xffff0000U 
                                           & ((IData)(
                                                      ((((QData)((IData)(vlTOPp->vercore_top__DOT__alu_y_e)) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(vlTOPp->vercore_top__DOT__op_b_e_fwd))) 
                                                       >> 0x20U)) 
                                              << 0x10U)));
            vlTOPp->vercore_top__DOT__exmem_q[5U] = 
                (0xffffU & ((IData)(((((QData)((IData)(vlTOPp->vercore_top__DOT__alu_y_e)) 
                                       << 0x20U) | (QData)((IData)(vlTOPp->vercore_top__DOT__op_b_e_fwd))) 
                                     >> 0x20U)) >> 0x10U));
        }
    } else {
        vlTOPp->vercore_top__DOT__exmem_q[0U] = 0U;
        vlTOPp->vercore_top__DOT__exmem_q[1U] = 0U;
        vlTOPp->vercore_top__DOT__exmem_q[2U] = 0U;
        vlTOPp->vercore_top__DOT__exmem_q[3U] = 0U;
        vlTOPp->vercore_top__DOT__exmem_q[4U] = 0U;
        vlTOPp->vercore_top__DOT__exmem_q[5U] = 0U;
    }
    vlTOPp->dcache_req = (1U & (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                & ((vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                    >> 2U) | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                              >> 1U))));
    vlTOPp->dcache_we = (1U & (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                               >> 1U));
    vlTOPp->dcache_size = (3U & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                                  << 0x1aU) | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                               >> 6U)));
    vlTOPp->dcache_addr = ((vlTOPp->vercore_top__DOT__exmem_q[5U] 
                            << 0x10U) | (vlTOPp->vercore_top__DOT__exmem_q[4U] 
                                         >> 0x10U));
    vlTOPp->dcache_wdata = ((vlTOPp->vercore_top__DOT__exmem_q[4U] 
                             << 0x10U) | (vlTOPp->vercore_top__DOT__exmem_q[3U] 
                                          >> 0x10U));
    if (vlTOPp->rst_n) {
        if (vlTOPp->vercore_top__DOT__flush_e) {
            vlTOPp->vercore_top__DOT__idex_q[0U] = 0U;
            vlTOPp->vercore_top__DOT__idex_q[1U] = 0U;
            vlTOPp->vercore_top__DOT__idex_q[2U] = 0U;
            vlTOPp->vercore_top__DOT__idex_q[3U] = 0U;
            vlTOPp->vercore_top__DOT__idex_q[4U] = 0U;
            vlTOPp->vercore_top__DOT__idex_q[5U] = 0U;
            vlTOPp->vercore_top__DOT__idex_q[6U] = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->vercore_top__DOT__stall_e)))) {
                vlTOPp->vercore_top__DOT__idex_q[0U] 
                    = vlTOPp->vercore_top__DOT__idex_d[0U];
                vlTOPp->vercore_top__DOT__idex_q[1U] 
                    = vlTOPp->vercore_top__DOT__idex_d[1U];
                vlTOPp->vercore_top__DOT__idex_q[2U] 
                    = vlTOPp->vercore_top__DOT__idex_d[2U];
                vlTOPp->vercore_top__DOT__idex_q[3U] 
                    = vlTOPp->vercore_top__DOT__idex_d[3U];
                vlTOPp->vercore_top__DOT__idex_q[4U] 
                    = vlTOPp->vercore_top__DOT__idex_d[4U];
                vlTOPp->vercore_top__DOT__idex_q[5U] 
                    = vlTOPp->vercore_top__DOT__idex_d[5U];
                vlTOPp->vercore_top__DOT__idex_q[6U] 
                    = vlTOPp->vercore_top__DOT__idex_d[6U];
            }
        }
    } else {
        vlTOPp->vercore_top__DOT__idex_q[0U] = 0U;
        vlTOPp->vercore_top__DOT__idex_q[1U] = 0U;
        vlTOPp->vercore_top__DOT__idex_q[2U] = 0U;
        vlTOPp->vercore_top__DOT__idex_q[3U] = 0U;
        vlTOPp->vercore_top__DOT__idex_q[4U] = 0U;
        vlTOPp->vercore_top__DOT__idex_q[5U] = 0U;
        vlTOPp->vercore_top__DOT__idex_q[6U] = 0U;
    }
    __Vtemp10[0U] = ((0U == (0x1fU & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                       << 0xcU) | (
                                                   vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                   >> 0x14U))))
                      ? 0U : ((((IData)(vlTOPp->vercore_top__DOT____Vcellinp__u_regfile__rd_we) 
                                & ((0x1fU & ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                                              << 0x1eU) 
                                             | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                                >> 2U))) 
                                   == (0x1fU & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                 << 0xcU) 
                                                | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                   >> 0x14U))))) 
                               & (0U != (0x1fU & ((
                                                   vlTOPp->vercore_top__DOT__memwb_q[1U] 
                                                   << 0x1eU) 
                                                  | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                                     >> 2U)))))
                               ? ((vlTOPp->vercore_top__DOT__memwb_q[3U] 
                                   << 0x19U) | (vlTOPp->vercore_top__DOT__memwb_q[2U] 
                                                >> 7U))
                               : vlTOPp->vercore_top__DOT__u_regfile__DOT__regs
                              [(0x1fU & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                          << 0xcU) 
                                         | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                            >> 0x14U)))]));
    __Vtemp10[1U] = (IData)((((QData)((IData)(vlTOPp->vercore_top__DOT__ifid_q[1U])) 
                              << 0x20U) | (QData)((IData)(
                                                          ((0U 
                                                            == 
                                                            (0x1fU 
                                                             & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                                 << 0x11U) 
                                                                | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                   >> 0xfU))))
                                                            ? 0U
                                                            : 
                                                           ((((IData)(vlTOPp->vercore_top__DOT____Vcellinp__u_regfile__rd_we) 
                                                              & ((0x1fU 
                                                                  & ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                                                                      << 0x1eU) 
                                                                     | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                                                        >> 2U))) 
                                                                 == 
                                                                 (0x1fU 
                                                                  & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                                      << 0x11U) 
                                                                     | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                        >> 0xfU))))) 
                                                             & (0U 
                                                                != 
                                                                (0x1fU 
                                                                 & ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                                                                     << 0x1eU) 
                                                                    | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                                                       >> 2U)))))
                                                             ? 
                                                            ((vlTOPp->vercore_top__DOT__memwb_q[3U] 
                                                              << 0x19U) 
                                                             | (vlTOPp->vercore_top__DOT__memwb_q[2U] 
                                                                >> 7U))
                                                             : 
                                                            vlTOPp->vercore_top__DOT__u_regfile__DOT__regs
                                                            [
                                                            (0x1fU 
                                                             & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                                 << 0x11U) 
                                                                | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                   >> 0xfU)))]))))));
    __Vtemp10[2U] = (IData)(((((QData)((IData)(vlTOPp->vercore_top__DOT__ifid_q[1U])) 
                               << 0x20U) | (QData)((IData)(
                                                           ((0U 
                                                             == 
                                                             (0x1fU 
                                                              & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                                  << 0x11U) 
                                                                 | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                    >> 0xfU))))
                                                             ? 0U
                                                             : 
                                                            ((((IData)(vlTOPp->vercore_top__DOT____Vcellinp__u_regfile__rd_we) 
                                                               & ((0x1fU 
                                                                   & ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                                                                       << 0x1eU) 
                                                                      | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                                                         >> 2U))) 
                                                                  == 
                                                                  (0x1fU 
                                                                   & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                                       << 0x11U) 
                                                                      | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                         >> 0xfU))))) 
                                                              & (0U 
                                                                 != 
                                                                 (0x1fU 
                                                                  & ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                                                                      << 0x1eU) 
                                                                     | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                                                        >> 2U)))))
                                                              ? 
                                                             ((vlTOPp->vercore_top__DOT__memwb_q[3U] 
                                                               << 0x19U) 
                                                              | (vlTOPp->vercore_top__DOT__memwb_q[2U] 
                                                                 >> 7U))
                                                              : 
                                                             vlTOPp->vercore_top__DOT__u_regfile__DOT__regs
                                                             [
                                                             (0x1fU 
                                                              & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                                  << 0x11U) 
                                                                 | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                    >> 0xfU)))]))))) 
                             >> 0x20U));
    __Vtemp14[0U] = ((0xfffffff8U & ((0xc0000000U & 
                                      (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                       << 0xfU)) | 
                                     ((0x3e000000U 
                                       & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                          << 5U)) | 
                                      ((0x1f00000U 
                                        & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                           << 0xdU)) 
                                       | (((IData)(vlTOPp->vercore_top__DOT__alu_op_d) 
                                           << 0xfU) 
                                          | ((0x7000U 
                                              & vlTOPp->vercore_top__DOT__ifid_q[0U]) 
                                             | (((IData)(vlTOPp->vercore_top__DOT__mem_size_d) 
                                                 << 0xaU) 
                                                | (((IData)(vlTOPp->vercore_top__DOT__wb_sel_d) 
                                                    << 8U) 
                                                   | (((IData)(vlTOPp->vercore_top__DOT__regwrite_d) 
                                                       << 7U) 
                                                      | (((IData)(vlTOPp->vercore_top__DOT__memread_d) 
                                                          << 6U) 
                                                         | (((IData)(vlTOPp->vercore_top__DOT__memwrite_d) 
                                                             << 5U) 
                                                            | (((IData)(vlTOPp->vercore_top__DOT__alu_src_d) 
                                                                << 4U) 
                                                               | ((IData)(vlTOPp->vercore_top__DOT__branch_d) 
                                                                  << 3U))))))))))))) 
                     | (((IData)(vlTOPp->vercore_top__DOT__jump_d) 
                         << 2U) | (((IData)(vlTOPp->vercore_top__DOT__jump_reg_d) 
                                    << 1U) | (1U & 
                                              vlTOPp->vercore_top__DOT__ifid_q[2U]))));
    __Vtemp14[1U] = ((7U & ((7U & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                   >> 0x11U)) | ((7U 
                                                  & ((IData)(vlTOPp->vercore_top__DOT__alu_op_d) 
                                                     >> 0x11U)) 
                                                 | ((7U 
                                                     & ((IData)(vlTOPp->vercore_top__DOT__mem_size_d) 
                                                        >> 0x16U)) 
                                                    | ((7U 
                                                        & ((IData)(vlTOPp->vercore_top__DOT__wb_sel_d) 
                                                           >> 0x18U)) 
                                                       | ((7U 
                                                           & ((IData)(vlTOPp->vercore_top__DOT__regwrite_d) 
                                                              >> 0x19U)) 
                                                          | ((7U 
                                                              & ((IData)(vlTOPp->vercore_top__DOT__memread_d) 
                                                                 >> 0x1aU)) 
                                                             | ((7U 
                                                                 & ((IData)(vlTOPp->vercore_top__DOT__memwrite_d) 
                                                                    >> 0x1bU)) 
                                                                | ((7U 
                                                                    & ((IData)(vlTOPp->vercore_top__DOT__alu_src_d) 
                                                                       >> 0x1cU)) 
                                                                   | ((IData)(vlTOPp->vercore_top__DOT__branch_d) 
                                                                      >> 0x1dU)))))))))) 
                     | (0xfffffff8U & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                       << 3U)));
    vlTOPp->vercore_top__DOT__idex_d[0U] = __Vtemp14[0U];
    vlTOPp->vercore_top__DOT__idex_d[1U] = __Vtemp14[1U];
    vlTOPp->vercore_top__DOT__idex_d[2U] = ((7U & (
                                                   vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                   >> 0x1dU)) 
                                            | (0xfffffff8U 
                                               & (vlTOPp->vercore_top__DOT__imm_d 
                                                  << 3U)));
    vlTOPp->vercore_top__DOT__idex_d[3U] = ((7U & (vlTOPp->vercore_top__DOT__imm_d 
                                                   >> 0x1dU)) 
                                            | (0xfffffff8U 
                                               & (__Vtemp10[0U] 
                                                  << 3U)));
    vlTOPp->vercore_top__DOT__idex_d[4U] = ((7U & (
                                                   __Vtemp10[0U] 
                                                   >> 0x1dU)) 
                                            | (0xfffffff8U 
                                               & (__Vtemp10[1U] 
                                                  << 3U)));
    vlTOPp->vercore_top__DOT__idex_d[5U] = ((7U & (
                                                   __Vtemp10[1U] 
                                                   >> 0x1dU)) 
                                            | (0xfffffff8U 
                                               & (__Vtemp10[2U] 
                                                  << 3U)));
    vlTOPp->vercore_top__DOT__idex_d[6U] = (7U & (__Vtemp10[2U] 
                                                  >> 0x1dU));
    vlTOPp->vercore_top__DOT__fwd_a_sel = 0U;
    if ((((vlTOPp->vercore_top__DOT__exmem_q[0U] >> 3U) 
          & (0U != (0x1fU & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                              << 0x15U) | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                           >> 0xbU))))) 
         & ((0x1fU & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                       << 0x15U) | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                    >> 0xbU))) == (0x1fU 
                                                   & ((vlTOPp->vercore_top__DOT__idex_q[1U] 
                                                       << 2U) 
                                                      | (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                         >> 0x1eU)))))) {
        vlTOPp->vercore_top__DOT__fwd_a_sel = 1U;
    } else {
        if ((((vlTOPp->vercore_top__DOT__memwb_q[0U] 
               >> 1U) & (0U != (0x1fU & ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                                          << 0x1eU) 
                                         | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                            >> 2U))))) 
             & ((0x1fU & ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                           << 0x1eU) | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                        >> 2U))) == 
                (0x1fU & ((vlTOPp->vercore_top__DOT__idex_q[1U] 
                           << 2U) | (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                     >> 0x1eU)))))) {
            vlTOPp->vercore_top__DOT__fwd_a_sel = 2U;
        }
    }
    vlTOPp->vercore_top__DOT__fwd_b_sel = 0U;
    if ((((vlTOPp->vercore_top__DOT__exmem_q[0U] >> 3U) 
          & (0U != (0x1fU & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                              << 0x15U) | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                           >> 0xbU))))) 
         & ((0x1fU & ((vlTOPp->vercore_top__DOT__exmem_q[1U] 
                       << 0x15U) | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                    >> 0xbU))) == (0x1fU 
                                                   & ((vlTOPp->vercore_top__DOT__idex_q[1U] 
                                                       << 7U) 
                                                      | (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                         >> 0x19U)))))) {
        vlTOPp->vercore_top__DOT__fwd_b_sel = 1U;
    } else {
        if ((((vlTOPp->vercore_top__DOT__memwb_q[0U] 
               >> 1U) & (0U != (0x1fU & ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                                          << 0x1eU) 
                                         | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                            >> 2U))))) 
             & ((0x1fU & ((vlTOPp->vercore_top__DOT__memwb_q[1U] 
                           << 0x1eU) | (vlTOPp->vercore_top__DOT__memwb_q[0U] 
                                        >> 2U))) == 
                (0x1fU & ((vlTOPp->vercore_top__DOT__idex_q[1U] 
                           << 7U) | (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                     >> 0x19U)))))) {
            vlTOPp->vercore_top__DOT__fwd_b_sel = 2U;
        }
    }
    vlTOPp->vercore_top__DOT__op_a_e = ((0x17U == (0x7fU 
                                                   & ((vlTOPp->vercore_top__DOT__idex_q[2U] 
                                                       << 0x1dU) 
                                                      | (vlTOPp->vercore_top__DOT__idex_q[1U] 
                                                         >> 3U))))
                                         ? ((vlTOPp->vercore_top__DOT__idex_q[6U] 
                                             << 0x1dU) 
                                            | (vlTOPp->vercore_top__DOT__idex_q[5U] 
                                               >> 3U))
                                         : ((1U == (IData)(vlTOPp->vercore_top__DOT__fwd_a_sel))
                                             ? ((vlTOPp->vercore_top__DOT__exmem_q[5U] 
                                                 << 0x10U) 
                                                | (vlTOPp->vercore_top__DOT__exmem_q[4U] 
                                                   >> 0x10U))
                                             : ((2U 
                                                 == (IData)(vlTOPp->vercore_top__DOT__fwd_a_sel))
                                                 ? 
                                                ((vlTOPp->vercore_top__DOT__memwb_q[3U] 
                                                  << 0x19U) 
                                                 | (vlTOPp->vercore_top__DOT__memwb_q[2U] 
                                                    >> 7U))
                                                 : 
                                                ((vlTOPp->vercore_top__DOT__idex_q[5U] 
                                                  << 0x1dU) 
                                                 | (vlTOPp->vercore_top__DOT__idex_q[4U] 
                                                    >> 3U)))));
    vlTOPp->vercore_top__DOT__op_b_e_fwd = ((1U == (IData)(vlTOPp->vercore_top__DOT__fwd_b_sel))
                                             ? ((vlTOPp->vercore_top__DOT__exmem_q[5U] 
                                                 << 0x10U) 
                                                | (vlTOPp->vercore_top__DOT__exmem_q[4U] 
                                                   >> 0x10U))
                                             : ((2U 
                                                 == (IData)(vlTOPp->vercore_top__DOT__fwd_b_sel))
                                                 ? 
                                                ((vlTOPp->vercore_top__DOT__memwb_q[3U] 
                                                  << 0x19U) 
                                                 | (vlTOPp->vercore_top__DOT__memwb_q[2U] 
                                                    >> 7U))
                                                 : 
                                                ((vlTOPp->vercore_top__DOT__idex_q[4U] 
                                                  << 0x1dU) 
                                                 | (vlTOPp->vercore_top__DOT__idex_q[3U] 
                                                    >> 3U))));
    vlTOPp->vercore_top__DOT__branch_target_e = ((1U 
                                                  & ((vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                      >> 2U) 
                                                     & (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                        >> 1U)))
                                                  ? 
                                                 (0xfffffffeU 
                                                  & (vlTOPp->vercore_top__DOT__op_a_e 
                                                     + 
                                                     ((vlTOPp->vercore_top__DOT__idex_q[3U] 
                                                       << 0x1dU) 
                                                      | (vlTOPp->vercore_top__DOT__idex_q[2U] 
                                                         >> 3U))))
                                                  : 
                                                 (((vlTOPp->vercore_top__DOT__idex_q[6U] 
                                                    << 0x1dU) 
                                                   | (vlTOPp->vercore_top__DOT__idex_q[5U] 
                                                      >> 3U)) 
                                                  + 
                                                  ((vlTOPp->vercore_top__DOT__idex_q[3U] 
                                                    << 0x1dU) 
                                                   | (vlTOPp->vercore_top__DOT__idex_q[2U] 
                                                      >> 3U))));
    vlTOPp->vercore_top__DOT__op_b_e = ((0x10U & vlTOPp->vercore_top__DOT__idex_q[0U])
                                         ? ((vlTOPp->vercore_top__DOT__idex_q[3U] 
                                             << 0x1dU) 
                                            | (vlTOPp->vercore_top__DOT__idex_q[2U] 
                                               >> 3U))
                                         : vlTOPp->vercore_top__DOT__op_b_e_fwd);
    vlTOPp->vercore_top__DOT__branch_taken_e = 0U;
    if ((4U & vlTOPp->vercore_top__DOT__idex_q[0U])) {
        vlTOPp->vercore_top__DOT__branch_taken_e = 1U;
    } else {
        if ((8U & vlTOPp->vercore_top__DOT__idex_q[0U])) {
            vlTOPp->vercore_top__DOT__branch_taken_e 
                = ((0x4000U & vlTOPp->vercore_top__DOT__idex_q[0U])
                    ? ((0x2000U & vlTOPp->vercore_top__DOT__idex_q[0U])
                        ? ((0x1000U & vlTOPp->vercore_top__DOT__idex_q[0U])
                            ? (vlTOPp->vercore_top__DOT__op_a_e 
                               >= vlTOPp->vercore_top__DOT__op_b_e_fwd)
                            : (vlTOPp->vercore_top__DOT__op_a_e 
                               < vlTOPp->vercore_top__DOT__op_b_e_fwd))
                        : ((0x1000U & vlTOPp->vercore_top__DOT__idex_q[0U])
                            ? VL_GTES_III(1,32,32, vlTOPp->vercore_top__DOT__op_a_e, vlTOPp->vercore_top__DOT__op_b_e_fwd)
                            : VL_LTS_III(1,32,32, vlTOPp->vercore_top__DOT__op_a_e, vlTOPp->vercore_top__DOT__op_b_e_fwd)))
                    : ((~ (vlTOPp->vercore_top__DOT__idex_q[0U] 
                           >> 0xdU)) & ((0x1000U & 
                                         vlTOPp->vercore_top__DOT__idex_q[0U])
                                         ? (vlTOPp->vercore_top__DOT__op_a_e 
                                            != vlTOPp->vercore_top__DOT__op_b_e_fwd)
                                         : (vlTOPp->vercore_top__DOT__op_a_e 
                                            == vlTOPp->vercore_top__DOT__op_b_e_fwd))));
        }
    }
    vlTOPp->vercore_top__DOT__u_alu__DOT__mul_lo = 
        (vlTOPp->vercore_top__DOT__op_a_e * vlTOPp->vercore_top__DOT__op_b_e);
    vlTOPp->vercore_top__DOT__u_alu__DOT__mulh_hi = 
        (- (VL_MULS_III(32,32,32, vlTOPp->vercore_top__DOT__op_a_e, vlTOPp->vercore_top__DOT__op_b_e) 
            >> 0x1fU));
    vlTOPp->vercore_top__DOT__u_alu__DOT__mulhsu_hi 
        = (IData)((0x1ffffffffULL & VL_SHIFTRS_QQI(33,33,32, 
                                                   (0x1ffffffffULL 
                                                    & VL_MULS_QQQ(33,33,33, 
                                                                  (0x1ffffffffULL 
                                                                   & VL_EXTENDS_QI(33,32, vlTOPp->vercore_top__DOT__op_a_e)), (QData)((IData)(vlTOPp->vercore_top__DOT__op_b_e)))), 0x20U)));
    vlTOPp->vercore_top__DOT__alu_y_e = ((0x80000U 
                                          & vlTOPp->vercore_top__DOT__idex_q[0U])
                                          ? 0U : ((0x40000U 
                                                   & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                   ? 
                                                  ((0x20000U 
                                                    & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                    ? 
                                                   ((0x10000U 
                                                     & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                     ? 0U
                                                     : 
                                                    ((0x8000U 
                                                      & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                      ? vlTOPp->vercore_top__DOT__u_alu__DOT__mulhsu_hi
                                                      : vlTOPp->vercore_top__DOT__u_alu__DOT__mulh_hi))
                                                    : 
                                                   ((0x10000U 
                                                     & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                     ? 
                                                    ((0x8000U 
                                                      & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                      ? vlTOPp->vercore_top__DOT__u_alu__DOT__mul_lo
                                                      : vlTOPp->vercore_top__DOT__op_b_e)
                                                     : 
                                                    ((0x8000U 
                                                      & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,5, vlTOPp->vercore_top__DOT__op_a_e, 
                                                                    (0x1fU 
                                                                     & vlTOPp->vercore_top__DOT__op_b_e))
                                                      : 
                                                     (vlTOPp->vercore_top__DOT__op_a_e 
                                                      >> 
                                                      (0x1fU 
                                                       & vlTOPp->vercore_top__DOT__op_b_e)))))
                                                   : 
                                                  ((0x20000U 
                                                    & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                    ? 
                                                   ((0x10000U 
                                                     & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                     ? 
                                                    ((0x8000U 
                                                      & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                      ? 
                                                     (vlTOPp->vercore_top__DOT__op_a_e 
                                                      << 
                                                      (0x1fU 
                                                       & vlTOPp->vercore_top__DOT__op_b_e))
                                                      : 
                                                     ((vlTOPp->vercore_top__DOT__op_a_e 
                                                       < vlTOPp->vercore_top__DOT__op_b_e)
                                                       ? 1U
                                                       : 0U))
                                                     : 
                                                    ((0x8000U 
                                                      & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                      ? 
                                                     (VL_LTS_III(1,32,32, vlTOPp->vercore_top__DOT__op_a_e, vlTOPp->vercore_top__DOT__op_b_e)
                                                       ? 1U
                                                       : 0U)
                                                      : 
                                                     (vlTOPp->vercore_top__DOT__op_a_e 
                                                      ^ vlTOPp->vercore_top__DOT__op_b_e)))
                                                    : 
                                                   ((0x10000U 
                                                     & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                     ? 
                                                    ((0x8000U 
                                                      & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                      ? 
                                                     (vlTOPp->vercore_top__DOT__op_a_e 
                                                      | vlTOPp->vercore_top__DOT__op_b_e)
                                                      : 
                                                     (vlTOPp->vercore_top__DOT__op_a_e 
                                                      & vlTOPp->vercore_top__DOT__op_b_e))
                                                     : 
                                                    ((0x8000U 
                                                      & vlTOPp->vercore_top__DOT__idex_q[0U])
                                                      ? 
                                                     (vlTOPp->vercore_top__DOT__op_a_e 
                                                      - vlTOPp->vercore_top__DOT__op_b_e)
                                                      : 
                                                     (vlTOPp->vercore_top__DOT__op_a_e 
                                                      + vlTOPp->vercore_top__DOT__op_b_e))))));
    vlTOPp->vercore_top__DOT__pc_next_f = ((IData)(vlTOPp->vercore_top__DOT__branch_taken_e)
                                            ? vlTOPp->vercore_top__DOT__branch_target_e
                                            : ((IData)(4U) 
                                               + vlTOPp->vercore_top__DOT__pc_f));
}

VL_INLINE_OPT void Vvercore_top::_combo__TOP__4(Vvercore_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvercore_top::_combo__TOP__4\n"); );
    Vvercore_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->vercore_top__DOT__icache_accept_valid = 
        ((IData)(vlTOPp->icache_valid) & (~ (IData)(vlTOPp->vercore_top__DOT__drop_icache_resp)));
    vlTOPp->vercore_top__DOT__load_data_m = ((0x400U 
                                              & vlTOPp->vercore_top__DOT__exmem_q[0U])
                                              ? ((0x200U 
                                                  & vlTOPp->vercore_top__DOT__exmem_q[0U])
                                                  ? vlTOPp->dcache_rdata
                                                  : 
                                                 ((0x100U 
                                                   & vlTOPp->vercore_top__DOT__exmem_q[0U])
                                                   ? 
                                                  ((0x20000U 
                                                    & vlTOPp->vercore_top__DOT__exmem_q[4U])
                                                    ? 
                                                   (0xffffU 
                                                    & (vlTOPp->dcache_rdata 
                                                       >> 0x10U))
                                                    : 
                                                   (0xffffU 
                                                    & vlTOPp->dcache_rdata))
                                                   : 
                                                  ((0U 
                                                    == 
                                                    (3U 
                                                     & ((vlTOPp->vercore_top__DOT__exmem_q[5U] 
                                                         << 0x10U) 
                                                        | (vlTOPp->vercore_top__DOT__exmem_q[4U] 
                                                           >> 0x10U))))
                                                    ? 
                                                   (0xffU 
                                                    & vlTOPp->dcache_rdata)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & ((vlTOPp->vercore_top__DOT__exmem_q[5U] 
                                                          << 0x10U) 
                                                         | (vlTOPp->vercore_top__DOT__exmem_q[4U] 
                                                            >> 0x10U))))
                                                     ? 
                                                    (0xffU 
                                                     & (vlTOPp->dcache_rdata 
                                                        >> 8U))
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (3U 
                                                       & ((vlTOPp->vercore_top__DOT__exmem_q[5U] 
                                                           << 0x10U) 
                                                          | (vlTOPp->vercore_top__DOT__exmem_q[4U] 
                                                             >> 0x10U))))
                                                      ? 
                                                     (0xffU 
                                                      & (vlTOPp->dcache_rdata 
                                                         >> 0x10U))
                                                      : 
                                                     (0xffU 
                                                      & (vlTOPp->dcache_rdata 
                                                         >> 0x18U)))))))
                                              : ((0x200U 
                                                  & vlTOPp->vercore_top__DOT__exmem_q[0U])
                                                  ? vlTOPp->dcache_rdata
                                                  : 
                                                 ((0x100U 
                                                   & vlTOPp->vercore_top__DOT__exmem_q[0U])
                                                   ? 
                                                  ((0x20000U 
                                                    & vlTOPp->vercore_top__DOT__exmem_q[4U])
                                                    ? 
                                                   ((0xffff0000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->dcache_rdata 
                                                                       >> 0x1fU)))) 
                                                        << 0x10U)) 
                                                    | (0xffffU 
                                                       & (vlTOPp->dcache_rdata 
                                                          >> 0x10U)))
                                                    : 
                                                   ((0xffff0000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->dcache_rdata 
                                                                       >> 0xfU)))) 
                                                        << 0x10U)) 
                                                    | (0xffffU 
                                                       & vlTOPp->dcache_rdata)))
                                                   : 
                                                  ((0U 
                                                    == 
                                                    (3U 
                                                     & ((vlTOPp->vercore_top__DOT__exmem_q[5U] 
                                                         << 0x10U) 
                                                        | (vlTOPp->vercore_top__DOT__exmem_q[4U] 
                                                           >> 0x10U))))
                                                    ? 
                                                   ((0xffffff00U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->dcache_rdata 
                                                                       >> 7U)))) 
                                                        << 8U)) 
                                                    | (0xffU 
                                                       & vlTOPp->dcache_rdata))
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & ((vlTOPp->vercore_top__DOT__exmem_q[5U] 
                                                          << 0x10U) 
                                                         | (vlTOPp->vercore_top__DOT__exmem_q[4U] 
                                                            >> 0x10U))))
                                                     ? 
                                                    ((0xffffff00U 
                                                      & ((- (IData)(
                                                                    (1U 
                                                                     & (vlTOPp->dcache_rdata 
                                                                        >> 0xfU)))) 
                                                         << 8U)) 
                                                     | (0xffU 
                                                        & (vlTOPp->dcache_rdata 
                                                           >> 8U)))
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (3U 
                                                       & ((vlTOPp->vercore_top__DOT__exmem_q[5U] 
                                                           << 0x10U) 
                                                          | (vlTOPp->vercore_top__DOT__exmem_q[4U] 
                                                             >> 0x10U))))
                                                      ? 
                                                     ((0xffffff00U 
                                                       & ((- (IData)(
                                                                     (1U 
                                                                      & (vlTOPp->dcache_rdata 
                                                                         >> 0x17U)))) 
                                                          << 8U)) 
                                                      | (0xffU 
                                                         & (vlTOPp->dcache_rdata 
                                                            >> 0x10U)))
                                                      : 
                                                     ((0xffffff00U 
                                                       & ((- (IData)(
                                                                     (1U 
                                                                      & (vlTOPp->dcache_rdata 
                                                                         >> 0x1fU)))) 
                                                          << 8U)) 
                                                      | (0xffU 
                                                         & (vlTOPp->dcache_rdata 
                                                            >> 0x18U)))))))));
    vlTOPp->vercore_top__DOT__mem_busy_m = (1U & ((
                                                   vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                   & ((vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                       >> 2U) 
                                                      | (vlTOPp->vercore_top__DOT__exmem_q[0U] 
                                                         >> 1U))) 
                                                  & (~ (IData)(vlTOPp->dcache_ready))));
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->vercore_top__DOT__branch_taken_e) 
                             << 3U) | (((IData)(vlTOPp->vercore_top__DOT__mem_busy_m) 
                                        << 2U) | ((0x7fffffeU 
                                                   & (((vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                        >> 5U) 
                                                       & ((0U 
                                                           != 
                                                           (0x1fU 
                                                            & ((vlTOPp->vercore_top__DOT__idex_q[1U] 
                                                                << 0xcU) 
                                                               | (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                                  >> 0x14U)))) 
                                                          << 1U)) 
                                                      & ((((0x1fU 
                                                            & ((vlTOPp->vercore_top__DOT__idex_q[1U] 
                                                                << 0xcU) 
                                                               | (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                                  >> 0x14U))) 
                                                           == 
                                                           (0x1fU 
                                                            & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                                << 0x11U) 
                                                               | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                  >> 0xfU)))) 
                                                          | ((0x1fU 
                                                              & ((vlTOPp->vercore_top__DOT__idex_q[1U] 
                                                                  << 0xcU) 
                                                                 | (vlTOPp->vercore_top__DOT__idex_q[0U] 
                                                                    >> 0x14U))) 
                                                             == 
                                                             (0x1fU 
                                                              & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
                                                                  << 0xcU) 
                                                                 | (vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                                    >> 0x14U))))) 
                                                         << 1U))) 
                                                  | (IData)(vlTOPp->vercore_top__DOT__icache_accept_valid))));
    vlTOPp->vercore_top__DOT__stall_f = vlTOPp->__Vtable1_vercore_top__DOT__stall_f
        [vlTOPp->__Vtableidx1];
    vlTOPp->vercore_top__DOT__stall_d = vlTOPp->__Vtable1_vercore_top__DOT__stall_d
        [vlTOPp->__Vtableidx1];
    vlTOPp->vercore_top__DOT__stall_e = vlTOPp->__Vtable1_vercore_top__DOT__stall_e
        [vlTOPp->__Vtableidx1];
    vlTOPp->vercore_top__DOT__stall_m = vlTOPp->__Vtable1_vercore_top__DOT__stall_m
        [vlTOPp->__Vtableidx1];
    vlTOPp->vercore_top__DOT__flush_d = vlTOPp->__Vtable1_vercore_top__DOT__flush_d
        [vlTOPp->__Vtableidx1];
    vlTOPp->vercore_top__DOT__flush_e = vlTOPp->__Vtable1_vercore_top__DOT__flush_e
        [vlTOPp->__Vtableidx1];
}

void Vvercore_top::_eval(Vvercore_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvercore_top::_eval\n"); );
    Vvercore_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vvercore_top::_change_request(Vvercore_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvercore_top::_change_request\n"); );
    Vvercore_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vvercore_top::_change_request_1(Vvercore_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvercore_top::_change_request_1\n"); );
    Vvercore_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vvercore_top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvercore_top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((icache_valid & 0xfeU))) {
        Verilated::overWidthError("icache_valid");}
    if (VL_UNLIKELY((dcache_ready & 0xfeU))) {
        Verilated::overWidthError("dcache_ready");}
}
#endif  // VL_DEBUG
