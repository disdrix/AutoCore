// =============================================================================
// FUN_0098d9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0098d9d0
// Address:   0x0098d9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098d9d0 @ 0x0098d9d0
// Stable ID: aa_0098d9d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: SQRT×2, FUN_0098d9d0.
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

void __fastcall FUN_0098d9d0(float *param_1,int param_2,float param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float *in_EAX;

  float fVar5;

  

  fVar4 = DAT_00a0f298;

  fVar1 = in_EAX[2];

  fVar2 = param_1[2];

  fVar5 = (param_1[1] + in_EAX[1]) * DAT_00a0f298;

  *(float *)(param_2 + 8) = (*param_1 + *in_EAX) * DAT_00a0f298;

  *(float *)(param_2 + 0xc) = fVar5;

  *(float *)(param_2 + 0x10) = (fVar1 + fVar2) * fVar4;

  fVar1 = in_EAX[1];

  fVar2 = in_EAX[2];

  fVar5 = param_1[1];

  fVar3 = param_1[2];

  *(float *)(param_2 + 0x14) = (*in_EAX - *param_1) * fVar4;

  *(float *)(param_2 + 0x18) = (fVar1 - fVar5) * fVar4;

  *(float *)(param_2 + 0x20) = param_3;

  *(float *)(param_2 + 0x1c) = (fVar2 - fVar3) * fVar4;

  fVar1 = *(float *)(param_2 + 0x14);

  param_3 = SQRT(*(float *)(param_2 + 0x1c) * *(float *)(param_2 + 0x1c) +

                 *(float *)(param_2 + 0x18) * *(float *)(param_2 + 0x18) + fVar1 * fVar1) + param_3;

  *(float *)(param_2 + 0x24) = param_3;

  fVar1 = *(float *)(param_2 + 8);

  *(float *)(param_2 + 4) =

       SQRT(*(float *)(param_2 + 0x10) * *(float *)(param_2 + 0x10) +

            *(float *)(param_2 + 0xc) * *(float *)(param_2 + 0xc) + fVar1 * fVar1) + param_3;

  return;

}
