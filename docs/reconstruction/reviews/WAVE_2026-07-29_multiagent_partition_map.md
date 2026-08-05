# Multi-agent partition map — 2026-07-29 mandatory concurrency wave

| Field | Value |
|-------|-------|
| Wave | 2026-07-29 multi-agent (skills / input / inventory / missions / interact) |
| Rule | **One write owner per VA** (or residual slice of a VA). No dual writers on the same stable ID. |
| Parent | Merges durable ledgers (`WORK_QUEUE` / `RESUME` / `CHANGE_LOG` / `VERIFICATION_MATRIX` / registries). Children **do not** edit those. |
| Agent IDs | Parent fills `Agent` column if needed (`—` = unassigned / parent-owned meta). |
| Scratch mirror | `tmp/partition_map.md` (same content) |

**Mandate focus prompts (ACTIVE_WORK):** skills residual · input camera residual · inventory Collect_Action refine · interact pick-hub · mission prerequisites edges · grab residual · skill FormatFailure · outFlags range helper · NPC skill entry · soft-steer UF-006 bind · dual adversarial samples.

**Concurrency:** isolated function ownership; dual A/B written only under that unit’s owner. ~80 VA/residual partitions + 4 meta roles.

---

## Skills (`skills-abilities`)

| Agent | VA | Stable ID | Ownership focus |
|-------|-----|-----------|-----------------|
| — | `0x005169c0` | `aa_005169c0` | LocalCast lazy alloc slot (`FUN_005169c0`; leave-FUN unless string/RTTI) |
| — | `0x00518c20` | `aa_00518c20` | LocalCast lazy map (`FUN_00518c20`; leave-FUN unless string/RTTI) |
| — | `0x0058c0a0` | `aa_0058c0a0` | **outFlags range helper** after filter (`FUN_0058c0a0`) |
| — | `0x005538a0` | `aa_005538a0` | Residual skill helper / ApplyEffects path (`FUN_005538a0`) |
| — | `0x0058d330` | `aa_0058d330` | `Skill_GatherTargetsInArea` mode table residual |
| — | `0x00519200` | `aa_00519200` | `Skill_StartCastAgainHeartbeat` |
| — | `0x00811170` | `aa_00811170` | `Client_RecvSkillStatusEffect` (S2C `0x2031`) |
| — | `0x005d1280` | `aa_005d1280` | **NPC skill entry** — `NPC_TryCastSkillFromSet` |
| — | `0x004d09a0` | `aa_004d09a0` | `CVOGReaction_CastSkillOnTarget` |
| — | `0x00941590` | `aa_00941590` | `Client_RequestCastSkill` |
| — | `0x00921b50` | `aa_00921b50` | `Client_QuickBarActivateSkillSlot` |
| — | `0x0051a790` | `aa_0051a790` | `Skill_LocalCastValidate` |
| — | `0x0093b3a0` | `aa_0093b3a0` | `Client_Skill_ResolveCastTarget` |
| — | `0x009436c0` | `aa_009436c0` | `Client_QuickBar_ActivateSlot` |
| — | `0x0051aa00` | `aa_0051aa00` | `Skill_ApplyStatusEffectLocal` |
| — | `0x00550300` | `aa_00550300` | `Skill_ResolveTargetList` |
| — | `0x0054c570` | `aa_0054c570` | `CVOGReaction_ResolveSkillTargets` |
| — | `0x0054fa20` | `aa_0054fa20` | **FormatFailure** — `Skill_FormatFailureMessage` / eSkillResponses table |
| — | `0x00553650` | `aa_00553650` | `Skill_ValidateTargetForSkill` |
| — | `0x0054ff00` | `aa_0054ff00` | `Skill_FilterTargetForResolveList_Inferred` (outFlags 4/8/0x10) |
| — | `0x004f8b80` | `aa_004f8b80` | `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` |
| — | `0x004e2600` | `aa_004e2600` | `CNDDoubleList_InvokePredicateAndRemove_Inferred` |
| — | `0x005788d0` | `aa_005788d0` | `CVOGHBSkillBase_ctor` |

---

## Input (`input-drive-control`)

