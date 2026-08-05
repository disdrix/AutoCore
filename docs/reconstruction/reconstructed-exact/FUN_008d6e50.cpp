// =============================================================================
// FUN_008d6e50
// -----------------------------------------------------------------------------
// Stable ID: aa_008d6e50
// Address:   0x008d6e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d6e50 @ 0x008d6e50
// Stable ID: aa_008d6e50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×8, return×8, do×2, while×2.
//  - Notable callees: CONCAT31×6, FUN_00792c20, FUN_008d6e50.
//  - Return sites: 8.

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

void __fastcall FUN_008d6e50(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int local_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009ba165;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a3f2b4;

  local_4 = 7;

  puVar2 = param_1 + 0x17a;

  local_14 = 3;

  do {

    iVar1 = 5;

    do {

      if ((void *)*puVar2 != (void *)0x0) {

        operator_delete__((void *)*puVar2);

      }

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

    local_14 = local_14 + -1;

  } while (local_14 != 0);

  local_4 = CONCAT31(local_4._1_3_,6);

  if ((void *)param_1[0x238] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x238]);

  }

  param_1[0x238] = 0;

  param_1[0x239] = 0;

  param_1[0x23a] = 0;

  local_4 = CONCAT31(local_4._1_3_,5);

  if ((void *)param_1[0x234] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x234]);

  }

  param_1[0x234] = 0;

  param_1[0x235] = 0;

  param_1[0x236] = 0;

  local_4 = CONCAT31(local_4._1_3_,4);

  if ((void *)param_1[0x230] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x230]);

  }

  param_1[0x230] = 0;

  param_1[0x231] = 0;

  param_1[0x232] = 0;

  local_4 = CONCAT31(local_4._1_3_,3);

  if ((void *)param_1[0x22c] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x22c]);

  }

  param_1[0x22c] = 0;

  param_1[0x22d] = 0;

  param_1[0x22e] = 0;

  local_4 = CONCAT31(local_4._1_3_,2);

  if ((void *)param_1[0x228] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x228]);

  }

  param_1[0x228] = 0;

  param_1[0x229] = 0;

  param_1[0x22a] = 0;

  local_4 = CONCAT31(local_4._1_3_,1);

  if ((void *)param_1[0x224] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x224]);

  }

  param_1[0x224] = 0;

  param_1[0x225] = 0;

  param_1[0x226] = 0;

  local_4 = (uint)local_4._1_3_ << 8;

  if ((void *)param_1[0x220] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x220]);

  }

  param_1[0x220] = 0;

  param_1[0x221] = 0;

  param_1[0x222] = 0;

  *param_1 = &PTR_FUN_00a3ee5c;

  *param_1 = &PTR_FUN_00a58c6c;

  local_4 = 0xffffffff;

  FUN_00792c20();

  ExceptionList = pvStack_c;

  return;

}
