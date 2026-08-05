// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_0075d470
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d470
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
// Address:   0x0075d470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_0043bdf0, FUN_005ae2b0, FUN_0075d3c0, FUN_0075d470, InitializeCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_0075d470(int param_1)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009acd33;

  local_c = ExceptionList;

  DAT_00d1f050 = param_1;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_0043bdf0(param_1);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x3c));

  *(uint8_t *)(param_1 + 0x54) = 1;

  local_4._0_1_ = 2;

  iVar1 = FUN_005ae2b0();

  *(int *)(param_1 + 0x5c) = iVar1;

  *(uint8_t *)(iVar1 + 0x19) = 1;

  *(int *)(*(int *)(param_1 + 0x5c) + 4) = *(int *)(param_1 + 0x5c);

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c);

  *(int *)(*(int *)(param_1 + 0x5c) + 8) = *(int *)(param_1 + 0x5c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

  local_4 = CONCAT31(local_4._1_3_,3);

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  *(uint8_t *)(param_1 + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  FUN_0075d3c0(param_1);

  ExceptionList = local_c;

  return param_1;

}
