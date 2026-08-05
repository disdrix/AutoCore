// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_008050a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008050a0
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x008050a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_008050a0, FUN_00805370.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_008050a0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad0f3;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00805370(param_1);

  *param_1 = &PTR_FUN_00a7fc6c;

  param_1[0x1e] = 0;

  param_1[0x1f] = 0;

  param_1[0x20] = 0;

  param_1[0x1c] = 0;

  param_1[0x24] = 0;

  param_1[0x23] = 0x80;

  param_1[0x22] = 0xffffffff;

  param_1[0x21] = 0xffffffff;

  param_1[0x27] = 0;

  param_1[0x28] = 0;

  param_1[0x29] = 0;

  param_1[0x2a] = 0;

  param_1[0x2b] = 0;

  param_1[0x2c] = 0;

  param_1[0x25] = 0;

  ExceptionList = local_c;

  return param_1;

}
