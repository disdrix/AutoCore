// =============================================================================
// UI_cont_btn_inc
// -----------------------------------------------------------------------------
// Stable ID: aa_008efb20
// Address:   0x008efb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_cont_btn_inc @ 0x008efb20
// Stable ID: aa_008efb20
// Embedded strings (evidence for future rename):
//   - "i_d_cont_2d_btn_inc.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~516 non-empty decompiler lines.
//  - Control keywords: if×40, return×1.
//  - Notable callees: FUN_008ebfe0×49, FUN_007b5dd0×31, FUN_0079c860×4, FUN_00792600, FUN_008eec60, FUN_008ef760, UI_cont_btn_inc.
//  - Strings: "i_d_cont_2d_btn_inc.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_cont_2d_btn_inc.xml"
 * Domain alias of FUN_008efb20 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_cont_btn_inc(int *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *pvVar2;

  int iVar3;

  int *piVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint8_t *puStack_284;

  uint32_t /* width from decompiler */ uStack_280;

  char *pcStack_268;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b76b8;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar2 = operator_new(0x488);

  local_4 = 0;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  param_1[0x15a] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15a] + 0x28))();

  (**(code **)(*(int *)param_1[0x15a] + 0xcc))();

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

  FUN_008ebfe0();

  iVar3 = param_1[0x1a] + 1;

  param_1[0x15e] = (int)piVar4;

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

  FUN_008ebfe0();

  param_1[0x15d] = (int)piVar4;

  (**(code **)(*piVar4 + 0x50))();

  *(uint8_t *)(param_1[0x15d] + 0xd7) = 1;

  iVar3 = param_1[0x1a] + 1;

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

  FUN_008ebfe0();

  param_1[0x16a] = (int)piVar4;

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

  FUN_008ebfe0();

  param_1[0x167] = (int)piVar4;

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

  FUN_008ebfe0();

  param_1[0x168] = (int)piVar4;

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

  FUN_008ebfe0();

  iVar3 = param_1[0x1a] + 1;

  param_1[0x169] = (int)piVar4;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  (**(code **)(*param_1 + 0x404))();

  FUN_008ebfe0();

  (**(code **)(*param_1 + 0x404))();

  FUN_008ebfe0();

  (**(code **)(*param_1 + 0x404))();

  FUN_008ebfe0();

  (**(code **)(*param_1 + 0x404))();

  FUN_008ebfe0();

  (**(code **)(*param_1 + 0x404))();

  FUN_008ebfe0();

  (**(code **)(*param_1 + 0x404))();

  FUN_008ebfe0();

  (**(code **)(*param_1 + 0x404))();

  FUN_008ebfe0();

  (**(code **)(*param_1 + 0x404))();

  FUN_008ebfe0();

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

  FUN_008ebfe0();

  param_1[0x141] = (int)piVar4;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x17d] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17d] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x17e] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17e] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x17f] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17f] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x180] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x180] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x181] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x181] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x182] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x182] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x183] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x183] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x184] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x184] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x185] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x185] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x186] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x186] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x187] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x187] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x188] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x188] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x189] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x189] + 0x28))();

  FUN_008ebfe0();

  (**(code **)(*param_1 + 0x404))();

  FUN_008ebfe0();

  (**(code **)(*param_1 + 0x404))();

  (**(code **)(*(int *)param_1[0x18b] + 0x15c))();

  FUN_008ebfe0();

  (**(code **)(*param_1 + 0x404))();

  (**(code **)(*(int *)param_1[0x18c] + 0x15c))();

  FUN_008ebfe0();

  (**(code **)(*param_1 + 0x404))();

  (**(code **)(*(int *)param_1[0x18d] + 0x15c))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x18e] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x18e] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[399] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[399] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[400] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[400] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x191] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x191] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x192] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x192] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x193] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x193] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x194] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x194] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x195] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x195] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x196] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x196] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x197] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x197] + 0x28))();

  FUN_008ebfe0();

  (**(code **)(*(int *)param_1[0x197] + 0x74))();

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x198] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x198] + 0x28))();

  FUN_008ebfe0();

  (**(code **)(*(int *)param_1[0x198] + 0x74))();

  (**(code **)(*param_1 + 0x404))();

  FUN_008ebfe0();

  (**(code **)(*param_1 + 0x408))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x19b] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x19b] + 0x28))();

  FUN_008ebfe0();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    pvVar2 = (void *)0x0;

  }

  else {

    pvVar2 = (void *)FUN_007b5dd0();

  }

  param_1[0x19c] = (int)pvVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x19c] + 0x28))();

  FUN_008ebfe0();

  pcStack_268 = (char *)0x8f0a9c;

  pvVar5 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar5 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x19e] = iVar3;

  pcStack_268 = (char *)0x8f0acd;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_268 = "i_d_cont_2d_btn_inc.xml";

  (**(code **)(*(int *)param_1[0x19e] + 0x28))();

  FUN_008ebfe0();

  (**(code **)(*(int *)param_1[0x19e] + 0x74))();

  if (param_1[0x19f] != 0) {

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)param_1[0x19f] + 0x43c))();

    (**(code **)(*(int *)param_1[0x19f] + 0x74))();

    (**(code **)(*(int *)param_1[0x19f] + 0xcc))();

    (**(code **)(*(int *)param_1[0x19f] + 0x34c))();

    uStack_280 = 1;

    puStack_284 = &stack0xfffffd9c;

    iVar3 = (**(code **)(*(int *)param_1[0x15d] + 0x120))();

    uVar1 = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

    puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x15d] + 0x120))(&pcStack_268,1,0);

    puStack_284 = (uint8_t *)*puVar6;

    uStack_280 = uVar1;

    (**(code **)(*(int *)param_1[0x19f] + 0x110))(&puStack_284);

  }

  (**(code **)(*param_1 + 0x404))();

  FUN_008ebfe0();

  uStack_280 = 0x8f0bc7;

  pvVar5 = operator_new(0x50c);

  if (pvVar5 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    uStack_280 = 0x8f0be0;

    iVar3 = FUN_008ef760();

  }

  param_1[0x16b] = iVar3;

  uStack_280 = 0x8f0bf9;

  (**(code **)(*param_1 + 0xa8))();

  uStack_280 = 0x8f0c07;

  (**(code **)(*(int *)param_1[0x16b] + 0x43c))();

  uStack_280 = 0;

  puStack_284 = (uint8_t *)0x8f0c17;

  (**(code **)(*(int *)param_1[0x16b] + 0xcc))();

  param_1[0x149] = (int)g_flOne;

  iVar3 = DAT_00a0f298;

  param_1[0x14a] = DAT_00a0f298;

  param_1[0x14b] = iVar3;

  param_1[0x150] = -1;

  puStack_284 = (uint8_t *)0x8f0c4f;

  (**(code **)(*param_1 + 0x448))();

  puStack_284 = (uint8_t *)0x8f0c59;

  (**(code **)(*param_1 + 0x34c))();

  puStack_284 = *(uint8_t **)(DAT_00d1b644 + 0xfc);

  FUN_008eec60();

  ExceptionList = pvVar2;

  return;

}
