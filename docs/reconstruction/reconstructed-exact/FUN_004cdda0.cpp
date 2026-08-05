// =============================================================================
// FUN_004cdda0
// -----------------------------------------------------------------------------
// Stable ID: aa_004cdda0
// Address:   0x004cdda0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cdda0 @ 0x004cdda0
// Stable ID: aa_004cdda0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×9, return×9, do×1, while×1.
//  - Notable callees: ROUND×4, ABS×3, FUN_004cdda0.
//  - Return sites: 9.

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

uint32_t /* width from decompiler */ __thiscall

FUN_004cdda0(int param_1,float *param_2,float *param_3,float *param_4,float param_5)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  float fVar7;

  float unaff_EBX;

  int iVar8;

  float10 extraout_ST0;

  float10 fVar9;

  float *pfVar10;

  float local_20;

  float fStack_1c;

  float local_18;

  

  if (*(int *)(param_1 + 0xe4e0) == 0) {

    return 0;

  }

  iVar1 = (int)ROUND(*param_2 / *(float *)(*(int *)(param_1 + 0xe4f8) + 0x18));

  pfVar10 = (float *)(param_2[2] / *(float *)(*(int *)(param_1 + 0xe4f8) + 0x18));

  local_20 = (float)(int)ROUND((float)pfVar10);

  fVar2 = *(float *)(*(int *)(param_1 + 0xe4f8) + 0x18);

  *param_4 = *param_2;

  param_4[1] = param_2[1];

  param_4[2] = param_2[2];

  local_18 = *param_2;

  fVar3 = param_2[1];

  fVar4 = param_2[2];

  fVar5 = *param_3;

  iVar8 = (int)(param_5 / fVar2) + 1;

  if ((((iVar1 < 0) || (*(int *)(*(int *)(param_1 + 0xe4f8) + 0x10) <= iVar1)) ||

      ((int)local_20 < 0)) || (*(int *)(*(int *)(param_1 + 0xe4f8) + 0x14) <= (int)local_20)) {

    return 1;

  }

  (**(code **)(**(int **)(param_1 + 0xe4e0) + 0x30))(iVar1,local_20);

  if ((float10)param_2[1] < extraout_ST0) {

    return 1;

  }

  if (0 < iVar8) {

    do {

      local_20 = fVar3 + local_20;

      fStack_1c = fVar4 + fStack_1c;

      local_18 = fVar5 * fVar2 + local_18;

      *pfVar10 = local_20;

      pfVar10[1] = fStack_1c;

      pfVar10[2] = local_18;

      iVar1 = (int)ROUND(local_20 / *(float *)(*(int *)(param_1 + 0xe4f8) + 0x18));

      iVar6 = (int)ROUND(local_18 / *(float *)(*(int *)(param_1 + 0xe4f8) + 0x18));

      if (iVar1 < 0) {

        return 0;

      }

      if (*(int *)(*(int *)(param_1 + 0xe4f8) + 0x10) <= iVar1) {

        return 0;

      }

      if (iVar6 < 0) {

        return 0;

      }

      if (*(int *)(*(int *)(param_1 + 0xe4f8) + 0x14) <= iVar6) {

        return 0;

      }

      fVar9 = (float10)(**(code **)(**(int **)(param_1 + 0xe4e0) + 0x30))(iVar1,iVar6);

      fVar7 = (float)fVar9;

      if (param_2[1] <= fVar7) {

        fVar2 = ABS(pfVar10[1] - unaff_EBX) / (ABS(fVar7 - fStack_1c) + ABS(pfVar10[1] - unaff_EBX))

        ;

        *pfVar10 = (local_20 - *pfVar10) * fVar2 + *pfVar10;

        pfVar10[2] = (local_18 - pfVar10[2]) * fVar2 + pfVar10[2];

        return 1;

      }

      param_3 = (float *)((int)param_3 + 1);

      unaff_EBX = fVar7;

    } while ((int)param_3 < iVar8);

  }

  return 0;

}
