// =============================================================================
// FUN_0065b560
// -----------------------------------------------------------------------------
// Stable ID: aa_0065b560
// Address:   0x0065b560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065b560 @ 0x0065b560
// Stable ID: aa_0065b560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0065b560.
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

void __thiscall FUN_0065b560(int param_1,float *param_2,float *param_3)



{

  float fVar1;

  

  (**(code **)(**(int **)(param_1 + 0x30) + 0x30))(param_2,param_3);

  if (g_flZero <

      *(float *)(param_1 + 0x18) * param_2[2] + *(float *)(param_1 + 0x14) * param_2[1] +

      *(float *)(param_1 + 0x10) * *param_2) {

    fVar1 = param_3[3];

    *param_3 = *(float *)(param_1 + 0x10) + *param_3;

    param_3[1] = *(float *)(param_1 + 0x14) + param_3[1];

    param_3[2] = *(float *)(param_1 + 0x18) + param_3[2];

    param_3[3] = *(float *)(param_1 + 0x1c) + fVar1;

    param_3[3] = fVar1;

  }

  return;

}
