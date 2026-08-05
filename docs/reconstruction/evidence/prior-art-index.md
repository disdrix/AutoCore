# Prior-art index (client RE)

Catalog of **existing** reverse-engineering documentation for `autoassault.exe`.  
**Nothing here is deleted or superseded by this file** — it only maps docs to reconstruction priority systems so new work can find evidence without re-deriving it.

| Item | Value |
|------|--------|
| Binary | `autoassault.exe` |
| Image base | `0x400000` |
| Ghidra program | AA (`AA-decode` in older physics notes) |
| Architecture overview | [../architecture/overview.md](../architecture/overview.md) |

---

## How to use this index

1. Pick the **system** you are reconstructing (left column / section).  
2. Open the listed docs for writers, consumers, offsets, and wire formats.  
3. Prefer **verified physics gates** for drive/movement math; prefer **top-level `docs/`** for inventory, missions, networking.  
4. Treat `docs/topic-extractions/*` as **secondary** (focused packet/behavior extracts, often narrower than canonical docs).

---

## Priority systems → prior art

### Input (player drive bindings → entity axes)

| Doc | What it covers |
|-----|----------------|
| [../physics/verified/fn_004f5620_setSteerInput.md](../physics/verified/fn_004f5620_setSteerInput.md) | `SetSteerInput` / `SetLongitudinalInput` — gated stores to `+0x618` / `+0x614` |
| [../physics/verified/fn_steering_input_feed.md](../physics/verified/fn_steering_input_feed.md) | End-to-end steer feed: entity → VA ramp → driverInput → `hkDefaultSteering` |
| [../physics/verified/fn_004fbc10_pushDriveAxes.md](../physics/verified/fn_004fbc10_pushDriveAxes.md) | Push thr/handbrake to input controller; `+0x101` / `+0x109` gates |
| [../physics/verified/fn_entity_driveAxes_offsets.md](../physics/verified/fn_entity_driveAxes_offsets.md) | Full thr/steer/sharp offset map + writers/consumers |
| [../types/VehicleEntity_drive_axes.md](../types/VehicleEntity_drive_axes.md) | Partial type notes (confidence-tagged) for drive-related entity fields |
| [../physics/drive-controller-spec.md](../physics/drive-controller-spec.md) | AI/local axis formulas + goldens (also used by NPC) |

### Movement (vehicle control, AI drive, ghost apply)

| Doc | What it covers |
|-----|----------------|
| [../physics/verified/fn_004fc650_driveController.md](../physics/verified/fn_004fc650_driveController.md) | `MoveToTarget3DPoint` — AI thr/steer/sharp writer |
| [../physics/verified/fn_004fbc10_pushDriveAxes.md](../physics/verified/fn_004fbc10_pushDriveAxes.md) | Controller bridge |
| [../physics/verified/fn_steering_input_feed.md](../physics/verified/fn_steering_input_feed.md) | Steer command path into steering update |
| [../physics/verified/fn_0053eec0_networkApply.md](../physics/verified/fn_0053eec0_networkApply.md) | Network pose apply |
| [../../MOTION_CLIENT_RE.md](../../MOTION_CLIENT_RE.md) | Client vehicle network pose, `setDrivingInputs`, integrate/apply rates |
| [../../NPCDriving.md](../../NPCDriving.md) | Broad NPC drive pipeline (axes → Havok) |
| [../../NPC_VEHICLE_DRIVE_RE.md](../../NPC_VEHICLE_DRIVE_RE.md) / [../../NPC_DRIVING_FIX_RE.md](../../NPC_DRIVING_FIX_RE.md) | NPC drive RE / fix notes |
| [../../nullWheels.md](../../nullWheels.md) | Missing VehicleAction / `+0x1a0` failure class |

### Inventory / cargo

