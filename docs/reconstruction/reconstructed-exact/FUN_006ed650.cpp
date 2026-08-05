// =============================================================================
// FUN_006ed650
// -----------------------------------------------------------------------------
// Stable ID: aa_006ed650
// Address:   0x006ed650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ed650 @ 0x006ed650
// Stable ID: aa_006ed650
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006ed650.
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

void __fastcall FUN_006ed650(uint32_t /* width from decompiler */ *param_1)



{

  (**(code **)(*(int *)param_1[3] + 0x14))();

  if ((int *)param_1[4] != (int *)0x0) {

    (**(code **)(*(int *)param_1[4] + 0x14))();

    param_1[4] = 0;

  }

  (**(code **)*param_1)(1);

  return;

}
