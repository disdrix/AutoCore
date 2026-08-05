// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00563a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00563a70
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x00563a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00563a70, FUN_00566f00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_00563a70(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  

  if (param_2 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2;

  }

  FUN_00566f00(iVar1);

  *(uint32_t /* width from decompiler */ *)(param_2 + 600) = param_1;

  return;

}
