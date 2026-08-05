// =============================================================================
// FUN_005e5620
// -----------------------------------------------------------------------------
// Stable ID: aa_005e5620
// Address:   0x005e5620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e5620 @ 0x005e5620
// Stable ID: aa_005e5620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: fwrite×3, FUN_005a61d0, FUN_005e5620.
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

void __thiscall FUN_005e5620(int param_1,FILE *param_2)



{

  int iVar1;

  

  FUN_005a61d0(param_2);

  fwrite((void *)(param_1 + 0x160),4,1,param_2);

  iVar1 = 0;

  do {

    fwrite((void *)(*(int *)(param_1 + 0x168) + iVar1),0xc,1,param_2);

    fwrite((void *)(*(int *)(param_1 + 0x178) + iVar1),0xc,1,param_2);

    iVar1 = iVar1 + 0xc;

  } while (iVar1 < 0x48);

  return;

}
