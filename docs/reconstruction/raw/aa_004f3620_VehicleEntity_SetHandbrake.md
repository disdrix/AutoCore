# Raw capture: VehicleEntity_SetHandbrake

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3620` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f3620` |
| **Canonical name** | `VehicleEntity_SetHandbrake` |
| **System** | input-drive-control |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WI-MOV-001: thiscall. this+0x61c = handbrake/bool. DriveControlTick sets 1 while Brake action
   held (DAT_00d1bd5e) or bounce path; clears to 0 on release. */

void __thiscall VehicleEntity_SetHandbrake(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x61c) = param_2;
  return;
}
```
