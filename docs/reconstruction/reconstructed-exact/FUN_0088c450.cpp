// =============================================================================
// FUN_0088c450
// -----------------------------------------------------------------------------
// Stable ID: aa_0088c450
// Address:   0x0088c450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088c450 @ 0x0088c450
// Stable ID: aa_0088c450
// Embedded strings (evidence for future rename):
//   - "i_d_sum_wnd_bg_texture.xml"
//   - "i_d_sum_gauge_hp.xml"
//   - "i_d_sum_wnd_name.xml"
//   - "i_d_sum_gauge_time.xml"
//   - "i_d_sum_wnd_cover.xml"
//   - "i_d_sum_btn_attack.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~161 non-empty decompiler lines.
//  - Control keywords: if×16, return×1.
//  - Notable callees: FUN_0079c860×4, FUN_007b5dd0×3, FUN_00792600, FUN_0088c340, FUN_0088c450, FUN_0097ffa0, UI_CooldownGaugeWidget_ctor.
//  - Strings: "i_d_sum_wnd_bg_texture.xml"; "i_d_sum_gauge_hp.xml"; "i_d_sum_wnd_name.xml"; "i_d_sum_gauge_time.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall FUN_0088c450(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5a2f;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  local_4 = 0xffffffff;

  param_1[0x143] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x143] + 0x28))("i_d_sum_wnd_bg_texture.xml");

  (**(code **)(*(int *)param_1[0x143] + 0xfc))(1,0x3f000000);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x4f8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0097ffa0(pvVar1);

  }

  param_1[0x147] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x147] + 0x28))("i_d_sum_gauge_hp.xml");

  (**(code **)(*(int *)param_1[0x147] + 0x74))(0x9c44);

  (**(code **)(*(int *)param_1[0x147] + 0xfc))(1,0x3f000000);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x145] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x145] + 0x28))("i_d_sum_wnd_name.xml");

  (**(code **)(*(int *)param_1[0x145] + 0x74))(0x9c44);

  (**(code **)(*(int *)param_1[0x145] + 0xfc))(1,0x3f000000);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x4bc);

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    pvVar1 = UI_CooldownGaugeWidget_ctor(pvVar1);

  }

  param_1[0x148] = (int)pvVar1;

  (**(code **)(*param_1 + 0xa8))(pvVar1);

  (**(code **)(*(int *)param_1[0x148] + 0x28))("i_d_sum_gauge_time.xml");

  (**(code **)(*(int *)param_1[0x148] + 0x74))(0x9c45);

  (**(code **)(*(int *)param_1[0x148] + 0xfc))(1,0x3f000000);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x144] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x144] + 0x28))("i_d_sum_wnd_cover.xml");

  (**(code **)(*(int *)param_1[0x144] + 0xfc))(1,0x3f000000);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x149] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x149] + 0x28))("i_d_sum_btn_attack.xml");

  (**(code **)(*(int *)param_1[0x149] + 0x74))(0x9c41);

  (**(code **)(*(int *)param_1[0x149] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x14a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14a] + 0x28))("i_d_sum_btn_guard.xml");

  (**(code **)(*(int *)param_1[0x14a] + 0x74))(0x9c42);

  (**(code **)(*(int *)param_1[0x14a] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x14b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14b] + 0x28))("i_d_sum_btn_dismiss.xml");

  (**(code **)(*(int *)param_1[0x14b] + 0x74))(0x9c43);

  pvVar3 = (void *)0x1;

  (**(code **)(*(int *)param_1[0x14b] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x14c] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14c] + 0x28))("i_d_sum_btn_minimize.xml");

  (**(code **)(*(int *)param_1[0x14c] + 0x74))(40000);

  (**(code **)(*(int *)param_1[0x14c] + 0xfc))(1,0x3f000000);

  (**(code **)(*param_1 + 0x448))();

  if (DAT_00af9300 == '\x01') {

    FUN_0088c340();

    iVar2 = (**(code **)(*param_1 + 0xe8))();

    if (iVar2 == -1) {

      (**(code **)(*param_1 + 0xcc))(0);

    }

  }

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar3;

  return;

}
