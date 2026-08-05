// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_007662b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007662b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTacArc_Initial
// Address:   0x007662b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTacArc_Initial: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_007662b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTacArc_Initial
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_007662b0(char *param_1)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  int iVar4;

  

  pcVar2 = param_1;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  iVar4 = 0x1505;

  for (iVar3 = (int)pcVar2 - (int)(param_1 + 1); iVar3 != 0; iVar3 = iVar3 + -1) {

    iVar4 = (int)*param_1 + iVar4 * 0x21;

    param_1 = param_1 + 1;

  }

  return iVar4;

}
