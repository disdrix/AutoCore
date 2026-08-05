// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGSpecGlowF_00450ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_00450ca0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGSpecGlowFilter
// Address:   0x00450ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOGSpecGlowFilter: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00450ca0, FUN_00450d70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGSpecGlowFilter
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGSpecGlowF_00450ca0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  

  iVar2 = param_2 - param_1 >> 2;

  for (iVar1 = iVar2 - (param_2 - param_1 >> 0x1f) >> 1; 0 < iVar1; iVar1 = iVar1 + -1) {

    FUN_00450d70(param_1,iVar2,*(uint32_t /* width from decompiler */ *)(param_1 + -4 + iVar1 * 4),param_3);

  }

  return;

}
