# Dual A/B review batch — Vehicle thin units + Skill_Uses_* (cap 25)

**Date:** 2026-07-23  
**Scope:** Remaining **thin Vehicle_*** / **VehicleEntity_*** combat-pool and drive-axis units still missing both standard `A_aa_*` and `B_aa_*`, plus all **Skill_Uses_*** string-alias clean units, with related thin companions and leftover vehicle physics/net fills to the 25-pair cap.  
**Prefer:** regen getters, hardpoint fire query, handbrake, Skill_Uses ledger closure.  
**Excluded:** Launcher (never).  
**Cap:** 25 pairs (50 files).

## Selection

Pre-batch dual count: **394** modern A_/B_ pairs.  
Prior vehicle/QB/skill wave left explicit dual-missing samples:

| Name | Notes |
|---|---|
| `Vehicle_GetHpRegenRate` / `GetShieldRegenRate` / `GetPowerRegenRate` / `GetCoolRate` | thin regen getters |
| `Vehicle_IsAnyWeaponFiring` | hardpoint fire query |
| `VehicleEntity_SetHandbrake` / `SetFlag_109` | tiny ungated stores |
| `Skill_Uses_*` | string-alias bulk |

Also dual-missing: real thin `SkillSet_GetEntryCount`, creature HP-regen glue, and several vehicle physics/net leftovers used to fill the cap.

## Pairs written

| # | Stable ID | Name | System | A verdict | B notes |
|---|---|---|---|---|---|
| 1 | `aa_004fb630` | Vehicle_GetHpRegenRate | inventory-transfer | **accept** | race-item short **+0x3FA**; null→0 |
| 2 | `aa_004fb600` | Vehicle_GetShieldRegenRate | inventory-transfer | **accept** | same walk; short **+0x4B6** |
| 3 | `aa_004f3870` | Vehicle_GetPowerRegenRate | inventory-transfer | **accept** | plant **+0xB8**; no plant→**1** |
| 4 | `aa_004f3840` | Vehicle_GetCoolRate | inventory-transfer | **accept** | plant cool + adjust; no plant→adjust+1 |
| 5 | `aa_004f7480` | Vehicle_IsAnyWeaponFiring | inventory-transfer | accept-with-gaps | turret **+0x264** + HP0..2; flag **+0xC7** |
| 6 | `aa_004f3620` | VehicleEntity_SetHandbrake | input-drive-control | **accept** | ungated **+0x61c** (no 0xC7) |
| 7 | `aa_004f3630` | VehicleEntity_SetFlag_109 | input-drive-control | accept-with-gaps | store **+0x109**; meaning open |
| 8 | `aa_004c4860` | Creature_GetHpRegenFromEquippedRaceItem | inventory-transfer | **accept** | vehicle **+0x250** → GetHpRegenRate else **1** |
| 9 | `aa_00402d80` | SkillSet_GetEntryCount | skills-abilities | **accept** | real thin; stride **0x18** |
| 10 | `aa_00412730` | Skill_Uses_SkillSet_GetEntryCount | skills-abilities | accept-with-gaps | string alias ≠ thin VA |
| 11 | `aa_0041e210` | Skill_Uses_SkillSet_GetEntryCount_0041e210 | skills-abilities | accept-with-gaps | bulk alias |
| 12 | `aa_00440f80` | Skill_Uses_SkillSet_GetEntryCount_00440f80 | skills-abilities | accept-with-gaps | bulk alias (may *call* real) |
| 13 | `aa_00442760` | Skill_Uses_SkillSet_GetEntryCount_00442760 | skills-abilities | accept-with-gaps | bulk alias |
| 14 | `aa_00454f30` | Skill_Uses_SkillSet_GetEntryCount_00454f30 | skills-abilities | accept-with-gaps | bulk alias |
| 15 | `aa_00455c90` | Skill_Uses_SkillSet_GetEntryCount_00455c90 | skills-abilities | accept-with-gaps | bulk alias |
| 16 | `aa_0046bba0` | Skill_Uses_SkillSet_GetEntryCount_0046bba0 | skills-abilities | accept-with-gaps | bulk alias |
| 17 | `aa_004c8a60` | Skill_Uses_Skill_EnsureLoadedInTree | skills-abilities | accept-with-gaps | real unit is **aa_0051a980** |
| 18 | `aa_004d1b80` | Skill_Uses_CVOGReaction_ResolveSkillTargets | skills-abilities | accept-with-gaps | real unit is **aa_0054c570** |
| 19 | `aa_004a9750` | VehicleEngine_torqueCurve2D | input-drive-control | accept-with-gaps | AA 2D table; no hk engine |
| 20 | `aa_00636a60` | VehicleAction_tickSubsystems | input-drive-control | accept-with-gaps | **this = framework** (WI-MOV-003) |
| 21 | `aa_00597f90` | VehicleAction_ctor | input-drive-control | accept-with-gaps | ctor; param map residual |
| 22 | `aa_005f9ed0` | VehicleNet_TriggerReplay | input-drive-control | accept-with-gaps | malloc+memcpy replay blob |
| 23 | `aa_00598040` | VehicleAction_calcWheelTorque | input-drive-control | accept-with-gaps | AA torque via curve |
| 24 | `aa_00598320` | VehicleAction_airStabilization | input-drive-control | accept-with-gaps | ≠ SetHandbrake |
| 25 | `aa_005f9f10` | VehicleNet_ReconcilePrediction | input-drive-control | accept-with-gaps | client prediction realign |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **Combat-pool regen quartet sealed as pure getters:**
   - HP: race-item walk **veh+0x270 → clonebase+0xAC → sub+0x3C → i16@+0x3FA** (null→**0**)
   - Shield: same walk, **i16@+0x4B6**
   - Power: plant **+0x268 / +0xB8** (null plant→**1**)
   - Cool: **plant.cool + veh.adjust** (null plant→**adjust+1**); adjust **+0x1E4**, plant cool **+0xBA**
