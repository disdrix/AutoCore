// =============================================================================
// FUN_00712480
// -----------------------------------------------------------------------------
// Stable ID: aa_00712480
// Address:   0x00712480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712480 @ 0x00712480
// Stable ID: aa_00712480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×2, return×1.
//  - Notable callees: ROUND×4, FUN_00712480, FUN_00714480.
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



void FUN_00712480(float param_1,float param_2,float param_3,uint16_t *param_4,uint32_t /* width from decompiler */ param_5,

                 float *param_6,float *param_7,int param_8)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  uint uVar4;

  float *pfVar5;

  int iVar6;

  float *pfVar7;

  float local_814 [216];

  float local_4b4 [41];

  float local_410 [216];

  float local_b0 [41];

  int local_c;

  int local_8;

  

  iVar6 = (int)param_3 >> 1;

  param_3 = param_1;

  local_8 = iVar6;

  (*(code *)PTR_memset_00af8a50)(local_410,0,0x404);

  (*(code *)PTR_memset_00af8a50)(local_814,0,0x404);

  local_c = 0;

  if (0 < (int)param_2) {

    param_8 = param_8 - (int)param_7;

    do {

      iVar6 = (int)ROUND(param_3);

      fVar1 = *(float *)(param_8 + (int)param_7) * DAT_00a0f298;

      uVar4 = (int)ROUND(_DAT_00a12d68 * *param_7) & 0xff;

      param_7 = param_7 + 1;

      param_2 = (float)((int)param_2 + -1);

      local_c = iVar6;

      local_410[iVar6] = fVar1 * *(float *)(PTR_DAT_00af8b14 + uVar4 * 4);

      local_814[iVar6] = fVar1 * *(float *)(PTR_DAT_00af8b10 + uVar4 * 4);

      param_3 = param_3 + param_1;

      iVar6 = local_8;

    } while (param_2 != 0.0);

  }

  FUN_00714480(local_410,local_814,0x200);

  if (iVar6 < 1) {

    param_2 = 0.0;

  }

  else {

    param_2 = g_flOne / (float)local_8;

  }

  param_1 = 0.0;

  param_3 = 1.0;

  pfVar5 = local_b0;

  iVar6 = 0x28;

  pfVar3 = param_6;

  pfVar7 = local_4b4;

  do {

    fVar1 = *pfVar5;

    pfVar5 = pfVar5 + 1;

    fVar2 = param_1 + param_2;

    param_8._0_2_ = (uint16_t)(int)ROUND(param_3 * *pfVar3 + param_1 * fVar1);

    *param_4 = (uint16_t)param_8;

    param_1 = fVar2 + param_2;

    param_8._0_2_ = (uint16_t)(int)ROUND((param_3 - param_2) * pfVar3[1] + fVar2 * *pfVar7);

    param_4[1] = (uint16_t)param_8;

    param_4 = param_4 + 2;

    iVar6 = iVar6 + -1;

    param_3 = (param_3 - param_2) - param_2;

    pfVar3 = pfVar3 + 2;

    pfVar7 = pfVar7 + 1;

  } while (iVar6 != 0);

  pfVar5 = local_410;

  pfVar3 = local_814;

  iVar6 = 0x28;

  do {

    fVar1 = *pfVar5;

    pfVar5 = pfVar5 + 1;

    *param_6 = fVar1;

    fVar1 = *pfVar3;

    pfVar3 = pfVar3 + 1;

    param_6[1] = fVar1;

    param_6 = param_6 + 2;

    iVar6 = iVar6 + -1;

  } while (iVar6 != 0);

  return;

}
