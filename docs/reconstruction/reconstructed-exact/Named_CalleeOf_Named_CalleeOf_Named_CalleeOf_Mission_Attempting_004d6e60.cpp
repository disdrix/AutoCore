// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Attempting_004d6e60
// -----------------------------------------------------------------------------
// Stable ID: aa_004d6e60
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d
// Address:   0x004d6e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_004a8680, FUN_004aa920, FUN_004ac290, FUN_004d6e60, _eh_vector_destructor_iterator_.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Attempting_004d6e60(int *param_1)



{

  void *pvVar1;

  

  if (param_1[0x393e] != 0) {

    FUN_004aa920();

    pvVar1 = (void *)param_1[0x39ed];

    if (pvVar1 != (void *)0x0) {

      _eh_vector_destructor_iterator_(pvVar1,0x20,*(int *)((int)pvVar1 + -4),FUN_004e45e0);

      operator_delete__((void *)((int)pvVar1 + -4));

    }

    param_1[0x39ed] = 0;

    *(uint8_t *)(param_1 + 0x39f2) = 0;

    FUN_004a8680();

    pvVar1 = (void *)param_1[0x393e];

    if (pvVar1 != (void *)0x0) {

      FUN_004ac290();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    param_1[0x393e] = 0;

  }

  if ((uint32_t /* width from decompiler */ *)param_1[0x393f] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x393f])(1);

  }

  param_1[0x393f] = 0;

  (**(code **)(*param_1 + 0xc))();

  if ((void *)param_1[0x3a42] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x3a42]);

  }

  param_1[0x3a42] = 0;

  param_1[0x3a43] = 0;

  param_1[0x3a44] = 0;

  return;

}
