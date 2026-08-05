// =============================================================================
// FUN_0040afa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040afa0
// Address:   0x0040afa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040afa0 @ 0x0040afa0
// Stable ID: aa_0040afa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040afa0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040afa0; evidence only — no invented semantics):
//  - Entry: `void FUN_0040afa0(void)`.
//  - Returns (1 site(s)): `void`.
//  - Assign `in_EAX = &PTR_LAB_00a2c238`.




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

void FUN_0040afa0(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  

  *in_EAX = &PTR_LAB_00a2c238;

  return;

}
