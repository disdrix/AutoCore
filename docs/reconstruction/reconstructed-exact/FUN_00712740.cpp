// =============================================================================
// FUN_00712740
// -----------------------------------------------------------------------------
// Stable ID: aa_00712740
// Address:   0x00712740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712740 @ 0x00712740
// Stable ID: aa_00712740
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×2, return×1.
//  - Notable callees: FUN_00712740.
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



void FUN_00712740(byte param_1,int *param_2)



{

  int iVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  int iVar7;

  

  iVar7 = (int)(short)(ushort)(param_1 >> 3);

  *(float *)(*param_2 + iVar7 * 4) =

       (*(float *)(*param_2 + iVar7 * 4) - g_flOne) * _DAT_00a0f6d4 + g_flOne;

  iVar5 = *param_2;

  iVar4 = 0;

  fVar2 = *(float *)(iVar5 + iVar7 * 4);

  if (iVar7 != 0) {

    do {

      iVar1 = iVar4 * 4;

      iVar4 = iVar4 + 1;

      *(float *)(iVar5 + -4 + iVar4 * 4) = *(float *)(iVar5 + iVar1) * _DAT_00a0f6d4;

      iVar5 = *param_2;

      fVar2 = fVar2 + *(float *)(iVar5 + -4 + iVar4 * 4);

    } while (iVar4 < iVar7);

  }

  if (iVar7 + 1U < 0x21) {

    iVar5 = *param_2;

    iVar4 = (iVar7 + 1U) * 4;

    do {

      iVar7 = iVar4 + 4;

      *(float *)(iVar4 + iVar5) = *(float *)(iVar4 + iVar5) * _DAT_00a0f6d4;

      iVar5 = *param_2;

      fVar2 = fVar2 + *(float *)(iVar4 + iVar5);

      iVar4 = iVar7;

    } while (iVar7 < 0x81);

  }

  _param_1 = 0;

  param_2[1] = 0;

  pfVar6 = (float *)*param_2;

  do {

    fVar3 = (float)_param_1;

    _param_1 = _param_1 + 1;

    param_2[1] = (int)((fVar3 * *pfVar6) / fVar2 + (float)param_2[1]);

    pfVar6 = pfVar6 + 1;

  } while (_param_1 < 0x21);

  fVar2 = (float)param_2[1] * DAT_00a0f6a4;

  *(uint16_t *)(param_2 + 2) = 0;

  param_2[1] = (int)fVar2;

  return;

}
