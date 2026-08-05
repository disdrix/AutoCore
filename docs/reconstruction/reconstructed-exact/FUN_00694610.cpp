// =============================================================================
// FUN_00694610
// -----------------------------------------------------------------------------
// Stable ID: aa_00694610
// Address:   0x00694610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00694610 @ 0x00694610
// Stable ID: aa_00694610
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00691720, FUN_00693bc0, FUN_00694610.
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

void FUN_00694610(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = (param_2 - param_1) / 0x30;

  iVar2 = iVar1 / 2;

  if (0 < iVar2) {

    iVar3 = iVar2 * 0x30 + 0x14 + param_1;

    do {

      iVar2 = iVar2 + -1;

      FUN_00691720(iVar3 + -0x44);

      FUN_00693bc0(param_1,iVar2,iVar1);

      iVar3 = iVar3 + -0x30;

    } while (0 < iVar2);

  }

  return;

}
