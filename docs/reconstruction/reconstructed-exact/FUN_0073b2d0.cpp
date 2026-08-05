// =============================================================================
// FUN_0073b2d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073b2d0
// Address:   0x0073b2d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073b2d0 @ 0x0073b2d0
// Stable ID: aa_0073b2d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004641d0, FUN_0073b2d0, FUN_0095d6c0.
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

void FUN_0073b2d0(int param_1)



{

  int iVar1;

  int iVar2;

  

  if (*(int *)(param_1 + 0x14) == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 3;

  }

  iVar2 = 0;

  if (0 < iVar1) {

    do {

      FUN_004641d0();

      FUN_0095d6c0();

      iVar2 = iVar2 + 1;

    } while (iVar2 < iVar1);

  }

  return;

}
