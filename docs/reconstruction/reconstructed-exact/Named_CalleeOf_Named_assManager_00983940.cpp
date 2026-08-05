// =============================================================================
// Named_CalleeOf_Named_assManager_00983940
// -----------------------------------------------------------------------------
// Stable ID: aa_00983940
// Callee of Named_assManager
// Address:   0x00983940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00469db0, FUN_00983940, InitializeCriticalSection.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int Named_CalleeOf_Named_assManager_00983940(int param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ac8fc;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00469db0(param_1);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));

  *(uint8_t *)(param_1 + 0x50) = 1;

  _DAT_00d1ef44 = 0;

  _DAT_00d1ef48 = 0;

  _DAT_00d1ef50 = 0;

  _DAT_00d1ef5c = 0;

  _DAT_00d1ef58 = 0;

  ExceptionList = local_c;

  return param_1;

}