2. **Creature HP glue:** `creature+0x250` vehicle → `GetHpRegenRate`, else **1** (not 0).
3. **Firing slows cool (caller-side):** `IsAnyWeaponFiring` checks turret **+0x264** then hardpoints **+0x260[0..2]** via weapon firing char **+0xC7**.
4. **Drive axes completeness:** thr **+0x614** / steer **+0x618** (gated **0xC7**) + HB **+0x61c** (**ungated** `SetHandbrake`). `SetFlag_109` is a different byte (**+0x109**), meaning still open.
5. **Skill_Uses_* are ledger aliases, not product APIs:**
   - Real length helper: `SkillSet_GetEntryCount` **`aa_00402d80`** — `(end-begin)/0x18`
   - Real ensure-load: **`aa_0051a980`**
   - Real resolve-targets: **`aa_0054c570`**
   - Do **not** wire `Skill_Uses_*` VAs as drop-ins for those names.
6. **Physics leftovers:** AA `torqueCurve2D` + `calcWheelTorque` replace stock hk engine; `tickSubsystems` is **hkVehicleFramework** tick (7 children), not VehicleAction `this`.

## Breakdown by family

| Group | Count |
|---|---:|
| Vehicle_* combat-pool thin getters / query | 5 |
| VehicleEntity_* tiny stores | 2 |
| Creature regen glue | 1 |
| SkillSet_GetEntryCount (real thin) | 1 |
| Skill_Uses_* string aliases | 9 |
| VehicleAction_* / Engine / Net fill | 7 |

(Counts: 25 total.)

## Not done (still dual-missing samples)

| Name | Notes |
|---|---|
| `VehicleAction_applyAction` | large (~900 lines) apply path |
| `VehicleNet_PostCorrectionEvent` / `UnpackGhostVehicle` | large net |
| `VehicleDb_LoadCloneBase` | decomp failed in clean |
| `Named_CalleeOf_Skill_Uses_*` bulk children | low dual value |
| Remaining string-dump Vehicle renames | prose filter excluded |

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (50 new files)
- Writer: `tmp/write_dual_reviews_vehicle_thin_skill_uses.py`
- Report: `docs/agents/task-dual-ab-vehicle-thin-skill-uses-report.md`
- Post-batch dual count: **419** (was 394)
- No Launcher touched; no servers started.
