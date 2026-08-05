# Review A (reconstruction fidelity): `aa_00504c70` Vehicle_setDrivingInputs

| Field | Value |
|---|---|
| **Stable ID** | `aa_00504c70` |
| **VA** | `0x00504c70` |
| **Canonical name** | `Vehicle_setDrivingInputs` |
| **Scaffold stem** | `throttle` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra; supersedes 2026-07-23 partial scaffold) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF; machine stores verified) |
| **Counterpart** | `reviews/B_aa_00504c70_Vehicle_setDrivingInputs.md` |
| **System** | `input-drive-control` (network/ghost path) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Primary **network / ghost** entry that applies remote driving inputs and pose to a vehicle entity when a physics host is present:

1. **Gate:** `entity+0x08 != 0` else full no-op.
2. **Type probe:** call `*(**(phys+0x3c)+0x18)()`; if result **`== 6`**, call `FUN_0053d970` with **entity in ECX** (motion / soft-body cleanup — leave-FUN).
3. **Ungated axis write:**
   - `entity+0x614 ← thr` (f32)
   - `entity+0x618 ← steer` (f32)
   - `entity+0x61c ← handbrake` (u8)
4. **`VehicleEntity_PushDriveAxesToController(entity)`** — thr/HB bridge only; steer stays on entity for applyAction.
5. **Optional activate:** if `param_9 == 0` and `entity+0x1a0 == 0`, resolve MI component at `+0xb0+adj`; if non-null and two owner vfuncs agree (`+0x19c` vs `+0x1c8`), `Vehicle_ActivateEnterWorld`.
6. **`FUN_0053eec0(pos, rot, linVel, angVel, integrateDt)`** — network pose/velocity apply.

**Not** local player `DriveControlTick`. Static callers are VehicleNet unpack / reconcile only.

