// =============================================================================
// FUN_006347f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006347f0
// Address:   0x006347f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006347f0 @ 0x006347f0
// Stable ID: aa_006347f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004b4b00, FUN_006347f0.
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

void __fastcall FUN_006347f0(uint32_t /* width from decompiler */ *param_1)



{

  if (param_1[2] != 0) {

    FUN_004b4b00(param_1[2]);

  }

  if (param_1[1] != 0) {

    (**(code **)(**(int **)*param_1 + 0x48))(param_1[1]);

  }

  operator_delete__((void *)param_1[4]);

  operator_delete__((void *)param_1[5]);

  operator_delete__((void *)param_1[7]);

  return;

}
