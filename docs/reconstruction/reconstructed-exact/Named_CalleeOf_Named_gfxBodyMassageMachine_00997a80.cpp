// =============================================================================
// Named_CalleeOf_Named_gfxBodyMassageMachine_00997a80
// -----------------------------------------------------------------------------
// Stable ID: aa_00997a80
// Callee of Named_gfxBodyMassageMachine
// Address:   0x00997a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBodyMassageMachine: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00748960, FUN_00997a80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxBodyMassageMachine
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_gfxBodyMassageMachine_00997a80(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009af945;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00748960();

  *param_1 = &PTR_FUN_00aa465c;

  param_1[1] = &PTR_LAB_00aa4650;

  param_1[0x32] = 0;

  param_1[0x33] = 0;

  param_1[0x34] = 0;

  param_1[0x35] = 0;

  param_1[0x36] = 0;

  param_1[0x38] = 0;

  param_1[0x39] = 0;

  param_1[0x3a] = 0;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  param_1[0x44] = 0;

  param_1[0x43] = &PTR_FUN_00a9db18;

  param_1[0x2f] = param_1[0x2f] | 10;

  ExceptionList = local_c;

  return param_1;

}
