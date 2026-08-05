// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004563c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004563c0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004563c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004563c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004563c0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bdcb1;

  local_c = ExceptionList;

  local_4 = 0;

  if (param_1 != (uint32_t /* width from decompiler */ *)0x0) {

    if (param_2 == 0) {

      piVar2 = (int *)0x0;

    }

    else {

      piVar2 = (int *)(param_2 + 4);

    }

    piVar1 = (int *)*piVar2;

    if ((piVar1 != (int *)0x0) &&

       (ExceptionList = &local_c, piVar1[1] = piVar1[1] + 1, piVar1[1] == 1)) {

      (**(code **)(*piVar1 + 4))();

    }

    param_1[1] = *piVar2;

    *param_1 = &PTR_FUN_00a9db18;

  }

  ExceptionList = local_c;

  return;

}
