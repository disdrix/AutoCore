# Function record: CVOGPhysics_SetAngularVelocity

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d040` |
| **Canonical name** | `CVOGPhysics_SetAngularVelocity` (inferred) |
| **Ghidra / prior** | `FUN_0040d040` / `Named_CalleeOf_Client_Input_DriveControlTick_0040d040` |
| **Address** | `0x0040d040` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `physics` (primary); callee of `input-drive-control` |
| **Body size** | `0x30` bytes (instruction-sealed) |
| **Completion status** | **Dual reviewed** — accept-with-gaps (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Static CF High; runtime open |

## Purpose

Optional readiness prepare on a `CVOGPhysics` object, then call bound rigid-body **vtable +0x54** with a caller-supplied vector — **set angular velocity**. Sibling of `CVOGPhysics_ApplyImpulseVector` (`0x0040d260`, vtbl **+0x50** linear).

## Signature (decompiler + asm)

```c
void __thiscall CVOGPhysics_SetAngularVelocity(void* phys /* ECX */, void* angVelVec /* stack */);
// ret 4
```

## Control flow

1. `FUN_005070b0(phys, &outByte)` — if `phys+0x44==0` → out=0; else out=`*(*(phys+0x44)+0x29)`.
2. If `out==0` **and** `*(phys+0x44)!=0` → `FUN_005070d0(phys)`.
3. `body = *(phys+0x3c)`; `(*body->vtbl)[+0x54](angVelVec)`.
4. Return. No null check on body.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040d040_FUN_0040d040.md`
- Annotated: `docs/reconstruction/raw/aa_0040d040_FUN_0040d040.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGPhysics_SetAngularVelocity.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_0040d040.cpp` / `Named_CalleeOf_Client_Input_DriveControlTick_0040d040.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040d040_CVOGPhysics_SetAngularVelocity.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040d040_CVOGPhysics_SetAngularVelocity.md`

## Callers / callees

**Callees:** `FUN_005070b0`, `FUN_005070d0`, indirect body vtbl+0x54.

**Callers (8 sites):** `Client_Input_DriveControlTick` @ `0x00922653`; `FUN_0053eec0` (network soft); `VehicleAction_airStabilization`; `CVOGHBAICreatureBase_DecideHeading`; `FUN_005d0d60`; `FUN_005cd3b0` (×2); `FUN_005dac00`.

## Confidence

| Claim | Level |
|---|---|
| Control flow / vtbl imm 0x54 | **High** |
| Sibling parity with +0x50 linear | **High** |
| Angular vs linear semantic | **High** (usage + prior verified) |
| English name | **Probable** |
| `phys+0x44` type / +0x29 name | **Tentative** |
| Runtime / bit-exact image | Open |

## Prior art

- `physics/verified/fn_0053eec0_networkApply.md` — soft teleport `setAngVel` row
- `physics/verified/fn_0064d810_avd.md` — continuous AVD write via same vtbl+0x54 (inline, not this helper)
- `physics/verified/fn_offsets_rigidbody.md` — rb angVel fields +0x50..5c vs method slot +0x54
- Sibling dual: `reviews/A_aa_0040d260_CVOGPhysics_ApplyImpulseVector.md`
