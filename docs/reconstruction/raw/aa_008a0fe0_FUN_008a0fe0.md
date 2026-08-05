# Raw capture: FUN_008a0fe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0fe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008a0fe0` |
| **Canonical name** | `FUN_008a0fe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008a0fe0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  
  FUN_00792250(param_2,param_3);
  if (((char)param_2 != '\0') && (cVar1 = (**(code **)(*param_1 + 0x3d8))(), cVar1 != '\0')) {
    FUN_008a0ed0();
    FUN_008a05a0();
    if (DAT_00d1b6d8 != 0) {
      FUN_008a0770();
    }
  }
  if (((char)param_1[0x148] != '\0') && (param_1[0x199] != 0)) {
    (**(code **)(*(int *)param_1[0x199] + 0xfc))(param_2,param_3);
  }
  return;
}
```
