// =============================================================================
// UI_ArenaAdvHost_CreateChildWidgets_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00879ea0
// Address:   0x00879ea0  (autoassault.exe, image base 0x400000)
// Body:      0x00879ea0-0x0087b38a inclusive (5355 B / 0x14EB)
// System:    inventory-transfer (UI chrome; no inventory wire)
// Generated: 2026-08-05 R13-011 dual seal (ASM-STRUCTURAL)
// Exactness: Control-flow recovered from decompile + entry/exit/vtbl bytes; not bit-identical C.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dispatch:  vtable DATA 0x00a59500 -> this VA (virtual CreateChildWidgets*)
// =============================================================================

// External helpers (Ghidra names / dualed where known)
// void FUN_00792600(void* host);                         // residual host prep
// void* operator_new(size_t);
// void* FUN_007b5dd0(void* p, int arg);                  // CNDUIWindow base (0x488)
// void* FUN_00864f20(void* p);                           // FX pane ctor (0x4bc)
// void* FUN_0079c860(...);                               // button ctor (0x4cc)
// void* FUN_00795f20(...);                               // edit ctor (0x4a4)
// void* FUN_008230b0(void* p);                           // tab window ctor (0x81c)
// void  UI_TabChrome_SetSelected_Inferred(...);          // FUN_00822cb0 [dualed]
// int   UI_Widget_MoveToFrontInParentGroup_Inferred(...);// FUN_00756c90 [dualed]
// void* FUN_0078e2f0(...);                               // combo ctor (0x938)
// void  FUN_00879240(...);                               // residual post-build

// Vtbl helpers (offsets sealed; product names open)
// host  +0xa8  attach child
// host  +0x448 post-tree layout/hook
// host  +0x34c post-build refresh
// child +0x28  load XML path
// child +0x74  set control id
// child +0x94  activate / bring-forward style
// child +0xd4 / +0x3b4 / +0x3c8  radio group hooks
// child +0x1d0 max length / mode
// child +0x3ac charset / filter string
// child +0x43c combo/tab post-load
// edit  +0x48b numeric flag; +0x48c password-style flag

// Host flag cleared at entry: byte host+0x524 = 0

void __thiscall UI_ArenaAdvHost_CreateChildWidgets_Inferred(void* host)
{
    // SEH: LAB_009b92cd (omitted)
    // this in ECX; kept in EBP in retail

    *(unsigned char*)((char*)host + 0x524) = 0;
    FUN_00792600(host);

    // --- Pattern (56 children) ---
    //   p = operator_new(size);
    //   if (p) p = Ctor(p[, arg]);
    //   host->vtbl[0xa8/4](p);
    //   child->vtbl[0x28/4](xml_path);
    //   optional id / flags; *(void**)((char*)host + slot) = p;

    // Background / frames
    // +0x560  i_d_arena/i_d_arena_adv_wnd_bg_fill.xml          (0x488 / 007b5dd0)
    // +0x564  i_d_arena/i_d_arena_adv_wnd_fx.xml               (0x4bc / 00864f20)
    // +0x568  …wnd_bg_texture.xml
    // +0x56c  …wnd_logo.xml
    // +0x570  …wnd_bg_ladder.xml
    // +0x574  …wnd_bg_combo_boxes.xml
    // +0x578  …wnd_bg_values.xml
    // +0x57c  …wnd_bg_name.xml

    // Action buttons (0x4cc / 0079c860)
    // +0x580  …btn_join_now.xml        id 0x9c41
    // +0x584  …btn_spectate_now.xml    id 0x9c42
    // +0x588  …btn_host_now.xml        id 0x9c43

    // Match setup edits / labels
    // +0x59c  …edit_level_maximum.xml  (+0x48b=1; maxLen 3; charset DAT_00a59fd0)
    // +0x5a0  …label_level_maximum.xml
    // +0x5a4  …edit_match_name.xml
    // +0x5a8  …edit_match_password.xml (charset DAT_00a1419b; maxLen 8; +0x48c=1)
    // +0x5ac  …label_match_name.xml
    // +0x5b0  …label_match_password.xml
    // +0x5b4  …label_match_password_size.xml

    // Ladder / practice radios (0x4cc)
    // +0x5b8  …btn_radio_ladder.xml    id 0x9c44; group hooks; child+0x498=0
    // +0x5c0  …label_radio_ladder.xml
    // +0x5bc  …btn_radio_practice.xml  id 0x9c45; group hooks; child+0x498=0
    // +0x5c4  …label_radio_practice.xml
    // practice vtbl+0xd4(0); ladder vtbl+0x3c8(1,1)

    // Entry fee labels + edits (b/m/k/c)
    // +0x5c8 …label_entry_fee.xml
    // +0x5cc …label_entry_fee_b.xml / +0x5d0 m / +0x5d4 k / +0x5d8 c
    // +0x5dc …edit_entry_fee_b.xml … (+0x48b=1; maxLen 3; charset DAT_00a32460)
    // +0x5e0 m / +0x5e4 k / +0x5e8 c

    // Value maximum labels + edits (b/m/k/c)
    // +0x5ec …label_value_maximum.xml + b/m/k/c labels
    // +0x600 …edit_value_maximum_b.xml … (maxLen 3; charset DAT_00a59fd0)
    // +0x604 m / +0x608 k / +0x60c c

    // Close + instructions + dividers
    // +0x504  …btn_close.xml           id 40000 (0x9C40)
    // +0x610…+0x61c  label_inst_1..4
    // +0x620…+0x62c  divider_1..4

    // Tabs (0x81c / 008230b0)
    // +0x630  …tab_console.xml      id 0x9c48; TabChrome_SetSelected(force); MoveToFront
    // +0x634  …tab_tournament.xml   id 0x9c49; TabChrome_SetSelected(force); MoveToFront
    // +0x638  …tab_advanced.xml     id 0x9c4a; TabChrome_SetSelected(force); child vtbl+0x94

    // Match size / type (post-tab)
    // +0x58c  …label_match_size.xml
    // +0x590  …label_match_type.xml
    // +0x598  …cb_match_type.xml    id 0x9c47 (0x938 / 0078e2f0); vtbl+0x94
    // +0x594  …cb_match_size.xml    id 0x9c46 (0x938 / 0078e2f0); vtbl+0x94

    FUN_00879240();
    // host->vtbl[+0x448]();
    // host->vtbl[+0x34c]();
}
