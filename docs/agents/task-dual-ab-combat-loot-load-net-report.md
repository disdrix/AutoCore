# Dual A/B review batch — combat / loot / load / net named managers (30)

**Date:** 2026-07-23  
**Scope:** Remaining high-value **named managers** still missing both standard `A_aa_*` and `B_aa_*`, preferring **combat**, **loot**, **load**, **net-adjacent** (ghost/step/create-msg, DB weapon/armor/clonebase loaders).  
**Excluded:** Launcher (never). String-literal Combat_* / Inv_* UI dumps demoted.  
**Cap:** 30 pairs (60 files).

## Selection

Pre-batch dual count: **503** modern A_/B_ pairs (**495** unique dual addrs).  
Prior waves closed Experience/Tech/Serialize/DB named managers and Net/CLoad stage helpers. This wave filled residual combat fire/heat/AI, loot prefix VA family, inventory grid, CLoad create-msg, sector-map step/generators, and combat gear DB openers.

## Pairs written

| # | Stable ID | Name | System | A verdict |
|---|---|---|---|---|
| 1 | `aa_0091a550` | Input_TryFireSecondaryWeapons | combat | accept-with-gaps |
| 2 | `aa_005a5020` | WeaponTrackAction_OnHeartBeat | combat | accept-with-gaps |
| 3 | `aa_00921580` | UI_UpdateOverheatTip | combat | accept-with-gaps |
| 4 | `aa_005cf560` | CVOGHBAICreatureBase_DoCreaturePursue | combat | accept-with-gaps |
| 5 | `aa_005dae50` | CVOGHBRecreateObject_OnHeartBeat | combat | accept-with-gaps |
| 6 | `aa_00509410` | CVOGLootGenerator_GetTypeFromIDPrefix_00509410 | inventory-transfer | accept-with-gaps |
| 7 | `aa_00509550` | CVOGLootGenerator_GetTypeFromIDPrefix_00509550 | inventory-transfer | accept-with-gaps |
| 8 | `aa_00509680` | CVOGLootGenerator_GetTypeFromIDPrefix_00509680 | inventory-transfer | accept-with-gaps |
| 9 | `aa_005097b0` | CVOGLootGenerator_GetTypeFromIDPrefix_005097b0 | inventory-transfer | accept-with-gaps |
| 10 | `aa_0050f940` | Map_LowerBoundFindByIntKey | inventory-transfer | accept-with-gaps |
| 11 | `aa_00570720` | InventoryGrid_AllocateCellArray_Inferred | inventory-transfer | accept-with-gaps |
| 12 | `aa_00570600` | InventoryGrid_SetOwnerFlag_Inferred | inventory-transfer | accept-with-gaps |
| 13 | `aa_007e7940` | Inv_dcArmor_Open | inventory-transfer | accept-with-gaps |
| 14 | `aa_005c6c70` | Named_LoadNode_setCreateMsg | client-load | accept-with-gaps |
| 15 | `aa_004cd670` | CVOGSectorMap_InitGenerators | client-load | accept-with-gaps |
| 16 | `aa_004d4da0` | CVOGSectorMap_StepCreatures | client-load | accept-with-gaps |
| 17 | `aa_004d3980` | CVOGSectorMap_StepTriggers | client-load | accept-with-gaps |
| 18 | `aa_004d6c80` | CVOGSectorMap_StepTo | client-load | accept-with-gaps |
| 19 | `aa_004d18a0` | CVOGSectorMap_PostPhysX | client-load | accept-with-gaps |
| 20 | `aa_004ec430` | Anim_CollectAllAnimationPreloads | client-load | accept-with-gaps |
| 21 | `aa_007e07b0` | Named_tCloneBase | client-load | accept-with-gaps |
| 22 | `aa_007e0230` | Named_tDamage | combat | accept-with-gaps |
| 23 | `aa_007bfa70` | Named_dcDamage_Insert_MoveFirst | combat | accept-with-gaps |
| 24 | `aa_007e82f0` | Named_dcWeapon_Insert_Open | combat | accept-with-gaps |
| 25 | `aa_007e1630` | Named_vCloneBase_NameList | client-load | accept-with-gaps |
| 26 | `aa_007bfd10` | Named_dcCloneBase_Insert_MoveFirst | client-load | accept-with-gaps |
| 27 | `aa_007e7530` | Named_dcCreature_Insert_Open | combat | accept-with-gaps |
| 28 | `aa_007e7bd0` | Named_dcCharacter_Insert_Open | client-load | accept-with-gaps |
| 29 | `aa_007dfd10` | Named_tCharacter | client-load | accept-with-gaps |
| 30 | `aa_007c3b80` | Named_tCreatureAI | combat | accept-with-gaps |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **Secondary fire path sealed:** `Input_TryFireSecondaryWeapons` requires vehicle `@char+0x250`, live sector net (vtbl+8), flags `+0xb8 & 0xd2 == 0`, then heat check `FUN_004f52e0` before fire `FUN_004f5110`. Heat fail only logs.
2. **Overheat UI uses same pools as CanFire:** vehicle heat **+0x150** vs max **+0x244**; floater `Weapons Overheated!` — presentation only, not the fire gate.
3. **Loot prefix VA family (do not collapse):** shared map `DAT_00b041dc` / end `DAT_00b041e0`, type at node **+0x10**, types `10/0xc/0xe/0x1c/0x44/0x46`:
   - `005092b0` primary (already dual)
   - `00509410` → field **+0x11** (name / GetModifierName)
   - `00509550` → field **+0x44**
   - `00509680` → **byte** at entry **+0x10**
   - `005097b0` → field **+0x70** (null-checked)
