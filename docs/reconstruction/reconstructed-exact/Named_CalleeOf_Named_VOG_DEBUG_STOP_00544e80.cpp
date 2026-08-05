// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00544e80
// -----------------------------------------------------------------------------
// Stable ID: aa_00544e80
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00544e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00544e80, FUN_00544ec0, free.
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

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_00544e80(int param_1)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  FUN_00544ec0();

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x10) != (uint32_t /* width from decompiler */ *)0x0) {

    free((void *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x10));

    operator_delete__(*(void **)(param_1 + 0x10));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  }

  return;

}
