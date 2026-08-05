// =============================================================================
// FUN_00664640
// -----------------------------------------------------------------------------
// Stable ID: aa_00664640
// Address:   0x00664640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00664640 @ 0x00664640
// Stable ID: aa_00664640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00638180×2, FUN_00664640.
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

void __fastcall FUN_00664640(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  

  piVar1 = (int *)(param_1[9] + -4);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 < 0) {

    FUN_00638180();

  }

  piVar1 = (int *)(param_1[8] + -4);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 < 0) {

    FUN_00638180();

  }

  if (-1 < (int)param_1[5]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[3],param_1[5] & 0x7fffffff,0x12);

  }

  if (-1 < (int)param_1[2]) {

    (**(code **)(*DAT_00b05060 + 0x14))(*param_1,param_1[2] * 8,0x12);

  }

  return;

}
