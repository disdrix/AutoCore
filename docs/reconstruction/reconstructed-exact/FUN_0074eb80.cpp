// =============================================================================
// FUN_0074eb80
// -----------------------------------------------------------------------------
// Stable ID: aa_0074eb80
// Address:   0x0074eb80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074eb80 @ 0x0074eb80
// Stable ID: aa_0074eb80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0073f820, FUN_0074eb80.
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

void __fastcall FUN_0074eb80(int param_1)



{

  if ((*(int *)(param_1 + 0x60) != -1) && (*(float *)(param_1 + 100) != *(float *)(param_1 + 0x6c)))

  {

    if (*(int *)(param_1 + 0x58) != 0) {

      FUN_0073f820(*(int *)(param_1 + 0x58),param_1,*(uint32_t /* width from decompiler */ *)(param_1 + 100),

                   *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c),g_flZero <= *(float *)(param_1 + 0x3c));

    }

  }

  return;

}
