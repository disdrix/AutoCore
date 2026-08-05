// =============================================================================
// FUN_004c3030
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3030
// Address:   0x004c3030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c3030 @ 0x004c3030
// Stable ID: aa_004c3030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004c3030, FUN_004d2a60, FUN_0053e330.
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

void __fastcall FUN_004c3030(int *param_1)



{

  (**(code **)(*param_1 + 0x50))();

  if (*(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1) != 0) {

    FUN_004d2a60(param_1);

  }

  FUN_0053e330();

  return;

}
