// =============================================================================
// Named_CalleeOf_Named_generator_00685620
// -----------------------------------------------------------------------------
// Stable ID: aa_00685620
// Callee of Named_generator (+1 other named callers)
// Address:   0x00685620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_generator: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_generator (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00680c30, FUN_00680c50, FUN_00685050, FUN_00685620, thunk_FUN_0076c4d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_generator (+1 other named callers)
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

void Named_CalleeOf_Named_generator_00685620(void)



{

  uint8_t local_34 [4];

  uint32_t /* width from decompiler */ local_30;

  uint8_t local_2c;

  uint8_t local_2b;

  uint16_t local_2a;

  uint8_t local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9c5e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00680c30();

  local_4 = 0;

  local_30 = 0;

  local_2b = 0;

  local_2a = 0;

  local_2c = 2;

  FUN_00685050(local_28,&local_30,local_34);

  thunk_FUN_0076c4d0();

  local_4 = 0xffffffff;

  FUN_00680c50();

  ExceptionList = local_c;

  return;

}
