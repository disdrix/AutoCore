// =============================================================================
// Named_CalleeOf_Drive_NDRiver_fx_0055c8c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055c8c0
// Callee of Drive_NDRiver_fx
// Address:   0x0055c8c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_NDRiver_fx: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0055c8c0, FUN_007560d0, FUN_0096f530.
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Drive_NDRiver_fx_0055c8c0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4938;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007560d0();

  local_4 = 0;

  *param_1 = &PTR_FUN_009d26ac;

  *(uint8_t *)(param_1 + 0x20) = 1;

  FUN_0096f530();

  param_1[0x23] = 0;

  param_1[0x24] = 0;

  param_1[0x25] = param_2;

  param_1[0x26] = *(uint32_t /* width from decompiler */ *)(param_2 + 0xe4e8);

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 0xe894);

  *(uint8_t *)(param_1 + 0x1e) = 0;

  param_1[0x27] = uVar1;

  ExceptionList = local_c;

  return param_1;

}
