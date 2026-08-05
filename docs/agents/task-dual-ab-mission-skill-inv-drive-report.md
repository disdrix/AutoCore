# Dual A/B review batch — Mission_ / Skill_ / Inv_ / Drive_ (cap 30)

**Date:** 2026-07-23  
**Scope:** Highest-value clean units under `docs/reconstruction/reconstructed-exact` with prefixes `Mission_*`, `Skill_*`, `Inv_*`, `Drive_*` that lacked **both** standard `A_aa_*` and `B_aa_*` under `docs/reconstruction/reviews/`.  
**Prefer names:** Objective, Equip, Cast, Steer, Inventory, Mission.  
**Excluded:** Launcher (never).  
**Cap:** 30 pairs (60 files).

## Selection

Pre-batch filter: **~450** clean units matching the four prefixes; **~424** missing any dual form when counting string dumps; **~135** high-value non-string candidates after filtering bulk/string noise.  

This batch: **30** real functions (scored by Cast/Objective/Equip/Steer/Inventory/Mission keywords + Client/CVOG/Compute/Validate/DbLoad/MoveTo/Collision patterns).  

Already dual (modern or address-matched) and **not** rewritten: `Mission_DbLoadQuestsAndObjectives`, `Skill_DbLoadSkillElements`, `Skill_DbLoadSkillsCharacters`, `Inv_DbLoadWeaponGroups`, and string-twin Client_* units already dual-reviewed under client backlog.

Legacy nonstandard duals (`aa_*_reconstruction_review.md` / `*_skeptical_review.md`) existed for a few skill units (`LocalCastValidate`, `ValidateTargetForSkill`, `ApplyStatusEffectLocal`, `ResolveTargetList`) — modern `A_/B_` pairs written here for consistency with recent batches.

## Pairs written

