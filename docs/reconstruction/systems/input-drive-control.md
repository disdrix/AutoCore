# System map: Client input → vehicle drive control axes

| Field | Value |
|---|---|
| System | Local-player **user input** → vehicle entity drive axes (`+0x614` / `+0x618` / `+0x61c`) → controller push |
| Priority | **High** — user-facing input/commands, then movement. **Not** physics-first. |
| Program | `autoassault.exe` (image base `0x400000`) |
| Primary unit | `Client_Input_DriveControlTick` @ `0x009223b0` |
| Primary important callee | `VehicleEntity_SetSteerInput` @ `0x004f5620` (gate + store) |
| Status | Behavioral map from fresh DriveControlTick decompile + indexed verified physics prior art |
| Scope of this file | Input sampling, axis writes, push bridge, and how axes leave the input layer. Downstream Havok ramps/steering are **indexed**, not re-proven here. |

---

## Scope

**In scope**

* Per-tick local client mapping of **held ActionMap actions** (and related analog device path) onto the **possessed vehicle entity’s drive axes**.
* The three entity slots that encode player drive intent:
  * `entity+0x614` — longitudinal / throttle-brake axis (f32)
  * `entity+0x618` — steer axis (f32)
  * `entity+0x61c` — handbrake / sharp byte (u8)
* Gated setters that write those slots and the end-of-tick **push** that copies thr/handbrake into the analog driver-input controller.
* Early-out when UI blocks input.
* Secondary behaviors co-located in the same tick (camera look offsets, terrain cast / airborne impulse, quick-bar skills, secondary weapons) — documented as **related but secondary**.

**Out of scope (indexed only)**

* Havok `VehicleAction_applyAction` stage-1 steer ramp, analog deadzone curve, `hkDefaultSteering_update` wheel angles — see physics verified notes.
* Network pose / ghost apply (`Vehicle_setDrivingInputs`, `FUN_0053eec0`) — related **movement** for remote vehicles; **not** the local input producer. See `docs/MOTION_CLIENT_RE.md`.
* NPC / AI axis generation (`MoveToTarget3DPoint` @ `0x004fc650`) — same entity slots, different producer.

**Sign convention (critical)**

Retail longitudinal axis for **Accelerate** is **negative** (`-1.0f`); **Reverse** is **positive** (`+1.0f`). Steer **left** is **`+1`**, **right** is **`-1`**. Ports that flip these will invert thr/steer relative to retail.

---

## Known entry points

| Address | Symbol (conservative) | Role |
|--------:|------------------------|------|
| `0x009223b0` | `Client_Input_DriveControlTick` | **Primary.** Local player drive-control tick: sample binds → set entity axes → optional push. |
| Call site area `0x00923676` | (within / near DriveControlTick push) | Calls `VehicleEntity_PushDriveAxesToController` for local player when vehicle is active (`entity+0x101==0`). |
| `0x004f5620` | `VehicleEntity_SetSteerInput` | Gated write of steer → `entity+0x618`. |
| `0x004f5650` | `VehicleEntity_SetLongitudinalInput` | Gated write of longitudinal → `entity+0x614`. |
| `0x004f3620` | `VehicleEntity_SetHandbrake` | Write handbrake → `entity+0x61c` (**no** `0xC7` gate documented on this setter). |
| `0x004fbc10` | `VehicleEntity_PushDriveAxesToController` | Bridge: entity thr/handbrake → driver-input controller (steer **not** copied here). |

**Other producers of the same slots (not this system’s entry, but share state):**

| Address | Role |
|--------:|------|
| `0x004fc650` | AI / move-to-target axis generator |
| `0x00504c70` | `Vehicle_setDrivingInputs` — network/ghost path (axes + pose) |
| Various | Other callers of `SetSteerInput` / `SetLongitudinalInput` (see `fn_004f5620_setSteerInput.md` xref tables) |

**Signature (DriveControlTick decompile):**

```text
undefined4 Client_Input_DriveControlTick(int *param_1, int param_2)

param_1  — client / player controller object (VOGClient-related; exact type name uncertain)
param_2  — vehicle entity pointer, or 0 if none
```

---

## Behavioral flow

High-level per-tick sequence for the **local driving** path (digital ActionMap name-3 path; analog path is a parallel producer — see Secondary):

