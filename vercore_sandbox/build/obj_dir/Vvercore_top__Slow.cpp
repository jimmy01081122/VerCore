// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvercore_top.h for the primary calling header

#include "Vvercore_top.h"
#include "Vvercore_top__Syms.h"

//==========
CData/*0:0*/ Vvercore_top::__Vtable1_vercore_top__DOT__stall_f[16];
CData/*0:0*/ Vvercore_top::__Vtable1_vercore_top__DOT__stall_d[16];
CData/*0:0*/ Vvercore_top::__Vtable1_vercore_top__DOT__stall_e[16];
CData/*0:0*/ Vvercore_top::__Vtable1_vercore_top__DOT__stall_m[16];
CData/*0:0*/ Vvercore_top::__Vtable1_vercore_top__DOT__flush_d[16];
CData/*0:0*/ Vvercore_top::__Vtable1_vercore_top__DOT__flush_e[16];

VL_CTOR_IMP(Vvercore_top) {
    Vvercore_top__Syms* __restrict vlSymsp = __VlSymsp = new Vvercore_top__Syms(this, name());
    Vvercore_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vvercore_top::__Vconfigure(Vvercore_top__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vvercore_top::~Vvercore_top() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vvercore_top::_initial__TOP__1(Vvercore_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvercore_top::_initial__TOP__1\n"); );
    Vvercore_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->icache_req = 1U;
}

void Vvercore_top::_settle__TOP__3(Vvercore_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvercore_top::_settle__TOP__3\n"); );
    Vvercore_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp15[3];
    WData/*223:0*/ __Vtemp19[7];
    // Body
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
    vlTOPp->vercore_top__DOT__icache_accept_valid = 
        ((IData)(vlTOPp->icache_valid) & (~ (IData)(vlTOPp->vercore_top__DOT__drop_icache_resp)));
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
    __Vtemp15[0U] = ((0U == (0x1fU & ((vlTOPp->vercore_top__DOT__ifid_q[1U] 
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
    __Vtemp15[1U] = (IData)((((QData)((IData)(vlTOPp->vercore_top__DOT__ifid_q[1U])) 
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
    __Vtemp15[2U] = (IData)(((((QData)((IData)(vlTOPp->vercore_top__DOT__ifid_q[1U])) 
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
    __Vtemp19[0U] = ((0xfffffff8U & ((0xc0000000U & 
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
    __Vtemp19[1U] = ((7U & ((7U & (vlTOPp->vercore_top__DOT__ifid_q[0U] 
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
    vlTOPp->vercore_top__DOT__idex_d[0U] = __Vtemp19[0U];
    vlTOPp->vercore_top__DOT__idex_d[1U] = __Vtemp19[1U];
    vlTOPp->vercore_top__DOT__idex_d[2U] = ((7U & (
                                                   vlTOPp->vercore_top__DOT__ifid_q[0U] 
                                                   >> 0x1dU)) 
                                            | (0xfffffff8U 
                                               & (vlTOPp->vercore_top__DOT__imm_d 
                                                  << 3U)));
    vlTOPp->vercore_top__DOT__idex_d[3U] = ((7U & (vlTOPp->vercore_top__DOT__imm_d 
                                                   >> 0x1dU)) 
                                            | (0xfffffff8U 
                                               & (__Vtemp15[0U] 
                                                  << 3U)));
    vlTOPp->vercore_top__DOT__idex_d[4U] = ((7U & (
                                                   __Vtemp15[0U] 
                                                   >> 0x1dU)) 
                                            | (0xfffffff8U 
                                               & (__Vtemp15[1U] 
                                                  << 3U)));
    vlTOPp->vercore_top__DOT__idex_d[5U] = ((7U & (
                                                   __Vtemp15[1U] 
                                                   >> 0x1dU)) 
                                            | (0xfffffff8U 
                                               & (__Vtemp15[2U] 
                                                  << 3U)));
    vlTOPp->vercore_top__DOT__idex_d[6U] = (7U & (__Vtemp15[2U] 
                                                  >> 0x1dU));
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

void Vvercore_top::_eval_initial(Vvercore_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvercore_top::_eval_initial\n"); );
    Vvercore_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vvercore_top::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvercore_top::final\n"); );
    // Variables
    Vvercore_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vvercore_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vvercore_top::_eval_settle(Vvercore_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvercore_top::_eval_settle\n"); );
    Vvercore_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vvercore_top::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvercore_top::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst_n = VL_RAND_RESET_I(1);
    icache_req = VL_RAND_RESET_I(1);
    icache_addr = VL_RAND_RESET_I(32);
    icache_rdata = VL_RAND_RESET_I(32);
    icache_valid = VL_RAND_RESET_I(1);
    dcache_req = VL_RAND_RESET_I(1);
    dcache_we = VL_RAND_RESET_I(1);
    dcache_size = VL_RAND_RESET_I(2);
    dcache_addr = VL_RAND_RESET_I(32);
    dcache_wdata = VL_RAND_RESET_I(32);
    dcache_rdata = VL_RAND_RESET_I(32);
    dcache_ready = VL_RAND_RESET_I(1);
    dbg_retire_valid = VL_RAND_RESET_I(1);
    dbg_retire_pc = VL_RAND_RESET_I(32);
    dbg_retire_instr = VL_RAND_RESET_I(32);
    dbg_retire_rd_we = VL_RAND_RESET_I(1);
    dbg_retire_rd_addr = VL_RAND_RESET_I(5);
    dbg_retire_rd_data = VL_RAND_RESET_I(32);
    vercore_top__DOT__pc_f = VL_RAND_RESET_I(32);
    vercore_top__DOT__drop_icache_resp = VL_RAND_RESET_I(1);
    vercore_top__DOT__pc_next_f = VL_RAND_RESET_I(32);
    vercore_top__DOT__icache_accept_valid = VL_RAND_RESET_I(1);
    vercore_top__DOT__stall_f = VL_RAND_RESET_I(1);
    vercore_top__DOT__stall_d = VL_RAND_RESET_I(1);
    vercore_top__DOT__stall_e = VL_RAND_RESET_I(1);
    vercore_top__DOT__stall_m = VL_RAND_RESET_I(1);
    vercore_top__DOT__flush_d = VL_RAND_RESET_I(1);
    vercore_top__DOT__flush_e = VL_RAND_RESET_I(1);
    vercore_top__DOT__fwd_a_sel = VL_RAND_RESET_I(2);
    vercore_top__DOT__fwd_b_sel = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(65, vercore_top__DOT__ifid_q);
    vercore_top__DOT__imm_d = VL_RAND_RESET_I(32);
    vercore_top__DOT__regwrite_d = VL_RAND_RESET_I(1);
    vercore_top__DOT__memread_d = VL_RAND_RESET_I(1);
    vercore_top__DOT__memwrite_d = VL_RAND_RESET_I(1);
    vercore_top__DOT__mem_size_d = VL_RAND_RESET_I(2);
    vercore_top__DOT__alu_src_d = VL_RAND_RESET_I(1);
    vercore_top__DOT__wb_sel_d = VL_RAND_RESET_I(2);
    vercore_top__DOT__alu_op_d = VL_RAND_RESET_I(5);
    vercore_top__DOT__branch_d = VL_RAND_RESET_I(1);
    vercore_top__DOT__jump_d = VL_RAND_RESET_I(1);
    vercore_top__DOT__jump_reg_d = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(195, vercore_top__DOT__idex_d);
    VL_RAND_RESET_W(195, vercore_top__DOT__idex_q);
    vercore_top__DOT__op_a_e = VL_RAND_RESET_I(32);
    vercore_top__DOT__op_b_e_fwd = VL_RAND_RESET_I(32);
    vercore_top__DOT__op_b_e = VL_RAND_RESET_I(32);
    vercore_top__DOT__alu_y_e = VL_RAND_RESET_I(32);
    vercore_top__DOT__branch_target_e = VL_RAND_RESET_I(32);
    vercore_top__DOT__branch_taken_e = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(176, vercore_top__DOT__exmem_q);
    vercore_top__DOT__mem_busy_m = VL_RAND_RESET_I(1);
    vercore_top__DOT__load_data_m = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(103, vercore_top__DOT__memwb_q);
    vercore_top__DOT____Vcellinp__u_regfile__rd_we = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            vercore_top__DOT__u_regfile__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }}
    vercore_top__DOT__u_alu__DOT__mul_lo = VL_RAND_RESET_I(32);
    vercore_top__DOT__u_alu__DOT__mulh_hi = VL_RAND_RESET_I(32);
    vercore_top__DOT__u_alu__DOT__mulhsu_hi = VL_RAND_RESET_I(32);
    __Vtableidx1 = 0;
    __Vtable1_vercore_top__DOT__stall_f[0] = 1U;
    __Vtable1_vercore_top__DOT__stall_f[1] = 0U;
    __Vtable1_vercore_top__DOT__stall_f[2] = 1U;
    __Vtable1_vercore_top__DOT__stall_f[3] = 1U;
    __Vtable1_vercore_top__DOT__stall_f[4] = 1U;
    __Vtable1_vercore_top__DOT__stall_f[5] = 1U;
    __Vtable1_vercore_top__DOT__stall_f[6] = 1U;
    __Vtable1_vercore_top__DOT__stall_f[7] = 1U;
    __Vtable1_vercore_top__DOT__stall_f[8] = 1U;
    __Vtable1_vercore_top__DOT__stall_f[9] = 0U;
    __Vtable1_vercore_top__DOT__stall_f[10] = 1U;
    __Vtable1_vercore_top__DOT__stall_f[11] = 1U;
    __Vtable1_vercore_top__DOT__stall_f[12] = 1U;
    __Vtable1_vercore_top__DOT__stall_f[13] = 1U;
    __Vtable1_vercore_top__DOT__stall_f[14] = 1U;
    __Vtable1_vercore_top__DOT__stall_f[15] = 1U;
    __Vtable1_vercore_top__DOT__stall_d[0] = 0U;
    __Vtable1_vercore_top__DOT__stall_d[1] = 0U;
    __Vtable1_vercore_top__DOT__stall_d[2] = 1U;
    __Vtable1_vercore_top__DOT__stall_d[3] = 1U;
    __Vtable1_vercore_top__DOT__stall_d[4] = 1U;
    __Vtable1_vercore_top__DOT__stall_d[5] = 1U;
    __Vtable1_vercore_top__DOT__stall_d[6] = 1U;
    __Vtable1_vercore_top__DOT__stall_d[7] = 1U;
    __Vtable1_vercore_top__DOT__stall_d[8] = 0U;
    __Vtable1_vercore_top__DOT__stall_d[9] = 0U;
    __Vtable1_vercore_top__DOT__stall_d[10] = 1U;
    __Vtable1_vercore_top__DOT__stall_d[11] = 1U;
    __Vtable1_vercore_top__DOT__stall_d[12] = 1U;
    __Vtable1_vercore_top__DOT__stall_d[13] = 1U;
    __Vtable1_vercore_top__DOT__stall_d[14] = 1U;
    __Vtable1_vercore_top__DOT__stall_d[15] = 1U;
    __Vtable1_vercore_top__DOT__stall_e[0] = 0U;
    __Vtable1_vercore_top__DOT__stall_e[1] = 0U;
    __Vtable1_vercore_top__DOT__stall_e[2] = 0U;
    __Vtable1_vercore_top__DOT__stall_e[3] = 0U;
    __Vtable1_vercore_top__DOT__stall_e[4] = 1U;
    __Vtable1_vercore_top__DOT__stall_e[5] = 1U;
    __Vtable1_vercore_top__DOT__stall_e[6] = 1U;
    __Vtable1_vercore_top__DOT__stall_e[7] = 1U;
    __Vtable1_vercore_top__DOT__stall_e[8] = 0U;
    __Vtable1_vercore_top__DOT__stall_e[9] = 0U;
    __Vtable1_vercore_top__DOT__stall_e[10] = 0U;
    __Vtable1_vercore_top__DOT__stall_e[11] = 0U;
    __Vtable1_vercore_top__DOT__stall_e[12] = 1U;
    __Vtable1_vercore_top__DOT__stall_e[13] = 1U;
    __Vtable1_vercore_top__DOT__stall_e[14] = 1U;
    __Vtable1_vercore_top__DOT__stall_e[15] = 1U;
    __Vtable1_vercore_top__DOT__stall_m[0] = 0U;
    __Vtable1_vercore_top__DOT__stall_m[1] = 0U;
    __Vtable1_vercore_top__DOT__stall_m[2] = 0U;
    __Vtable1_vercore_top__DOT__stall_m[3] = 0U;
    __Vtable1_vercore_top__DOT__stall_m[4] = 1U;
    __Vtable1_vercore_top__DOT__stall_m[5] = 1U;
    __Vtable1_vercore_top__DOT__stall_m[6] = 1U;
    __Vtable1_vercore_top__DOT__stall_m[7] = 1U;
    __Vtable1_vercore_top__DOT__stall_m[8] = 0U;
    __Vtable1_vercore_top__DOT__stall_m[9] = 0U;
    __Vtable1_vercore_top__DOT__stall_m[10] = 0U;
    __Vtable1_vercore_top__DOT__stall_m[11] = 0U;
    __Vtable1_vercore_top__DOT__stall_m[12] = 1U;
    __Vtable1_vercore_top__DOT__stall_m[13] = 1U;
    __Vtable1_vercore_top__DOT__stall_m[14] = 1U;
    __Vtable1_vercore_top__DOT__stall_m[15] = 1U;
    __Vtable1_vercore_top__DOT__flush_d[0] = 0U;
    __Vtable1_vercore_top__DOT__flush_d[1] = 0U;
    __Vtable1_vercore_top__DOT__flush_d[2] = 0U;
    __Vtable1_vercore_top__DOT__flush_d[3] = 0U;
    __Vtable1_vercore_top__DOT__flush_d[4] = 0U;
    __Vtable1_vercore_top__DOT__flush_d[5] = 0U;
    __Vtable1_vercore_top__DOT__flush_d[6] = 0U;
    __Vtable1_vercore_top__DOT__flush_d[7] = 0U;
    __Vtable1_vercore_top__DOT__flush_d[8] = 1U;
    __Vtable1_vercore_top__DOT__flush_d[9] = 1U;
    __Vtable1_vercore_top__DOT__flush_d[10] = 1U;
    __Vtable1_vercore_top__DOT__flush_d[11] = 1U;
    __Vtable1_vercore_top__DOT__flush_d[12] = 1U;
    __Vtable1_vercore_top__DOT__flush_d[13] = 1U;
    __Vtable1_vercore_top__DOT__flush_d[14] = 1U;
    __Vtable1_vercore_top__DOT__flush_d[15] = 1U;
    __Vtable1_vercore_top__DOT__flush_e[0] = 0U;
    __Vtable1_vercore_top__DOT__flush_e[1] = 0U;
    __Vtable1_vercore_top__DOT__flush_e[2] = 1U;
    __Vtable1_vercore_top__DOT__flush_e[3] = 1U;
    __Vtable1_vercore_top__DOT__flush_e[4] = 0U;
    __Vtable1_vercore_top__DOT__flush_e[5] = 0U;
    __Vtable1_vercore_top__DOT__flush_e[6] = 1U;
    __Vtable1_vercore_top__DOT__flush_e[7] = 1U;
    __Vtable1_vercore_top__DOT__flush_e[8] = 1U;
    __Vtable1_vercore_top__DOT__flush_e[9] = 1U;
    __Vtable1_vercore_top__DOT__flush_e[10] = 1U;
    __Vtable1_vercore_top__DOT__flush_e[11] = 1U;
    __Vtable1_vercore_top__DOT__flush_e[12] = 1U;
    __Vtable1_vercore_top__DOT__flush_e[13] = 1U;
    __Vtable1_vercore_top__DOT__flush_e[14] = 1U;
    __Vtable1_vercore_top__DOT__flush_e[15] = 1U;
}
