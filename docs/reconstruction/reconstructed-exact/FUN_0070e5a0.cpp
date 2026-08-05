// =============================================================================
// FUN_0070e5a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0070e5a0
// Address:   0x0070e5a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070e5a0 @ 0x0070e5a0
// Stable ID: aa_0070e5a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×3, do×3, while×3, return×1.
//  - Notable callees: FUN_0070e5a0.
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

void FUN_0070e5a0(int param_1,float *param_2,int param_3,float *param_4,int param_5,int param_6,

                 float *param_7)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  float *pfVar4;

  float *pfVar5;

  int iVar6;

  float *pfVar7;

  int iVar8;

  int local_14;

  

  if (0 < param_5) {

    param_1 = param_1 - (int)param_4;

    local_14 = param_5;

    do {

      fVar1 = *(float *)(param_1 + (int)param_4);

      fVar2 = fVar1 * *param_2 + *param_7;

      *param_4 = fVar2;

      iVar6 = 0;

      if (3 < param_6 + -1) {

        iVar8 = (param_6 - 5U >> 2) + 1;

        iVar6 = iVar8 * 4;

        pfVar4 = (float *)(param_3 + 4);

        pfVar5 = param_2 + 3;

        pfVar7 = param_7 + 2;

        do {

          pfVar3 = pfVar4 + 4;

          iVar8 = iVar8 + -1;

          pfVar7[-2] = (fVar1 * *(float *)((int)pfVar4 + ((int)param_2 - param_3)) +

                       *(float *)((int)param_7 + (-0x10 - param_3) + (int)pfVar3)) - fVar2 * *pfVar4

          ;

          *(float *)((int)param_7 + (-0x10 - param_3) + (int)pfVar3) =

               (fVar1 * pfVar5[-1] + *pfVar7) - fVar2 * pfVar4[1];

          *pfVar7 = (fVar1 * *pfVar5 + *(float *)((int)pfVar5 + ((int)param_7 - (int)param_2))) -

                    fVar2 * pfVar4[2];

          *(float *)((int)pfVar5 + ((int)param_7 - (int)param_2)) =

               (fVar1 * pfVar5[1] + pfVar7[2]) - fVar2 * pfVar4[3];

          pfVar4 = pfVar3;

          pfVar5 = pfVar5 + 4;

          pfVar7 = pfVar7 + 4;

        } while (iVar8 != 0);

      }

      if (iVar6 < param_6 + -1) {

        iVar8 = (param_6 + -1) - iVar6;

        pfVar4 = param_7 + iVar6 + 1;

        do {

          iVar8 = iVar8 + -1;

          pfVar4[-1] = (fVar1 * *(float *)(((int)param_2 - (int)param_7) + (int)pfVar4) + *pfVar4) -

                       fVar2 * *(float *)((param_3 - (int)param_7) + -4 + (int)(pfVar4 + 1));

          pfVar4 = pfVar4 + 1;

        } while (iVar8 != 0);

      }

      param_4 = param_4 + 1;

      param_7[param_6 + -1] = fVar1 * param_2[param_6] - fVar2 * *(float *)(param_3 + param_6 * 4);

      local_14 = local_14 + -1;

    } while (local_14 != 0);

  }

  return;

}
