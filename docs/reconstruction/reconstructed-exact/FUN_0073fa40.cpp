// =============================================================================
// FUN_0073fa40
// -----------------------------------------------------------------------------
// Stable ID: aa_0073fa40
// Address:   0x0073fa40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073fa40 @ 0x0073fa40
// Stable ID: aa_0073fa40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0044ffa0, FUN_00450020, FUN_0073f7b0, FUN_0073fa40.
//  - Return sites: 2.

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

int __thiscall FUN_0073fa40(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,int param_4)



{

  int iVar1;

  int iVar2;

  

  iVar2 = FUN_0073f7b0(param_2,param_3);

  if (iVar2 != -1) {

    return -1;

  }

  iVar2 = 0;

  if (*(int *)(param_1 + 0x28) != 0) {

    iVar2 = (*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c;

  }

  iVar2 = iVar2 + 1;

  FUN_00450020(iVar2);

  iVar1 = *(int *)(param_1 + 0x28) + -0x1c + iVar2 * 0x1c;

  if (param_4 != 0) {

    FUN_0044ffa0(iVar1,param_4);

  }

  *(uint32_t /* width from decompiler */ *)(iVar1 + 4) = *param_2;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 8) = *param_3;

  return iVar2;

}
