// =============================================================================
// FUN_004049e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004049e0
// Address:   0x004049e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004049e0 @ 0x004049e0
// Stable ID: aa_004049e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~4 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004049e0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x004049e0; evidence only — no invented semantics):
//  - Entry: `undefined4 __fastcall FUN_004049e0(int param_1)`.
//  - Returns (1 site(s)): `*(*(*(*(param_1 + 4) + 4) + 0xac + pa...`.
//  - Sparse CF in raw; see body.




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

uint32_t /* width from decompiler */ __fastcall FUN_004049e0(int param_1)



{

  return *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

}
