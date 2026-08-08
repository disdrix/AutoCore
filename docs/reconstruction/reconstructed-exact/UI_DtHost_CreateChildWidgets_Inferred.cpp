// =============================================================================
// UI_DtHost_CreateChildWidgets_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008e1020
// Address:   0x008e1020  (autoassault.exe, image base 0x400000)
// Body:      0x008e1020-0x008e17be inclusive (1951 B / 0x79F)
// System:    inventory-transfer
// Generated: 2026-08-05 R13-014 dual seal (ASM-STRUCTURAL)
// Exactness: Control-flow recovered from disassembly; not bit-identical C.
// Bit-for-bit vs retail EXE: DEFERRED (decompiler FAILED: Overlapping input varnodes).
// Dispatch:  vtable DATA 0x00a3c3a0 -> this VA (virtual CreateChildWidgets*)
// =============================================================================

// External helpers (Ghidra names / dualed where known)
// void FUN_00792600(void* host);                         // residual host prep
// void* operator_new(size_t);                            // 0x00489892
// void* FUN_007b5dd0(void* p, int arg0);                 // CNDUIWindow base
// void* FUN_00864f20(void* p);                           // 0x4BC fx pane ctor
// void* FUN_0079c860(/* EAX context */);                 // 0x4CC button ctor
// void* FUN_008230b0(void* p);                           // tab window ctor 0x81C
// void  UI_TabChrome_SetSelected_Inferred(/* ESI=w, BL=sel, stack force */); // 00822cb0
// int   UI_Widget_MoveToFrontInParentGroup_Inferred(/* EDI=w */);            // 00756c90
// void  FUN_007fca10(/* EBX context 0x00d1a840 */);

// Vtbl helpers (offsets sealed; product names open)
// host  +0xa8  attach child
// host  +0x3f4 z-order / layout bump (arg 1)
// host  +0x404 create named chrome (icon_cover path; args out, path, -1)
// host  +0x114 apply optional global string/title path
// host  +0x448 pre-refresh hook
// host  +0x34c post-build refresh
// child +0x28  load XML path
// child +0x74  set control id
// child +0xfc  show/alpha (1, 0.5f)
// child +0x43c tab finalize
// child +0x94  tab activate hook

void __thiscall UI_DtHost_CreateChildWidgets_Inferred(void* host)
{
    // SEH: handler 0x009b72a8 (omitted)
    // this in ECX; kept in EBP in retail

    FUN_00792600(host);

    // --- Pattern (chrome children) ---
    //   p = operator_new(size);
    //   if (p) p = Ctor(p[, 0]);
    //   host->vtbl[0xa8/4](p);
    //   child->vtbl[0x28/4](xml_path);
    //   optional child->vtbl[0xfc/4](1, 0.5f);
    //   *(void**)((char*)host + slot) = p;
    //   bump host+0x68 / float host+0x74; maybe host+0x70; host->vtbl[+0x3f4](1)

    // Background / frames / instructions (0x488 / FUN_007b5dd0 unless noted)
    // +0x520  i_d_dt_2d_wnd_bg_fill.xml            @ 0x00a3c690
    // +0x524  i_d_dt_2d_wnd_fx.xml (0x4BC/00864f20)@ 0x00a3c678
    // +0x540  i_d_dt_2d_wnd_frame_instructions.xml @ 0x00a3c650
    // +0x544  i_d_dt_2d_wnd_frame_instructions_bottom.xml @ 0x00a3c624
    // +0x548  i_d_dt_2d_wnd_frame_image.xml        @ 0x00a3c604
    // +0x52c  i_d_dt_2d_wnd_bg_image.xml           @ 0x00a3c5e8
    // +0x528  i_d_dt_2d_wnd_bg_texture.xml         @ 0x00a3c5c8
    // +0x530  i_d_dt_2d_wnd_title.xml              @ 0x00a3c5b0
    // +0x530  i_d_dt_2d_wnd_icon.xml               @ 0x00a3c598  // OVERWRITES title
    // host.vtbl[+0x404](&tmp, i_d_dt_2d_wnd_icon_cover.xml @ 0x00a3c578, -1)
    // +0x538  i_d_dt_2d_wnd_instructions.xml       @ 0x00a3c558
    // +0x53c  i_d_dt_2d_wnd_instructions_bottom.xml@ 0x00a3c530

    // Close button (0x4CC / FUN_0079c860)
    // +0x504  i_d_dt_2d_btn_close.xml @ 0x00a3c518 ; control id 0x9c40

    // Tabs (0x81C / FUN_008230b0)
    // +0x54c  i_d_dt_2d_tab_crafting.xml    @ 0x00a3c4fc ; id 0x9c41
    //         UI_TabChrome_SetSelected_Inferred(force=1, selected=0)
    //         UI_Widget_MoveToFrontInParentGroup_Inferred(tab)
    // +0x550  i_d_dt_2d_tab_disciplines.xml @ 0x00a3c4dc ; id 0x9c42
    //         UI_TabChrome_SetSelected_Inferred(force=1, selected=1)
    //         tab->vtbl[+0x94]()

    // Optional global path (DAT_00d1b8a8)
    // if (DAT_00d1b8a8 && DAT_00d1b8a8->vtbl[+0x3d8]()) {
    //   t = DAT_00d1b8a8->vtbl[+0x120](&tmp, 1, 0);
    //   host->vtbl[+0x114](t);
    //   FUN_007fca10(); // EBX = 0x00d1a840
    // }

    // Post-build
    // host->vtbl[+0x448]();
    // host->vtbl[+0x34c]();
}

// Twin Ghidra name: FUN_008e1020
// Dual A/B: docs/reconstruction/reviews/A_aa_008e1020_UI_DtHost_CreateChildWidgets_Inferred.md
//           docs/reconstruction/reviews/B_aa_008e1020_UI_DtHost_CreateChildWidgets_Inferred.md
// Report:   docs/agents/task-dual-ab-008e1020-r13-report.md