| Doc | What it covers |
|-----|----------------|
| [../../inventory-cargo-wire-re.md](../../inventory-cargo-wire-re.md) | Cargo wire (`0x2040`…), CreateVehicle COID array, client grid occupancy |
| [../../inventory-grid-footprint.md](../../inventory-grid-footprint.md) | Multi-cell footprint, InvSizeX/Y, place/find-free behavior |
| [../../topic-extractions/vendor-store-useobject.md](../../topic-extractions/vendor-store-useobject.md) | Vendor / UseObject (secondary) |

### Missions

| Doc | What it covers |
|-----|----------------|
| [../../missionHandler.md](../../missionHandler.md) | Canonical server mission runtime ownership and dispatch |
| [../../missionState.md](../../missionState.md) | Client RE, packet layouts, Ghidra anchors (linked from missionHandler) |
| [../../missionWork.md](../../missionWork.md) | Persistence / open bugs (linked) |
| [../../topic-extractions/set-active-objective.md](../../topic-extractions/set-active-objective.md) | SetActiveObjective (secondary) |
| [../../topic-extractions/auto-patrol.md](../../topic-extractions/auto-patrol.md) | AutoPatrol (secondary) |
| [../../topic-extractions/unlock-contobj.md](../../topic-extractions/unlock-contobj.md) | Contested object unlock (secondary) |

### Networking / packets

| Doc | What it covers |
|-----|----------------|
| [../../networking.md](../../networking.md) | Opcode + fixed-layout packet contract, send path, padding rules |
| [../../MOTION_CLIENT_RE.md](../../MOTION_CLIENT_RE.md) | Ghost pose / drive-input unpack and apply |
| [../physics/verified/server_ghost_pack_notes.md](../physics/verified/server_ghost_pack_notes.md) | Server ghost pack layout notes |
| [../physics/verified/server_handbrake_wire.md](../physics/verified/server_handbrake_wire.md) | Handbrake on ghost wire (`VehicleFlags` bit0) |
| [../../topic-extractions/reaction-packets.md](../../topic-extractions/reaction-packets.md) | Reaction packet family (secondary) |

### Combat / skills / reactions / NPC (secondary surfaces)

| Doc | What it covers |
|-----|----------------|
| [../../topic-extractions/skill-cast.md](../../topic-extractions/skill-cast.md) | Skill cast RE extract |
| [../../topic-extractions/vehicle-combat-pools-ghidra.md](../../topic-extractions/vehicle-combat-pools-ghidra.md) | Vehicle combat pools |
| [../../topic-extractions/boost-reaction.md](../../topic-extractions/boost-reaction.md) | Boost reaction |
| [../../topic-extractions/delete-reaction.md](../../topic-extractions/delete-reaction.md) / [delete-reaction-type.md](../../topic-extractions/delete-reaction-type.md) | Delete reaction |
| [../../topic-extractions/make-not-invincible-set-faction.md](../../topic-extractions/make-not-invincible-set-faction.md) | Invincibility / faction |
| [../../topic-extractions/server-triggers.md](../../topic-extractions/server-triggers.md) | Server triggers |
| [../../NPC.md](../../NPC.md) | Broader NPC / combat notes |
| [../../XP.md](../../XP.md) | XP (if needed for mission rewards loop) |

---

## Deep physics (preserved — lower default priority)

Use when a higher-priority system **depends** on sim math, layout, or consumers. Do not treat as the default next RE queue.

### Entry points

| Doc | Role |
|-----|------|
| [../physics/README.md](../physics/README.md) | Phase status, evidence table, port cross-cuts |
| [../physics/verified/INDEX.md](../physics/verified/INDEX.md) | Full one-line index of verified gates |

### Drive / input / controller (subset of verified)

