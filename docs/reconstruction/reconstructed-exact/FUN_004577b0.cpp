// =============================================================================
// FUN_004577b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004577b0
// Address:   0x004577b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004577b0 @ 0x004577b0
// Stable ID: aa_004577b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: _eh_vector_destructor_iterator_×3, FUN_004577b0.
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

void FUN_004577b0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009bca04;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00aa33a4;

  local_4 = 2;

  _eh_vector_destructor_iterator_(param_1 + 0xd,8,2,FUN_0096f510);

  local_4._0_1_ = 1;

  _eh_vector_destructor_iterator_(param_1 + 9,8,2,FUN_00437640);

  local_4 = (uint)local_4._1_3_ << 8;

  _eh_vector_destructor_iterator_(param_1 + 5,8,2,FUN_00437450);

  *param_1 = &PTR_LAB_00a9db34;

  ExceptionList = local_c;

  return;

}
