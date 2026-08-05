// =============================================================================
// FUN_004c46b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c46b0
// Address:   0x004c46b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c46b0 @ 0x004c46b0
// Stable ID: aa_004c46b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004c46b0.
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

void __thiscall FUN_004c46b0(int param_1,float *param_2,float *param_3)



{

  int iVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  float fVar5;

  

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x144))();

  fVar5 = g_flMultiKillCountBlend;

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  *param_3 = *(float *)(iVar1 + 0x84 + param_1);

  param_3[1] = *(float *)(iVar1 + 0x88 + param_1);

  param_3[2] = *(float *)(iVar1 + 0x8c + param_1);

  fVar2 = *(float *)(iVar1 + param_1 + 0x90);

  param_3[3] = fVar2;

  *param_3 = *param_3 + fVar5;

  fVar4 = DAT_00a0f520;

  param_3[1] = param_3[1] + DAT_00a0f520;

  param_3[3] = fVar2;

  param_3[2] = param_3[2] + fVar5;

  iVar3 = *(int *)(*(int *)(param_1 + 4) + 4);

  iVar1 = iVar3 + 0x84 + param_1;

  *param_2 = *(float *)(iVar3 + 0x84 + param_1);

  param_2[1] = *(float *)(iVar1 + 4);

  param_2[2] = *(float *)(iVar1 + 8);

  fVar2 = *(float *)(iVar1 + 0xc);

  *param_2 = *param_2 - fVar5;

  param_2[3] = fVar2;

  param_2[1] = param_2[1] - fVar4;

  param_2[2] = param_2[2] - fVar5;

  param_2[3] = fVar2;

  return;

}
