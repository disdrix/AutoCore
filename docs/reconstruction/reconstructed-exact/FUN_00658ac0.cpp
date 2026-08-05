// =============================================================================
// FUN_00658ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00658ac0
// Address:   0x00658ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00658ac0 @ 0x00658ac0
// Stable ID: aa_00658ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: ABS×3, FUN_005070d0, FUN_00658ac0.
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

void __thiscall FUN_00658ac0(int param_1,float *param_2)



{

  if ((g_flMsToSeconds_Inferred < ABS(param_2[2] - *(float *)(param_1 + 0x38)) ||

      g_flMsToSeconds_Inferred < ABS(param_2[1] - *(float *)(param_1 + 0x34))) ||

      g_flMsToSeconds_Inferred < ABS(*param_2 - *(float *)(param_1 + 0x30))) {

    FUN_005070d0();

  }

  *(float *)(param_1 + 0x30) = *param_2;

  *(float *)(param_1 + 0x34) = param_2[1];

  *(float *)(param_1 + 0x38) = param_2[2];

  *(float *)(param_1 + 0x3c) = param_2[3];

  return;

}
