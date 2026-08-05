# Naming Registry

Canonical names only. Do not invent original studio names without evidence.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `VehicleEntity_SetSteerInput` | function | `aa_004f5620` / `0x004f5620` | `VehicleEntity_SetSteerInput` (Ghidra symbol) | input-drive-control | `client::vehicle` | Fresh decompile; prior `physics/verified/fn_004f5620_setSteerInput.md`; callers include DriveControlTick | High | none | Writes `entity+0x618` under 0xC7 gate |
| `VehicleEntity_SetLongitudinalInput` | function | `aa_004f5650` / `0x004f5650` | `VehicleEntity_SetLongitudinalInput` | input-drive-control | `client::vehicle` | Sibling decompile; same gate → `+0x614` | High | none | Not fully reconstructed this pass |
| `VehicleEntity_SetHandbrake` | function | `aa_004f3620` / `0x004f3620` | `VehicleEntity_SetHandbrake` | input-drive-control | `client::vehicle` | Decompile + dual residual 2026-07-29: unguarded store `+0x61c` | High | none | No 0xC7 gate; MoveToTarget bypasses setter |
| `Client_Input_DriveControlTick` | function | `aa_009223b0` / `0x009223b0` | `Client_Input_DriveControlTick` | input-drive-control | `client::input` | Decompile + plate comments; primary entry for held drive flags | High | DriveControlTick | Large; map only this pass |
| `VehicleEntity_PushDriveAxesToController` | function | `aa_004fbc10` / `0x004fbc10` | `VehicleEntity_PushDriveAxesToController` / prior `FUN_004fbc10` | input-drive-control | `client::vehicle` | Callee of DriveControlTick; physics notes | Probable | FUN_004fbc10 | Downstream of axis writes |
| `steerInput` | field | entity `+0x618` | `*(float*)(this+0x618)` | input-drive-control | `VehicleEntity` | Store site in SetSteerInput | High | entity+0x618 | f32 axis typically [-1,+1] |
| `longitudinalInput` | field | entity `+0x614` | `*(float*)(this+0x614)` | input-drive-control | `VehicleEntity` | Store site in SetLongitudinalInput | High | entity+0x614 | f32 |
| `handbrakeFlag` | field | entity `+0x61c` | `*(uint8*)(this+0x61c)` | input-drive-control | `VehicleEntity` | SetHandbrake store | High | entity+0x61c | u8 / bool-like |
| `driveAxisGateObject` | field/object | via `*(*( *(this+4)+4 ) + this + 0xb0)` | decompiler `iVar1` | input-drive-control | unknown | Gate chain in both setters | Probable | wobj; was driveAxisLockObject | Exact type unresolved; "lock" unproven |
| `driveAxisSuppressFlags` | field | gateobj `+0xb4` | `*(byte*)(iVar1+0xb4)` | input-drive-control | unknown | Masked with `0xC7` | Probable (as suppress bits) | driveAxisLockFlags | Per-bit meaning unknown; avoid "lock" seal |
| `INPUT_AXIS_SUPPRESS_MASK` | constant | `0xC7` / 199 | decompiler `199` | input-drive-control | — | Both setters | Confirmed (value) | INPUT_AXIS_LOCK_MASK, 199 | Bits 0x01\|0x02\|0x04\|0x40\|0x80 |

## Rename history

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-07-23 | aa_004f5620 | already named in Ghidra | keep `VehicleEntity_SetSteerInput` | Matches evidence; no invent |
| 2026-07-23 | gate mask names | INPUT_AXIS_LOCK_MASK / driveAxisLock* | INPUT_AXIS_SUPPRESS_MASK / driveAxisGate* | Skeptical review: "lock" semantics unproven |

## Mission batch names

