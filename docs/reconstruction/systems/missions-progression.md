# System map: Missions & progression (client)

| Field | Value |
|---|---|
| System | Mission grant, prerequisites, objectives, dialog, journal |
| Priority | **High** â€” user-facing progression managers |
| Program | `autoassault.exe` base `0x400000` |
| Status | Behavioral map from Ghidra decompiles + prior `docs/missionState.md`; **dialog/journal residual duals sealed 2026-08-04** (16 units; runtime still open) |
| Bit-for-bit | Deferred |

## Scope

**In scope:** Client mission lifecycle â€” auto-grant, prerequisites, give/fail, objective progress packets, NPC dialog UI, journal refresh.

**Out of scope:** Server authority; full clonebase mission table dump; physics.

## Known entry points

| Address | Symbol | Role |
|--------:|--------|------|
| `0x00532b60` | `CVOGCharacter_SearchAutoMissions` | Auto-award eligible missions |
| `0x00536540` | `CVOGCharacter_CheckMissionPrerequisites` | Prereq gate |
| `0x005462b0` | `CVOGCharacter_CheckMissionRequirements` | Race/class/level/discipline/event/prereqs (Ored/Negative) |
| `0x005327c0` | `CVOGReaction_GiveMission` | Grant mission + toast |
| `0x00531b00` | `CVOGMission_AddActiveObjective` | Push objective active |
| `0x00536080` | `CVOGCharacter_CompleteMissionObjectives` | Bulk complete objectives |
| `0x00533f90` | `CVOGReaction_CompleteObjective` | Advance or final complete (+ XP/credits on final) |
| `0x0059dde0` | `Mission_ComputeObjectiveXp` | Final grant XP calculator (toast also calls for display; map residual sealed 2026-07-29) |
| `0x0059df20` | `Mission_ComputeObjectiveCredits` | Final-path credit calculator |
| `0x00534920` | `CVOGCharacter_EvaluatePendingObjectives` | Re-evaluate pending set |
| `0x0052aa20` | `CVOGCharacter_HasCompletedMission` | Completed hash lookup |
| `0x0052da30` | `CVOGReaction_FailMission` | Fail active mission |
| `0x0080b100` | `Client_RecvFailMission` | S2C `0x20B2` apply fail (post-abandon / server fail) |
| `0x00911840` | `Client_UiModalDispatch` | Modal switch; abandon Yes `0x4e46` â†’ C2S `0x20B2` |
| `0x0080ff00` | `Client_RecvCompleteDynamicObjective` | S2C `0x2070` force CompleteObjective |
| `0x00809460` | `Client_RecvObjectiveState` | S2C `0x2071` progress floats + bitmask |
| `0x00815070` | `Client_RecvNpcMissionDialog` | S2C `0x206D` NPC dialog |
| `0x009438f0` | `Client_ShowNpcMissionDialogUI` | Present/reconfigure NPC dialog UI |
| `0x008ae7c0` | `Client_MissionDialogHandleButton` | Accept/claim/abandon UI |
| `0x008ac7a0` | `Client_MaybeShowMultiActiveMissionTip_Inferred` | After accept: tip `0x20` if â‰¥2 active missions (dual 2026-08-04) |
| `0x008aaf60` | `Client_MissionDialog_SetHeaderCaption_Inferred` | Dialog header caption apply (dual 2026-08-04) |
| `0x008ac110` | `UI_MissionDialog_BuildResponseButtons_Inferred` | Response button strip rebuild (dual 2026-08-04) |
| `0x008aa610` | `UI_MissionPanel_SyncListScrollbar_Inferred` | List scrollbar page/thumb sync after caption/list rebuild (dual 2026-08-04) |
| `0x008aa560` | `MissionDialog_ClearResponseButtonSlots_Inferred` | 8-slot TFID/widget wipe before response rebuild (dual 2026-08-04) |
| `0x008aab00` | `MissionDialog_ParseMarkupToRichText_Inferred` | `[$imp/npc/â€¦]` markup â†’ richtext (dual 2026-08-04) |
| `0x005465c0` | `Mission_ExpandPlayerTokenPlaceholders_Inferred` | `[$name/class/race/credits/level]` expand (dual 2026-08-04) |
| `0x00521800` | `Character_GetRaceDisplayName_Inferred` | Race string for `[$race]` (dual 2026-08-04) |
| `0x00521900` | `Character_GetClassDisplayName_Inferred` | Class string for `[$class]` (dual 2026-08-04) |
| `0x00829ec0` | `UI_MissionJournal_MSelectEntry_Ctor_Inferred` | Journal mselect entry widget ctor (dual 2026-08-04) |
| `0x00411180` | `StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred` | Dword vector push (journal consumers among callers; dual 2026-08-04) |
| `0x0040b6d0` | `StdVector_InsertOne_RebindIt_Via419880_Inferred` | Push_back grow insert-one (dual 2026-08-04) |
| `0x007f5120` | `Input_KeyCodeToDisplayName` | Key display name for `[$key]` markup (dual 2026-08-04) |
| `0x007f9160` | `ActionMap_FormatSlotBindDisplay` | MOD+KEY bind format for markup (dual 2026-08-04) |
| `0x0060d630` | `CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress` | UseItem progress + optional GiveMission (dual 2026-08-04) |
| `0x006508d0` | `CVOGHBMissionEscort_OnHeartBeat` | Escort HB â†’ CompleteObjective / FailMission (dual 2026-08-04) |
| `0x008ae130` | `Client_UpdateMissionJournal` | Journal refresh (state 3) |
| `0x00525bd0` | `Client_FindObjectiveMatchingTarget` | Active-obj MatchTarget for UseObject |
| `0x00611940` | `CVOGObjectiveRequirement_Collect_Eval` | Live cargo count / NumToCollect fraction |
| `0x006124b0` | `CVOGObjectiveRequirement_Collect_SlotAction` | Journal `"name: have / need"` from cargo count |
| `0x005711c0` | `InventoryGrid_CountItemsByCbid` | Grid CBID quantity sum (inventory bridge) |
| `0x00611690` | `CVOGObjectiveRequirement_Collect_ctor` | type code 2; vtable `PTR_FUN_009e12c4` |
| `0x00611a00` | `CVOGObjectiveRequirement_Collect_DeserializeXml` | CBID / NumToCollect / drop % fields |