```
1. Client_Input_DriveControlTick(controller, vehicle)
2. Early exit if UI blocks input
   — DAT_00d1b6d8[0x7f] vtbl+0x3c (exact object type uncertain; blocks drive sampling)
3. If vehicle present and vehicle+0x101 == 0 (drive-enabled):
   a. Sample held ActionMap flags (name-3 DAT_* action structs)
   b. Longitudinal:
        Accelerate held (DAT_00d1bc26) → SetLongitudinalInput(vehicle, -1.0f)
        Reverse held     (DAT_00d1bc5a) → SetLongitudinalInput(vehicle, +1.0f)
        (neither / release path → typically 0; exact clear timing may share tick logic)
   c. Steer (**exclusive priority**, not additive):
        1. hard-R  (DAT_00d1bcc2) → SetSteerInput(vehicle, -1.0f)   // 0xbf800000
        2. hard-L  (DAT_00d1bc8e) → SetSteerInput(vehicle, +1.0f)   // 0x3f800000
        3. soft-L  (DAT_00d1bd2a) → SetSteerInput(vehicle, -0.5f)   // 0xbf000000  (UF-006)
        4. soft-R  (DAT_00d1bcf6) → SetSteerInput(vehicle, +0.5f)   // 0x3f000000
        5. none + no analog → SetSteerInput(0)
   d. Handbrake:
        Brake held (DAT_00d1bd5e) → SetHandbrake(vehicle, 1)
        release clears (SetHandbrake 0) — same tick family
4. End of active vehicle path:
   VehicleEntity_PushDriveAxesToController(vehicle)  // only if vehicle+0x101==0 (and internal gates)
5. Secondary same-tick work (may interleave; not all gated on vehicle+0x101 the same way):
   — analog device path (DAT_00d1b618 / DAT_00d1b620) — see Soft/analog residual below
   — camera / look offsets (local_d* stack locals — **not** steer axis; see Camera residual)
   — terrain cast CVOGMap_CastTerrainHeight (airborne impulse helper)
   — quick-bar skill activation
   — Input_TryFireSecondaryWeapons
```

### Camera look-offset residual (SECTION 1 / 3 / 5–7 / 15) — 2026-07-29 (strengthen)

**Locals vs steer (High / sealed structural):** drive steer is only `SetSteerInput` → `entity+0x618`. Stack `local_d*` are camera/look state co-located in the same tick; SECTION 7 bind branches may update **both** independently. Separation axes: storage / gate (`+0x101` on setters only) / value domain (steer ±1/±0.5 vs look `local_d4` ±0.03/±0.2) / consumer (`FUN_0091a5f0`+SECTION 15 vs physics on `+0x618`). Soft look ±0.2 ≠ soft steer ±0.5 (UF-006).

| Concern | Storage | DCT path | Gated by `+0x101`? |
|---------|---------|----------|--------------------|
| Steer axis | `entity+0x618` | `SetSteerInput` (SECTION 7 / analog drive) | **Yes** |
| Look scale / aim param | `local_d4` (seed 1.0) | SECTION 1 / 3 / 7 mode tables | **No** |
| Look vector | `local_d0, local_cc, local_c8, local_c4` | seed `DAT_00d1a640..64c`; thr/steer side-effects | **No** |
| Look apply | `FUN_0091a5f0(local_d4, &local_d0)` | post-steer when look helper present | n/a |
| Analog camera-only | `pClient` vtbl `+0x44c` | SECTION 3 if no vehicle or `+0x101!=0` | branch is non-drive |
| World camera slots | `*(DAT_00d1b644+0xe894)+0x11c/120/124` | SECTION 15 epilogue | n/a |

| DAT | f32 | Look use (normal mode unless noted) |
|-----|----:|-------------------------------------|
| `DAT_00aaa8fc` | 0.03 | hard L/R → `local_d4` ± |
| `DAT_00a0f70c` | 0.2 | soft L/R → `local_d4` ± |
| `DAT_00aaa878` | 0.004 | alternate-mode `local_d4` step |
| `DAT_00aaa688` | 5.0 | hard-R → add to `local_c8` |
| `DAT_00aaacc8` | 11.0 | default look step `local_a4` |
| `DAT_00aaacc4` | −5.0 | reverse special look step |

Evidence: clean SECTION comments + live re-decompile CF + re-`read_memory` on DAT floats; dual A/B `*_camera_refresh.md` (bind-site matrix); scratch `tmp/a_camera_dct.md`. **Open:** yaw/pitch names for components; full combat mode tables; `FUN_0091a5f0` deep semantics. UF-003 camera slice **sealed structural**; skills/airborne still open.

