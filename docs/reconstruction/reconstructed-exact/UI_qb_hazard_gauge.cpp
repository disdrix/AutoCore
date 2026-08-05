// =============================================================================
// UI_qb_hazard_gauge
// -----------------------------------------------------------------------------
// Stable ID: aa_008a16b0
// Address:   0x008a16b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_qb_hazard_gauge @ 0x008a16b0
// Stable ID: aa_008a16b0
// Embedded strings (evidence for future rename):
//   - "i_d_qb_2d_btn_inc.xml"
//   - "i_d_qb_2d_wnd_hazard_bar.xml"
//   - "i_d_qb_2d_wnd_hazard_inc.xml"
//   - "i_d_qb_2d_wnd_hazard_gauge.xml"
//   - "i_d_qb_2d_wnd_hazard_label.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~261 non-empty decompiler lines.
//  - Control keywords: if×20, do×1, while×1, return×1.
//  - Notable callees: FUN_0079c860×3, FUN_007b5dd0×2, FUN_00825bf0×2, sprintf×2, FUN_00792600, FUN_00826780, FUN_0082f4a0, FUN_008a0210.
//  - Strings: "i_d_qb_2d_btn_inc.xml"; "i_d_qb_2d_wnd_hazard_bar.xml"; "i_d_qb_2d_wnd_hazard_inc.xml"; "i_d_qb_2d_wnd_hazard_gauge.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_qb_2d_wnd_hazard_gauge.xml"
 * Domain alias of FUN_008a16b0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_qb_hazard_gauge(int *param_1)



