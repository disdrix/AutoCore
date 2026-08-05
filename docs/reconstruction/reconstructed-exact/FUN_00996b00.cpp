// =============================================================================
// FUN_00996b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00996b00
// Address:   0x00996b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00996b00 @ 0x00996b00
// Stable ID: aa_00996b00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00415e90×2, FUN_00449a90, FUN_009899a0, FUN_00996b00.
//  - Return sites: 2.

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

void FUN_00996b00(int param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009acd62;

  pvStack_c = ExceptionList;

  local_4 = 1;

  ExceptionList = &pvStack_c;

  FUN_00415e90();

  FUN_00449a90(9);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 1;

  FUN_009899a0();

  if (*(void **)(param_1 + 0x3c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x3c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  FUN_00415e90();

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x30));

}
