// =============================================================================
// FUN_0081aa50
// -----------------------------------------------------------------------------
// Stable ID: aa_0081aa50
// Address:   0x0081aa50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0081aa50 @ 0x0081aa50
// Stable ID: aa_0081aa50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_008186f0, FUN_0081aa50.
//  - Return sites: 4.

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

void __fastcall FUN_0081aa50(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b8389;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a79cbc;

  local_4 = 2;

  if ((void *)param_1[0x3ca] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x3ca]);

  }

  param_1[0x3ca] = 0;

  param_1[0x3cb] = 0;

  param_1[0x3cc] = 0;

  local_4 = 1;

  if ((void *)param_1[0x3c3] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x3c3]);

  }

  param_1[0x3c3] = 0;

  param_1[0x3c4] = 0;

  param_1[0x3c5] = 0;

  local_4 = 0;

  if ((void *)param_1[0x3bf] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x3bf]);

  }

  param_1[0x3bf] = 0;

  param_1[0x3c0] = 0;

  param_1[0x3c1] = 0;

  local_4 = 0xffffffff;

  FUN_008186f0();

  ExceptionList = pvStack_c;

  return;

}
