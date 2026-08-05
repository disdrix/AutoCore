# Raw capture: FUN_004c3af0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3af0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c3af0` |
| **Canonical name** | `FUN_004c3af0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
FUN_004c3af0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + -0x2b0);
  if (iVar1 != 0) {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 600))
              (param_2,param_3,param_4,param_5);
  }
  FUN_005139f0(param_2,param_3,param_4,param_5);
  return;
}
```
