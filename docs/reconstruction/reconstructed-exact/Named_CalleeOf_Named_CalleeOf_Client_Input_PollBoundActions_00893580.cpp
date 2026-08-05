// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00893580
// -----------------------------------------------------------------------------
// Stable ID: aa_00893580
// Callee of Named_CalleeOf_Client_Input_PollBoundActions
// Address:   0x00893580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00837d50, FUN_00893580.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_PollBoundActions
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

void Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00893580(void)



{

  int unaff_EBX;

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0x54c) != 0) {

    FUN_00837d50();

    if (unaff_EBX != 0) {

      (**(code **)(**(int **)(unaff_EDI + 0x54c) + 0xfc))(1);

      return;

    }

    (**(code **)(**(int **)(unaff_EDI + 0x54c) + 0xfc))(0,0x3f000000);

  }

  return;

}
