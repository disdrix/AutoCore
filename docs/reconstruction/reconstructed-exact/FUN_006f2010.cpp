// =============================================================================
// FUN_006f2010
// -----------------------------------------------------------------------------
// Stable ID: aa_006f2010
// Address:   0x006f2010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f2010 @ 0x006f2010
// Stable ID: aa_006f2010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_006f1e40×2, FUN_006f2010.
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

void FUN_006f2010(int *param_1,int param_2,int param_3)



{

  if (*param_1 == 0) {

    if ((*(int *)(param_3 + 0x44) == 0) && (*(int *)(param_3 + 0x40) != 0)) {

      FUN_006f1e40(0,*(int *)(param_3 + 0x40));

    }

  }

  else if ((*(int *)(param_3 + 0x44) == 0) && (*(int *)(param_2 + 0x44) != 0)) {

    FUN_006f1e40(0,*(uint32_t /* width from decompiler */ *)(param_3 + 0x40));

    return;

  }

  return;

}
