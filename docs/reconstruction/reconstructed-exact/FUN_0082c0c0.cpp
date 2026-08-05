// =============================================================================
// FUN_0082c0c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0082c0c0
// Address:   0x0082c0c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082c0c0 @ 0x0082c0c0
// Stable ID: aa_0082c0c0
// Embedded strings (evidence for future rename):
//   - "i_d_dt_2d_btn_disc_available.xml"
//   - "i_d_dt_2d_btn_disc_lock.xml"
//   - "i_d_dt_2d_btn_disc_btn.xml"
//   - "i_d_dt_2d_btn_disc_rank_progress.xml"
//   - "i_d_dt_2d_btn_disc_rank.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_007b5dd0×4, FUN_00792600, FUN_0079c860, FUN_0082c0c0.
//  - Strings: "i_d_dt_2d_btn_disc_available.xml"; "i_d_dt_2d_btn_disc_lock.xml"; "i_d_dt_2d_btn_disc_btn.xml"; "i_d_dt_2d_btn_disc_rank_progress.xml".
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

void __fastcall FUN_0082c0c0(int *param_1)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b43ed;

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

  (**(code **)(*piVar2 + 0x74))(0xea61);

  (**(code **)(*piVar2 + 0x28))("i_d_dt_2d_btn_disc_available.xml");

  iVar3 = param_1[0x1a] + 1;

  param_1[0x185] = (int)piVar2;

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

  (**(code **)(*piVar2 + 0x28))("i_d_dt_2d_btn_disc_lock.xml");

  iVar3 = param_1[0x1a] + 1;

  param_1[0x186] = (int)piVar2;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x74))(60000);

  (**(code **)(*piVar2 + 0x28))("i_d_dt_2d_btn_disc_btn.xml");

  param_1[0x184] = (int)piVar2;

  piVar2 = (int *)(**(code **)(*piVar2 + 0x164))(0);

  param_1[0x183] = *piVar2;

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_dt_2d_btn_disc_rank_progress.xml");

  param_1[0x188] = (int)piVar2;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_dt_2d_btn_disc_rank.xml");

  param_1[0x187] = (int)piVar2;

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0x1;

  return;

}
