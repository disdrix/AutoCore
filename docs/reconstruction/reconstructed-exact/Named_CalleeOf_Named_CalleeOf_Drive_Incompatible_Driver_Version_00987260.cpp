// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Incompatible_Driver_Version_00987260
// -----------------------------------------------------------------------------
// Stable ID: aa_00987260
// Callee of Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive
// Address:   0x00987260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00439770, FUN_00462f80, FUN_00987260.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive
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

int Named_CalleeOf_Named_CalleeOf_Drive_Incompatible_Driver_Version_00987260(int param_1)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aca24;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar1 = FUN_00462f80();

  *(int *)(param_1 + 4) = iVar1;

  *(uint8_t *)(iVar1 + 0x21) = 1;

  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  DAT_00d1f650 = param_1;

  local_4 = 1;

  iVar1 = FUN_00439770();

  *(int *)(param_1 + 0x14) = iVar1;

  *(uint8_t *)(iVar1 + 0x15) = 1;

  *(int *)(*(int *)(param_1 + 0x14) + 4) = *(int *)(param_1 + 0x14);

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

  *(int *)(*(int *)(param_1 + 0x14) + 8) = *(int *)(param_1 + 0x14);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  ExceptionList = local_c;

  return param_1;

}
