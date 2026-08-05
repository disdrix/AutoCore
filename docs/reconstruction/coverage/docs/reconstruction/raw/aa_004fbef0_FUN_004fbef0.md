# Raw capture: FUN_004fbef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fbef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fbef0` |
| **Canonical name** | `FUN_004fbef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004fbef0(int param_1,char param_2)

{
  if (param_2 != *(char *)(param_1 + 0x10a)) {
    *(char *)(param_1 + 0x10a) = param_2;
    *(char *)(param_1 + 0x109) = param_2;
    *(undefined4 *)(param_1 + 0x614) = 0;
    *(undefined4 *)(param_1 + 0x618) = 0;
    *(char *)(param_1 + 0x61c) = param_2;
    VehicleEntity_PushDriveAxesToController();
    *(undefined1 *)(param_1 + 0x101) = *(undefined1 *)(param_1 + 0x10a);
  }
  return;
}
```
