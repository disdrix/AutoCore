// =============================================================================
// FUN_0040c2d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c2d0
// Address:   0x0040c2d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040c2d0 @ 0x0040c2d0
// Stable ID: aa_0040c2d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040c2d0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040c2d0; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_0040c2d0(undefined4 *param_1)`.
//  - Writes: *param_1 = &PTR_LAB_00a2f028.
//  - Returns (1 site(s)): `void`.
//  - Assign `param_1 = &PTR_LAB_00a2f028`.




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

void __fastcall FUN_0040c2d0(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_LAB_00a2f028;

  return;

}
