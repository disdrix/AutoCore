# Annotated low-level: hkpVehicleSteering_setSteeringAngle

| Field | Value |
|---|---|
| Stable ID | `aa_00636410` |
| VA | `0x00636410` |
| System | input-drive-control |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00636410`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
