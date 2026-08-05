// =============================================================================
// FUN_0070fa10
// -----------------------------------------------------------------------------
// Stable ID: aa_0070fa10
// Address:   0x0070fa10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070fa10 @ 0x0070fa10
// Stable ID: aa_0070fa10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×13, do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_0070fa10.
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



void FUN_0070fa10(float *param_1,int param_2,float param_3)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  

  if (*param_1 < param_3) {

    *param_1 = param_3;

  }

  if ((float)_DAT_00a0f190 - param_3 < param_1[param_2 + -1]) {

    param_1[param_2 + -1] = (float)_DAT_00a0f190 - param_3;

  }

  iVar2 = 1;

  if (3 < param_2 + -2) {

    iVar3 = (param_2 - 6U >> 2) + 1;

    pfVar1 = param_1 + 2;

    iVar2 = iVar3 * 4 + 1;

    do {

      if (pfVar1[-1] < pfVar1[-2] + param_3) {

        pfVar1[-1] = pfVar1[-2] + param_3;

      }

      if (*pfVar1 - param_3 < pfVar1[-1]) {

        pfVar1[-1] = ((pfVar1[-1] + *pfVar1) - param_3) * (float)_DAT_00aaa5e0;

      }

      if (*pfVar1 < pfVar1[-1] + param_3) {

        *pfVar1 = pfVar1[-1] + param_3;

      }

      if (pfVar1[1] - param_3 < *pfVar1) {

        *pfVar1 = ((pfVar1[1] + *pfVar1) - param_3) * (float)_DAT_00aaa5e0;

      }

      if (pfVar1[1] < *pfVar1 + param_3) {

        pfVar1[1] = *pfVar1 + param_3;

      }

      if (pfVar1[2] - param_3 < pfVar1[1]) {

        pfVar1[1] = ((pfVar1[2] + pfVar1[1]) - param_3) * (float)_DAT_00aaa5e0;

      }

      if (pfVar1[2] < pfVar1[1] + param_3) {

        pfVar1[2] = pfVar1[1] + param_3;

      }

      if (pfVar1[3] - param_3 < pfVar1[2]) {

        pfVar1[2] = ((pfVar1[3] + pfVar1[2]) - param_3) * (float)_DAT_00aaa5e0;

      }

      pfVar1 = pfVar1 + 4;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

  }

  for (; iVar2 < param_2 + -1; iVar2 = iVar2 + 1) {

    if (param_1[iVar2] < param_1[iVar2 + -1] + param_3) {

      param_1[iVar2] = param_1[iVar2 + -1] + param_3;

    }

    if (param_1[iVar2 + 1] - param_3 < param_1[iVar2]) {

      param_1[iVar2] = ((param_1[iVar2] + param_1[iVar2 + 1]) - param_3) * (float)_DAT_00aaa5e0;

    }

  }

  return;

}
