# Raw capture: FUN_0096daa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096daa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0096daa0` |
| **Canonical name** | `FUN_0096daa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0096daa0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0xc))(param_2,param_3);
  FUN_0074c9c0(uVar1,param_2,param_3);
  return;
}
```
