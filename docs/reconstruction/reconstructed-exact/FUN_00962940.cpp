// =============================================================================
// FUN_00962940
// -----------------------------------------------------------------------------
// Stable ID: aa_00962940
// Address:   0x00962940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00962940 @ 0x00962940
// Stable ID: aa_00962940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×20, while×2, return×2, do×1.
//  - Notable callees: FUN_00962940×5, CONCAT31×4.
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

uint __thiscall FUN_00962940(int *param_1,float param_2,int *param_3,float param_4,float param_5)



{

  float fVar1;

  int *piVar2;

  float fVar3;

  byte bVar4;

  char cVar5;

  float *pfVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  float *pfVar9;

  float *pfVar10;

  int *piVar11;

  float local_4;

  

  piVar2 = param_3;

  fVar1 = param_2;

  iVar8 = 0;

  pfVar6 = (float *)((int)param_2 + 0x10);

  pfVar9 = (float *)(param_1 + 6);

  while( true ) {

    local_4 = (pfVar9[-3] - pfVar6[-3]) * (g_flOne / *pfVar6);

    param_2 = (*pfVar9 - pfVar6[-3]) * (g_flOne / *pfVar6);

    pfVar10 = &param_4;

    if (param_2 <= local_4) {

      if (param_4 <= param_2) {

        pfVar10 = &param_2;

      }

      param_4 = *pfVar10;

      pfVar10 = &param_5;

      if (local_4 <= param_5) {

        pfVar10 = &local_4;

      }

    }

    else {

      if (param_4 <= local_4) {

        pfVar10 = &local_4;

      }

      param_4 = *pfVar10;

      pfVar10 = &param_5;

      if (param_2 <= param_5) {

        pfVar10 = &param_2;

      }

    }

    param_5 = *pfVar10;

    if (*pfVar10 < param_4) break;

    iVar8 = iVar8 + 1;

    pfVar9 = pfVar9 + 1;

    pfVar6 = pfVar6 + 1;

    if (2 < iVar8) {

      piVar11 = (int *)param_1[0x10];

      param_2 = (float)((uint)param_2 & 0xffffff00);

      if (piVar11 != (int *)param_1[0x11]) {

        do {

          bVar4 = (**(code **)(*piVar2 + 4))(fVar1,*(uint32_t /* width from decompiler */ *)(*piVar11 + 0x18));

          bVar4 = param_2._0_1_ | bVar4;

          param_2 = (float)CONCAT31(param_2._1_3_,bVar4);

          piVar11 = piVar11 + 1;

        } while (piVar11 != (int *)param_1[0x11]);

        if (bVar4 != 0) {

          param_5 = *(float *)((int)fVar1 + 0x1c);

        }

      }

      fVar3 = param_4;

      if ((param_1[2] != 0) && (cVar5 = FUN_00962940(fVar1,piVar2,param_4,param_5), cVar5 != '\0'))

      {

        param_2 = (float)CONCAT31(param_2._1_3_,1);

        param_5 = *(float *)((int)fVar1 + 0x1c);

      }

      iVar8 = param_1[0xd];

      param_3 = (int *)(((float)param_1[0xe] - *(float *)((int)fVar1 + 4 + iVar8 * 4)) /

                       *(float *)((int)fVar1 + 0x10 + iVar8 * 4));

      if (*(float *)((int)fVar1 + 0x10 + iVar8 * 4) <= g_flZero) {

        if ((*param_1 != 0) && (param_4 < (float)param_3)) {

          puVar7 = &param_5;

          if ((float)param_3 <= param_5) {

            puVar7 = &param_3;

          }

          cVar5 = FUN_00962940(fVar1,piVar2,fVar3,*puVar7);

          if (cVar5 != '\0') {

            param_2 = (float)CONCAT31(param_2._1_3_,1);

            param_5 = *(float *)((int)fVar1 + 0x1c);

          }

        }

        iVar8 = param_1[1];

      }

      else {

        if ((param_1[1] != 0) && (param_4 < (float)param_3)) {

          puVar7 = &param_5;

          if ((float)param_3 <= param_5) {

            puVar7 = &param_3;

          }

          cVar5 = FUN_00962940(fVar1,piVar2,fVar3,*puVar7);

          if (cVar5 != '\0') {

            param_2 = (float)CONCAT31(param_2._1_3_,1);

            param_5 = *(float *)((int)fVar1 + 0x1c);

          }

        }

        iVar8 = *param_1;

      }

      if ((iVar8 != 0) && ((float)param_3 < param_5)) {

        puVar7 = &param_4;

        if (param_4 <= (float)param_3) {

          puVar7 = &param_3;

        }

        cVar5 = FUN_00962940(fVar1,piVar2,*puVar7,param_5);

        if (cVar5 != '\0') {

          param_2 = 1.4013e-45;

        }

      }

      return (uint)param_2 & 0xff;

    }

  }

  return 0;

}
