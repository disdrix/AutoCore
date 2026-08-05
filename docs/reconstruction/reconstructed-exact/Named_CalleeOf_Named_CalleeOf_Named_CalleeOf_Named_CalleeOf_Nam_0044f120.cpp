// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0044f120
// -----------------------------------------------------------------------------
// Stable ID: aa_0044f120
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0044f120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_0044f120.
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0044f120(int *param_1,int param_2,int *param_3)



{

  int *piVar1;

  void *local_10;

  uint8_t *puStack_c;

  uint8_t local_8;

  undefined3 uStack_7;

  

  puStack_c = &LAB_009bdf31;

  local_10 = ExceptionList;

  uStack_7 = 0;

  ExceptionList = &local_10;

  for (; param_2 != 0; param_2 = param_2 + -1) {

    local_8 = 1;

    if (param_3 != (int *)0x0) {

      piVar1 = (int *)*param_1;

      if ((piVar1 != (int *)0x0) && (piVar1[1] = piVar1[1] + 1, piVar1[1] == 1)) {

        (**(code **)(*piVar1 + 4))();

      }

      *param_3 = *param_1;

      *(short *)(param_3 + 1) = (short)param_1[1];

      *(uint16_t *)((int)param_3 + 6) = *(uint16_t *)((int)param_1 + 6);

    }

    param_3 = param_3 + 2;

  }

  ExceptionList = local_10;

  return;

}
