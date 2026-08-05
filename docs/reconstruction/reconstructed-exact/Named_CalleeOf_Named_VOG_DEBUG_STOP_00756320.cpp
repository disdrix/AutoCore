// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00756320
// -----------------------------------------------------------------------------
// Stable ID: aa_00756320
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x00756320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00442c80, FUN_00756320, FUN_00986070.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_00756320(int param_1,uint param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  void *pvVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009afd8d;

  local_c = ExceptionList;

  if ((*(int *)(param_1 + 4) != 0) || (*(int *)(param_1 + 8) != 0)) {

    return 0xffffffff;

  }

  ExceptionList = &local_c;

  if ((param_2 & 1) != 0) {

    ExceptionList = &local_c;

    uVar1 = FUN_00986070();

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = uVar1;

  }

  pvVar2 = operator_new(0x14);

  local_4 = 0;

  if (pvVar2 != (void *)0x0) {

    uVar1 = FUN_00442c80(pvVar2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar1;

    ExceptionList = local_c;

    return 0;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  ExceptionList = local_c;

  return 0;

}
