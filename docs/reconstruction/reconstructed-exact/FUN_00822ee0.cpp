// =============================================================================
// FUN_00822ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00822ee0
// Address:   0x00822ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00822ee0 @ 0x00822ee0
// Stable ID: aa_00822ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00792600, FUN_0079c860, FUN_007b5dd0, FUN_00822ee0.
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

void __fastcall FUN_00822ee0(int *param_1)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b41d5;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x4cc);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0079c860();

  }

  local_4 = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))(piVar2);

  uVar7 = 60000;

  (**(code **)(*piVar2 + 0x74))(60000);

  iVar4 = (int)param_1 + 0x4fe;

  (**(code **)(*piVar2 + 0x28))(iVar4);

  uVar6 = 1;

  (**(code **)(*piVar2 + 0xfc))(1,0x3f000000);

  iVar3 = param_1[0x1a] + 1;

  param_1[0x205] = (int)piVar2;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  uVar5 = 1;

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x206] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3,uVar5,uVar6,pvVar1,iVar4,uVar7,0xffffffff);

  (**(code **)(*(int *)param_1[0x206] + 0x74))(0xea61);

  (**(code **)(*(int *)param_1[0x206] + 0x28))();

  iVar4 = (**(code **)(*(int *)param_1[0x206] + 0x164))(1);

  *(uint8_t *)((int)param_1 + 0x4fd) = *(uint8_t *)(iVar4 + 3);

  (**(code **)(*(int *)param_1[0x206] + 0xfc))(1,0x3f000000);

  if (*(char *)((int)param_1 + 0x706) != '\0') {

    (**(code **)(*(int *)param_1[0x206] + 0x1d8))((int)param_1 + 0x706,1,1);

  }

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)((int)param_1 + 0x602);

  return;

}
