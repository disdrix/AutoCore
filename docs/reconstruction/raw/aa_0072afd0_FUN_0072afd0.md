# Raw capture: FUN_0072afd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0072afd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0072afd0` |
| **Canonical name** | `FUN_0072afd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0072afd0(undefined4 *param_1,undefined4 *param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (*(int *)(in_EAX + 0x10) != 0) {
    puVar1 = operator_new__(*(int *)(in_EAX + 0x10) * 0xc);
    *(undefined4 **)(in_EAX + 0x14) = puVar1;
    for (uVar2 = (uint)(*(int *)(in_EAX + 0x10) * 0xc) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar1 = *param_1;
      param_1 = param_1 + 1;
      puVar1 = puVar1 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar1 = *(undefined1 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      puVar1 = (undefined4 *)((int)puVar1 + 1);
    }
  }
  if (*(int *)(in_EAX + 0xc) != 0) {
    puVar1 = operator_new__(*(int *)(in_EAX + 0xc) * 6);
    *(undefined4 **)(in_EAX + 0x18) = puVar1;
    uVar2 = *(int *)(in_EAX + 0xc) * 6;
    for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar1 = *param_2;
      param_2 = param_2 + 1;
      puVar1 = puVar1 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar1 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      puVar1 = (undefined4 *)((int)puVar1 + 1);
    }
  }
  return;
}
```
