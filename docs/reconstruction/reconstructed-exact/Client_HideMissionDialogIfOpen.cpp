// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: Client_HideMissionDialogIfOpen, it, layout, visible.
//  - Return sites: 2.

// =============================================================================
// Client_HideMissionDialogIfOpen
// -----------------------------------------------------------------------------
// Stable ID: aa_0092ce50
// Address:   0x0092ce50  (autoassault.exe, image base 0x400000)
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

/* Client_HideMissionDialogIfOpen

   

   If mission dialog root at game+0x107c is visible (vtable+0x3d8), hide it (+0x448)

   and refresh layout (+0x34c). */



void Client_HideMissionDialogIfOpen(void)



{

  char cVar1;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x107c) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x107c) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x107c) + 0x448))();

                    /* WARNING: Could not recover jumptable at 0x0092ce81. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(unaff_ESI + 0x107c) + 0x34c))();

      return;

    }

  }

  return;

}
