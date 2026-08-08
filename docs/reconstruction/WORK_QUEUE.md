# Work Queue

Priority model: user-facing systems first (input → movement → interaction → inventory → …). Physics/rendering/allocators only when a selected high-level behavior requires them.

Status values: `queued` | `active` | `blocked` | `partial` | `done` | `deferred`

**Coverage honesty:** Live Ghidra **25671** (sizing). Dual A∩B **2726** = review-depth **byproduct**, not a goal. Inventory `full`/`reviewed`/`terminal_full_coverage` = accounting only — **not** verification complete. Scaffolds/placeholders must not raise completion metrics. Runtime **open**. Residual dual volume waves **frozen**. Prefer user-facing WQ verification over dual % growth.

**Audit rating:** **PARTIAL FAILURE** — see `docs/reconstruction/audits/CURRENT_AUDIT.md`.

---

## WQ-AUDIT-001 — Progress vocabulary + metric honesty (P0)

| Field | Value |
|-------|-------|
| ID | WQ-AUDIT-001 |
| System | process-integrity |
| Target | CAP-001 / CAP-003 — status vocabulary + dual recount single source of truth |
| Priority score | **100** |
| Status | **active** (audit session) |
| Evidence | `audits/CURRENT_AUDIT.md`, F-001/F-003 |
| Next action | Keep progress.json dual == filesystem; banner all top-level status docs; never treat `full` as verified |

---

## WQ-AUDIT-002 — Inventory dual / reviewed reconciliation (P0)

| Field | Value |
|-------|-------|
| ID | WQ-AUDIT-002 |
| System | process-integrity |
| Target | CAP-002 — mark dualed VAs in inventory (`reviewed` or `dual=true`) |
| Priority score | **99** |
| Status | **done** (2026-08-05 bulk promote: dualed `full`→`reviewed`; reviewed=dual=2726) |
| Dependencies | WQ-AUDIT-001 recount |
| Next action | Keep invariant: dual A∩B count == inventory `reviewed` count (or document deliberate exceptions) |

---

## WQ-AUDIT-003 — Freeze residual STL dual waves (P0)

| Field | Value |
|-------|-------|
| ID | WQ-AUDIT-003 |
| System | process-priority |
| Target | CAP-004 — stop R13-style undualed FUN_*/STL leaf dual volume |
| Priority score | **98** |
| Status | **active** (freeze applied; R13 sealed; no R14) |
| Next action | No new residual dual partitions; prefer user-facing WQ-001..009 verticals over STL leaf dual volume |

---

## WQ-AUDIT-004 — Verification matrix repair (P1)

| Field | Value |
|-------|-------|
| ID | WQ-AUDIT-004 |
| System | process-integrity |
| Target | CAP-007 — truncated matrix rows + schema |
| Priority score | **90** |
| Status | **queued** |
| Next action | Repair `aa_006070e0`, `aa_005711c0`, short rows; move confidence blocks out of main table |

---

## WQ-AUDIT-005 — Ghidra type commit pilot (P1)

| Field | Value |
|-------|-------|
| ID | WQ-AUDIT-005 |
| System | input-drive-control + missions + inventory |
| Target | CAP-006 — apply types for SetSteer/Longitudinal/Handbrake, HasCompletedMission, InventoryGrab |
| Priority score | **91** |
| Status | **queued** |
| Next action | After CAP-001 banners; commit Ghidra signatures to match byte-sealed docs |

---

## WQ-AUDIT-006 — Experiment suite green (P1)

| Field | Value |
|-------|-------|
| ID | WQ-AUDIT-006 |
| System | process-integrity |
| Target | CAP-011 / CAP-017 — dual match + undefined4 clean policy |
| Priority score | **89** |
| Status | **queued** (dual match fixed; undefined4 policy still open) |
| Next action | Fix remaining discover failure on `aa_00922270` clean policy |

---

## WQ-AUDIT-007 — Mode-gate attach `this` (HasCompletedMission + siblings) (P0/P1)

| Field | Value |
|-------|-------|
| ID | WQ-AUDIT-007 |
| System | missions-progression |
| Target | CAP-019 / F-027 — `WeaponAllowsKillXpBonus` ECX = continent attach |
| Address | Mode `0x004ce340`; call sites in `0x0052aa20` (+ GiveMission / AddExperience) |
| Priority score | **97** |
| Status | **partial** — clean `CVOGCharacter_HasCompletedMission.cpp` fixed this audit; siblings + dual notes remain |
| Next action | Re-verify GiveMission/AddExperience plates; update dual A/B if they sealed character-mode; confirm aa_004ce340 field base |

