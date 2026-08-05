// =============================================================================
// FUN_006f9e30
// -----------------------------------------------------------------------------
// Stable ID: aa_006f9e30
// Address:   0x006f9e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f9e30 @ 0x006f9e30
// Stable ID: aa_006f9e30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006f9e30.
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

void __thiscall FUN_006f9e30(int param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float *pfVar12;

  float local_30 [6];

  float local_18;

  

  local_30[2] = 0.0;

  local_30[1] = 0.0;

  local_30[0] = 0.0;

  local_30[*(ushort *)(param_2 + 0xe)] = 1.0;

  pfVar12 = (float *)((*(ushort *)((int)param_2 + 0x3a) + 7) * 0x10 + param_1);

  fVar10 = pfVar12[2] * local_30[1] - pfVar12[1] * local_30[2];

  fVar11 = local_30[2] * *pfVar12 - pfVar12[2] * local_30[0];

  local_18 = pfVar12[1] * local_30[0] - local_30[1] * *pfVar12;

  if (fVar10 * *(float *)(param_1 + 0xb0) +

      fVar11 * *(float *)(param_1 + 0xb4) + local_18 * *(float *)(param_1 + 0xb8) < g_flZero) {

    fVar10 = -fVar10;

    fVar11 = -fVar11;

    local_18 = -local_18;

  }

  fVar1 = *(float *)(param_1 + 0x78);

  fVar2 = *(float *)(param_1 + 0x74);

  fVar3 = *(float *)(param_1 + 0x70);

  fVar4 = *(float *)(param_1 + 0x88);

  fVar5 = *(float *)(param_1 + 0x84);

  fVar6 = *(float *)(param_1 + 0x80);

  fVar7 = *(float *)(param_1 + 0x98);

  fVar8 = *(float *)(param_1 + 0x94);

  fVar9 = *(float *)(param_1 + 0x90);

  param_2[2] = local_18;

  param_2[3] = 0.0;

  *param_2 = fVar10;

  param_2[1] = fVar11;

  param_2[4] = fVar10 * fVar3 + fVar11 * fVar2 + local_18 * fVar1;

  param_2[5] = fVar10 * fVar6 + fVar11 * fVar5 + local_18 * fVar4;

  param_2[6] = fVar10 * fVar9 + fVar11 * fVar8 + local_18 * fVar7;

  param_2[7] = 0.0;

  return;

}
