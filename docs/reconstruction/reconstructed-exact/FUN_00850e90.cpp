// =============================================================================
// FUN_00850e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00850e90
// Address:   0x00850e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00850e90 @ 0x00850e90
// Stable ID: aa_00850e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0084f760, FUN_0084fb20, FUN_0084fd60, FUN_00850e90, NDUIWindow_ReloadInterface.
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

/* WARNING: Type propagation algorithm not settling */



void __thiscall FUN_00850e90(int *param_1,int param_2)



{

  float fVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  float fVar4;

  float fVar5;

  int local_c [3];

  

  FUN_0084fb20();

  local_c[0] = param_1[0x141];

  NDUIWindow_ReloadInterface(param_2);

  fVar5 = DAT_00aaa67c;

  iVar2 = (int)((float)param_1[0x150] * (float)DAT_00d1e818 * DAT_00aaa67c);

  fVar4 = (float)DAT_00d1e81c;

  param_1[0x150] = iVar2;

  fVar1 = DAT_00aaa678;

  param_1[0x151] = (int)((float)param_1[0x151] * fVar4 * DAT_00aaa678);

  param_1[0x146] = iVar2;

  param_1[0x147] = param_1[0x151];

  fVar4 = (float)DAT_00d1e81c;

  iVar2 = (int)((float)param_1[0x152] * (float)DAT_00d1e818 * fVar5);

  param_1[0x152] = iVar2;

  param_1[0x153] = (int)((float)param_1[0x153] * fVar4 * fVar1);

  param_1[0x148] = iVar2;

  param_1[0x149] = param_1[0x153];

  fVar4 = (float)DAT_00d1e81c;

  iVar2 = (int)((float)param_1[0x154] * (float)DAT_00d1e818 * fVar5);

  param_1[0x154] = iVar2;

  param_1[0x155] = (int)((float)param_1[0x155] * fVar4 * fVar1);

  param_1[0x14a] = iVar2;

  param_1[0x14b] = param_1[0x155];

  fVar4 = (float)DAT_00d1e81c;

  iVar2 = (int)((float)param_1[0x156] * (float)DAT_00d1e818 * fVar5);

  param_1[0x156] = iVar2;

  param_1[0x157] = (int)((float)param_1[0x157] * fVar4 * fVar1);

  param_1[0x14c] = iVar2;

  param_1[0x14d] = param_1[0x157];

  iVar2 = (int)((float)param_1[0x158] * (float)DAT_00d1e818 * fVar5);

  fVar5 = (float)DAT_00d1e81c;

  param_1[0x158] = iVar2;

  param_1[0x159] = (int)((float)param_1[0x159] * fVar5 * fVar1);

  param_1[0x14e] = iVar2;

  param_1[0x14f] = param_1[0x159];

  if (param_1[0x19a] != 0) {

    local_c[1] = 0;

    local_c[2] = 0;

    (**(code **)(*(int *)param_1[0x19a] + 0x110))(local_c + 1);

    iVar2 = *(int *)param_1[0x19a];

    uVar3 = (**(code **)(*param_1 + 0x140))(local_c,1);

    (**(code **)(iVar2 + 0x130))(uVar3);

  }

  if (param_2 == 0) {

    FUN_0084fd60();

  }

  FUN_0084f760();

  (**(code **)(*param_1 + 0x444))();

  (**(code **)(*param_1 + 0x34c))();

  return;

}
