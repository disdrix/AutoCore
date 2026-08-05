// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_Setup_of_CNDA_0046e310
// -----------------------------------------------------------------------------
// Stable ID: aa_0046e310
// Callee of Named_CalleeOf_Named_CalleeOf_Auth_Setup_of_CNDAuthClient_faile
// Address:   0x0046e310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Auth_Setup_of_CNDAuthClient_faile: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00439770, FUN_0046e310, FUN_005ae2b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Auth_Setup_of_CNDAuthClient_faile
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_Setup_of_CNDA_0046e310(int param_1)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bdbb8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar1 = FUN_00439770();

  *(int *)(param_1 + 4) = iVar1;

  *(uint8_t *)(iVar1 + 0x15) = 1;

  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  local_4 = 0;

  iVar1 = FUN_005ae2b0();

  *(int *)(param_1 + 0x10) = iVar1;

  *(uint8_t *)(iVar1 + 0x19) = 1;

  *(int *)(*(int *)(param_1 + 0x10) + 4) = *(int *)(param_1 + 0x10);

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  *(int *)(*(int *)(param_1 + 0x10) + 8) = *(int *)(param_1 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  ExceptionList = local_c;

  return param_1;

}
