# Raw capture: FUN_0040ebd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ebd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040ebd0` |
| **Canonical name** | `FUN_0040ebd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0040ebd0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*param_1 != 0) {
    uVar1 = FUN_0096be60(param_2,param_3,0,4);
    return uVar1;
  }
  return 0;
}
```