## Behavioral flow

```
SearchAutoMissions â†’ CheckMissionRequirements â†’ GiveMission â†’ AddActiveObjective
Objective progress (0x2071) â†’ RecvObjectiveState (slots only; no complete)
Server force complete (0x2070) â†’ RecvCompleteDynamicObjective â†’ CompleteObjective(force=1)
Dialog turn-in â†’ MissionDialogHandleButton â†’ local CompleteObjective (do not also 0x2070)
CompleteObjective advance â†’ next AddActiveObjective + skill/attrib
CompleteObjective final â†’ ComputeObjectiveXp/Credits â†’ AddExperience + money + rewards
NPC dialog (0x206D) â†’ MissionDialogHandleButton â†’ accept/claim/abandon
FailMission â†’ FailMissionNotify + character flag

Abandon (journal / dialog state 2):
  MissionDialogHandleButton
    â†’ DAT_00d1b4b4 = pending mission id
    â†’ post modal code 0x4e47 ("Are you sure you wish to abandon â€¦?")
  Client_UiModalDispatch
    â†’ case 0x4e47 action 8: close only (No)
    â†’ case 0x4e46 action 8: C2S FailMission 0x20B2 size 0x18 (Yes) + close
  Server processes abandon/fail
  S2C 0x20B2 â†’ Client_RecvFailMission â†’ CVOGReaction_FailMission
```

## Call graph summary

- Requirements checker calls `HasCompletedMission` for up to 4 prereq IDs at mission `+0x9c`.
- CompleteMissionObjectives walks mission def objectives array `+0x13c` count `+0x130`.
- ObjectiveState writes 4 IEEE slot floats then bit-selected evaluator **Action** (`vtable+0x20`); UI refresh via `FUN_0092ce90`; **no** EvaluatePending / CompleteObjective (dual residual 2026-07-29).

