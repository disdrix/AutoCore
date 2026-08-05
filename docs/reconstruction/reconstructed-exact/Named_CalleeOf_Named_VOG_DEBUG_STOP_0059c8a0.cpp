// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0059c8a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0059c8a0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0059c8a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0059c8a0, _aligned_free.
//  - Return sites: 2.

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

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_0059c8a0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

  if (puVar1 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc)) {

    do {

      _aligned_free((void *)*puVar1);

      puVar1 = puVar1 + 1;

    } while (puVar1 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc));

  }

  if (*(void **)(param_1 + 8) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 8));

}
