# Dual A/B review batch — Net_* / CLoad* / Phy_* / hkDefault* / Weapon_* (cap 30)

**Date:** 2026-07-23  
**Scope:** Remaining high-value **named managers** still missing both standard `A_aa_*` and `B_aa_*`, preferring **Vehicle-related hkDefault\***, **Skill-adjacent Weapon_***, **CLoad\***, **Phy\***, **Net\***.  
**Prefer:** ghost pack/unpack, load-node pipeline, physics init/preload, brake/driver-input, weapon heat cost.  
**Excluded:** Launcher (never). String-literal Skill_* / Combat_* UI dumps demoted.  
**Cap:** 30 pairs (60 files).

## Selection

Pre-batch dual count: **431** modern A_/B_ pairs (then concurrent waves may have advanced the global count).  
Family scan (Stable ID from clean plates) found large dual-missing sets under preferred prefixes dominated by string-dump renames; this wave filtered for:

* Semantic manager names (`Net_Unpack*`, `CLoadNode__*`, `Phy_*`, `CPhysXBase_*`, `hkDefault*`, `Weapon_*`)
* Real CF / body size
* AutoCore-relevant contracts (ghost masks, heat fire gate, load stages, brake)

Already dual from prior vehicle waves (not rewritten): all `Vehicle_*` / `VehicleNet_*` / `VehicleAction_*` / `hkVehicleFramework_*` clean units with duals; Skill cast stack from mission/skill waves.

## Pairs written

