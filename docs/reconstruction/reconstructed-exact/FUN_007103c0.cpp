// =============================================================================
// FUN_007103c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007103c0
// Address:   0x007103c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007103c0 @ 0x007103c0
// Stable ID: aa_007103c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×12, do×4, while×4, goto×4, for×1, return×1.
//  - Notable callees: FUN_007103c0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_007103c0(int param_1,float *param_2,int param_3,int param_4,int param_5,int param_6,

                 int param_7,int param_8)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  uint32_t /* width from decompiler */ *puVar7;

  bool bVar8;

  int local_10;

  int local_c;

  

  local_10 = 0;

  local_c = 0;

  if (0 < param_4) {

    do {

      iVar4 = 0;

      fVar2 = g_flZero;

      if (3 < param_3) {

        iVar5 = (param_3 - 4U >> 2) + 1;

        iVar4 = iVar5 * 4;

        pfVar3 = (float *)(param_1 + 8);

        pfVar6 = param_2;

        do {

          param_2 = pfVar6 + 4;

          iVar5 = iVar5 + -1;

          fVar2 = pfVar3[1] * pfVar6[3] +

                  pfVar6[2] * *pfVar3 + pfVar3[-1] * pfVar6[1] + pfVar3[-2] * *pfVar6 + fVar2;

          pfVar3 = pfVar3 + 4;

          pfVar6 = param_2;

        } while (iVar5 != 0);

      }

      for (; iVar4 < param_3; iVar4 = iVar4 + 1) {

        iVar5 = iVar4 * 4;

        fVar1 = *param_2;

        param_2 = param_2 + 1;

        fVar2 = *(float *)(param_1 + iVar5) * fVar1 + fVar2;

      }

      bVar8 = fVar2 <= g_flZero;

      if (!bVar8) {

        fVar2 = -fVar2;

      }

      fVar2 = *(float *)(param_5 + local_c * 4) * (float)_DAT_00aaa5e0 + fVar2;

      if ((local_c < param_6) || (fVar2 < *(float *)(param_8 + -4 + param_6 * 4))) {

        iVar4 = param_6 + -1;

        if (3 < iVar4) {

          iVar5 = param_6 + -3;

          puVar7 = (uint32_t /* width from decompiler */ *)(param_7 + iVar5 * 4);

          pfVar3 = (float *)(param_8 + -4 + iVar4 * 4);

          do {

            if ((iVar4 <= local_10) && (*pfVar3 <= fVar2)) goto LAB_007105ba;

            pfVar3[1] = *pfVar3;

            puVar7[2] = *(uint32_t /* width from decompiler */ *)((int)pfVar3 + (param_7 - param_8));

            if ((iVar5 + 1 <= local_10) && (pfVar3[-1] <= fVar2)) {

              iVar4 = iVar4 + -1;

              goto LAB_007105ba;

            }

            *pfVar3 = pfVar3[-1];

            *(uint32_t /* width from decompiler */ *)((int)pfVar3 + (param_7 - param_8)) = *puVar7;

            if ((iVar5 <= local_10) && (pfVar3[-2] <= fVar2)) {

              iVar4 = iVar4 + -2;

              goto LAB_007105ba;

            }

            pfVar3[-1] = pfVar3[-2];

            *puVar7 = puVar7[-1];

            if ((iVar5 + -1 <= local_10) && (pfVar3[-3] <= fVar2)) {

              iVar4 = iVar4 + -3;

              goto LAB_007105ba;

            }

            pfVar3[-2] = pfVar3[-3];

            puVar7[-1] = puVar7[-2];

            iVar4 = iVar4 + -4;

            pfVar3 = pfVar3 + -4;

            puVar7 = puVar7 + -4;

            iVar5 = iVar5 + -4;

          } while (3 < iVar4);

        }

        if (0 < iVar4) {

          pfVar3 = (float *)(param_8 + -4 + iVar4 * 4);

          do {

            if ((iVar4 <= local_10) && (*pfVar3 <= fVar2)) break;

            pfVar3[1] = *pfVar3;

            *(uint32_t /* width from decompiler */ *)(param_7 + iVar4 * 4) =

                 *(uint32_t /* width from decompiler */ *)((int)pfVar3 + (param_7 - param_8));

            iVar4 = iVar4 + -1;

            pfVar3 = pfVar3 + -1;

          } while (0 < iVar4);

        }

LAB_007105ba:

        *(float *)(param_8 + iVar4 * 4) = fVar2;

        local_10 = local_10 + 1;

        *(int *)(param_7 + iVar4 * 4) = local_c;

        if (bVar8) {

          *(int *)(param_7 + iVar4 * 4) = local_c + param_4;

        }

      }

      local_c = local_c + 1;

    } while (local_c < param_4);

  }

  return;

}
