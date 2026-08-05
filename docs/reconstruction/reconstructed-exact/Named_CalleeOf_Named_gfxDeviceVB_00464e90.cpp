// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_00464e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00464e90
// Callee of Named_gfxDeviceVB
// Address:   0x00464e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00464e90, FUN_007399d0, FUN_00748960.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceVB
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_gfxDeviceVB_00464e90(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bf092;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00748960();

  *param_1 = &PTR_FUN_00aa479c;

  param_1[1] = &PTR_LAB_00aa4790;

  param_1[0x32] = 0;

  param_1[0x31] = &PTR_FUN_00a9da78;

  param_1[0x35] = 0;

  param_1[0x36] = 0;

  param_1[0x37] = 0;

  param_1[0x39] = 0;

  param_1[0x38] = &PTR_FUN_00a9db18;

  local_4 = 3;

  FUN_007399d0(param_2);

  ExceptionList = local_c;

  return param_1;

}
