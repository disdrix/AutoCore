// =============================================================================
// FUN_00858a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00858a30
// Address:   0x00858a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00858a30 @ 0x00858a30
// Stable ID: aa_00858a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_008575e0, FUN_00857670, FUN_00857b90, FUN_00858a30, NDUIWindow_ReloadInterface.
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

void __thiscall FUN_00858a30(int *param_1,int param_2)



{

  int iVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  float fVar5;

  

  FUN_008575e0();

  iVar1 = param_1[0x13f];

  NDUIWindow_ReloadInterface(param_2);

  fVar5 = DAT_00aaa67c;

  iVar3 = (int)((float)param_1[0x150] * (float)DAT_00d1e818 * DAT_00aaa67c);

  fVar4 = (float)DAT_00d1e81c;

  param_1[0x150] = iVar3;

  fVar2 = DAT_00aaa678;

  param_1[0x151] = (int)((float)param_1[0x151] * fVar4 * DAT_00aaa678);

  param_1[0x146] = iVar3;

  param_1[0x147] = param_1[0x151];

  fVar4 = (float)DAT_00d1e81c;

  iVar3 = (int)((float)param_1[0x152] * (float)DAT_00d1e818 * fVar5);

  param_1[0x152] = iVar3;

  param_1[0x153] = (int)((float)param_1[0x153] * fVar4 * fVar2);

  param_1[0x148] = iVar3;

  param_1[0x149] = param_1[0x153];

  fVar4 = (float)DAT_00d1e81c;

  iVar3 = (int)((float)param_1[0x154] * (float)DAT_00d1e818 * fVar5);

  param_1[0x154] = iVar3;

  param_1[0x155] = (int)((float)param_1[0x155] * fVar4 * fVar2);

  param_1[0x14a] = iVar3;

  param_1[0x14b] = param_1[0x155];

  fVar4 = (float)DAT_00d1e81c;

  iVar3 = (int)((float)param_1[0x156] * (float)DAT_00d1e818 * fVar5);

  param_1[0x156] = iVar3;

  param_1[0x157] = (int)((float)param_1[0x157] * fVar4 * fVar2);

  param_1[0x14c] = iVar3;

  param_1[0x14d] = param_1[0x157];

  iVar3 = (int)((float)param_1[0x158] * (float)DAT_00d1e818 * fVar5);

  fVar5 = (float)DAT_00d1e81c;

  param_1[0x158] = iVar3;

  param_1[0x159] = (int)((float)param_1[0x159] * fVar5 * fVar2);

  param_1[0x14e] = iVar3;

  param_1[0x14f] = param_1[0x159];

  FUN_00857670();

  fVar2 = g_flOne;

  if (param_2 == 0) {

    FUN_00857b90();

    param_1[0x13f] = iVar1;

  }

  else {

    fVar5 = DAT_00af9320;

    if (DAT_00af931c < DAT_00af9320) {

      fVar5 = DAT_00af931c;

    }

    fVar5 = (fVar5 * DAT_00a0f298) / (float)param_1[0x141];

    param_1[0x13f] = (int)fVar5;

    if (fVar5 < fVar2) {

      param_1[0x13f] = (int)fVar2;

    }

  }

  (**(code **)(*param_1 + 0x444))();

  (**(code **)(*param_1 + 0x34c))();

  return;

}
