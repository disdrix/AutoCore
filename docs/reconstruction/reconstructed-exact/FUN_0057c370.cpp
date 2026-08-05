// =============================================================================
// FUN_0057c370
// -----------------------------------------------------------------------------
// Stable ID: aa_0057c370
// Address:   0x0057c370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0057c370 @ 0x0057c370
// Stable ID: aa_0057c370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×8, return×7.
//  - Notable callees: FUN_00518ec0, FUN_0057b240, FUN_0057c370.
//  - Return sites: 7.

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

void __fastcall FUN_0057c370(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  

  pvVar1 = (void *)param_1[0x96];

  *param_1 = &PTR_FUN_009d414c;

  if (pvVar1 != (void *)0x0) {

    FUN_0057b240();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0x96] = 0;

  if ((void *)param_1[0x94] != (void *)0x0) {

    operator_delete__((void *)param_1[0x94]);

  }

  param_1[0x94] = 0;

  if ((void *)param_1[0x8b] != (void *)0x0) {

    operator_delete__((void *)param_1[0x8b]);

  }

  param_1[0x8b] = 0;

  if ((void *)param_1[0x91] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x91]);

  }

  param_1[0x91] = 0;

  param_1[0x92] = 0;

  param_1[0x93] = 0;

  if ((void *)param_1[0x8d] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x8d]);

  }

  param_1[0x8d] = 0;

  param_1[0x8e] = 0;

  param_1[0x8f] = 0;

  if ((void *)param_1[0x83] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x83]);

  }

  param_1[0x83] = 0;

  param_1[0x84] = 0;

  param_1[0x85] = 0;

  if ((void *)param_1[0x7a] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x7a]);

  }

  param_1[0x7a] = 0;

  param_1[0x7b] = 0;

  param_1[0x7c] = 0;

  if ((void *)param_1[0x76] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x76]);

  }

  param_1[0x76] = 0;

  param_1[0x77] = 0;

  param_1[0x78] = 0;

  FUN_00518ec0();

  return;

}
