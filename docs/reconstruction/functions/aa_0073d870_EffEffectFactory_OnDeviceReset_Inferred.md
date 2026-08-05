# Function record: EffEffectFactory_OnDeviceReset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073d870` |
| **Canonical name** | `EffEffectFactory_OnDeviceReset_Inferred` |
| **Ghidra name** | `FUN_0073d870` |
| **Address** | `0x0073d870` |
| **Body** | **82 B** (`0x0073d870`–`0x0073d8c2` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | graphics / Effects |
| **Name confidence** | **Inferred** (caller string seals Effect Factory; OnReset from post-Reset placement) |
| **Dual** | **accept-with-gaps** (W38-V A+B) |

## Role

Effect Factory **post-device-reset recreate**: walk 0x14-entry table; optional child vcall `+0x118`; rebind params via `FUN_007525f0`; return `0`.

## ABI

| Slot | Value |
|---|---|
| EAX | factory host\* (`+4` begin / `+8` end) |
| stack | none |
| return | `0` always (`XOR EAX,EAX`) |
| cleanup | plain `RET` |

## Rejected aliases

- `Named_CalleeOf_Named_gfxDevice_0073d870`

## Artifacts

See `aa_0073d870_FUN_0073d870.md`.
