// =============================================================================
// FUN_005bfa90
// -----------------------------------------------------------------------------
// Stable ID: aa_005bfa90
// Address:   0x005bfa90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005bfa90 @ 0x005bfa90
// Stable ID: aa_005bfa90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005bfa90, FUN_0074b8f0.
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

uint32_t /* width from decompiler */ __thiscall FUN_005bfa90(int *param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  (**(code **)(*param_1 + 0x20))(*(uint32_t /* width from decompiler */ *)(*param_2 + 0x390));

  param_1[0x2f] = param_1[0x2f] & 0xfffffffe;

  fStack_10 = (float)param_1[0x33] * (float)param_2[0x10];

  fStack_c = (float)*(ushort *)((int)param_1 + 0xea) * (float)param_2[0x11];

  fStack_8 = (float)param_1[0x34] * (float)param_2[0x10];

  if ((*(byte *)(param_1 + 0x2f) & 1) != 0) {

    (**(code **)(*param_1 + 0x5c))();

  }

  FUN_0074b8f0(&fStack_10,&stack0xffffffe4);

  iVar1 = (**(code **)(**(int **)(*param_2 + 0x390) + 0xc))();

  param_1[0x19] = iVar1;

  iVar1 = *param_1;

  uVar2 = (**(code **)(**(int **)(*param_2 + 0x390) + 100))();

  (**(code **)(iVar1 + 0x34))(uVar2);

  return 1;

}
