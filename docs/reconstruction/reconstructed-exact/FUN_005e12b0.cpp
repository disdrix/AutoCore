// =============================================================================
// FUN_005e12b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e12b0
// Address:   0x005e12b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e12b0 @ 0x005e12b0
// Stable ID: aa_005e12b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_005ae2b0, FUN_005e12b0, _eh_vector_constructor_iterator_.
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

int __fastcall FUN_005e12b0(int param_1)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a74d0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar1 = FUN_005ae2b0();

  *(int *)(param_1 + 4) = iVar1;

  *(uint8_t *)(iVar1 + 0x19) = 1;

  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  local_4 = 0;

  _eh_vector_constructor_iterator_((void *)(param_1 + 0xc),0x10,0x8700,FUN_004565f0,FUN_00691630);

  local_4._0_1_ = 1;

  _eh_vector_constructor_iterator_

            ((void *)(param_1 + 0x8700c),0x10,0x8700,FUN_004565f0,FUN_00691630);

  local_4 = CONCAT31(local_4._1_3_,2);

  _eh_vector_constructor_iterator_

            ((void *)(param_1 + 0x10e00c),0x10,12000,FUN_004565f0,FUN_00691630);

  ExceptionList = local_c;

  return param_1;

}
