// =============================================================================
// FUN_0041b4b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041b4b0
// Address:   0x0041b4b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041b4b0 @ 0x0041b4b0
// Stable ID: aa_0041b4b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: CoTaskMemFree×2, FUN_0041d2c0×2, CONCAT31, FUN_0041b4b0, FUN_0041b9f0, FUN_00422a90, FUN_00422de0.
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

void FUN_0041b4b0(int param_1)



{

  int iVar1;

  int *piVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009bd7f0;

  pvStack_c = ExceptionList;

  local_4 = 0;

  iVar1 = *(int *)(param_1 + 0x28);

  ExceptionList = &pvStack_c;

  if (iVar1 != 0) {

    ExceptionList = &pvStack_c;

    FUN_00422a90(iVar1);

    FUN_00422de0();

    FUN_0041b9f0();

    FUN_0041d2c0();

  }

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_0041d2c0();

  piVar2 = *(int **)(param_1 + 0x2c);

  if (piVar2 != (int *)0x0) {

    (**(code **)(*piVar2 + 8))(piVar2);

  }

  local_4 = local_4 & 0xffffff00;

  piVar2 = *(int **)(param_1 + 0x28);

  if (piVar2 != (int *)0x0) {

    (**(code **)(*piVar2 + 8))(piVar2);

  }

  CoTaskMemFree(*(LPVOID *)(param_1 + 0x14));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  CoTaskMemFree(*(LPVOID *)(param_1 + 0x18));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  operator_delete__(*(void **)(param_1 + 8));

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  operator_delete__(*(void **)(param_1 + 0x10));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  ExceptionList = pvStack_c;

  return;

}
