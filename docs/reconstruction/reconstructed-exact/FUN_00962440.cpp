// =============================================================================
// FUN_00962440
// -----------------------------------------------------------------------------
// Stable ID: aa_00962440
// Address:   0x00962440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00962440 @ 0x00962440
// Stable ID: aa_00962440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×6, return×6, for×1.
//  - Notable callees: FUN_00962400, FUN_00962440.
//  - Return sites: 6.

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

void __fastcall FUN_00962440(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac92f;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00aa5fbc;

  local_4 = 3;

  FUN_00962400();

  if ((void *)param_1[3] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[3]);

  }

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  piVar1 = (int *)param_1[8];

  for (piVar2 = (int *)param_1[7]; piVar2 != piVar1; piVar2 = piVar2 + 1) {

    if ((uint32_t /* width from decompiler */ *)*piVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)*piVar2)(1);

    }

  }

  if ((void *)param_1[7] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[7]);

  }

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  if ((void *)param_1[0xb] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xb]);

  }

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  if ((void *)param_1[7] == (void *)0x0) {

    param_1[7] = 0;

    param_1[8] = 0;

    param_1[9] = 0;

    if ((void *)param_1[3] == (void *)0x0) {

      param_1[3] = 0;

      param_1[4] = 0;

      param_1[5] = 0;

      *param_1 = &PTR_LAB_009d3aa0;

      ExceptionList = pvStack_c;

      return;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[3]);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[7]);

}
