# Raw capture: ClientSpecialEvent_Respawn_dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979c70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00979c70` |
| **Canonical name** | `ClientSpecialEvent_Respawn_dtor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* ClientSpecialEvent_Respawn_dtor — teardown airlift ship, restore camera if local player. */

void __fastcall ClientSpecialEvent_Respawn_dtor(undefined4 *param_1)

{
  int iVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
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
              (*(undefined4 *)(DAT_00d1b644 + 0xe4e8));
    iVar1 = param_1[4];
    if (iVar1 != 0) {
      (*(code *)**(undefined4 **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1))(1);
    }
  }
  if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[5])(1);
  }
  iVar1 = FUN_004bb010(param_1 + 10);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x210))(0);
    if (iVar1 == DAT_00d1b6d8) {
      *(undefined4 *)(DAT_00d1b778 + 0x60c) = param_1[3];
      FUN_0090dd50();
    }
  }
  FUN_00979290();
  *param_1 = &PTR_LAB_00a766f8;
  ExceptionList = pvStack_c;
  return;
}
```
