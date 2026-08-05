// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00693d60
// -----------------------------------------------------------------------------
// Stable ID: aa_00693d60
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00693d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00691720, FUN_00691d80, FUN_00693bc0, FUN_00693d60.
//  - Return sites: 2.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00693d60(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,void *param_5,

                 uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,uint32_t /* width from decompiler */ param_9,

                 uint8_t param_10,uint32_t /* width from decompiler */ param_11,uint32_t /* width from decompiler */ param_12,uint32_t /* width from decompiler */ param_13,

                 uint32_t /* width from decompiler */ param_14,uint32_t /* width from decompiler */ param_15,uint32_t /* width from decompiler */ param_16)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009aa7b8;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_00691d80();

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

  *(uint8_t *)(param_3 + 0x18) = *(uint8_t *)(param_1 + 0x18);

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x28) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

  FUN_00691720(&param_4);

  FUN_00693bc0(param_1,0,(param_2 - param_1) / 0x30);

  if (param_5 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_5);

  }

  ExceptionList = local_c;

  return;

}
