# Raw capture: FUN_005a3be0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a3be0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005a3be0` |
| **Canonical name** | `FUN_005a3be0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005a3be0(int param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 uVar1;
  bool bVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_4;
  
  puVar3 = param_3;
  puVar5 = *(undefined4 **)(param_1 + 4);
  bVar2 = true;
  local_4 = 1;
  if (*(char *)((int)puVar5[1] + 0x21) == '\0') {
    puVar4 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar4;
      if (((int)puVar5[5] < (int)param_3[1]) ||
         (((int)puVar5[5] <= (int)param_3[1] && ((uint)puVar5[4] <= *param_3)))) {
        puVar4 = (undefined4 *)puVar5[2];
        bVar2 = false;
        local_4 = 0;
      }
      else {
        puVar4 = (undefined4 *)*puVar5;
        bVar2 = true;
        local_4 = 1;
      }
    } while (*(char *)((int)puVar4 + 0x21) == '\0');
  }
  param_3 = puVar5;
  if (bVar2) {
    if (puVar5 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar5 = (undefined4 *)FUN_005a3500(&param_3,1,puVar5,puVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_2 + 1) = 1;
      *param_2 = uVar1;
      return;
    }
    FUN_005adff0();
  }
  if (((int)param_3[5] <= (int)puVar3[1]) &&
     (((int)param_3[5] < (int)puVar3[1] || (param_3[4] < *puVar3)))) {
    puVar5 = (undefined4 *)FUN_005a3500(&param_3,local_4,puVar5,puVar3);
    *param_2 = *puVar5;
    *(undefined1 *)(param_2 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_2 + 1) = 0;
  *param_2 = param_3;
  return;
}
```
