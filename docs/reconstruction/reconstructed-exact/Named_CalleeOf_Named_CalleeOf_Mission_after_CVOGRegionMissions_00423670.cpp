// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_after_CVOGRegionMissions_00423670
// -----------------------------------------------------------------------------
// Stable ID: aa_00423670
// Callee of Named_CalleeOf_Mission_after_CVOGRegionMissions (+1 other named callers)
// Address:   0x00423670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_after_CVOGRegionMissions: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Mission_after_CVOGRegionMissions (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004048e0, FUN_00423670, SysAllocString.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_after_CVOGRegionMissions (+1 other named callers)
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Mission_after_CVOGRegionMissions_00423670(uint32_t /* width from decompiler */ *param_1,OLECHAR *param_2)



{

  BSTR pOVar1;

  

  if (param_2 == (OLECHAR *)0x0) {

    *param_1 = 0;

  }

  else {

    pOVar1 = SysAllocString(param_2);

    *param_1 = pOVar1;

    if (pOVar1 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0(0x8007000e);

    }

  }

  return param_1;

}
