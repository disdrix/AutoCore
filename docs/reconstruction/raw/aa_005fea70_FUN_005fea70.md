# Raw capture: FUN_005fea70

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fea70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fea70` |
| **Canonical name** | `FUN_005fea70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_005fea70(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  FUN_004ce940();
  puVar1 = (undefined4 *)FUN_00508b10(param_2);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(param_1 + -0xe0,param_3,0);
    return 1;
  }
  return 0;
}
```