4. **Map lower_bound layouts differ:** `Map_LowerBoundFindByIntKey` node flag **+0x15** vs `StdMap_LowerBoundByIntKey_INFERRED` **+0x1d** — loot/XP maps use the +0x15 variant.
5. **Inventory grid empty init:** cells **8 bytes**, fill **0xFFFFFFFF**, dims `+0x08/+0x0C/+0x10/+0x14/+0x18/+0x1C`, array `+0x28`; owner flag setter writes **+0x4** (clean scaffold may omit write — prefer annotated raw).
6. **CLoad create-msg opcodes:** `setCreateMsg` handles **0x2012** (0xD8 SimpleObject), **0x2013** (0x930 + recalculateInitAI), **0x2015** (0x1a8); stores blob at node **+0x6c**; unknown logs.
7. **Sector step graph:** `StepTo` → substep loop (`FUN_00561910`/`00561b60`/`StepCreatures`) → `StepTriggers`; autodelete creatures after **0x77a1** ms staleness; `InitGenerators` builds global creature gen `DAT_00b037ec` (0x2c) + loot gen `DAT_00b037e8` (0xbc).
8. **PostPhysX** calls `CPhysXBase_RenderResults` then delayed ops/fluids — not `CPhysXBase_Step`.
9. **Combat DB stack:** `tDamage` / `dcDamage_Insert` / `dcWeapon_Insert_Open` / `dcArmor_Open` / `tCreatureAI` / `dcCreature` — load-time templates, distinct from runtime heat/fire.

## Breakdown by family

| Group | Count |
|---|---:|
| Combat fire / heat UI / weapon track / pursue / recreate | 5 |
| Loot prefix siblings + Map_LowerBound + Inv grid/armor | 8 |
| CLoad setCreateMsg + sector map step/generators + anim/tCloneBase | 8 |
| Damage/weapon/creature/character DB openers + tCreatureAI | 9 |

(Counts: **30** total.)

## Not done (still dual-missing samples)

| Name | Notes |
|---|---|
| Many `Combat_*` / `Inv_*` UI string plates | low dual value |
| `Net_Nazgul_*` / ghost count log strings | medium protocol layer |
| Thin `hkDefaultChassis_vtbl_*` stubs | low |
| `Inventory_WriteSwapDebugLog` | thin debug |
| Large `Named_tOutpost` / `Named_tCreatureEnhancement` | medium next |
| Graphics serialize (`gfx*Serialize`) | out of preferred scope |

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (**60** new files)
- Writer: `tmp/write_dual_reviews_combat_loot_load_net.py`
- Finder: `tmp/find_missing_dual_combat_loot_load_net.py`, `tmp/find_missing_dual_named_managers30.py`
- Extracts: `tmp/dual_batch_combat_loot_load_net_sources/`, `tmp/extract_dual_combat_sources.py`
- Report: `docs/agents/task-dual-ab-combat-loot-load-net-report.md`
- Post-batch dual count: **533** A_/B_ files; **525** unique dual addrs
- **No Launcher** touched; no servers started.
