# Raw capture: FUN_0065abb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0065abb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0065abb0` |
| **Canonical name** | `FUN_0065abb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0065abb0(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_009e46ec;
  (**(code **)(*DAT_00b05060 + 4))(param_1[6]);
  piVar1 = (int *)(param_1[4] + -4);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    FUN_00638180();
  }
  piVar1 = (int *)(param_1[3] + -4);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    FUN_00638180();
  }
  *param_1 = &PTR_LAB_009cc290;
  return;
}
```
