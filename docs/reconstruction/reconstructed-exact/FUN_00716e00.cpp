// =============================================================================
// FUN_00716e00
// -----------------------------------------------------------------------------
// Stable ID: aa_00716e00
// Address:   0x00716e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00716e00 @ 0x00716e00
// Stable ID: aa_00716e00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, do×2, while×2, goto×1.
//  - Notable callees: FUN_00716e00.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00716e00(int param_1,int param_2,int *param_3,int *param_4,int *param_5)



{

  float fVar1;

  int iVar2;

  bool bVar3;

  float fVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  

  iVar2 = *param_4;

  bVar3 = false;

  iVar6 = 0;

  iVar8 = *param_5;

  piVar5 = param_3;

  if (0 < iVar2) {

    do {

      if (param_2 == *piVar5) {

        bVar3 = true;

      }

      if (*piVar5 < param_2) break;

      iVar6 = iVar6 + 1;

      piVar5 = piVar5 + 1;

    } while (iVar6 < iVar2);

  }

  if (bVar3) {

LAB_00716ecd:

    *param_5 = iVar8;

    *param_4 = iVar2;

    return;

  }

  fVar1 = *(float *)(param_1 + param_2 * 4);

  fVar4 = *(float *)(param_1 + param_3[iVar8] * 4) * _DAT_00a13304;

  if ((iVar6 != iVar2) || (fVar1 < *(float *)(param_1 + *param_3 * 4) * _DAT_00a13310)) {

    if (iVar6 <= iVar8) goto LAB_00716ecd;

    if (fVar1 < fVar4) {

      *param_5 = iVar8;

      *param_4 = iVar2;

      return;

    }

  }

  if (iVar6 < iVar2) {

    piVar5 = param_3 + iVar2;

    iVar7 = iVar2 - iVar6;

    do {

      *piVar5 = piVar5[-1];

      piVar5 = piVar5 + -1;

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

  }

  param_3[iVar6] = param_2;

  if (fVar4 <= fVar1) {

    iVar8 = iVar6;

  }

  *param_5 = iVar8;

  *param_4 = iVar2 + 1;

  return;

}