Append-only batch for missions-progression units (`aa_0052*`, `aa_0053*`, `aa_00809460`, `aa_00815070`, `aa_008ae*`). Canonical names match Ghidra symbols / plate comments; no invented studio names.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `CVOGCharacter_HasCompletedMission` | function | `aa_0052aa20` / `0x0052aa20` | `CVOGCharacter_HasCompletedMission` | missions-progression | `client::mission` | Raw decompile; completed hashes `+0x538`/`+0x53c` | High | none | Continent match on def `+0xfc` |
| `CVOGReaction_FailMission` | function | `aa_0052da30` / `0x0052da30` | `CVOGReaction_FailMission` | missions-progression | `client::mission` | Raw + asm dual residual; active hash `+0x540`; Notify `ECX=char+0x560` | High | none | Push end-quest ids; `+0x634\|=0x10`; no hash erase; abandon via S2C only |
| `CVOGMission_AddActiveObjective` | function | `aa_00531b00` / `0x00531b00` | `CVOGMission_AddActiveObjective` | missions-progression | `client::mission` | Raw + asm: def hash `+0x548`, pending `+0x55c`; evaluators `+0x158/+0x15c`; node `0x14` | High | none | Dirty `+0x634\|=0x10`; dual tightened 2026-07-29 |
| `CVOGReaction_GiveMission` | function | `aa_005327c0` / `0x005327c0` | `CVOGReaction_GiveMission` | missions-progression | `client::mission` | Raw; inserts active mission/objective; toast path | High | none | Watch `undefined4*` field indexing |
| `CVOGCharacter_SearchAutoMissions` | function | `aa_00532b60` / `0x00532b60` | `CVOGCharacter_SearchAutoMissions` | missions-progression | `client::mission` | Raw; iterates auto defs → Requirements → Give | High | none | `this[0x150]` = byte `+0x540` |
| `CVOGReaction_CompleteObjective` | function | `aa_00533f90` / `0x00533f90` | `CVOGReaction_CompleteObjective` | missions-progression | `client::mission` | Raw + dual review; advance/final; XP/credits final | High | none | force=1 from 0x2070 |
| `CVOGCharacter_EvaluatePendingObjectives` | function | `aa_00534920` / `0x00534920` | `CVOGCharacter_EvaluatePendingObjectives` | missions-progression | `client::mission` | Dual residual sealed 2026-07-29; pending `+0x55c` **slot** (`def=*slot`); CompleteCount `FUN_0059d880`=`*(def+0x164)`; twin of CompleteObjective force=0; 7 callers | High | none | Vtable `+4/+8/+0x20`; collect `(count!=0 && count<=succ)\|\|allTrue` + `def+0x138==0` |
| `Mission_ComputeObjectiveXp` | function | `aa_0059dde0` / `0x0059dde0` | `Mission_ComputeObjectiveXp` | missions-progression | `client::mission` | Raw + dual residual seal 2026-07-29; pure XP calc; map node High | High | table payloads / runtime | Bias is caller-side; presentation xrefs too |
| `Mission_ComputeObjectiveCredits` | function | `aa_0059df20` / `0x0059df20` | `Mission_ComputeObjectiveCredits` | missions-progression | `client::mission` | Dual residual 2026-07-29; ceil+FISTP chop | High | none | Adds at char+0x720 by caller |
| `CVOGCharacter_CompleteMissionObjectives` | function | `aa_00536080` / `0x00536080` | `CVOGCharacter_CompleteMissionObjectives` | missions-progression | `client::mission` | Raw; def `+0x130` count, `+0x13c` array | High | none | `__cdecl`; reason forwarded |
| `CVOGCharacter_CheckMissionPrerequisites` | function | `aa_00536540` / `0x00536540` | `CVOGCharacter_CheckMissionPrerequisites` | missions-progression | `client::mission` | Dual residual edges 2026-07-29: mutator; call matrix (1,1)/(1,0)/(0,0); +0x124 RequirementsNegative | High | none | Not pure predicate; ≠ Requirements |
| `Client_RecvObjectiveState` | function | `aa_00809460` / `0x00809460` | `Client_RecvObjectiveState` | missions-progression | `client::mission` | Raw + dual residual 2026-07-29; S2C `0x2071` progress slots | High | none | Does not CompleteObjective; slots IEEE float |
| `Client_RefreshMissionRelatedUi` | function | `aa_0092ce90` / `0x0092ce90` | `FUN_0092ce90` | missions-progression | `client::mission` | Decompile; RecvObjectiveState / inventory callers; dual residual 2026-07-29 | High (role) | original unknown | Refreshes `client+0x107c` / `+0x10b8`; not EvaluatePending |
| `missionUiRoot` | field | client `+0x107c` | `*(ptr*)(client+0x107c)` | missions-progression | client controller | HideMissionDialogIfOpen; RecvObjectiveState; FUN_0092ce90 | High (role) | none | Mission dialog / mission UI root |
| `Client_RecvCompleteDynamicObjective` | function | `aa_0080ff00` / `0x0080ff00` | `Client_RecvCompleteDynamicObjective` | missions-progression | `client::mission` | Raw; S2C `0x2070` force CompleteObjective | High | was misnamed RecvObjectiveState | Always force=1 |
| `Client_RecvNpcMissionDialog` | function | `aa_00815070` / `0x00815070` | `Client_RecvNpcMissionDialog` | missions-progression | `client::mission` | Raw; S2C `0x206D`; stride 40 entries | High | none | Ends in ShowNpcMissionDialogUI |
| `Client_UpdateMissionJournal` | function | `aa_008ae130` / `0x008ae130` | `Client_UpdateMissionJournal` | missions-progression | `client::mission` | Raw; state `+0x648==3`; Active/New via hash `+0x540`+`[node+0x8]`; residual dual 2026-07-29 | High | none | UI rebuild; EBX-heavy; FailMissionNotify=push |
| `Client_MissionDialogHandleButton` | function | `aa_008ae7c0` / `0x008ae7c0` | `Client_MissionDialogHandleButton` | missions-progression | `client::mission` | Raw; state 0–3; C2S `0x206F`; fills 0x206E body | High | none | Accept / claim / abandon / re-show |
| `Client_MissionDialog_FlushPreparedResponse` | function | `aa_008ab8f0` / `0x008ab8f0` | `FUN_008ab8f0` | missions-progression | `client::mission` | Asm send `+0x650` size `0x20`; vtbl `0x00a4a95c` | High | original name unknown | **C2S 0x206E send site** |
| `Client_UiModalDispatch` | function | `aa_00911840` / `0x00911840` | `FUN_00911840` | missions-progression | `client::ui` | Abandon cases `0x4e46`/`0x4e47` | High (slice) | full switch open | Confirm → C2S `0x20B2` |
| `Client_RecvFailMission` | function | `aa_0080b100` / `0x0080b100` | `FUN_0080b100` | missions-progression | `client::mission` | PacketDispatch `0x20b2` sole xref `0x00815d97`; UF-012 framing dual residual; FailMission thiscall; packet `+0x10`; return ignored; end-quest always | High | original symbol unknown | S2C apply after fail; EAX=packet ECX=client |
| `pendingAbandonMissionId` | global | `DAT_00d1b4b4` | `DAT_00d1b4b4` | missions-progression | — | HandleButton state 2 WRITE; modal READ | High | none | Stash for abandon confirm |
| `OPCODE_C2S_FAIL_MISSION` | constant | `0x20B2` | case `0x4e46` packet | missions-progression | — | Asm + decompile size `0x18` | High | 0x20B2 | Abandon confirm C2S |
| `InventoryGrid_CountItemsByCbid` | function | `aa_005711c0` / `0x005711c0` | `FUN_005711c0` | inventory-transfer | `client::inventory` | Collect_Eval/SlotAction + decompile; dual residual 2026-07-29 | High | original unknown | Sum qty by CBID; exclude Broken unless includeBroken |
| `ItemFlag_Broken` | field/flag | `item+0x17c` bit 19 / mask `0x80000` | `object[0x5f]>>0x13` | inventory-transfer | `client::inventory` | `"Broken: "` loot+UI; `i_g_2d_overlay_broken.dds`; setter `0x00513de0` | High | original unknown | Broken item state |
| `Item_SetBroken` | function | `aa_00513de0` / `0x00513de0` | `FUN_00513de0` | inventory-transfer | `client::inventory` | Dual A/B 2026-07-29; bytes seal mask `0x80000`; dirty `FUN_00512670`; vtbl+0x90 if set | High (mask/CF) | original unknown | Set/clear ItemFlag_Broken |
| `Item_IsStackEligible` | function | `aa_00513e70` / `0x00513e70` | `FUN_00513e70` | inventory-transfer | `client::inventory` | Dual A/B 2026-07-29; bytes seal `type4\|\|(blob+0x3f2&0x40&&!Broken)` | High (role) | original unknown | Stack-merge/display eligibility; **not** capacity (`0x0040abf0`) |
| `Item_CanAcceptStackQty` | function | `aa_0040abf0` / `0x0040abf0` | `FUN_0040abf0` | inventory-transfer | `client::inventory` | Dual A/B 2026-07-29; bytes seal `(qty+add)<=(max&0xFFFF)`; type4 999999→16959; def+0x4BA /0→200 | High (role/CF) | original unknown | Stack capacity fit; **not** eligibility (`0x00513e70`) |
| `List_TraversalLock` | function | `aa_004294f0` / `0x004294f0` | `FUN_004294f0` | inventory-transfer | `client::list` | string `List Error! TraversalLock Call Stack` | High (role) | original unknown | Enter list CS for traversal |
| `List_IterateNext` | function | `aa_004022a0` / `0x004022a0` | `FUN_004022a0` | inventory-transfer | `client::list` | list node walk under TraversalLock | High (role) | original unknown | Next object under locked list |
| `CVOGObjectiveRequirement_Collect_Eval` | function | `aa_00611940` / `0x00611940` | `FUN_00611940` | missions-progression | `client::mission` | Count/NumToCollect; cargo path; vtable+0x10; RET8 ABI; dual residual 2026-07-29 | High | original unknown | Progress 0..1 |
| `CVOGObjectiveRequirement_Collect_SlotAction` | function | `aa_006124b0` / `0x006124b0` | `FUN_006124b0` | missions-progression | `client::mission` | vtable+0x18; `"%s: %d / %d"` + CountItemsByCbid | High (role) | original unknown | Live cargo UI text |
| `CVOGObjectiveRequirement_Collect_ctor` | function | `aa_00611690` / `0x00611690` | `FUN_00611690` | missions-progression | `client::mission` | type code 2; vtable `PTR_FUN_009e12c4`; dual A/B seal 2026-07-29 | High | original unknown | Collect ctor |
| `CVOGObjectiveRequirement_Collect_DeserializeXml` | function | `aa_00611a00` / `0x00611a00` | `FUN_00611a00` | missions-progression | `client::mission` | strings CBID/NumToCollect/collect error | High | original unknown | GLM field load |
| `CVOGObjectiveRequirement_Collect` | type | RTTI `0x00afe9ac` / vtable `0x009e12c4` | `.?AVCVOGObjectiveRequirement_Collect@@` | missions-progression | — | RTTI string + ctor | High | none | Collect requirement class |
| `collectReqItemCbid` | field | req `+0x10` | XML `CBID` | missions-progression | Collect req | SerializeXml + Eval | High | none | Item to count |
| `collectReqNumToCollect` | field | req `+0x14` | XML `NumToCollect` | missions-progression | Collect req | SerializeXml + Eval | High | none | Target stack count |
| `Client_SendUseObject` | function | `aa_00916740` / `0x00916740` | `Client_SendUseObject` | interaction-activation | `client::interact` | Fresh decompile + dual A/B 2026-07-29; C2S `0x2072` size `0x20` | High | none | TFID + objective (−1 none); stash `client+0xd28` |
| `Client_SendUseObject_IfInteractable` | function | `aa_00930d70` / `0x00930d70` | `Client_SendUseObject_IfInteractable` | interaction-activation | `client::interact` | Fresh decompile + dual A/B 2026-07-29 | High | none | Gated send; objective id or 0 (type-4) |
| `Client_InteractClickPickTarget` | function | `aa_009247b0` / `0x009247b0` | `Client_InteractClickPickTarget` | interaction-activation | `client::interact` | Human refine + dual A/B 2026-07-29; pick → UseObject | High (role + gate) | none | Dist gate `DAT_00aaa6fc`=25f; type4→`0x205D` |
| `Client_UpdateNpcInteractIcons` | function | `aa_0091b8d0` / `0x0091b8d0` | `Client_UpdateNpcInteractIcons` | interaction-activation | `client::interact` | Plate dual; chrome only | High (role) | none | No `0x2072` send |
| `CVOGCharacter_FindActiveObjectiveIdForInteract` | function | `aa_00524520` / `0x00524520` | `FUN_00524520` | interaction-activation | `client::mission` | Decompile: hash `+0x548` → id `@+0x10` | Probable | FUN_00524520; was Named_VOG_DEBUG_STOP | Gate + id for IfInteractable |
| `CVOGCharacter_FindActiveObjectiveIdForPick` | function | `aa_005245d0` / `0x005245d0` | `FUN_005245d0` | interaction-activation | `client::mission` | Clone walk; `CVOGObjective_MatchTargetEvaluators_Slot44` eval **+0x44**; dual A/B 2026-07-29 | Probable | FUN_005245d0; scaffold InteractAlt | Pick/hover id; sibling of ForInteract |
| `OPCODE_C2S_USE_OBJECT` | constant | `0x2072` | SendUseObject packet literal | interaction-activation | — | Both send paths | High | 0x2072 | UseObject C2S |
| `CLIENT_USEOBJECT_RANGE` | constant | `DAT_00aaa6fc` = `25.0f` (`0x41c80000`) | float at `0x00aaa6fc` | interaction-activation | — | Ghidra `read_memory` 2026-07-29 | High | DAT_00aaa6fc | Click path gate before SendUseObject |
| `lastUseObjectTarget` | field | client `+0xd28` | `*(ptr*)(client+0xd28)` | interaction-activation | client controller | SendUseObject store | High | none | Last-use stash |
| `objectTfId` | field | object `+0x160` | TFID_16 block | interaction-activation | world object | Both send paths pack 16 B | High | none | Wire target |
| `objectInteractFlag` | field | object `+0x11c` | `*(int*)(obj+0x11c)` | interaction-activation | world object | Pick/poll prefer SendUseObject | Probable | none | Non-zero → unconditional path |
| `charCompletedMissionsHash` | field | char `+0x538` | `*(void**)(this+0x538)` | missions-progression | `CVOGCharacter` | HasCompletedMission / GiveMission / SearchAuto | High | permanent completed | CNDHash* |
| `charInstanceCompletedMissionsHash` | field | char `+0x53c` | `*(void**)(this+0x53c)` | missions-progression | `CVOGCharacter` | HasCompletedMission instance path | High | instance completed | CNDHash* |
| `charActiveMissionsHash` | field | char `+0x540` | `*(void**)(this+0x540)` | missions-progression | `CVOGCharacter` | Fail/Give/Search/Prereq | High | active missions | CNDHash* |
| `charActiveObjectivesHash` | field | char `+0x548` | AddActiveObjective asm `MOV ECX,[this+0x548]` → `FUN_0053c460` | missions-progression | `CVOGCharacter` | Def insert this for active objectives | High | active objectives | Dual-tighten aa_00531b00 |
| `charPendingObjectivesHash` | field | char `+0x55c` | `*(void**)(this+0x55c)` | missions-progression | `CVOGCharacter` | EvaluatePending; RecvObjectiveState | High | pending objectives | CNDHash* |
| `charMissionDirtyFlags` | field | char `+0x634` | `*(uint*)(this+0x634)` | missions-progression | `CVOGCharacter` | FailMission / AddActiveObjective `|= 0x10`; family also `1`/`2`/`0x20`/`0x40` | Probable | mission dirty | Bit `0x10` not fail-exclusive; readers open |
| `charEndQuestIdVector` | field | char `+0x560` (triple `+0x564/+0x568/+0x56c`) | FailMission Notify `this` | missions-progression | `CVOGCharacter` | asm `LEA ECX,[ESI+0x560]`; drained by `FUN_005307e0` | High (layout) | end-quest id list | Generic push helper `0x004149d0` multi-caller |
| `missionDefObjectiveCount` | field | def `+0x130` | `*(byte*)(def+0x130)` | missions-progression | mission def | CompleteMissionObjectives | High | none | u8 count |
| `missionDefObjectiveArray` | field | def `+0x13c` | `*(ptr*)(def+0x13c)` | missions-progression | mission def | CompleteMissionObjectives | High | none | ptr table of objective defs |
| `missionDefPrereqIds` | field | def `+0x9c` | four `uint` slots | missions-progression | mission def | CheckMissionPrerequisites | High | none | `0xFFFFFFFF` = empty |
| `missionDefMinLevel` | field | def `+0x94` | `*(int*)(def+0x94)` | missions-progression | mission def | CheckMissionPrerequisites | High | none | compared to vtable level |
| `missionDefRace` | field | def `+0x90` | `*(ushort*)(def+0x90)` | missions-progression | mission def | CheckMissionPrerequisites | High | none | vs char race byte |
| `missionDefFaction` | field | def `+0x92` | `*(ushort*)(def+0x92)` | missions-progression | mission def | CheckMissionPrerequisites | High | none | `0xFFFF` = any |
| `objectiveDefEvaluators` | field | obj `+0x158`/`+0x15c` | begin/end ptr range | missions-progression | objective def | AddActive / Evaluate / RecvState | High | none | count `(end-begin)>>2` |
| `objectiveDefId` | field | obj `+0x10` | `*(uint*)(obj+0x10)` | missions-progression | objective def | CompleteObjective key | High | none | u32 id |
| `OPCODE_S2C_NPC_MISSION_DIALOG` | constant | `0x206D` | plate / RecvNpcMissionDialog | missions-progression | — | Raw plate | High | 0x206D | Open dialog |
| `OPCODE_C2S_MISSION_DIALOG_RESPONSE` | constant | `0x206E` | Prepare `+0x650` + Flush size `0x20` | missions-progression | — | Prepare imm + Flush send sealed 2026-07-29 | High | 0x206E | HandleButton fills body only |
| `OPCODE_C2S_MISSION_ACCEPT_REQUEST` | constant | `0x206F` | HandleButton state 0 packet | missions-progression | — | Raw `auStack = 0x206f` | High | 0x206F | Sector send size 0x18 |
| `OPCODE_S2C_COMPLETE_DYNAMIC_OBJECTIVE` | constant | `0x2070` | RecvCompleteDynamicObjective plate | missions-progression | — | Raw plate | High | 0x2070 | Force complete |
| `OPCODE_S2C_OBJECTIVE_STATE` | constant | `0x2071` | RecvObjectiveState plate | missions-progression | — | Raw plate | High | 0x2071 | Progress-only |
| `OPCODE_C2S_FAIL_MISSION` | constant | `0x20B2` | UiModalDispatch case `0x4e46` packet literal | missions-progression | — | C2S abandon send size `0x18`; S2C same opcode → RecvFailMission | High | `OPCODE_S2C_FAIL_MISSION`, FailMission, 0x20B2 | Bidirectional; wire: pad4 + COID i64 + MissionId i32 + pad4 |
| `pendingAbandonMissionId` | global | `DAT_00d1b4b4` | `DAT_00d1b4b4` | missions-progression | — | HandleButton state 2 store; UiModalDispatch lookup key | High | DAT_00d1b4b4 | `0xFFFFFFFF` = no pending abandon |
| `Client_UiModalDispatch` | function | `aa_00911840` / `0x00911840` | `FUN_00911840` | missions-progression | `client::ui` | Abandon cases `0x4e46`/`0x4e47`; C2S `0x20B2` | High | FUN_00911840 | Large modal switch; abandon slice reconstructed |
| `Client_RecvFailMission` | function | `aa_0080b100` / `0x0080b100` | `FUN_0080b100` | missions-progression | `client::mission` | PacketDispatch `0x20b2` → FailMission; UF-012 framing dual residual sealed | High | Client_OnFailMissionPacket, FUN_0080b100 | MissionId @ packet+0x10; char @ game+0xe98; end-quest always |
| `dialogUiState` | field | dialog host `+0x648` | `*(int*)(host+0x648)` | missions-progression | mission dialog UI | HandleButton / UpdateJournal | High | state 0–3 | 3 = journal view |
| `dialogTurnInMode` | field | dialog host `+0x64c` | `*(char*)(host+0x64c)` | missions-progression | mission dialog UI | HandleButton claim path | High | none | Non-zero = complete/deliver |

