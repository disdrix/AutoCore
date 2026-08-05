# Work Queue

Priority model: user-facing systems first (input â†’ movement â†’ interaction â†’ inventory â†’ â€¦). Physics/rendering/allocators only when a selected high-level behavior requires them.

Status values: `queued` | `active` | `blocked` | `partial` | `done` | `deferred`

**Coverage honesty:** Live Ghidra **25666** functions; dual A∩B unique **2209** (~8.6%). Inventory stamp none=0 is **not** dual depth. Manager waves expand duals + high-priority systems; remainder stays open.

---

## WQ-001 â€” input-drive-control system map

| Field | Value |
|-------|-------|
| ID | WQ-001 |
| System | input-drive-control |
| Target | System behavioral map |
| Address / symbol | `Client_Input_DriveControlTick` @ `0x009223b0` (+ setters) |
| Priority score | 95 |
| User-facing impact | Direct: keyboard/action-map drive controls |
| State mutation | High (entity axes +0x614/+0x618/+0x61c) |
| Callers importance | Per-frame client tick path |
| Comm / persistence | Low (local input â†’ entity; push to controller) |
| Crash risk | Medium (null vehicle / UI gates) |
| Confidence | High for map of primary axis path; partial for camera/skill side branches |
| Verification gaps | Full DriveControlTick assembly pass; runtime key-flag correlation |
| Dependencies | None |
| Status | **partial** (map written; deeper DriveControlTick still open) |
| Next action | After WQ-002 reviews land, expand soft-steer and analog-device branches |

---

## WQ-002 â€” VehicleEntity_SetSteerInput reconstruction unit

| Field | Value |
|-------|-------|
| ID | WQ-002 |
| System | input-drive-control |
| Target | Function unit `aa_004f5620` |
| Address / symbol | `VehicleEntity_SetSteerInput` @ `0x004f5620` |
| Priority score | 92 |
| User-facing impact | Direct steer axis write from player + NPC callers |
| State mutation | Single gated float store to `entity+0x618` |
| Callers | DriveControlTick, drive-to-point `0x4fc650`, others |
| Comm / persistence | None |
| Crash risk | Low (null-safe gate) |
| Confidence | High (control flow + store); Probable (lock object identity) |
| Verification gaps | Runtime observation; differential harness; full wobj type identity |
| Dependencies | WQ-001 (context) |
| Status | **partial** (artifacts + dual reviews; not fully complete) |
| Next action | Leave open gaps; WQ-003 duals already present â€” residual runtime/diff only |

---

## WQ-003 â€” VehicleEntity_SetLongitudinalInput sibling

| Field | Value |
|-------|-------|
| ID | WQ-003 |
| System | input-drive-control |
| Target | `aa_004f5650` `VehicleEntity_SetLongitudinalInput` |
| Address | `0x004f5650` |
| Priority score | 90 |
| User-facing impact | Direct longitudinal axis write (accel/reverse) |
| State mutation | Single gated float store to `entity+0x614` |
| Dependencies | WQ-002 (identical gate pattern) |
| Status | **partial** (raw + annotated + clean + function record + dual A/B present accept-with-gaps; runtime/diff/bit-exact still open) |
| Artifacts | `raw/aa_004f5650_*`, `reconstructed-exact/VehicleEntity_SetLongitudinalInput.cpp`, `functions/aa_004f5650_*`, `reviews/A_aa_004f5650_*`, `reviews/B_aa_004f5650_*` |
| Verification gaps | Runtime; differential; bit-exact; same UF gate questions as SetSteerInput (wobj type / suppress-bit meanings) |
| Next action | Leave dual complete; residual runtime/diff only â€” do **not** re-emit dual reviews |

---

## WQ-004 â€” DriveControlTick full vertical trace