| Agent | VA | Stable ID | Ownership focus |
|-------|-----|-----------|-----------------|
| — | `0x009223b0` **camera** | `aa_009223b0` | **Camera residual only** (look `local_d*`; not full re-dual) |
| — | `0x009223b0` **soft-steer** | `aa_009223b0` | **UF-006 soft-steer bind residual only** (±0.5/±1.0; no camera files) |
| — | `0x004fbc10` | `aa_004fbc10` | `VehicleEntity_PushDriveAxesToController` |
| — | `0x004f3620` | `aa_004f3620` | `VehicleEntity_SetHandbrake` |
| — | `0x004f5620` | `aa_004f5620` | `VehicleEntity_SetSteerInput` |
| — | `0x004f5650` | `aa_004f5650` | `VehicleEntity_SetLongitudinalInput` |

> Same VA `0x009223b0` is split by **residual slice** (camera vs soft-steer). Owners must not rewrite each other’s dual/artifacts; parent resolves merge conflicts on shared function record if both land.

---

## Interact (`interaction-activation`)

| Agent | VA | Stable ID | Ownership focus |
|-------|-----|-----------|-----------------|
| — | `0x009247b0` | `aa_009247b0` | **Interact pick-hub** — `Client_InteractClickPickTarget` |
| — | `0x00925d60` | `aa_00925d60` | `Client_Input_PollBoundActions` (interact edge slice) |
| — | `0x00916740` | `aa_00916740` | `Client_SendUseObject` (C2S `0x2072`) |
| — | `0x00930d70` | `aa_00930d70` | `Client_SendUseObject_IfInteractable` |
| — | `0x00524520` | `aa_00524520` | `CVOGCharacter_FindActiveObjectiveIdForInteract` |
| — | `0x005245d0` | `aa_005245d0` | Sibling walker (+0x44 / alt match path) |
| — | `0x0059d9c0` | `aa_0059d9c0` | `CVOGObjective_MatchTargetEvaluators` |
| — | `0x0059da10` | `aa_0059da10` | MatchTarget evaluators +0x44 sibling |
| — | `0x00525bd0` | `aa_00525bd0` | `Client_FindObjectiveMatchingTarget` |
| — | `0x00807460` | `aa_00807460` | `Client_SendSectorPacket` (send helper for interact/skill) |

---

## Inventory (`inventory-transfer`)

| Agent | VA | Stable ID | Ownership focus |
|-------|-----|-----------|-----------------|
| — | `0x00860e20` | `aa_00860e20` | **Grab residual** — `Client_SendInventoryGrab_FromGrid` (C2S `0x2034`) |
| — | `0x00860a50` | `aa_00860a50` | Drop residual — `Client_UI_InventoryDropToGrid` (C2S `0x2036`) |
| — | `0x00811be0` | `aa_00811be0` | `Client_RecvInventoryGrabResponse` |
| — | `0x00813730` | `aa_00813730` | `Client_RecvInventoryDropResponse` |
| — | `0x00813f40` | `aa_00813f40` | `Client_RecvInventoryEquip` |
| — | `0x00813bf0` | `aa_00813bf0` | `Client_RecvInventoryUnequipNotify` |
| — | `0x008151a0` | `aa_008151a0` | `Client_RecvInventoryAddItem` |
| — | `0x005713a0` | `aa_005713a0` | `InventoryGrid_FindFreeSlot` |
| — | `0x00570720` | `aa_00570720` | `InventoryGrid_AllocateCellArray_Inferred` |
| — | `0x00571620` | `aa_00571620` | `InventoryGrid_PlaceItemFootprint` |
| — | `0x005711c0` | `aa_005711c0` | `InventoryGrid_CountItemsByCbid` (collect bridge) |
| — | `0x004f3a30` | `aa_004f3a30` | `Vehicle_CreateCargoInventoryFromPageCount` |
| — | `0x00611f20` | `aa_00611f20` | **Collect_Action refine** — `CVOGObjectiveRequirement_Collect_Action` |
| — | `0x00611940` | `aa_00611940` | `CVOGObjectiveRequirement_Collect_Eval` |
| — | `0x006124b0` | `aa_006124b0` | `CVOGObjectiveRequirement_Collect_SlotAction` |
| — | `0x00611290` | `aa_00611290` | Deliver OnInventoryEvent (cargo readiness) |
| — | `0x00610f20` | `aa_00610f20` | Deliver CargoReady predicate |

---

## Missions (`missions-progression`)

