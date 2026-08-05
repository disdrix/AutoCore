// =============================================================================
// Named_CalleeOf_Named_phyBoundingVolumeFactory_00467600
// -----------------------------------------------------------------------------
// Stable ID: aa_00467600
// Callee of Named_phyBoundingVolumeFactory
// Address:   0x00467600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_phyBoundingVolumeFactory: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00467600, FUN_00972cc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_phyBoundingVolumeFactory
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

int Named_CalleeOf_Named_phyBoundingVolumeFactory_00467600(uint32_t /* width from decompiler */ *param_1)



{

  int extraout_EDX;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009bdc78;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[1] = 0;

  *param_1 = &PTR_FUN_00aa5c3c;

  *(uint8_t *)(param_1 + 2) = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  FUN_00972cc0();

  *(uint8_t *)(extraout_EDX + 0xf0) = 0;

  ExceptionList = local_c;

  return extraout_EDX;

}
