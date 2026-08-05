// =============================================================================
// FUN_004c3d20
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3d20
// Address:   0x004c3d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c3d20 @ 0x004c3d20
// Stable ID: aa_004c3d20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004c3d20, FUN_00513d80.
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

void __thiscall FUN_004c3d20(int param_1,int param_2)



{

  FUN_00513d80(param_2);

  *(uint16_t *)(param_2 + 0x28) = *(uint16_t *)(param_1 + -0x3d4);

  *(uint16_t *)(param_2 + 0x2a) = *(uint16_t *)(param_1 + -0x3d2);

  return;

}
