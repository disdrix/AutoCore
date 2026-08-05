# Raw capture: FUN_008fa5f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008fa5f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008fa5f0` |
| **Canonical name** | `FUN_008fa5f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008fa5f0(int *param_1)

{
  if (param_1[0x536] != 0) {
    FUN_00855810(0);
    (**(code **)(*(int *)param_1[0x536] + 0xcc))(0);
    (**(code **)(*param_1 + 0xb0))(param_1[0x536]);
  }
  (**(code **)(*param_1 + 0x3ac))();
  FUN_00792490();
  return;
}
```
