# Function record: Vehicle_UpdateWeaponHardpoints3_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f9030` |
| **Canonical name** | `Vehicle_UpdateWeaponHardpoints3_Inferred` |
| **Address** | `0x004f9030` |
| **Body** | `0x004f9030`–`0x004f9563` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | vehicle / combat weapon hardpoints |
| **Completion status** | **accept-with-gaps** — dual A/B W19-A 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_004f9030`

## Purpose

Vehicle **primary hardpoint (×3)** update:

1. Optionally **clear fire flags** on all three slots when a lock/control object reports flags `& 0x13`.
2. For each slot: load aim offsets from plant def, transform to world, build **+Y yaw** quaternion from mode-gated angle at `this+0x158`, compose with vehicle orientation, push pos/orient to hardpoint iface, invoke **fire helper**, and optionally materialize a 4×4 for attachment graphics.

Called from vehicle tick path `FUN_00500560` (alongside `CVOGPlayerVehicle_UpdateTurretAiming`) and `FUN_008d7e40`.

## Signature

```c
// ECX = vehicle*; near RET; 0 stack args
void __fastcall Vehicle_UpdateWeaponHardpoints3_Inferred(void* vehicle /*ECX*/);
```

## Key layout (vehicle / plant)

| Off | Role |
|---|---|
| `this+0x260` | pointer table of 3 hardpoint objects |
| `this+0x158` | yaw angle (float bits) when mode ∉ {0,1} |
| `this+0x105` | enable gfx/matrix attach path |
| `this+8` | nested transform host (0 = use MI-local +0x84/+0x94) |
| plant `+0x4e8` | aim vec3 base (stride 0xC per slot) |
| plant `+0x50c` | packed 3×3-bit mode fields |
| hardpoint `+0xC7..+0xC9` | fire flag trio (cleared in phase 1) |
| hardpoint `+8` | pos/orient iface (vtbl +0x14/+0x18) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004f9030_FUN_004f9030.md`
- Annotated: `docs/reconstruction/raw/aa_004f9030_FUN_004f9030.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Vehicle_UpdateWeaponHardpoints3_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004f9030.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004f9030_Vehicle_UpdateWeaponHardpoints3_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004f9030_Vehicle_UpdateWeaponHardpoints3_Inferred.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Caller | `FUN_00500560` | vehicle update; site `0x00500612` |
| Caller | `FUN_008d7e40` | site `0x008d7f5e` |
| Callee | `Weapon_SetFireFlagPair_Inferred` | clear |
| Callee | `Quat_FromAxisAngle_Inferred` | +Y yaw |
| Callee | `Weapon_FireHelper_Inferred` | fire path |
| Callee | `Math_Matrix4x4_Set16` | gfx matrix |
| Callee | `FUN_004e9370`, `FUN_004e8830`, `FUN_004e88a0`, `FUN_0076eb00`, `FUN_0076f5f0`, `FUN_0099b8a0`, `FUN_0040cf90` | helpers |

## Confidence

| Claim | Level |
|---|---|
| ECX this + 3-slot walk + fire clear | **Confirmed** |
| Mode packing + yaw gate + +Y axis | **Confirmed** |
| Product English name | **Inferred** |
| Nested transform host exact class | **Medium** |
| Full attachment gfx contract | **Medium** (helpers residual) |
