// =============================================================================
// FUN_0065abb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0065abb0
// Address:   0x0065abb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065abb0 @ 0x0065abb0
// Stable ID: aa_0065abb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00638180×2, FUN_0065abb0.
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

void __fastcall FUN_0065abb0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  

  *param_1 = &PTR_FUN_009e46ec;

  (**(code **)(*DAT_00b05060 + 4))(param_1[6]);

  piVar1 = (int *)(param_1[4] + -4);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 < 0) {

    FUN_00638180();

  }

  piVar1 = (int *)(param_1[3] + -4);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 < 0) {

    FUN_00638180();

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
