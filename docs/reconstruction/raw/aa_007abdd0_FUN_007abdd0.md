# Raw capture: FUN_007abdd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007abdd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007abdd0` |
| **Canonical name** | `FUN_007abdd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_007abdd0(int *param_1,undefined4 *param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  (**(code **)(*param_1 + 0x68))();
  *(undefined1 *)((int)param_1 + 0xbd) = param_3;
  param_1[0xad] = (int)param_2;
  if (param_2 != (undefined4 *)0x0) {
    (**(code **)*param_2)(param_1[0xa6]);
    uVar1 = (**(code **)(*param_1 + 0x1a0))();
    *(undefined4 *)(param_1[0xad] + 4) = uVar1;
  }
  return;
}
```
