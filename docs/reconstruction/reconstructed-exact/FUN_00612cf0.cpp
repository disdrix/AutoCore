// =============================================================================
// FUN_00612cf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00612cf0
// Address:   0x00612cf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00612cf0 @ 0x00612cf0
// Stable ID: aa_00612cf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00612cf0, FUN_00637dc0.
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

void __fastcall FUN_00612cf0(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_009e1854;

  if ((void *)param_1[0x10] != (void *)0x0) {

    operator_delete__((void *)param_1[0x10]);

  }

  param_1[0x10] = 0;

  if ((void *)param_1[9] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[9]);

  }

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  if ((void *)param_1[5] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[5]);

  }

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  FUN_00637dc0();

  return;

}
