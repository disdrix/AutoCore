// =============================================================================
// FUN_004c2fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c2fd0
// Address:   0x004c2fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c2fd0 @ 0x004c2fd0
// Stable ID: aa_004c2fd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004c2fd0, FUN_00512150.
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

void __thiscall FUN_004c2fd0(int param_1,short param_2)



{

  if (*(short *)(param_1 + 0x12e) < param_2) {

    param_2 = *(short *)(param_1 + 0x12e);

  }

  if (param_2 < 0) {

    param_2 = 0;

  }

  if (param_2 != *(short *)(param_1 + 300)) {

    *(short *)(param_1 + 300) = param_2;

    FUN_00512150(3,(float)(int)param_2,0,0);

  }

  return;

}