### Soft-steer residual (sealed body / open UF-006)

| Flag | Plate role | Immediate | f32 | Image push site | Sealed? |
|------|------------|-----------|----:|-----------------|---------|
| `DAT_00d1bd2a` | Soft L | `0xbf000000` | −0.5 | `0x00922c48` | **High** body |
| `DAT_00d1bcf6` | Soft R | `0x3f000000` | +0.5 | `0x00922cf8` | **High** body |
| `DAT_00d1bc8e` | Hard L | `0x3f800000` | +1.0 | decompile | **High** |
| `DAT_00d1bcc2` | Hard R | `0xbf800000` | −1.0 | decompile | **High** |

**UF-006 (open):** SoftL body = −0.5 while HardL body = +1 — **opposite signs** if both labels mean physical left. Display strings “Steer Left Soft” / “Steer Right Soft” (`Client_InitActionDisplayNames` `+0x34d`/`+0x381`) do not alone prove DAT identity. **Do not invent a fix** (no clean/value flip without runtime bind hold). CX-001 remains open.

### Analog device residual (SECTION 3)

| Step | Behavior | Confidence |
|------|----------|------------|
| Presence | `DAT_00d1b618` code* non-null and returns non-zero | High CF |
| Sample thr | `DAT_00d1b620(7) − DAT_00d1b620(6)` | High CF |
| Sample steer | `DAT_00d1b620(9) − DAT_00d1b620(10)` | High CF |
| No vehicle / `+0x101!=0` | Camera/look only (`pClient` vtbl+0x44c); no axis setters | High CF |
| Drive-enabled | Clear `+0x109`/HB if set; clamp thr (`DAT_00aaa668`..`g_flOne`); continuous `SetLongitudinal` + `SetSteer` | High CF |
| vs digital | Thr clear skipped when analog present; steer clear skipped when analog active | High CF |
| Deadzone/scale table | Partial — continuous mapping not fully expanded | Medium–Low |

**Axis write gate (steer + longitudinal only):**

```
wobj = *(*(*(entity+4)+4) + entity + 0xb0)
if (wobj != 0 && (*(u8*)(wobj+0xb4) & 0xC7) != 0)
    skip store;   // lock / external override
else
    store float to entity+0x614 or +0x618
```

Handbrake setter does **not** use this gate (writes `+0x61c` unconditionally from the input path).

**Push gates (end of tick):**

```
if (entity+0x101 != 0 || entity+0x1a0 == 0)
    PushDriveAxes is complete no-op
else
    copy thr + handbrake into ctrl = *(entity+0x1a0)+8
    // entity+0x618 is NOT written by Push
```

---

## Call graph summary

```
Client_Input_DriveControlTick                 0x009223b0
  │
  ├─[UI block?]──► early return
  │
  ├─ VehicleEntity_SetLongitudinalInput       0x004f5650  → entity+0x614
  ├─ VehicleEntity_SetSteerInput              0x004f5620  → entity+0x618
  ├─ VehicleEntity_SetHandbrake               0x004f3620  → entity+0x61c
  │
  ├─ VehicleEntity_PushDriveAxesToController  0x004fbc10
  │     └─ writes driverInput thr (+0x20), handbrake (+0x24)
  │        (ctrl = handle[entity+0x1a0]+8)
  │
  ├─ (secondary) analog sampling              DAT_00d1b618 / DAT_00d1b620
  ├─ (secondary) camera/look offset locals
  ├─ (secondary) CVOGMap_CastTerrainHeight    0x004cfe60  (xref from ~0x9230c7)
  ├─ (secondary) quick-bar skill activation
  └─ (secondary) Input_TryFireSecondaryWeapons

─── Downstream (indexed; not re-verified in this map) ───

entity+0x618
  → VehicleAction_applyAction                 0x00598650  stage-1 ramp → VA+0x24
  → mirror DI+0x1c
  → FUN_005fdf20 / calcStatus                 → DI+0x14 filtered steer
  → hkDefaultSteering_update                  0x0064f840

entity+0x614  (via Push → DI+0x20) + entity+0x61c (via Push → DI+0x24)
  → transmission / wheel torque / brake consumers under applyAction family
```

