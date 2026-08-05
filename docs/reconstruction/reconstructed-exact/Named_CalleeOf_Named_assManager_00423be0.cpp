// =============================================================================
// Named_CalleeOf_Named_assManager_00423be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00423be0
// Callee of Named_assManager
// Address:   0x00423be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00423be0, FUN_00423cf0, InitializeCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_assManager
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_assManager_00423be0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bd3c8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[1] = 0;

  local_4 = 0;

  *param_1 = &PTR_FUN_00a95acc;

  FUN_00423cf0(param_1 + 2);

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));

  *(uint8_t *)(param_1 + 0x12) = 1;

  ExceptionList = local_c;

  return param_1;

}