### Abandon → FailMission chain notes (2026-07-29)

| Step | Symbol | Address / value |
|------|--------|-----------------|
| Journal abandon button | `Client_MissionDialogHandleButton` state 2 | `0x008ae7c0` |
| Pending id | `pendingAbandonMissionId` | `DAT_00d1b4b4` |
| Modal post code | `FUN_007fdfb0(..., 0x4e47, ...)` | cancel case id |
| Confirm / cancel modal | `Client_UiModalDispatch` cases `0x4e46` / `0x4e47` | `0x00911840` |
| C2S opcode | `OPCODE_C2S_FAIL_MISSION` | `0x20B2` size `0x18` |
| S2C apply | `Client_RecvFailMission` | `0x0080b100` |
| Fail kernel | `CVOGReaction_FailMission` | `0x0052da30` |

### Interaction / UseObject chain notes (2026-07-29)

| Step | Symbol | Address / value |
|------|--------|-----------------|
| Click pick hub | `Client_InteractClickPickTarget` | `0x009247b0` |
| Bound-action poll (interact slice) | `Client_Input_PollBoundActions` | `0x00925d60` |
| Unconditional send | `Client_SendUseObject` | `0x00916740` |
| Gated send | `Client_SendUseObject_IfInteractable` | `0x00930d70` |
| Objective def\* match (SendUseObject) | `Client_FindObjectiveMatchingTarget` | `0x00525bd0` (MatchTarget `vtable+0x38`) |
| Objective id match (IfInteractable) | `CVOGCharacter_FindActiveObjectiveIdForInteract` | `0x00524520` (via `FUN_0059d9c0` `vtable+0x40`) |
| Objective id match (pick/hover) | `CVOGCharacter_FindActiveObjectiveIdForPick` | `0x005245d0` (via `CVOGObjective_MatchTargetEvaluators_Slot44` `vtable+0x44`) |
| C2S opcode / size | `OPCODE_C2S_USE_OBJECT` | `0x2072` / `0x20` |
| Client range gate | `CLIENT_USEOBJECT_RANGE` | `25.0f` @ `DAT_00aaa6fc` |
| Icon chrome (no send) | `Client_UpdateNpcInteractIcons` | `0x0091b8d0` |