**Primary important unit for this goal:** `aa_004f5620` / `VehicleEntity_SetSteerInput` — pure **gate + store** of the steer command the rest of the movement stack consumes.

---

## Data flow summary

| Source | Transform | Destination |
|--------|-----------|-------------|
| ActionMap held: Accelerate `DAT_00d1bc26` | map to `-1.0f` | `SetLongitudinalInput` → `entity+0x614` |
| ActionMap held: Reverse `DAT_00d1bc5a` | map to `+1.0f` | `SetLongitudinalInput` → `entity+0x614` |
| ActionMap held: SteerLeft `DAT_00d1bc8e` | map to `+1.0f` | `SetSteerInput` → `entity+0x618` |
| ActionMap held: SteerRight `DAT_00d1bcc2` | map to `-1.0f` | `SetSteerInput` → `entity+0x618` |
| Soft L `DAT_00d1bd2a` | map to `-0.5f` (`0xbf000000`; image `push` @ `0x00922c48`) | `SetSteerInput` → `entity+0x618` — **UF-006 label open** |
| Soft R `DAT_00d1bcf6` | map to `+0.5f` (`0x3f000000`; image `push` @ `0x00922cf8`) | `SetSteerInput` → `entity+0x618` |
| Brake `DAT_00d1bd5e` | map to `1` / release `0` | `SetHandbrake` → `entity+0x61c` |
| Analog device path | continuous axes: thr ch7−ch6, steer ch9−ch10; clamp thr; same setters when `+0x101==0` | same entity slots (`DAT_00d1b618` / `DAT_00d1b620`) |
| `entity+0x614` | PushDriveAxes (optional clamp / speed-cap) | `driverInput+0x20` throttle |
| `entity+0x61c` | PushDriveAxes | `driverInput+0x24` handbrake byte |
| `entity+0x618` | **not** via Push | read later by `applyAction` stage-1 into `VA+0x24` → `DI+0x1c` → filtered `DI+0x14` |

```
[keyboard/bind state]     [analog device]
        │                        │
        ▼                        ▼
  ActionMap DAT_* flags     DAT_00d1b618/620 path
        │                        │
        └──────────┬─────────────┘
                   ▼
     SetLongitudinal / SetSteer / SetHandbrake
                   │
                   ▼
         entity +0x614 / +0x618 / +0x61c
              │              │
              │              └──► applyAction (steer ramp; next physics substeps)
              ▼
     PushDriveAxesToController
              │
              ▼
     driverInput +0x20 thr, +0x24 handbrake
```

---

## State owners

| State | Owner object | Who writes (this system) | Who reads |
|-------|--------------|--------------------------|-----------|
| Longitudinal command | Vehicle entity `+0x614` | `SetLongitudinalInput` from DriveControlTick (and other producers) | `PushDriveAxes` → controller; physics thr path |
| Steer command | Vehicle entity `+0x618` | `SetSteerInput` from DriveControlTick | `VehicleAction_applyAction` stage-1 (direct entity read) |
| Handbrake / sharp | Vehicle entity `+0x61c` | `SetHandbrake` (DriveControlTick + AI/UI packs); **also** direct stores from MoveToTarget / SetDriveAxes | `PushDriveAxes` → `ctrl+0x24`; `calcWheelTorque` (rear torque ×0.5) |
| Steer lock / override | wheel-control `wobj+0xb4` bits `0xC7` | (other systems; not DriveControlTick) | Gate inside SetSteer / SetLongitudinal |
| Drive-disabled flag | `entity+0x101` | (spawn/stop/AI paths) | DriveControlTick thr path / Push entry |
| VehicleAction handle | `entity+0x1a0` | create/activate | Push uses `*(+0x1a0)+8` as controller |
| Controller thr / HB | driverInput `+0x20` / `+0x24` | `PushDriveAxesToController` | Havok analog driver-input / brake family |
| Stage-1 steer ramp | `VehicleAction+0x24` | applyAction (physics tick) | mirrored to `DI+0x1c` |
| Filtered steer status | `driverInput+0x14` | `calcStatus` / `FUN_005fdf20` | `hkDefaultSteering_update` |
| Local player global | `DAT_00d1b6d8` | client lifecycle | UI-block probe at `[0x7f]` vtbl+0x3c; also used elsewhere as local player |

---

## State transitions

