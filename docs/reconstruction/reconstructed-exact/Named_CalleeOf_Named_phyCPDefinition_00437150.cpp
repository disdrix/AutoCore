// =============================================================================
// Named_CalleeOf_Named_phyCPDefinition_00437150
// -----------------------------------------------------------------------------
// Stable ID: aa_00437150
// Callee of Named_phyCPDefinition
// Address:   0x00437150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_phyCPDefinition: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00437150.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_phyCPDefinition
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

void Named_CalleeOf_Named_phyCPDefinition_00437150(int *param_1)



{

  int *piVar1;

  int *piVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bc278;

  pvStack_c = ExceptionList;

  local_4 = 0;

  piVar2 = (int *)*param_1;

  ExceptionList = &pvStack_c;

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    ExceptionList = &pvStack_c;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    *param_1 = 0;

  }

  local_4 = 0xffffffff;

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    piVar2 = param_1 + 1;

    *piVar2 = *piVar2 + -1;

    if (*piVar2 == 0) {

      (**(code **)(*param_1 + 8))();

    }

  }

  ExceptionList = pvStack_c;

  return;

}
