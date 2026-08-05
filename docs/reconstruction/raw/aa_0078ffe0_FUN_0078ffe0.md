# Raw capture: FUN_0078ffe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078ffe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0078ffe0` |
| **Canonical name** | `FUN_0078ffe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0078ffe0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if (cVar1 != '\0') {
    if (param_1[0x12f] != 0) {
      (**(code **)(*(int *)param_1[0x12f] + 0x35c))(param_2,param_3);
    }
    return 1;
  }
  return 0;
}
```
