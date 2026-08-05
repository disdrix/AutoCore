// =============================================================================
// FUN_0072a530
// -----------------------------------------------------------------------------
// Stable ID: aa_0072a530
// Address:   0x0072a530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072a530 @ 0x0072a530
// Stable ID: aa_0072a530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0072a4d0, FUN_0072a530.
//  - Return sites: 2.

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

void __fastcall FUN_0072a530(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ab714;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00aa71c8;

  local_4 = 1;

  FUN_0072a4d0();

  if ((void *)param_1[4] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[4]);

  }

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  *param_1 = &PTR_LAB_009d3a7c;

  ExceptionList = local_c;

  return;

}
