// =============================================================================
// FUN_00700e10
// -----------------------------------------------------------------------------
// Stable ID: aa_00700e10
// Address:   0x00700e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00700e10 @ 0x00700e10
// Stable ID: aa_00700e10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: ABS×4, FUN_00700810×2, FUN_00700a30×2, SQRT×2, FUN_00700e10.
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

void __fastcall FUN_00700e10(int param_1)



{

  float fVar1;

  float *pfVar2;

  float fVar3;

  bool bVar4;

  uint uVar5;

  uint uVar6;

  float local_d0 [4];

  float local_c0 [4];

  float local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  float local_98;

  float local_94;

  uint8_t local_90 [48];

  float local_60;

  uint8_t local_50 [48];

  float local_20;

  

  pfVar2 = *(float **)(param_1 + 0x50);

  local_c0[0] = *pfVar2 - pfVar2[4];

  local_c0[1] = pfVar2[1] - pfVar2[5];

  local_c0[2] = pfVar2[2] - pfVar2[6];

  local_c0[3] = pfVar2[3] - pfVar2[7];

  local_94 = ABS(local_c0[1]);

  local_98 = ABS(local_c0[2]);

  bVar4 = ABS(local_c0[0]) <= local_94;

  fVar1 = ABS(local_c0[0]);

  if (!bVar4) {

    fVar1 = local_94;

  }

  uVar5 = (uint)!bVar4;

  uVar6 = 2;

  if (local_98 < fVar1) {

    uVar5 = 2;

    uVar6 = (uint)!bVar4;

  }

  fVar3 = local_c0[uVar6];

  fVar1 = local_c0[bVar4];

  local_d0[uVar5] = 0.0;

  local_d0[bVar4] = fVar3;

  local_d0[uVar6] = -fVar1;

  local_b0 = local_d0[2] * local_c0[1] - local_d0[1] * local_c0[2];

  local_ac = local_c0[2] * local_d0[0] - local_d0[2] * local_c0[0];

  local_a8 = local_d0[1] * local_c0[0] - local_d0[0] * local_c0[1];

  fVar1 = local_d0[0] * local_d0[0] + local_d0[2] * local_d0[2] + local_d0[1] * local_d0[1];

  fVar3 = g_flZero;

  if (fVar1 != g_flZero) {

    fVar3 = g_flOne / SQRT(fVar1);

  }

  local_d0[0] = local_d0[0] * fVar3;

  local_d0[1] = local_d0[1] * fVar3;

  local_d0[2] = local_d0[2] * fVar3;

  local_d0[3] = fVar3 * local_d0[3];

  fVar1 = local_b0 * local_b0 + local_ac * local_ac + local_a8 * local_a8;

  local_a4 = g_flZero;

  if (fVar1 != g_flZero) {

    local_a4 = g_flOne / SQRT(fVar1);

  }

  local_b0 = local_a4 * local_b0;

  local_ac = local_ac * local_a4;

  local_a8 = local_a8 * local_a4;

  local_a4 = local_a4 * g_flZero;

  FUN_00700a30(local_d0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),local_90);

  FUN_00700a30(&local_b0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),local_50);

  if (local_60 <= local_20) {

    FUN_00700810(local_50);

    return;

  }

  FUN_00700810(local_90);

  return;

}
