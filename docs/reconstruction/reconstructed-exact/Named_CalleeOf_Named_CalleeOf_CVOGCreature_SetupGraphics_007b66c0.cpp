// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGCreature_SetupGraphics_007b66c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b66c0
// Callee of Named_CalleeOf_CVOGCreature_SetupGraphics (+1 other named callers)
// Address:   0x007b66c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGCreature_SetupGraphics: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_CVOGCreature_SetupGraphics (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, goto×1.
//  - Notable callees: strrchr×2, FUN_007b66c0, FUN_00989e00.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGCreature_SetupGraphics (+1 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_CVOGCreature_SetupGraphics_007b66c0(int param_1)



{

  char *in_EAX;

  char *pcVar1;

  char *pcVar2;

  int iVar3;

  

  iVar3 = param_1;

  if ((*(byte *)(param_1 + 4) & 2) == 0) {

    return 0;

  }

  pcVar1 = strrchr(in_EAX,0x5c);

  pcVar2 = strrchr(in_EAX,0x2f);

  if (pcVar1 == (char *)0x0) {

    if (pcVar2 == (char *)0x0) goto LAB_007b66f8;

  }

  else if (pcVar2 < pcVar1) {

    pcVar2 = pcVar1;

  }

  in_EAX = pcVar2 + 1;

LAB_007b66f8:

  FUN_00989e00(&param_1,in_EAX);

  iVar3 = (**(code **)(**(int **)(iVar3 + 0xc) + 0x14))(&param_1);

  if (iVar3 == 0) {

    return 0;

  }

  return 1;

}
