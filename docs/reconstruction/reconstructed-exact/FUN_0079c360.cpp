// =============================================================================
// FUN_0079c360
// -----------------------------------------------------------------------------
// Stable ID: aa_0079c360
// Address:   0x0079c360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079c360 @ 0x0079c360
// Stable ID: aa_0079c360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0079b0b0, FUN_0079bb20, FUN_0079c360, FUN_007a70f0, NDUIWindow_LoadInterfaceFile.
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

void __fastcall FUN_0079c360(int *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  piVar1 = (int *)(**(code **)(*param_1 + 0x170))(0xe);

  param_1[0x129] = *piVar1;

  piVar1 = (int *)(**(code **)(*param_1 + 0x170))(0xe);

  param_1[0x12a] = *piVar1;

  piVar1 = (int *)(**(code **)(*param_1 + 0x170))(0xc);

  param_1[299] = *piVar1;

  piVar1 = (int *)(**(code **)(*param_1 + 0x170))(8);

  param_1[300] = *piVar1;

  piVar1 = (int *)(**(code **)(*param_1 + 0x170))(4);

  param_1[0x8a] = *piVar1;

  piVar1 = (int *)(**(code **)(*param_1 + 0x170))(0xf);

  uVar2 = 0xf;

  param_1[0x12d] = *piVar1;

  piVar1 = (int *)(**(code **)(*param_1 + 0x170))(0xf);

  param_1[0x12e] = *piVar1;

  piVar1 = (int *)(**(code **)(*param_1 + 0x170))(0xd);

  param_1[0x12f] = *piVar1;

  piVar1 = (int *)(**(code **)(*param_1 + 0x170))(9);

  param_1[0x130] = *piVar1;

  piVar1 = (int *)(**(code **)(*param_1 + 0x170))(5);

  param_1[0x8b] = *piVar1;

  NDUIWindow_LoadInterfaceFile(uVar2);

  if (param_1[0x117] == 0) {

    FUN_007a70f0();

  }

  if (-1 < param_1[0x126]) {

    *(uint8_t *)((int)param_1 + 0x48a) = 1;

  }

  piVar1 = (int *)(**(code **)(*param_1 + 0x164))(0);

  param_1[0x127] = *piVar1;

  FUN_0079bb20();

  FUN_0079b0b0(param_1);

  return;

}
