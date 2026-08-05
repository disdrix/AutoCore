# Raw capture: FUN_005eb7d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eb7d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005eb7d0` |
| **Canonical name** | `FUN_005eb7d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005eb7d0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_009dce20;
  if (-1 < (int)param_1[0x32]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x30],param_1[0x32] * 4,0x12);
  }
  FUN_006343d0();
  return;
}
```
