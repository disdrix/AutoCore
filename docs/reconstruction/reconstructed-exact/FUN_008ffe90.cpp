// =============================================================================
// FUN_008ffe90
// -----------------------------------------------------------------------------
// Stable ID: aa_008ffe90
// Address:   0x008ffe90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ffe90 @ 0x008ffe90
// Stable ID: aa_008ffe90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00792c20, FUN_008ffe90.
//  - Return sites: 3.

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

void __fastcall FUN_008ffe90(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b7bf5;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a33cec;

  local_4 = 1;

  if ((void *)param_1[0x1f5] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x1f5]);

  }

  param_1[0x1f5] = 0;

  param_1[0x1f6] = 0;

  param_1[0x1f7] = 0;

  local_4 = 0;

  if ((void *)param_1[0x1ef] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x1ef]);

  }

  param_1[0x1ef] = 0;

  param_1[0x1f0] = 0;

  param_1[0x1f1] = 0;

  *param_1 = &PTR_FUN_00a58c6c;

  local_4 = 0xffffffff;

  FUN_00792c20();

  ExceptionList = pvStack_c;

  return;

}
