// =============================================================================
// FUN_0090b970
// -----------------------------------------------------------------------------
// Stable ID: aa_0090b970
// Address:   0x0090b970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090b970 @ 0x0090b970
// Stable ID: aa_0090b970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0090b6a0, FUN_0090b970.
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

void FUN_0090b970(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  FUN_0090b6a0((int)((float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80) * DAT_00a0f298),

               (int)((float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * DAT_00a0f704),param_1,

               param_2);

  return;

}
