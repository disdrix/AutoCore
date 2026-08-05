// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00560f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00560f30
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00560f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0055e760, FUN_0055fa40, FUN_00560f30.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00560f30(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint8_t uVar1;

  

  uVar1 = *(uint8_t *)(param_1 + 300);

  *(uint8_t *)(param_1 + 300) = 1;

  FUN_0055e760(param_2);

  FUN_0055fa40(param_2);

  *(uint8_t *)(param_1 + 300) = uVar1;

  return;

}
