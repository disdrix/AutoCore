// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004440a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004440a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxFontImpl
// Address:   0x004440a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxFontImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004440a0, FUN_00444100.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxFontImpl
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

int * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004440a0(int *param_1)



{

  int iVar1;

  int *unaff_ESI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bd558;

  pvStack_c = ExceptionList;

  iVar1 = *unaff_ESI;

  ExceptionList = &pvStack_c;

  if (iVar1 != 0) {

    ExceptionList = &pvStack_c;

    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;

    if (*(int *)(iVar1 + 8) == 1) {

      (**(code **)(*(int *)(iVar1 + 4) + 4))();

    }

  }

  *param_1 = *unaff_ESI;

  local_4 = 0;

  FUN_00444100(param_1 + 1);

  ExceptionList = pvStack_c;

  return param_1;

}
