// =============================================================================
// FUN_0053e330
// -----------------------------------------------------------------------------
// Stable ID: aa_0053e330
// Address:   0x0053e330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053e330 @ 0x0053e330
// Stable ID: aa_0053e330
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_004cfc90, FUN_0053d720, FUN_0053e330.
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

void __fastcall FUN_0053e330(int param_1)



{

  if (*(int *)(param_1 + 8) != 0) {

    FUN_0053d720();

  }

  if (*(int *)(param_1 + 0xc) != 0) {

    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) != 0) {

      FUN_004cfc90(*(int *)(param_1 + 0xc));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  }

  if (*(void **)(param_1 + 0x2c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x2c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  return;

}