## Data flow summary

- Mission def fields: race `+0x90`, faction `+0x92`, min/max level `+0x94/+0x98`, currency `+0x104/+0x108`, flag `+0x118`, prereqs `+0x9c`.
- Character completed hashes: `+0x538`, instance `+0x53c`; active missions `+0x540`; pending objectives `+0x55c`.

## State owners

| Owner | Location | Notes |
|-------|----------|-------|
| Character mission hashes | char+0x538/53c/540/55c | In-memory only on client |
| Mission definitions | clonebase / hash via `FUN_0053fff0` | Read-only defs |

## State transitions

| From | Event | To | Evidence |
|------|-------|-----|----------|
| None | GiveMission | Active mission + objectives | `0x005327c0` |
| Active | ObjectiveState progress | Updated floats/bits | `0x00809460` |
| Active | Complete objectives | Completed hash | CompleteObjective path |
| Active | FailMission (local/S2C) | Failed + notify + dirty `+0x634\|=0x10` | `0x0052da30` |
| Active (UI) | Abandon confirm modal Yes | C2S `0x20B2` (server then S2C fail) | `0x00911840` case `0x4e46` |
| Active (UI) | Abandon confirm modal No | Modal closed; mission still active | `0x00911840` case `0x4e47` |

## External effects

- UI toasts, journal refresh, LogicUI packets, audio tables (secondary).

## Dependencies

- **Inventory collect progress** â€” sealed static cross-link 2026-07-29 (see below).
- Packet dispatch for opcodes `0x206D`, `0x206E` (C2S dialog response â€” Prepare+Flush sealed), `0x206F`, `0x2070`, `0x2071`, **`0x20B2`** (FailMission C2S/S2C).

## Inventory collect dependency (cross-system, 2026-07-29)

Client **Collect** requirements (`RequirementType` **2**, RTTI `CVOGObjectiveRequirement_Collect`) read **cargo inventory** for progress fraction and journal text. UseItem still uses 0x2071 slot floats; Collect Eval/SlotAction do not.

```
Inventory place/grab/add (type-1 cargo grid)
        â”‚
        â–¼
InventoryGrid @ char+0x250 â†’ +0x2b0
        â”‚
        â”œâ”€â”€ CountItemsByCbid(cbid) @ 0x005711c0
        â”‚         â”‚
        â”‚         â”œâ”€â”€ Collect_Eval @ 0x00611940  â†’ float 0..1
        â”‚         â””â”€â”€ Collect_SlotAction @ 0x006124b0 â†’ "Item: n / N"
        â”‚
Server path (AutoCore): ItemPickup â†’ MissionCollectProgress.SyncProgressFromInventory
        â””â”€â”€ S2C 0x2071 absolute slots (parallel authority; client may lag â€” missionHandler Â§5.5)
```

| Offset (Collect req) | Field | Source |
|---------------------:|-------|--------|
| `+0x10` | item CBID | XML `CBID` |
| `+0x14` | NumToCollect | XML `NumToCollect` |
| `+0x18` | TakeAllItems | XML |
| `+0x48` | OptionalDropPercent | XML (Action path, not Eval) |

**Artifacts:** chain `reviews/CHAIN_2026-07-29_inventory_collect.md`; inventory map Â§ Mission collect progress; duals A/B on `aa_005711c0`, `aa_00611940`, `aa_006124b0`.

**Related:** Deliver (type 3) also counts cargo for readiness â€” not Collect.

## Known types / identifiers

See `docs/missionState.md` for `eMissionSavedState` and create-packet fields.

## Important functions

Listed in entry points; records under `functions/aa_*` for captured units.

## Evidence

- Fresh Ghidra `batch_decompile` 2026-07-23
- Inventory collect bridge re-verify Ghidra HTTP 2026-07-29 (`0x005711c0`, `0x00611940`, `0x006124b0`, Collect vtable/`type=2`)
- Prior: `docs/missionState.md`, `docs/missionHandler.md`

## Confidence

| Area | Level |
|------|-------|
| Manager addresses | High |
| Requirement field offsets | High (decompile comments) |
| Full dialog button matrix | Probable |
| Runtime | Open |