| # | Stable ID | Name | System | A verdict | B notes |
|---|---|---|---|---|---|
| 1 | `aa_0060a820` | Net_UnpackGhostUpdate | networking | accept-with-gaps | Distinct from vehicle UnpackGhostVehicle |
| 2 | `aa_0060a230` | Net_PackInitialCharacterUpdate | networking | accept-with-gaps | Initial create pack, not delta |
| 3 | `aa_00781c30` | Net_GhostConnection | networking | accept-with-gaps | Connection hub ≠ object unpack |
| 4 | `aa_005b17b0` | Net_UnpackGhostUpdate_005b17b0 | networking | accept-with-gaps | Sibling VA to 0060a820 |
| 5 | `aa_005b10a0` | Net_GhostObject_getUpdatePriority | networking | accept-with-gaps | Dist/self → priority formula |
| 6 | `aa_00786c10` | NetObject_SetMaskBits | networking | accept-with-gaps | OR +0x18/+0x1c; dirty list |
| 7 | `aa_005b0d70` | GhostObject_OnGhostAdd | networking | accept-with-gaps | +0x50 vtbl+0x2b8 else spatial |
| 8 | `aa_009493c0` | Net_InitNetworking_sector | networking | accept-with-gaps | Sector bring-up, not ghost fields |
| 9 | `aa_004bfe10` | CLoadQueue_Update | client-load | accept-with-gaps | 9 buckets; dt-sliced |
| 10 | `aa_005c76f0` | CLoadNode__initPhysics | client-load | accept-with-gaps | Wait +0x14c; type 0xE special |
| 11 | `aa_005c78a0` | CLoadNode__initFull | client-load | accept-with-gaps | Wait +0x160 |
| 12 | `aa_005c72f0` | CLoadNode__initPreload | client-load | accept-with-gaps | Wait +0x174; FUN_004eb3b0 |
| 13 | `aa_005c6a10` | CLoadNode__initPostCreateMsg | client-load | accept-with-gaps | Apply blob@+0x6c then delete |
| 14 | `aa_005c6880` | CLoadNode_initAI | client-load | accept-with-gaps | vtbl+0xc0 HBAI attach |
| 15 | `aa_005c7400` | CLoadNode__initAnim | client-load | accept-with-gaps | Wait +0x138; vtbl+0x20 |
| 16 | `aa_005c67b0` | CLoadNode__recalculateInitAI | client-load | accept-with-gaps | Sets +0x64 only |
| 17 | `aa_005c6960` | CLoadNode__initSelection | client-load | accept-with-gaps | Thin FUN_0051aed0 |
| 18 | `aa_005c69e0` | CLoadNode__initPostPreload | client-load | **accept** | Flag +0x68 only |
| 19 | `aa_004ec7b0` | Phy_CollectAllPhysicsPreloads | physics | accept-with-gaps | Path collect + eb3b0 |
| 20 | `aa_009463b0` | Phy_Start_ReinitPhysics | physics | accept-with-gaps | Map-transition teardown |
| 21 | `aa_00932060` | Phy_Inside_InitPhysics | physics | accept-with-gaps | Init body; unaff_ESI residual |
| 22 | `aa_004f1c70` | Phy_Preload_ReloadRigidBody | physics | accept-with-gaps | RB reload pipeline |
| 23 | `aa_00467820` | Phy_BoundingVolumeFactory_CreateFromTag | physics | accept-with-gaps | Tags 1..5 factory |
| 24 | `aa_004b5220` | CPhysXBase_Step | physics | accept-with-gaps | ~1/30; one-shot flag |
| 25 | `aa_004b50f0` | CPhysXBase_RenderResults | physics | accept-with-gaps | Debug/vis not sim |
| 26 | `aa_005fe0b0` | hkDefaultAnalogDriverInput_calcReverse | input-drive-control | accept-with-gaps | Reverse flag out |
| 27 | `aa_005fe520` | hkDefaultAnalogDriverInput_calcStatus | input-drive-control | accept-with-gaps | brake/accel/steer/HB status |
| 28 | `aa_0064e6f0` | hkDefaultBrake_update | input-drive-control | accept-with-gaps | WI-MOV-005 pedal/HB torques |
| 29 | `aa_0056aca0` | Weapon_CanFireHeatCheck | inventory-transfer | **accept** | heat+0x150 < max+0x244 |
| 30 | `aa_0056ad00` | Weapon_ApplyShotHeatAndPowerCost | inventory-transfer | accept-with-gaps | 0xE gate; check→power→AddHeat |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **Ghost dirty API sealed:** `NetObject_SetMaskBits` ORs **+0x18 lo / +0x1c hi** and splices into `g_pNetObjectDirtyListHead` when masks were previously clear. Combat masks: POWER `0x08000000`, SHIELD `0x04000000`, HEAT `0x20000000`.
2. **Ghost unpack siblings:** keep **`0x0060a820`**, **`0x005b17b0`**, and **`VehicleNet_UnpackGhostVehicle` (`0x005f7720`)** distinct — different object families / payloads.
3. **Update priority:** `getUpdatePriority` returns **1.0** for self/parent/child/TFID match; else distance-scaled with ghost weight **+0x58** and viewer range fields.
4. **CLoad pipeline stage keys (clonebase offsets):** preload **+0x174**, anim **+0x138**, physics **+0x14c**, full **+0x160**; queue is **9** dt-sliced buckets @ queue+0x8.
5. **initAI:** host vtbl **+0xc0** attaches HBAI; **recalculateInitAI** only sets flag **+0x64** (does not attach).
6. **Weapon fire costs (player vehicle type 0xE):** `CanFireHeatCheck` (`veh+0x150 < +0x244`) → optional power **weapon+0xD6** → `Vehicle_AddHeat(weapon+0xD4)`. Non-0xE returns success without costs.
7. **hk brake vs entity handbrake:** `hkDefaultBrake_update` consumes framework status pedal/HB; **distinct** from `VehicleEntity_SetHandbrake` (**entity+0x61c**).
8. **CPhysXBase_Step:** fixed dt **`0x3d088889` (~1/30)** and **one-shot** flag `this[2]`; `RenderResults` is vis/debug not integration.

## Breakdown by family

| Group | Count |
|---|---:|
| Net_* / Ghost* / NetObject_* | 8 |
| CLoadQueue / CLoadNode_* | 10 |
| Phy_* / CPhysXBase_* | 7 |
| hkDefaultAnalogDriverInput_* / hkDefaultBrake_* | 3 |
| Weapon_* heat path | 2 |

(Counts: **30** total.)

## Not done (still dual-missing samples)

| Name | Notes |
|---|---|
| Many `Skill_*` / `Combat_*` string-dump UI plates | low dual value |
| `Net_Nazgul_*` include/session string units | medium; protocol layer |
| `Phy_PhysX_*` path/error string units | low |
| `hkDefaultChassis_vtbl_*` thin stubs | low |
| `hkDefaultAnalogDriverInput_ctor` / `update_candidate` | thin leftovers |
| `Experience_*` table helpers / `Character_GetTechForPoolCalcs` | high value next wave |
| `CreateSimpleObject_Serialize*` | large; good next |
| `DB_ReadPowerPlantSpecific` | high value next |

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (**60** new files)
- Writer: `tmp/write_dual_reviews_net_cload_phy.py`
- Source extracts: `tmp/dual_batch_net_cload_phy_sources/`
- Report: `docs/agents/task-dual-ab-net-cload-phy-report.md`
- Post-batch dual count: **469** A_/B_ pairs on disk (includes any concurrent waves)
- **No Launcher** touched; no servers started.
