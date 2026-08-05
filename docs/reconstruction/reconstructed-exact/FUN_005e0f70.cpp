// =============================================================================
// FUN_005e0f70
// -----------------------------------------------------------------------------
// Stable ID: aa_005e0f70
// Address:   0x005e0f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e0f70 @ 0x005e0f70
// Stable ID: aa_005e0f70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: _eh_vector_destructor_iterator_×3, FUN_005e0f70, FUN_005e1990.
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

void __fastcall FUN_005e0f70(int param_1)



{

  int local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a7466;

  pvStack_c = ExceptionList;

  local_4 = 2;

  ExceptionList = &pvStack_c;

  local_10 = param_1;

  _eh_vector_destructor_iterator_((void *)(param_1 + 0x10e00c),0x10,12000,FUN_00691630);

  local_4._0_1_ = 1;

  _eh_vector_destructor_iterator_((void *)(param_1 + 0x8700c),0x10,0x8700,FUN_00691630);

  local_4 = (uint)local_4._1_3_ << 8;

  _eh_vector_destructor_iterator_((void *)(param_1 + 0xc),0x10,0x8700,FUN_00691630);

  local_4 = 0xffffffff;

  FUN_005e1990(&local_10,**(uint32_t /* width from decompiler */ **)(param_1 + 4),*(uint32_t /* width from decompiler */ **)(param_1 + 4));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 4));

}
