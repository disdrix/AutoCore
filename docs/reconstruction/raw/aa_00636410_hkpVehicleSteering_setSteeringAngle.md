# Raw capture: hkpVehicleSteering_setSteeringAngle

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636410` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00636410` |
| **Canonical name** | `hkpVehicleSteering_setSteeringAngle` |
| **System** | input-drive-control |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Trivial __thiscall setter: *(this+0x50) = param_2 (float). Called from
   VehicleAction_applyAction (0x598ad2) and FUN_00597ec0. Purpose NOT confirmed — a plausible
   candidate for a target-speed/speed-limiter value given the call site, but this was not
   verified by tracing how +0x50 is subsequently read. Do not treat as confirmed; see the
   correction note on VehicleAction_tickSubsystems (0x636a60). */

void __thiscall hkpVehicleSteering_setSteeringAngle(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x50) = param_2;
  return;
}
```
