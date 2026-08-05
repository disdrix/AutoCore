// =============================================================================
// FUN_007a40e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a40e0
// Address:   0x007a40e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a40e0 @ 0x007a40e0
// Stable ID: aa_007a40e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007a40e0.
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

void __fastcall FUN_007a40e0(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_00a97168;

  if ((void *)param_1[5] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[5]);

  }

  param_1[5] = 0;

  if ((void *)param_1[2] != (void *)0x0) {

    operator_delete__((void *)param_1[2]);

  }

  param_1[2] = 0;

  *(uint8_t *)(param_1 + 1) = 0;

  return;

}
