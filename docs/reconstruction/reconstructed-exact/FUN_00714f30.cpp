// =============================================================================
// FUN_00714f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00714f30
// Address:   0x00714f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00714f30 @ 0x00714f30
// Stable ID: aa_00714f30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_007144b0×3, ROUND×3, FUN_00714f30, FUN_00715980, SQRT.
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



float10 FUN_00714f30(int param_1,int param_2,float param_3,float *param_4,float param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = (int)ROUND(param_3 * param_5);

  if (4 < local_8) {

    local_8 = 4;

  }

  iVar1 = (int)ROUND(param_3 - (float)local_8);

  param_3 = (float)(int)ROUND((float)local_8 + param_3);

  if (iVar1 < 8) {

    iVar1 = 8;

  }

  if (0xa0 < (int)param_3) {

    param_3 = 2.24208e-43;

  }

  iVar3 = 0;

  param_5 = -3.4028235e+38;

  local_8 = param_1 + iVar1 * 4;

  local_c = 0;

  local_10 = 0.0;

  local_14 = 0.0;

  local_18 = 0.0;

  iVar2 = param_2 - iVar1;

  do {

    fVar4 = (float10)FUN_007144b0(param_1,local_8,iVar2);

    if (fVar4 <= (float10)param_5) {

      if (local_c == iVar3 + -1) {

        local_10 = (float)fVar4;

      }

    }

    else {

      param_5 = (float)fVar4;

      local_18 = local_14;

      local_c = iVar3;

    }

    local_14 = (float)fVar4;

    iVar3 = iVar3 + 1;

    iVar2 = iVar2 + -1;

    local_8 = local_8 + 4;

  } while (iVar3 + iVar1 <= (int)param_3);

  local_c = local_c + iVar1;

  if ((iVar1 < local_c) && (local_c < (int)param_3)) {

    fVar4 = (float10)FUN_00715980(local_18,param_5,local_10,param_4);

    param_3 = (float)(fVar4 + (float10)local_c);

  }

  else {

    param_3 = (float)local_c;

    *param_4 = param_5;

  }

  fVar4 = (float10)FUN_007144b0(param_1,param_1,param_2 - local_c);

  param_1 = param_1 + local_c * 4;

  fVar5 = (float10)FUN_007144b0(param_1,param_1,param_2 - local_c);

  *param_4 = (float)((float10)*param_4 /

                    SQRT(fVar5 * (float10)(float)fVar4 + (float10)_DAT_00a110e4));

  return (float10)param_3;

}
