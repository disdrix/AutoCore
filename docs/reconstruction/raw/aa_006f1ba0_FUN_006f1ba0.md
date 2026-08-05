# Raw capture: FUN_006f1ba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006f1ba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006f1ba0` |
| **Canonical name** | `FUN_006f1ba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_006f1ba0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  *param_1 = &PTR_FUN_00a0ee70;
  param_1[2] = &PTR_FUN_00a0ee6c;
  param_1[3] = &PTR_FUN_00a0ee64;
  param_1[4] = &PTR_FUN_00a0ee5c;
  param_1[5] = &PTR_FUN_00a0ee58;
  if (0 < (int)param_1[7]) {
    do {
      puVar1 = *(undefined4 **)(param_1[6] + iVar2 * 4);
      *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;
      if (*(short *)((int)puVar1 + 6) == 0) {
        (**(code **)*puVar1)(1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[7]);
  }
  if (-1 < (int)param_1[8]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[6],param_1[8] << 2,0x12);
  }
  param_1[4] = &PTR_LAB_009d278c;
  param_1[3] = &PTR_LAB_009d2784;
  *param_1 = &PTR_FUN_009d81e8;
  if ((short)*(ushort *)(param_1 + 1) < 0) {
    *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0x7fff;
    FUN_005ffdb0(0);
  }
  *param_1 = &PTR_LAB_009cc290;
  return;
}
```
