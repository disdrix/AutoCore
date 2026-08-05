# Raw capture: FUN_0059dcc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059dcc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0059dcc0` |
| **Canonical name** | `FUN_0059dcc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0059dcc0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x53] = param_3;
  puVar2 = param_1 + 3;
  for (iVar1 = 0x50; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[0x54] = 0;
  param_1[0x59] = 0;
  return;
}
```
