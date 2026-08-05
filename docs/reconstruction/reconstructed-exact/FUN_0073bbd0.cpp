// =============================================================================
// FUN_0073bbd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073bbd0
// Address:   0x0073bbd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073bbd0 @ 0x0073bbd0
// Stable ID: aa_0073bbd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00463d80, FUN_0073bad0, FUN_0073bbd0.
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

void FUN_0073bbd0(int param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009ad694;

  pvStack_c = ExceptionList;

  local_4 = 1;

  ExceptionList = &pvStack_c;

  FUN_0073bad0();

  local_4 = local_4 & 0xffffff00;

  if (*(void **)(param_1 + 0x14) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x14));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  FUN_00463d80();

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 8));

}
