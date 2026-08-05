# Raw capture: FUN_006efd10

| Field | Value |
|---|---|
| **Stable ID** | `aa_006efd10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006efd10` |
| **Canonical name** | `FUN_006efd10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006efd10(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  *param_1 = &PTR_FUN_009e5fdc;
  *(undefined2 *)((int)param_1 + 6) = 1;
  param_1[2] = *param_2;
  *param_1 = &PTR_FUN_00a0ed24;
  iVar1 = param_2[2];
  iVar2 = 0;
  param_1[3] = iVar1;
  if (0 < iVar1) {
    puVar4 = param_1 + 6;
    do {
      puVar3 = (undefined4 *)((int)puVar4 + param_2[1] + (-0x18 - (int)param_1));
      puVar4[-2] = *puVar3;
      puVar4[-1] = puVar3[1];
      *puVar4 = puVar3[2];
      puVar4[1] = puVar3[3];
      iVar2 = iVar2 + 1;
      puVar4 = puVar4 + 4;
    } while (iVar2 < (int)param_1[3]);
  }
  return;
}
```
