// =============================================================================
// ClientSpecialEvent_Respawn_dtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00979c70
// Address:   0x00979c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* ClientSpecialEvent_Respawn_dtor - teardown airlift ship, restore camera if local player. */



void __fastcall ClientSpecialEvent_Respawn_dtor(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bba08;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_ClientSpecialEvent_Respawn_Update_00a76720;

  local_4 = 0;

  if (param_1[4] != 0) {

    if ((*(int *)(param_1[4] + 8) != 0) && (param_1[5] != 0)) {

      FUN_0096d550(param_1[5]);

    }

    iVar1 = param_1[4];

    if (iVar1 != 0) {

      iVar1 = *(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1;

    }

    FUN_00944d50(iVar1);

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1[4] + 4) + 4) + 4 + param_1[4]) + 0x2a8))

              (*(uint32_t /* width from decompiler */ *)(DAT_00d1b644 + 0xe4e8));

    iVar1 = param_1[4];

    if (iVar1 != 0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1))(1);

    }

  }

  if ((uint32_t /* width from decompiler */ *)param_1[5] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[5])(1);

  }

  iVar1 = FUN_004bb010(param_1 + 10);

  if (iVar1 != 0) {

    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x210))(0);

    if (iVar1 == DAT_00d1b6d8) {

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b778 + 0x60c) = param_1[3];

      FUN_0090dd50();

    }

  }

  FUN_00979290();

  *param_1 = &PTR_LAB_00a766f8;

  ExceptionList = pvStack_c;

  return;

}
