# Dual A/B review batch — Vehicle_* / QuickBar_* / Skill_* (cap 25)

**Date:** 2026-07-23  
**Scope:** Remaining high-value **Vehicle_*** / **VehicleEntity_*** / **QuickBar_*** / **Skill_*** units still missing both standard `A_aa_*` and `B_aa_*` under `docs/reconstruction/reviews/`, after the MSID/Named wave2 batch.  
**Prefer:** physics setup, enter-world activate, combat pools, drive axes, QB cooldown/chrome, non-creature cast.  
**Excluded:** Launcher (never). String-literal bulk renames demoted. Weak `Skill_Uses_*` aliases left for a later low-value pass.  
**Cap:** 25 pairs (50 files).

## Selection

Pre-batch: **361** existing duals. Family scan found **35** real-name dual-missing candidates (Vehicle 28 / QuickBar 3 / Skill 4 after prose filter). Top body/CF units selected first; wave2 holdouts (`buildHavokVehicleFramework`, `TryActivatePhysics`, `Build*Descriptor`, QB siblings) prioritized.

Already dual from prior waves (not rewritten): `Vehicle_EquipFromCreate`, `Vehicle_SetWheelset`, `Vehicle_EquipPowerPlant`, `Vehicle_SetEquippedArmor`, `VehicleEntity_PushDriveAxesToController`, `QuickBar_UpdateSkillSlotCooldownGauge`, `QuickBar_BuildSkillButtonWidgets`, full Skill cast/CD/rank core, etc.

## Pairs written

