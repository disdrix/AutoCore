// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_00419dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00419dd0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_bActiveObj
// Address:   0x00419dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_bActiveObj: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00419dd0, SysAllocStringByteLen, SysStringByteLen, _com_issue_error.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_bActiveObj
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_00419dd0(char param_1)



{

  UINT len;

  BSTR pOVar1;

  uint32_t /* width from decompiler */ *unaff_ESI;

  BSTR unaff_EDI;

  

  unaff_ESI[1] = 0;

  unaff_ESI[2] = 1;

  if ((param_1 == '\0') || (unaff_EDI == (BSTR)0x0)) {

    *unaff_ESI = unaff_EDI;

  }

  else {

    len = SysStringByteLen(unaff_EDI);

    pOVar1 = SysAllocStringByteLen((LPCSTR)unaff_EDI,len);

    *unaff_ESI = pOVar1;

    if (pOVar1 == (BSTR)0x0) {

      _com_issue_error(-0x7ff8fff2);

      return;

    }

  }

  return;

}