| From | Event | To |
|------|-------|-----|
| Thr idle (`+0x614` cleared / 0) | Accelerate name held, `+0x101==0`, gate open | `+0x614 = -1.0` |
| Thr idle | Reverse name held, gate open | `+0x614 = +1.0` |
| Steer neutral | SteerLeft held, gate open | `+0x618 = +1.0` |
| Steer neutral | SteerRight held, gate open | `+0x618 = -1.0` |
| Steer neutral | SoftL flag held (plate), gate open | `+0x618 = -0.5` (UF-006: may not match hard-left physical) |
| Steer neutral | SoftR flag held (plate), gate open | `+0x618 = +0.5` (UF-006 residual) |
| Handbrake off | Brake name held | `+0x61c = 1` |
| Handbrake on | Brake released | `+0x61c = 0` (clear path) |
| Axes written | Push runs (`+0x101==0`, `+0x1a0!=0`) | Controller thr/HB updated; steer remains entity-only |
| Gate closed (`wobj+0xb4 & 0xC7`) | SetSteer / SetLongitudinal called | **No write** — previous axis retained |
| `entity+0x101 != 0` | Tick would accelerate / push | Longitudinal accelerate path skipped; Push no-op |
| UI block active | Tick entry | Early exit — no axis sampling (drive path) |

**Uncertainty:** exact mutual exclusion when both Accelerate and Reverse are held; soft vs hard steer priority when multiple steer actions true; whether longitudinal clear to `0` is explicit every tick or only on release. Marked open below.

---

## External effects

| Effect | When | Notes |
|--------|------|-------|
| Entity drive axis memory | Every successful setter | Sole direct write of player thr/steer/HB commands on the entity |
| Driver-input thr / handbrake | End of tick via Push | Enables Havok drive force / handbrake consumers |
| Steer into physics | **Not** same function | Deferred: applyAction later ramps `entity+0x618` |
| Terrain height query | Secondary path in same tick | `CVOGMap_CastTerrainHeight` — airborne impulse helper, not wheel collision |
| Camera / look | Secondary | Stack `local_d*` + `FUN_0091a5f0` + SECTION 15 slots; **does not write** drive axes (`+0x614/+0x618/+0x61c`) |
| Skills / secondary weapons | Secondary | Combat/UI side effects in same tick function |
| Network outbound | **Not established in this map** | Local axis → server replication (if any) not traced here |
| Rigid body pose | **Not written here** | Pose/network is separate (`MOTION_CLIENT_RE.md`) |

---

## Dependencies

| Dependency | Why |
|------------|-----|
| ActionMap / bind state (`DAT_00d1bc*` family) | Source of held digital drive actions |
| Vehicle entity with live `+0x1a0` VehicleAction handle | Push no-ops without it (class of `nullWheels` failures) |
| `entity+0x101 == 0` | Drive-enabled; gates accelerate path and Push |
| Linked wheel-control object gate (`0xC7`) | Can suppress thr/steer writes |
| Client controller object (`param_1`) | Tick context; UI block via related globals |
| `DAT_00d1b6d8` UI / local-player machinery | Early-out when UI consumes input |
| Downstream physics (applyAction / framework) | Consumes axes; **not** owned by this system |
| Map terrain cast (`0x004cfe60`) | Secondary airborne path only |

---

## Known types

| Name / label | Confidence | Notes |
|--------------|------------|-------|
| Vehicle entity (`CVOGVehicle`-class) | High (prior art) | Carrier of `+0x614/+0x618/+0x61c/+0x101/+0x1a0` |
| Client / player controller (`param_1`) | Medium | Decompile: VOGClient-related; exact C++ type name not fixed in this pass |
| ActionMap action records (`DAT_00d1bc*`) | Medium–High | Held-action flags; “name-3” family from plate comments |
| Analog driver input / input controller | High | Object at `*(entity+0x1a0)+8`; thr `+0x20`, HB `+0x24` |
| `VehicleAction` / Havok framework | High (indexed) | Consumes steer from entity; thr path partly via controller |
| `hkDefaultSteering` | High (indexed) | Multiplies filtered `DI+0x14` by `maxSteeringAngle` |
| UI block object via `DAT_00d1b6d8[0x7f]` | Low–Medium | vtbl+0x3c call; type not named |

---

## Known identifiers

### Functions

