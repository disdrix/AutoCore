// =============================================================================
// FUN_0070e810
// -----------------------------------------------------------------------------
// Stable ID: aa_0070e810
// Address:   0x0070e810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070e810 @ 0x0070e810
// Stable ID: aa_0070e810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×3, do×3, while×3, return×1.
//  - Notable callees: FUN_0070e810.
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

void FUN_0070e810(int param_1,float *param_2,float *param_3,int param_4,int param_5,float *param_6)



{

  float fVar1;

  float *pfVar2;

  float *pfVar3;

  float *pfVar4;

  int iVar5;

  int iVar6;

  int local_8;

  

  if (0 < param_4) {

    param_1 = param_1 - (int)param_3;

    local_8 = param_4;

    do {

      fVar1 = *(float *)(param_1 + (int)param_3);

      iVar6 = 0;

      *param_3 = fVar1 * *param_2 + *param_6;

      if (3 < param_5 + -1) {

        iVar5 = (param_5 - 5U >> 2) + 1;

        iVar6 = iVar5 * 4;

        pfVar2 = param_6 + 1;

        pfVar3 = param_2 + 2;

        do {

          pfVar4 = pfVar3 + 4;

          iVar5 = iVar5 + -1;

          pfVar2[-1] = fVar1 * pfVar3[-1] + *pfVar2;

          *pfVar2 = fVar1 * *pfVar3 +

                    *(float *)((int)param_6 + (-0x10 - (int)param_2) + (int)pfVar4);

          *(float *)((int)param_6 + (-0x10 - (int)param_2) + (int)pfVar4) =

               fVar1 * pfVar3[1] + pfVar2[2];

          pfVar2[2] = fVar1 * pfVar3[2] + pfVar2[3];

          pfVar2 = pfVar2 + 4;

          pfVar3 = pfVar4;

        } while (iVar5 != 0);

      }

      if (iVar6 < param_5 + -1) {

        iVar5 = (param_5 + -1) - iVar6;

        pfVar2 = param_6 + iVar6 + 1;

        do {

          iVar5 = iVar5 + -1;

          pfVar2[-1] = fVar1 * *(float *)((int)param_2 + (-4 - (int)param_6) + (int)(pfVar2 + 1)) +

                       *pfVar2;

          pfVar2 = pfVar2 + 1;

        } while (iVar5 != 0);

      }

      param_3 = param_3 + 1;

      param_6[param_5 + -1] = fVar1 * param_2[param_5];

      local_8 = local_8 + -1;

    } while (local_8 != 0);

  }

  return;

}