---



## WQ-001 Ã¢â‚¬â€ input-drive-control system map

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
| Comm / persistence | Low (local input Ã¢â€ â€™ entity; push to controller) |
| Crash risk | Medium (null vehicle / UI gates) |
| Confidence | High for map of primary axis path; partial for camera/skill side branches |
| Verification gaps | Full DriveControlTick assembly pass; runtime key-flag correlation |
| Dependencies | None |
| Status | **partial** (map written; deeper DriveControlTick still open) |
| Next action | After WQ-002 reviews land, expand soft-steer and analog-device branches |

---

## WQ-002 Ã¢â‚¬â€ VehicleEntity_SetSteerInput reconstruction unit

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
| Status | **partial** (dual accept-with-gaps; **not complete** — verification-first) |
| Next action | Runtime/diff when Launcher approved; do **not** re-dual or count dual as complete. Re-verify 2026-08-06: live bytes still seal 0xC7 gate + store +0x618 |

---

## WQ-003 Ã¢â‚¬â€ VehicleEntity_SetLongitudinalInput sibling

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
| Next action | Leave dual complete; residual runtime/diff only Ã¢â‚¬â€ do **not** re-emit dual reviews |

---

## WQ-004 Ã¢â‚¬â€ DriveControlTick full vertical trace

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
| Sealed 2026-07-29 | Soft-steer order + Ã‚Â±0.5/Ã‚Â±1.0 immediates dual refresh; UF-006 label map still Probable |

---

## WQ-005 Ã¢â‚¬â€ Inventory grab/drop client path

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

## WQ-006 Ã¢â‚¬â€ Interaction / activation (placeholder)

| Field | Value |
|-------|-------|
| ID | WQ-006 |
| System | interaction-activation |
| Priority score | 78 |
| Status | **partial** (system map + UseObject duals 2026-07-29; runtime open) |
| Artifacts | `systems/interaction-activation.md`; `aa_00916740`, `aa_00930d70` three-rep + duals |
| Next action | Runtime interact capture; type-4 objective 0 vs âˆ’1 wire live; UseObject/IfInteractable/Activate 15f dual residual sealed wave2 |
| Sealed | FindActiveObjectiveIdForInteract `aa_00524520` + MatchTargetEvaluators `aa_0059d9c0` three-rep + dual |

---

## WQ-007 Ã¢â‚¬â€ Missions managers (high-priority wave)

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
| Status | **partial** (0x206E + abandon + collect bridge + modal + dialog/journal residual duals 2026-08-04; runtime open; not full system coverage) |; **mega residual duals 2026-08-05** (missions nested sealed)
| Dependencies | None blocking |
| Next action | Runtime when Launcher approved; residual UseItem/Escort runtime correlation; English field labels on dialog widgets |
| System map | `systems/missions-progression.md` |
| Sealed this wave | C2S `0x206E`; abandon; Collect; Deliver; modal; Prerequisites dual |
| Sealed 2026-08-04 residual | 16 undualed dialog/journal/give/complete-path duals (tip, caption, buttons, markup, tokens, race/class, mselect, key display, UseItem apply, Escort HB) â€” see `WAVE_2026-08-04_wq007_residual_partition_map.md` |

---

## WQ-008 Ã¢â‚¬â€ Inventory managers (high-priority wave)

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
| Status | **partial** (grab/drop duals refreshed; collect bridge sealed; place duals prior; **WQ-008 residual duals 2026-08-04**; runtime open) |
| Dependencies | Overlaps WQ-005 (transfer path is a subset) |
| Next action | Runtime grab/drop/add capture when Launcher approved; residual English on craft/type-0x1a; WQ-009 residual undualed callees |
| System map | `systems/inventory-transfer.md` |
| Prior art | `docs/inventory-cargo-wire-re.md`, `docs/inventory-grid-footprint.md` |
| Sealed this wave | Grab `0x2034` / Drop `0x2036` dual quality; `InventoryGrid_CountItemsByCbid` collect bridge |
| Sealed 2026-08-04 residual | 20 undualed callees dualed (grid move/canplace/remove/set-owner/dirty/dtor; type-0x1a craft/exchange; store add; gadget 0x20A8; craft UI bind/tooltip; COID use; QB cast readiness; hardpoint cast) â€” `WAVE_2026-08-04_wq008_residual_partition_map.md` |

---

## WQ-009 Ã¢â‚¬â€ Skills managers (high-priority wave)

