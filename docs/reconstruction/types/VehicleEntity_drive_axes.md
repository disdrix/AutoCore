# Type notes: `VehicleEntity` / `CVOGVehicle` drive axes (partial)

Partial field map for **drive-related** slots on the client vehicle entity (`this` of MoveToTarget / SetSteerInput / PushDriveAxes / setDrivingInputs).

| Item | Value |
|------|--------|
| Binary | `autoassault.exe` |
| Image base | `0x400000` |
| Ghidra program | AA |
| Object | `CVOGVehicle` entity (vehicle object, not Havok `VehicleAction`) |
| Scope | Drive input axes + gates that suppress apply — **not** full entity layout |
| Status | Partial; confidence per field below |

Full writer/consumer narrative:  
[`../physics/verified/fn_entity_driveAxes_offsets.md`](../physics/verified/fn_entity_driveAxes_offsets.md)

---

## Drive axes

| Offset | Type | Name (working) | Meaning | Confidence |
|-------:|------|----------------|---------|:----------:|
| `+0x614` | `f32` | longitudinal / throttle | Forward/reverse command. Retail AI path uses **negative** for forward cruise (`base = −1`), positive for reverse. Typical range ~`[-1, +1]`. | **High** |
| `+0x618` | `f32` | steer | Raw steer axis `[-1, +1]`. Stage-1 target for `VehicleAction+0x24` inside `applyAction`. **Not** copied by PushDrive. | **High** |
| `+0x61c` | `u8` | handbrake / sharp | `0` or `1`. Sharp-turn / handbrake-assist: rear drive torque ×0.5 in `calcWheelTorque`; also pushed to input controller `+0x24`. **Not** service brake torque; **not** `VehicleAction+0x24` (that is steer ramp). | **High** |

### Sign convention (`+0x614`)

- Forward cruise (AI / MoveToTarget): **`base = −1`** → negative longitudinal.  
- Reverse (allow + aim behind): **`base = +1`**.  
- Local player path via `SetLongitudinalInput`: Accelerate name → `−1`, Reverse name → `+1` (same inverted sense as AI).  

Ports that flip “forward = +1” without flipping consumers will invert retail response.

---

## Input-suppress / hard-stop flags

| Offset | Type | Name (working) | Meaning | Confidence |
|-------:|------|----------------|---------|:----------:|
| `+0x101` | `u8` / `char` | input-suppress / disabled | When **non-zero**: blocks MoveToTarget drive body; **PushDriveAxes is a complete no-op** (thr/handbrake never reach controller). Cleared to `0` on MoveToTarget drive path. | **High** |
| `+0x109` | `u8` / `char` | hard-stop related | When **non-zero** inside PushDrive: forces `ctrl+0x20 = 0`, `ctrl+0x24 = 1`, early return. Cleared to `0` on MoveToTarget drive path. | **High** |

Related (not full notes here; see entity driveAxes doc):

| Offset | Type | Role | Confidence |
|-------:|------|------|:----------:|
| `+0x102` | `u8` | Mode-`0x02`: suppress `setSteeringAngle` when set | Medium–High |
| `+0x103` | `u8` | Forced-drive override (skip arrival stop in MoveToTarget) | Medium–High |
| `+0x1a0` | `ptr` | Input-controller holder; `ctrl = *([+0x1a0]+8)` | **High** |
| `+0x190..+0x198` | `f32×3` | AI aim point for MoveToTarget | **High** |

---

## Steer / longitudinal write gate (wheel-control object)

Both `VehicleEntity_SetSteerInput` (`0x004f5620`) and `VehicleEntity_SetLongitudinalInput` (`0x004f5650`) use the **same** gate. MoveToTarget’s inline proportional steer write uses the same mask.

### Pointer chain

Ghidra / decompile expression (entity `this` = `param_1`):

```text
wobj = *( *(*(this + 4) + 4) + this + 0xb0 )
```

Reading order:

```text
p0   = *(this + 4)
p1   = *(p0 + 4)
wobj = *(p1 + this + 0xb0)    // entity-relative slot on linked object
```

### Flag test

| Item | Value |
|------|--------|
| Flag byte | `wobj + 0xb4` |
| Mask | **`0xC7`** (decimal `199`) = bits `0x01 \| 0x02 \| 0x04 \| 0x40 \| 0x80` |
| Allow write if | `wobj == 0` **OR** `(*(u8*)(wobj + 0xb4) & 0xC7) == 0` |
| If closed | **No store** — previous axis value retained |

Semantic (working): steer/longitudinal **lock / external override** on the linked wheel-control object. Exact object type name not required for port if the null-or-mask rule is preserved.

| Item | Confidence |
|------|:----------:|
| Chain expression + mask + allow/deny rule | **High** |
| Full type identity of `wobj` | **Low–Medium** (behavior verified; naming open) |

---

## Pipeline (where these fields go)

