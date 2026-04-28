// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VVERCORE_TOP_H_
#define _VVERCORE_TOP_H_  // guard

#include "verilated.h"

//==========

class Vvercore_top__Syms;

//----------

VL_MODULE(Vvercore_top) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_OUT8(icache_req,0,0);
    VL_IN8(icache_valid,0,0);
    VL_OUT8(dcache_req,0,0);
    VL_OUT8(dcache_we,0,0);
    VL_OUT8(dcache_size,1,0);
    VL_IN8(dcache_ready,0,0);
    VL_OUT8(dbg_retire_valid,0,0);
    VL_OUT8(dbg_retire_rd_we,0,0);
    VL_OUT8(dbg_retire_rd_addr,4,0);
    VL_OUT(icache_addr,31,0);
    VL_IN(icache_rdata,31,0);
    VL_OUT(dcache_addr,31,0);
    VL_OUT(dcache_wdata,31,0);
    VL_IN(dcache_rdata,31,0);
    VL_OUT(dbg_retire_pc,31,0);
    VL_OUT(dbg_retire_instr,31,0);
    VL_OUT(dbg_retire_rd_data,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ vercore_top__DOT__drop_icache_resp;
    CData/*0:0*/ vercore_top__DOT__icache_accept_valid;
    CData/*0:0*/ vercore_top__DOT__stall_f;
    CData/*0:0*/ vercore_top__DOT__stall_d;
    CData/*0:0*/ vercore_top__DOT__stall_e;
    CData/*0:0*/ vercore_top__DOT__stall_m;
    CData/*0:0*/ vercore_top__DOT__flush_d;
    CData/*0:0*/ vercore_top__DOT__flush_e;
    CData/*1:0*/ vercore_top__DOT__fwd_a_sel;
    CData/*1:0*/ vercore_top__DOT__fwd_b_sel;
    CData/*0:0*/ vercore_top__DOT__regwrite_d;
    CData/*0:0*/ vercore_top__DOT__memread_d;
    CData/*0:0*/ vercore_top__DOT__memwrite_d;
    CData/*1:0*/ vercore_top__DOT__mem_size_d;
    CData/*0:0*/ vercore_top__DOT__alu_src_d;
    CData/*1:0*/ vercore_top__DOT__wb_sel_d;
    CData/*4:0*/ vercore_top__DOT__alu_op_d;
    CData/*0:0*/ vercore_top__DOT__branch_d;
    CData/*0:0*/ vercore_top__DOT__jump_d;
    CData/*0:0*/ vercore_top__DOT__jump_reg_d;
    CData/*0:0*/ vercore_top__DOT__branch_taken_e;
    CData/*0:0*/ vercore_top__DOT__mem_busy_m;
    IData/*31:0*/ vercore_top__DOT__pc_f;
    IData/*31:0*/ vercore_top__DOT__pc_next_f;
    WData/*64:0*/ vercore_top__DOT__ifid_q[3];
    IData/*31:0*/ vercore_top__DOT__imm_d;
    WData/*194:0*/ vercore_top__DOT__idex_d[7];
    WData/*194:0*/ vercore_top__DOT__idex_q[7];
    IData/*31:0*/ vercore_top__DOT__op_a_e;
    IData/*31:0*/ vercore_top__DOT__op_b_e_fwd;
    IData/*31:0*/ vercore_top__DOT__op_b_e;
    IData/*31:0*/ vercore_top__DOT__alu_y_e;
    IData/*31:0*/ vercore_top__DOT__branch_target_e;
    WData/*175:0*/ vercore_top__DOT__exmem_q[6];
    IData/*31:0*/ vercore_top__DOT__load_data_m;
    WData/*102:0*/ vercore_top__DOT__memwb_q[4];
    IData/*31:0*/ vercore_top__DOT__u_alu__DOT__mul_lo;
    IData/*31:0*/ vercore_top__DOT__u_alu__DOT__mulh_hi;
    IData/*31:0*/ vercore_top__DOT__u_alu__DOT__mulhsu_hi;
    IData/*31:0*/ vercore_top__DOT__u_regfile__DOT__regs[32];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ vercore_top__DOT____Vcellinp__u_regfile__rd_we;
    CData/*3:0*/ __Vtableidx1;
    CData/*0:0*/ __Vclklast__TOP__clk;
    static CData/*0:0*/ __Vtable1_vercore_top__DOT__stall_f[16];
    static CData/*0:0*/ __Vtable1_vercore_top__DOT__stall_d[16];
    static CData/*0:0*/ __Vtable1_vercore_top__DOT__stall_e[16];
    static CData/*0:0*/ __Vtable1_vercore_top__DOT__stall_m[16];
    static CData/*0:0*/ __Vtable1_vercore_top__DOT__flush_d[16];
    static CData/*0:0*/ __Vtable1_vercore_top__DOT__flush_e[16];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vvercore_top__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vvercore_top);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vvercore_top(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vvercore_top();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vvercore_top__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vvercore_top__Syms* symsp, bool first);
  private:
    static QData _change_request(Vvercore_top__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vvercore_top__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vvercore_top__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vvercore_top__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vvercore_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vvercore_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vvercore_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vvercore_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vvercore_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
