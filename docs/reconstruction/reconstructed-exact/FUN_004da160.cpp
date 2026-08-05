// =============================================================================
// FUN_004da160
// -----------------------------------------------------------------------------
// Stable ID: aa_004da160
// Address:   0x004da160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004da160 @ 0x004da160
// Stable ID: aa_004da160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: while×2, return×1.
//  - Notable callees: FUN_004bae00×4, FUN_00462f80, FUN_004da160, FUN_004e48b0, FUN_004e52a0.
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

void __fastcall FUN_004da160(int param_1)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ local_3c;

  uint8_t local_38 [8];

  uint local_30;

  int local_2c;

  uint8_t local_28 [4];

  uint32_t /* width from decompiler */ *local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint local_14;

  int local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a227e;

  pvStack_c = ExceptionList;

  local_30 = 1;

  local_2c = 0;

  ExceptionList = &pvStack_c;

  local_24 = (uint32_t /* width from decompiler */ *)FUN_00462f80();

  *(uint8_t *)((int)local_24 + 0x21) = 1;

  local_24[1] = local_24;

  *local_24 = local_24;

  local_24[2] = local_24;

  local_20 = 0;

  local_4 = 0;

  local_3c = 0;

  iVar5 = FUN_004bae00(1,&local_3c);

  uVar3 = local_30;

  iVar4 = local_2c;

  uVar1 = local_14;

  iVar2 = local_10;

  while (local_10 = iVar4, local_14 = uVar3, iVar5 != 0) {

    local_1c = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x160);

    local_18 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x164);

    local_30 = local_14 + 1;

    local_2c = local_10 + (uint)(0xfffffffe < local_14);

    FUN_004e48b0(local_38,&local_1c);

    iVar5 = FUN_004bae00(1,&local_3c);

    uVar3 = local_30;

    iVar4 = local_2c;

    uVar1 = local_14;

    iVar2 = local_10;

  }

  local_3c = 0;

  local_30 = local_14;

  local_2c = local_10;

  local_14 = uVar1;

  local_10 = iVar2;

  piVar6 = (int *)FUN_004bae00(1,&local_3c);

  while (piVar6 != (int *)0x0) {

    (**(code **)(*piVar6 + 0x30))(local_28,&local_30);

    piVar6 = (int *)FUN_004bae00(1,&local_3c);

  }

  *(uint *)(param_1 + 0xe6d8) = local_30;

  *(int *)(param_1 + 0xe6dc) = local_2c;

  local_4 = 0xffffffff;

  FUN_004e52a0(local_38,*local_24,local_24);

                    /* WARNING: Subroutine does not return */

  operator_delete(local_24);

}
