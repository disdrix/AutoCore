// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007aff00
// -----------------------------------------------------------------------------
// Stable ID: aa_007aff00
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x007aff00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00424060, FUN_00797d70, FUN_007aff00.
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

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_007aff00(int param_1)



{

  void *pvVar1;

  

  if (*(int *)(param_1 + 0x20c) != 0) {

    pvVar1 = *(void **)(param_1 + 0x28c);

    if (pvVar1 != (void *)0x0) {

      FUN_00797d70(pvVar1);

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28c) = 0;

  }

  FUN_00424060();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x128) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 300) = 0;

  return;

}