## Open questions

- Exact `CheckMissionPrerequisites` vs Requirements split semantics
- Force-complete opcode `0x2070` path not yet unit-reconstructed
- Persistence is server-side; client hashes process-memory only
- ~~Exact `FUN_007fdfb0` Yes/No â†’ modal codes `0x4e46`/`0x4e47` map~~ **Sealed High (UF-009)** â€” abandon Yes=`0x4e46` / No=`0x4e47`; OK/Cancel widget bind **High** (`CNDUICtrlButton` on `CDlgPopup`, `reviews/a_007fdfb0.md`)
- ~~Full C2S `0x206E` dialog-response packing relative to HandleButton turn-in~~ **Sealed (static)** â€” Prepare `+0x650=0x206E` + HandleButton body fill + FlushPreparedResponse size `0x20` (`reviews/CHAIN_2026-07-29_c2s_206e_seal.md`); residual is **runtime live capture only** (not open packing)
- `FUN_005307e0` product dual / `FUN_0092fd00` / `DAT_00d1ad10` after S2C FailMission (RecvFailMission **UF-012 framing dual residual sealed High** â€” opcode+regs+body/return-ignored/UI tail; helper product names open)

## Verification gaps

- Dual A/B for GiveMission / CheckMissionRequirements: **done** (CheckMissionRequirements residual 2026-07-29: Ored/Negative/Discipline/Event/ABI sealed; accept-with-gaps)
- Abandon â†’ FailMission **static chain sealed** (2026-07-29): HandleButton â†’ UiModalDispatch `0x4e46` â†’ C2S `0x20B2` â†’ RecvFailMission â†’ FailMission; RecvFailMission opcode+register framing **UF-012 sealed** (call `0x00815d97`, EAX=packet/ECX=client)
- Inventory â†” collect progress **static chain sealed** (2026-07-29): CountItemsByCbid â†’ Collect_Eval + Collect_SlotAction
- Runtime dialog button matrix + abandon confirm **live** e2e (packet capture) still open
- Runtime Grab/Add â†’ Collect journal recount timing still open
- Differential against AutoCore mission services (optional later)
- ~~`FUN_00568200` journal id-vector fill~~ â€” **sealed 2026-07-29 (`aa_008ae130`):** `FUN_00568200` = tree iterator++ (not id fill); Active/New partition via hash `+0x540` + `[node+0x8]`; FailMissionNotify = Vector_PushDword at journal site
- ~~count width on 0x206D~~ â€” **sealed 2026-07-29:** client **u8** at `+0x18` (`CHAIN_2026-07-29_s2c_206d_npcmissiondialog.md`); wire i32 LE OK â‰¤255

## Dual reviews (dialog / journal / objective chain â€” 2026-07-23)

