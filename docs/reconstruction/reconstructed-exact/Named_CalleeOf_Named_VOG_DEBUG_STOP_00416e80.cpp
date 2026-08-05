// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00416e80
// -----------------------------------------------------------------------------
// Stable ID: aa_00416e80
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00416e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00416e80, _aligned_free.
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

void Named_CalleeOf_Named_VOG_DEBUG_STOP_00416e80(int param_1)



{

  void **ppvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bc71b;

  local_c = ExceptionList;

  local_4 = 0;

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

  ExceptionList = &local_c;

  ppvVar1 = &local_c;

  if (puVar2 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc)) {

    do {

      ExceptionList = ppvVar1;

      _aligned_free((void *)*puVar2);

      puVar2 = puVar2 + 1;

      ppvVar1 = ExceptionList;

    } while (puVar2 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc));

  }

  local_4 = 0xffffffff;

  if (*(void **)(param_1 + 8) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    ExceptionList = local_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 8));

}
