// =============================================================================
// FUN_006f84b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f84b0
// Address:   0x006f84b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f84b0 @ 0x006f84b0
// Stable ID: aa_006f84b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006f84b0.
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

void __thiscall FUN_006f84b0(int param_1,float *param_2,uint16_t *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  uint uVar4;

  

  *(uint16_t *)(param_2 + 0xe) = *param_3;

  param_2[0xc] = (float)(((ushort)param_3[1] & 0xffffff00) << 0x14 | 0x3f800000);

  uVar4 = *(byte *)(param_3 + 1) >> 1 & 0x78;

  param_2[4] = *(float *)(param_1 + 0x30) * *(float *)(&DAT_00a0ef70 + uVar4);

  param_2[5] = *(float *)(param_1 + 0x34) * *(float *)(&DAT_00a0ef74 + uVar4);

  param_2[6] = *(float *)(param_1 + 0x38) * *(float *)(&DAT_00a0ef78 + uVar4);

  param_2[7] = *(float *)(param_1 + 0x3c) * *(float *)(&DAT_00a0ef7c + uVar4);

  fVar1 = param_2[4];

  fVar2 = param_2[5];

  fVar3 = param_2[6];

  *param_2 = fVar1 * *(float *)(param_1 + 0x70) +

             fVar2 * *(float *)(param_1 + 0x80) + fVar3 * *(float *)(param_1 + 0x90) +

             *(float *)(param_1 + 0xa0);

  param_2[1] = fVar1 * *(float *)(param_1 + 0x74) +

               fVar2 * *(float *)(param_1 + 0x84) + fVar3 * *(float *)(param_1 + 0x94) +

               *(float *)(param_1 + 0xa4);

  param_2[2] = fVar1 * *(float *)(param_1 + 0x78) +

               fVar2 * *(float *)(param_1 + 0x88) + fVar3 * *(float *)(param_1 + 0x98) +

               *(float *)(param_1 + 0xa8);

  param_2[3] = 0.0;

  return;

}
