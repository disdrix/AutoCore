// =============================================================================
// FUN_004068f0  (canonical: LogicUiEventQueue_InsertOne_GrowPath)
// -----------------------------------------------------------------------------
// Stable ID: aa_004068f0
// Address:   0x004068f0 – 0x00406964  (autoassault.exe, image base 0x400000)
// System:    client-logic-ui / event queue
// Generated: 2026-07-29 W22-I dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named plate: reconstructed-exact/LogicUiEventQueue_InsertOne_GrowPath.cpp
// =============================================================================

// PURPOSE: Index-preserving grow-insert of one 0x138 Logic-UI event slot.
// Caller: Client_SendLogicUiPacket capacity miss → this path.
// Callee: FUN_004076a0 insert-N (count=1).

void __thiscall FUN_004068f0(int param_1, int *param_2, int param_3, uint32_t param_4)
{
  int iVar1;

  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    if ((*(int *)(param_1 + 8) - iVar1) / 0x138 != 0) {
      iVar1 = (param_3 - iVar1) / 0x138;
      goto LAB_00406939;
    }
  }
  iVar1 = 0;
LAB_00406939:
  FUN_004076a0(param_3, 1, param_4);
  *param_2 = *(int *)(param_1 + 4) + iVar1 * 0x138;
  return;
}
