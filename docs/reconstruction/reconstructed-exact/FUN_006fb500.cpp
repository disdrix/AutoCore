// =============================================================================
// FUN_006fb500
// -----------------------------------------------------------------------------
// Stable ID: aa_006fb500
// Address:   0x006fb500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fb500 @ 0x006fb500
// Stable ID: aa_006fb500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, do×1, while×1.
//  - Notable callees: FUN_006fb500.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __fastcall FUN_006fb500(uint32_t /* width from decompiler */ param_1,int param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  int iVar10;

  float *pfVar11;

  int iVar12;

  int iVar13;

  int local_44;

  

  local_44 = 0;

  pfVar11 = (float *)(param_2 + 8);

  do {

    iVar12 = (int)(char)(&DAT_00a0eefe)[local_44];

    iVar13 = (int)(char)(&DAT_00a0eefc)[local_44];

    if ((g_flZero <= param_4[iVar12]) && (g_flZero <= param_4[iVar13])) {

      iVar10 = iVar12 * 0x10 + param_2;

      fVar1 = *(float *)(iVar12 * 0x10 + param_2) - pfVar11[-2];

      fVar4 = *(float *)(iVar10 + 4) - pfVar11[-1];

      fVar5 = *(float *)(iVar10 + 8) - *pfVar11;

      iVar10 = iVar13 * 0x10 + param_2;

      fVar3 = *(float *)(iVar13 * 0x10 + param_2) - pfVar11[-2];

      fVar6 = *(float *)(iVar10 + 4) - pfVar11[-1];

      fVar7 = *(float *)(iVar10 + 8) - *pfVar11;

      fVar8 = *(float *)(param_2 + 0x30) - pfVar11[-2];

      fVar9 = *(float *)(param_2 + 0x34) - pfVar11[-1];

      fVar2 = *(float *)(param_2 + 0x38) - *pfVar11;

      if ((fVar8 * fVar1 + fVar9 * fVar4 + fVar2 * fVar5) *

          ((*param_3 - pfVar11[-2]) * fVar3 +

          (param_3[1] - pfVar11[-1]) * fVar6 + (param_3[2] - *pfVar11) * fVar7) <=

          ((*param_3 - pfVar11[-2]) * fVar1 +

          (param_3[1] - pfVar11[-1]) * fVar4 + (param_3[2] - *pfVar11) * fVar5) *

          (fVar8 * fVar3 + fVar9 * fVar6 + fVar2 * fVar7)) {

        param_4[iVar12] = -1.0;

      }

      else {

        param_4[iVar13] = -1.0;

      }

    }

    local_44 = local_44 + 1;

    pfVar11 = pfVar11 + 4;

  } while (local_44 < 3);

  if (g_flZero < *param_4) {

    return 0;

  }

  if (g_flZero < param_4[1]) {

    return 1;

  }

  if (param_4[2] <= g_flZero) {

    return 0xffffffff;

  }

  return 2;

}
