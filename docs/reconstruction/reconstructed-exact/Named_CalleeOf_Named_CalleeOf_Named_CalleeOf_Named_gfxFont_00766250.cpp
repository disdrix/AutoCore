// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxFont_00766250
// -----------------------------------------------------------------------------
// Stable ID: aa_00766250
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxFont (+1 other named callers)
// Address:   0x00766250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxFont: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Named_gfxFont (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_00766250.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxFont (+1 other named callers)
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxFont_00766250(void)



{

  int in_EAX;

  int iVar1;

  char *pcVar2;

  int iVar3;

  

  iVar3 = *(int *)(in_EAX + 0x14);

  if (*(uint *)(in_EAX + 0x18) < 0x10) {

    pcVar2 = (char *)(in_EAX + 4);

  }

  else {

    pcVar2 = *(char **)(in_EAX + 4);

  }

  iVar1 = 0x1505;

  for (; iVar3 != 0; iVar3 = iVar3 + -1) {

    iVar1 = (int)*pcVar2 + iVar1 * 0x21;

    pcVar2 = pcVar2 + 1;

  }

  return iVar1;

}
