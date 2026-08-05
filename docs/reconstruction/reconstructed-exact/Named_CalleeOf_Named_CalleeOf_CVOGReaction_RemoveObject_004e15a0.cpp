// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_RemoveObject_004e15a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e15a0
// Callee of Named_CalleeOf_CVOGReaction_RemoveObject (+1 other named callers)
// Address:   0x004e15a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_RemoveObject: event/reaction helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_CVOGReaction_RemoveObject (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: LeaveCriticalSection×4, EnterCriticalSection×2, FUN_004e15a0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_RemoveObject (+1 other named callers)
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_CVOGReaction_RemoveObject_004e15a0(int param_1,int param_2)



{

  LPCRITICAL_SECTION lpCriticalSection;

  LPCRITICAL_SECTION lpCriticalSection_00;

  int iVar1;

  

  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x28);

  EnterCriticalSection(lpCriticalSection);

  lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 0x10);

  EnterCriticalSection(lpCriticalSection_00);

  iVar1 = *(int *)(param_1 + 4);

  while( true ) {

    if (iVar1 == 0) {

      LeaveCriticalSection(lpCriticalSection_00);

      LeaveCriticalSection(lpCriticalSection);

      return 0;

    }

    if (*(int *)(iVar1 + 4) == param_2) break;

    iVar1 = *(int *)(iVar1 + 8);

  }

  LeaveCriticalSection(lpCriticalSection_00);

  LeaveCriticalSection(lpCriticalSection);

  return 1;

}
