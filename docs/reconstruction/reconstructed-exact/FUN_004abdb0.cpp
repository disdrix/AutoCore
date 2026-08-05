// =============================================================================
// FUN_004abdb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004abdb0
// Address:   0x004abdb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004abdb0 @ 0x004abdb0
// Stable ID: aa_004abdb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~97 non-empty decompiler lines.
//  - Control keywords: if×12, do×2, while×2, for×2, return×1.
//  - Notable callees: FUN_004abdb0, FUN_005beae0.
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

void __thiscall FUN_004abdb0(int param_1,int param_2,int param_3)



{

  float *pfVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  int local_24;

  int local_1c;

  int local_18;

  int local_14;

  

  fVar10 = DAT_00a0f718;

  iVar6 = 0;

  if ((*(int *)(param_2 + 4) != 0) &&

     (local_24 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x14, 2 < local_24)) {

    iVar5 = *(int *)(param_1 + 0x14) + -1;

    iVar8 = *(int *)(param_1 + 0x10) + -1;

    local_1c = 0;

    local_18 = 0;

    local_14 = iVar5;

    if (0 < local_24) {

      iVar7 = 0;

      do {

        pfVar2 = (float *)(*(int *)(param_2 + 4) + iVar7);

        if (*pfVar2 <= 0.0 && *pfVar2 != 0.0) {

          *pfVar2 = 0.0;

        }

        fVar9 = (float)*(int *)(param_1 + 0x10) * *(float *)(param_1 + 0x18);

        if (fVar9 <= *pfVar2) {

          *pfVar2 = fVar9 - fVar10;

        }

        if (pfVar2[2] <= 0.0 && pfVar2[2] != 0.0) {

          pfVar2[2] = 0.0;

        }

        fVar9 = (float)*(int *)(param_1 + 0x14) * *(float *)(param_1 + 0x18);

        if (fVar9 <= pfVar2[2]) {

          pfVar2[2] = fVar9 - fVar10;

        }

        fVar9 = g_flOne / *(float *)(param_1 + 0x18);

        iVar4 = (int)(fVar9 * *pfVar2);

        if (iVar4 < iVar8) {

          iVar8 = iVar4;

        }

        iVar3 = (int)(fVar9 * pfVar2[2]);

        if (local_18 < iVar4) {

          local_18 = iVar4;

        }

        if (iVar3 < iVar5) {

          iVar5 = iVar3;

          local_14 = iVar3;

        }

        if (iVar6 < iVar3) {

          iVar6 = iVar3;

          local_1c = iVar3;

        }

        iVar7 = iVar7 + 0x14;

        local_24 = local_24 + -1;

      } while (local_24 != 0);

    }

    for (iVar7 = (int)(iVar8 + (iVar8 >> 0x1f & 0xfU)) >> 4;

        iVar4 = (int)(iVar5 + (iVar5 >> 0x1f & 0xfU)) >> 4,

        iVar7 <= (int)(local_18 + (local_18 >> 0x1f & 0xfU)) >> 4; iVar7 = iVar7 + 1) {

      for (; iVar4 <= (int)(iVar6 + (iVar6 >> 0x1f & 0xfU)) >> 4; iVar4 = iVar4 + 1) {

        if (*(int *)(*(int *)(param_1 + 0x38c) + (*(int *)(param_1 + 900) * iVar4 + iVar7) * 4) != 0

           ) {

          FUN_005beae0(param_2,iVar8,local_1c,local_18,local_14,param_3);

        }

      }

    }

    pfVar2 = *(float **)(param_3 + 4);

    if (pfVar2 != *(float **)(param_3 + 8)) {

      do {

        pfVar1 = *(float **)(param_2 + 4);

        fVar11 = g_flOne / ((pfVar1[0xc] - pfVar1[2]) * (pfVar1[5] - *pfVar1) -

                           (pfVar1[7] - pfVar1[2]) * (pfVar1[10] - *pfVar1));

        fVar9 = ((pfVar1[2] - pfVar2[2]) * (pfVar1[10] - *pfVar2) -

                (pfVar1[0xc] - pfVar2[2]) * (*pfVar1 - *pfVar2)) * fVar11;

        fVar10 = ((pfVar1[0xc] - pfVar2[2]) * (pfVar1[5] - *pfVar2) -

                 (pfVar1[7] - pfVar2[2]) * (pfVar1[10] - *pfVar2)) * fVar11;

        fVar11 = ((pfVar1[7] - pfVar2[2]) * (*pfVar1 - *pfVar2) -

                 (pfVar1[2] - pfVar2[2]) * (pfVar1[5] - *pfVar2)) * fVar11;

        pfVar2[3] = pfVar1[0xd] * fVar11 + pfVar1[8] * fVar9 + pfVar1[3] * fVar10;

        iVar6 = *(int *)(param_2 + 4);

        pfVar2[4] = *(float *)(iVar6 + 0x38) * fVar11 + *(float *)(iVar6 + 0x24) * fVar9 +

                    *(float *)(iVar6 + 0x10) * fVar10;

        pfVar2 = pfVar2 + 5;

      } while (pfVar2 != *(float **)(param_3 + 8));

    }

  }

  return;

}
