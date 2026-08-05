// =============================================================================
// Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007fb990
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb990
// Callee of Client_Input_OnKeyDown_MatchAction
// Address:   0x007fb990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_OnKeyDown_MatchAction: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_007fb990.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_Input_OnKeyDown_MatchAction
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007fb990(void)



{

  char cVar1;

  int iVar2;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x1144) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xd0))();

    if (cVar1 != '\0') {

      iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xe8))();

      if (iVar2 != -1) {

        (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xfc))(0,0x3dcccccd);

      }

    }

  }

  return;

}