| # | Stable ID | Name | System | A verdict | B notes |
|---|---|---|---|---|---|
| 1 | `aa_005fd390` | Vehicle_buildHavokVehicleFramework | input-drive-control | accept-with-gaps | Sole hkVehicle assembly; no hkEngine; +0x110 governor |
| 2 | `aa_00501420` | Vehicle_TryActivatePhysics | input-drive-control | accept-with-gaps | Physics enter gate; param_2–4 residual |
| 3 | `aa_00503f30` | Vehicle_ActivateEnterWorld | input-drive-control | accept-with-gaps | Token + 30 ms weapon track + 3s/5s combat pool; heat/shield reset |
| 4 | `aa_00505270` | Vehicle_applyCreatePacket | inventory-transfer | accept-with-gaps | Create pkt apply; relative base map open |
| 5 | `aa_005fcff0` | Vehicle_BuildSuspensionDescriptor | input-drive-control | accept-with-gaps | Framework step 7; 0x68 suspension |
| 6 | `aa_00827ab0` | QuickBar_UpdateSlotCooldownOverlay | skills-abilities | accept-with-gaps | type1 skill / type2 item; +0x548 |
| 7 | `aa_005fc840` | Vehicle_BuildTransmissionDescriptor | input-drive-control | accept-with-gaps | Gear ratios; framework step 5 |
| 8 | `aa_004ceba0` | Skill_NonCreatureCastAutoHit | skills-abilities | accept-with-gaps | Inanimate AutoHit; null atk/vic gates |
| 9 | `aa_005fc710` | Vehicle_BuildSteeringDescriptor | input-drive-control | accept-with-gaps | maxSteer cb×entity; +0x5f0 wheel bits |
| 10 | `aa_00825e00` | QuickBar_BuildItemButtonWidgets | skills-abilities | accept-with-gaps | Item QB chrome XMLs |
| 11 | `aa_004fdf20` | Vehicle_AttachWeapon | inventory-transfer | accept-with-gaps | +0x260 slots 0..2; type 0xc |
| 12 | `aa_005002d0` | Vehicle_CalcMaxHitPoints | inventory-transfer | accept-with-gaps | Player race/class/tech/armor formula |
| 13 | `aa_004fb660` | Vehicle_createVehicleAction | input-drive-control | accept-with-gaps | +0x1a0 {action, framework, input} |
| 14 | `aa_008274c0` | QuickBar_ClearActiveSlot_INFERRED | skills-abilities | accept-with-gaps | Clear item+skill; row×10+col |
| 15 | `aa_004f7210` | Vehicle_AddHeat | inventory-transfer | accept-with-gaps | Clamp [0,2×Max]; HeatMask 0x20000000 |
| 16 | `aa_004f5650` | VehicleEntity_SetLongitudinalInput | input-drive-control | accept-with-gaps | +0x614 gated 0xC7 |
| 17 | `aa_004f5620` | VehicleEntity_SetSteerInput | input-drive-control | accept-with-gaps | +0x618 gated 0xC7 |
| 18 | `aa_00501f60` | Vehicle_RecalcCombatPools | inventory-transfer | accept-with-gaps | Post-equip max HP; skip +0x2ac |
| 19 | `aa_004f7360` | Vehicle_CalcHeatMaximum | inventory-transfer | accept-with-gaps | Plant + race tables + +0x1e0 |
| 20 | `aa_004f7e10` | Vehicle_EnsureRegenerationHeartbeat | inventory-transfer | accept-with-gaps | Once @ +0x27C combat pool HB |
| 21 | `aa_005a4f60` | Vehicle_CreateWeaponTrackAction | inventory-transfer | accept-with-gaps | 30 ms track HB; not combat pool |
| 22 | `aa_00419140` | Vehicle_SetCurrentShield | inventory-transfer | **accept** | +0x144 clamp; caller diries 0x04000000 |
| 23 | `aa_0052a9b0` | Vehicle_GetSkillCooldownModifier | skills-abilities | accept-with-gaps | plant+0xCC × category scale |
| 24 | `aa_004fbec0` | VehicleEntity_SetDriveAxes | input-drive-control | accept-with-gaps | Ungated thr/steer/HB + Push |
| 25 | `aa_005fc4f0` | Vehicle_BuildAerodynamicsDescriptor | input-drive-control | accept-with-gaps | 6 floats from clonebase 0x59c–0x5b4 |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **Physics spawn chain:** `createVehicleAction(+0x1a0)` → `buildHavokVehicleFramework` (Wheels→Chassis→Steer Tank|Default→WheelCollide→Trans→Brake→Susp→Aero→AVD→Framework) → **no stock hkEngine**; torque from AA `calcWheelTorque` / `torqueCurve2D`. Speed governor precompute at **entity+0x110**.
2. **Descriptor builders sealed enough for parity:** Steering (maxSteer **cb+0x594/598 × entity+0x208/20c**, tank split **chassis+0x4cc**, bits from **+0x5f0**); Transmission gear tables; Suspension 0x68; Aero 6 floats **0x59c–0x5b4**.
3. **Enter-world HB nest:** `ActivateEnterWorld` creates token (300s), **weapon track 30 ms**, combat pool **3s/5s by race**; zeros heat **+0x150/+0x154**, fills shield **+0x144←+0x148**. `EnsureRegenerationHeartbeat` is once-only @ **+0x27C**.
4. **Drive axes contract:** Gated singles **SetLongitudinalInput(+0x614)** / **SetSteerInput(+0x618)** with suppress mask **0xC7**; bulk **SetDriveAxes** always stores thr/steer/HB then **PushDriveAxesToController** (ungated).
5. **Combat pools:** `CalcMaxHitPoints` player formula (base 60, race/class/tech/armor); `RecalcCombatPools` after armor/race equip (skip **+0x2ac**); `AddHeat` clamp **[0, 2×Max]** + **HeatMask 0x20000000**; `SetCurrentShield` clamp only — **caller** diries **ShieldMask 0x04000000**.
6. **Weapons:** `AttachWeapon` slots **0..2** @ **+0x260**, type **0xc**, track words **+0x630/+0x634**.
7. **QuickBar:** Overlay splits **type1 skill / type2 item** at **+0x548**; item path cargo lookup; shares category CD + plant CD modifier with skill gauge. Clear slot zeros payload and both item/skill arrays (`row*10+col`).
8. **Skill cast edge:** `NonCreatureCastAutoHit` is structure/inanimate AutoHit path (null gates + inanimate string), not the creature accuracy formula.

## Breakdown by family

| Group | Count |
|---|---:|
| Vehicle_* physics/setup | 8 |
| Vehicle_* combat pools / equip | 8 |
| VehicleEntity_* drive axes | 3 |
| QuickBar_* | 3 |
| Skill_* | 1 |
| Vehicle_* skill CD modifier | 1 |
| Vehicle_* create/attach | 1 |

(Counts: 25 total.)

## Not done (still dual-missing samples)

| Name | Notes |
|---|---|
| `Vehicle_GetHpRegenRate` / `GetShieldRegenRate` / `GetPowerRegenRate` / `GetCoolRate` | thin regen getters; medium value |
| `Vehicle_IsAnyWeaponFiring` | hardpoint fire query |
| `VehicleEntity_SetHandbrake` / `SetFlag_109` | tiny ungated stores |
| `Skill_Uses_*` string-alias bulk | low dual value |
| Remaining Vehicle string-dump renames | prose filter excluded |

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (50 new files)
- Writer: `tmp/write_dual_reviews_vehicle_qb_skill.py`
- Source extracts: `tmp/dual_batch_vehicle_qb_skill_sources/`
- Report: `docs/agents/task-dual-ab-vehicle-qb-skill-report.md`
- Post-batch dual count: **386** (was 361)
- No Launcher touched; no servers started.
