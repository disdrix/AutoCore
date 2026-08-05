// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, while×1, goto×1.
//  - Notable callees: FUN_0054a290×2, CONCAT31, FUN_0054a1a0, FUN_0054a640, FUN_0054b2c0, FUN_0054d780, FUN_007989b0, FUN_00799940.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 4.

// =============================================================================
// Named_VOG_DEBUG_STOP_0054b2c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0054b2c0
// Address:   0x0054b2c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_VOG_DEBUG_STOP_0054b2c0(void)



{

  int *piVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  uint8_t local_30 [4];

  void *local_2c;

  int local_28;

  uint32_t /* width from decompiler */ local_24;

  uint8_t local_20 [20];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4622;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00799940();

  iVar4 = 0;

  local_4 = 0;

  DAT_00b04724 = 1;

  FUN_0054a1a0();

  FUN_0054a640();

  if (DAT_00b04694 == '\0') {

    FUN_0054d780(*(uint32_t /* width from decompiler */ *)(DAT_00b04738 + 4));

    *(int *)(DAT_00b04738 + 4) = DAT_00b04738;

    _DAT_00b0473c = 0;

    *(int *)DAT_00b04738 = DAT_00b04738;

    *(int *)(DAT_00b04738 + 8) = DAT_00b04738;

    local_2c = (void *)0x0;

    local_28 = 0;

    local_24 = 0;

    local_4 = CONCAT31(local_4._1_3_,1);

    iVar2 = FUN_007e34b0(local_30);

    if (iVar2 < 0) {

      FUN_007a4480(0,"VOG_DEBUG_STOP");

LAB_0054b436:

      if (local_2c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(local_2c);

      }

    }

    else {

      uVar3 = 0;

      while (local_2c != (void *)0x0) {

        if ((uint)((local_28 - (int)local_2c) / 0x934) <= uVar3) goto LAB_0054b436;

        FUN_0054a290(iVar4 + (int)local_2c,local_20);

        operator_delete__(*(void **)(iVar4 + 0x930 + (int)local_2c));

        uVar3 = uVar3 + 1;

        iVar4 = iVar4 + 0x934;

      }

    }

    local_2c = (void *)0x0;

    local_28 = 0;

    local_24 = 0;

  }

  else {

    if (DAT_00b0435c != DAT_00b04360) {

      piVar1 = (int *)*DAT_00b0435c;

      if (*piVar1 != -1) {

        FUN_0054a290(piVar1,local_20);

      }

      operator_delete__((void *)piVar1[0x24c]);

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar1);

    }

    if (DAT_00b0435c != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(DAT_00b0435c);

    }

    DAT_00b0435c = (uint32_t /* width from decompiler */ *)0x0;

    DAT_00b04360 = (uint32_t /* width from decompiler */ *)0x0;

    DAT_00b04364 = 0;

  }

  local_4 = 0xffffffff;

  FUN_007989b0();

  ExceptionList = local_c;

  return;

}
