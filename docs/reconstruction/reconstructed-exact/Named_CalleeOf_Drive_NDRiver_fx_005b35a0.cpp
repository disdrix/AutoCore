// =============================================================================
// Named_CalleeOf_Drive_NDRiver_fx_005b35a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b35a0
// Callee of Drive_NDRiver_fx
// Address:   0x005b35a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_NDRiver_fx: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0044b440, FUN_005b35a0, FUN_007560d0, FUN_00972cc0, FUN_00972e50.
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Drive_NDRiver_fx_005b35a0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a67ed;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007560d0();

  local_4 = 0;

  *param_1 = &PTR_FUN_009d95a0;

  FUN_00972cc0();

  param_1[0x57] = param_2;

  param_1[0x56] = 0;

  param_1[0x58] = *(uint32_t /* width from decompiler */ *)(param_2 + 0xe4e8);

  param_1[0x55] = 0;

  param_1[0x54] = 0;

  param_1[0x59] = *(uint32_t /* width from decompiler */ *)(param_2 + 0xe894);

  FUN_0044b440();

  if ((*(byte *)(param_1 + 0x53) & 1) != 0) {

    FUN_00972e50();

  }

  *(uint8_t *)(param_1 + 0x1e) = 1;

  *(uint8_t *)(param_1 + 0x20) = 1;

  ExceptionList = local_c;

  return param_1;

}