| Address | Identifier | Role |
|--------:|------------|------|
| `0x009223b0` | `Client_Input_DriveControlTick` | Input → axes tick (dual A/B reviews) |
| `0x004f5620` | `VehicleEntity_SetSteerInput` | Gate + store steer |
| `0x004f5650` | `VehicleEntity_SetLongitudinalInput` | Gate + store longitudinal |
| `0x004f3620` | `VehicleEntity_SetHandbrake` | Store handbrake (no `0xC7` gate) |
| `0x004fbc10` | `VehicleEntity_PushDriveAxesToController` | Entity → controller thr/HB |
| `0x004fc650` | `CVOGVehicle_MoveToTarget3DPoint` | AI path thr/steer/HB (UF-007 gate) |
| `0x007f9110` | `Client_ActionMap_Init` | Zero tables → names → default DIKs |
| `0x007f7570` | `Client_InitActionDisplayNames` | Display strings (incl. Accel/Steer/Brake) |
| `0x007f8720` | `Client_InitDefaultKeybinds` | Default DIK table (dual A/B reviews) |
| `0x00911030` | `Client_Input_OnKeyDown_MatchAction` | WM key-down → held/edge flags |
| `0x00925d60` | `Client_Input_PollBoundActions` | Edge poll (QB/UI; pairs with tick) |
| `0x004cfe60` | `CVOGMap_CastTerrainHeight` | Secondary terrain query from tick |
| `0x00598650` | `VehicleAction_applyAction` | Downstream stage-1 steer ramp (indexed) |
| `0x0064f840` | `hkDefaultSteering_update` | Downstream wheel steer angles (indexed) |

### Entity / controller offsets

| Offset | Type | Meaning |
|-------:|------|---------|
| `entity+0x101` | u8 | Drive disabled if ≠ 0 |
| `entity+0x109` | u8 | Hard-stop flag (Push forces thr=0, HB=1) — Push path, not ActionMap |
| `entity+0x1a0` | ptr | Handle block; `+8` → driver-input controller |
| `entity+0x614` | f32 | Longitudinal axis |
| `entity+0x618` | f32 | Steer axis |
| `entity+0x61c` | u8 | Handbrake / sharp |
| `ctrl+0x20` | f32 | Controller throttle (from Push) |
| `ctrl+0x24` | u8 | Controller handbrake (from Push) |
| `wobj+0xb4` | u8 | Lock mask; bits `0xC7` block thr/steer sets |

### ActionMap / globals (digital path)

| Address | Bind role (from decompile plates) | Axis effect |
|---------|-----------------------------------|-------------|
| `DAT_00d1bc26` | Accelerate | `SetLongitudinalInput(-1.0f)` when `vehicle+0x101==0` |
| `DAT_00d1bc5a` | Reverse | `SetLongitudinalInput(+1.0f)` |
| `DAT_00d1bc8e` | SteerLeft | `SetSteerInput(+1.0f)` |
| `DAT_00d1bcc2` | SteerRight | `SetSteerInput(-1.0f)` |
| `DAT_00d1bd2a` | Soft left | `SetSteerInput(-0.5f)` |
| `DAT_00d1bcf6` | Soft right | `SetSteerInput(+0.5f)` |
| `DAT_00d1bd5e` | Brake | `SetHandbrake(1)` / release clears |
| `DAT_00d1b618` / `DAT_00d1b620` | Analog device path | Continuous sampling (details partial) |
| `DAT_00d1b6d8` | Local player / UI root | UI-block early exit via `[0x7f]` vtbl+0x3c |

### Gate constant

| Value | Meaning |
|------:|---------|
| `199` / `0xC7` | `wobj+0xb4` mask: bits `0x01\|0x02\|0x04\|0x40\|0x80` |

---

## Important functions

### 1. `Client_Input_DriveControlTick` @ `0x009223b0` — **system root**

* Args: controller object, vehicle entity (or 0).
* Samples ActionMap held actions → digital axis magnitudes.
* Secondary: analog, camera, terrain, skills, secondary weapons.
* Ends active drive path with `PushDriveAxesToController` when `vehicle+0x101==0`.

### 2. `VehicleEntity_SetSteerInput` @ `0x004f5620` — **primary important unit**

* Pure gate + single float store to `entity+0x618`.
* No clamp, no ramp, no Push.
* Identical gate shape to longitudinal sibling.
* Full verified note: `docs/reconstruction/physics/verified/fn_004f5620_setSteerInput.md`.

### 3. `VehicleEntity_SetLongitudinalInput` @ `0x004f5650`

