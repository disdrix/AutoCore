# Raw capture: FUN_008cf7f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008cf7f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008cf7f0` |
| **Canonical name** | `FUN_008cf7f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008cf7f0(undefined4 param_1)

{
  char cVar1;
  int in_EAX;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(in_EAX + 0x794);
  iVar3 = 3;
  do {
    cVar1 = (**(code **)(*(int *)*puVar2 + 0xd8))();
    if (cVar1 != (char)param_1) {
      (**(code **)(*(int *)*puVar2 + 0xd4))(param_1);
      (**(code **)(*(int *)*puVar2 + 0x34c))();
    }
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}
```
