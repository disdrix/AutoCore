// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004cb550
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb550
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004cb550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004cb550×2.
//  - Return sites: 2.

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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004cb550(void *param_1)



{

  if (*(char *)((int)param_1 + 0x29) == '\0') {

    Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004cb550(*(uint32_t /* width from decompiler */ *)((int)param_1 + 8));

                    /* WARNING: Subroutine does not return */

    operator_delete(param_1);

  }

  return;

}
