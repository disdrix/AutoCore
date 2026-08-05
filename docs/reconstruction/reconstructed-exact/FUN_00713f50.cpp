// =============================================================================
// FUN_00713f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00713f50
// Address:   0x00713f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713f50 @ 0x00713f50
// Stable ID: aa_00713f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00713f50, FUN_007140c0, FUN_007141b0, FUN_00715200, FUN_00715340, FUN_007157b0, ceil, ftol.
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



void FUN_00713f50(int param_1,int param_2,int *param_3,int *param_4,float param_5)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  float local_1c0;

  int *local_1bc;

  uint8_t local_1b4 [28];

  float local_198 [8];

  uint8_t local_178 [28];

  float local_15c [87];

  

  FUN_00715340(param_1,0,0x57,0x2b,param_3,param_4);

  ceil((double)((float)param_2 * _DAT_00a1107c));

  iVar2 = ftol();

  if (7 < iVar2) {

    iVar2 = 7;

  }

  FUN_007140c0(param_1,param_2,local_198,iVar2);

  local_198[0] = local_198[0] * DAT_00a11078;

  FUN_00715200(local_198,iVar2,local_1b4,local_178,&local_1c0);

  FUN_007157b0(local_1b4,local_1b4,iVar2,0x3f7ae148);

  FUN_007141b0(local_1b4,iVar2,local_15c,param_2);

  local_1c0 = local_1c0 * DAT_00a0f70c;

  iVar2 = 0;

  iVar4 = 0;

  param_5 = param_5 * _DAT_00a11074;

  if (0 < *param_4) {

    local_1bc = param_3;

    piVar3 = param_3;

    do {

      iVar1 = *piVar3;

      if (((iVar1 < param_2) && (local_1c0 <= local_15c[iVar1] * *(float *)(param_1 + iVar1 * 4)))

         && (param_5 < *(float *)(param_1 + iVar1 * 4))) {

        iVar2 = iVar2 + 1;

        *local_1bc = iVar1;

        local_1bc = local_1bc + 1;

      }

      iVar4 = iVar4 + 1;

      piVar3 = piVar3 + 1;

    } while (iVar4 < *param_4);

  }

  param_3[iVar2] = 0x7fff;

  param_3[iVar2 + 1] = 0x7fff;

  param_3[iVar2 + 2] = 0x7fff;

  param_3[iVar2 + 3] = 0x7fff;

  *param_4 = iVar2;

  return;

}