| Field | Value |
|-------|-------|
| ID | WQ-009 |
| System | skills-abilities |
| Target | Skill cast / quick-bar / local validate / target resolve managers |
| Address / symbol | Entry set: QuickBarActivate `0x00921b50`, RequestCast `0x00941590`, CastFromQuickBar `0x009418e0`, LocalCastValidate `0x0051a790`, ValidateTarget `0x00553650`, ResolveTargets `0x0054c570`, GatherTargetsInArea `0x0058d330`, CastSkillOnTarget `0x004d09a0` |
| Priority score | **93** |
| User-facing impact | Direct combat/utility cast initiation and targeting |
| State mutation | MediumÃ¢â‚¬â€œHigh (cast bindings, cooldowns, local FX) |
| Comm / persistence | Medium (cast request packets; S2C status effects) |
| Status | **partial** (ValidateTarget dual sealed; LocalCastValidate prior; **WQ-009 residual through depth-9 duals 2026-08-05**; runtime open; not full cast SM) |
| Dependencies | Input binds (DriveControlTick may call QuickBar path) |
| Next action | Runtime cast when Launcher approved; or claim next mega residual undualed nested callees / deeper residual beyond depth-9 |
| System map | `systems/skills-abilities.md` |
| Sealed this wave | `Skill_ValidateTargetForSkill` asm ABI (AL polarity, handler codes); 3 evidence renames |
| Sealed 2026-08-04 residual | 20 undualed nested duals (RNG seed window, crew contains, Virus HB, hostile cycle/nearest, skill hash trio load, OnDeath, factions, TFID helpers, material bank neighborhood) â€” `WAVE_2026-08-04_wq009_residual_partition_map.md` |
| Sealed 2026-08-04 depth residual | 20 deeper undualed nested duals (SkillCNDHash recreate/ctor, Virus ctor/SharedHB, tree min/max/rotates, map erase twins, crew insert/clear, presence flags, TraversalUnlock, OnEnd FX clear, RNG sample, combat chat, convoy Invite/Kick, nameplate color, world-clock phase) â€” `WAVE_2026-08-04_wq009_depth_partition_map.md` |
| Sealed 2026-08-05 depth-9 residual | 20 deeper undualed nested duals (isnil131 iterator++/erase; out_of_range; L/R rotate+max isnil31; RDTSC timer; UI dtor leaves; CVOGMenu hash traverse-delete; StdList clear; dialog child-hash; shop slot bind/orient) â€” `WAVE_2026-08-05_wq009_depth9_partition_map.md` |

---

## WQ-PHY Ã¢â‚¬â€ Physics verified corpus (indexed, not primary)

| Field | Value |
|-------|-------|
| ID | WQ-PHY |
| System | physics-vehicle (infrastructure) |
| Status | `deferred` (preserved under `physics/`; not primary next) |
| Rationale | Deep prior RE; lower default priority unless selected high-level behavior depends on it |
| Index | `physics/verified/INDEX.md`, `physics/README.md` |

---

## Selection rule

**Post-audit (2026-08-05):** Highest actionable work is **WQ-AUDIT-001..003** (metric honesty + dual freeze), then user-facing vertical residuals on WQ-001..009 (not STL leaf dual volume). **Runtime captures** when Launcher approved. Soft-steer label UF-006 remains open. Physics **deferred**. Inventory stamp ≠ dual depth ≠ runtime confirmed (dual **~2724 ≪ 25671**).

---

## MEGA residual dual seal (2026-08-05) - **complete**

| Field | Value |
|-------|-------|
| Scope | Nested undualed callees of dualed WQ-007/008/009 managers (EXP-M/I/S/X/GAP/D -> 140 VAs) |
| Partition | `reviews/WAVE_2026-08-05_mega_residual_partition_map.md` |
| Dual sealed | **140 / 140** |
| Open residual | **none** (final residual `0x00589bc0` MEGA-005 `Skill_HB_ApplyHeatDelta_Inferred` sealed MERGE-MEGA-005) |
| Dual unique | **2428 -> 2568** (+140) |
| ADV | `ADV_mega_spotcheck.md` **8/8 PASS** |
| Systems | missions 41, skills 37, inventory 23, interaction 23, input 16 |
| Status | **mega dual seal complete** - dual depth advanced; runtime/diff still open; terminal **false** |
| Next | Claim next undualed residual wave or runtime when Launcher approved |
| Merge report | `docs/agents/task-merge-mega-residual-report.md` |
| Final residual report | `docs/agents/task-merge-mega-005-final-report.md` |

WQ-007 / WQ-008 / WQ-009 residual manager waves remain **partial** (not full system English). Mega nested duals sealed into system maps and VERIFICATION_MATRIX.
