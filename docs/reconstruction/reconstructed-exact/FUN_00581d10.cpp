// =============================================================================
// FUN_00581d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00581d10
// Address:   0x00581d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00581d10 @ 0x00581d10
// Stable ID: aa_00581d10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00581d10.
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

void __fastcall FUN_00581d10(int param_1)



{

  byte *pbVar1;

  

  pbVar1 = (byte *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0xf1 + param_1);

  *pbVar1 = *pbVar1 | 0x20;

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0x8c + param_1) + 0x104))(1);

  return;

}
