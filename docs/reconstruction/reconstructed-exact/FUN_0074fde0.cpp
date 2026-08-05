// =============================================================================
// FUN_0074fde0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074fde0
// Address:   0x0074fde0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074fde0 @ 0x0074fde0
// Stable ID: aa_0074fde0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT31, FUN_00445a90, FUN_0073d9b0, FUN_0074f4d0, FUN_0074fde0, _eh_vector_destructor_iterator_.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_0074fde0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ada5f;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00a9fa78;

  param_1[1] = &PTR_LAB_00a9fa68;

  local_4 = 3;

  if (DAT_00d1f61c != 0) {

    FUN_0073d9b0(param_1);

  }

  FUN_0074f4d0();

  local_4 = CONCAT31(local_4._1_3_,2);

  _eh_vector_destructor_iterator_(param_1 + 0xf,0x10,0x19,FUN_00691630);

  FUN_00445a90();

  param_1[1] = &PTR_LAB_009d45f0;

  *param_1 = &PTR_LAB_00a9a9bc;

  ExceptionList = local_c;

  return;

}
