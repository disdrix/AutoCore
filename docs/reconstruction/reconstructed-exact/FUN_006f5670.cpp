// =============================================================================
// FUN_006f5670
// -----------------------------------------------------------------------------
// Stable ID: aa_006f5670
// Address:   0x006f5670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f5670 @ 0x006f5670
// Stable ID: aa_006f5670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~249 non-empty decompiler lines.
//  - Control keywords: if×33, do×1, while×1, return×1.
//  - Notable callees: FUN_006f5670.
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

void FUN_006f5670(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int *param_4)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  float fVar6;

  float fVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  int *piVar11;

  int iVar12;

  uint32_t /* width from decompiler */ local_3c;

  char local_38 [8];

  float local_30;

  float local_2c;

  float local_28;

  float local_20;

  float local_1c;

  

  pfVar1 = (float *)*param_1;

  local_3c = 5;

  local_38[4] = '\0';

  local_38[0] = '\0';

  local_38[1] = '\0';

  local_38[2] = '\0';

  local_38[3] = '\0';

  pfVar2 = (float *)param_1[1];

  fVar7 = (*pfVar1 - *pfVar2) * (*pfVar1 - *pfVar2) +

          (pfVar1[1] - pfVar2[1]) * (pfVar1[1] - pfVar2[1]) +

          (pfVar1[2] - pfVar2[2]) * (pfVar1[2] - pfVar2[2]);

  fVar6 = g_flZero;

  if (g_flZero < fVar7) {

    fVar6 = fVar7;

  }

  uVar9 = (uint)(g_flZero < fVar7);

  if (uVar9 != 2) {

    pfVar2 = (float *)param_1[2];

    fVar7 = (*pfVar1 - *pfVar2) * (*pfVar1 - *pfVar2) +

            (pfVar1[1] - pfVar2[1]) * (pfVar1[1] - pfVar2[1]) +

            (pfVar1[2] - pfVar2[2]) * (pfVar1[2] - pfVar2[2]);

    if (fVar6 < fVar7) {

      uVar9 = 2;

      fVar6 = fVar7;

    }

  }

  if (uVar9 != 3) {

    pfVar2 = (float *)param_1[3];

    fVar7 = (*pfVar1 - *pfVar2) * (*pfVar1 - *pfVar2) +

            (pfVar1[1] - pfVar2[1]) * (pfVar1[1] - pfVar2[1]) +

            (pfVar1[2] - pfVar2[2]) * (pfVar1[2] - pfVar2[2]);

    if (fVar6 < fVar7) {

      uVar9 = 3;

      fVar6 = fVar7;

    }

  }

  if ((uVar9 != 4) &&

     (pfVar2 = (float *)param_1[4],

     fVar6 < (*pfVar1 - *pfVar2) * (*pfVar1 - *pfVar2) +

             (pfVar1[1] - pfVar2[1]) * (pfVar1[1] - pfVar2[1]) +

             (pfVar1[2] - pfVar2[2]) * (pfVar1[2] - pfVar2[2]))) {

    uVar9 = 4;

  }

  local_38[uVar9] = '\x01';

  pfVar2 = (float *)param_1[uVar9];

  uVar10 = uVar9;

  fVar6 = g_flZero;

  if ((local_38[0] == '\0') &&

     (fVar7 = (*pfVar2 - *pfVar1) * (*pfVar2 - *pfVar1) +

              (pfVar2[1] - pfVar1[1]) * (pfVar2[1] - pfVar1[1]) +

              (pfVar2[2] - pfVar1[2]) * (pfVar2[2] - pfVar1[2]), g_flZero < fVar7)) {

    uVar10 = 0;

    fVar6 = fVar7;

  }

  if (local_38[1] == '\0') {

    pfVar3 = (float *)param_1[1];

    fVar7 = (*pfVar2 - *pfVar3) * (*pfVar2 - *pfVar3) +

            (pfVar2[1] - pfVar3[1]) * (pfVar2[1] - pfVar3[1]) +

            (pfVar2[2] - pfVar3[2]) * (pfVar2[2] - pfVar3[2]);

    if (fVar6 < fVar7) {

      uVar10 = 1;

      fVar6 = fVar7;

    }

  }

  if (local_38[2] == '\0') {

    pfVar3 = (float *)param_1[2];

    fVar7 = (*pfVar2 - *pfVar3) * (*pfVar2 - *pfVar3) +

            (pfVar2[1] - pfVar3[1]) * (pfVar2[1] - pfVar3[1]) +

            (pfVar2[2] - pfVar3[2]) * (pfVar2[2] - pfVar3[2]);

    if (fVar6 < fVar7) {

      uVar10 = 2;

      fVar6 = fVar7;

    }

  }

  if (local_38[3] == '\0') {

    pfVar3 = (float *)param_1[3];

    fVar7 = (*pfVar2 - *pfVar3) * (*pfVar2 - *pfVar3) +

            (pfVar2[1] - pfVar3[1]) * (pfVar2[1] - pfVar3[1]) +

            (pfVar2[2] - pfVar3[2]) * (pfVar2[2] - pfVar3[2]);

    if (fVar6 < fVar7) {

      uVar10 = 3;

      fVar6 = fVar7;

    }

  }

  if ((local_38[4] == '\0') &&

     (pfVar3 = (float *)param_1[4],

     fVar6 < (*pfVar2 - *pfVar3) * (*pfVar2 - *pfVar3) +

             (pfVar2[1] - pfVar3[1]) * (pfVar2[1] - pfVar3[1]) +

             (pfVar2[2] - pfVar3[2]) * (pfVar2[2] - pfVar3[2]))) {

    uVar10 = 4;

  }

  pfVar2 = (float *)param_1[uVar9];

  pfVar3 = (float *)param_1[uVar10];

  local_30 = *pfVar2 - *pfVar3;

  local_38[uVar10] = '\x01';

  local_2c = pfVar2[1] - pfVar3[1];

  local_28 = pfVar2[2] - pfVar3[2];

  fVar6 = g_flZero;

  if (local_38[0] == '\0') {

    local_20 = (pfVar3[1] - pfVar1[1]) * local_28 - (pfVar3[2] - pfVar1[2]) * local_2c;

    local_1c = (pfVar3[2] - pfVar1[2]) * local_30 - local_28 * (*pfVar3 - *pfVar1);

    fVar7 = local_2c * (*pfVar3 - *pfVar1) - (pfVar3[1] - pfVar1[1]) * local_30;

    fVar7 = local_20 * local_20 + local_1c * local_1c + fVar7 * fVar7;

    if (g_flZero < fVar7) {

      uVar10 = 0;

      fVar6 = fVar7;

    }

  }

  if (local_38[1] == '\0') {

    pfVar2 = (float *)param_1[1];

    local_20 = (pfVar3[1] - pfVar2[1]) * local_28 - (pfVar3[2] - pfVar2[2]) * local_2c;

    local_1c = (pfVar3[2] - pfVar2[2]) * local_30 - local_28 * (*pfVar3 - *pfVar2);

    fVar7 = local_2c * (*pfVar3 - *pfVar2) - (pfVar3[1] - pfVar2[1]) * local_30;

    fVar7 = local_20 * local_20 + local_1c * local_1c + fVar7 * fVar7;

    if (fVar6 < fVar7) {

      uVar10 = 1;

      fVar6 = fVar7;

    }

  }

  if (local_38[2] == '\0') {

    pfVar2 = (float *)param_1[2];

    local_20 = (pfVar3[1] - pfVar2[1]) * local_28 - (pfVar3[2] - pfVar2[2]) * local_2c;

    local_1c = (pfVar3[2] - pfVar2[2]) * local_30 - local_28 * (*pfVar3 - *pfVar2);

    fVar7 = local_2c * (*pfVar3 - *pfVar2) - (pfVar3[1] - pfVar2[1]) * local_30;

    fVar7 = local_20 * local_20 + local_1c * local_1c + fVar7 * fVar7;

    if (fVar6 < fVar7) {

      uVar10 = 2;

      fVar6 = fVar7;

    }

  }

  if (local_38[3] == '\0') {

    pfVar2 = (float *)param_1[3];

    local_20 = (pfVar3[1] - pfVar2[1]) * local_28 - (pfVar3[2] - pfVar2[2]) * local_2c;

    local_1c = (pfVar3[2] - pfVar2[2]) * local_30 - local_28 * (*pfVar3 - *pfVar2);

    fVar7 = local_2c * (*pfVar3 - *pfVar2) - (pfVar3[1] - pfVar2[1]) * local_30;

    fVar7 = local_20 * local_20 + local_1c * local_1c + fVar7 * fVar7;

    if (fVar6 < fVar7) {

      uVar10 = 3;

      fVar6 = fVar7;

    }

  }

  if (local_38[4] == '\0') {

    pfVar2 = (float *)param_1[4];

    local_20 = (pfVar3[1] - pfVar2[1]) * local_28 - (pfVar3[2] - pfVar2[2]) * local_2c;

    local_1c = (pfVar3[2] - pfVar2[2]) * local_30 - local_28 * (*pfVar3 - *pfVar2);

    fVar7 = local_2c * (*pfVar3 - *pfVar2) - (pfVar3[1] - pfVar2[1]) * local_30;

    if (fVar6 < local_20 * local_20 + local_1c * local_1c + fVar7 * fVar7) {

      uVar10 = 4;

    }

  }

  pfVar2 = (float *)param_1[uVar10];

  local_38[uVar10] = '\x01';

  fVar6 = g_flZero;

  if ((local_38[0] == '\0') &&

     (fVar7 = (*pfVar2 - *pfVar1) * (*pfVar2 - *pfVar1) +

              (pfVar2[1] - pfVar1[1]) * (pfVar2[1] - pfVar1[1]) +

              (pfVar2[2] - pfVar1[2]) * (pfVar2[2] - pfVar1[2]), g_flZero < fVar7)) {

    uVar10 = 0;

    fVar6 = fVar7;

  }

  if (local_38[1] == '\0') {

    pfVar1 = (float *)param_1[1];

    fVar7 = (*pfVar2 - *pfVar1) * (*pfVar2 - *pfVar1) +

            (pfVar2[1] - pfVar1[1]) * (pfVar2[1] - pfVar1[1]) +

            (pfVar2[2] - pfVar1[2]) * (pfVar2[2] - pfVar1[2]);

    if (fVar6 < fVar7) {

      uVar10 = 1;

      fVar6 = fVar7;

    }

  }

  if (local_38[2] == '\0') {

    pfVar1 = (float *)param_1[2];

    fVar7 = (*pfVar2 - *pfVar1) * (*pfVar2 - *pfVar1) +

            (pfVar2[1] - pfVar1[1]) * (pfVar2[1] - pfVar1[1]) +

            (pfVar2[2] - pfVar1[2]) * (pfVar2[2] - pfVar1[2]);

    if (fVar6 < fVar7) {

      uVar10 = 2;

      fVar6 = fVar7;

    }

  }

  if (local_38[3] == '\0') {

    pfVar1 = (float *)param_1[3];

    fVar7 = (*pfVar2 - *pfVar1) * (*pfVar2 - *pfVar1) +

            (pfVar2[1] - pfVar1[1]) * (pfVar2[1] - pfVar1[1]) +

            (pfVar2[2] - pfVar1[2]) * (pfVar2[2] - pfVar1[2]);

    if (fVar6 < fVar7) {

      uVar10 = 3;

      fVar6 = fVar7;

    }

  }

  if ((local_38[4] == '\0') &&

     (pfVar1 = (float *)param_1[4],

     fVar6 < (*pfVar2 - *pfVar1) * (*pfVar2 - *pfVar1) +

             (pfVar2[1] - pfVar1[1]) * (pfVar2[1] - pfVar1[1]) +

             (pfVar2[2] - pfVar1[2]) * (pfVar2[2] - pfVar1[2]))) {

    uVar10 = 4;

  }

  local_38[uVar10] = '\x01';

  iVar12 = 0;

  piVar11 = param_1 + 4;

  do {

    if (local_38[iVar12] == '\0') {

      (**(code **)(*param_4 + 8))(*(uint16_t *)(param_1[iVar12] + 0x1c));

      puVar4 = (uint32_t /* width from decompiler */ *)*piVar11;

      puVar5 = (uint32_t /* width from decompiler */ *)param_1[iVar12];

      *puVar5 = *puVar4;

      puVar5[1] = puVar4[1];

      puVar5[2] = puVar4[2];

      puVar5[3] = puVar4[3];

      puVar5[4] = puVar4[4];

      puVar5[5] = puVar4[5];

      puVar5[6] = puVar4[6];

      puVar5[7] = puVar4[7];

      puVar5[8] = puVar4[8];

      puVar5[9] = puVar4[9];

      puVar5[10] = puVar4[10];

      puVar5[0xb] = puVar4[0xb];

      iVar8 = local_3c + 3;

      local_3c = local_3c + -1;

      local_38[iVar12] = *(char *)((int)&local_3c + iVar8);

      piVar11 = piVar11 + -1;

    }

    else {

      iVar12 = iVar12 + 1;

    }

  } while (iVar12 < local_3c);

  return;

}
