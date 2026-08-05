// =============================================================================
// FUN_00702e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00702e60
// Address:   0x00702e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00702e60 @ 0x00702e60
// Stable ID: aa_00702e60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, while×1, return×1.
//  - Notable callees: FUN_00702bb0×2, FUN_00702e60.
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

void FUN_00702e60(int param_1)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0xc) < 7) {

    FUN_00702bb0(param_1,0,1);

    iVar1 = *(int *)(param_1 + 0xc);

    while (iVar1 < 7) {

      FUN_00702bb0(param_1,1,1);

      iVar1 = *(int *)(param_1 + 0xc);

    }

  }

  return;

}