* Same gate; store `entity+0x614`.
* Retail accelerate = **−1**, reverse = **+1**.

### 4. `VehicleEntity_SetHandbrake` @ `0x004f3620`

* Writes `entity+0x61c`; **no** `0xC7` gate (dual residual 2026-07-29 sealed; live ≡ raw).
* NPC `MoveToTarget3DPoint` writes the **same byte directly** (not a caller of this setter).

### 5. `VehicleEntity_PushDriveAxesToController` @ `0x004fbc10`

* Requires `+0x101==0` and `+0x1a0!=0`.
* Copies thr and handbrake only; **steer stays on entity** for applyAction.
* May clamp thr, hard-stop, or zero thr under speed-cap rules.
* Full verified note: `docs/reconstruction/physics/verified/fn_004fbc10_pushDriveAxes.md`.

---

## Evidence

| Claim | Source | Strength |
|-------|--------|----------|
| DriveControlTick signature, param roles, ActionMap→setter mapping, soft ±0.5, brake, Push at end if `+0x101==0`, secondary paths (analog, camera, terrain, skills, weapons), UI early-out | Fresh Ghidra decompile of `Client_Input_DriveControlTick` @ `0x009223b0` (this pass) | **High** (input layer) |
| SetSteer / SetLongitudinal gate, offsets, no side effects | `fn_004f5620_setSteerInput.md` (decompile `0x4f5620` / `0x4f5650`) | **Verified** |
| Push copies thr/HB not steer; no-op gates; controller layout | `fn_004fbc10_pushDriveAxes.md`, `fn_entity_driveAxes_offsets.md` | **Verified** |
| Downstream `entity+0x618` → VA+0x24 → DI+0x1c → DI+0x14 → `0x64f840` | `fn_steering_input_feed.md` | **Verified** (physics; indexed here) |
| DriveControlTick xref to terrain cast ~`0x9230c7` | `fn_004cfe60_castTerrain.md` | **High** |
| Network pose is separate movement path | `docs/MOTION_CLIENT_RE.md` | Related context |
| Soft L/R float bits `0xbf000000` / `0x3f000000` | DriveControlTick decompile + `read_memory` push sites `0x00922c48` / `0x00922cf8` (2026-07-29) | **High** (body sealed) |
| Soft vs hard exclusive priority hard-R→hard-L→soft-L→soft-R→clear | Fresh decompile SECTION 7 if/else chain | **High** |
| UF-006 SoftL sign vs HardL | Body SoftL=−0.5 HardL=+1; labels unproven physical | **Open residual** (do not invent fix) |
| Analog continuous → same setters when drive-enabled | SECTION 3 decompile | **High** CF; scale details Medium |
| Camera look locals ≠ steer axis; SECTION 7 interleave | Clean SECTION 1/3/5–7/15 + dual camera refresh; look steps `read_memory` 0.03/0.2/5/11 | **High** CF (locals vs steer); component names open |
| SECTION 15 world camera slots `+0x11c/120/124` | Clean epilogue | **High** CF |

**Prior-art index (do not re-verify for this map):**

* `docs/reconstruction/physics/verified/fn_004f5620_setSteerInput.md`
* `docs/reconstruction/physics/verified/fn_steering_input_feed.md`
* `docs/reconstruction/physics/verified/fn_004fbc10_pushDriveAxes.md`
* `docs/reconstruction/physics/verified/fn_entity_driveAxes_offsets.md`
* `docs/MOTION_CLIENT_RE.md` (network pose — related movement, not primary input)

---

## Confidence

| Area | Level | Notes |
|------|-------|-------|
| Digital ActionMap → axis magnitudes and signs | **High** | Fresh decompile + matching setter plates |
| Entity offsets `+0x614/+0x618/+0x61c` | **High** | Multiple verified notes |
| Setter gate `0xC7` | **High** | Verified on both thr/steer setters |
| Push does not write steer | **High** | Verified Push decompile |
| End-to-end physics consumption of steer | **High** as indexed prior art; **not** re-opened here | Trust `fn_steering_input_feed.md` |
| Exact tick ordering vs other client systems | **Medium** | Caller of DriveControlTick not fully mapped in this file |
| Analog device path | **Medium–Low** | Globals known; continuous mapping not fully expanded |
| UI block object type / all early-out conditions | **Medium–Low** | One known probe; may be incomplete |
| Soft vs hard steer priority (exclusive order) | **High** | Sealed if/else: hard-R → hard-L → soft-L → soft-R → clear |
| Soft L/R physical polarity vs hard (UF-006) | **Tentative** | Body values High; labels open — runtime needed |
| Longitudinal clear-to-zero every tick | **Medium** | Typical for held-action systems; exact branch not fully quoted in this summary |
| Camera look locals vs steer (structural) | **High** | Residual sealed 2026-07-29; not axis path |
| Look-vector component names / full mode tables | **Low–Medium** | Secondary; open residual |
| Airborne impulse / skill side details | **Low** for this system goal | UF-003 remainder |

