// =============================================================================
// CDlgQuickBar_CreateChildWidgets_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008a16b0
// Address:   0x008a16b0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / client QuickBar UI
// Generated: 2026-07-29 W21-R dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Tools: Ghidra decompile_function + read_memory (no disassemble_bytes).
// =============================================================================
//
// PURPOSE:
//   Virtual CreateChildWidgets-style builder for CDlgQuickBar host: allocate and
//   parent-attach chrome widgets (including two UI_QuickBar_CreateSlotButton
//   page buttons labeled 1/2), load hazard-bar/gauge/label XML skins, Y-reposition
//   +0x684, rebind page columns (FUN_008a0e10), restore or auto-pick selection.
//
// ABI:
//   __thiscall / __fastcall  ECX = CDlgQuickBar* host
//   void return; MSVC SEH LAB_009b98c0
//
// String evidence:
//   i_d_qb_2d_btn_inc.xml
//   i_d_qb_2d_wnd_hazard_bar.xml
//   i_d_qb_2d_wnd_hazard_inc.xml
//   i_d_qb_2d_wnd_hazard_gauge.xml
//   i_d_qb_2d_wnd_hazard_label.xml
//
// Vtable: slot at 0x00a4d320; nearby "Show Quick Menu" / "Hide Quick Menu".
// Scaffold: FUN_008a16b0.cpp (same CF).
// =============================================================================

// Authoritative CF follows raw aa_008a16b0 (live decompile ≡ 2026-07-23).
// Named stages for readability; vtbl offsets and FUN_* callees preserved.

