// =============================================================================
// FUN_008a5ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_008a5ba0
// Address:   0x008a5ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a5ba0 @ 0x008a5ba0
// Stable ID: aa_008a5ba0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00415e90, FUN_008a2a30, FUN_008a5ba0, _eh_vector_destructor_iterator_.
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

void __fastcall FUN_008a5ba0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b621e;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a4c61c;

  local_4 = 4;

  FUN_008a2a30();

  local_4._0_1_ = 3;

  _eh_vector_destructor_iterator_(param_1 + 0x173,0xc,4,FUN_00402280);

  local_4 = CONCAT31(local_4._1_3_,2);

  FUN_00415e90();

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x171]);

}