**Rename note:** `FUN_00524520` prior alias `Named_VOG_DEBUG_STOP` is misleading (string is hash-lock assert). Proposed canonical `CVOGCharacter_FindActiveObjectiveIdForInteract` — **Probable**. Sibling `FUN_005245d0` → `CVOGCharacter_FindActiveObjectiveIdForPick` — **Probable**; Ghidra renamed 2026-07-29.

## Inventory batch names

Canonical names for inventory-transfer units refined in the annotated raw layer (2026-07-23). `_Inferred` = retail symbol not recovered.

| Canonical name | Kind | Stable ID / address | Notes |
|----------------|------|---------------------|-------|
| `Vehicle_CreateCargoInventoryFromPageCount` | function | `aa_004f3a30` / `0x004f3a30` | Cargo grid 6×(pages×13) @ vehicle+0x2b0 |
| `InventoryGrid_AllocateCellArray_Inferred` | function | `aa_00570720` / `0x00570720` | width×height cells ×8; empty=0xFFFFFFFF |
| `InventoryGrid_FindFreeSlot` | function | `aa_005713a0` / `0x005713a0` | First-fit Y outer, X inner; CanPlace |
| `InventoryGrid_FindFreeForItem` | function | `aa_005714e0` / `0x005714e0` | Item-aware space probe; tail → FindFreeSlot; dual sealed 2026-07-29 |
| `InventoryGrid_PlaceItemFootprint` | function | `aa_00571620` / `0x00571620` | Stamp COID into every footprint cell |
| `InventoryGrid_ctor_Inferred` | function | `aa_00572650` / `0x00572650` | Construct 0x68-byte grid; alloc cells |
| `Client_RecvInventoryGrabResponse` | function | `aa_00811be0` / `0x00811be0` | S2C 0x2035; stack split / cursor; dual residual 2026-07-29 |
| `Client_InventoryGrabApplyToCursor` | function (proposed) | `aa_0093d6e0` / `0x0093d6e0` | GrabResponse/Unequip cursor apply; EAX=item DL=invType |
| `Object_SetCoidIdentity` | function (proposed) | `aa_00512160` / `0x00512160` | thiscall write COID +0x160/164 flag +0x168 |
| `Client_RecvInventoryDropResponse` | function | `aa_00813730` / `0x00813730` | S2C 0x2037; type 1/3/5/6 → Place |
| `Client_RecvInventoryUnequipNotify` | function | `aa_00813bf0` / `0x00813bf0` | S2C 0x203E size 0x30 |
| `Client_RecvInventoryEquip` | function | `aa_00813f40` / `0x00813f40` | S2C 0x203C size 0x40 |
| `Client_RecvInventoryAddItem` | function | `aa_008151a0` / `0x008151a0` | S2C add/loot; place helpers |
| `Client_UI_InventoryDropToGrid` | function | `aa_00860a50` / `0x00860a50` | C2S 0x2036 size 0x20 |
| `Client_UI_InventoryDropHitTest` | function | `aa_0085f220` / `0x0085f220` | Drop cell hit-test; page-local X/Y + CanPlace; dual 2026-07-29 |
| `Client_SendInventoryGrab_FromGrid` | function | `aa_00860e20` / `0x00860e20` | C2S 0x2034 size 0x20; pack/split dual residual 2026-07-29 |

## Skills batch names

Canonical Ghidra symbols for the skills-abilities annotation batch (`docs/reconstruction/raw/` aa_009*, aa_0051*, aa_0054*, aa_0055*, aa_0058*, aa_004d09a0). Count: **8**.