| Doc | Role |
|-----|------|
| [../physics/verified/fn_004f5620_setSteerInput.md](../physics/verified/fn_004f5620_setSteerInput.md) | Gated steer/longitudinal setters |
| [../physics/verified/fn_steering_input_feed.md](../physics/verified/fn_steering_input_feed.md) | Steer feed into `0x64f840` |
| [../physics/verified/fn_004fc650_driveController.md](../physics/verified/fn_004fc650_driveController.md) | Drive controller (MoveToTarget) |
| [../physics/verified/fn_004fbc10_pushDriveAxes.md](../physics/verified/fn_004fbc10_pushDriveAxes.md) | Push drive axes |
| [../physics/verified/fn_entity_driveAxes_offsets.md](../physics/verified/fn_entity_driveAxes_offsets.md) | Entity axis offsets |
| [../physics/drive-controller-spec.md](../physics/drive-controller-spec.md) | Spec + goldens |
| [../physics/steering-spec.md](../physics/steering-spec.md) | Steering falloff / ramp |
| [../physics/brake-spec.md](../physics/brake-spec.md) | Brake vs handbrake (`+0x61c`) |
| [../physics/0.8-struct-offsets.md](../physics/0.8-struct-offsets.md) | Struct offset cross-ref |

### Other physics areas (index only — see verified INDEX for full list)

| Spec / note | Area |
|-------------|------|
| `0.1-step-rate.md` … `0.7-transmission.md` | Step, mass, friction, susp, wheel collide, aero, transmission |
| `engine-torque-spec.md`, `avd-airstab-spec.md`, `setup-field-mapping.md` | Engine, AVD/air-stab, setup mapping |
| `verified/fn_00598650_*.md`, `fn_00598040_*.md`, `fn_0064*.md`, `fn_006c4450_*` | applyAction, torque, framework components, friction solve |
| `verified/server_*` | Server ghost / NPC ticker wiring notes |
| `docs/agents/physicsHandoff.md`, `docs/agents/task-*-report.md` | Port task reports (not primary RE gates) |

---

## Secondary: topic extractions (full list)

All under `docs/topic-extractions/` — use after canonical docs, or when the topic is only covered there:

| File | System hint |
|------|-------------|
| [auto-patrol.md](../../topic-extractions/auto-patrol.md) | missions |
| [boost-reaction.md](../../topic-extractions/boost-reaction.md) | combat / reactions |
| [delete-reaction.md](../../topic-extractions/delete-reaction.md) | reactions |
| [delete-reaction-type.md](../../topic-extractions/delete-reaction-type.md) | reactions |
| [make-not-invincible-set-faction.md](../../topic-extractions/make-not-invincible-set-faction.md) | NPC / combat |
| [reaction-packets.md](../../topic-extractions/reaction-packets.md) | networking / reactions |
| [server-triggers.md](../../topic-extractions/server-triggers.md) | world / missions |
| [set-active-objective.md](../../topic-extractions/set-active-objective.md) | missions |
| [skill-cast.md](../../topic-extractions/skill-cast.md) | combat / skills |
| [unlock-contobj.md](../../topic-extractions/unlock-contobj.md) | missions / world |
| [vehicle-combat-pools-ghidra.md](../../topic-extractions/vehicle-combat-pools-ghidra.md) | combat |
| [vendor-store-useobject.md](../../topic-extractions/vendor-store-useobject.md) | inventory / vendors |

---

## Related non-reconstruction docs (context only)

| Doc | Note |
|-----|------|
| [../../PATH_A_DEBUGGER.md](../../PATH_A_DEBUGGER.md) | Live debugger hooks (image base `0x400000`) |
| [../../CREATEVEHICLE_DEBUGGER.md](../../CREATEVEHICLE_DEBUGGER.md) | CreateVehicle live probes |
| [../../ghostPlan.md](../../ghostPlan.md) | Ghost streaming plan |
| [../../GHOST_OBJECT_DIAG.md](../../GHOST_OBJECT_DIAG.md) | Ghost object diagnostics |

---

## Maintenance

- When adding a new systems or types note, **link back** here if it becomes a primary prior-art source.  
- Do not move or delete physics verified files to “clean up” — update this index instead.  
- Prefer absolute VAs at base `0x400000` and point confidence/gaps at the leaf evidence files.