| # | Stable ID | Name | System | A verdict | B notes |
|---|---|---|---|---|---|
| 1 | `aa_0051a790` | Skill_LocalCastValidate | skills-abilities | accept-with-gaps | eSkillResponses 0/3/4/5/6/7/10–12; local only |
| 2 | `aa_004fc650` | Drive_CVOGVehicle_MoveToTarget3DPoint | input-drive-control | accept-with-gaps | thr/steer/HB + PushDriveAxes; UF-007 residual |
| 3 | `aa_00933650` | Inv_ValidateEquippedClonebaseSlots | inventory-transfer | accept-with-gaps | equip slot type codes; validate/log only |
| 4 | `aa_0086d020` | Mission_Client_ClaimSelectedReward | missions-progression | accept-with-gaps | select-first toast; C2S **0x20c6** seed |
| 5 | `aa_005307e0` | Mission_Client_HandleEndQuest | missions-progression | accept-with-gaps | audio + hash teardown; not XP math |
| 6 | `aa_0059df20` | Mission_ComputeObjectiveCredits | missions-progression | **accept** | ceil(scaler×frac×base); FINAL delta only |
| 7 | `aa_00517b90` | Skill_ClearActiveCastCounterAndQueueId | skills-abilities | accept-with-gaps | post-cast bookkeeping |
| 8 | `aa_0051d3b0` | Skill_QueueDeferredCastId | skills-abilities | accept-with-gaps | ring queue +0x8/+0xc/+0x10 |
| 9 | `aa_00519200` | Skill_StartCastAgainHeartbeat | skills-abilities | accept-with-gaps | HBOKToCastAgain → world+0xe4ec |
| 10 | `aa_00553650` | Skill_ValidateTargetForSkill | skills-abilities | accept-with-gaps | vtbl+0x44 glue only |
| 11 | `aa_005a8a90` | Drive_CVOGVehicle_UpdateWaterFX | input-drive-control | accept-with-gaps | cosmetic water FX |
| 12 | `aa_005d9290` | Drive_CollisionListener_DoVehicleCollision | input-drive-control | accept-with-gaps | crash response; formula open |
| 13 | `aa_0089bf50` | Inv_Client_ValidateCraftAffordability | inventory-transfer | accept-with-gaps | mats + credit craft gate |
| 14 | `aa_0093bf60` | Inv_ValidateItemsAfterRandomization | inventory-transfer | accept-with-gaps | post-random integrity walk |
| 15 | `aa_004d0530` | Mission_CVOGSectorMap_StreamMissionStrings | missions-progression | accept-with-gaps | map+0xe5c8 string stream |
| 16 | `aa_008a3510` | Mission_Client_BuildMissionDetailPanel | missions-progression | accept-with-gaps | journal detail UI |
| 17 | `aa_00521650` | Skill_CVOGHBSkill_Summon | skills-abilities | accept-with-gaps | summon HB + CastSkillOnTarget |
| 18 | `aa_0051a700` | Skill_ClearCastBindingAndMaybeRestartCd | skills-abilities | accept-with-gaps | clear bind; +0x61c restart |
| 19 | `aa_0054b4a0` | Skill_EvaluateRankedElements | skills-abilities | accept-with-gaps | rank equations; CD +0x10 ms |
| 20 | `aa_00518cf0` | Skill_LookupActiveCastBinding | skills-abilities | accept-with-gaps | active-cast map lookup |
| 21 | `aa_005502d0` | Skill_SetIsCastingFlag | skills-abilities | **accept** | +0x628 + tick +0x178 |
| 22 | `aa_0093d110` | Inv_Client_ReverseEngineerItem | inventory-transfer | accept-with-gaps | client RE gates; C2S open |
| 23 | `aa_00546460` | Mission_BuildMissionXmlPath | missions-progression | **accept** | `..\missions\%s%S.xml` + unlink |
| 24 | `aa_0051aa00` | Skill_ApplyStatusEffectLocal | skills-abilities | accept-with-gaps | S2C **0x2031** local apply |
| 25 | `aa_005506a0` | Skill_FormatTargetFilterTooltip | skills-abilities | accept-with-gaps | huge tooltip formatter |
| 26 | `aa_0058d330` | Skill_GatherTargetsInArea | skills-abilities | accept-with-gaps | AoE TFID list stride **0x10** |
| 27 | `aa_00553130` | Skill_LocalRangeTargetCheck | skills-abilities | accept-with-gaps | range codes for LocalCastValidate |
| 28 | `aa_00550300` | Skill_ResolveTargetList | skills-abilities | accept-with-gaps | flags → gather/primary |
| 29 | `aa_00553480` | Skill_CopyRuntimeFieldsFromTemplate | skills-abilities | accept-with-gaps | template→runtime + reevaluate |
| 30 | `aa_0051a980` | Skill_EnsureLoadedInTree | skills-abilities | accept-with-gaps | lazy skill tree load |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **Cast pipeline (client):** `LocalCastValidate` → optional `LocalRangeTargetCheck` / `ValidateTargetForSkill` → `ResolveTargetList` → `GatherTargetsInArea` (stride **0x10**). Fail codes 3/4/5/6/7/10–12 map to UX; server must re-validate.
2. **Cast bookkeeping:** `SetIsCastingFlag(+0x628)`, `Lookup/Clear` active-cast bindings, `QueueDeferredCastId`, `StartCastAgainHeartbeat` → world HB list **`+0xe4ec`** (`CVOGHBOKToCastAgain`).
3. **Rank scaling:** `EvaluateRankedElements` writes cooldown at runtime **`+0x10` ms** (verified note); `CopyRuntimeFieldsFromTemplate` clears cast flag then reevaluates.
4. **Mission credits:** `ComputeObjectiveCredits` is pure delta — `ROUND(ceil(scaler * frac * base))`; keys mission TargetLevel **`+0x11c`**, CreditsIndex **`+0x13e`**, scaler **`+0x148`**; no mission-null check (unlike XP); caller adds to char **`+0x720`**.
5. **Reward claim:** UI requires selection; sector opcode seed **`0x20c6`** + optional `GiveItemByCbid` — confirm full payload before port.
6. **NPC drive:** `MoveToTarget3DPoint` writes thr **`+0x614`**, steer **`+0x618`** (or hard SetSteerInput), HB **`+0x61c`**, then `PushDriveAxesToController` — pairs `MapPath_AdvanceAndSteer`.
7. **Equip integrity:** `ValidateEquippedClonebaseSlots` asserts clonebase type codes (Character **0x14**, weapons **0xe**, …) — load-time assert, not equip mutator.
8. **Status apply:** `ApplyStatusEffectLocal` consumes **0x2031** SkillStatusEffect locally (not cast request).

## Breakdown by family

| Prefix | Count in batch |
|---|---:|
| Skill_* | 17 |
| Mission_* | 6 |
| Inv_* | 4 |
| Drive_* | 3 |

## Not done (remaining high-value filter samples)

Still dual-missing after this batch (non-exhaustive; string dumps excluded):

| Name | Notes |
|---|---|
| `Skill_CategoryCooldownMap_Insert` | CD map mutator |
| `Skill_*` secondary helpers | format/nullify/train UI leftovers under Skill_* prefix |
| `Inv_Client_HandleRefineryRemoveResponse` | refinery path sibling |
| `Drive_LoadOneVehicleTemplate_*` | vehicle template load |
| Many `Mission_*` / `Inv_*` / `Drive_*` string-dump clean units | low value for dual A/B |

Post-batch: modern duals now present for all **30** selected units. Cap reached; further Skill/Inv/Drive helpers remain if another wave is wanted.

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (60 new files)
- Writer: `tmp/write_dual_reviews_mission_skill_inv_drive.py`
- Source extracts: `tmp/dual_batch_mission_skill_inv_drive_sources/`
- Report: `docs/agents/task-dual-ab-mission-skill-inv-drive-report.md`
- No Launcher touched; no servers started.
