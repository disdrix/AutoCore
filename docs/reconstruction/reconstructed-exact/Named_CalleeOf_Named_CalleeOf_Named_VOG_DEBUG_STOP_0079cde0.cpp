// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0079cde0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079cde0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0079cde0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_0079cde0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0079cde0(int *param_1,char *param_2)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ unaff_ESI;

  

  pcVar2 = param_2;

  cVar1 = *param_2;

  pcVar3 = param_2;

  while (cVar1 != '\0') {

    pcVar3 = pcVar3 + 1;

    cVar1 = *pcVar3;

  }

  param_2 = pcVar3 + (1 - (int)param_2);

  (**(code **)(*param_1 + 8))(&param_2,4);

  (**(code **)(*param_1 + 8))(pcVar2,unaff_ESI);

  return;

}
