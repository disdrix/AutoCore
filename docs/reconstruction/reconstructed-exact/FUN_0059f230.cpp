// =============================================================================
// FUN_0059f230
// -----------------------------------------------------------------------------
// Stable ID: aa_0059f230
// Address:   0x0059f230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059f230 @ 0x0059f230
// Stable ID: aa_0059f230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: CONCAT31, FUN_00424dc0, FUN_0042b270, FUN_0059f230, FUN_00780820, free.
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

void __thiscall

FUN_0059f230(uint32_t /* width from decompiler */ param_1,int param_2,uint16_t param_3,uint16_t param_4,uint16_t param_5

            ,int *param_6)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  void *unaff_EBX;

  undefined **local_718 [4];

  uint32_t /* width from decompiler */ uStack_708;

  uint8_t local_5e0 [1472];

  void *pvStack_20;

  uint uStack_18;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a5eb3;

  pvStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  piVar3 = operator_new(0x30);

  local_4._0_1_ = 1;

  if (piVar3 == (int *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    FUN_00780820(1,1);

    *piVar3 = (int)&PTR_LAB_009d7cec;

    piVar3[6] = (int)&PTR_FUN_009d7c0c;

    piVar3[7] = (int)&LAB_005a2110;

    piVar3[0xb] = 0;

    piVar3[5] = (int)(piVar3 + 6);

  }

  piVar3[8] = param_2;

  *(uint16_t *)(piVar3 + 9) = param_3;

  *(uint16_t *)((int)piVar3 + 0x26) = param_4;

  *(uint16_t *)(piVar3 + 10) = param_5;

  piVar2 = (int *)piVar3[0xb];

  local_4._0_1_ = 0;

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  piVar3[0xb] = (int)param_6;

  if (param_6 != (int *)0x0) {

    param_6[2] = param_6[2] + 1;

  }

  FUN_00424dc0(local_5e0,0x5d2,0x5d2);

  local_718[0] = &PTR_LAB_009d7ba4;

  local_4 = CONCAT31(local_4._1_3_,2);

  (**(code **)(*piVar3 + 0xc))(param_1,local_718);

  uStack_708 = 0;

  (**(code **)(*piVar3 + 0x10))(param_1,&stack0xfffff8e0);

  (**(code **)(*piVar3 + 0x14))(param_1);

  uStack_18 = uStack_18 & 0xffffff00;

  if ((char)local_718[0] != '\0') {

    free(unaff_EBX);

  }

  FUN_0042b270();

  uStack_18 = 0xffffffff;

  if (param_6 != (int *)0x0) {

    piVar3 = param_6 + 2;

    *piVar3 = *piVar3 + -1;

    if (*piVar3 == 0) {

      (**(code **)(*param_6 + 8))();

    }

  }

  ExceptionList = pvStack_20;

  return;

}