{

  char cVar1;

  void *pvVar2;

  int iVar3;

  int *piVar4;

  float *pfVar5;

  char *pcVar6;

  char *pcVar7;

  int iVar8;

  char *pcVar9;

  uint8_t *puStack_b0;

  int iStack_ac;

  void *pvStack_a4;

  int iStack_a0;

  int iStack_9c;

  char *pcStack_98;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b98c0;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar2 = operator_new(0x580);

  local_4 = 0;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0082f4a0();

  }

  local_4 = 0xffffffff;

  param_1[0x199] = iVar3;

  pvVar2 = operator_new(0x488);

  local_4 = 1;

  if (pvVar2 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar4 + 0x28))();

  (**(code **)(*piVar4 + 0xfc))();

  iVar3 = param_1[0x1a] + 1;

  param_1[0x189] = (int)piVar4;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar4 + 0x28))();

  (**(code **)(*piVar4 + 0xfc))();

  iVar3 = param_1[0x1a] + 1;

  param_1[0x18a] = (int)piVar4;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x4cc);

  if (pvVar2 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar4 + 0x28))();

  (**(code **)(*piVar4 + 0x74))();

  (**(code **)(*piVar4 + 0xfc))();

  param_1[0x18b] = (int)piVar4;

  pvVar2 = operator_new(0x4cc);

  if (pvVar2 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar4 + 0x28))();

  (**(code **)(*piVar4 + 0x74))();

  (**(code **)(*piVar4 + 0xfc))();

  param_1[0x18c] = (int)piVar4;

  pvVar2 = operator_new(0x520);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_008c4f10();

  }

  param_1[0x19a] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x19a] + 0x43c))();

  (**(code **)(*(int *)param_1[0x19a] + 0xfc))();

  pcStack_98 = (char *)0x8a194e;

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x18d] = iVar3;

  pcStack_98 = (char *)0x8a197f;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_98 = "i_d_qb_2d_btn_inc.xml";

  iStack_9c = 0x8a198f;

  (**(code **)(*(int *)param_1[0x18d] + 0x28))();

  iStack_9c = 0x9c42;

  iStack_a0 = 0x8a199f;

  (**(code **)(*(int *)param_1[0x18d] + 0x74))();

  iStack_a0 = 0x3f000000;

  pvStack_a4 = (void *)0x1;

  (**(code **)(*(int *)param_1[0x18d] + 0xfc))();

  iStack_ac = 0x8a19be;

  pvVar2 = operator_new(0x554);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iStack_ac = 0x8a19d7;

    iVar3 = FUN_00825bf0();

  }

  param_1[0x19b] = iVar3;

  iStack_ac = 0x8a19f0;

  (**(code **)(*param_1 + 0xa8))();

  iStack_ac = 0x9c44;

  puStack_b0 = (uint8_t *)0x8a1a00;

  (**(code **)(*(int *)param_1[0x19b] + 0x74))();

  puStack_b0 = (uint8_t *)0x8a1a0e;

  (**(code **)(*(int *)param_1[0x19b] + 0x43c))();

  iVar3 = param_1[0x19b];

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x500) = 0;

  if (*(int *)(iVar3 + 0x548) != 0) {

    puStack_b0 = (uint8_t *)0x1;

    sprintf(&stack0xffffff6c,"%i");

    puStack_b0 = (uint8_t *)0x1;

    (**(code **)(**(int **)(iVar3 + 0x548) + 0x1d8))(&stack0xffffff6c,1);

    (**(code **)(**(int **)(iVar3 + 0x548) + 0x34c))();

  }

  puStack_b0 = (uint8_t *)0x8a1a6e;

  (**(code **)(*(int *)param_1[0x19b] + 0x444))();

  iVar3 = param_1[0x145];

  puStack_b0 = &stack0xffffff6c;

  pfVar5 = (float *)(**(code **)(*(int *)param_1[0x19b] + 0x134))();

  iStack_a0 = (int)((float)(int)(((float)param_1[0x146] + *pfVar5) * g_flZero +

                                (float)param_1[0x144]) * (float)DAT_00d1e818 * DAT_00aaa67c);

  iStack_9c = (int)((float)iVar3 * (float)DAT_00d1e81c * DAT_00aaa678);

  (**(code **)(*(int *)param_1[0x19b] + 0x118))(&iStack_a0);

  pvStack_a4 = operator_new(0x554);

  if (pvStack_a4 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_00825bf0(pvStack_a4);

  }

  param_1[0x19c] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x19c] + 0x74))(0x9c45);

  (**(code **)(*(int *)param_1[0x19c] + 0x43c))();

  iVar3 = param_1[0x19c];

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x500) = 1;

  if (*(int *)(iVar3 + 0x548) != 0) {

    sprintf((char *)&pvStack_a4,"%i",2);

    (**(code **)(**(int **)(iVar3 + 0x548) + 0x1d8))(&pvStack_a4,1,1);

    (**(code **)(**(int **)(iVar3 + 0x548) + 0x34c))();

  }

  (**(code **)(*(int *)param_1[0x19c] + 0x444))();

  iVar3 = param_1[0x145];

  pfVar5 = (float *)(**(code **)(*(int *)param_1[0x19c] + 0x134))(&pvStack_a4);

  puStack_b0 = (uint8_t *)

               (int)((float)(int)((float)param_1[0x146] + *pfVar5 + (float)param_1[0x144]) *

                     (float)DAT_00d1e818 * DAT_00aaa67c);

  iStack_ac = (int)((float)iVar3 * (float)DAT_00d1e81c * DAT_00aaa678);

  (**(code **)(*(int *)param_1[0x19c] + 0x118))(&puStack_b0);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x19d,"i_d_qb_2d_wnd_hazard_bar.xml",0xffffffff);

  pcVar9 = "i_d_qb_2d_wnd_hazard_inc.xml";

  (**(code **)(*param_1 + 0x404))(param_1 + 0x19f,"i_d_qb_2d_wnd_hazard_inc.xml",0xffffffff);

  pvVar2 = operator_new(0x4f8);

  iStack_ac = 9;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0097ffa0(pvVar2);

  }

  iStack_ac = 0xffffffff;

  param_1[0x1a0] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x1a0] + 0x28))("i_d_qb_2d_wnd_hazard_gauge.xml");

  (**(code **)(*(int *)param_1[0x1a0] + 0x3b0))(0x3f800000);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x19e,"i_d_qb_2d_wnd_hazard_label.xml",0xffffffff);

  pcVar6 = (char *)(**(code **)(*(int *)param_1[0x19e] + 0x1dc))();

  pcVar7 = (char *)((int)param_1 + 0x523);

  do {

    cVar1 = *pcVar6;

    *pcVar7 = cVar1;

    pcVar6 = pcVar6 + 1;

    pcVar7 = pcVar7 + 1;

  } while (cVar1 != '\0');

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar2 = operator_new(0x58c);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_008b0ce0(pvVar2);

  }

  param_1[0x1a1] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x1a1] + 0x43c))();

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar3 = param_1[0x1a];

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  FUN_008a0370();

  iVar3 = param_1[0x143];

  iVar8 = -1;

  if ((-1 < iVar3) && (iVar3 < 10)) {

    iVar8 = *(int *)(&DAT_00d1da38 + iVar3 * 4);

  }

  FUN_008a04b0();

  FUN_008a1110();

  FUN_008a0e10(param_1);

  (**(code **)(*param_1 + 0x448))();

  DAT_00d1a9fc = 0xffffffff;

  if ((((iVar8 < 0) || (9 < iVar8)) || (*(int *)(param_1[iVar8 + 399] + 0x548) == 0)) ||

     (*(int *)(param_1[iVar8 + 399] + 0x548) == 6)) {

    FUN_008a0210(1);

  }

  else {

    FUN_00826780(1);

  }

  if (DAT_00d1b6d8 != 0) {

    FUN_008a0770();

  }

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pcVar9;

  return;

}
