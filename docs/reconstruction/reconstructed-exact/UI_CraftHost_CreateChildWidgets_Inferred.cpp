// =============================================================================
// UI_CraftHost_CreateChildWidgets_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008e6b50
// Address:   0x008e6b50  (autoassault.exe, image base 0x400000)
// Body:      0x008e6b50-0x008e811f inclusive (5584 B / 0x15D0)
// System:    inventory-transfer
// Generated: 2026-08-05 R11-036 dual seal (ASM-STRUCTURAL)
// Exactness: Control-flow recovered from disassembly; not bit-identical C.
// Bit-for-bit vs retail EXE: DEFERRED (decompiler temps untrustworthy; large body).
// Dispatch:  vtable DATA 0x00a3aca8 -> this VA (virtual CreateChildWidgets*)
// =============================================================================

// External helpers (Ghidra names / dualed where known)
// void FUN_00792600(void* host);                         // residual host prep
// void* operator_new(size_t);
// void* FUN_007b5dd0(void* p, int arg);                  // CNDUIWindow base
// void* CNDUIWndBuffered_Ctor_Inferred(void* p, ...);    // FUN_0078caf0
// void* FUN_0079c860(...);
// void* FUN_0078b6e0(...);
// void* FUN_0078f890(...);
// void* FUN_008230b0(void* p);                           // tab window ctor
// void  FUN_00822cb0(int flag);
// void  FUN_00756c90(...);
// void  FUN_007fbe50(...);
// void  FUN_007fca10(...);
// void  UI_CraftHost_BindResolvedObject_Inferred(void* host, void* object); // FUN_008e5990
// uint8 FUN_0052eb90(void* mgr, void* object);           // residual gate

// Vtbl helpers (offsets sealed; product names open)
// host  +0xa8  attach child
// host  +0x3f4 z-order / layout bump (arg 1)
// host  +0x404 create named chrome (icon_cover path)
// host  +0x114 apply player string/title path
// host  +0x34c post-build refresh
// child +0x28  load XML path
// child +0x74  set control id
// child +0xfc  show/alpha (1, 0.5f)
// child +0xcc  hide/zero-style
// child +0x114 / +0x11c position apply
// child +0x140 query size pair -> host+0x7c4/+0x7c8
// child +0x1a8 geo sub-object (buffered); byte +0x78 cleared
// child +0x43c / +0x474 / +0x4a0 / +0x94 tab/list hooks

void __thiscall UI_CraftHost_CreateChildWidgets_Inferred(void* host)
{
    // SEH: LAB_009ba671 (omitted)
    // this in ECX; kept in EBP in retail

    FUN_00792600(host);

    // --- Pattern (many children) ---
    //   p = operator_new(size);
    //   if (p) p = Ctor(p[, arg]);
    //   host->vtbl[0xa8/4](p);
    //   child->vtbl[0x28/4](xml_path);
    //   optional child->vtbl[0xfc/4](1, 0.5f);
    //   *(void**)((char*)host + slot) = p;
    //   bump host+0x68 / float host+0x74; maybe host+0x70; host->vtbl[+0x3f4](1)

    // Background / frames (0x488 / FUN_007b5dd0 unless noted)
    // +0x50c  i_d_craft_2d_wnd_bg_fill.xml
    // +0x514  i_d_craft_2d_wnd_bg_texture.xml
    // +0x518  craft wnd xml @ 0x00a3b680
    // +0x74c  craft wnd xml @ 0x00a3b660

    // Geo pane (0x4FC / CNDUIWndBuffered_Ctor_Inferred FUN_0078caf0)
    // +0x520  i_d_craft_2d_wnd_geo.xml ; id 0x9c45
    //         sub = vtbl+0x1a8(); *(u8*)(sub+0x78) = 0

    // Item header labels
    // +0x524  i_d_craft_2d_wnd_item_name.xml ; id 0x9c45
    // +0x778  item disc bar family
    // +0x774  i_d_craft_2d_wnd_item_disc_name.xml
    // +0x780  i_d_craft_2d_wnd_item_diff_level.xml
    // +0x77c  i_d_craft_2d_wnd_item_diff_name.xml
    // +0x528  i_d_craft_2d_wnd_item_success_percent.xml
    // size pair from +0x778 vtbl+0x140 -> host+0x7c4 / +0x7c8

    // Object preview stack (parent bind show/hide uses +0x530 / +0x54c)
    // +0x530  object_background_base
    // +0x534..+0x544  object_background_enh1..enh5  (vtbl+0xcc hide-init)
    // +0x54c  object_label_base
    // +0x550..+0x560  object_label_enh1..enh5

    // --- 5 material component rows ---
    // ESI = host+0x5b8; EBX = 0..4; ESI += 4 each
    // XML: i_d_craft_2d_wnd_item_component.xml
    // first column: *(host + 0x568 + 4*i)   // BindResolvedObject clears this bank
    // positions: base host+0x78c..+0x7c0 * index; scale DAT_00d1e818/1c * DAT_00aaa67c/78
    // additional per-row widgets at ESI+0x14 / +0x28 / +0x3c / +0x50 (same XML family)

    // Lists / buttons / dividers / experiment chrome (0x4CC, 0x9A8, 0x954, 0x488)
    // +0x504 / +0x748 ... craftable list/scroll family
    // exp_instructions, label_experimentation, dividers, btn_assemble, btn_close
    // icon + icon_cover (cover via host vtbl+0x404)

    // Tabs (0x81C / FUN_008230b0)
    // +0x784  i_d_craft_2d_tab_crafting.xml    ; id 0x9c43 ; FUN_00822cb0(1); vtbl+0x94
    // +0x788  i_d_craft_2d_tab_disciplines.xml ; id 0x9c44 ; FUN_00822cb0(1)
    // FUN_00756c90 / FUN_007fbe50 around tab finalization

    // Optional player/global path
    // if (DAT_00d1b8b4 && DAT_00d1b8b4->vtbl[+0x3d8]()) {
    //   t = DAT_00d1b8b4->vtbl[+0x120](&tmp, 1, 0);
    //   host->vtbl[+0x114](t);
    //   FUN_007fca10();
    // }

    // Rebind current object pointer (nullable / prior selection)
    UI_CraftHost_BindResolvedObject_Inferred(
        host, *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0x7cc));

    // Capability / gate byte used by later craft host logic
    {
        void* object = *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0x7cc);
        void* mgr = *reinterpret_cast<void**>(0x00d1b6d8);
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(host) + 0x7e2) =
            static_cast<unsigned char>(FUN_0052eb90(mgr, object));
    }

    // host->vtbl[+0x34c]();  // post-build refresh
    // SEH epilogue; RET
}