| Unit | Reviews |
|------|---------|
| `Client_RecvObjectiveState` | A/B `aa_00809460` (dual residual 2026-07-29: slot float + `FUN_0092ce90` UI + no EvaluatePending) |
| `Client_MissionDialogHandleButton` | A/B `aa_008ae7c0` |
| `Client_RecvNpcMissionDialog` | A/B `aa_00815070` |
| `Client_UpdateMissionJournal` | A/B `aa_008ae130` (residual dual 2026-07-29: iterator++ + Active/New partition) |
| `Client_ShowNpcMissionDialogUI` | A/B `aa_009438f0` (dual residual 2026-07-29: EAX/+0x64c sealed) |
| `Client_FindObjectiveMatchingTarget` | A/B `aa_00525bd0` |
| `CVOGReaction_CompleteObjective` | A/B `aa_00533f90` (prior) |
| `CVOGMission_AddActiveObjective` | A/B `aa_00531b00` (modern; prior reconstruction/skeptical kept) |
| `CVOGCharacter_HasCompletedMission` | A/B `aa_0052aa20` |
| `CVOGCharacter_CompleteMissionObjectives` | A/B `aa_00536080` |
| `CVOGCharacter_EvaluatePendingObjectives` | A/B `aa_00534920` (dual residual sealed 2026-07-29: slot + CompleteCount `def+0x164` + twin + 7 callers) |
| `CVOGCharacter_SearchAutoMissions` | A/B `aa_00532b60` |
| `CVOGCharacter_AddCredits` | A/B `aa_005355a0` |
| `CVOGCharacter_AddSkillPoints` | A/B `aa_005312c0` |
| `CVOGCharacter_AddAttributePoints` | A/B `aa_00531250` |
| `CVOGMission_EvalActiveObjectiveInteractState` | A/B `aa_004d3ef0` |
| `CVOGObjectiveRequirement_Kill_Eval` | A/B `aa_00613910` (dual residual sealed 2026-07-29 â€” formula/provenance High) |
| `CVOGObjectiveRequirement_Kill_Precheck` | A/B `aa_00613b50` |
| `CVOGObjectiveRequirement_Patrol_Eval` | A/B `aa_0060e0f0` (residual 2026-07-29: Laps/`+0x24` + absolute slot sealed) |
| `CVOGObjectiveRequirement_Patrol_Action` | A/B `aa_0060e120` |
| `CVOGObjectiveRequirement_Patrol_GetFlags` | A/B `aa_0060e260` |
| `CVOGObjectiveRequirement_Patrol_GetTarget` | A/B `aa_0060e370` |
| `CVOGObjectiveRequirement_Patrol_InitActive` | A/B `aa_0060e3d0` |
| `CVOGObjectiveRequirement_Patrol_GetSomething` | A/B `aa_0060e9e0` |
| `CVOGObjectiveRequirement_UseItem_Eval` | A/B `aa_0060cfe0` + residual 2026-07-29 (absolute `0x2071` + shared slot; scratch `tmp/a_0060cfe0.md`) |
| `CVOGObjectiveRequirement_UseItem_InitActive` | A/B `aa_0060d540` |
| `CVOGObjectiveRequirement_UseItem_MatchTarget` | A/B `aa_0060d7f0` |
| `CVOGObjectiveRequirement_UseItem_OnComplete` | A/B `aa_0060cfd0` |
| `CVOGObjectiveRequirement_UseItem_SerializeXml` | A/B `aa_0060d800` |
| `CVOGObjectiveRequirement_UseItem_SlotAction` | A/B `aa_0060d060` |
| `CVOGReaction_GiveMission` | A/B `aa_005327c0` (refreshed 2026-07-28) |
| `CVOGCharacter_CheckMissionRequirements` | A/B `aa_005462b0` (residual 2026-07-29; Ored/Negative/Discipline/Event/ABI sealed) |
| `CVOGCharacter_GetResourceBalanceByType` (`FUN_0052ada0`) | A/B `aa_0052ada0` (2026-07-29; Discipline map `+0x584` sealed) |
| `Client_IsRequirementEventActive` (`FUN_005405e0`) | A/B `aa_005405e0` (2026-07-29; event vector membership; sole caller Requirements) |
| `CVOGCharacter_CheckMissionPrerequisites` | A/B `aa_00536540` |
| `InventoryGrid_CountItemsByCbid` | A/B `aa_005711c0` (inventory bridge) |
| `CVOGObjectiveRequirement_Collect_Eval` | A/B `aa_00611940` |
| `CVOGObjectiveRequirement_Collect_SlotAction` | A/B `aa_006124b0` |

## Next recommended work

1. ~~Seal C2S `0x206E` send site relative to HandleButton turn-in~~ **Done 2026-07-29** â€” Prepare `+0x650=0x206E`; HandleButton fills body; `Client_MissionDialog_FlushPreparedResponse` @ `0x008ab8f0` sends size `0x20` (see `reviews/CHAIN_2026-07-29_c2s_206e_seal.md`)
2. ~~Abandon confirm â†’ FailMission path~~ **Done 2026-07-29 (static)** â€” state2â†’`DAT_00d1b4b4`â†’modal `0x4e47`â†’confirm `0x4e46` C2S `0x20B2`â†’`FailMission` apply (`reviews/CHAIN_2026-07-29_abandon_failmission.md`); Yes/No pairing **High (UF-009 sealed)** â€” residual is **runtime live e2e capture only**
3. ~~Wire inventory collect progress cross-links~~ **Done 2026-07-29 (static)** â€” CountItemsByCbid + Collect_Eval + Collect_SlotAction; chain `reviews/CHAIN_2026-07-29_inventory_collect.md`
4. Runtime dialog button matrix (non-abandon paths still **Probable** static) + live 0x206E/0x20B2 capture (Launcher approval required)
5. Runtime Grab/Add â†’ Collect journal string refresh timing
6. Optional: Collect_Action `0x00611f20` duals; Deliver inventory readiness duals
7. Optional: residual skill FUN_* naming with string/xref evidence only

