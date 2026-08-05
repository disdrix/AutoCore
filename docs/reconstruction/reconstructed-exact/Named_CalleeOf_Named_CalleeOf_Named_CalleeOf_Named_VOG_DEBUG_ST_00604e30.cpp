// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00604e30
// -----------------------------------------------------------------------------
// Stable ID: aa_00604e30
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00604e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×5, if×4.
//  - Notable callees: FUN_00604e30.
//  - Return sites: 5.

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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00604e30(int param_1)



{

  if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  if (*(void **)(param_1 + 8) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 8));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  if (*(void **)(param_1 + 0xc) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0xc));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  if (*(void **)(param_1 + 0x10) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x10));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  return;

}
