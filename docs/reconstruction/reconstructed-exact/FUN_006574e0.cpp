// =============================================================================
// FUN_006574e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006574e0
// Address:   0x006574e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006574e0 @ 0x006574e0
// Stable ID: aa_006574e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: ABS×4, FUN_00567ce0×2, FUN_005b3300, FUN_006574e0, SQRT.
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

void __thiscall FUN_006574e0(int param_1,int *param_2)



{

  int iVar1;

  bool bVar2;

  uint uVar3;

  float *pfVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30 [4];

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  iVar7 = *(int *)(param_1 + 0x80);

  if ((int)(param_2[2] & 0x7fffffffU) < iVar7) {

    iVar5 = (param_2[2] & 0x7fffffffU) * 2;

    if (iVar5 <= iVar7) {

      iVar5 = iVar7;

    }

    FUN_005b3300(param_2,iVar5,0x10);

  }

  param_2[1] = iVar7;

  fVar8 = ABS(*(float *)(param_1 + 0x70));

  pfVar4 = (float *)(param_1 + 0x70);

  bVar2 = fVar8 <= ABS(*(float *)(param_1 + 0x74));

  if (!bVar2) {

    fVar8 = ABS(*(float *)(param_1 + 0x74));

  }

  uVar3 = (uint)!bVar2;

  uVar6 = 2;

  if (ABS(*(float *)(param_1 + 0x78)) < fVar8) {

    uVar3 = 2;

    uVar6 = (uint)!bVar2;

  }

  fVar8 = 0.0;

  local_30[uVar3] = 0.0;

  local_30[bVar2] = pfVar4[uVar6];

  local_30[uVar6] = 0.0 - pfVar4[bVar2];

  fVar12 = local_30[2] * local_30[2] + local_30[1] * local_30[1] + local_30[0] * local_30[0];

  if (fVar12 != 0.0) {

    fVar8 = g_flOne / SQRT(fVar12);

  }

  local_30[2] = local_30[2] * fVar8;

  local_30[0] = fVar8 * local_30[0];

  local_30[1] = fVar8 * local_30[1];

  local_30[3] = local_30[3] * fVar8;

  FUN_00567ce0(local_30,*(uint32_t /* width from decompiler */ *)(param_1 + 0x84));

  FUN_00567ce0(pfVar4,DAT_00a11098 / (float)*(int *)(param_1 + 0x80));

  fVar9 = local_14 * local_14 * g_flLevelUpUiBase_Inferred - g_flOne;

  fVar8 = (*(float *)(param_1 + 0x74) * local_1c + *(float *)(param_1 + 0x78) * local_18 +

          *pfVar4 * local_20) * g_flLevelUpUiBase_Inferred;

  fVar12 = local_14 * g_flLevelUpUiBase_Inferred;

  fVar16 = (*(float *)(param_1 + 0x78) * local_1c - *(float *)(param_1 + 0x74) * local_18) * fVar12

           + local_20 * fVar8 + *pfVar4 * fVar9;

  fVar13 = (*pfVar4 * local_18 - *(float *)(param_1 + 0x78) * local_20) * fVar12 +

           local_1c * fVar8 + *(float *)(param_1 + 0x74) * fVar9;

  iVar7 = 0;

  fVar14 = (*(float *)(param_1 + 0x74) * local_20 - *pfVar4 * local_1c) * fVar12 +

           local_18 * fVar8 + *(float *)(param_1 + 0x78) * fVar9;

  fVar8 = fVar12 * g_flZero + local_14 * fVar8 + *(float *)(param_1 + 0x7c) * fVar9;

  if (0 < *(int *)(param_1 + 0x80)) {

    iVar5 = 0;

    do {

      fVar9 = g_flLevelUpUiBase_Inferred;

      iVar1 = *param_2;

      *(uint32_t /* width from decompiler */ *)(iVar1 + iVar5) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

      *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + iVar5) = *(uint32_t /* width from decompiler */ *)(param_1 + 100);

      *(uint32_t /* width from decompiler */ *)(iVar1 + 8 + iVar5) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc + iVar5) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c);

      fVar12 = *(float *)(param_1 + 0x88);

      pfVar4 = (float *)(*param_2 + iVar5);

      *pfVar4 = fVar12 * fVar16 + *pfVar4;

      pfVar4[1] = fVar13 * fVar12 + pfVar4[1];

      pfVar4[3] = fVar8 * fVar12 + pfVar4[3];

      pfVar4[2] = fVar14 * fVar12 + pfVar4[2];

      fVar12 = (local_38 * fVar14 + local_3c * fVar13 + local_40 * fVar16) * fVar9;

      fVar10 = local_34 * local_34 * fVar9 - g_flOne;

      fVar9 = local_34 * fVar9;

      fVar17 = local_38 * fVar13;

      fVar11 = local_3c * fVar14;

      fVar15 = fVar13 * local_40;

      fVar13 = (local_38 * fVar16 - fVar14 * local_40) * fVar9 + local_3c * fVar12 + fVar13 * fVar10

      ;

      fVar14 = (fVar15 - local_3c * fVar16) * fVar9 + local_38 * fVar12 + fVar14 * fVar10;

      iVar7 = iVar7 + 1;

      iVar5 = iVar5 + 0x10;

      fVar16 = (fVar11 - fVar17) * fVar9 + local_40 * fVar12 + fVar10 * fVar16;

      fVar8 = fVar9 * g_flZero + local_34 * fVar12 + fVar8 * fVar10;

    } while (iVar7 < *(int *)(param_1 + 0x80));

  }

  return;

}
