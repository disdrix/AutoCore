// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a3400
// -----------------------------------------------------------------------------
// Stable ID: aa_006a3400
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006a3400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00698400×2, CONCAT31, FUN_00697e10, FUN_006a2f30, FUN_006a3170, FUN_006a3400, block.
//  - Return sites: 3.

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

/* WARNING: Removing unreachable block (ram,0x006a349a) */



uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a3400(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,void *param_3)



{

  void *local_18;

  void *local_c;

  uint8_t *puStack_8;

  uint8_t local_4;

  undefined3 uStack_3;

  

  puStack_8 = &LAB_009ab3c8;

  local_c = ExceptionList;

  local_4 = 1;

  uStack_3 = 0;

  ExceptionList = &local_c;

  FUN_00698400(&param_2);

  FUN_006a3170();

  FUN_006a2f30();

  local_4 = 2;

  FUN_00697e10();

  _local_4 = CONCAT31(uStack_3,1);

  if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_18);

  }

  FUN_00698400();

  if (param_3 == (void *)0x0) {

    ExceptionList = local_c;

    return param_1;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(param_3);

}
