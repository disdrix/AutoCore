// =============================================================================
// Named_CalleeOf_CVOGObjectiveRequirement_UseItem_SerializeXml_0060d400
// -----------------------------------------------------------------------------
// Stable ID: aa_0060d400
// Callee of CVOGObjectiveRequirement_UseItem_SerializeXml
// Address:   0x0060d400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGObjectiveRequirement_UseItem_SerializeXml: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, if×1, return×1.
//  - Notable callees: FUN_0060d400.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGObjectiveRequirement_UseItem_SerializeXml
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

void __thiscall Named_CalleeOf_CVOGObjectiveRequirement_UseItem_SerializeXml_0060d400(int param_1,char *param_2)



{

  char *pcVar1;

  char cVar2;

  char *pcVar3;

  char *pcVar4;

  

  if (*(void **)(param_1 + 0x44) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x44));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  pcVar1 = param_2 + 1;

  pcVar3 = param_2;

  do {

    cVar2 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar2 != '\0');

  pcVar4 = operator_new__((uint)(pcVar3 + (1 - (int)pcVar1)));

  *(char **)(param_1 + 0x44) = pcVar4;

  do {

    cVar2 = *param_2;

    *pcVar4 = cVar2;

    param_2 = param_2 + 1;

    pcVar4 = pcVar4 + 1;

  } while (cVar2 != '\0');

  pcVar3[*(int *)(param_1 + 0x44) - (int)pcVar1] = '\0';

  return;

}