```text
  writers: SetSteerInput / SetLongitudinalInput / MoveToTarget / setDrivingInputs / SetDriveAxes
                    │
                    ▼
           entity +0x614  thr (f32)
           entity +0x618  steer (f32)
           entity +0x61c  sharp (u8)
           entity +0x101  must be 0 for PushDrive
           entity +0x109  hard-stop inside PushDrive
                    │
        ┌───────────┴───────────┐
        ▼                       ▼
  PushDrive 0x4fbc10      applyAction 0x598650
  thr  → ctrl+0x20        reads entity+0x618 → VA+0x24 (steer ramp)
  sharp→ ctrl+0x24        calcWheelTorque reads +0x61c (rear ×0.5)
  steer NOT copied        thr path via controller / VA family
```

---

## Confidence summary

| Field / fact | Confidence | Primary evidence |
|--------------|:----------:|------------------|
| `+0x614` f32 longitudinal | **High** | SetLongitudinalInput store; MoveToTarget write; PushDrive → `ctrl+0x20` |
| `+0x618` f32 steer | **High** | SetSteerInput store; applyAction stage-1 target; not in PushDrive |
| `+0x61c` u8 handbrake/sharp | **High** | MoveToTarget set 0/1; PushDrive → `ctrl+0x24`; calcWheelTorque rear ×0.5 |
| `+0x101` suppresses PushDrive / MoveToTarget | **High** | PushDrive entry; MoveToTarget preconditions |
| `+0x109` hard-stop in PushDrive | **High** | PushDrive hard-stop branch |
| Gate `*(*(*(this+4)+4)+this+0xb0)`, flags `+0xb4 & 0xC7` | **High** | Identical decompiles of SetSteer / SetLongitudinal; MoveToTarget inline |
| Identity / full layout of gate object | **Low–Medium** | Behavior only |
| Full entity size / unrelated fields | **N/A** | Out of scope |

---

## Evidence pointers

### Verified physics notes (authoritative)

| Doc | Use for |
|-----|---------|
| [fn_entity_driveAxes_offsets.md](../physics/verified/fn_entity_driveAxes_offsets.md) | Full axis map, pipeline, consumers, constants |
| [fn_004f5620_setSteerInput.md](../physics/verified/fn_004f5620_setSteerInput.md) | Gate + stores for `+0x618` / sibling `+0x614` |
| [fn_steering_input_feed.md](../physics/verified/fn_steering_input_feed.md) | entity `+0x618` → VA → driverInput → `0x64f840` |
| [fn_004fc650_driveController.md](../physics/verified/fn_004fc650_driveController.md) | MoveToTarget writer for all three axes + clear `+0x101`/`+0x109` |
| [fn_004fbc10_pushDriveAxes.md](../physics/verified/fn_004fbc10_pushDriveAxes.md) | `+0x101`/`+0x109`, thr/handbrake push, no steer copy |
| [fn_00598040_calcWheelTorque.md](../physics/verified/fn_00598040_calcWheelTorque.md) | `+0x61c` rear torque cut |
| [fn_00598650_applyAction.md](../physics/verified/fn_00598650_applyAction.md) / [fn_00598650_steerRamp.md](../physics/verified/fn_00598650_steerRamp.md) | Steer consumer |
| [INDEX.md](../physics/verified/INDEX.md) | Full verified catalog |

### Specs / layout

| Doc | Use for |
|-----|---------|
| [drive-controller-spec.md](../physics/drive-controller-spec.md) | Formulas + goldens |
| [steering-spec.md](../physics/steering-spec.md) | Ramp / falloff |
| [brake-spec.md](../physics/brake-spec.md) | Handbrake vs false VA+0x24 brake myth |
| [0.8-struct-offsets.md](../physics/0.8-struct-offsets.md) | Broader entity / VA / ctrl layout |

### Fresh Ghidra decompile anchors (re-open in program AA)

| VA | Symbol / role |
|----|----------------|
| `0x004f5620` | `VehicleEntity_SetSteerInput` — gate + store `+0x618` |
| `0x004f5650` | `VehicleEntity_SetLongitudinalInput` — gate + store `+0x614` |
| `0x004fbc10` | `VehicleEntity_PushDriveAxesToController` — `+0x101`/`+0x109`, thr/handbrake |
| `0x004fc650` | `CVOGVehicle::MoveToTarget3DPoint` — writes three axes |
| `0x004fbec0` | `VehicleEntity_SetDriveAxes` — clear/set all three + push |
| `0x00504c70` | `Vehicle_setDrivingInputs` — network entry, same slots |
| `0x00598650` | `VehicleAction_applyAction` — reads `+0x618` |
| `0x00598040` | `VehicleAction_calcWheelTorque` — reads `+0x61c` |

Prefer `decompile_function` + `read_memory` on these VAs if notes and binary ever disagree.

---

## Out of scope / open

- Full `CVOGVehicle` size and non-drive fields.  
- Named C++ type of the `+0xb0` gate object.  
- Wire packing of thr/steer/sharp in ghost packets (see motion / server_handbrake notes).  
- Havok `VehicleAction` and input-controller layouts beyond the slots above (see offset docs).
