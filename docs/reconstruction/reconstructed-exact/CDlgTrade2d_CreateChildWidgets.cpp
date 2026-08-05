// =============================================================================
// CDlgTrade2d_CreateChildWidgets
// -----------------------------------------------------------------------------
// Stable ID: aa_008847f0
// Address:   0x008847f0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-29 ASM-STRUCTURAL (Ghidra decompile blocked)
// Exactness: Control-flow recovered from disassembly; not bit-identical C.
// Bit-for-bit vs retail EXE: DEFERRED (decompiler: Overlapping input varnodes).
// Dispatch:  vtable DATA 0x00a56ad8 → this VA
// =============================================================================

// External helpers (names as labeled in Ghidra / registry)
// void FUN_00792600(void* host);
// void* operator_new(size_t);
// void* FUN_007b5dd0(void* p, int arg);
// void* FUN_00864f20(void* p);
// void* FUN_0079c860();              // this in ESI, flag in EAX
// void* FUN_008609b0(void* p);
// void  FUN_00860700();              // this in ESI
// void* FUN_00795f20();              // this in ESI
// void* FUN_0097ffa0(void* p);
// void  InventoryGrid_SetOwnerFlag_Inferred(void* inv, int nFlag);

void __fastcall CDlgTrade2d_CreateChildWidgets(void* this_)
{
    // SEH frame: LAB_009b5699 (omitted)
    // EDI = this_

    FUN_00792600(this_);

    // --- Pattern (many children) ---
    //   p = operator_new(size);
    //   if (p) p = Ctor(p[, arg]);
    //   host->vtbl[0xa8/4](p);                 // attach
    //   child->vtbl[0x28/4](xml_path);         // load skin
    //   optional child->vtbl[0xfc/4](1, 0.5f); // alpha
    //   *(void**)((char*)this_ + slot) = p;
    //   bump this_+0x68 / float this_+0x74; maybe this_+0x70

    // Chrome / frames (size 0x488 base window unless noted)
    // +0x514 bg_fill        "i_d_t_2d_wnd_bg_fill.xml"
    // +0x518 fx (0x4bc)     "i_d_t_2d_wnd_fx.xml"       FUN_00864f20
    // +0x520 bg_texture     "i_d_t_2d_wnd_bg_texture.xml"
    // +0x51c icon           "i_d_t_2d_wnd_icon.xml"
    //        icon_cover     via host vtbl +0x404 (no durable slot)
    // +0x530 frame_1        "i_d_t_2d_wnd_frame_1.xml"
    // +0x534 frame_2        "i_d_t_2d_wnd_frame_2.xml"
    // +0x538 frame_3        "i_d_t_2d_wnd_frame_3.xml"
    // +0x53c frame_credits_you
    // +0x540 frame_credits_them

    // Ready buttons (0x4cc, FUN_0079c860) + vtbl +0x3b4(1) + alpha 0.5
    // +0x580 ready_you      "i_d_t_2d_btn_ready_you.xml"
    // +0x584 ready_them     "i_d_t_2d_btn_ready_them.xml"

    // --- Inventory grids (0x578, FUN_008609b0) ---
    // inv_you @ +0x588:
    //   grid+0x56c = *(DAT_00d1b6d8 + 0xce0);
    //   if inv: scale grid+0x50c / +0x510 from screen metrics
    //   grid.vtbl+0x444("i_d_t_2d_wnd_inv_you.xml");
    //   grid.vtbl+0x74(0x9c42);  // id 40002
    //   alpha 0.5; FUN_00860700(grid);
    //
    // inv_them @ +0x58c:
    //   root = *(void**)((char*)this_ + 0x510);
    //   grid+0x56c = root ? *(void**)((char*)root + 0xce0) : 0;
    //   scale dims if inv; FUN_00860700(grid);
    //   grid.vtbl+0x444("i_d_t_2d_wnd_inv_them.xml");
    //   grid.vtbl+0x74(0x9c43);  // id 40003
    //   if (grid+0x56c) InventoryGrid_SetOwnerFlag_Inferred(grid+0x56c, 6);
    //   grid.vtbl+0x300(0);

    // Credits:
    // +0x550 / +0x554  credits_bg you/them
    // icon_credits_you_1..4 via vtbl +0x404
    // +0x558..+0x564   edt_credits_you_1..4 (FUN_00795f20, id 0x9c41, digits 0..3)
    // icon_credits_them_1..4 via vtbl +0x404
    // +0x568..+0x574   credits_them digit windows

    // Offer / balance:
    // +0x544 offer_you
    // +0x548 sequential: offer_them, balance_title, balance (last write wins)
    // +0x590 gauge (0x4f8, FUN_0097ffa0) "i_d_t_2d_gauge_balance.xml"
    // +0x52c title

    // Action buttons:
    // +0x578 accept id 0x9c44
    // +0x57c cancel id 0x9c45
    // +0x504 close  id 0x9c40

    // Finish:
    // *(int*)((char*)this_ + 0x49c) = 0x9c40;
    // *((char*)this_ + 0x50c) = 0;
    // *((char*)this_ + 0x50d) = 0;
    // host.vtbl+0x448(); host.vtbl+0x34c();
    (void)this_;
}
