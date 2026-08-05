# Dual A/B review batch wave2 — Mission_/Skill_/Inv_/Drive_ + Named (cap 30)

**Date:** 2026-07-23  
**Scope:** Highest-value clean units still missing **both** standard `A_aa_*` and `B_aa_*` under `docs/reconstruction/reviews/`, after the prior Mission/Skill/Inv/Drive batch. Includes family prefixes **and** Named high-value units (Vehicle_*, InventoryGrid_*, QuickBar_*, NPC_*, LoadQuest*).  
**Prefer:** non-string-dump real functions with substantial body (Cast / Cooldown / Equip / Inventory / Drive / Mission credits).  
**Excluded:** Launcher (never). String-literal bulk renames demoted.  
**Cap:** 30 pairs (60 files).

## Selection

Pre-batch: ~331 existing duals. Family-prefix clean units still dual-missing were dominated by string-dump renames; this wave filtered for:

* Semantic CamelCase names (not prose UI strings)
* Real CF (if-count / body size)
* High-value keywords: Cast, Cooldown, Equip, Inventory, Drive, Quest credits, QuickBar, Wheelset

Already dual from prior wave (not rewritten): `Skill_LocalCastValidate`, `Skill_ResolveTargetList`, `Drive_CVOGVehicle_MoveToTarget3DPoint`, `Inv_ValidateEquippedClonebaseSlots`, `Mission_ComputeObjectiveCredits`, etc.

## Pairs written

