# Raw capture: FUN_005fe8c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe8c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fe8c0` |
| **Canonical name** | `FUN_005fe8c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_005fe8c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_005c8030(param_2,param_3,param_4);
  if (-1 < iVar1) {
    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) + 0xc))();
    iVar1 = 0;
  }
  return iVar1;
}
```
