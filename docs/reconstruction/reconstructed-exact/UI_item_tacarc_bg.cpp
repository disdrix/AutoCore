// =============================================================================
// UI_item_tacarc_bg
// -----------------------------------------------------------------------------
// Stable ID: aa_0084ca70
// Address:   0x0084ca70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_item_tacarc_bg @ 0x0084ca70
// Stable ID: aa_0084ca70
// Embedded strings (evidence for future rename):
//   - "i_d_item_2d_wnd_debug.xml"
//   - "i_d_item_2d_wnd_frame.xml"
//   - "i_d_item_2d_wnd_geo_bg.xml"
//   - "i_d_item_2d_wnd_geo.xml"
//   - "i_d_item_2d_wnd_tacarc_bg.xml"
//   - "i_d_item_2d_wnd_tacarc.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~231 non-empty decompiler lines.
//  - Control keywords: if×23, return×1.
//  - Notable callees: FUN_007b5dd0×11, FUN_00792600, FUN_0079c860, FUN_008345c0, FUN_0083a760, FUN_00844940, UI_item_tacarc_bg.
//  - Strings: "i_d_item_2d_wnd_debug.xml"; "i_d_item_2d_wnd_frame.xml"; "i_d_item_2d_wnd_geo_bg.xml"; "i_d_item_2d_wnd_geo.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_item_2d_wnd_tacarc_bg.xml"
 * Domain alias of FUN_0084ca70 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_item_tacarc_bg(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  void *pvVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b486d;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x51c);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00844940(pvVar1);

  }

  local_4 = 0xffffffff;

  param_1[0x159] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x159] + 0x43c))();

  piVar3 = (int *)(**(code **)(*(int *)param_1[0x159] + 0x120))(&stack0xffffffe8,1,0);

  param_1[0x15a] = *piVar3;

  iVar2 = param_1[0x1a] + 1;

  param_1[0x15b] = piVar3[1];

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_item_2d_wnd_debug.xml");

  param_1[0x156] = (int)piVar3;

  (**(code **)(*piVar3 + 0xcc))(0);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_item_2d_wnd_frame.xml");

  iVar2 = param_1[0x1a] + 1;

  param_1[0x14b] = (int)piVar3;

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

  param_1[0x14e] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14e] + 0x28))("i_d_item_2d_wnd_geo_bg.xml");

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x5f0);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_008345c0(pvVar1,0x41b40000);

  }

  param_1[0x14d] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14d] + 0x28))("i_d_item_2d_wnd_geo.xml");

  iVar2 = (**(code **)(*(int *)param_1[0x14d] + 0x1a8))();

  *(uint8_t *)(iVar2 + 0x78) = 0;

  iVar2 = (**(code **)(*(int *)param_1[0x14d] + 0x1a0))();

  if (iVar2 != 0) {

    iVar2 = (**(code **)(*(int *)param_1[0x14d] + 0x1a0))();

    *(float *)(iVar2 + 0xf0) = g_flMsToSeconds_Inferred;

    *(uint8_t *)(iVar2 + 0x48) = 1;

    *(uint8_t *)(iVar2 + 0xcc) = 1;

  }

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

  param_1[0x158] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x158] + 0x28))("i_d_item_2d_wnd_tacarc_bg.xml");

  pvVar1 = operator_new(0x4fc);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0083a760(pvVar1);

  }

  param_1[0x157] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x157] + 0x28))("i_d_item_2d_wnd_tacarc.xml");

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_item_2d_wnd_name.xml");

  param_1[0x14f] = (int)piVar3;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_item_2d_wnd_subtitle.xml");

  param_1[0x150] = (int)piVar3;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_item_2d_wnd_item_description.xml");

  param_1[0x151] = (int)piVar3;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_item_2d_wnd_stats.xml");

  param_1[0x152] = (int)piVar3;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_item_2d_wnd_stats_enhancements.xml");

  param_1[0x155] = (int)piVar3;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_item_2d_wnd_requirements.xml");

  param_1[0x153] = (int)piVar3;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_item_2d_wnd_value.xml");

  param_1[0x154] = (int)piVar3;

  if ((char)param_1[0x14a] != '\0') {

    pvVar4 = operator_new(0x4cc);

    iVar2 = 0;

    if (pvVar4 != (void *)0x0) {

      iVar2 = FUN_0079c860();

    }

    param_1[0x14c] = iVar2;

    (**(code **)(*param_1 + 0xa8))(iVar2);

    (**(code **)(*(int *)param_1[0x14c] + 0x28))("i_d_item_2d_btn_close.xml");

    (**(code **)(*(int *)param_1[0x14c] + 0x74))(40000);

    *(uint8_t *)((int)param_1 + 0xc5) = 1;

    *(uint8_t *)((int)param_1 + 0xcd) = 0;

    *(uint8_t *)(param_1[0x14b] + 0xc4) = 1;

    *(uint8_t *)(param_1[0x14b] + 0xcd) = 0;

  }

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar1;

  return;

}
