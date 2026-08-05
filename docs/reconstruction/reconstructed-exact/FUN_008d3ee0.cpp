// =============================================================================
// FUN_008d3ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_008d3ee0
// Address:   0x008d3ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d3ee0 @ 0x008d3ee0
// Stable ID: aa_008d3ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_008d3a70, FUN_008d3b30, FUN_008d3c90, FUN_008d3ee0, FUN_008d7800.
//  - Return sites: 4.

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

void __fastcall FUN_008d3ee0(int param_1)



{

  int iVar1;

  

  FUN_008d7800(param_1);

  if ((*(int *)(param_1 + 0x548) != 0) && (*(int *)(*(int *)(param_1 + 0x548) + 0x48) != 0)) {

    iVar1 = *(int *)(param_1 + 0x568);

    if (iVar1 == 0) {

      FUN_008d3a70();

      return;

    }

    if (iVar1 == 1) {

      FUN_008d3c90();

      return;

    }

    if (iVar1 == 2) {

      FUN_008d3b30();

      return;

    }

  }

  return;

}
