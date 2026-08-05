// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxEffectDet_004621a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004621a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxEffectDetailDisplay
// Address:   0x004621a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxEffectDetailDisplay: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004621a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxEffectDetailDisplay
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxEffectDet_004621a0(int *param_1)



{

  int *piVar1;

  int *unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bdcb1;

  local_c = ExceptionList;

  local_4 = 0;

  if (param_1 != (int *)0x0) {

    piVar1 = (int *)*unaff_EDI;

    if ((piVar1 != (int *)0x0) &&

       (ExceptionList = &local_c, piVar1[1] = piVar1[1] + 1, piVar1[1] == 1)) {

      (**(code **)(*piVar1 + 4))();

    }

    *param_1 = *unaff_EDI;

    *(char *)(param_1 + 1) = (char)unaff_EDI[1];

    *(uint8_t *)((int)param_1 + 5) = *(uint8_t *)((int)unaff_EDI + 5);

    *(uint8_t *)((int)param_1 + 6) = *(uint8_t *)((int)unaff_EDI + 6);

    param_1[2] = unaff_EDI[2];

  }

  ExceptionList = local_c;

  return;

}
