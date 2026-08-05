# Raw capture: FUN_0062aff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0062aff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0062aff0` |
| **Canonical name** | `FUN_0062aff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0062aff0(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 local_14 [2];
  int local_10;
  int local_c;
  int local_8;
  
  uVar4 = param_2;
  iVar2 = *(int *)(param_1 + 0x20);
  iVar3 = *(int *)(param_1 + 0x1c);
  local_14[0] = (undefined2)param_2;
  local_10 = param_1;
  local_c = iVar3;
  local_8 = iVar2;
  FUN_0062a610(*(undefined4 *)(param_1 + 8),local_14);
  if (*(int *)(iVar3 + 100) != 0) {
    FUN_006000c0(iVar3,local_14);
  }
  if (*(int *)(iVar2 + 100) != 0) {
    FUN_006000c0(iVar2,local_14);
  }
  FUN_006515a0(uVar4);
  if (*(int *)(param_1 + 0xa4) == 0) {
    uVar1 = *(undefined1 *)(*(int *)(param_1 + 8) + 300);
    *(undefined1 *)(*(int *)(param_1 + 8) + 300) = 0;
    FUN_0055e860(&param_2,param_1 + 0x10);
    *(undefined1 *)(*(int *)(param_1 + 8) + 300) = uVar1;
  }
  return;
}
```
