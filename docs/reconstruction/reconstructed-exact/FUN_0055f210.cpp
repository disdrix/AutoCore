// =============================================================================
// FUN_0055f210
// -----------------------------------------------------------------------------
// Stable ID: aa_0055f210
// Address:   0x0055f210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055f210 @ 0x0055f210
// Stable ID: aa_0055f210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00629240×2, FUN_0055eb80, FUN_0055efd0, FUN_0055f210, FUN_0062a550.
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

int __thiscall FUN_0055f210(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *(int *)(*(int *)(param_2 + 0x10) + 0x44);

  iVar3 = *(int *)(*(int *)(param_2 + 0xc) + 0x44);

  if (iVar3 == *(int *)(param_1 + 0x2c)) {

    FUN_00629240(param_2);

    cVar1 = *(char *)(iVar2 + 0x29);

  }

  else {

    if ((iVar2 != *(int *)(param_1 + 0x2c)) && (iVar3 != iVar2)) {

      FUN_0055efd0(*(int *)(param_2 + 0xc),*(int *)(param_2 + 0x10));

    }

    FUN_00629240(param_2);

    cVar1 = *(char *)(iVar3 + 0x29);

    iVar2 = iVar3;

  }

  if (cVar1 == '\0') {

    FUN_0055eb80(iVar2);

  }

  FUN_0062a550(param_1,param_2);

  return param_2;

}
