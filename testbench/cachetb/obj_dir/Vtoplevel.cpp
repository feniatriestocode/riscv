// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoplevel.h for the primary calling header

#include "Vtoplevel.h"
#include "Vtoplevel__Syms.h"

//==========

void Vtoplevel::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtoplevel::eval\n"); );
    Vtoplevel__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../../src/cache_controller/../../src/pipelined/toplevel.v", 5, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtoplevel::_eval_initial_loop(Vtoplevel__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
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
            VL_FATAL_MT("../../src/cache_controller/../../src/pipelined/toplevel.v", 5, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtoplevel::_combo__TOP__3(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_combo__TOP__3\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->reset) & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheMemWen) 
                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__mask = 3U;
    }
    if (vlTOPp->reset) {
        vlTOPp->toplevel__DOT__cpu__DOT__cacheBytesAccess = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__cacheBytesAccess 
            = (((~ ((IData)(0xfU) << (4U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__addr) 
                                            << 2U)))) 
                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__cacheBytesAccess)) 
               | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__byteSelectVector) 
                  << (4U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__addr) 
                            << 2U))));
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__cacheBytesAccess = 0U;
    }
    if (((IData)(vlTOPp->reset) & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen))) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i = 2U;
    }
    if (((IData)(vlTOPp->reset) & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheMemWen) 
                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i = 2U;
    }
    if (((IData)(vlTOPp->reset) & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen) 
                                    | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen)) 
                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheMemWen)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__mask = 3U;
    }
    if (((IData)(vlTOPp->reset) & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen) 
                                    | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen)) 
                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheMemWen)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i = 2U;
    }
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__4(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__4\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__toplevel__DOT__Instruction_Mem__DOT__delay_counter 
        = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter;
    vlTOPp->__Vdly__toplevel__DOT__Instruction_Mem__DOT__delay_counter 
        = ((IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset)
            ? 0U : (0xfU & ((IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delayed)
                             ? (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter)
                             : ((IData)(1U) + (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter)))));
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__5(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__5\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__toplevel__DOT__Data_Mem__DOT__delay_counter 
        = vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter;
    vlTOPp->__Vdly__toplevel__DOT__Data_Mem__DOT__delay_counter 
        = ((IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset)
            ? 0U : (0xfU & ((IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delayed)
                             ? (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)
                             : ((IData)(1U) + (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)))));
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__6(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__6\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v1;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v8;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0;
    CData/*1:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1;
    CData/*1:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v12;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v4;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0;
    CData/*1:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1;
    CData/*1:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2;
    IData/*31:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0;
    WData/*127:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[4];
    WData/*127:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[4];
    QData/*63:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0;
    QData/*63:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1;
    // Body
    vlTOPp->__Vdly__toplevel__DOT__Data_Mem__DOT__flag 
        = vlTOPp->toplevel__DOT__Data_Mem__DOT__flag;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v4 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v8 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v12 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v1 = 0U;
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__i = 0x20U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen) {
            vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i = 2U;
        } else {
            if (vlTOPp->toplevel__DOT__cpu__DOT__IcacheMemWen) {
                vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i = 2U;
            }
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i = 4U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen) {
            vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i = 2U;
        } else {
            if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen) {
                vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i = 2U;
            } else {
                if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheMemWen) {
                    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i = 2U;
                }
            }
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i = 4U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen) {
            if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))) {
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                    vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j = 2U;
                }
            }
            if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))) {
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                    vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j = 2U;
                }
            }
        } else {
            if (vlTOPp->toplevel__DOT__cpu__DOT__IcacheMemWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j = 2U;
                    }
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j = 2U;
                    }
                }
            }
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j = 2U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen)))) {
            if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__l = 8U;
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__l = 8U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen)))) {
            if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][0U] 
                            = ((0xffffffffffffff00ULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin)))));
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][0U] 
                            = ((0xffffffffffff00ffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 8U))))) 
                                         << 8U));
                    }
                    if ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][0U] 
                            = ((0xffffffffff00ffffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                    }
                    if ((8U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][0U] 
                            = ((0xffffffff00ffffffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                    }
                    if ((0x10U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][0U] 
                            = ((0xffffff00ffffffffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                    }
                    if ((0x20U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][0U] 
                            = ((0xffff00ffffffffffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                    }
                    if ((0x40U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][0U] 
                            = ((0xff00ffffffffffffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                    }
                    if ((0x80U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][0U] 
                            = ((0xffffffffffffffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                    }
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][1U] 
                            = ((0xffffffffffffff00ULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin)))));
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][1U] 
                            = ((0xffffffffffff00ffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 8U))))) 
                                         << 8U));
                    }
                    if ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][1U] 
                            = ((0xffffffffff00ffffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                    }
                    if ((8U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][1U] 
                            = ((0xffffffff00ffffffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                    }
                    if ((0x10U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][1U] 
                            = ((0xffffff00ffffffffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                    }
                    if ((0x20U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][1U] 
                            = ((0xffff00ffffffffffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                    }
                    if ((0x40U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][1U] 
                            = ((0xff00ffffffffffffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                    }
                    if ((0x80U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[(3U 
                                                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))][1U] 
                            = ((0xffffffffffffffULL 
                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                [1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                    }
                }
            }
        }
    }
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen) {
            if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
                }
            }
            if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
                }
            }
        } else {
            if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
                    }
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
                    }
                }
            } else {
                if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheMemWen) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                            vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
                        }
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                            vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
    }
    vlTOPp->toplevel__DOT__dmem_done = ((IData)(vlTOPp->reset) 
                                        & (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_done));
    vlTOPp->toplevel__DOT__imem_ready = ((IData)(vlTOPp->reset) 
                                         & (0xfU == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter)));
    vlTOPp->toplevel__DOT__dmem_ready = ((IData)(vlTOPp->reset) 
                                         & (((0xfU 
                                              == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)) 
                                             & (IData)(vlTOPp->toplevel__DOT__dmem_ren)) 
                                            & (~ (IData)(vlTOPp->toplevel__DOT__dmem_wen))));
    vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state 
        = ((IData)(vlTOPp->reset) ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__next_state)
            : 0U);
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
        = ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)) 
                  | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))
            ? 0U : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutB);
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl 
        = ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
                  | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))
            ? 0U : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemWrite));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_inA_is_PC 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Jump 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUSrc 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Zero 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (0U == vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val));
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen)))) {
            if (vlTOPp->toplevel__DOT__cpu__DOT__IcacheMemWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0 
                        = (3U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr) 
                                 >> 2U));
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1 
                        = (3U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr) 
                                 >> 2U));
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v2 = 1U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen)))) {
            if (vlTOPp->toplevel__DOT__cpu__DOT__IcacheMemWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[0U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__IcacheDin[0U];
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[1U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__IcacheDin[1U];
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[2U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__IcacheDin[2U];
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[3U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__IcacheDin[3U];
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[0U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__IcacheDin[0U];
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[1U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__IcacheDin[1U];
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[2U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__IcacheDin[2U];
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[3U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__IcacheDin[3U];
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v2 = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Branch 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Branch));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_JumpJALR 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR));
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen)))) {
            if (vlTOPp->toplevel__DOT__cpu__DOT__IcacheMemWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0 = 0U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v2 = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7 
        = ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
                  | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))
            ? 0U : (0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                             >> 0x19U)));
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen)))) {
            if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen)))) {
                if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheMemWen) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0 
                            = (3U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr) 
                                     >> 2U));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1 
                            = (3U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr) 
                                     >> 2U));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                    }
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v2 = 1U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen)))) {
            if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen)))) {
                if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheMemWen) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0 = 0U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                    }
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v2 = 1U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen)))) {
            if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen)))) {
                if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheMemWen) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0 
                            = vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin;
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1 
                            = vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin;
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                    }
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2 = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut 
        = ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)) 
                  | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))
            ? 0U : (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                      ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                      : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC) 
                    + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs1 
        = ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
                  | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))
            ? 0U : (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                             >> 0xfU)));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_MemToReg 
        = ((IData)(vlTOPp->reset) & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemToReg));
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen)))) {
            if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0 = 0U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                }
            } else {
                if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheMemWen) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2 = 0U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                    }
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v4 = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3 
        = ((IData)(vlTOPp->reset) ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3)
            : 7U);
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen) {
            if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))) {
                __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0 = 1U;
                __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0 = 0U;
                __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0 
                    = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                }
            }
            if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))) {
                __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2 = 1U;
                __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2 = 1U;
                __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2 
                    = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3 = 0U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                }
            }
        } else {
            if (vlTOPp->toplevel__DOT__cpu__DOT__IcacheMemWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4 = 0U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                    }
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7 = 0U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr));
                    }
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v8 = 1U;
    }
    if (vlTOPp->reset) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut 
            = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__DMemOut;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut 
            = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut;
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut = 0U;
    }
    if ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdA = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdB = 0U;
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdA 
            = ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                 & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                    == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                 >> 0xfU)))) & (0U 
                                                != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
               [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                          >> 0xfU))]);
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdB 
            = ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                 & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                    == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                 >> 0x14U)))) & (0U 
                                                 != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
               [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                          >> 0x14U))]);
    }
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen) {
            if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0 = 1U;
                __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0 = 0U;
                __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0 
                    = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                }
            }
            if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2 = 1U;
                __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2 = 1U;
                __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2 
                    = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3 = 0U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                }
            }
        } else {
            if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4 = 0U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                    }
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6 
                        = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7 = 0U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                    }
                }
            } else {
                if (vlTOPp->toplevel__DOT__cpu__DOT__DcacheMemWen) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8 = 0U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                        if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                            __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9 = 1U;
                            __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9 = 1U;
                            __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9 
                                = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                        }
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10 
                            = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                        if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                            __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11 = 1U;
                            __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11 = 0U;
                            __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11 
                                = (3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr));
                        }
                    }
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v12 = 1U;
    }
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
             & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))) {
            __Vdlyvval__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData;
            __Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0 = 1U;
            __Vdlyvdim0__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr;
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v1 = 1U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0][0U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1][1U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[2U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[2U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[3U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[3U][1U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0][0U][0U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[0U];
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0][0U][1U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[1U];
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0][0U][2U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[2U];
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0][0U][3U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[3U];
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1][1U][0U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[0U];
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1][1U][1U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[1U];
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1][1U][2U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[2U];
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1][1U][3U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[3U];
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][0U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][0U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][1U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][1U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][0U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][0U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][1U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][1U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][0U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][0U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][1U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][1U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][0U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][0U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][1U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][1U][3U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[3U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0][0U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1][1U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[2U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[2U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[3U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[3U][1U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[3U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0][0U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1][1U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[0U][0U] = 0ULL;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[0U][1U] = 0ULL;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[1U][0U] = 0ULL;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[1U][1U] = 0ULL;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[2U][0U] = 0ULL;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[2U][1U] = 0ULL;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[3U][0U] = 0ULL;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[3U][1U] = 0ULL;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v4) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[3U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v8) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[3U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v12) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[3U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[__Vdlyvdim0__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[4U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[5U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[6U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[7U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[8U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[9U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0xaU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0xbU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0xcU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0xdU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0xeU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0xfU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x10U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x11U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x12U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x13U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x14U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x15U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x16U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x17U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x18U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x19U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x1aU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x1bU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x1cU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x1dU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x1eU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x1fU] = 0U;
    }
    vlTOPp->__Vtableidx3 = (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__cacheDirtyBit) 
                             << 7U) | (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__cacheHit) 
                                        << 6U) | ((
                                                   (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ren) 
                                                     & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__wen))) 
                                                    | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__wen) 
                                                       & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ren)))) 
                                                   << 5U) 
                                                  | (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__memWriteDone) 
                                                      << 4U) 
                                                     | (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__memReadReady) 
                                                         << 3U) 
                                                        | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))))));
    vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__next_state 
        = vlTOPp->__Vtable3_toplevel__DOT__cpu__DOT__Dcntr__DOT__next_state
        [vlTOPp->__Vtableidx3];
    vlTOPp->__Vtableidx4 = vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state;
    vlTOPp->toplevel__DOT__cpu__DOT__stall = vlTOPp->__Vtable4_toplevel__DOT__cpu__DOT__stall
        [vlTOPp->__Vtableidx4];
    vlTOPp->toplevel__DOT__cpu__DOT__cacheMemWen = 
        vlTOPp->__Vtable4_toplevel__DOT__cpu__DOT__cacheMemWen
        [vlTOPp->__Vtableidx4];
    vlTOPp->toplevel__DOT__cpu__DOT__memRen = vlTOPp->__Vtable4_toplevel__DOT__cpu__DOT__memRen
        [vlTOPp->__Vtableidx4];
    vlTOPp->toplevel__DOT__cpu__DOT__memWen = vlTOPp->__Vtable4_toplevel__DOT__cpu__DOT__memWen
        [vlTOPp->__Vtableidx4];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemWrite 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Branch 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Branch));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend 
        = ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
                  | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))
            ? 0U : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend);
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC 
        = ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
                  | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))
            ? 0U : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC);
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemToReg 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemToReg));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3 
        = ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)) 
                  | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))
            ? 7U : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3));
    vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne 
        = (3U & ((~ vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
                  [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))]) 
                 & ((~ vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
                     [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))]) 
                    - (IData)(1U))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
        = ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)) 
                  | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))
            ? 0U : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val);
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel 
        = (0xffU & ((0U == (3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut))
                     ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut
                     : ((1U == (3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut))
                         ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut 
                            >> 8U) : ((2U == (3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut))
                                       ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut 
                                          >> 0x10U)
                                       : (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut 
                                          >> 0x18U)))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half 
        = (0xffffU & ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut)
                       ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut 
                          >> 0x10U) : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut));
    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne 
        = (3U & ((~ vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
                  [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]) 
                 & ((~ vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
                     [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]) 
                    - (IData)(1U))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite 
        = ((IData)(vlTOPp->reset) & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr 
        = ((IData)(vlTOPp->reset) ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr)
            : 0U);
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData 
        = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_MemToReg)
            ? ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                    ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut
                    : ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                        ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half)
                        : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel)))
                : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                    ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut
                    : ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                        ? ((0xffff0000U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half) 
                                                          >> 0xfU)))) 
                                           << 0x10U)) 
                           | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half))
                        : ((0xffffff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel)))))
            : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut);
    if ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC = 0U;
    } else {
        if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC;
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemToReg 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3 
        = ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
                  | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))
            ? 0U : (7U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                          >> 0xcU)));
    vlTOPp->__Vtableidx2 = (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Zero) 
                             << 5U) | ((0x10U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                                 >> 0x1bU)) 
                                       | (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3) 
                                           << 1U) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Branch))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken 
        = vlTOPp->__Vtable2_toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken
        [vlTOPp->__Vtableidx2];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegWrite));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr 
        = ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)) 
                  | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))
            ? 0U : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst)
                     ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd)
                     : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2)));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc 
        = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_JumpJALR) 
           | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken));
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC_new;
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC = 0x400000U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp 
        = ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl))
            ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl))
                ? 0U : ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl))
                         ? ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                             ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                 ? ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                     ? 4U : 3U) : (
                                                   (1U 
                                                    & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                    ? 
                                                   ((0U 
                                                     == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7))
                                                     ? 6U
                                                     : 7U)
                                                    : 2U))
                             : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                 ? ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                     ? 9U : 8U) : (
                                                   (1U 
                                                    & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                    ? 5U
                                                    : 0U)))
                         : 0xcU)) : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl))
                                      ? ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl))
                                          ? 0xbU : 
                                         ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                           ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                               ? 0xaU
                                               : 1U)
                                           : 1U)) : 
                                     ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl))
                                       ? 0U : ((4U 
                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                     ? 4U
                                                     : 3U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                     ? 
                                                    ((0U 
                                                      == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7))
                                                      ? 6U
                                                      : 7U)
                                                     : 2U))
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                     ? 9U
                                                     : 8U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                     ? 5U
                                                     : 
                                                    ((0U 
                                                      == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7))
                                                      ? 0U
                                                      : 1U)))))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem = 0U;
    if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegWrite 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst 
        = ((~ (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassA 
        = ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite) 
             & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr))) 
            & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr) 
               == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs1)))
            ? 2U : ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                      & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr))) 
                     & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                        == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs1)))
                     ? 1U : 0U));
    if ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2 = 0U;
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd 
            = (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                        >> 7U));
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2 
            = (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                        >> 0x14U));
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA 
        = ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassA))
            ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdA
            : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassA))
                ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
        = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_inA_is_PC)
            ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC
            : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA);
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassB 
        = ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite) 
             & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr))) 
            & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr) 
               == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2)))
            ? 2U : ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                      & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr))) 
                     & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                        == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2)))
                     ? 1U : 0U));
    if ((1U & (((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid)) 
               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr = 0U;
    } else {
        if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__instr;
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutB 
        = ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassB))
            ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdB
            : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassB))
                ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB 
        = (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Jump) 
            | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR))
            ? 4U : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUSrc)
                     ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend
                     : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutB));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid = 1U;
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead) 
         & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
             == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                          >> 0xfU))) | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
                                        == (0x1fU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                             >> 0x14U)))))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid = 0U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex = 0U;
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead) 
         & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
             == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                          >> 0xfU))) | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
                                        == (0x1fU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                             >> 0x14U)))))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex = 1U;
    }
    if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i 
        = ((0xfffff000U & ((- (IData)((1U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                             >> 0x1fU)))) 
                           << 0xcU)) | (0xfffU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                  >> 0x14U)));
    vlTOPp->__Vtableidx1 = (0x7fU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr);
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Branch 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__Branch
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__Jump
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__unsigned_sub 
        = (0x1ffffffffULL & ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                             - (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend 
        = ((0x40U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
            ? ((0x20U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                ? ((0x10U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                    ? 0U : ((8U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                             ? ((4U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                 ? ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                     ? ((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                         ? ((0xfff00000U 
                                             & ((- (IData)(
                                                           (1U 
                                                            & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                               >> 0x1fU)))) 
                                                << 0x14U)) 
                                            | ((0xff000U 
                                                & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr) 
                                               | ((0x800U 
                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                      >> 9U)) 
                                                  | ((0x7e0U 
                                                      & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                         >> 0x14U)) 
                                                     | (0x1eU 
                                                        & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                           >> 0x14U))))))
                                         : 0U) : 0U)
                                 : 0U) : ((4U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                           ? ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                               ? ((1U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                                   ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i
                                                   : 0U)
                                               : 0U)
                                           : ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                               ? ((1U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                                   ? 
                                                  ((0xfffff000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                                      >> 0x1fU)))) 
                                                       << 0xcU)) 
                                                   | ((0x800U 
                                                       & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                          << 4U)) 
                                                      | ((0x7e0U 
                                                          & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                             >> 0x14U)) 
                                                         | (0x1eU 
                                                            & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                               >> 7U)))))
                                                   : 0U)
                                               : 0U))))
                : 0U) : ((0x20U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                          ? ((0x10U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                              ? ((8U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                  ? 0U : ((4U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                           ? ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                               ? ((1U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                                   : 0U)
                                               : 0U)
                                           : 0U)) : 
                             ((8U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                               ? 0U : ((4U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                        ? 0U : ((2U 
                                                 & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                                 ? 
                                                ((1U 
                                                  & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                                  ? 
                                                 ((0xfffff000U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                                     >> 0x1fU)))) 
                                                      << 0xcU)) 
                                                  | ((0xfe0U 
                                                      & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                         >> 0x14U)) 
                                                     | (0x1fU 
                                                        & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                           >> 7U))))
                                                  : 0U)
                                                 : 0U))))
                          : ((0x10U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                              ? ((8U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                  ? 0U : ((4U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                           ? ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                               ? ((1U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                                   : 0U)
                                               : 0U)
                                           : ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                               ? ((1U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                                   ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i
                                                   : 0U)
                                               : 0U)))
                              : ((8U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                  ? 0U : ((4U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                           ? 0U : (
                                                   (2U 
                                                    & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)
                                                     ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i
                                                     : 0U)
                                                    : 0U))))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid = 0U;
    if ((1U & (~ ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead) 
                  & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
                      == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                   >> 0xfU))) | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
                                                 == 
                                                 (0x1fU 
                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                     >> 0x14U)))))))) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid = 1U;
        }
    }
    if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc = 1U;
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead) 
         & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
             == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                          >> 0xfU))) | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
                                        == (0x1fU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                             >> 0x14U)))))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc = 0U;
    } else {
        if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc = 1U;
        }
    }
    if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__overflow 
        = (1U & (IData)((1ULL & (((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                   ? ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                                      + (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                   : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                       ? ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                                          - (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                       : ((2U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                           ? (QData)((IData)(
                                                             (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                              ^ vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                           : ((3U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                               ? (QData)((IData)(
                                                                 (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                  | vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                               : ((4U 
                                                   == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                   ? (QData)((IData)(
                                                                     (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                      & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                    ? (QData)((IData)(
                                                                      (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                       << 
                                                                       (0x1fU 
                                                                        & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                     ? (QData)((IData)(
                                                                       (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                      ? (QData)((IData)(
                                                                        VL_SHIFTRS_III(32,32,5, vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA, 
                                                                                (0x1fU 
                                                                                & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                       ? (QData)((IData)(
                                                                         (VL_LTS_III(1,32,32, vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA, vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)
                                                                           ? 1U
                                                                           : 0U)))
                                                       : 
                                                      ((9U 
                                                        == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                        ? (QData)((IData)(
                                                                          ((vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                            < vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)
                                                                            ? 1U
                                                                            : 0U)))
                                                        : 
                                                       ((0xaU 
                                                         == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                         ? (QData)((IData)(
                                                                           (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__unsigned_sub 
                                                                            >> 1U)))
                                                         : 
                                                        ((0xbU 
                                                          == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                          ? 
                                                         ((QData)((IData)(
                                                                          (0xfffffU 
                                                                           & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB 
                                                                              >> 0xcU)))) 
                                                          << 0xcU)
                                                          : 
                                                         ((0xcU 
                                                           == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                           ? 
                                                          ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                                                           + (QData)((IData)(
                                                                             (0xfffff000U 
                                                                              & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                           : 0ULL))))))))))))) 
                                 >> 0x20U))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val 
        = (IData)((0x1ffffffffULL & ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                      ? ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                                         + (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                      : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                          ? ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                                             - (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                          : ((2U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                              ? (QData)((IData)(
                                                                (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                 ^ vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                              : ((3U 
                                                  == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                  ? (QData)((IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                     | vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                   ? (QData)((IData)(
                                                                     (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                      & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                    ? (QData)((IData)(
                                                                      (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                       << 
                                                                       (0x1fU 
                                                                        & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                     ? (QData)((IData)(
                                                                       (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                      ? (QData)((IData)(
                                                                        VL_SHIFTRS_III(32,32,5, vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA, 
                                                                                (0x1fU 
                                                                                & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                       ? (QData)((IData)(
                                                                         (VL_LTS_III(1,32,32, vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA, vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)
                                                                           ? 1U
                                                                           : 0U)))
                                                       : 
                                                      ((9U 
                                                        == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                        ? (QData)((IData)(
                                                                          ((vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                            < vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)
                                                                            ? 1U
                                                                            : 0U)))
                                                        : 
                                                       ((0xaU 
                                                         == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                         ? (QData)((IData)(
                                                                           (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__unsigned_sub 
                                                                            >> 1U)))
                                                         : 
                                                        ((0xbU 
                                                          == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                          ? 
                                                         ((QData)((IData)(
                                                                          (0xfffffU 
                                                                           & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB 
                                                                              >> 0xcU)))) 
                                                          << 0xcU)
                                                          : 
                                                         ((0xcU 
                                                           == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                           ? 
                                                          ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                                                           + (QData)((IData)(
                                                                             (0xfffff000U 
                                                                              & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                           : 0ULL)))))))))))))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC_new 
        = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc)
            ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut
            : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump)
                ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                   + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)
                : ((IData)(4U) + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)));
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__7(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__7\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__Data_Mem__DOT__data__v0;
    QData/*63:0*/ __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v0;
    // Body
    __Vdlyvset__toplevel__DOT__Data_Mem__DOT__data__v0 = 0U;
    if (vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_done) {
        __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v0 
            = vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din;
        __Vdlyvset__toplevel__DOT__Data_Mem__DOT__data__v0 = 1U;
        __Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v0 
            = (0xfU & (IData)((QData)((IData)(vlTOPp->toplevel__DOT____Vcellout__cpu__dmem_block_address))));
    }
    if (__Vdlyvset__toplevel__DOT__Data_Mem__DOT__data__v0) {
        vlTOPp->toplevel__DOT__Data_Mem__DOT__data[__Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v0] 
            = __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v0;
    }
}

VL_INLINE_OPT void Vtoplevel::_combo__TOP__8(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_combo__TOP__8\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset 
        = (1U & ((~ (IData)(vlTOPp->reset)) | (~ (IData)(vlTOPp->toplevel__DOT__imem_ren))));
    vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset 
        = (1U & (((~ (IData)(vlTOPp->reset)) | ((~ (IData)(vlTOPp->toplevel__DOT__dmem_wen)) 
                                                & (~ (IData)(vlTOPp->toplevel__DOT__dmem_ren)))) 
                 | ((IData)(vlTOPp->toplevel__DOT__dmem_wen) 
                    & (IData)(vlTOPp->toplevel__DOT__dmem_ren))));
    vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[0U] = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[1U] = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[2U] = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[3U] = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg = 0U;
    if (((IData)(vlTOPp->reset) & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen))) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg 
            = ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg)) 
               | (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
                  [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))] 
                  & (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                     [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))]
                     [0U] == (3U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr) 
                                    >> 2U)))));
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg 
            = ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg)) 
               | (0xfffffffeU & (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
                                 [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))] 
                                 & ((vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                     [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))]
                                     [1U] == (3U & 
                                              ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr) 
                                               >> 2U))) 
                                    << 1U))));
        if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))) {
            vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[0U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))]
                [0U][0U];
            vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[1U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))]
                [0U][1U];
            vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[2U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))]
                [0U][2U];
            vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[3U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))]
                [0U][3U];
        }
        if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))) {
            vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[0U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))]
                [1U][0U];
            vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[1U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))]
                [1U][1U];
            vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[2U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))]
                [1U][2U];
            vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[3U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))]
                [1U][3U];
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict = 0U;
    if (((IData)(vlTOPp->reset) & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheMemWen) 
                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen)))) {
        if ((3U == vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
             [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))])) {
            vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict 
                = ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict)) 
                   | (0U == (1U & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
                             [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))])));
            vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict 
                = ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict)) 
                   | ((1U == (3U & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
                              [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))])) 
                      << 1U));
        } else {
            vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict 
                = ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict)) 
                   | (0U == (1U & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
                             [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))])));
            vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict 
                = ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict)) 
                   | ((1U == (3U & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
                              [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))])) 
                      << 1U));
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__DcacheDirtyBit = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout = 0ULL;
    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict = 0U;
    if (((IData)(vlTOPp->reset) & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen) 
                                    | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen)) 
                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheMemWen)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg 
            = ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg)) 
               | ((vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                   [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                   [0U] == (3U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr) 
                                  >> 2U))) & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
                  [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]));
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict 
            = ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict)) 
               | ((3U == vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
                   [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))])
                   ? (0U == (1U & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
                             [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]))
                   : (0U == (1U & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
                             [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]))));
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg 
            = ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg)) 
               | (0xfffffffeU & (((vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                   [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                                   [1U] == (3U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr) 
                                                  >> 2U))) 
                                  << 1U) & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
                                 [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))])));
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict 
            = ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict)) 
               | (((3U == vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
                    [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))])
                    ? (1U == (3U & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
                              [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]))
                    : (1U == (3U & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
                              [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]))) 
                  << 1U));
        if ((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
            if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                    [0U];
                vlTOPp->toplevel__DOT__cpu__DOT__DcacheDirtyBit 
                    = (1U & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
                       [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]);
            }
            vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
            if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                    [1U];
                vlTOPp->toplevel__DOT__cpu__DOT__DcacheDirtyBit 
                    = (1U & (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
                             [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))] 
                             >> 1U));
            }
        } else {
            if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                    [0U];
                vlTOPp->toplevel__DOT__cpu__DOT__DcacheDirtyBit 
                    = (1U & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
                       [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]);
            }
            vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__m = 2U;
            if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))]
                    [1U];
                vlTOPp->toplevel__DOT__cpu__DOT__DcacheDirtyBit 
                    = (1U & (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
                             [(3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))] 
                             >> 1U));
            }
        }
    }
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__cacheMemWen) {
            vlTOPp->toplevel__DOT__cpu__DOT__cacheDin 
                = vlTOPp->toplevel__DOT__cpu__DOT__memDout;
            if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__wen) 
                 & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ren)))) {
                vlTOPp->toplevel__DOT__cpu__DOT__cacheDin 
                    = (((~ (0xffffffffULL << (0x20U 
                                              & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__addr) 
                                                 << 5U)))) 
                        & vlTOPp->toplevel__DOT__cpu__DOT__cacheDin) 
                       | ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__din)) 
                          << (0x20U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__addr) 
                                       << 5U))));
            }
        } else {
            vlTOPp->toplevel__DOT__cpu__DOT__cacheDin = 0ULL;
            vlTOPp->toplevel__DOT__cpu__DOT__cacheDin 
                = (((~ (0xffffffffULL << (0x20U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__addr) 
                                                   << 5U)))) 
                    & vlTOPp->toplevel__DOT__cpu__DOT__cacheDin) 
                   | ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__din)) 
                      << (0x20U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__addr) 
                                   << 5U))));
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__cacheDin = 0ULL;
    }
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__9(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__9\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter 
        = vlTOPp->__Vdly__toplevel__DOT__Instruction_Mem__DOT__delay_counter;
    vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delayed 
        = (0xfU == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter));
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__10(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__10\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter 
        = vlTOPp->__Vdly__toplevel__DOT__Data_Mem__DOT__delay_counter;
    vlTOPp->toplevel__DOT__Data_Mem__DOT__delayed = 
        (0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter));
    vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_done 
        = (((0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)) 
            & (~ (IData)(vlTOPp->toplevel__DOT__dmem_ren))) 
           & (IData)(vlTOPp->toplevel__DOT__dmem_wen));
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__11(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__11\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        if ((1U & ((~ (IData)(vlTOPp->toplevel__DOT__dmem_wen)) 
                   | (IData)(vlTOPp->toplevel__DOT__dmem_ren)))) {
            vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din = 0ULL;
            vlTOPp->__Vdly__toplevel__DOT__Data_Mem__DOT__flag = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__flag)))) {
                vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din 
                    = (QData)((IData)(vlTOPp->toplevel__DOT____Vcellout__cpu__dmem_din));
                vlTOPp->__Vdly__toplevel__DOT__Data_Mem__DOT__flag = 1U;
            }
        }
    } else {
        vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din = 0ULL;
        vlTOPp->__Vdly__toplevel__DOT__Data_Mem__DOT__flag = 0U;
    }
    vlTOPp->toplevel__DOT__Data_Mem__DOT__flag = vlTOPp->__Vdly__toplevel__DOT__Data_Mem__DOT__flag;
}