| Canonical name | Stable ID | VA | Role (short) |
|----------------|-----------|-----|--------------|
| `CVOGReaction_CastSkillOnTarget` | `aa_004d09a0` | `0x004d09a0` | Pack local/reaction `SkillStatusEffect` `0x2031` |
| `Skill_LocalCastValidate` | `aa_0051a790` | `0x0051a790` | Local pre-cast gates → `eSkillResponses` |
| `Skill_StartCastAgainHeartbeat` | `aa_00519200` | `0x00519200` | Alloc type-8 cast-again HB + enqueue/start |
| `Skill_ApplyStatusEffectLocal` | `aa_0051aa00` | `0x0051aa00` | Local 0x2031 apply / cancel / delay HB |
| `CVOGHBOKToCastAgain_ctor` | `aa_0051e240` | `0x0051e240` | Type-8 HB; CD duration formula |
| `Skill_ResolveTargetList` | `aa_00550300` | `0x00550300` | Build TFID list; outFlags; gather |
| `CVOGReaction_ResolveSkillTargets` | `aa_0054c570` | `0x0054c570` | Materialize ranked skill runtime (`0x630`) from def map; miss→null; rank `+0x5f6` (name misnomer vs targets) |
| `Skill_ValidateTargetForSkill` | `aa_00553650` | `0x00553650` | Handler vtbl+0x44 target legality + HB list probe |
| `Skill_ValidateTarget_HBSkillListener` | `aa_005532e0` | `0x005532e0` | HB list predicate; RTTI `CVOGHBSkillBase`; `"Skill found with no base class: %d"` |
| `CVOGHBSkillBase_ctor` | `aa_005788d0` | `0x005788d0` | RTTI `CVOGHBSkillBase`; ValidateTarget notify=1 |
| `Skill_FilterTargetForResolveList_Inferred` | `aa_0054ff00` | `0x0054ff00` | ResolveTargetList filter; outFlags 4/8/0x10 |
| `Skill_RangeCheckTargetForResolveList_Inferred` | `aa_0058c0a0` | `0x0058c0a0` | Range helper after filter; return 0 → outFlags bit2 |
| `Skill_ApplyEffectsOnTarget_Inferred` | `aa_005538a0` | `0x005538a0` | Combat/effect apply core; events 4/0xc/0xe/5/6; handler +0x5f0 |
| `Skill_AccuracyHitCheck_Inferred` | `aa_00553240` | `0x00553240` | Accuracy hit/miss; skill+0x24; -1 auto-hit; (roll%100)*0.01 |
| `Skill_AccuracyScore_Inferred` | `aa_005531d0` | `0x005531d0` | Accuracy score helper; bonus+skill+0x24 → NonCreatureCastAutoHit |
| `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` | `aa_004f8b80` | `0x004f8b80` | ResolveCastTarget alt TFID helper |
| `CNDDoubleList_InvokePredicateAndRemove_Inferred` | `aa_004e2600` | `0x004e2600` | CS list walk/remove; ValidateTarget consumer |
| `Outpost_CastSkillsForFaction` | `aa_00606d70` | `0x00606d70` | `"Invalid outpost skill cast for skill %d, map: %s"`; ValidateTarget + CastSkillOnTarget |
| `Outpost_CastSkillsForBeaconShare` | `aa_006070e0` | `0x006070e0` | Same outpost cast string; beacon-share ratio path |
| `NPC_TryCastSkillFromSet` | `aa_005d1280` | `0x005d1280` | AI cast from skill-set table |
| `Skill_GatherTargetsInArea` | `aa_0058d330` | `0x0058d330` | Area/chain TFID gather (INFERRED name sense) |
| `Client_RecvSkillStatusEffect` | `aa_00811170` | `0x00811170` | S2C 0x2031 handler |
| `Client_Skill_ResolveCastTarget` | function | `aa_0093b3a0` / `0x0093b3a0` | Player TFID resolve via ResolveTargetList |
| `Client_QuickBar_ActivateSlot` | function | `aa_009436c0` / `0x009436c0` | Hotbar slot dispatcher (skill/item/chat-macro; dual residual 2026-07-29) |
| `CVOGCharacter_SetQuickBarSkill` | function | `aa_005208c0` / `0x005208c0` | char+0x74c skill id bind |
| `CVOGCharacter_SetQuickBarItem` | function | `aa_00520890` / `0x00520890` | char+0x930 item COID bind |
| `Client_QuickBarActivateSkillSlot` | `aa_00921b50` | `0x00921b50` | Hotbar slot → C2S `0x2030` |
| `Client_RequestCastSkill` | `aa_00941590` | `0x00941590` | Validate + optimistic CD HB + send `0x2030` |
| `Client_CastSkillFromQuickBarSlot` | `aa_009418e0` | `0x009418e0` | skillId → resolve aim/TFID → RequestCast |
| `Client_CastAfterPrompt` | `aa_00941ac0` | `0x00941ac0` | Pending `+0x30c0` → RequestCast after target pick; clear prompt |

Related symbols referenced in annotations: `Skill_FormatFailureMessage`, `Skill_SetRankAndReevaluate`.

## String-literal rename batch (2026-07-23)

Human names for high-value `FUN_*` units with clear AuthServer / Inventory / Mission / QuickBar / Skill / Login / `palantir/` string evidence. `FUN_*.cpp` retained; function records updated to canonical clean path.

| Address | Canonical name | Evidence (short) |
|---------|----------------|------------------|
| `0x00727c90` | `AuthClient_OnSCCCheckReq` | `SCCCheckReq` / AuthServer |
| `0x00727d70` | `AuthClient_OnServerListEx` | `ServerListEx` / AuthServer |
| `0x00727e50` | `AuthClient_OnServerListFail` | `ServerListFail` / AuthServer |
| `0x00727f30` | `AuthClient_OnPlayOk` | `PlayOk` / AuthServer |
| `0x00728010` | `AuthClient_OnPlayFail` | `PlayFail` / AuthServer |
| `0x007280f0` | `AuthClient_OnLoginOk` | `LoginOk` / AuthServer |
| `0x00728210` | `AuthClient_OnLoginFail` | `LoginFail` / AuthServer |
| `0x007282f0` | `AuthClient_OnBlockedAccountWithMsg` | `BlockedAccountWithMsg` |
| `0x007283d0` | `AuthClient_OnBlockedAccount` | `BlockedAccount` |
| `0x007284b0` | `AuthClient_OnAccountKicked` | `AccountKicked` |
| `0x00728590` | `AuthClient_OnProtocolVer` | `ProtocolVer` |
| `0x00728700` | `AuthClient_SendSCCCheck` | `SCCCheck` outbound |
| `0x00728840` | `AuthClient_SendServerListEx` | `ServerListEx` outbound |
| `0x00728990` | `AuthClient_SendAboutToPlay` | `AboutToPlay` |
| `0x00728ae0` | `AuthClient_SendLogout` | `Logout` |
| `0x00728c20` | `AuthClient_SendLoginInsecure` | `LoginInsecure` + AuthClientImpl.cpp |
| `0x007290e0` | `AuthClient_CloseTcpConnection` | `[Closing TCP Connection]` |
| `0x00729200` | `AuthClient_OnOpenedTcpConnection` | `[Opened TCP Connection]` |
| `0x008096c0` | `Client_OnGlobalForceQuitDialog` | multiple logins / login screen |
| `0x0080c3c0` | `Client_ShowLoginFailureDialog` | Failed to login |
| `0x0080fea0` | `Client_OnServerNotAcceptingLogins` | not accepting logins |
| `0x00812de0` | `Client_OnServerConnectionTerminated` | connection terminated → login |
| `0x008221e0` | `Client_OnAuthDisconnected` | OnDisconnected + login fail |
| `0x009494c0` | `Client_OnBadCharacterLoginId` | Bad character ID on login |
| `0x009365e0` | `Client_LoadVogIniConfig` | VOG.ini AUTHSERVERIP/ID |
| `0x00931870` | `Inventory_WriteSwapDebugLog` | InventoryLog.txt |
| `0x00931db0` | `Client_ShowEquipFailureMessage` | inventory space equip msgs |
| `0x00941b20` | `Client_ConfirmEquipOrCustomizeItem` | equip/customize confirms |
| `0x0093c700` | `Client_ShowVendorBuyFailureMessage` | inventory too full to buy |
| `0x0094caa0` | `Client_ShowInventoryFullAcceptMessage` | too full to accept |
| `0x0093bf60` | `Inventory_LogMissingItemAfterRandomize` | cargo/locker randomize miss |
| `0x00810360` | `Client_OnVehicleSwitchFailure` | vehicle not in inventory |
| `0x0080a410` | `Client_OnRefineryAddItemFailure` | refinery add inventory fail |
| `0x0080df40` | `Client_OnReverseEngineerFailure` | RE + inventory room |
| `0x0080e360` | `Client_OnRefineryRemoveItemFailure` | refinery remove fail |
| `0x00809c70` | `Client_OnInventoryModifyMissingObject` | not in inventory |
| `0x00809d20` | `Client_OnInventoryModifyMissingObjectAlt` | sibling not in inventory |
| `0x0093bac0` | `Client_PromptSkillTargetSelect` | Select a target for skill |
| `0x00824140` | `UI_SkillPanel_BindAvailableButtons` | skill_available.xml |
| `0x00825bf0` | `UI_QuickBar_CreateSlotButton` | quickbar.xml |
| `0x0081c4d0` | `Client_BuildInterfaceOptionsDialog` | Quickbar/Mission options |
| `0x0081e700` | `Client_WriteJoyCustomIni` | joy_custom + QuickBar* |
| `0x008066f0` | `Client_UpdateObjectiveDisplayHud` | Objective Display |
| `0x0090b9c0` | `Client_SetAnnouncementLabelTextures` | label_mission.dds |
| `0x00944770` | `Client_NotifyActiveMissionChanged` | changed active mission |
| `0x0080f7a0` | `Client_NotifyConvoyActiveMissionChanged` | convoy leader mission |
| `0x00954670` | `Client_DebugDumpMissionsAndObjectives` | Mission/Objective DEBUG |
| `0x009572e0` | `Client_DebugListMissionsStatus` | Still To Complete / Active |
| `0x00959230` | `Client_RegisterDebugSlashCommands` | debugmissions/castskill/quickbar |
| `0x0095ae10` | `Client_LoadGraphicsIniKeys` | SET_NEW_MISSION_ACTIVE / FULL_QUICKBAR_RED |
| `0x00955eb0` | `Client_DebugDumpEntityCombatStats` | SkillsInState DEBUG |
| `0x0044af00` | `Phy_CPConnection_AssertConnectionPoint` | palantir/physics/phyCPConnection.h |
| `0x0044b1f0` | `Gfx_SurfaceFormat_AssertUnknownFormat` | palantir/.../effSurfaceFormat.h |
| `0x00467690` | `Phy_BoundingVolumeFactory_InvalidTag` | phyBoundingVolumeFactory.h |
| `0x00467820` | `Phy_BoundingVolumeFactory_CreateFromTag` | phyBoundingVolumeFactory.h |
| `0x00951e70` | `Client_ShowDriverSitHumorMessages` | driver's seat humor |

