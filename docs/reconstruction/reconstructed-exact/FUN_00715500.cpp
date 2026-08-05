// =============================================================================
// FUN_00715500
// -----------------------------------------------------------------------------
// Stable ID: aa_00715500
// Address:   0x00715500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00715500 @ 0x00715500
// Stable ID: aa_00715500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, while×2, return×2, do×1, goto×1.
//  - Notable callees: FUN_00715500, ROUND.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_00715500(int param_1,int param_2,float *param_3,int param_4,float param_5,int param_6,

                float *param_7,int param_8)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  float *pfVar6;

  int iVar7;

  int local_14;

  float local_10;

  float local_c;

  

  fVar4 = param_5 * DAT_00a0f298;

  local_10 = fVar4 + param_5;

  local_14 = 0;

  fVar2 = *param_3;

  pfVar6 = param_3;

  for (iVar5 = 0; (fVar2 < fVar4 && (iVar5 < param_4)); iVar5 = iVar5 + 1) {

    fVar2 = pfVar6[1];

    pfVar6 = pfVar6 + 1;

  }

  fVar2 = _DAT_00a111ac - fVar4;

  if (fVar2 <= fVar4) {

    local_14 = 0;

  }

  else {

    param_6 = param_6 - (int)param_7;

    local_c = fVar4;

    while (local_14 < param_8) {

      if ((param_4 <= iVar5) || (local_10 <= param_3[iVar5])) {

LAB_00715602:

        iVar7 = (int)ROUND((local_10 + local_c) * DAT_00a0f298);

        *(float *)(param_6 + (int)param_7) = *(float *)(param_1 + iVar7 * 4) + _DAT_00a110e4;

        *param_7 = (float)iVar7;

      }

      else {

        pfVar6 = (float *)(param_2 + iVar5 * 4);

        iVar7 = iVar5;

        fVar3 = g_flZero;

        do {

          if (param_4 <= iVar7) break;

          if (fVar3 < *pfVar6) {

            fVar3 = *pfVar6;

            iVar5 = iVar7;

          }

          pfVar1 = (float *)((int)param_3 + (4 - param_2) + (int)pfVar6);

          pfVar6 = pfVar6 + 1;

          iVar7 = iVar7 + 1;

        } while (*pfVar1 < local_10);

        if (fVar3 <= g_flZero) goto LAB_00715602;

        *(float *)(param_6 + (int)param_7) = fVar3;

        *param_7 = param_3[iVar5];

      }

      local_c = fVar4 + *param_7;

      local_10 = local_c + param_5;

      if (_DAT_00a111ac < local_10) {

        local_10 = 256.0;

      }

      fVar3 = param_3[iVar5];

      local_14 = local_14 + 1;

      param_7 = param_7 + 1;

      pfVar6 = param_3 + iVar5;

      for (; (fVar3 < local_c && (iVar5 < param_4)); iVar5 = iVar5 + 1) {

        fVar3 = pfVar6[1];

        pfVar6 = pfVar6 + 1;

      }

      if (fVar2 <= local_c) {

        return local_14;

      }

    }

  }

  return local_14;

}
