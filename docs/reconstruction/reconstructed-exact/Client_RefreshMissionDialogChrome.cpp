// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: Client_RefreshMissionDialogChrome, FUN_008a05a0.
//  - Return sites: 1.

// =============================================================================
// Client_RefreshMissionDialogChrome
// -----------------------------------------------------------------------------
// Stable ID: aa_009306a0
// Address:   0x009306a0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* Client_RefreshMissionDialogChrome

   

   If dialog chrome at game+0x10b0 is open, call FUN_008a05a0 to refresh it. */



void Client_RefreshMissionDialogChrome(void)



{

  char cVar1;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x10b0) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x10b0) + 0x3d8))();

    if (cVar1 != '\0') {

      FUN_008a05a0();

    }

  }

  return;

}