| Agent | VA | Stable ID | Ownership focus |
|-------|-----|-----------|-----------------|
| — | `0x00536540` | `aa_00536540` | **Prerequisites edges** — `CVOGCharacter_CheckMissionPrerequisites` |
| — | `0x005462b0` | `aa_005462b0` | `CVOGCharacter_CheckMissionRequirements` |
| — | `0x00532b60` | `aa_00532b60` | `CVOGCharacter_SearchAutoMissions` |
| — | `0x005327c0` | `aa_005327c0` | `CVOGReaction_GiveMission` residual |
| — | `0x00531b00` | `aa_00531b00` | `CVOGMission_AddActiveObjective` |
| — | `0x00536080` | `aa_00536080` | `CVOGCharacter_CompleteMissionObjectives` |
| — | `0x00533f90` | `aa_00533f90` | `CVOGReaction_CompleteObjective` residual |
| — | `0x00534920` | `aa_00534920` | `CVOGCharacter_EvaluatePendingObjectives` |
| — | `0x0052aa20` | `aa_0052aa20` | `CVOGCharacter_HasCompletedMission` |
| — | `0x0052da30` | `aa_0052da30` | `CVOGReaction_FailMission` |
| — | `0x0080b100` | `aa_0080b100` | `Client_RecvFailMission` (S2C `0x20B2`) |
| — | `0x00809460` | `aa_00809460` | `Client_RecvObjectiveState` (S2C `0x2071`) |
| — | `0x0080ff00` | `aa_0080ff00` | `Client_RecvCompleteDynamicObjective` (S2C `0x2070`) |
| — | `0x00815070` | `aa_00815070` | `Client_RecvNpcMissionDialog` (S2C `0x206D`) |
| — | `0x009438f0` | `aa_009438f0` | `Client_ShowNpcMissionDialogUI` |
| — | `0x008ae7c0` | `aa_008ae7c0` | `Client_MissionDialogHandleButton` |
| — | `0x008ae130` | `aa_008ae130` | `Client_UpdateMissionJournal` |
| — | `0x008abd70` | `aa_008abd70` | `Client_NpcDialog_PrepareResponseOpcode` (`0x206E` prepare) |
| — | `0x008ab8f0` | `aa_008ab8f0` | `Client_MissionDialog_FlushPreparedResponse` |
| — | `0x00911840` | `aa_00911840` | `Client_UiModalDispatch` (abandon Yes/No slice) |
| — | `0x007fdfb0` | `aa_007fdfb0` | `Client_ShowModalPrompt` |
| — | `0x0059dde0` | `aa_0059dde0` | `Mission_ComputeObjectiveXp` |
| — | `0x0059df20` | `aa_0059df20` | `Mission_ComputeObjectiveCredits` |
| — | `0x0060e0f0` | `aa_0060e0f0` | `CVOGObjectiveRequirement_Patrol_Eval` |
| — | `0x0060cfe0` | `aa_0060cfe0` | `CVOGObjectiveRequirement_UseItem_Eval` |
| — | `0x00613910` | `aa_00613910` | `CVOGObjectiveRequirement_Kill_Eval` |

---

## Meta (non-VA / shared read)

| Agent | Role | Ownership |
|-------|------|-----------|
| — | Adversarial A | Chain-doc contradictions → UF only (no production unit rewrites) |
| — | Adversarial B | `NAMING_REGISTRY` conflict scan (report only unless parent assigns fix) |
| — | Matrix rows | Append-only residual matrix rows (parent merge preferred) |
| — | Experiments | `experiments/test_skill_fun_residuals.py` (+ related recon suite files if assigned) |

---

## Complete stable-ID index (this mandate)

Sorted unique `aa_*` units owned by this wave. Parent may attach agent IDs against this list.

