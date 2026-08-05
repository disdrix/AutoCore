# Raw capture: FUN_0067bea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067bea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0067bea0` |
| **Canonical name** | `FUN_0067bea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0067bea0(undefined4 *param_1)

{
  int *piVar1;
  
  piVar1 = param_1 + 5;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    (**(code **)*param_1)(1);
  }
  return;
}
```