| Field | Value |
|-------|-------|
| ID | WQ-004 |
| System | input-drive-control |
| Target | Full `Client_Input_DriveControlTick` reconstruction |
| Address | `0x009223b0` |
| Priority score | 88 |
| Status | **partial** (raw + clean + `functions/aa_009223b0_*` + dual A/B present; soft-steer/analog residual) |
| Dependencies | WQ-002, WQ-003 |
| Artifacts | `raw/aa_009223b0_*`, `reconstructed-exact/Client_Input_DriveControlTick.cpp`, `functions/aa_009223b0_Client_Input_DriveControlTick.md`, A/B reviews |
| Next action | Runtime key-flag correlation when Launcher approved; UF-006 label bind residual; UF-007 MoveToTarget gate sealed High wave2 |
| Sealed 2026-07-29 | Soft-steer order + Â±0.5/Â±1.0 immediates dual refresh; UF-006 label map still Probable |

---

## WQ-005 â€” Inventory grab/drop client path

| Field | Value |
|-------|-------|
| ID | WQ-005 |
| System | inventory-transfer |
| Target | `Client_SendInventoryGrab_FromGrid` / drop / response |
| Address | Grab `0x00860e20`, Drop `0x00860a50`, DropResponse `0x00813730` |
| Priority score | 80 (priority order #4) |
| Status | **partial** (scaffold units exist under `functions/` + `reconstructed-exact/`; dual reviews / runtime open) |
| Dependencies | None blocking |
| Next action | Tighten system map + dual-review critical transfer units; see also WQ-008 manager wave |
| Prior art | `docs/inventory-cargo-wire-re.md`, `docs/inventory-grid-footprint.md` |

---

## WQ-006 â€” Interaction / activation (placeholder)

| Field | Value |
|-------|-------|
| ID | WQ-006 |
| System | interaction-activation |
| Priority score | 78 |
| Status | **partial** (system map + UseObject duals 2026-07-29; runtime open) |
| Artifacts | `systems/interaction-activation.md`; `aa_00916740`, `aa_00930d70` three-rep + duals |
| Next action | Runtime interact capture; type-4 objective 0 vs −1 wire live; UseObject/IfInteractable/Activate 15f dual residual sealed wave2 |
| Sealed | FindActiveObjectiveIdForInteract `aa_00524520` + MatchTargetEvaluators `aa_0059d9c0` three-rep + dual |

---

## WQ-007 â€” Missions managers (high-priority wave)

| Field | Value |
|-------|-------|
| ID | WQ-007 |
| System | missions-progression |
| Target | Client mission lifecycle managers: auto-grant, prereqs, give/fail, objectives, dialog, journal |
| Address / symbol | Entry set: `SearchAutoMissions` `0x00532b60`, `CheckMissionPrerequisites` `0x00536540`, `CheckMissionRequirements` `0x005462b0`, `GiveMission` `0x005327c0`, `AddActiveObjective` `0x00531b00`, `CompleteMissionObjectives` `0x00536080`, `EvaluatePendingObjectives` `0x00534920`, `HasCompletedMission` `0x0052aa20`, `FailMission` `0x0052da30`, `RecvObjectiveState` `0x00809460`, `RecvNpcMissionDialog` `0x00815070`, `MissionDialogHandleButton` `0x008ae7c0`, `UpdateMissionJournal` `0x008ae130` |
| Priority score | **96** |
| User-facing impact | Direct progression: grant, complete, fail, dialog, journal |
| State mutation | High (character mission hashes / active / pending objectives) |
| Comm / persistence | Medium (S2C `0x206D`/`0x2071`; UI toasts) |
| Status | **partial** (0x206E + abandon + collect bridge + modal + dialog/journal residual duals 2026-08-04; runtime open; not full system coverage) |
| Dependencies | None blocking |
| Next action | Runtime when Launcher approved; residual UseItem/Escort runtime correlation; English field labels on dialog widgets |
| System map | `systems/missions-progression.md` |
| Sealed this wave | C2S `0x206E`; abandon; Collect; Deliver; modal; Prerequisites dual |
| Sealed 2026-08-04 residual | 16 undualed dialog/journal/give/complete-path duals (tip, caption, buttons, markup, tokens, race/class, mselect, key display, UseItem apply, Escort HB) — see `WAVE_2026-08-04_wq007_residual_partition_map.md` |

---

## WQ-008 â€” Inventory managers (high-priority wave)

| Field | Value |
|-------|-------|
| ID | WQ-008 |
| System | inventory-transfer |
| Target | Grid inventory managers: grab/drop/equip/add + footprint place/find + cargo create |
| Address / symbol | Entry set: Grab `0x00860e20`, Drop `0x00860a50`, DropResponse `0x00813730`, GrabResponse `0x00811be0`, AddItem `0x008151a0`, Equip `0x00813f40`, Unequip `0x00813bf0`, PlaceFootprint `0x00571620`, FindFreeSlot `0x005713a0`, AllocateCellArray `0x00570720`, CreateCargo `0x004f3a30` (+ ctor inferred) |
| Priority score | **94** |
| User-facing impact | Direct item transfer, equip, cargo grid placement |
| State mutation | High (grid cells, cursor/stack, equip slots) |
| Comm / persistence | High (C2S `0x2034`/`0x2036`; S2C responses) |
| Status | **partial** (grab/drop duals refreshed; collect cargo count bridge sealed; place duals prior; runtime open) |
| Dependencies | Overlaps WQ-005 (transfer path is a subset) |
| Next action | Runtime grab/drop/add capture when Launcher approved; Collect_Action/Deliver dual residual sealed wave2 (static) |
| System map | `systems/inventory-transfer.md` |
| Prior art | `docs/inventory-cargo-wire-re.md`, `docs/inventory-grid-footprint.md` |
| Sealed this wave | Grab `0x2034` / Drop `0x2036` dual quality; `InventoryGrid_CountItemsByCbid` collect bridge |

---

## WQ-009 â€” Skills managers (high-priority wave)

| Field | Value |
|-------|-------|
| ID | WQ-009 |
| System | skills-abilities |
| Target | Skill cast / quick-bar / local validate / target resolve managers |
| Address / symbol | Entry set: QuickBarActivate `0x00921b50`, RequestCast `0x00941590`, CastFromQuickBar `0x009418e0`, LocalCastValidate `0x0051a790`, ValidateTarget `0x00553650`, ResolveTargets `0x0054c570`, GatherTargetsInArea `0x0058d330`, CastSkillOnTarget `0x004d09a0` |
| Priority score | **93** |
| User-facing impact | Direct combat/utility cast initiation and targeting |
| State mutation | Mediumâ€“High (cast bindings, cooldowns, local FX) |
| Comm / persistence | Medium (cast request packets; S2C status effects) |
| Status | **partial** (ValidateTarget dual sealed with asm ABI fix; LocalCastValidate prior; runtime open; not full cast SM) |
| Dependencies | Input binds (DriveControlTick may call QuickBar path) |
| Next action | LocalCast leave-FUN unless string/RTTI; vtbl+0x44 handler catalog; runtime cast; FormatFailure/ValidateTarget residual sealed wave2 |
| System map | `systems/skills-abilities.md` |
| Sealed this wave | `Skill_ValidateTargetForSkill` asm ABI (AL polarity, handler codes); 3 evidence renames |

---

## WQ-PHY â€” Physics verified corpus (indexed, not primary)

| Field | Value |
|-------|-------|
| ID | WQ-PHY |
| System | physics-vehicle (infrastructure) |
| Status | `deferred` (preserved under `physics/`; not primary next) |
| Rationale | Deep prior RE; lower default priority unless selected high-level behavior depends on it |
| Index | `physics/verified/INDEX.md`, `physics/README.md` |

---

## Selection rule

Highest actionable non-deferred work: **runtime captures** (Launcher approval) for dialog/grab/cast/drive; WQ-008/WQ-009 residual undualed callees; continue dual depth on nested managers; soft-steer **label** UF-006 (body High; label open). Physics **deferred**. Inventory stamp ≠ full verified depth (**deep dual pairs 2209 ≪ 25666**).