## Plate-driven domain rename batch full address range (2026-07-23)

200 `FUN_*` clean units with PURPOSE/READABILITY string evidence, previously bare or
`Named_CalleeOf_*` only. Domain aliases written beside originals (not CalleeOf).
Full map: `docs/reconstruction/coverage/plate_domain_rename_full_range_report.txt`.

| Address | Canonical name | Evidence (short) |
|---------|----------------|------------------|
| `0x005092b0` | `CVOGLootGenerator_GetTypeFromIDPrefix` | Class::Method |
| `0x005c76f0` | `CLoadNode__initPhysics` | CLoadNode::_initPhysics |
| `0x00517ab0` | `CVOGClonedObjectBase_InitializeFromCBID` | Class::Method |
| `0x00520dc0` | `CVOGCharacter_CleanupDraggingObject` | Class::Method |
| `0x005cf560` | `CVOGHBAICreatureBase_DoCreaturePursue` | Class::Method |
| `0x005d5cc0` | `CVOGWaypoint_DoFollowObjectShortcutsUpdate` | Class::Method |
| `0x00586060` | `CVOGGraphicsBase_InitializeGraphics` | Class::Method |
| `0x004d0df0` | `Inv_GenerateLootItem` | GenerateLootItem (id) |
| `0x007c4920` | `Inv_tItemTemplate` | //tItemTemplate/row |
| `0x008be100` | `Inv_invmis` | i_d_invmis.xml |
| `0x005b10a0` | `Net_GhostObject_getUpdatePriority` | GhostObject::getUpdatePriority |
| `0x00502970` | `Phy_NDPhysicsDebug` | NDPhysicsDebug.fx |
| `0x00839ff0` | `Combat_target_bg_fill` | i_d_target_2d_wnd_bg_fill.xml |
| `0x008a5fe0` | `Mission_q_tab_convoy` | i_d_q_2d_wnd_tab_convoy.xml |
| `0x0088aac0` | `Skill_sc_btn_ai_distance_1` | i_d_sc_2d_btn_ai_distance_1.xml |

## Plate-driven domain rename batch [0x00600000, 0x00a00000) (2026-07-23)

100 `FUN_*` clean units with PURPOSE/READABILITY string evidence, previously bare or
`Named_CalleeOf_*` only. Domain aliases written beside originals (not CalleeOf).
Full map: `docs/reconstruction/coverage/plate_domain_rename_6m_a0_report.txt`.

| Address | Canonical name | Evidence (short) |
|---------|----------------|------------------|
| `0x00642b70` | `CVOGTriggerPhantomListener_collidableAddedCallback` | Class::Method |
| `0x009463b0` | `Phy_Start_ReinitPhysics` | start reinitPhysics |
| `0x0067c330` | `Net_Nazgul_Session` | nazgul/net/netSession.cpp |
| `0x00682850` | `Net_Nazgul_TcpConnection` | nazgul/net/netTcpConnection |
| `0x00805900` | `LCD_CLCDGfx_Initialize` | CLCDGfx::Initialize |
| `0x0099b8e0` | `CNDAssetStringTable_Serialize` | CNDAssetStringTable::Serialize |
| `0x00932060` | `Phy_Inside_InitPhysics` | @@inside InitPhysics |
| `0x007217c0` | `Snd_PlayBackgroundMusic_CreateStreaming` | PlayBackgroundMusic::CreateStreamingMusic |
| `0x007ce130` | `Inv_tLootRarity` | //tLootRarity/row |
| `0x007cc0d0` | `Mission_tQuestXPLookup` | //tQuestXPLookup/row |
| `0x007c6110` | `Drive_tVehicleTemplate` | //tVehicleTemplate/row |
| `0x007e7fd0` | `Drive_dcWheelSet_Insert_Open` | dcWheelSet_Insert::Open |
| `0x0080fe10` | `Inv_ConvoyLootMode_KillerTakes` | Convoy Loot Mode switched… |
| `0x0060a230` | `Net_PackInitialCharacterUpdate` | Packing initial update for character |
| `0x0060a820` | `Net_UnpackGhostUpdate` | unpacking update from net … ghost |
| `0x0093e7e0` | `Combat_DeathRespawnButton` | i_g_2d_btn_death_respawn.xml |

## Plate-driven domain rename batch under 0x00500000 (2026-07-23)

50 `FUN_*` clean units with PURPOSE/READABILITY string evidence, previously bare or
`Named_CalleeOf_*` only. Domain aliases written beside originals (not CalleeOf).
Full map: `docs/reconstruction/coverage/plate_domain_rename_under_500k_report.txt`.