void Vtoplevel::_eval(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_eval\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset))))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset))))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    vlTOPp->_combo__TOP__8(vlSymsp);
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset))))) {
        vlTOPp->_sequent__TOP__9(vlSymsp);
        vlTOPp->__Vm_traceActivity[4U] = 1U;
    }
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset))))) {
        vlTOPp->_sequent__TOP__10(vlSymsp);
        vlTOPp->__Vm_traceActivity[5U] = 1U;
    }
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__11(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset 
        = vlTOPp->__VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset 
        = vlTOPp->__VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
    vlTOPp->__VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset 
        = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset;
    vlTOPp->__VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset 
        = vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset;
}

VL_INLINE_OPT QData Vtoplevel::_change_request(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_change_request\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtoplevel::_change_request_1(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_change_request_1\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset)
         | (vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset));
    VL_DEBUG_IF( if(__req && ((vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset))) VL_DBG_MSGF("        CHANGE: ../../src/memories/Imem.v:22: toplevel.Instruction_Mem.counter_reset\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset))) VL_DBG_MSGF("        CHANGE: ../../src/memories/Dmem.v:26: toplevel.Data_Mem.counter_reset\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset 
        = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset;
    vlTOPp->__Vchglast__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset 
        = vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset;
    return __req;
}

#ifdef VL_DEBUG
void Vtoplevel::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
