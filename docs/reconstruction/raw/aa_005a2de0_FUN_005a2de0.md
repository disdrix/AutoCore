# Raw capture: FUN_005a2de0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2de0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005a2de0` |
| **Canonical name** | `FUN_005a2de0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005a2de0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x30);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[4] = *param_4;
    puVar1[5] = param_4[1];
    puVar1[6] = param_4[2];
    puVar1[7] = param_4[3];
    puVar1[8] = param_4[4];
    puVar1[9] = param_4[5];
    *(undefined1 *)(puVar1 + 10) = param_5;
    *(undefined1 *)((int)puVar1 + 0x29) = 0;
  }
  return;
}
```
