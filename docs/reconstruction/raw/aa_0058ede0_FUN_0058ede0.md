# Raw capture: FUN_0058ede0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058ede0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0058ede0` |
| **Canonical name** | `FUN_0058ede0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0058ede0(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  if (puVar3 != *(undefined4 **)(param_1 + 8)) {
    piVar2 = *(int **)(param_2 + 8);
    do {
      piVar4 = *(int **)(param_2 + 4);
      uVar1 = *puVar3;
      if (piVar4 != piVar2) {
        do {
          (**(code **)(*(int *)(*(int *)(*(int *)(*piVar4 + 4) + 4) + 4 + *piVar4) + 0xe8))(uVar1);
          piVar2 = *(int **)(param_2 + 8);
          piVar4 = piVar4 + 1;
        } while (piVar4 != piVar2);
      }
      puVar3 = puVar3 + 1;
    } while (puVar3 != *(undefined4 **)(param_1 + 8));
  }
  return;
}
```
