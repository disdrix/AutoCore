// =============================================================================
// FUN_00560ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_00560ec0
// Address:   0x00560ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00560ec0 @ 0x00560ec0
// Stable ID: aa_00560ec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0055e760, FUN_0055fa40, FUN_00560ec0, FUN_0062a450.
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

int __thiscall FUN_00560ec0(int param_1,int param_2)



{

  uint8_t uVar1;

  int iVar2;

  

  uVar1 = *(uint8_t *)(param_1 + 300);

  *(uint8_t *)(param_1 + 300) = 1;

  if (*(char *)(param_2 + 0x40) == '\0') {

    iVar2 = *(int *)(param_1 + 0x130);

    *(int *)(param_1 + 0x130) = iVar2 + 1;

  }

  else {

    iVar2 = *(int *)(param_1 + 0x134);

    *(int *)(param_1 + 0x134) = iVar2 + -1;

  }

  *(int *)(param_2 + 0x20) = iVar2;

  FUN_0055e760(param_2);

  FUN_0055fa40(param_2);

  *(uint8_t *)(param_1 + 300) = uVar1;

  *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;

  FUN_0062a450(param_1,param_2);

  return param_2;

}
