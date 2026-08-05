// =============================================================================
// FUN_00716bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00716bc0
// Address:   0x00716bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00716bc0 @ 0x00716bc0
// Stable ID: aa_00716bc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×5, while×3, goto×1, return×1.
//  - Notable callees: FUN_00714590, FUN_00716bc0.
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



int FUN_00716bc0(int param_1,int *param_2,int *param_3)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  float *pfVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  int *local_8;

  int local_4;

  

  iVar5 = 0;

  iVar6 = 0;

  iVar3 = 0x49;

  local_8 = (int *)0xbf800000;

  piVar7 = param_2;

  while (FUN_00714590(param_1,iVar3 + 1,&local_4,&param_2),

        (float)local_8 * _DAT_00a13308 <= (float)param_2) {

    fVar2 = (float)local_8 * _DAT_00a13304;

    *piVar7 = local_4;

    if (fVar2 <= (float)param_2) {

      iVar5 = iVar6;

    }

    pfVar4 = &DAT_00a10e7c + local_4;

    local_8 = param_2;

    iVar6 = iVar6 + 1;

    piVar7 = piVar7 + 1;

    if ((&DAT_00a10e7c)[local_4] * _DAT_00a13300 < DAT_00a10e7c) break;

    fVar2 = *pfVar4;

    iVar3 = local_4;

    while ((&DAT_00a10e7c)[local_4] * _DAT_00a13300 < fVar2) {

      pfVar1 = pfVar4 + -1;

      pfVar4 = pfVar4 + -1;

      iVar3 = iVar3 + -1;

      fVar2 = *pfVar1;

    }

    if (iVar3 < 0) break;

    pfVar4 = (float *)(param_1 + iVar3 * 4);

    while (*pfVar4 < pfVar4[1]) {

      iVar3 = iVar3 + -1;

      pfVar4 = pfVar4 + -1;

      if (iVar3 < 0) goto LAB_00716ca5;

    }

    if ((iVar3 < 0) || (4 < iVar6)) break;

  }

LAB_00716ca5:

  *param_3 = iVar5;

  return iVar6;

}
