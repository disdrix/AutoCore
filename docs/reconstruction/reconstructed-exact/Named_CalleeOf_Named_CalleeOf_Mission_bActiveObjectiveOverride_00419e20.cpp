// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride_00419e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00419e20
// Callee of Named_CalleeOf_Mission_bActiveObjectiveOverride
// Address:   0x00419e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00419e20, InterlockedDecrement, SysFreeString.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_bActiveObjectiveOverride
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

LONG Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride_00419e20(void)



{

  LONG LVar1;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  LVar1 = InterlockedDecrement(unaff_ESI + 2);

  if (LVar1 != 0) {

    return unaff_ESI[2];

  }

  if (unaff_ESI != (uint32_t /* width from decompiler */ *)0x0) {

    if ((BSTR)*unaff_ESI != (BSTR)0x0) {

      SysFreeString((BSTR)*unaff_ESI);

    }

    if ((void *)unaff_ESI[1] != (void *)0x0) {

      operator_delete__((void *)unaff_ESI[1]);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(unaff_ESI);

  }

  return 0;

}
