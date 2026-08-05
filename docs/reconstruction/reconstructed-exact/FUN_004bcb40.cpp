// =============================================================================
// FUN_004bcb40
// -----------------------------------------------------------------------------
// Stable ID: aa_004bcb40
// Address:   0x004bcb40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bcb40 @ 0x004bcb40
// Stable ID: aa_004bcb40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004bcb40, InitializeCriticalSection.
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

uint32_t /* width from decompiler */ * __fastcall FUN_004bcb40(uint32_t /* width from decompiler */ *param_1)



{

  param_1[8] = 0;

  param_1[7] = 0;

  param_1[9] = 0;

  *(uint8_t *)(param_1 + 10) = 0;

  *param_1 = &PTR_FUN_009cb334;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));

  *param_1 = &PTR_FUN_009cb378;

  return param_1;

}
