// =============================================================================
// FUN_00467c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00467c90
// Address:   0x00467c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00467c90 @ 0x00467c90
// Stable ID: aa_00467c90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×13, for×2, while×2, goto×2, do×1, return×1.
//  - Notable callees: FUN_00467c90, FUN_00468460.
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

void FUN_00467c90(uint32_t /* width from decompiler */ *param_1,int *param_2,int *param_3,int param_4)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  int *piVar7;

  int *piVar8;

  int *piVar9;

  int *local_c;

  int *local_8;

  

  local_8 = param_2 + (((int)param_3 - (int)param_2 >> 2) - ((int)param_3 - (int)param_2 >> 0x1f) >>

                      1);

  FUN_00468460(param_2,local_8,param_3 + -1,param_4);

  piVar5 = local_8 + 1;

  for (; param_2 < local_8; local_8 = local_8 + -1) {

    iVar3 = *local_8;

    iVar4 = local_8[-1];

    fVar2 = *(float *)(iVar3 + param_4 * 4);

    pfVar1 = (float *)(iVar4 + param_4 * 4);

    if ((*pfVar1 <= fVar2 && fVar2 != *pfVar1) ||

       ((((*(float *)(iVar4 + param_4 * 4) == *(float *)(iVar3 + param_4 * 4) &&

          (fVar2 = *(float *)(iVar3 + 0xc + param_4 * 4),

          pfVar1 = (float *)(iVar4 + 0xc + param_4 * 4), *pfVar1 <= fVar2 && fVar2 != *pfVar1)) ||

         (fVar2 = *(float *)(iVar4 + param_4 * 4), pfVar1 = (float *)(iVar3 + param_4 * 4),

         *pfVar1 <= fVar2 && fVar2 != *pfVar1)) ||

        ((*(float *)(iVar3 + param_4 * 4) == *(float *)(iVar4 + param_4 * 4) &&

         (fVar2 = *(float *)(iVar4 + 0xc + param_4 * 4),

         pfVar1 = (float *)(iVar3 + 0xc + param_4 * 4), *pfVar1 <= fVar2 && fVar2 != *pfVar1))))))

    break;

  }

  piVar6 = piVar5;

  local_c = piVar5;

  piVar9 = local_8;

  if (piVar5 < param_3) {

    iVar3 = *local_8;

    while (((iVar4 = *piVar5, fVar2 = *(float *)(iVar3 + param_4 * 4),

            pfVar1 = (float *)(iVar4 + param_4 * 4), piVar6 = piVar5, local_c = piVar5,

            fVar2 < *pfVar1 || fVar2 == *pfVar1 &&

            ((*(float *)(iVar4 + param_4 * 4) != *(float *)(iVar3 + param_4 * 4) ||

             (fVar2 = *(float *)(iVar3 + 0xc + param_4 * 4),

             pfVar1 = (float *)(iVar4 + 0xc + param_4 * 4), fVar2 < *pfVar1 || fVar2 == *pfVar1))))

           && (fVar2 = *(float *)(iVar4 + param_4 * 4), pfVar1 = (float *)(iVar3 + param_4 * 4),

              fVar2 < *pfVar1 || fVar2 == *pfVar1))) {

      if (((*(float *)(iVar3 + param_4 * 4) == *(float *)(iVar4 + param_4 * 4)) &&

          (fVar2 = *(float *)(iVar4 + 0xc + param_4 * 4),

          pfVar1 = (float *)(iVar3 + 0xc + param_4 * 4), *pfVar1 <= fVar2 && fVar2 != *pfVar1)) ||

         (piVar5 = piVar5 + 1, piVar6 = piVar5, local_c = piVar5, param_3 <= piVar5)) break;

    }

  }

