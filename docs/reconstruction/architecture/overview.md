# Client reconstruction architecture (`autoassault.exe`)

Brief map of the **client reverse-engineering** effort that feeds AutoCore server parity and packet/layout work.

---

## Target binary

| Item | Value |
|------|--------|
| Binary | `autoassault.exe` (retail Auto Assault client) |
| Image base | **`0x400000`** (no ASLR on main module; Ghidra VAs match live process VAs for this build) |
| Ghidra program | **`AA`** (also referred to as `AA-decode` in older physics notes) |
| Primary RE tooling | Ghidra MCP (`decompile_function`, `read_memory`, xrefs) — prefer decompile over disassembly |

All function addresses in reconstruction docs are absolute VAs at this image base unless stated otherwise.

---

## What we reconstruct

Work is organized under `docs/reconstruction/`:

| Area | Role |
|------|------|
| **architecture/** | This overview and high-level dependency order |
| **systems/** | User-facing systems (input, movement, inventory, missions, …) as primary product surface |
| **types/** | Partial entity/struct field maps with confidence + evidence |
| **evidence/** | Indexes into prior RE (physics, inventory, motion, missions, networking, topic extractions) |
| **physics/** | Deep Havok vehicle physics RE (large, mature, mostly ported) |
| **functions/**, **experiments/**, **reviews/** | Per-function notes, probes, review artifacts |

Server C# under `src/` is the **consumer** of RE: packets, ghost pose, NPC drive, inventory wire, mission dispatch. Reconstruction docs stay evidence-first (addresses, decompiles, constants); port code lives elsewhere.

---

## Priority order

**Default priority is user-facing systems first.** Deeper subsystems are pulled in when a user-facing path depends on them.

### High priority (user-facing surface)

1. **Input / drive control** — bound actions → entity drive axes → push to controller  
2. **Movement / vehicle control** — local player + NPC aim → thr/steer/handbrake; network ghost apply  
3. **Inventory / cargo** — grid footprint, cargo wire, grab/drop, CreateVehicle inventory slots  
4. **Missions** — grant/progress/complete, dialog, kill/collect/use/patrol objectives  
5. **Networking / packets** — opcode + fixed layouts the client parses by offset  
6. **Combat / skills / reactions / vendors** — as needed for live play loops  

### Lower default priority (preserve; do not re-litigate)

- **Deep client Havok vehicle physics** under [`docs/reconstruction/physics/`](../physics/README.md)  
  Already extensively verified and largely ported. Keep as **dependency material** when input, movement, ghost pose, or NPC drive needs a consumer/writer fact — not as the default next RE topic.

When a systems note needs physics detail, link into physics README / verified INDEX rather than duplicating formulas.

---

## Physics corpus (preserved, lower default priority)

| Entry | Purpose |
|-------|---------|
| [physics/README.md](../physics/README.md) | Phase status, evidence table, cross-cutting port facts |
| [physics/verified/INDEX.md](../physics/verified/INDEX.md) | One-line index of every verified function/offset gate |

Key drive-axis anchors used by higher-priority systems:

- `VehicleEntity_SetSteerInput` / `SetLongitudinalInput` — gated axis writers  
- `VehicleEntity_PushDriveAxesToController` — thr/handbrake bridge  
- `CVOGVehicle::MoveToTarget3DPoint` — AI axis generator  
- `VehicleAction::applyAction` + steer feed into `hkDefaultSteering_update`  
- Entity offsets `+0x614` / `+0x618` / `+0x61c` (see [types/VehicleEntity_drive_axes.md](../types/VehicleEntity_drive_axes.md))

---

## Prior art (do not erase)

Older RE lives across `docs/` and `docs/reconstruction/physics/`. The index that maps those files to systems priorities is:

**[evidence/prior-art-index.md](../evidence/prior-art-index.md)**

---

## Working rules (architecture level)

1. **Evidence before port** — decompile + constant reads (or live debugger) before changing server behavior that claims retail parity.  
2. **Link, don’t fork** — new systems notes cite verified physics gates and prior docs; do not rewrite physics goldens unless the binary conflicts.  
3. **Image base is fixed** — document VAs at `0x400000`; note if a different build is ever used.  
4. **Ghidra program name** — use **AA** for new notes; treat `AA-decode` as the same corpus when reading older physics files.