## Mega residual duals (2026-08-05)

Nested undualed callees of dualed WQ-007 managers (tracker/objective/dialog/reward/UseItem).

41 dualed units from mega residual partition (MEGA-001..140). Parent merge: dual unique 2428→2567. Runtime Confirmed: none. Terminal: false.

| Address | Symbol | Notes |
|--------:|--------|-------|
| `0x005310a0` | `Character_GiveItemByCbid_Inventory_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0092a590` | `Tracker_SetActiveMissionObjective_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0052b350` | `CVOGCharacter_RewardInventoryList_PushBack_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0059dc50` | `ObjectiveNode_IsEligibleForTracker_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x004cc820` | `MatchTargetEval_DefaultReturnFalse_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0060e800` | `CVOGObjectiveRequirement_Patrol_EventAction_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0060df70` | `CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00402b30` | `StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x008aa510` | `MissionDialog_StampResponseSlot_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00403250` | `StdTree_InsertAndRebalance_Isnil31_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00403f30` | `StdTree_Buynode_Val32_Isnil31_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x008ab550` | `Client_NpcMissionDialog_ApplyPanelMode_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x004023f0` | `StdList_DefaultCtor_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x008aa4b0` | `MissionDialog_SetNpcObjectAndNameCaption_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x004025e0` | `StdList_PushBack_Val0x28_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00404c00` | `Math_Vec3_Length_Sqrt_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0090cbc0` | `MedalUI_RefreshPagedAchievementSlots_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00401c50` | `StdMap_StringKey_InsertOrFind_Via401db0_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00401d30` | `BasicStringFlag_CtorFromStringAndChar_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00401db0` | `StdTree_InsertAndRebalance_Isnil2D_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00402280` | `StdList_Destroy_FreeHead_ViaClearEsi_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x008aa490` | `MissionDialog_SetTurnInReadyFlag_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00401f40` | `StdTree_Buynode_StringByte_Isnil2D_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00402040` | `BasicStringFlag_CopyCtor_EdiSrc_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00418700` | `StdList_BuyNode_Dword_Seh` | mega residual dual 2026-08-05 (accept) |
| `0x00929c00` | `MissionTracker_ResetUiStateFields_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0092a3d0` | `Tracker_ClearOwnedPtrVectorAt11c_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x004027f0` | `StdList_PushFront_DwordFromEax_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0059db80` | `CVOGObjective_ProbeEligibilityCode_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0090c9a0` | `MedalUi_ApplyAchievementSlotButton_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0090c700` | `MedalUI_PrepClearButtonSlots_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0090c810` | `MedalUI_CountDisplayableEntries_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x008ab340` | `MissionSelect_ClearRowWidgetVectors_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x008ac3f0` | `Client_NpcMissionDialogHost_Ctor_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x008ac890` | `UI_MissionDialog_SetResponseCountAndRebuild_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0040dab0` | `Math_RoundFloatToInt_MissionXpBias_Inferred` | mega residual dual 2026-08-05 (accept) |
| `0x004111d0` | `Character_GetXpRemainingToMaxLevelSoftCap_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00402d10` | `StdList_PushBack_Dword_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00402dd0` | `StdList_Resize_EsiList_EaxCount_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0093e7e0` | `Client_UI_CreateNDUIDialogs_InstallHost_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x004034c0` | `StdList_InsertN_BeforeNode_Dword_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |

Open mega residual in other systems only (this system: 41/41 dualed).
