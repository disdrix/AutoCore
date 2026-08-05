# Raw capture: FUN_0068bee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068bee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0068bee0` |
| **Canonical name** | `FUN_0068bee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0068bee0(int param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (param_2 != 0) {
    if (0x3fffffff < param_2) {
      FUN_00418130();
    }
    puVar1 = operator_new(param_2 * 4);
    *(undefined4 **)(param_1 + 0xc) = puVar1 + param_2;
    *(undefined4 **)(param_1 + 4) = puVar1;
    *(undefined4 **)(param_1 + 8) = puVar1;
    puVar2 = puVar1;
    for (uVar3 = param_2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar2 = *param_3;
      puVar2 = puVar2 + 1;
    }
    *(undefined4 **)(param_1 + 8) = puVar1 + param_2;
  }
  return;
}
```
