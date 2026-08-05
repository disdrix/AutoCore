// =============================================================================
// FUN_006d14a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006d14a0
// Address:   0x006d14a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d14a0 @ 0x006d14a0
// Stable ID: aa_006d14a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0042a340×2, FUN_006d14a0, FUN_006f2d10, FUN_006f38d0, FUN_006f3950, FUN_006f39a0, FUN_006f4810, FUN_006f5030.
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

int __thiscall FUN_006d14a0(uint32_t /* width from decompiler */ *param_1,int *param_2,int param_3,int param_4)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_EDI;

  int iVar4;

  int iStack_110;

  int iStack_10c;

  int iStack_108;

  int iStack_104;

  uint8_t auStack_100 [16];

  uint8_t auStack_f0 [60];

  uint8_t auStack_b4 [20];

  int iStack_a0;

  int aiStack_94 [36];

  

  iVar1 = (**(code **)(*param_2 + 4))();

  iVar4 = param_1[2];

  FUN_006f38d0((iVar1 + iVar4) * 0xc);

  FUN_006f5350(param_1 + 6);

  FUN_006f2d10(param_1 + 0xc,auStack_100,param_2);

  iVar2 = (**(code **)(*param_2 + 4))();

  iVar2 = (iVar2 + 0x1b400 + param_1[2]) * 0x10;

  if ((param_3 == 0) || (iStack_110 = param_3, param_4 < iVar2)) {

    iStack_110 = (**(code **)*DAT_00b05060)(iVar2,0x23);

  }

  iStack_108 = (iVar1 + iVar4) * 0x10 + iStack_110;

  iStack_104 = iStack_108 + 0xf8000;

  iStack_10c = iStack_110;

  (**(code **)(*param_2 + 8))(iStack_110);

  FUN_006f4810();

  uVar3 = FUN_006f5030(param_2,auStack_b4,aiStack_94,param_1 + 1,&iStack_110);

  (**(code **)(aiStack_94[0] + 0xc))(uVar3,auStack_f0,0x2000);

  FUN_0042a340();

  if (unaff_EDI != param_3) {

    (**(code **)(*DAT_00b05060 + 4))(unaff_EDI);

  }

  *param_1 = uVar3;

  iVar4 = 0x30;

  do {

    FUN_006f39a0(0);

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  iVar4 = FUN_006f3950();

  *(int *)(iVar4 + 0x20) = iStack_108;

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0x24) = 1;

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0x10) = 0xff;

  (**(code **)(iStack_a0 + 0x10))(uVar3,iVar4);

  FUN_0042a340();

  return iVar4;

}
