# Dual A/B review batch — Experience_* / Tech / Serialize / DB + named managers (34)

**Date:** 2026-07-23  
**Scope:** Dual A/B for all remaining `Experience_*` clean units, `Character_GetTechForPoolCalcs`, `CreateSimpleObject_Serialize*`, `DB_ReadPowerPlantSpecific`, plus **24** other high-value named managers still missing both standard `A_aa_*` and `B_aa_*`.  
**Excluded:** Launcher (never). `Experience_LevelDiffBaseXp` already dual (`A_aa_004c9800_review.md` / `B_aa_*`) — not rewritten.  
**Cap:** priority set + up to 25 others → **34 pairs** (68 files).

## Selection

Pre-batch dual count: **469** modern A_/B_ pairs.  
Prior net/cload/phy report called out this family as the high-value next wave. Fill set preferred XP table loaders (`Mission_tExperience*`), outpost pulse XP, loot table/runtime managers, vehicle template, and related map/combat companions — demoting string-dump UI plates.

## Pairs written

### Priority (10)

| # | Stable ID | Name | System | A verdict |
|---|---|---|---|---|
| 1 | `aa_004c97b0` | Experience_GetCreatureXpForLevel | missions-progression | accept-with-gaps |
| 2 | `aa_0052c860` | Experience_GetCumulativeThreshold | missions-progression | accept-with-gaps |
| 3 | `aa_0052dec0` | Experience_XpToReachRelativeLevel | missions-progression | accept-with-gaps |
| 4 | `aa_005128b0` | Experience_EnsureLevelTableLoaded_INFERRED | missions-progression | accept-with-gaps |
| 5 | `aa_005128f0` | Experience_EnsureCreatureXpTableLoaded_INFERRED | missions-progression | accept-with-gaps |
| 6 | `aa_005127f0` | Experience_EnsureQuestXpTableLoaded_INFERRED | missions-progression | accept-with-gaps |
| 7 | `aa_004c3ff0` | Character_GetTechForPoolCalcs | vehicle-combat-pools | accept-with-gaps |
| 8 | `aa_005c9f20` | CreateSimpleObject_Serialize | networking | accept-with-gaps |
| 9 | `aa_005ca720` | CreateSimpleObject_SerializeVariant2 | networking | accept-with-gaps |
| 10 | `aa_007f4c50` | DB_ReadPowerPlantSpecific | inventory-transfer | accept-with-gaps |

### Other named managers (24)

