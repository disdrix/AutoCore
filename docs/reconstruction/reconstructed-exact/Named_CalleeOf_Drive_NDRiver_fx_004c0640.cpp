// =============================================================================
// Named_CalleeOf_Drive_NDRiver_fx_004c0640
// -----------------------------------------------------------------------------
// Stable ID: aa_004c0640
// Callee of Drive_NDRiver_fx
// Address:   0x004c0640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_NDRiver_fx: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0096f530×2, CONCAT31, FUN_004c0640, FUN_007560d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_NDRiver_fx
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Drive_NDRiver_fx_004c0640(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a19c6;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007560d0();

  local_4 = 0;

  *param_1 = &PTR_FUN_009cb62c;

  *(uint8_t *)(param_1 + 0x20) = 1;

  FUN_0096f530();

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_0096f530();

  param_1[0x25] = 0;

  param_1[0x26] = 0;

  param_1[0x27] = 0;

  param_1[0x28] = param_2;

  param_1[0x29] = *(uint32_t /* width from decompiler */ *)(param_2 + 0xe4e8);

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 0xe894);

  param_1[0x2b] = 0;

  param_1[0x2c] = 0;

  param_1[0x2d] = 0;

  param_1[0x2f] = 0;

  param_1[0x30] = 0;

  param_1[0x31] = 0;

  param_1[0x2a] = uVar1;

  DAT_00b03790 = param_1;

  *(uint8_t *)(param_1 + 0x1e) = 0;

  ExceptionList = local_c;

  return param_1;

}