**Overall system map confidence:** **High** for the digital local-player path into entity axes and Push; **Medium** for co-located secondary branches and multi-key edge cases.

---

## Open questions

1. Who calls `Client_Input_DriveControlTick` each frame (client main loop / sector tick / input pump)? Exact parent not listed in this map.
2. When both Accelerate and Reverse are held, which wins (or do both fire last-write-wins)?
3. ~~Soft steer vs hard steer priority~~ — **sealed exclusive:** hard-R → hard-L → soft-L → soft-R → clear (not additive).
4. Is longitudinal axis forced to `0` every tick when neither thr/rev is held, or only on transition?
5. Full analog deadzone/scale: `DAT_00d1b618` / `DAT_00d1b620` continuous → setters (CF sealed; curve table partial).
5b. UF-006: does SoftL physical match HardL under real binds? (body SoftL=−0.5 vs HardL=+1 residual)
6. Exact type of `param_1` and of `DAT_00d1b6d8[0x7f]` UI gate object.
7. Does local player thr/steer get replicated outbound on the wire the same frame, or only consume local Havok?
8. Interaction with `entity+0x109` hard-stop during player input (Push behavior known; whether DriveControlTick clears it unknown).
9. Airborne impulse formula after terrain cast (secondary; not needed for axis map).
10. ~~Camera look locals vs steer~~ — **sealed structural:** `local_d*` ≠ `+0x618`; residual open only for component names / full combat look tables / `FUN_0091a5f0` deep semantics.

---

## Verification gaps

| Gap | Impact | Suggested check |
|-----|--------|-----------------|
| Full structured decompile dump of `0x009223b0` committed as a verified fn note | Traceability of secondary branches | Promote a `fn_009223b0_driveControlTick.md` under physics/verified or functions/ |
| Caller xrefs of DriveControlTick | Integration into client frame | `get_function_xrefs` / call graph |
| Multi-key conflict order | Port parity under chorded inputs | Step through decompile hold order; optional live bind test |
| Analog continuous mapping | Gamepad / wheel parity | Decompile analog block + DAT layouts |
| UI early-out completeness | “Stuck axes” when menus open | Enumerate all early returns |
| Live: hold Accelerate → confirm `+0x614 == -1` then Push thr | End-to-end smoke | CE/hook on entity slots during local drive |
| Soft body magnitudes −0.5 / +0.5 | **Sealed** (decompile + image push) | — residual closed for hex |
| UF-006 SoftL/SoftR **physical** direction vs hard | Label polarity residual | Runtime hold Soft L/R bind → CE `entity+0x618` |

---

## Next recommended work

1. **Promote** a verified function note for `Client_Input_DriveControlTick` (`0x009223b0`) with full ordered branch list (digital, analog, secondary) and all early returns — same quality bar as `fn_004f5620_setSteerInput.md`.
2. **Map callers** of DriveControlTick and relation to `Client_Input_PollBoundActions` (Push xref area `0x9260da` noted in prior art).
3. **Port surface (input-first):** ensure AutoCore local (or predicted) control path can:
   * write `+0x614/+0x618/+0x61c` with retail signs;
   * honor `0xC7` gate;
   * call Push semantics without requiring full Havok first.
4. **Leave physics ramps alone** until input axes are correct — stage-1 / DI filter already verified; wrong input signs are the higher-risk user-facing bug.
5. Optionally instrument live entity slots while driving to close multi-key and clear-to-zero questions.

---

## Priority rationale

User-facing **commands** (what the player holds) and the **movement axes** those commands become are the first mile of vehicle control. Physics ramps and steering falloff only scale what this system writes. Network pose (`MOTION_CLIENT_RE.md`) moves remote bodies; it does not replace local ActionMap → entity axes. This map therefore stops at entity/controller handoff and **indexes** the rest.
