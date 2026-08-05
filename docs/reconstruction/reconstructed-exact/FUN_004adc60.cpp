// =============================================================================
// FUN_004adc60
// -----------------------------------------------------------------------------
// Stable ID: aa_004adc60
// Address:   0x004adc60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004adc60 @ 0x004adc60
// Stable ID: aa_004adc60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×8, do×4, while×4, return×3.
//  - Notable callees: FUN_004b07d0×2, FUN_004adc60, FUN_004afd00, FUN_004b0010, FUN_004b0840, FUN_004b09d0, FUN_00567420, FUN_00788280.
//  - Return sites: 3.

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

/* WARNING: Removing unreachable block (ram,0x004adf30) */



void FUN_004adc60(int param_1,int param_2,int param_3)



{

  int iVar1;

  float *pfVar2;

  float *pfVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ uVar13;

  bool bVar14;

  char cVar15;

  int iVar16;

  int iVar17;

  float fVar18;

  int local_30;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  

  if ((((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3 == 3))

      && (*(int *)(param_2 + 4) != 0)) && (*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 3 == 3))

  {

    FUN_004b0840(0,local_10,local_c);

    bVar14 = true;

    iVar17 = 0;

    do {

      pfVar3 = *(float **)(param_2 + 4);

      pfVar2 = (float *)(iVar17 + *(int *)(param_1 + 4));

      fVar4 = pfVar3[4];

      fVar5 = pfVar3[5];

      fVar6 = pfVar3[2];

      fVar7 = pfVar3[3];

      fVar8 = *pfVar3;

      fVar9 = pfVar3[1];

      fVar10 = pfVar2[1];

      fVar11 = *pfVar2;

      fVar18 = (fVar4 - fVar6) * (fVar10 - fVar7) - (fVar5 - fVar7) * (fVar11 - fVar6);

      if ((((fVar6 - fVar8) * (fVar10 - fVar9) - (fVar11 - fVar8) * (fVar7 - fVar9)) * fVar18 <= 0.0

          ) || (((fVar8 - fVar4) * (fVar10 - fVar5) - (fVar11 - fVar4) * (fVar9 - fVar5)) * fVar18

                <= 0.0)) {

        bVar14 = false;

      }

      else {

        FUN_004b07d0(pfVar2);

      }

      iVar17 = iVar17 + 8;

    } while (iVar17 < 0x18);

    if (bVar14) {

      FUN_004b09d0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8),fVar4);

      return;

    }

    bVar14 = true;

    iVar17 = 0;

    do {

      pfVar3 = *(float **)(param_1 + 4);

      pfVar2 = (float *)(iVar17 + *(int *)(param_2 + 4));

      fVar4 = pfVar3[4];

      fVar5 = pfVar3[5];

      fVar6 = pfVar3[2];

      fVar7 = pfVar3[3];

      fVar8 = *pfVar3;

      fVar9 = pfVar3[1];

      fVar10 = pfVar2[1];

      fVar11 = *pfVar2;

      fVar18 = (fVar10 - fVar7) * (fVar4 - fVar6) - (fVar5 - fVar7) * (fVar11 - fVar6);

      if ((((fVar6 - fVar8) * (fVar10 - fVar9) - (fVar7 - fVar9) * (fVar11 - fVar8)) * fVar18 <= 0.0

          ) || (((fVar8 - fVar4) * (fVar10 - fVar5) - (fVar11 - fVar4) * (fVar9 - fVar5)) * fVar18

                <= 0.0)) {

        bVar14 = false;

      }

      else {

        FUN_004b07d0(pfVar2);

      }

      iVar17 = iVar17 + 8;

    } while (iVar17 < 0x18);

    if (bVar14) {

      uVar12 = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

      uVar13 = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

      if (*(int *)(param_3 + 4) != *(int *)(param_3 + 8)) {

        *(int *)(param_3 + 8) = *(int *)(param_3 + 4);

      }

      FUN_004b0010(*(uint32_t /* width from decompiler */ *)(param_3 + 4),uVar12,uVar13,fVar4);

      return;

    }

    local_30 = 0;

    do {

      iVar16 = local_30 + 1;

      iVar17 = 0;

      do {

        iVar1 = iVar17 + 1;

        cVar15 = FUN_00788280(&local_10,*(int *)(param_1 + 4) + local_30 * 8,

                              (iVar16 % 3) * 8 + *(int *)(param_1 + 4),

                              *(int *)(param_2 + 4) + iVar17 * 8,

                              *(int *)(param_2 + 4) + (iVar1 % 3) * 8);

        if (cVar15 != '\0') {

          iVar17 = *(int *)(param_3 + 4);

          if ((iVar17 == 0) ||

             ((uint)(*(int *)(param_3 + 0xc) - iVar17 >> 3) <=

              (uint)(*(int *)(param_3 + 8) - iVar17 >> 3))) {

            FUN_004afd00(*(uint32_t /* width from decompiler */ *)(param_3 + 8),1,&local_10);

          }

          else {

            iVar17 = *(int *)(param_3 + 8);

            FUN_00567420(iVar17,1,&local_10,param_3,iVar16);

            *(int *)(param_3 + 8) = iVar17 + 8;

          }

        }

        iVar17 = iVar1;

      } while (iVar1 < 3);

      local_30 = iVar16;

    } while (iVar16 < 3);

  }

  return;

}