| # | Stable ID | Name | System | A verdict | B notes |
|---|---|---|---|---|---|
| 1 | `aa_0054fa20` | Skill_FormatFailureMessage | skills-abilities | accept-with-gaps | eSkillResponses 1–14, 0x12 string table |
| 2 | `aa_0051d2f0` | Skill_CategoryCooldownMap_Insert | skills-abilities | accept-with-gaps | CD map mutator |
| 3 | `aa_00519150` | Skill_GetCategoryCooldownRemaining | skills-abilities | accept-with-gaps | +0x10 start / +0x14 dur; erase expired |
| 4 | `aa_00518d70` | Skill_GetCategoryCooldownMap | skills-abilities | **accept** | lazy map at owner+0x6c |
| 5 | `aa_00518df0` | Skill_InsertCategoryCooldown | skills-abilities | accept-with-gaps | now=DAT_00b041cc + durationMs |
| 6 | `aa_00553710` | Skill_InitializeRuntimeObject | skills-abilities | accept-with-gaps | +0x5e8/+0x5fc/+0x614; +0x61c defer |
| 7 | `aa_00553390` | Skill_ReevaluateForCurrentRank | skills-abilities | accept-with-gaps | EvaluateRankedElements; +0x624 flags |
| 8 | `aa_005535a0` | Skill_SetRankAndReevaluate | skills-abilities | **accept** | +0x5f6 then reeval |
| 9 | `aa_00840ac0` | Skill_Client_FormatStatusEffectsNullified | skills-abilities | accept-with-gaps | nullify tooltip only |
| 10 | `aa_00551700` | Skill_FormatCooldownDurationRangeLines | skills-abilities | accept-with-gaps | compact combat lines |
| 11 | `aa_00552180` | Skill_FormatTimingAttributeLines | skills-abilities | accept-with-gaps | cast_time/cd/duration/… |
| 12 | `aa_00552950` | Skill_ParseTimingAttributeToken | skills-abilities | accept-with-gaps | token stream parser |
| 13 | `aa_007d8fe0` | Drive_LoadOneVehicleTemplate_dcFetch_Open | input-drive-control | accept-with-gaps | template DB fetch, not drive tick |
| 14 | `aa_005d1280` | NPC_TryCastSkillFromSet | skills-abilities | accept-with-gaps | AI cast pipeline; entry stride 0x18 INFERRED |
| 15 | `aa_00504480` | Vehicle_EquipFromCreate | inventory-transfer | accept-with-gaps | CreateVehicle 0x201D hardpoints; +0x45c wheel |
| 16 | `aa_004fbc10` | VehicleEntity_PushDriveAxesToController | input-drive-control | accept-with-gaps | thr/HB push; steer NOT here |
| 17 | `aa_004fe1b0` | Vehicle_EquipPowerPlant | inventory-transfer | accept-with-gaps | +0x268 type 10; MaxHeat +0x244 |
| 18 | `aa_00825520` | QuickBar_UpdateSkillSlotCooldownGauge | skills-abilities | accept-with-gaps | +0x628 charge vs category CD |
| 19 | `aa_00571620` | InventoryGrid_PlaceItemFootprint | inventory-transfer | accept-with-gaps | CanPlace + footprint +0x406/407 |
| 20 | `aa_005713a0` | InventoryGrid_FindFreeSlot | inventory-transfer | accept-with-gaps | Y-outer X-inner first-fit |
| 21 | `aa_00572650` | InventoryGrid_ctor_Inferred | inventory-transfer | accept-with-gaps | 0x68 layout; CS + cells |
| 22 | `aa_00502460` | Vehicle_SetEquippedRaceItem | inventory-transfer | accept-with-gaps | +0x270 type6/subtype 0xb |
| 23 | `aa_00502090` | Vehicle_SetEquippedArmor | inventory-transfer | accept-with-gaps | +0x254 type 0x1c |
| 24 | `aa_004fadb0` | Inventory_SerializeAddItemPacket | inventory-transfer | accept-with-gaps | **0x2047**; COID@+8, XY@+0x10 |
| 25 | `aa_007cc470` | LoadQuestCreditsLookupFromWad | missions-progression | accept-with-gaps | tQuestCreditsLookup scaler table |
| 26 | `aa_007cc810` | LoadQuestBaseCreditsFromWad | missions-progression | accept-with-gaps | base credits table load |
| 27 | `aa_004f3a30` | Vehicle_CreateCargoInventoryFromPageCount | inventory-transfer | accept-with-gaps | grid@+0x2b0; skip +0x2ac |
| 28 | `aa_00824140` | UI_SkillPanel_BindAvailableButtons | skills-abilities | accept-with-gaps | skill panel UI bind |
| 29 | `aa_00829490` | QuickBar_BuildSkillButtonWidgets | skills-abilities | accept-with-gaps | QB chrome + CD gauge widget |
| 30 | `aa_004fea90` | Vehicle_SetWheelset | inventory-transfer | accept-with-gaps | +0x258 type 0x10; wheel scale loop |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **Category CD pipeline:** `GetCategoryCooldownMap(+0x6c lazy)` → `InsertCategoryCooldown(cat, ms)` / `CategoryCooldownMap_Insert` → `GetCategoryCooldownRemaining` (entry **+0x10 start / +0x14 duration**, erase if expired). Feeds LocalCastValidate code **7** and QB gauge.
2. **Rank pipeline:** `InitializeRuntimeObject` (id **+0x5fc**, cat **+0x5e8**, flags **+0x614**, defer **+0x61c**) → `SetRankAndReevaluate(+0x5f6)` → `ReevaluateForCurrentRank` → `EvaluateRankedElements` + targeting **+0x624**.
3. **Fail UX:** `Skill_FormatFailureMessage` is the sealed eSkillResponses→string bridge (cases **1–14**, **0x12** summon level).
4. **NPC cast:** `NPC_TryCastSkillFromSet` is the AI bank caster: post-cast map **+0x9c**, HP-ratio band, full LocalCastValidate → ResolveTargetList → CastSkillOnTarget chain. Entry stride **0x18** still INFERRED.
5. **Drive axes:** `PushDriveAxesToController` copies thr **entity+0x614 → ctrl+0x20** and HB **+0x61c → ctrl+0x24**; **steer +0x618 is not written here** (steer ramp later). Completes MoveToTarget3DPoint path.
6. **CreateVehicle equip nest:** `Vehicle_EquipFromCreate` (packet wheel CBID **+0x45c**) → `SetWheelset(+0x258, type 0x10)` / `SetEquippedArmor(+0x254, 0x1c)` / `EquipPowerPlant(+0x268, type 10)` / race **+0x270**. Special flag **+0x2ac** skips cargo create.
7. **Cargo grid:** ctor **0x68** → `CreateCargoInventoryFromPageCount` @ **+0x2b0** → `FindFreeSlot` (Y outer) → `PlaceItemFootprint` → `SerializeAddItemPacket` **0x2047** with **COID at +0x08/+0x0c**, **XY at +0x10/+0x11** (older XY-at-+8 claim is wrong).
8. **Mission credits tables:** `LoadQuestCreditsLookupFromWad` + `LoadQuestBaseCreditsFromWad` supply scaler/base for `Mission_ComputeObjectiveCredits`.

## Breakdown by family / Named

| Group | Count |
|---|---:|
| Skill_* | 12 |
| Named Vehicle_* / VehicleEntity_* | 7 |
| Named Inventory* | 4 |
| Named QuickBar_* / UI_* | 3 |
| Named LoadQuest* (mission) | 2 |
| Drive_* | 1 |
| Named NPC_* | 1 |

## Not done (still dual-missing samples)

| Name | Notes |
|---|---|
| `Vehicle_buildHavokVehicleFramework` / `TryActivatePhysics` / `Build*Descriptor` | large drive/physics; good next wave |
| `QuickBar_UpdateSlotCooldownOverlay` / `BuildItemButtonWidgets` | QB siblings |
| `InventoryGrid_AllocateCellArray_Inferred` | grid helper |
| Many `Mission_*` / `Skill_*` string-dump clean units | low dual value |
| `Skill_Following_Skill_is_On*` formatters | skill-type display; medium value |

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (60 new files)
- Writer: `tmp/write_dual_reviews_msid_named_wave2.py`
- Source extracts: `tmp/dual_batch_msid_named_wave2_sources/`
- Finder: `tmp/find_missing_dual_msid_wave2.py` / `wave2b.py`
- Report: `docs/agents/task-dual-ab-msid-named-wave2-report.md`
- No Launcher touched; no servers started.
