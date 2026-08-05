# Raw capture: FUN_0046deb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046deb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0046deb0` |
| **Canonical name** | `FUN_0046deb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0046deb0(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float10 fVar5;
  float10 fVar6;
  
  puVar2 = param_1;
  if (param_1 != param_2) {
    while (puVar2 = puVar2 + 1, puVar2 != param_2) {
      piVar1 = *(int **)*param_1;
      fVar5 = (float10)(**(code **)(**(int **)*puVar2 + 0x10))();
      fVar6 = (float10)(**(code **)(*piVar1 + 0x10))();
      puVar3 = puVar2;
      if ((float10)(float)fVar5 < fVar6 - (float10)DAT_00aaa620) {
        do {
          puVar4 = puVar3;
          piVar1 = *(int **)puVar4[-1];
          fVar5 = (float10)(**(code **)(**(int **)*puVar2 + 0x10))();
          fVar6 = (float10)(**(code **)(*piVar1 + 0x10))();
          puVar3 = puVar4 + -1;
        } while (fVar6 - (float10)DAT_00aaa620 <= (float10)(float)fVar5);
        if ((puVar4 != puVar2) && (puVar2 != puVar2 + 1)) {
          FUN_00468970(puVar4,puVar2,puVar2 + 1);
        }
      }
      else if ((param_1 != puVar2) && (puVar2 != puVar2 + 1)) {
        FUN_00468970(param_1,puVar2,puVar2 + 1);
      }
    }
  }
  return;
}
```
