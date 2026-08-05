// =============================================================================
// FUN_007141b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007141b0
// Address:   0x007141b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007141b0 @ 0x007141b0
// Stable ID: aa_007141b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×2.
//  - Notable callees: FUN_007141b0, FUN_00714450, ROUND.
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

/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_007141b0(float *param_1,int param_2,float *param_3,int param_4)



{

  float *pfVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  float *pfVar5;

  float *pfVar6;

  int iVar7;

  int iVar8;

  float afStackY_40210 [65524];

  int local_8;

  

  local_8 = param_2 + 1;

  pfVar1 = (float *)&stack0xfffffef4;

  iVar3 = local_8 >> 1;

  pfVar2 = (float *)&stack0xfffffdf0;

  pfVar5 = param_1;

  pfVar6 = pfVar2;

  iVar7 = 0;

  param_2 = iVar3;

  if (0 < iVar3) {

    do {

      pfVar6 = pfVar2 + 1;

      *pfVar1 = *pfVar5;

      *pfVar2 = pfVar5[1];

      pfVar1 = pfVar1 + 1;

      param_2 = param_2 + -1;

      pfVar5 = pfVar5 + 2;

      pfVar2 = pfVar6;

      iVar7 = iVar3;

    } while (param_2 != 0);

  }

  pfVar2 = pfVar1;

  if (iVar3 * 2 != local_8) {

    *pfVar6 = 0.0;

    pfVar2 = pfVar1 + 1;

    pfVar6 = pfVar6 + 1;

    iVar3 = iVar7 * 2;

    iVar7 = iVar7 + 1;

    *pfVar1 = param_1[iVar3];

  }

  iVar7 = iVar7 * -4 + 0x104;

  (*(code *)PTR_memset_00af8a50)(pfVar2,0,iVar7);

  (*(code *)PTR_memset_00af8a50)(pfVar6,0,iVar7);

  FUN_00714450(&stack0xfffffef4,&stack0xfffffdf0,0x80);

  iVar7 = (int)ROUND((DAT_00a11088 / (float)param_4) * _DAT_00a0f6b0);

  param_4 = param_4 + -1;

  iVar3 = 0;

  if (0 < param_4) {

    iVar4 = 0x4000;

    pfVar1 = param_3;

    iVar8 = param_4;

    do {

      iVar8 = iVar8 + -1;

      *pfVar1 = *(float *)((int)&stack0xfffffef4 + (iVar4 >> 0xf) * 4) *

                *(float *)((int)&stack0xfffffef4 + (iVar4 >> 0xf) * 4) +

                *(float *)((int)&stack0xfffffdf0 + (iVar4 >> 0xf) * 4) *

                *(float *)((int)&stack0xfffffdf0 + (iVar4 >> 0xf) * 4);

      iVar4 = iVar4 + iVar7;

      pfVar1 = pfVar1 + 1;

      iVar3 = param_4;

    } while (iVar8 != 0);

  }

  iVar7 = iVar7 * iVar3 + 0x4000 >> 0xf;

  if (iVar7 < 0x40) {

    param_3[iVar3] =

         *(float *)((int)&stack0xfffffef4 + iVar7 * 4) *

         *(float *)((int)&stack0xfffffef4 + iVar7 * 4) +

         *(float *)((int)&stack0xfffffdf0 + iVar7 * 4) *

         *(float *)((int)&stack0xfffffdf0 + iVar7 * 4);

    return;

  }

  param_3[iVar3] = param_3[iVar3 + -1];

  return;

}
