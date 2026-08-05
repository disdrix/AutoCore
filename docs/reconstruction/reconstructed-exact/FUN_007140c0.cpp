// =============================================================================
// FUN_007140c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007140c0
// Address:   0x007140c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007140c0 @ 0x007140c0
// Stable ID: aa_007140c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, if×2, return×1.
//  - Notable callees: FUN_007140c0, FUN_00714480, ROUND.
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



void FUN_007140c0(int param_1,int param_2,float *param_3,int param_4)



{

  float fVar1;

  float *pfVar2;

  float *pfVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float *pfVar8;

  float local_210 [65];

  float local_10c [65];

  int local_8;

  

  iVar6 = (int)ROUND((float)param_2 * _DAT_00a11084 * _DAT_00a0f6b0);

  local_10c[0] = 0.0;

  iVar4 = iVar6 + 0x4000;

  iVar5 = 0x3f;

  pfVar2 = local_10c + 1;

  local_8 = iVar6;

  do {

    pfVar8 = pfVar2 + 1;

    iVar7 = iVar4 >> 0xf;

    iVar4 = iVar4 + iVar6;

    iVar5 = iVar5 + -1;

    *pfVar2 = *(float *)(param_1 + iVar7 * 4);

    pfVar2 = pfVar8;

  } while (iVar5 != 0);

  *pfVar8 = 0.0;

  (*(code *)PTR_memset_00af8a50)(local_210,0,0x104);

  FUN_00714480(local_10c,local_210,0x80);

  pfVar2 = local_10c;

  pfVar8 = local_210;

  iVar6 = param_4 + 1 >> 1;

  pfVar3 = param_3;

  iVar4 = iVar6;

  if (0 < iVar6) {

    do {

      fVar1 = *pfVar2;

      pfVar2 = pfVar2 + 1;

      pfVar3 = param_3 + 2;

      iVar4 = iVar4 + -1;

      *param_3 = fVar1 * DAT_00a11080;

      param_3[1] = *pfVar8 * DAT_00a11080;

      param_3 = pfVar3;

      pfVar8 = pfVar8 + 1;

    } while (iVar4 != 0);

  }

  if (iVar6 * 2 != param_4 + 1) {

    *pfVar3 = *pfVar2 * DAT_00a11080;

  }

  return;

}
