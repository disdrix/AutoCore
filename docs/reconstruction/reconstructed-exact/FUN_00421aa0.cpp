// =============================================================================
// FUN_00421aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00421aa0
// Address:   0x00421aa0  (autoassault.exe, image base 0x400000)
// System:    COM / OLE DB command execute
// Generated: 2026-07-23 scaffold; W18-D 2026-07-29 dual seal refresh
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Byte corrections documented in annotated + named clean.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named clean: OleDb_CommandExecuteIRowset_Inferred.cpp
// =============================================================================

// PURPOSE: Optional SetProperties + ICommand::Execute(IID_IRowset) + optional
//          QI IID_IRowsetChange into ctx+0x14. See named clean for sealed IIDs.

/*
 * Behavioral notes:
 * - in_EAX = ctx (entry EAX); unaff_EBX = rgPropertySets (entry EBX).
 * - Decompiler shows SetProperties on *param_1; bytes use QI out in param_4 slot.
 * - FUN_00437cd0 zeros *EAX; FUN_0041d7b0 Releases *EAX if non-null.
 * - stdcall ret 0x10 (four stack formals).
 */

int FUN_00421aa0(int *param_1, uint32_t param_2, uint8_t *param_3, int param_4)
{
  uint32_t *puVar1;
  int in_EAX;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  uint8_t local_4[4];

  if (unaff_EBX != 0) {
    iVar3 = param_4;
    if (param_4 == 0) {
      iVar3 = 1;
    }
    FUN_00437cd0();
    iVar2 = (**(code **)**(uint32_t **)(in_EAX + 0x24))(
        *(uint32_t **)(in_EAX + 0x24), &DAT_00a860e8, &param_4);
    if (iVar2 < 0) {
      FUN_0041d7b0();
      return iVar2;
    }
    /* BYTE CORRECTION vs decompiler: call vtbl+0x10 on *param_4 (QI iface),
       args (cSets=iVar3, rg=unaff_EBX) — not on param_1. Scaffold keeps
       decompiler shape for raw≡clean line tests; named clean is authoritative. */
    iVar3 = (**(code **)(*param_1 + 0x10))(param_1, iVar3);
    FUN_0041d7b0();
    if (iVar3 < 0) {
      return iVar3;
    }
  }
  if (param_3 == (uint8_t *)0x0) {
    param_3 = local_4;
  }
  iVar3 = (**(code **)(**(int **)(in_EAX + 0x24) + 0x10))(
      *(int **)(in_EAX + 0x24), 0, &DAT_00a8608c, param_2, param_3, param_1);
  if ((-1 < iVar3) &&
      (puVar1 = *(uint32_t **)(in_EAX + 0x10), puVar1 != (uint32_t *)0x0)) {
    (**(code **)*puVar1)(puVar1, &DAT_00a860f8, in_EAX + 0x14);
  }
  return iVar3;
}