| Address | Canonical name | Evidence (short) |
|---------|----------------|------------------|
| `0x004d18a0` | `CVOGSectorMap_PostPhysX` | `CVOGSectorMap::PostPhysX` |
| `0x004b50f0` | `CPhysXBase_RenderResults` | `CPhysXBase::RenderResults` |
| `0x004cd670` | `CVOGSectorMap_InitGenerators` | `CVOGSectorMap::InitGenerators` |
| `0x004b52e0` | `Phy_PhysX_Path` | `..\physics\physx\` |
| `0x0046e2a0` | `Net_Nazgul_NetInclude` | nazgul/net include path |
| `0x0046e410` | `Net_Nazgul_MsgInclude` | nazgul/msg include path |
| `0x004b5220` | `CPhysXBase_Step` | `CPhysXBase::Step` |
| `0x004eb560` | `Phy_PhysX_RigidBodyZeroLength` | PhysX rigid body zero length |
| `0x004d3980` | `CVOGSectorMap_StepTriggers` | `CVOGSectorMap::StepTriggers` |
| `0x004d4da0` | `CVOGSectorMap_StepCreatures` | `CVOGSectorMap::StepCreatures` |
| `0x00495600` | `CVOGEnvironmentSector_ProcessPreloads` | `CVOGEnvironmentSector::ProcessPreloads` |
| `0x004449b0` | `Sto_AbstractUnserializationFactory` | stoAbstractUnserializationFactory.h |
| `0x00444a40` | `Sto_AbstractUnserializationFactory_00444a40` | same header (sibling) |
| `0x004b5660` | `Phy_PhysX_InstancingDisabled` | Instancing not supported, Disabling PhysX |
| `0x004ec7b0` | `Phy_CollectAllPhysicsPreloads` | `CollectAllPhysicsPreloads` |
| `0x0048edc0` | `VOGEnvironmentSector` | VOGEnvironmentSector.cpp |
| `0x004c7490` | `CVOGCreature_UpdateGraphics` | `CVOGCreature::UpdateGraphics` |
| `0x004d6c80` | `CVOGSectorMap_StepTo` | `CVOGSectorMap::StepTo` |
| `0x004dcb80` | `CVOGSectorMap_SaveToFile` | `CVOGSectorMap::SaveToFile` |
| `0x00435410` | `Gfx_Png_InitInfoFailed` | Failed to initialize PNG info |
| `0x0048f660` | `Gfx_RenderParticles` | render Particles |
| `0x00497d60` | `CVOGFlairGenerator` | `CVOGFlairGenerator` |
| `0x004f1c70` | `Phy_Preload_ReloadRigidBody` | `Preload::ReloadRigidBody` |
| `0x004aac50` | `Gfx_NDDiffTerrainLayered` | NDDiffTerrainLayered.fx |
| `0x004323e0` | `CxImage_Create` | `CxImage::Create` |
| `0x0047ad80` | `Gfx_Gamma` | gamma = (%d/100000) |
| `0x0047b510` | `Gfx_IncorrectGamma` | incorrect gamma |
| `0x0049a240` | `Gfx_Particles` | Particles.dds |
| `0x004c0a90` | `Gfx_NDParticleFluidBlendNormal` | NDParticleFluidBlendNormal.fx |
| `0x004c1a10` | `Gfx_NDParticleFluidBlendNormal_004c1a10` | same FX (sibling) |
| `0x004c1cb0` | `Gfx_NDParticleFluid` | NDParticleFluid.fx |
| `0x00476e70` | `Gfx_Libpng_Error` | libpng error |
| `0x004deb20` | `Gfx_NumGfxDebug` | NumGfx:%d |
| `0x004ebf50` | `Snd_CollectAllSoundPreloads` | CollectAllSoundPreloads |
| `0x004ec430` | `Anim_CollectAllAnimationPreloads` | CollectAllAnimationPreloads |
| `0x00433dc0` | `Gfx_Bmp_ReadInfoError` | Error reading BMP info |
| `0x00497bf0` | `CVOGFlairObject` | CVOGFlairObject |
| `0x004bfe10` | `CLoadQueue_Update` | CLoadQueue::update |
| `0x004ec8b0` | `Phy_RigidBodyTooManyVertices` | too many vertices |
| `0x004f1530` | `Phy_RigidBodyZeroLength` | rigid body zero length |
| `0x00419ad0` | `Util_HashListError_Repair` | HashListError repair |
| `0x00429310` | `Util_HashListError_Repair_00429310` | HashListError repair |
| `0x00475070` | `Gfx_Libpng_VersionCheck` | png.h libpng version |
| `0x00476fa0` | `Gfx_Libpng_Warning` | libpng warning |
| `0x0048a550` | `Gfx_EffectProc` | EffectProc - ENTER |
| `0x0048a780` | `Gfx_SetEffect` | SetEffect path/capability |
| `0x004ceba0` | `Skill_NonCreatureCastAutoHit` | Non-Creature cast (AutoHit) |
| `0x004e2360` | `Util_HashListError_Repair_004e2360` | HashListError repair |
| `0x0047f7d0` | `Zlib_InvalidLiteralLengthCode` | invalid literal/length code |
| `0x00498380` | `Named_CouldNotFindFlair` | Could not find flair %d |

## 2026-07-29 Collect_Action / Deliver / Interact objective id

| Canonical name | Kind | Stable ID / address | Notes |
|----------------|------|---------------------|-------|
| `CVOGObjectiveRequirement_Collect_Action` | function | `aa_00611f20` / `0x00611f20` | kill-loot + inventory event; CountItemsByCbid |
| `CVOGObjectiveRequirement_Deliver_OnInventoryEvent_Inferred` | function | `aa_00611290` / `0x00611290` | type-4 event; progress 1.0; name Inferred |
| `CVOGObjectiveRequirement_Deliver_CargoReady_Inferred` | function | `aa_00610f20` / `0x00610f20` | pure cargo ready; name Inferred |
| `CVOGCharacter_FindActiveObjectiveIdForInteract` | function | `aa_00524520` / `0x00524520` | returns objective id not bool |
| `CVOGCharacter_FindActiveObjectiveIdForPick` | function | `aa_005245d0` / `0x005245d0` | sibling walk; vtbl+0x44 via MatchTargetEvaluators_Slot44 |
| `CVOGObjective_MatchTargetEvaluators` | function | `aa_0059d9c0` / `0x0059d9c0` | vtbl+0x40 over +0x158..+0x15c |
| `CVOGObjective_MatchTargetEvaluators_Slot44` | function | `aa_0059da10` / `0x0059da10` | same loop as sibling; vtbl+0x44; sole caller FUN_005245d0 |

## 2026-07-29 skill FUN residual renames (evidence-only)

| Canonical name | VA | Evidence |
|----------------|-----|----------|
| `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` | `0x004f8b80` | sole caller ResolveCastTarget; returns TFID@+0x160; dual quality |
| `Skill_FilterTargetForResolveList_Inferred` | `0x0054ff00` | sole caller ResolveTargetList; outFlags **4/8/0x10** writers sealed; dual quality |
| `Skill_ApplyEffectsOnTarget_Inferred` | `0x005538a0` | 5 skill-cast callers; combat events 4/0xc/0xe/5/6; handler +0x5f0 vtbl+0x2c; dual quality |
| `Skill_AccuracyHitCheck_Inferred` | `0x00553240` | skill thiscall; 2 xrefs; sentinel -1.0; threshold (roll%100)*0.01; dual A/B |
| `Skill_AccuracyScore_Inferred` | `0x005531d0` | skill thiscall RET 0xC; float ST0; bonus via 004c4140; pack → 004ceba0; dual A/B |
| `CNDDoubleList_InvokePredicateAndRemove_Inferred` | `0x004e2600` | CS list + RTTI family `CNDDoubleList@PAVCVOGHBBase`; ValidateTarget consumer; dual quality |
| `CVOGHBSkillBase_ctor` | `0x005788d0` | **RTTI Confirmed** `".?AVCVOGHBSkillBase@@"` (COL `0x00aaede0` → type_info `0x00af8cec` on vtbl `PTR_FUN_009d3fdc`); ValidateTarget notify=1; dual quality. **Supersedes** mistaken scaffold `CVOGHBSkillCast_ctor_Inferred` |

## 2026-07-29 W19-P dual A/B renames (evidence-only)

| Canonical name | VA | Evidence |
|----------------|-----|----------|
| `CVOGHBAIBase_SetFloat0x2c` | `0x0063a700` | leaf `movss` store `this+0x2c`; Turreted/Default ctor `push 0`; vtbl[+0x20]; dual A/B W19-P |
| `DES_BuildSBoxLookupTables` | `0x0071bdd0` | expands FIPS S1..S8 (`DAT_00afcb48`) → four 0x1000 banks `d12e90..d15e90`; sole caller `DES_InitializeCipher`; dual A/B W19-P |

## 2026-08-04 WQ-007 residual dual renames (evidence-only)

Append-only batch for residual undualed callees of MissionDialog / journal / GiveMission / CompleteObjective paths. `_Inferred` = retail symbol not recovered; RTTI-backed names omit suffix.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `Client_MaybeShowMultiActiveMissionTip_Inferred` | function | `aa_008ac7a0` / `0x008ac7a0` | `FUN_008ac7a0` | missions-progression | `client::mission` | Sole caller HandleButton; hash `+0x540` walk; tip `0x20` if count≥2; dual A/B + ADV PASS | High (CF) | none | Not dialog list refresh |
| `Client_MissionDialog_SetHeaderCaption_Inferred` | function | `aa_008aaf60` / `0x008aaf60` | `FUN_008aaf60` | missions-progression | `client::mission` | Widget `+0x6e0`; vtbl+0x1d8 arity (0,1,1); dual A/B + ADV PASS | High (CF) | none | Clear vs set caption |
| `UI_MissionDialog_BuildResponseButtons_Inferred` | function | `aa_008ac110` / `0x008ac110` | `FUN_008ac110` | missions-progression | `client::mission` | `i_d_npc_2d_btn_response.xml`; ids `0x9C46+i`; dual A/B | High (role) | none | Response strip rebuild |
| `UI_MissionPanel_SyncListScrollbar_Inferred` | function | `aa_008aa610` / `0x008aa610` | `FUN_008aa610` | missions-progression | `client::mission` | Sole caller SetHeaderCaption tail; pages formula; dual A/B | High (role) | none | List scrollbar sync |
| `MissionDialog_ParseMarkupToRichText_Inferred` | function | `aa_008aab00` / `0x008aab00` | `FUN_008aab00` | missions-progression | `client::mission` | Tag/color matrix sealed; dual A/B + ADV PASS | High (CF) | none | `[$imp/npc/inst/loc/emote/pause/key]` |
| `MissionDialog_ClearResponseButtonSlots_Inferred` | function | `aa_008aa560` / `0x008aa560` | `FUN_008aa560` | missions-progression | `client::mission` | 8× TFID `+0x518`; destroy `+0x708`; dual A/B + ADV PASS | High (CF) | none | Pre-rebuild wipe |
| `Mission_ExpandPlayerTokenPlaceholders_Inferred` | function | `aa_005465c0` / `0x005465c0` | `FUN_005465c0` | missions-progression | `client::mission` | Five tokens name/class/race/credits/level; dual A/B + ADV PASS | High (CF) | none | No wallet write |
| `Character_GetRaceDisplayName_Inferred` | function | `aa_00521800` / `0x00521800` | `FUN_00521800` | missions-progression | `client::mission` | Human/Mutant/Biomek strings; `[$race]` parent; dual A/B | High (role) | none | Ephemeral ring string |
| `Character_GetClassDisplayName_Inferred` | function | `aa_00521900` / `0x00521900` | `FUN_00521900` | missions-progression | `client::mission` | Thin wrapper → `FUN_0051f940`; `[$class]`; dual A/B | High (role) | none | Ephemeral ring string |
| `UI_MissionJournal_MSelectEntry_Ctor_Inferred` | function | `aa_00829ec0` / `0x00829ec0` | `FUN_00829ec0` | missions-progression | `client::mission` | `new(0x510)`; skin `i_d_npc_2d_btn_mselect.xml`; dual A/B | High (role) | none | Journal mselect entry |
| `StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred` | function | `aa_00411180` / `0x00411180` | `FUN_00411180` | missions-progression | `client::util` | EAX=vec ESI=val; journal ×3 of 9 callers; dual A/B + ADV PASS | High (CF) | none | Generic; multi-domain |
| `StdVector_InsertOne_RebindIt_Via419880_Inferred` | function | `aa_0040b6d0` / `0x0040b6d0` | `FUN_0040b6d0` | missions-progression | `client::util` | Sole caller push_back slow path; dual A/B | High (CF) | none | Grow insert-one |
| `Input_KeyCodeToDisplayName` | function | `aa_007f5120` / `0x007f5120` | `FUN_007f5120` | missions-progression | `client::input` | DIK/mouse/joy tables; `[$key]` consumer; dual A/B | High (CF) | none | Multi-domain display |
| `ActionMap_FormatSlotBindDisplay` | function | `aa_007f9160` / `0x007f9160` | `FUN_007f9160` | missions-progression | `client::input` | MOD+KEY; calls KeyCodeToDisplayName; dual A/B | High (CF) | none | Bind format for markup |
| `CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress` | function | `aa_0060d630` / `0x0060d630` | `FUN_0060d630` | missions-progression | `client::mission` | RTTI UseItem; slot+=1; optional GiveMission; dual A/B | High | none | Client optimistic progress |
| `CVOGHBMissionEscort_OnHeartBeat` | function | `aa_006508d0` / `0x006508d0` | `FUN_006508d0` | missions-progression | `client::mission` | RTTI `.?AVCVOGHBMissionEscort@@`; CompleteObjective/FailMission; dual A/B | High | none | Not Outpost HB |

### Rename history (2026-08-04 WQ-007 residual)

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-08-04 | aa_008ac7a0 | `FUN_008ac7a0` / scaffold Named_VOG_DEBUG_STOP | `Client_MaybeShowMultiActiveMissionTip_Inferred` | CF + sole HandleButton caller; assert string is lock noise |
| 2026-08-04 | aa_008aaf60 | `FUN_008aaf60` | `Client_MissionDialog_SetHeaderCaption_Inferred` | Caption apply CF sealed |
| 2026-08-04 | aa_008ac110 | `FUN_008ac110` | `UI_MissionDialog_BuildResponseButtons_Inferred` | Response XML plate |
| 2026-08-04 | aa_008aa610 | `FUN_008aa610` | `UI_MissionPanel_SyncListScrollbar_Inferred` | Scrollbar math + sole caption tail caller |
| 2026-08-04 | aa_008aab00 | `FUN_008aab00` | `MissionDialog_ParseMarkupToRichText_Inferred` | Tag/color matrix sealed |
| 2026-08-04 | aa_008aa560 | `FUN_008aa560` | `MissionDialog_ClearResponseButtonSlots_Inferred` | 8-slot wipe before rebuild |
| 2026-08-04 | aa_005465c0 | `FUN_005465c0` | `Mission_ExpandPlayerTokenPlaceholders_Inferred` | Five fixed tokens sealed |
| 2026-08-04 | aa_00521800 | `FUN_00521800` | `Character_GetRaceDisplayName_Inferred` | Race string table |
| 2026-08-04 | aa_00521900 | `FUN_00521900` | `Character_GetClassDisplayName_Inferred` | Class display wrapper |
| 2026-08-04 | aa_00829ec0 | `FUN_00829ec0` | `UI_MissionJournal_MSelectEntry_Ctor_Inferred` | mselect skin plate |
| 2026-08-04 | aa_00411180 | `FUN_00411180` | `StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred` | EAX/ESI push_back ABI |
| 2026-08-04 | aa_0040b6d0 | `FUN_0040b6d0` | `StdVector_InsertOne_RebindIt_Via419880_Inferred` | Insert-one rebind |
| 2026-08-04 | aa_007f5120 | `FUN_007f5120` | `Input_KeyCodeToDisplayName` | Key name tables |
| 2026-08-04 | aa_007f9160 | `FUN_007f9160` | `ActionMap_FormatSlotBindDisplay` | MOD+KEY format |
| 2026-08-04 | aa_0060d630 | `FUN_0060d630` | `CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress` | RTTI UseItem + GiveMission residual |
| 2026-08-04 | aa_006508d0 | `FUN_006508d0` | `CVOGHBMissionEscort_OnHeartBeat` | RTTI Escort OnHeartBeat |
