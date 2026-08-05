// =============================================================================
// FUN_006f9c20
// -----------------------------------------------------------------------------
// Stable ID: aa_006f9c20
// Address:   0x006f9c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f9c20 @ 0x006f9c20
// Stable ID: aa_006f9c20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_006f9c20.
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



void __thiscall FUN_006f9c20(int param_1,float *param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  int iVar8;

  float local_20;

  float local_1c;

  

  *(short *)(param_2 + 0xe) = (short)param_3 + 3;

  iVar8 = (param_3 + 7) * 0x10;

  fVar1 = *(float *)(iVar8 + param_1);

  iVar8 = iVar8 + param_1;

  fVar2 = *(float *)(iVar8 + 0xc);

  fVar3 = *(float *)(iVar8 + 4);

  fVar4 = *(float *)(iVar8 + 8);

  if (g_flZero <= *(float *)(param_1 + 0xc0 + param_3 * 4)) {

    param_2[0xc] = 1.0;

    *param_2 = *(float *)(param_1 + 0x20);

    param_2[1] = *(float *)(param_1 + 0x24);

    param_2[2] = *(float *)(param_1 + 0x28);

    param_2[3] = *(float *)(param_1 + 0x2c);

  }

  else {

    param_2[0xc] = -1.0;

    *param_2 = -*(float *)(param_1 + 0x20);

    param_2[1] = -*(float *)(param_1 + 0x24);

    param_2[2] = -*(float *)(param_1 + 0x28);

    param_2[3] = -*(float *)(param_1 + 0x2c);

  }

  local_20 = 1e-05;

  local_1c = 1e-05;

  if (g_flZero < *(float *)(param_1 + 0xb0)) {

    local_20 = -1e-05;

  }

  if (g_flZero < *(float *)(param_1 + 0xb4)) {

    local_1c = -1e-05;

  }

  fVar7 = DAT_00aaa620;

  if (g_flZero < *(float *)(param_1 + 0xb8)) {

    fVar7 = _DAT_00aaa940;

  }

  fVar5 = -param_2[0xc];

  fVar6 = fVar5 * g_flZero;

  *param_2 = (float)((uint)*param_2 ^ (uint)(local_20 * fVar5 + fVar1) & 0x80000000);

  param_2[1] = (float)((uint)param_2[1] ^ (uint)(local_1c * fVar5 + fVar3) & 0x80000000);

  param_2[2] = (float)((uint)param_2[2] ^ (uint)(fVar7 * fVar5 + fVar4) & 0x80000000);

  param_2[3] = (float)((uint)param_2[3] ^ (uint)(fVar6 + fVar2) & 0x80000000);

  fVar1 = *param_2 - *(float *)(param_1 + 0xa0);

  fVar3 = param_2[1] - *(float *)(param_1 + 0xa4);

  fVar2 = param_2[2] - *(float *)(param_1 + 0xa8);

  param_2[4] = fVar1 * *(float *)(param_1 + 0x70) +

               fVar3 * *(float *)(param_1 + 0x74) + fVar2 * *(float *)(param_1 + 0x78);

  param_2[5] = fVar1 * *(float *)(param_1 + 0x80) +

               fVar3 * *(float *)(param_1 + 0x84) + fVar2 * *(float *)(param_1 + 0x88);

  param_2[6] = fVar1 * *(float *)(param_1 + 0x90) +

               fVar3 * *(float *)(param_1 + 0x94) + fVar2 * *(float *)(param_1 + 0x98);

  return;

}
