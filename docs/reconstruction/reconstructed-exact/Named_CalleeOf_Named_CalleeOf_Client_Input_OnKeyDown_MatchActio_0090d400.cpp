// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_OnKeyDown_MatchActio_0090d400
// -----------------------------------------------------------------------------
// Stable ID: aa_0090d400
// Callee of Named_CalleeOf_Client_Input_OnKeyDown_MatchAction
// Address:   0x0090d400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_OnKeyDown_MatchAction: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0090d400.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_OnKeyDown_MatchAction
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

void Named_CalleeOf_Named_CalleeOf_Client_Input_OnKeyDown_MatchActio_0090d400(void)



{

  char cVar1;

  int *unaff_ESI;

  int *unaff_EDI;

  

  if (unaff_ESI != (int *)0x0) {

    cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(*unaff_ESI + 0xcc))(0);

      (**(code **)(*unaff_ESI + 0x440))();

      (**(code **)(*unaff_EDI + 0xb0))();

      if (DAT_00d1b978 != (int *)0x0) {

        cVar1 = (**(code **)(*DAT_00d1b978 + 0x3d8))();

        if (cVar1 != '\0') {

          (**(code **)(*unaff_EDI + 0x3bc))(DAT_00d1b978);

        }

      }

      (**(code **)(*unaff_EDI + 0x3f4))(0xffffffff);

    }

  }

  return;

}
