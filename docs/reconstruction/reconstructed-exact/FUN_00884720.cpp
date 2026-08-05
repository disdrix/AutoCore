// =============================================================================
// FUN_00884720
// -----------------------------------------------------------------------------
// Stable ID: aa_00884720
// Address:   0x00884720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00884720 @ 0x00884720
// Stable ID: aa_00884720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00520d90×2, FUN_00570f50, FUN_00570f70, FUN_00792490, FUN_00884720, FUN_0094c430.
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

void __fastcall FUN_00884720(int *param_1)



{

  if ((param_1[0x144] != 0) && (*(int *)(param_1[0x144] + 0xce0) != 0)) {

    FUN_00570f70();

    FUN_00520d90();

  }

  if (DAT_00d1b6d8 != 0) {

    FUN_00520d90();

    if (*(int *)(DAT_00d1b6d8 + 0xce0) != 0) {

      FUN_00570f50();

    }

  }

  if (param_1[0x162] != 0) {

    (**(code **)(*(int *)param_1[0x162] + 0x440))();

  }

  if (param_1[0x163] != 0) {

    (**(code **)(*(int *)param_1[0x163] + 0x440))();

  }

  FUN_0094c430();

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  return;

}