| Stable ID | VA | System |
|-----------|-----|--------|
| `aa_004d09a0` | `0x004d09a0` | skills |
| `aa_004e2600` | `0x004e2600` | skills |
| `aa_004f3620` | `0x004f3620` | input |
| `aa_004f3a30` | `0x004f3a30` | inventory |
| `aa_004f5620` | `0x004f5620` | input |
| `aa_004f5650` | `0x004f5650` | input |
| `aa_004f8b80` | `0x004f8b80` | skills |
| `aa_004fbc10` | `0x004fbc10` | input |
| `aa_005169c0` | `0x005169c0` | skills |
| `aa_00518c20` | `0x00518c20` | skills |
| `aa_00519200` | `0x00519200` | skills |
| `aa_0051a790` | `0x0051a790` | skills |
| `aa_0051aa00` | `0x0051aa00` | skills |
| `aa_00524520` | `0x00524520` | interact |
| `aa_005245d0` | `0x005245d0` | interact |
| `aa_00525bd0` | `0x00525bd0` | interact |
| `aa_0052aa20` | `0x0052aa20` | missions |
| `aa_0052da30` | `0x0052da30` | missions |
| `aa_00531b00` | `0x00531b00` | missions |
| `aa_005327c0` | `0x005327c0` | missions |
| `aa_00532b60` | `0x00532b60` | missions |
| `aa_00533f90` | `0x00533f90` | missions |
| `aa_00534920` | `0x00534920` | missions |
| `aa_00536080` | `0x00536080` | missions |
| `aa_00536540` | `0x00536540` | missions |
| `aa_005462b0` | `0x005462b0` | missions |
| `aa_0054c570` | `0x0054c570` | skills |
| `aa_0054fa20` | `0x0054fa20` | skills |
| `aa_0054ff00` | `0x0054ff00` | skills |
| `aa_00550300` | `0x00550300` | skills |
| `aa_00553650` | `0x00553650` | skills |
| `aa_005538a0` | `0x005538a0` | skills |
| `aa_00570720` | `0x00570720` | inventory |
| `aa_005711c0` | `0x005711c0` | inventory |
| `aa_005713a0` | `0x005713a0` | inventory |
| `aa_00571620` | `0x00571620` | inventory |
| `aa_005788d0` | `0x005788d0` | skills |
| `aa_0058c0a0` | `0x0058c0a0` | skills |
| `aa_0058d330` | `0x0058d330` | skills |
| `aa_0059d9c0` | `0x0059d9c0` | interact |
| `aa_0059da10` | `0x0059da10` | interact |
| `aa_0059dde0` | `0x0059dde0` | missions |
| `aa_0059df20` | `0x0059df20` | missions |
| `aa_005d1280` | `0x005d1280` | skills |
| `aa_0060cfe0` | `0x0060cfe0` | missions |
| `aa_0060e0f0` | `0x0060e0f0` | missions |
| `aa_00610f20` | `0x00610f20` | inventory |
| `aa_00611290` | `0x00611290` | inventory |
| `aa_00611940` | `0x00611940` | inventory |
| `aa_00611f20` | `0x00611f20` | inventory |
| `aa_006124b0` | `0x006124b0` | inventory |
| `aa_00613910` | `0x00613910` | missions |
| `aa_007fdfb0` | `0x007fdfb0` | missions |
| `aa_00807460` | `0x00807460` | interact |
| `aa_00809460` | `0x00809460` | missions |
| `aa_0080b100` | `0x0080b100` | missions |
| `aa_0080ff00` | `0x0080ff00` | missions |
| `aa_00811170` | `0x00811170` | skills |
| `aa_00811be0` | `0x00811be0` | inventory |
| `aa_00813730` | `0x00813730` | inventory |
| `aa_00813bf0` | `0x00813bf0` | inventory |
| `aa_00813f40` | `0x00813f40` | inventory |
| `aa_00815070` | `0x00815070` | missions |
| `aa_008151a0` | `0x008151a0` | inventory |
| `aa_00860a50` | `0x00860a50` | inventory |
| `aa_00860e20` | `0x00860e20` | inventory |
| `aa_008ab8f0` | `0x008ab8f0` | missions |
| `aa_008abd70` | `0x008abd70` | missions |
| `aa_008ae130` | `0x008ae130` | missions |
| `aa_008ae7c0` | `0x008ae7c0` | missions |
| `aa_00911840` | `0x00911840` | missions |
| `aa_00916740` | `0x00916740` | interact |
| `aa_00921b50` | `0x00921b50` | skills |
| `aa_009223b0` | `0x009223b0` | input (camera + soft-steer slices) |
| `aa_009247b0` | `0x009247b0` | interact |
| `aa_00925d60` | `0x00925d60` | interact |
| `aa_00930d70` | `0x00930d70` | interact |
| `aa_0093b3a0` | `0x0093b3a0` | skills |
| `aa_00941590` | `0x00941590` | skills |
| `aa_009436c0` | `0x009436c0` | skills |
| `aa_009438f0` | `0x009438f0` | missions |

**Count:** 82 unique stable IDs (+ residual double-slice on `aa_009223b0`).

---

## Non-goals (children)

- Start/stop Launcher without approval
- Edit `WORK_QUEUE.md` / `RESUME.md` / parent ledgers
- Two writers on the same stable ID or full dual re-emit of a unit already sealed this wave without parent assign
- Invent product names without string/RTTI/xref evidence
