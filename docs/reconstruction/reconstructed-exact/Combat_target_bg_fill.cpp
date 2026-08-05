// =============================================================================
// Combat_target_bg_fill
// -----------------------------------------------------------------------------
// Stable ID: aa_00839ff0
// Address:   0x00839ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Combat_target_bg_fill @ 0x00839ff0
// Stable ID: aa_00839ff0
// Embedded strings (evidence for future rename):
//   - "i_d_target_2d_wnd_bg_fill.xml"
//   - "i_d_target_2d_wnd_gmdata.xml"
//   - "i_d_target_2d_gauge_hp.xml"
//   - "i_d_target_2d_wnd_frame.xml"
//   - "i_d_target_2d_wnd_bg_name.xml"
//   - "i_d_target_2d_wnd_name.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~149 non-empty decompiler lines.
//  - Control keywords: if×12, do×1, while×1, return×1.
//  - Notable callees: FUN_007b5dd0×9, FUN_00792600, Combat_target_bg_fill, FUN_0097ffa0.
//  - Strings: "i_d_target_2d_wnd_bg_fill.xml"; "i_d_target_2d_wnd_gmdata.xml"; "i_d_target_2d_gauge_hp.xml"; "i_d_target_2d_wnd_frame.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_target_2d_wnd_bg_fill.xml"
 * Domain alias of FUN_00839ff0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Combat_target_bg_fill(int *param_1)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b8603;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  local_4 = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_target_2d_wnd_bg_fill.xml");

  iVar3 = param_1[0x1a] + 1;

  param_1[0x147] = (int)piVar2;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x14e] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x14e] + 0x28))("i_d_target_2d_wnd_gmdata.xml");

  (**(code **)(*(int *)param_1[0x14e] + 0xcc))(0);

  pvVar1 = operator_new(0x4f8);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0097ffa0(pvVar1);

  }

  param_1[0x14f] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x14f] + 0x28))("i_d_target_2d_gauge_hp.xml");

  piVar2 = (int *)(**(code **)(*(int *)param_1[0x14f] + 0x164))(0);

  param_1[0x150] = *piVar2;

  piVar2 = (int *)(**(code **)(*(int *)param_1[0x14f] + 0x164))(1);

  param_1[0x151] = *piVar2;

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_target_2d_wnd_frame.xml");

  param_1[0x14d] = (int)piVar2;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_target_2d_wnd_bg_name.xml");

  param_1[0x148] = (int)piVar2;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_target_2d_wnd_name.xml");

  param_1[0x149] = (int)piVar2;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  piVar5 = piVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar2 + 0x28))("i_d_target_2d_wnd_hp.xml");

  param_1[0x14a] = (int)piVar2;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_target_2d_token_icon.xml");

  param_1[0x14b] = (int)piVar2;

  pvVar1 = operator_new(0x488);

  iVar3 = 8;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_target_2d_notoken_icon.xml");

  param_1[0x14c] = (int)piVar2;

  piVar2 = param_1 + 0x153;

  do {

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      iVar4 = 0;

    }

    else {

      iVar4 = FUN_007b5dd0(pvVar1,0);

    }

    *piVar2 = iVar4;

    (**(code **)(*param_1 + 0xa8))(iVar4);

    (**(code **)(*(int *)*piVar2 + 0x28))("i_d_target_2d_wnd_resist_icon.xml");

    (**(code **)(*(int *)*piVar2 + 0xcc))(0);

    piVar2 = piVar2 + 1;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  (**(code **)(*param_1 + 0x444))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = piVar5;

  return;

}
