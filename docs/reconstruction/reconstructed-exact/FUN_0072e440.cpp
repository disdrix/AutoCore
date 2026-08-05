// =============================================================================
// FUN_0072e440
// -----------------------------------------------------------------------------
// Stable ID: aa_0072e440
// Address:   0x0072e440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072e440 @ 0x0072e440
// Stable ID: aa_0072e440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~138 non-empty decompiler lines.
//  - Control keywords: if×15, do×3, while×3, return×2.
//  - Notable callees: FUN_00414a50×3, FUN_00464b30, FUN_0046cc90, FUN_0072e440, FUN_00746520, FUN_007468e0.
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

void FUN_0072e440(float *param_1,int param_2)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  int *piVar4;

  int *piVar5;

  char cVar6;

  float *pfVar7;

  int iVar8;

  int iVar9;

  float *pfVar10;

  int iVar11;

  int iVar12;

  float *pfVar13;

  float *local_24;

  int local_18;

  float *local_14;

  float *local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar8 = *(int *)((int)param_1 + 0x14);

  if (iVar8 == 0) {

    local_18 = 0;

  }

  else if (*(int *)(iVar8 + 0x10) == 0) {

    local_18 = 0;

  }

  else {

    local_18 = *(int *)(*(int *)(iVar8 + 0x10) + 8);

  }

  if (iVar8 == 0) {

    local_24 = (float *)0x0;

  }

  else {

    local_24 = *(float **)(iVar8 + 0x18);

  }

  if (*(int *)(iVar8 + 0x10) == 0) {

    pfVar13 = (float *)0x0;

  }

  else {

    pfVar13 = (float *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar8 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar8 + 0x18),4);

  }

  local_10 = pfVar13;

  if (pfVar13 != (float *)0x0) {

    iVar8 = *(int *)(param_2 + 4);

    if ((*(byte *)(*(int *)(iVar8 + 0x10) + 4) & 1) == 0) {

      piVar4 = *(int **)(iVar8 + 0x10);

      local_14 = local_24;

      if (piVar4 == (int *)0x0) {

        pfVar7 = (float *)0x0;

      }

      else {

        if ((int)local_24 < 1) {

          local_14 = *(float **)(iVar8 + 0x18);

        }

        piVar5 = (int *)*piVar4;

        if (piVar5 == (int *)0x0) {

          pfVar7 = (float *)0x0;

        }

        else {

          iVar8 = (**(code **)(*piVar5 + 0x2c))

                            (piVar5,piVar4[2] * *(int *)(iVar8 + 0x14),piVar4[2] * (int)local_14,

                             &local_14,0x800);

          if (iVar8 < 0) {

            pfVar7 = (float *)0x0;

          }

          else {

            piVar4[4] = piVar4[4] + 1;

            pfVar7 = local_14;

          }

        }

      }

    }

    else {

      pfVar7 = (float *)FUN_00464b30();

    }

    if (pfVar7 != (float *)0x0) {

      cVar6 = FUN_0046cc90();

      if (cVar6 == '\0') {

        if (-1 < (int)local_24 + -1) {

          do {

            *pfVar7 = *pfVar13;

            pfVar7[1] = pfVar13[1];

            local_24 = (float *)((int)local_24 + -1);

            pfVar7[2] = pfVar13[2];

            pfVar13 = (float *)((int)pfVar13 + local_18);

            pfVar7 = pfVar7 + 3;

          } while (local_24 != (float *)0x0);

        }

      }

      else {

        iVar9 = FUN_007468e0(2,0);

        iVar8 = *(int *)(*(int *)((int)param_1 + 200) + 0xc);

        iVar12 = (uint)*(ushort *)(iVar9 + 2) + (int)pfVar13;

        iVar9 = *(int *)((int)param_1 + 0xb0);

        if (-1 < (int)local_24 + -1) {

          param_1 = local_24;

          do {

            local_c = *pfVar13;

            local_8 = pfVar13[1];

            local_4 = pfVar13[2];

            iVar11 = 0;

            if (0 < iVar9) {

              pfVar10 = pfVar13 + 5;

              do {

                fVar2 = *(float *)(iVar8 + (uint)*(byte *)(iVar11 + iVar12) * 4);

                pfVar13 = pfVar10 + -2;

                pfVar1 = pfVar10 + -1;

                fVar3 = *pfVar10;

                iVar11 = iVar11 + 1;

                pfVar10 = pfVar10 + 3;

                local_c = *pfVar13 * fVar2 + local_c;

                local_8 = local_8 + *pfVar1 * fVar2;

                local_4 = local_4 + fVar3 * fVar2;

                pfVar13 = local_10;

              } while (iVar11 < iVar9);

            }

            *pfVar7 = local_c;

            pfVar7[1] = local_8;

            pfVar7[2] = local_4;

            pfVar13 = (float *)((int)pfVar13 + local_18);

            iVar12 = iVar12 + local_18;

            pfVar7 = pfVar7 + 3;

            param_1 = (float *)((int)param_1 + -1);

            local_10 = pfVar13;

          } while (param_1 != (float *)0x0);

        }

      }

    }

    FUN_00414a50();

    FUN_00414a50();

    return;

  }

  FUN_00414a50();

  return;

}
