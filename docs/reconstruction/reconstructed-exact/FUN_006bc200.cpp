// =============================================================================
// FUN_006bc200
// -----------------------------------------------------------------------------
// Stable ID: aa_006bc200
// Address:   0x006bc200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bc200 @ 0x006bc200
// Stable ID: aa_006bc200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×10, goto×5, while×2, return×1, do×1.
//  - Notable callees: FUN_005b3300, FUN_006bc200.
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

void FUN_006bc200(float param_1,uint *param_2,uint *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  uint uVar4;

  float *pfVar5;

  float *pfVar6;

  int iVar7;

  float *pfVar8;

  uint uVar9;

  int iVar10;

  float *local_44;

  float *local_40;

  

  pfVar6 = (float *)*param_2;

  iVar7 = param_2[1] - 1;

  local_40 = pfVar6;

  if (iVar7 < 0) {

LAB_006bc355:

    uVar9 = (int)((int)local_40 - *param_2) >> 4;

    *param_3 = uVar9;

    if ((int)(param_2[2] & 0x7fffffff) < (int)uVar9) {

      uVar4 = (param_2[2] & 0x7fffffff) * 2;

      if ((int)uVar4 <= (int)uVar9) {

        uVar4 = uVar9;

      }

      FUN_005b3300(param_2,uVar4,0x10);

    }

    param_2[1] = uVar9;

    return;

  }

  local_44 = pfVar6 + -4;

LAB_006bc230:

  if ((float *)*param_2 <= local_44) {

    pfVar5 = local_44;

    do {

      if (*pfVar5 < *pfVar6 - DAT_00a0f718) break;

      if ((pfVar5[2] - pfVar6[2]) * (pfVar5[2] - pfVar6[2]) +

          (pfVar5[1] - pfVar6[1]) * (pfVar5[1] - pfVar6[1]) +

          (*pfVar5 - *pfVar6) * (*pfVar5 - *pfVar6) < param_1) {

        iVar10 = iVar7 + -1;

        if (iVar10 < 0) goto LAB_006bc347;

        pfVar8 = pfVar6 + 6;

        goto LAB_006bc2e0;

      }

      pfVar5 = pfVar5 + -4;

    } while ((float *)*param_2 <= pfVar5);

  }

  fVar1 = pfVar6[1];

  fVar2 = pfVar6[2];

  fVar3 = pfVar6[3];

  local_44 = local_44 + 4;

  *local_40 = *pfVar6;

  local_40[1] = fVar1;

  local_40[2] = fVar2;

  local_40[3] = fVar3;

  local_40 = local_40 + 4;

  goto LAB_006bc347;

  while( true ) {

    pfVar6 = pfVar6 + 4;

    pfVar8 = pfVar8 + 4;

    iVar7 = iVar7 + -1;

    iVar10 = iVar10 + -1;

    if (iVar10 < 0) break;

LAB_006bc2e0:

    if (param_1 <=

        (pfVar5[2] - *pfVar8) * (pfVar5[2] - *pfVar8) +

        (pfVar5[1] - pfVar8[-1]) * (pfVar5[1] - pfVar8[-1]) +

        (*pfVar5 - pfVar8[-2]) * (*pfVar5 - pfVar8[-2])) break;

  }

LAB_006bc347:

  pfVar6 = pfVar6 + 4;

  iVar7 = iVar7 + -1;

  if (iVar7 < 0) goto LAB_006bc355;

  goto LAB_006bc230;

}