| # | Stable ID | Name | System | A verdict |
|---|---|---|---|---|
| 11 | `aa_00607830` | Outpost_ComputePulseXp | missions-progression | accept-with-gaps |
| 12 | `aa_006075b0` | Outpost_GetPulseXpPercent | missions-progression | accept-with-gaps |
| 13 | `aa_004054f0` | StdMap_LowerBoundByIntKey_INFERRED | missions-progression | accept-with-gaps |
| 14 | `aa_007cbbb0` | Mission_tExperienceLevel | missions-progression | accept-with-gaps |
| 15 | `aa_007cc0d0` | Mission_tQuestXPLookup | missions-progression | accept-with-gaps |
| 16 | `aa_007cd150` | Mission_tCreatureExperienceLevel | missions-progression | accept-with-gaps |
| 17 | `aa_007dd5e0` | Mission_tContinentExploredAreas | missions-progression | accept-with-gaps |
| 18 | `aa_005355e0` | Character_MaybeRefreshCombatState_Inferred | combat | accept-with-gaps |
| 19 | `aa_007ca4e0` | Inv_tLootTable | inventory-transfer | accept-with-gaps |
| 20 | `aa_007cd9a0` | Inv_tLootConfig | inventory-transfer | accept-with-gaps |
| 21 | `aa_007c77b0` | Inv_tLootWeights | inventory-transfer | accept-with-gaps |
| 22 | `aa_007ce130` | Inv_tLootRarity | inventory-transfer | accept-with-gaps |
| 23 | `aa_004d0df0` | Inv_GenerateLootItem | inventory-transfer | accept-with-gaps |
| 24 | `aa_004d0cf0` | Inv_GenerateLootItem_type | inventory-transfer | accept-with-gaps |
| 25 | `aa_00810670` | Inv_LootCredits | inventory-transfer | accept-with-gaps |
| 26 | `aa_007da570` | Inv_vLootBaseItems | inventory-transfer | accept-with-gaps |
| 27 | `aa_007c4920` | Inv_tItemTemplate | inventory-transfer | accept-with-gaps |
| 28 | `aa_00945540` | Inv_lootpickup | inventory-transfer | accept-with-gaps |
| 29 | `aa_007c6110` | Drive_tVehicleTemplate | input-drive-control | accept-with-gaps |
| 30 | `aa_005092b0` | CVOGLootGenerator_GetTypeFromIDPrefix | inventory-transfer | accept-with-gaps |
| 31 | `aa_005d1df0` | Map_EraseNode_IntKey | missions-progression | accept-with-gaps |
| 32 | `aa_0040ba20` | Combat_rlWeaponHeatMultiplier | inventory-transfer | accept-with-gaps |
| 33 | `aa_004c7490` | CVOGCreature_UpdateGraphics | client-load | accept-with-gaps |
| 34 | `aa_004dcb80` | CVOGSectorMap_SaveToFile | missions-progression | accept-with-gaps |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **XP table triad sealed as distinct maps:** creature kill-base (`GetCreatureXpForLevel`, miss→**0**), player cumulative (`GetCumulativeThreshold`, miss→**0x7FFFFFFF**), quest fractions (`tQuestXPLookup` via EnsureQuest). Do not conflate miss sentinels.
2. **Ensure_* twins** call `Mission_tExperienceLevel` (`0x007cbbb0`), `Mission_tCreatureExperienceLevel` (`0x007cd150`), `Mission_tQuestXPLookup` (`0x007cc0d0`) with shared bookend + `VOG_DEBUG_STOP` fail path; ready-flag **writes** still open (not in Ensure bodies).
3. **XpToReachRelativeLevel:** `thr(level+delta-1) / flPersonalXpGain@+0xc54 - totalXp@+0x730 + 1`; can be **negative** (de-level). GetLevel via vtbl **+0x27c**.
4. **GetTechForPoolCalcs:** `min(Tech@+0x13c, 200) + bonus@+0x144` clamped to **[1, 250]** — feeds `Vehicle_CalcMaxHitPoints` / AutoCore `VehicleHitPointCalculator`.
5. **CreateSimpleObject serializers:** both pack opcode **0x2012** / **0xD8** layout; **Variant2** uses different multi-inherit this-base (**-0x10c** vs primary **-0xbc**). Character create uses Variant2 first. Client forces **IsIdentified=1**.
6. **DB_ReadPowerPlantSpecific:** out struct **0xC** (HeatMax, PowerMax, PowerRegen short, CoolRate short) → clonebase plant **+0xB0..+0xBA** (regen getters).
7. **Outpost pulse XP:** gate `+0x238`, scalar `+0x21c`, percent tables `DAT_00d029e0` / `DAT_00d029f0` by `+0x220`, row stride **0x10**, percent float **+0x08**.
8. **Loot pipeline split:** table loaders (`tLootTable/Config/Weights/Rarity`, `vLootBaseItems`, `tItemTemplate`) vs runtime `GenerateLootItem` **(id)** / **(type)** siblings vs `lootpickup` vs `LootCredits`.
9. **Heat multiplier map** (`rlWeaponHeatMultiplier`) is **not** `Weapon_ApplyShotHeatAndPowerCost` — keep table manager vs apply path split.

## Breakdown by family

| Group | Count |
|---|---:|
| Experience_* helpers / ensures | 6 |
| Character tech + combat refresh | 2 |
| CreateSimpleObject_Serialize* | 2 |
| DB_ReadPowerPlantSpecific | 1 |
| Outpost pulse + StdMap lower_bound | 3 |
| Mission_t* XP/area table loaders | 4 |
| Inv_* loot / item managers | 10 |
| Drive_tVehicleTemplate | 1 |
| CVOGLootGenerator / Map erase / heat mult / graphics / map save | 5 |

(Counts: **34** total.)

## Not done (still dual-missing samples)

| Name | Notes |
|---|---|
| `Experience_LevelDiffBaseXp` | already dual (`*_review.md` naming) |
| Many `Mission_Uses_*` / UI string-dump plates | low dual value |
| Other `CVOGLootGenerator_GetTypeFromIDPrefix_*` siblings | medium; VA family residual |
| Large UI `Combat_*` / `Drive_*` string units | low |
| Remaining `DB_*` if any beyond power plant | none found in clean tree |

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (**68** new files)
- Writer: `tmp/write_dual_reviews_exp_tech_serialize_db.py`
- Finder: `tmp/find_missing_dual_exp_wave.py`
- Report: `docs/agents/task-dual-ab-exp-tech-serialize-db-report.md`
- Post-batch dual count: **503** A_/B_ pairs on disk
- **No Launcher** touched; no servers started.
