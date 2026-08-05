// =============================================================================
// FUN_00423870
// -----------------------------------------------------------------------------
// Stable ID: aa_00423870
// Address:   0x00423870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00423870 @ 0x00423870
// Stable ID: aa_00423870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00423860, FUN_00423870.
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

void FUN_00423870(void)



{

  int iVar1;

  int *unaff_ESI;

  

  iVar1 = (**(code **)(**(int **)(*unaff_ESI + -0x10) + 8))(*unaff_ESI + -0x10);

  if (iVar1 == 0) {

    FUN_00423860();

    return;

  }

  *unaff_ESI = iVar1 + 0x10;

  return;

}