joined_r0x00467d9a:

  do {

    piVar7 = local_8;

    if (param_3 <= piVar5) {

joined_r0x00467e14:

      for (; piVar8 = piVar6, param_2 < local_8; local_8 = local_8 + -1) {

        piVar7 = piVar7 + -1;

        iVar3 = *piVar9;

        iVar4 = *piVar7;

        fVar2 = *(float *)(iVar3 + param_4 * 4);

        pfVar1 = (float *)(iVar4 + param_4 * 4);

        if ((fVar2 < *pfVar1 || fVar2 == *pfVar1) &&

           ((*(float *)(iVar4 + param_4 * 4) != *(float *)(iVar3 + param_4 * 4) ||

            (fVar2 = *(float *)(iVar3 + 0xc + param_4 * 4),

            pfVar1 = (float *)(iVar4 + 0xc + param_4 * 4), fVar2 < *pfVar1 || fVar2 == *pfVar1)))) {

          fVar2 = *(float *)(iVar4 + param_4 * 4);

          pfVar1 = (float *)(iVar3 + param_4 * 4);

          piVar8 = local_c;

          if ((*pfVar1 <= fVar2 && fVar2 != *pfVar1) ||

             ((*(float *)(iVar3 + param_4 * 4) == *(float *)(iVar4 + param_4 * 4) &&

              (fVar2 = *(float *)(iVar4 + 0xc + param_4 * 4),

              pfVar1 = (float *)(iVar3 + 0xc + param_4 * 4), *pfVar1 <= fVar2 && fVar2 != *pfVar1)))

             ) break;

          iVar3 = piVar9[-1];

          piVar9 = piVar9 + -1;

          *piVar9 = *piVar7;

          *piVar7 = iVar3;

        }

        piVar6 = local_c;

      }

      if (local_8 == param_2) {

        if (piVar5 == param_3) {

          *param_1 = piVar9;

          param_1[1] = piVar8;

          return;

        }

        if (piVar8 != piVar5) {

          iVar3 = *piVar9;

          *piVar9 = *piVar8;

          *piVar8 = iVar3;

        }

        iVar3 = *piVar9;

        *piVar9 = *piVar5;

        *piVar5 = iVar3;

        piVar5 = piVar5 + 1;

        piVar6 = piVar8 + 1;

        local_c = piVar8 + 1;

        piVar9 = piVar9 + 1;

      }

      else {

        local_8 = local_8 + -1;

        if (piVar5 == param_3) {

          piVar9 = piVar9 + -1;

          if (local_8 != piVar9) {

            iVar3 = *local_8;

            *local_8 = *piVar9;

            *piVar9 = iVar3;

          }

          iVar3 = *piVar9;

          piVar6 = piVar8 + -1;

          *piVar9 = piVar8[-1];

          *piVar6 = iVar3;

          local_c = piVar6;

        }

        else {

          iVar3 = *piVar5;

          *piVar5 = *local_8;

          piVar5 = piVar5 + 1;

          *local_8 = iVar3;

          piVar6 = piVar8;

        }

      }

      goto joined_r0x00467d9a;

    }

    iVar3 = *piVar5;

    iVar4 = *piVar9;

    fVar2 = *(float *)(iVar3 + param_4 * 4);

    pfVar1 = (float *)(iVar4 + param_4 * 4);

    if ((fVar2 < *pfVar1 || fVar2 == *pfVar1) &&

       ((*(float *)(iVar4 + param_4 * 4) != *(float *)(iVar3 + param_4 * 4) ||

        (fVar2 = *(float *)(iVar3 + 0xc + param_4 * 4),

        pfVar1 = (float *)(iVar4 + 0xc + param_4 * 4), fVar2 < *pfVar1 || fVar2 == *pfVar1)))) {

      fVar2 = *(float *)(iVar4 + param_4 * 4);

      pfVar1 = (float *)(iVar3 + param_4 * 4);

      local_c = piVar6;

      if ((*pfVar1 <= fVar2 && fVar2 != *pfVar1) ||

         ((*(float *)(iVar3 + param_4 * 4) == *(float *)(iVar4 + param_4 * 4) &&

          (fVar2 = *(float *)(iVar4 + 0xc + param_4 * 4),

          pfVar1 = (float *)(iVar3 + 0xc + param_4 * 4), *pfVar1 <= fVar2 && fVar2 != *pfVar1))))

      goto joined_r0x00467e14;

      iVar3 = *piVar6;

      *piVar6 = *piVar5;

      piVar6 = piVar6 + 1;

      *piVar5 = iVar3;

    }

    piVar5 = piVar5 + 1;

    local_c = piVar6;

  } while( true );

}
