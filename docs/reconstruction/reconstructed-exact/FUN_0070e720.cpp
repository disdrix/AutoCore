// =============================================================================
// FUN_0070e720
// -----------------------------------------------------------------------------
// Stable ID: aa_0070e720
// Address:   0x0070e720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070e720 @ 0x0070e720
// Stable ID: aa_0070e720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×3, do×3, while×3, return×1.
//  - Notable callees: FUN_0070e720.
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

void FUN_0070e720(int param_1,int param_2,float *param_3,int param_4,int param_5,float *param_6)



{

  float fVar1;

  float *pfVar2;

  float *pfVar3;

  int iVar4;

  int iVar5;

  

  if (0 < param_4) {

    param_1 = param_1 - (int)param_3;

    do {

      iVar4 = 0;

      *param_3 = *(float *)(param_1 + (int)param_3) + *param_6;

      if (3 < param_5 + -1) {

        iVar5 = (param_5 - 5U >> 2) + 1;

        iVar4 = iVar5 * 4;

        pfVar2 = param_6 + 1;

        pfVar3 = (float *)(param_2 + 8);

        do {

          iVar5 = iVar5 + -1;

          pfVar2[-1] = *pfVar2 - pfVar3[-1] * *param_3;

          *pfVar2 = *(float *)((int)pfVar3 + ((int)param_6 - param_2)) - *pfVar3 * *param_3;

          *(float *)((int)pfVar3 + ((int)param_6 - param_2)) = pfVar2[2] - pfVar3[1] * *param_3;

          pfVar2[2] = pfVar2[3] - pfVar3[2] * *param_3;

          pfVar2 = pfVar2 + 4;

          pfVar3 = pfVar3 + 4;

        } while (iVar5 != 0);

      }

      if (iVar4 < param_5 + -1) {

        pfVar2 = (float *)(param_2 + 4 + iVar4 * 4);

        do {

          iVar5 = iVar4 + 1;

          param_6[iVar4] = *(float *)((int)pfVar2 + ((int)param_6 - param_2)) - *pfVar2 * *param_3;

          pfVar2 = pfVar2 + 1;

          iVar4 = iVar5;

        } while (iVar5 < param_5 + -1);

      }

      fVar1 = *param_3;

      param_3 = param_3 + 1;

      param_4 = param_4 + -1;

      param_6[param_5 + -1] = -(fVar1 * *(float *)(param_2 + param_5 * 4));

    } while (param_4 != 0);

  }

  return;

}
