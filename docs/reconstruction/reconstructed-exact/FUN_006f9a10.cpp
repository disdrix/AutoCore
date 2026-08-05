// =============================================================================
// FUN_006f9a10
// -----------------------------------------------------------------------------
// Stable ID: aa_006f9a10
// Address:   0x006f9a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f9a10 @ 0x006f9a10
// Stable ID: aa_006f9a10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_006f9a10.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_006f9a10(int param_1,float *param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_20;

  float local_1c;

  

  *(short *)(param_2 + 0xe) = (short)param_3;

  fVar1 = *(float *)(param_1 + 0x70 + param_3 * 4);

  fVar2 = *(float *)(param_1 + 0x80 + param_3 * 4);

  fVar3 = *(float *)(param_1 + 0x90 + param_3 * 4);

  if (g_flZero <= *(float *)(param_1 + 0xb0 + param_3 * 4)) {

    param_2[0xc] = 1.0;

    param_2[4] = -*(float *)(param_1 + 0x30);

    param_2[5] = -*(float *)(param_1 + 0x34);

    param_2[6] = -*(float *)(param_1 + 0x38);

    param_2[7] = -*(float *)(param_1 + 0x3c);

  }

  else {

    param_2[0xc] = -1.0;

    param_2[4] = *(float *)(param_1 + 0x30);

    param_2[5] = *(float *)(param_1 + 0x34);

    param_2[6] = *(float *)(param_1 + 0x38);

    param_2[7] = *(float *)(param_1 + 0x3c);

  }

  local_20 = -1e-05;

  local_1c = -1e-05;

  if (g_flZero < *(float *)(param_1 + 0xc0)) {

    local_20 = 1e-05;

  }

  if (g_flZero < *(float *)(param_1 + 0xc4)) {

    local_1c = 1e-05;

  }

  fVar5 = _DAT_00aaa940;

  if (g_flZero < *(float *)(param_1 + 200)) {

    fVar5 = DAT_00aaa620;

  }

  fVar4 = param_2[0xc];

  fVar6 = fVar4 * g_flZero;

  param_2[4] = (float)((uint)param_2[4] ^ (uint)(local_20 * fVar4 + fVar1) & 0x80000000);

  param_2[5] = (float)((uint)param_2[5] ^ (uint)(local_1c * fVar4 + fVar2) & 0x80000000);

  param_2[6] = (float)((uint)param_2[6] ^ (uint)(fVar5 * fVar4 + fVar3) & 0x80000000);

  param_2[7] = (float)((uint)param_2[7] ^ (uint)fVar6 & 0x80000000);

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
