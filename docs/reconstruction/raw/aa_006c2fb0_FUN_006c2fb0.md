# Raw capture: FUN_006c2fb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c2fb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c2fb0` |
| **Canonical name** | `FUN_006c2fb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006c2fb0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)param_2[1];
  uVar2 = *param_2;
  uVar3 = param_1[1];
  puVar1[3] = *param_1;
  puVar1[2] = param_3;
  puVar1[4] = uVar3;
  puVar1[5] = param_4;
  *puVar1 = 0x11801;
  puVar1[1] = uVar2;
  param_2[1] = puVar1 + 6;
  return;
}
```
