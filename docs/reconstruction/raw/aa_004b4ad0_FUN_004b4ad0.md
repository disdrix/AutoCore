# Raw capture: FUN_004b4ad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b4ad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004b4ad0` |
| **Canonical name** | `FUN_004b4ad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004b4ad0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *unaff_retaddr;
  
  if ((*param_1 != 0) && (param_1[1] != 0)) {
    uVar1 = (**(code **)(*(int *)param_1[1] + 0x188))(param_3);
    *unaff_retaddr = uVar1;
  }
  return;
}
```
