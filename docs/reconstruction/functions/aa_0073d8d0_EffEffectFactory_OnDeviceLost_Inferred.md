# Function record: EffEffectFactory_OnDeviceLost_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073d8d0` |
| **Canonical name** | `EffEffectFactory_OnDeviceLost_Inferred` |
| **Ghidra name** | `FUN_0073d8d0` |
| **Address** | `0x0073d8d0` |
| **Body** | **103 B** (`0x0073d8d0`–`0x0073d937` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | graphics / Effects |
| **Name confidence** | **Inferred** (Device Reset shutdown + same host as Effect Factory reset) |
| **Dual** | **accept-with-gaps** (W38-V A+B) |

## Role

Effect Factory **pre-reset / device-lost release**: walk same 0x14 table; `FUN_0074f0c0` + `FUN_00752640`; clear `DAT_00d1f048[+0xC]`; optional device vtbl`+0x134`(0) when mode flag set.

## ABI

| Slot | Value |
|---|---|
| EAX | factory host\* (`+4` begin / `+8` end) |
| stack | none |
| return | void |
| cleanup | plain `RET` |

## Rejected aliases

- `Named_CalleeOf_Named_gfxDevice_0073d8d0`

## Artifacts

See `aa_0073d8d0_FUN_0073d8d0.md`.