void __fastcall CDlgQuickBar_CreateChildWidgets_Inferred(int *host /* ECX */)
{
  // SEH: ExceptionList = { LAB_009b98c0, ... }
  FUN_00792600();

  // --- mid widget +0x664 ---
  {
    void *p = operator_new(0x580);
    host[0x199] = (p == 0) ? 0 : FUN_0082f4a0();
  }

  // --- anchor pair +0x624 / +0x628 (0x488 each) with z-order bump ---
  for (int slot = 0x189; slot <= 0x18a; ++slot) {
    void *p = operator_new(0x488);
    int *w = (p == 0) ? 0 : (int *)FUN_007b5dd0();
    (**(code **)(*host + 0xa8))();          // parent attach
    if (w) {
      (**(code **)(*w + 0x28))();
      (**(code **)(*w + 0xfc))();
    }
    host[slot] = (int)w;
    int c = host[0x1a] + 1;
    host[0x1a] = c;
    host[0x1d] = (int)(float)-c;
    if (host[0x1c] < c) host[0x1c] = c;
    (**(code **)(*host + 0x3f4))();
  }

  // --- two 0x4cc button-class children +0x62c / +0x630 ---
  for (int slot = 0x18b; slot <= 0x18c; ++slot) {
    void *p = operator_new(0x4cc);
    int *w = (p == 0) ? 0 : (int *)FUN_0079c860();
    (**(code **)(*host + 0xa8))();
    if (w) {
      (**(code **)(*w + 0x28))();
      (**(code **)(*w + 0x74))();
      (**(code **)(*w + 0xfc))();
    }
    host[slot] = (int)w;
  }

  // --- +0x668 ---
  {
    void *p = operator_new(0x520);
    int w = (p == 0) ? 0 : FUN_008c4f10();
    host[0x19a] = w;
    (**(code **)(*host + 0xa8))();
    (**(code **)(*(int *)host[0x19a] + 0x43c))();
    (**(code **)(*(int *)host[0x19a] + 0xfc))();
  }

  // --- +0x634 inc button ---
  {
    void *p = operator_new(0x4cc);
    int w = (p == 0) ? 0 : FUN_0079c860();
    host[0x18d] = w;
    (**(code **)(*host + 0xa8))();
    (**(code **)(*(int *)host[0x18d] + 0x28))();   // "i_d_qb_2d_btn_inc.xml"
    (**(code **)(*(int *)host[0x18d] + 0x74))();   // id 0x9c42
    (**(code **)(*(int *)host[0x18d] + 0xfc))();   // scale 0.5f
  }

  // --- page buttons 0/1 via UI_QuickBar_CreateSlotButton (+0x66c / +0x670) ---
  // index 0: label "1"; index 1: label "2"; position via host metrics + scale floats
  // (full math in raw; DAT_00aaa67c≈0.000625, DAT_00aaa678≈0.000833)
  {
    void *p = operator_new(0x554);
    int w = (p == 0) ? 0 : FUN_00825bf0();         // UI_QuickBar_CreateSlotButton
    host[0x19b] = w;
    (**(code **)(*host + 0xa8))();
    (**(code **)(*(int *)host[0x19b] + 0x74))();   // 0x9c44
    (**(code **)(*(int *)host[0x19b] + 0x43c))();
    *(int *)(w + 0x500) = 0;
    if (*(int *)(w + 0x548) != 0) {
      // sprintf "%i" with 1 → label vtbl+0x1d8 / +0x34c
    }
    (**(code **)(*(int *)host[0x19b] + 0x444))();
    // position vtbl+0x134 / +0x118 using host[0x144..0x146] scales
  }
  {
    void *p = operator_new(0x554);
    int w = (p == 0) ? 0 : FUN_00825bf0();
    host[0x19c] = w;
    (**(code **)(*host + 0xa8))();
    (**(code **)(*(int *)host[0x19c] + 0x74))();   // 0x9c45
    (**(code **)(*(int *)host[0x19c] + 0x43c))();
    *(int *)(w + 0x500) = 1;
    if (*(int *)(w + 0x548) != 0) {
      // sprintf "%i" with 2
    }
    (**(code **)(*(int *)host[0x19c] + 0x444))();
    // position...
  }

  // --- hazard chrome ---
  (**(code **)(*host + 0x404))(host + 0x19d, "i_d_qb_2d_wnd_hazard_bar.xml", 0xffffffff);
  (**(code **)(*host + 0x404))(host + 0x19f, "i_d_qb_2d_wnd_hazard_inc.xml", 0xffffffff);
  {
    void *p = operator_new(0x4f8);
    int w = (p == 0) ? 0 : FUN_0097ffa0(p);
    host[0x1a0] = w;
    (**(code **)(*host + 0xa8))();
    (**(code **)(*(int *)host[0x1a0] + 0x28))();   // "i_d_qb_2d_wnd_hazard_gauge.xml"
    (**(code **)(*(int *)host[0x1a0] + 0x3b0))();  // 1.0f
  }
  (**(code **)(*host + 0x404))(host + 0x19e, "i_d_qb_2d_wnd_hazard_label.xml", 0xffffffff);
  // copy label text into host+0x523; z-order bump; host.vtbl+0x3f4(1)

  // --- +0x684 reposition target ---
  {
    void *p = operator_new(0x58c);
    int w = (p == 0) ? 0 : FUN_008b0ce0(p);
    host[0x1a1] = w;
    (**(code **)(*host + 0xa8))();
    (**(code **)(*(int *)host[0x1a1] + 0x43c))();
    // z-order bump; host.vtbl+0x3f4(1)
  }

  FUN_008a0370();                                  // Y-reposition +0x684
  int page = host[0x143];
  int prevCol = -1;
  if ((-1 < page) && (page < 10)) {
    prevCol = *(int *)(&DAT_00d1da38 + page * 4);
  }
  FUN_008a04b0();
  FUN_008a1110();
  FUN_008a0e10(host);                              // rebind 10 page columns
  (**(code **)(*host + 0x448))();
  DAT_00d1a9fc = 0xffffffff;
  if ((((prevCol < 0) || (9 < prevCol))
       || (*(int *)(host[prevCol + 399] + 0x548) == 0))
      || (*(int *)(host[prevCol + 399] + 0x548) == 6)) {
    FUN_008a0210(1);
  } else {
    FUN_00826780(1);                               // SetSelected (ECX residual → column)
  }
  if (DAT_00d1b6d8 != 0) {
    FUN_008a0770();
  }
  (**(code **)(*host + 0x34c))();
  // SEH pop
}
