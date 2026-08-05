// =============================================================================
// FUN_00716cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00716cc0
// Address:   0x00716cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00716cc0 @ 0x00716cc0
// Stable ID: aa_00716cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×5, while×2, return×2.
//  - Notable callees: FUN_00714590, FUN_00716cc0.
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

void FUN_00716cc0(float param_1,int *param_2,int *param_3,int *param_4)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  bool bVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float local_4;

  

  iVar8 = *param_3;

  iVar7 = param_2[iVar8 + -1];

  iVar6 = *param_4;

  local_4 = (float)(&DAT_00a10e7c)[iVar7];

  if (local_4 <= DAT_00a0f694) {

    bVar4 = false;

    fVar3 = *(float *)((int)param_1 + iVar7 * 4) * DAT_00a0f70c;

    iVar7 = iVar7 + 1;

    pfVar5 = (float *)(&DAT_00a10e7c + iVar7);

    fVar2 = *pfVar5;

    while (fVar2 < local_4 + local_4) {

      pfVar1 = pfVar5 + 1;

      pfVar5 = pfVar5 + 1;

      iVar7 = iVar7 + 1;

      fVar2 = *pfVar1;

    }

    if ((*(float *)((int)param_1 + -4 + iVar7 * 4) < fVar3) &&

       (*(float *)((int)param_1 + iVar7 * 4) < fVar3)) {

      bVar4 = true;

    }

    iVar7 = iVar7 + 1;

    pfVar5 = (float *)(&DAT_00a10e7c + iVar7);

    fVar2 = *pfVar5;

    while (fVar2 < local_4 * g_flVehicleHpTechCoeff) {

      pfVar1 = pfVar5 + 1;

      pfVar5 = pfVar5 + 1;

      iVar7 = iVar7 + 1;

      fVar2 = *pfVar1;

    }

    pfVar5 = (float *)((int)param_1 + iVar7 * 4);

    if (((*(float *)((int)param_1 + -4 + iVar7 * 4) < fVar3) && (*pfVar5 < fVar3)) || (bVar4)) {

      if (iVar8 == 1) {

        param_1 = local_4 * g_flVehicleHpTechCoeff;

        FUN_00714590(pfVar5,0x4a - iVar7,&param_1,&local_4);

        *param_2 = (int)param_1 + iVar7;

        *param_4 = iVar6;

        *param_3 = 1;

        return;

      }

      iVar8 = iVar8 + -1;

      if (iVar6 == iVar8) {

        iVar6 = 0;

      }

    }

  }

  *param_4 = iVar6;

  *param_3 = iVar8;

  return;

}
