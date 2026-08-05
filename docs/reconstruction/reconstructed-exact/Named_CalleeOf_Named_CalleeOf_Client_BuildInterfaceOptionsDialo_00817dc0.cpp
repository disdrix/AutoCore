// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_BuildInterfaceOptionsDialo_00817dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00817dc0
// Callee of Named_CalleeOf_Client_BuildInterfaceOptionsDialog
// Address:   0x00817dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_BuildInterfaceOptionsDialog: UI/dialog helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, FUN_00817dc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_BuildInterfaceOptionsDialog
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Client_BuildInterfaceOptionsDialo_00817dc0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b41b5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  *param_1 = &PTR_FUN_00a7a874;

  *(uint8_t *)(param_1 + 0x13f) = 0;

  param_1[0x180] = 0;

  ExceptionList = local_c;

  return param_1;

}
