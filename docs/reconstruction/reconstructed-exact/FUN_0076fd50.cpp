// =============================================================================
// FUN_0076fd50
// -----------------------------------------------------------------------------
// Stable ID: aa_0076fd50
// Address:   0x0076fd50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076fd50 @ 0x0076fd50
// Stable ID: aa_0076fd50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076f5f0, FUN_0076fd50.
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

float * FUN_0076fd50(void)



{

  float fVar1;

  float fVar2;

  float *extraout_EDX;

  int unaff_ESI;

  float fVar3;

  float fVar4;

  float local_10;

  float local_c;

  float local_8;

  

  FUN_0076f5f0(&local_10);

  fVar2 = DAT_00a12f70;

  fVar1 = *(float *)(unaff_ESI + 0xc);

  *extraout_EDX = g_flOne - local_10 * local_10 * g_flLevelUpUiBase_Inferred;

  fVar3 = local_c * local_10 * fVar2;

  extraout_EDX[1] = fVar3;

  extraout_EDX[4] = fVar3;

  extraout_EDX[3] = 0.0;

  fVar4 = g_flOne - local_c * local_c * g_flLevelUpUiBase_Inferred;

  fVar3 = local_8 * local_10 * fVar2;

  extraout_EDX[2] = fVar3;

  extraout_EDX[8] = fVar3;

  extraout_EDX[5] = fVar4;

  fVar3 = local_8 * local_c * fVar2;

  extraout_EDX[6] = fVar3;

  extraout_EDX[7] = 0.0;

  extraout_EDX[9] = fVar3;

  fVar3 = g_flOne;

  fVar4 = g_flOne - local_8 * local_8 * g_flLevelUpUiBase_Inferred;

  extraout_EDX[0xb] = 0.0;

  extraout_EDX[0xc] = fVar1 * local_10 * fVar2;

  extraout_EDX[10] = fVar4;

  extraout_EDX[0xd] = fVar1 * local_c * fVar2;

  extraout_EDX[0xe] = fVar1 * local_8 * fVar2;

  extraout_EDX[0xf] = fVar3;

  return extraout_EDX;

}
