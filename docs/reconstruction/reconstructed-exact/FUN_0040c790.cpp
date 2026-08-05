// =============================================================================
// FUN_0040c790
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c790
// Address:   0x0040c790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040c790 @ 0x0040c790
// Stable ID: aa_0040c790
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0040c790.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040c790; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_0040c790(undefined4 param_1,undefined4 *param_2)`.
//  - Branches: if (-1 < param_2[2]).
//  - Returns (1 site(s)): `void`.




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

void __fastcall FUN_0040c790(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  if (-1 < (int)param_2[2]) {

    (**(code **)(*DAT_00b05060 + 0x14))(*param_2,(param_2[2] & 0x7fffffff) * 0x30,0x12);

  }

  return;

}