**Calling convention:** MSVC `__thiscall` — entity in **ECX**; stack args include four pose pointers, thr, steer, hb, skip-flag, dt.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00504c70_throttle.md` | Live re-capture + machine prefix |
| Annotated | `docs/reconstruction/raw/aa_00504c70_throttle.annotated.md` | Param map + CF diagram |
| Clean | `docs/reconstruction/reconstructed-exact/throttle.cpp` | Decompiler-structure exact |
| Function record | `docs/reconstruction/functions/aa_00504c70_throttle.md` | Dual + confidence |
| Live decompile | Ghidra MCP `decompile_function` @ `0x00504c70` | **≡ scaffold body CF** |
| Live bytes | `read_memory` len 128 @ entry | thr/steer `movss`, HB byte, Push rel32 |
| Callers | `get_function_callers` / `get_xrefs_to` | **2** static sites |
| Callees | `get_function_callees` | `53d970`, `4fbc10`, `503f30`, `53eec0` |
| Push dual | `aa_004fbc10` (strengthened) | thr/HB only |
| Pose verified | `physics/verified/fn_0053eec0_networkApply.md` | pos/rot/vel/ang/dt |
| Axis type | `types/VehicleEntity_drive_axes.md` | slots + writers table |
| System map | `systems/input-drive-control.md` | network path indexed |

**Not performed:** Launcher, runtime golden, bit-exact package diff, full VehicleNet caller arg recovery (OWN-ONLY this VA).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Gate requires `entity+0x08 != 0` | **High** | Live `if (*(param_1+8)!=0)`; machine `test [esi+8]; jz` |
| No work when phys null | **High** | Entire body under that if |
| Type query via `phys+0x3c` vtbl `+0x18` | **High** | Decompile + machine `call [edx+0x18]` |
| Compare constant **6** | **High** | `cmp eax, 6` |
| Type-6 → `FUN_0053d970` with **entity this** | **High** | `mov ecx,esi; call 0x0053d970`; decomp `(0)` is **wrong** |
| Thr store `+0x614` f32 | **High** | `movss [esi+0x614]` disp `14 06 00 00` |
| Steer store `+0x618` f32 | **High** | `movss [esi+0x618]` |
| HB store `+0x61c` u8 | **High** | `mov [esi+0x61c], al` |
| **No** 0xC7 suppress gate | **High** | Straight stores; contrast `SetLongitudinal`/`SetSteer` |
| Always Push on gated path | **High** | Unconditional `call 0x004fbc10` after stores |
| Push omits steer | **High** | Owned Push dual |
| Activate gate: `param_9==0` ∧ `+0x1a0==0` | **High** | Live nested if |
| Component walk `+0xb0 + *( *(entity+4)+4 )` | **High CF** | Live decompile |
| Owner match vfuncs `0x19c` / `0x1c8` | **High CF** / product **Low** | Equality gate only |
| ActivateEnterWorld thiscall | **High** | Callee list + decompile name |
| `FUN_0053eec0` last after axes/push | **High** | Order sealed |
| Pose args = param_2..5 + param_10 | **High** | Matches verified networkApply signature |
| Callers: UnpackGhost + ReconcilePrediction | **High** | Two UNCONDITIONAL_CALL xrefs |
| Local input producer | **Falsified** | No DriveControlTick xref |
| Runtime / bit-exact package | **Open** | Deferred |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Phys-null early out | **Yes** |
| Type-6 optional cleanup | **Yes** |
| thr → `+0x614` | **Yes** |
| steer → `+0x618` | **Yes** |
| hb → `+0x61c` | **Yes** |
| PushDriveAxesToController | **Yes** |
| Optional ActivateEnterWorld | **Yes** |
| FUN_0053eec0 always on gated path | **Yes** |
| No invent 0xC7 / thr clamp in this unit | **Yes** |
| No invent steer copy into controller here | **Yes** |

### 4.1 Order of side effects (must preserve)

```
phys gate
→ optional FUN_0053d970
→ write +0x614, +0x618, +0x61c
→ PushDriveAxesToController
→ optional ActivateEnterWorld
→ FUN_0053eec0
```

Push runs **before** pose apply. Activate can run with still-null `+0x1a0` before pose.

### 4.2 Contrast: other axis writers

| API | Gate | Push? | Pose? |
|---|---|---|---|
| `SetLongitudinalInput` / `SetSteerInput` | **0xC7** | No | No |
| `SetHandbrake` | none | No | No |
| `SetDriveAxes` | none | **Always** | No |
| **`setDrivingInputs`** | **phys `+0x08` only** | **Always** (gated path) | **Yes** |
| `MoveToTarget3DPoint` | own AI gates | Yes | No |

Network path can force axes even when local gated setters would suppress under 0xC7.

### 4.3 Machine store/call proof (prefix)

| Item | Evidence |
|------|----------|
| `this` → ESI | `56 8b f1` |
| thr from `[esp+0x18]` after push | `f3 0f 10 44 24 18` |
| hb from `[esp+0x20]` | `8a 44 24 20` |
| Push rel32 | `e8 4d 6f ff ff` → `0x004fbc10` |
| Type-6 call | `e8 da 8c 03 00` → `0x0053d970` with `8b ce` |

---

## 5. Layout (body-backed)

### Entity (`this`)

| Offset | Type | Role in this unit |
|-------:|------|-------------------|
| `+0x04` | ptr | link / MI base for `+0xb0` component and activate vfuncs |
| `+0x08` | ptr | physics host — **entry gate** |
| `+0x1a0` | ptr | input-controller holder — must be 0 for activate branch |
| `+0x614` | f32 | thr **written** |
| `+0x618` | f32 | steer **written** |
| `+0x61c` | u8 | handbrake **written** |

### Downstream (not written here)

| Path | Role |
|------|------|
| Push → `ctrl+0x20` / `ctrl+0x24` | thr / HB (dual `aa_004fbc10`) |
| applyAction reads `+0x618` | steer ramp |
| calcWheelTorque reads `+0x61c` | rear torque ×0.5 |
| `FUN_0053eec0` | soft/hard pose & velocity |

---

## 6. Constants

| Constant | Value | Role | Confidence |
|----------|------:|------|------------|
| Body-type compare | **6** | immediate `cmp eax, 6` | **High** (machine) |
| Vfunc slot type | `+0x18` | type query | **High** |
| Activate vfunc A | `+0x19c` | owner token | **High CF** |
| Activate vfunc B | `+0x1c8` | owner token | **High CF** |
| No float DAT_* in body | — | thr/steer passed as args | **High** |

---

## 7. Gaps / open

1. Product enum for type return **6** (leave-FUN callee body not re-owned here).
2. Product English name for `param_9` skip-activate flag.
3. Full arg packing at `VehicleNet_UnpackGhostVehicle` / `ReconcilePrediction` call sites (OWN-ONLY limit).
4. Runtime / differential / bit-exact package.
5. Port risk: trusting decompiler `FUN_0053d970(0)` literally would pass wrong this.

**Verdict:** **accept-with-gaps** — static CF, three-axis stores, Push, optional activate, pose apply, and two VehicleNet callers **sealed**; product names for type-6 / param_9 and runtime remain open.
