// =============================================================================
// FUN_006ea1b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006ea1b0
// Address:   0x006ea1b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ea1b0 @ 0x006ea1b0
// Stable ID: aa_006ea1b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_005d6a40, FUN_0063a3f0, FUN_006ea1b0.
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

void FUN_006ea1b0(uint32_t /* width from decompiler */ *param_1,int param_2,int param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float unaff_EBX;

  float unaff_ESI;

  float fStack_74;

  float fStack_70;

  float fStack_6c;

  uint8_t local_50 [76];

  

  FUN_0063a3f0(*(int *)(param_2 + 8) + 0x20,param_1[2] + 0x20);

  (**(code **)(*(int *)*param_1 + 0x18))(local_50,*(uint32_t /* width from decompiler */ *)(param_3 + 8),param_4);

  FUN_005d6a40(*(int *)(param_2 + 8) + 0x20,param_3 + 0x10);

  fStack_6c = unaff_ESI;

  if (g_flZero < unaff_ESI) {

    fStack_6c = 0.0;

  }

  fVar1 = unaff_EBX;

  if (g_flZero < unaff_EBX) {

    fVar1 = g_flZero;

  }

  fVar2 = fStack_74;

  if (g_flZero < fStack_74) {

    fVar2 = g_flZero;

  }

  fVar3 = fStack_70;

  if (g_flZero < fStack_70) {

    fVar3 = g_flZero;

  }

  if (unaff_ESI < g_flZero) {

    unaff_ESI = g_flZero;

  }

  if (unaff_EBX < g_flZero) {

    unaff_EBX = g_flZero;

  }

  if (fStack_74 < g_flZero) {

    fStack_74 = g_flZero;

  }

  if (fStack_70 < g_flZero) {

    fStack_70 = g_flZero;

  }

  *param_4 = fStack_6c + *param_4;

  param_4[1] = fVar1 + param_4[1];

  param_4[2] = fVar2 + param_4[2];

  param_4[3] = fVar3 + param_4[3];

  param_4[4] = unaff_ESI + param_4[4];

  param_4[5] = unaff_EBX + param_4[5];

  param_4[6] = fStack_74 + param_4[6];

  param_4[7] = fStack_70 + param_4[7];

  return;

}
