// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_004bcbf0
// -----------------------------------------------------------------------------
// Stable ID: aa_004bcbf0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x004bcbf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: DeleteCriticalSection×2, FUN_0040b020×2, FUN_004bcbf0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_004bcbf0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  *param_1 = &PTR_FUN_009cb368;

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_0040b020();

  while (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)*puVar1)(1);

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_0040b020();

  }

  param_1[3] = 0;

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 10));

  return;

}
