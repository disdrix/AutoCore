// =============================================================================
// FUN_008337c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008337c0
// Address:   0x008337c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008337c0 @ 0x008337c0
// Stable ID: aa_008337c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0076f5f0, FUN_0078bc80, FUN_00833390, FUN_008337c0, FUN_00972bd0, fcos, fsin.
//  - Return sites: 2.

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

void __thiscall FUN_008337c0(int param_1,float param_2)



{

  int extraout_EDX;

  float10 fVar1;

  float *pfVar2;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if ((*(int *)(param_1 + 0x24) != 0) && (param_2 != g_flZero)) {

    FUN_0076f5f0(&local_1c,param_1 + 0x18);

    fVar1 = (float10)fsin((float10)param_2 * (float10)DAT_00a0f298);

    local_10 = (float)((float10)local_1c * fVar1);

    local_c = (float)((float10)local_18 * fVar1);

    local_8 = (float)((float10)local_14 * fVar1);

    fVar1 = (float10)fcos((float10)param_2 * (float10)DAT_00a0f298);

    local_4 = (float)fVar1;

    if (*(int **)(extraout_EDX + 0x48) != (int *)0x0) {

      pfVar2 = &local_10;

      (**(code **)(**(int **)(extraout_EDX + 0x48) + 0x10))(3,pfVar2);

      FUN_00972bd0(pfVar2);

    }

    (**(code **)(**(int **)(param_1 + 0x24) + 0x44))();

    FUN_00833390();

    *(float *)(param_1 + 0x14) = *(float *)(param_1 + 0x14) + param_2;

    return;

  }

  FUN_0078bc80(param_2);

  return;

}
