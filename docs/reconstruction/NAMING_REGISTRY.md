# Naming Registry

Canonical names only. Do not invent original studio names without evidence.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `VehicleEntity_SetSteerInput` | function | `aa_004f5620` / `0x004f5620` | `VehicleEntity_SetSteerInput` (Ghidra symbol) | input-drive-control | `client::vehicle` | Fresh decompile; prior `physics/verified/fn_004f5620_setSteerInput.md`; callers include DriveControlTick | High | none | Writes `entity+0x618` under 0xC7 gate |
| `VehicleEntity_SetLongitudinalInput` | function | `aa_004f5650` / `0x004f5650` | `VehicleEntity_SetLongitudinalInput` | input-drive-control | `client::vehicle` | Sibling decompile; same gate â†’ `+0x614` | High | none | Not fully reconstructed this pass |
| `VehicleEntity_SetHandbrake` | function | `aa_004f3620` / `0x004f3620` | `VehicleEntity_SetHandbrake` | input-drive-control | `client::vehicle` | Decompile + dual residual 2026-07-29: unguarded store `+0x61c` | High | none | No 0xC7 gate; MoveToTarget bypasses setter |
| `Client_Input_DriveControlTick` | function | `aa_009223b0` / `0x009223b0` | `Client_Input_DriveControlTick` | input-drive-control | `client::input` | Decompile + plate comments; primary entry for held drive flags | High | DriveControlTick | Large; map only this pass |
| `VehicleEntity_PushDriveAxesToController` | function | `aa_004fbc10` / `0x004fbc10` | `VehicleEntity_PushDriveAxesToController` / prior `FUN_004fbc10` | input-drive-control | `client::vehicle` | Callee of DriveControlTick; physics notes | Probable | FUN_004fbc10 | Downstream of axis writes |
| `steerInput` | field | entity `+0x618` | `*(float*)(this+0x618)` | input-drive-control | `VehicleEntity` | Store site in SetSteerInput | High | entity+0x618 | f32 axis typically [-1,+1] |
| `longitudinalInput` | field | entity `+0x614` | `*(float*)(this+0x614)` | input-drive-control | `VehicleEntity` | Store site in SetLongitudinalInput | High | entity+0x614 | f32 |
| `handbrakeFlag` | field | entity `+0x61c` | `*(uint8*)(this+0x61c)` | input-drive-control | `VehicleEntity` | SetHandbrake store | High | entity+0x61c | u8 / bool-like |
| `driveAxisGateObject` | field/object | via `*(*( *(this+4)+4 ) + this + 0xb0)` | decompiler `iVar1` | input-drive-control | unknown | Gate chain in both setters | Probable | wobj; was driveAxisLockObject | Exact type unresolved; "lock" unproven |
| `driveAxisSuppressFlags` | field | gateobj `+0xb4` | `*(byte*)(iVar1+0xb4)` | input-drive-control | unknown | Masked with `0xC7` | Probable (as suppress bits) | driveAxisLockFlags | Per-bit meaning unknown; avoid "lock" seal |
| `INPUT_AXIS_SUPPRESS_MASK` | constant | `0xC7` / 199 | decompiler `199` | input-drive-control | â€” | Both setters | Confirmed (value) | INPUT_AXIS_LOCK_MASK, 199 | Bits 0x01\|0x02\|0x04\|0x40\|0x80 |

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
| `CVOGCharacter_SearchAutoMissions` | function | `aa_00532b60` / `0x00532b60` | `CVOGCharacter_SearchAutoMissions` | missions-progression | `client::mission` | Raw; iterates auto defs â†’ Requirements â†’ Give | High | none | `this[0x150]` = byte `+0x540` |
| `CVOGReaction_CompleteObjective` | function | `aa_00533f90` / `0x00533f90` | `CVOGReaction_CompleteObjective` | missions-progression | `client::mission` | Raw + dual review; advance/final; XP/credits final | High | none | force=1 from 0x2070 |
| `CVOGCharacter_EvaluatePendingObjectives` | function | `aa_00534920` / `0x00534920` | `CVOGCharacter_EvaluatePendingObjectives` | missions-progression | `client::mission` | Dual residual sealed 2026-07-29; pending `+0x55c` **slot** (`def=*slot`); CompleteCount `FUN_0059d880`=`*(def+0x164)`; twin of CompleteObjective force=0; 7 callers | High | none | Vtable `+4/+8/+0x20`; collect `(count!=0 && count<=succ)\|\|allTrue` + `def+0x138==0` |
| `Mission_ComputeObjectiveXp` | function | `aa_0059dde0` / `0x0059dde0` | `Mission_ComputeObjectiveXp` | missions-progression | `client::mission` | Raw + dual residual seal 2026-07-29; pure XP calc; map node High | High | table payloads / runtime | Bias is caller-side; presentation xrefs too |
| `Mission_ComputeObjectiveCredits` | function | `aa_0059df20` / `0x0059df20` | `Mission_ComputeObjectiveCredits` | missions-progression | `client::mission` | Dual residual 2026-07-29; ceil+FISTP chop | High | none | Adds at char+0x720 by caller |
| `CVOGCharacter_CompleteMissionObjectives` | function | `aa_00536080` / `0x00536080` | `CVOGCharacter_CompleteMissionObjectives` | missions-progression | `client::mission` | Raw; def `+0x130` count, `+0x13c` array | High | none | `__cdecl`; reason forwarded |
| `CVOGCharacter_CheckMissionPrerequisites` | function | `aa_00536540` / `0x00536540` | `CVOGCharacter_CheckMissionPrerequisites` | missions-progression | `client::mission` | Dual residual edges 2026-07-29: mutator; call matrix (1,1)/(1,0)/(0,0); +0x124 RequirementsNegative | High | none | Not pure predicate; â‰  Requirements |
| `Client_RecvObjectiveState` | function | `aa_00809460` / `0x00809460` | `Client_RecvObjectiveState` | missions-progression | `client::mission` | Raw + dual residual 2026-07-29; S2C `0x2071` progress slots | High | none | Does not CompleteObjective; slots IEEE float |
| `Client_RefreshMissionRelatedUi` | function | `aa_0092ce90` / `0x0092ce90` | `FUN_0092ce90` | missions-progression | `client::mission` | Decompile; RecvObjectiveState / inventory callers; dual residual 2026-07-29 | High (role) | original unknown | Refreshes `client+0x107c` / `+0x10b8`; not EvaluatePending |
| `missionUiRoot` | field | client `+0x107c` | `*(ptr*)(client+0x107c)` | missions-progression | client controller | HideMissionDialogIfOpen; RecvObjectiveState; FUN_0092ce90 | High (role) | none | Mission dialog / mission UI root |
| `Client_RecvCompleteDynamicObjective` | function | `aa_0080ff00` / `0x0080ff00` | `Client_RecvCompleteDynamicObjective` | missions-progression | `client::mission` | Raw; S2C `0x2070` force CompleteObjective | High | was misnamed RecvObjectiveState | Always force=1 |
| `Client_RecvNpcMissionDialog` | function | `aa_00815070` / `0x00815070` | `Client_RecvNpcMissionDialog` | missions-progression | `client::mission` | Raw; S2C `0x206D`; stride 40 entries | High | none | Ends in ShowNpcMissionDialogUI |
| `Client_UpdateMissionJournal` | function | `aa_008ae130` / `0x008ae130` | `Client_UpdateMissionJournal` | missions-progression | `client::mission` | Raw; state `+0x648==3`; Active/New via hash `+0x540`+`[node+0x8]`; residual dual 2026-07-29 | High | none | UI rebuild; EBX-heavy; FailMissionNotify=push |
| `Client_MissionDialogHandleButton` | function | `aa_008ae7c0` / `0x008ae7c0` | `Client_MissionDialogHandleButton` | missions-progression | `client::mission` | Raw; state 0â€“3; C2S `0x206F`; fills 0x206E body | High | none | Accept / claim / abandon / re-show |
| `Client_MissionDialog_FlushPreparedResponse` | function | `aa_008ab8f0` / `0x008ab8f0` | `FUN_008ab8f0` | missions-progression | `client::mission` | Asm send `+0x650` size `0x20`; vtbl `0x00a4a95c` | High | original name unknown | **C2S 0x206E send site** |
| `Client_UiModalDispatch` | function | `aa_00911840` / `0x00911840` | `FUN_00911840` | missions-progression | `client::ui` | Abandon cases `0x4e46`/`0x4e47` | High (slice) | full switch open | Confirm â†’ C2S `0x20B2` |
| `Client_RecvFailMission` | function | `aa_0080b100` / `0x0080b100` | `FUN_0080b100` | missions-progression | `client::mission` | PacketDispatch `0x20b2` sole xref `0x00815d97`; UF-012 framing dual residual; FailMission thiscall; packet `+0x10`; return ignored; end-quest always | High | original symbol unknown | S2C apply after fail; EAX=packet ECX=client |
| `pendingAbandonMissionId` | global | `DAT_00d1b4b4` | `DAT_00d1b4b4` | missions-progression | â€” | HandleButton state 2 WRITE; modal READ | High | none | Stash for abandon confirm |
| `OPCODE_C2S_FAIL_MISSION` | constant | `0x20B2` | case `0x4e46` packet | missions-progression | â€” | Asm + decompile size `0x18` | High | 0x20B2 | Abandon confirm C2S |
| `InventoryGrid_CountItemsByCbid` | function | `aa_005711c0` / `0x005711c0` | `FUN_005711c0` | inventory-transfer | `client::inventory` | Collect_Eval/SlotAction + decompile; dual residual 2026-07-29 | High | original unknown | Sum qty by CBID; exclude Broken unless includeBroken |
| `ItemFlag_Broken` | field/flag | `item+0x17c` bit 19 / mask `0x80000` | `object[0x5f]>>0x13` | inventory-transfer | `client::inventory` | `"Broken: "` loot+UI; `i_g_2d_overlay_broken.dds`; setter `0x00513de0` | High | original unknown | Broken item state |
| `Item_SetBroken` | function | `aa_00513de0` / `0x00513de0` | `FUN_00513de0` | inventory-transfer | `client::inventory` | Dual A/B 2026-07-29; bytes seal mask `0x80000`; dirty `FUN_00512670`; vtbl+0x90 if set | High (mask/CF) | original unknown | Set/clear ItemFlag_Broken |
| `Item_IsStackEligible` | function | `aa_00513e70` / `0x00513e70` | `FUN_00513e70` | inventory-transfer | `client::inventory` | Dual A/B 2026-07-29; bytes seal `type4\|\|(blob+0x3f2&0x40&&!Broken)` | High (role) | original unknown | Stack-merge/display eligibility; **not** capacity (`0x0040abf0`) |
| `Item_CanAcceptStackQty` | function | `aa_0040abf0` / `0x0040abf0` | `FUN_0040abf0` | inventory-transfer | `client::inventory` | Dual A/B 2026-07-29; bytes seal `(qty+add)<=(max&0xFFFF)`; type4 999999â†’16959; def+0x4BA /0â†’200 | High (role/CF) | original unknown | Stack capacity fit; **not** eligibility (`0x00513e70`) |
| `List_TraversalLock` | function | `aa_004294f0` / `0x004294f0` | `FUN_004294f0` | inventory-transfer | `client::list` | string `List Error! TraversalLock Call Stack` | High (role) | original unknown | Enter list CS for traversal |
| `List_IterateNext` | function | `aa_004022a0` / `0x004022a0` | `FUN_004022a0` | inventory-transfer | `client::list` | list node walk under TraversalLock | High (role) | original unknown | Next object under locked list |
| `CVOGObjectiveRequirement_Collect_Eval` | function | `aa_00611940` / `0x00611940` | `FUN_00611940` | missions-progression | `client::mission` | Count/NumToCollect; cargo path; vtable+0x10; RET8 ABI; dual residual 2026-07-29 | High | original unknown | Progress 0..1 |
| `CVOGObjectiveRequirement_Collect_SlotAction` | function | `aa_006124b0` / `0x006124b0` | `FUN_006124b0` | missions-progression | `client::mission` | vtable+0x18; `"%s: %d / %d"` + CountItemsByCbid | High (role) | original unknown | Live cargo UI text |
| `CVOGObjectiveRequirement_Collect_ctor` | function | `aa_00611690` / `0x00611690` | `FUN_00611690` | missions-progression | `client::mission` | type code 2; vtable `PTR_FUN_009e12c4`; dual A/B seal 2026-07-29 | High | original unknown | Collect ctor |
| `CVOGObjectiveRequirement_Collect_DeserializeXml` | function | `aa_00611a00` / `0x00611a00` | `FUN_00611a00` | missions-progression | `client::mission` | strings CBID/NumToCollect/collect error | High | original unknown | GLM field load |
| `CVOGObjectiveRequirement_Collect` | type | RTTI `0x00afe9ac` / vtable `0x009e12c4` | `.?AVCVOGObjectiveRequirement_Collect@@` | missions-progression | â€” | RTTI string + ctor | High | none | Collect requirement class |
| `collectReqItemCbid` | field | req `+0x10` | XML `CBID` | missions-progression | Collect req | SerializeXml + Eval | High | none | Item to count |
| `collectReqNumToCollect` | field | req `+0x14` | XML `NumToCollect` | missions-progression | Collect req | SerializeXml + Eval | High | none | Target stack count |
| `Client_SendUseObject` | function | `aa_00916740` / `0x00916740` | `Client_SendUseObject` | interaction-activation | `client::interact` | Fresh decompile + dual A/B 2026-07-29; C2S `0x2072` size `0x20` | High | none | TFID + objective (âˆ’1 none); stash `client+0xd28` |
| `Client_SendUseObject_IfInteractable` | function | `aa_00930d70` / `0x00930d70` | `Client_SendUseObject_IfInteractable` | interaction-activation | `client::interact` | Fresh decompile + dual A/B 2026-07-29 | High | none | Gated send; objective id or 0 (type-4) |
| `Client_InteractClickPickTarget` | function | `aa_009247b0` / `0x009247b0` | `Client_InteractClickPickTarget` | interaction-activation | `client::interact` | Human refine + dual A/B 2026-07-29; pick â†’ UseObject | High (role + gate) | none | Dist gate `DAT_00aaa6fc`=25f; type4â†’`0x205D` |
| `Client_UpdateNpcInteractIcons` | function | `aa_0091b8d0` / `0x0091b8d0` | `Client_UpdateNpcInteractIcons` | interaction-activation | `client::interact` | Plate dual; chrome only | High (role) | none | No `0x2072` send |
| `CVOGCharacter_FindActiveObjectiveIdForInteract` | function | `aa_00524520` / `0x00524520` | `FUN_00524520` | interaction-activation | `client::mission` | Decompile: hash `+0x548` â†’ id `@+0x10` | Probable | FUN_00524520; was Named_VOG_DEBUG_STOP | Gate + id for IfInteractable |
| `CVOGCharacter_FindActiveObjectiveIdForPick` | function | `aa_005245d0` / `0x005245d0` | `FUN_005245d0` | interaction-activation | `client::mission` | Clone walk; `CVOGObjective_MatchTargetEvaluators_Slot44` eval **+0x44**; dual A/B 2026-07-29 | Probable | FUN_005245d0; scaffold InteractAlt | Pick/hover id; sibling of ForInteract |
| `OPCODE_C2S_USE_OBJECT` | constant | `0x2072` | SendUseObject packet literal | interaction-activation | â€” | Both send paths | High | 0x2072 | UseObject C2S |
| `CLIENT_USEOBJECT_RANGE` | constant | `DAT_00aaa6fc` = `25.0f` (`0x41c80000`) | float at `0x00aaa6fc` | interaction-activation | â€” | Ghidra `read_memory` 2026-07-29 | High | DAT_00aaa6fc | Click path gate before SendUseObject |
| `lastUseObjectTarget` | field | client `+0xd28` | `*(ptr*)(client+0xd28)` | interaction-activation | client controller | SendUseObject store | High | none | Last-use stash |
| `objectTfId` | field | object `+0x160` | TFID_16 block | interaction-activation | world object | Both send paths pack 16 B | High | none | Wire target |
| `objectInteractFlag` | field | object `+0x11c` | `*(int*)(obj+0x11c)` | interaction-activation | world object | Pick/poll prefer SendUseObject | Probable | none | Non-zero â†’ unconditional path |
| `charCompletedMissionsHash` | field | char `+0x538` | `*(void**)(this+0x538)` | missions-progression | `CVOGCharacter` | HasCompletedMission / GiveMission / SearchAuto | High | permanent completed | CNDHash* |
| `charInstanceCompletedMissionsHash` | field | char `+0x53c` | `*(void**)(this+0x53c)` | missions-progression | `CVOGCharacter` | HasCompletedMission instance path | High | instance completed | CNDHash* |
| `charActiveMissionsHash` | field | char `+0x540` | `*(void**)(this+0x540)` | missions-progression | `CVOGCharacter` | Fail/Give/Search/Prereq | High | active missions | CNDHash* |
| `charActiveObjectivesHash` | field | char `+0x548` | AddActiveObjective asm `MOV ECX,[this+0x548]` â†’ `FUN_0053c460` | missions-progression | `CVOGCharacter` | Def insert this for active objectives | High | active objectives | Dual-tighten aa_00531b00 |
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
| `OPCODE_S2C_NPC_MISSION_DIALOG` | constant | `0x206D` | plate / RecvNpcMissionDialog | missions-progression | â€” | Raw plate | High | 0x206D | Open dialog |
| `OPCODE_C2S_MISSION_DIALOG_RESPONSE` | constant | `0x206E` | Prepare `+0x650` + Flush size `0x20` | missions-progression | â€” | Prepare imm + Flush send sealed 2026-07-29 | High | 0x206E | HandleButton fills body only |
| `OPCODE_C2S_MISSION_ACCEPT_REQUEST` | constant | `0x206F` | HandleButton state 0 packet | missions-progression | â€” | Raw `auStack = 0x206f` | High | 0x206F | Sector send size 0x18 |
| `OPCODE_S2C_COMPLETE_DYNAMIC_OBJECTIVE` | constant | `0x2070` | RecvCompleteDynamicObjective plate | missions-progression | â€” | Raw plate | High | 0x2070 | Force complete |
| `OPCODE_S2C_OBJECTIVE_STATE` | constant | `0x2071` | RecvObjectiveState plate | missions-progression | â€” | Raw plate | High | 0x2071 | Progress-only |
| `OPCODE_C2S_FAIL_MISSION` | constant | `0x20B2` | UiModalDispatch case `0x4e46` packet literal | missions-progression | â€” | C2S abandon send size `0x18`; S2C same opcode â†’ RecvFailMission | High | `OPCODE_S2C_FAIL_MISSION`, FailMission, 0x20B2 | Bidirectional; wire: pad4 + COID i64 + MissionId i32 + pad4 |
| `pendingAbandonMissionId` | global | `DAT_00d1b4b4` | `DAT_00d1b4b4` | missions-progression | â€” | HandleButton state 2 store; UiModalDispatch lookup key | High | DAT_00d1b4b4 | `0xFFFFFFFF` = no pending abandon |
| `Client_UiModalDispatch` | function | `aa_00911840` / `0x00911840` | `FUN_00911840` | missions-progression | `client::ui` | Abandon cases `0x4e46`/`0x4e47`; C2S `0x20B2` | High | FUN_00911840 | Large modal switch; abandon slice reconstructed |
| `Client_RecvFailMission` | function | `aa_0080b100` / `0x0080b100` | `FUN_0080b100` | missions-progression | `client::mission` | PacketDispatch `0x20b2` â†’ FailMission; UF-012 framing dual residual sealed | High | Client_OnFailMissionPacket, FUN_0080b100 | MissionId @ packet+0x10; char @ game+0xe98; end-quest always |
| `dialogUiState` | field | dialog host `+0x648` | `*(int*)(host+0x648)` | missions-progression | mission dialog UI | HandleButton / UpdateJournal | High | state 0â€“3 | 3 = journal view |
| `dialogTurnInMode` | field | dialog host `+0x64c` | `*(char*)(host+0x64c)` | missions-progression | mission dialog UI | HandleButton claim path | High | none | Non-zero = complete/deliver |

### Abandon â†’ FailMission chain notes (2026-07-29)

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

**Rename note:** `FUN_00524520` prior alias `Named_VOG_DEBUG_STOP` is misleading (string is hash-lock assert). Proposed canonical `CVOGCharacter_FindActiveObjectiveIdForInteract` â€” **Probable**. Sibling `FUN_005245d0` â†’ `CVOGCharacter_FindActiveObjectiveIdForPick` â€” **Probable**; Ghidra renamed 2026-07-29.

## Inventory batch names

Canonical names for inventory-transfer units refined in the annotated raw layer (2026-07-23). `_Inferred` = retail symbol not recovered.

| Canonical name | Kind | Stable ID / address | Notes |
|----------------|------|---------------------|-------|
| `Vehicle_CreateCargoInventoryFromPageCount` | function | `aa_004f3a30` / `0x004f3a30` | Cargo grid 6Ã—(pagesÃ—13) @ vehicle+0x2b0 |
| `InventoryGrid_AllocateCellArray_Inferred` | function | `aa_00570720` / `0x00570720` | widthÃ—height cells Ã—8; empty=0xFFFFFFFF |
| `InventoryGrid_FindFreeSlot` | function | `aa_005713a0` / `0x005713a0` | First-fit Y outer, X inner; CanPlace |
| `InventoryGrid_FindFreeForItem` | function | `aa_005714e0` / `0x005714e0` | Item-aware space probe; tail â†’ FindFreeSlot; dual sealed 2026-07-29 |
| `InventoryGrid_PlaceItemFootprint` | function | `aa_00571620` / `0x00571620` | Stamp COID into every footprint cell |
| `InventoryGrid_ctor_Inferred` | function | `aa_00572650` / `0x00572650` | Construct 0x68-byte grid; alloc cells |
| `Client_RecvInventoryGrabResponse` | function | `aa_00811be0` / `0x00811be0` | S2C 0x2035; stack split / cursor; dual residual 2026-07-29 |
| `Client_InventoryGrabApplyToCursor` | function (proposed) | `aa_0093d6e0` / `0x0093d6e0` | GrabResponse/Unequip cursor apply; EAX=item DL=invType |
| `Object_SetCoidIdentity` | function (proposed) | `aa_00512160` / `0x00512160` | thiscall write COID +0x160/164 flag +0x168 |
| `Client_RecvInventoryDropResponse` | function | `aa_00813730` / `0x00813730` | S2C 0x2037; type 1/3/5/6 â†’ Place |
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
| `Skill_LocalCastValidate` | `aa_0051a790` | `0x0051a790` | Local pre-cast gates â†’ `eSkillResponses` |
| `Skill_StartCastAgainHeartbeat` | `aa_00519200` | `0x00519200` | Alloc type-8 cast-again HB + enqueue/start |
| `Skill_ApplyStatusEffectLocal` | `aa_0051aa00` | `0x0051aa00` | Local 0x2031 apply / cancel / delay HB |
| `CVOGHBOKToCastAgain_ctor` | `aa_0051e240` | `0x0051e240` | Type-8 HB; CD duration formula |
| `Skill_ResolveTargetList` | `aa_00550300` | `0x00550300` | Build TFID list; outFlags; gather |
| `CVOGReaction_ResolveSkillTargets` | `aa_0054c570` | `0x0054c570` | Materialize ranked skill runtime (`0x630`) from def map; missâ†’null; rank `+0x5f6` (name misnomer vs targets) |
| `Skill_ValidateTargetForSkill` | `aa_00553650` | `0x00553650` | Handler vtbl+0x44 target legality + HB list probe |
| `Skill_ValidateTarget_HBSkillListener` | `aa_005532e0` | `0x005532e0` | HB list predicate; RTTI `CVOGHBSkillBase`; `"Skill found with no base class: %d"` |
| `CVOGHBSkillBase_ctor` | `aa_005788d0` | `0x005788d0` | RTTI `CVOGHBSkillBase`; ValidateTarget notify=1 |
| `Skill_FilterTargetForResolveList_Inferred` | `aa_0054ff00` | `0x0054ff00` | ResolveTargetList filter; outFlags 4/8/0x10 |
| `Skill_RangeCheckTargetForResolveList_Inferred` | `aa_0058c0a0` | `0x0058c0a0` | Range helper after filter; return 0 â†’ outFlags bit2 |
| `Skill_ApplyEffectsOnTarget_Inferred` | `aa_005538a0` | `0x005538a0` | Combat/effect apply core; events 4/0xc/0xe/5/6; handler +0x5f0 |
| `Skill_AccuracyHitCheck_Inferred` | `aa_00553240` | `0x00553240` | Accuracy hit/miss; skill+0x24; -1 auto-hit; (roll%100)*0.01 |
| `Skill_AccuracyScore_Inferred` | `aa_005531d0` | `0x005531d0` | Accuracy score helper; bonus+skill+0x24 â†’ NonCreatureCastAutoHit |
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
| `Client_QuickBarActivateSkillSlot` | `aa_00921b50` | `0x00921b50` | Hotbar slot â†’ C2S `0x2030` |
| `Client_RequestCastSkill` | `aa_00941590` | `0x00941590` | Validate + optimistic CD HB + send `0x2030` |
| `Client_CastSkillFromQuickBarSlot` | `aa_009418e0` | `0x009418e0` | skillId â†’ resolve aim/TFID â†’ RequestCast |
| `Client_CastAfterPrompt` | `aa_00941ac0` | `0x00941ac0` | Pending `+0x30c0` â†’ RequestCast after target pick; clear prompt |

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
| `0x00812de0` | `Client_OnServerConnectionTerminated` | connection terminated â†’ login |
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
| `0x0080fe10` | `Inv_ConvoyLootMode_KillerTakes` | Convoy Loot Mode switchedâ€¦ |
| `0x0060a230` | `Net_PackInitialCharacterUpdate` | Packing initial update for character |
| `0x0060a820` | `Net_UnpackGhostUpdate` | unpacking update from net â€¦ ghost |
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
| `Skill_AccuracyScore_Inferred` | `0x005531d0` | skill thiscall RET 0xC; float ST0; bonus via 004c4140; pack â†’ 004ceba0; dual A/B |
| `CNDDoubleList_InvokePredicateAndRemove_Inferred` | `0x004e2600` | CS list + RTTI family `CNDDoubleList@PAVCVOGHBBase`; ValidateTarget consumer; dual quality |
| `CVOGHBSkillBase_ctor` | `0x005788d0` | **RTTI Confirmed** `".?AVCVOGHBSkillBase@@"` (COL `0x00aaede0` â†’ type_info `0x00af8cec` on vtbl `PTR_FUN_009d3fdc`); ValidateTarget notify=1; dual quality. **Supersedes** mistaken scaffold `CVOGHBSkillCast_ctor_Inferred` |

## 2026-07-29 W19-P dual A/B renames (evidence-only)

| Canonical name | VA | Evidence |
|----------------|-----|----------|
| `CVOGHBAIBase_SetFloat0x2c` | `0x0063a700` | leaf `movss` store `this+0x2c`; Turreted/Default ctor `push 0`; vtbl[+0x20]; dual A/B W19-P |
| `DES_BuildSBoxLookupTables` | `0x0071bdd0` | expands FIPS S1..S8 (`DAT_00afcb48`) â†’ four 0x1000 banks `d12e90..d15e90`; sole caller `DES_InitializeCipher`; dual A/B W19-P |

## 2026-08-04 WQ-007 residual dual renames (evidence-only)

Append-only batch for residual undualed callees of MissionDialog / journal / GiveMission / CompleteObjective paths. `_Inferred` = retail symbol not recovered; RTTI-backed names omit suffix.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `Client_MaybeShowMultiActiveMissionTip_Inferred` | function | `aa_008ac7a0` / `0x008ac7a0` | `FUN_008ac7a0` | missions-progression | `client::mission` | Sole caller HandleButton; hash `+0x540` walk; tip `0x20` if countâ‰¥2; dual A/B + ADV PASS | High (CF) | none | Not dialog list refresh |
| `Client_MissionDialog_SetHeaderCaption_Inferred` | function | `aa_008aaf60` / `0x008aaf60` | `FUN_008aaf60` | missions-progression | `client::mission` | Widget `+0x6e0`; vtbl+0x1d8 arity (0,1,1); dual A/B + ADV PASS | High (CF) | none | Clear vs set caption |
| `UI_MissionDialog_BuildResponseButtons_Inferred` | function | `aa_008ac110` / `0x008ac110` | `FUN_008ac110` | missions-progression | `client::mission` | `i_d_npc_2d_btn_response.xml`; ids `0x9C46+i`; dual A/B | High (role) | none | Response strip rebuild |
| `UI_MissionPanel_SyncListScrollbar_Inferred` | function | `aa_008aa610` / `0x008aa610` | `FUN_008aa610` | missions-progression | `client::mission` | Sole caller SetHeaderCaption tail; pages formula; dual A/B | High (role) | none | List scrollbar sync |
| `MissionDialog_ParseMarkupToRichText_Inferred` | function | `aa_008aab00` / `0x008aab00` | `FUN_008aab00` | missions-progression | `client::mission` | Tag/color matrix sealed; dual A/B + ADV PASS | High (CF) | none | `[$imp/npc/inst/loc/emote/pause/key]` |
| `MissionDialog_ClearResponseButtonSlots_Inferred` | function | `aa_008aa560` / `0x008aa560` | `FUN_008aa560` | missions-progression | `client::mission` | 8Ã— TFID `+0x518`; destroy `+0x708`; dual A/B + ADV PASS | High (CF) | none | Pre-rebuild wipe |
| `Mission_ExpandPlayerTokenPlaceholders_Inferred` | function | `aa_005465c0` / `0x005465c0` | `FUN_005465c0` | missions-progression | `client::mission` | Five tokens name/class/race/credits/level; dual A/B + ADV PASS | High (CF) | none | No wallet write |
| `Character_GetRaceDisplayName_Inferred` | function | `aa_00521800` / `0x00521800` | `FUN_00521800` | missions-progression | `client::mission` | Human/Mutant/Biomek strings; `[$race]` parent; dual A/B | High (role) | none | Ephemeral ring string |
| `Character_GetClassDisplayName_Inferred` | function | `aa_00521900` / `0x00521900` | `FUN_00521900` | missions-progression | `client::mission` | Thin wrapper â†’ `FUN_0051f940`; `[$class]`; dual A/B | High (role) | none | Ephemeral ring string |
| `UI_MissionJournal_MSelectEntry_Ctor_Inferred` | function | `aa_00829ec0` / `0x00829ec0` | `FUN_00829ec0` | missions-progression | `client::mission` | `new(0x510)`; skin `i_d_npc_2d_btn_mselect.xml`; dual A/B | High (role) | none | Journal mselect entry |
| `StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred` | function | `aa_00411180` / `0x00411180` | `FUN_00411180` | missions-progression | `client::util` | EAX=vec ESI=val; journal Ã—3 of 9 callers; dual A/B + ADV PASS | High (CF) | none | Generic; multi-domain |
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

## 2026-08-04 WQ-008 residual dual renames (evidence-only)

Append-only inventory residual batch. `_Inferred` = retail symbol not recovered.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `InventoryGrid_SetOwner_Inferred` | function | `aa_005718a0` / `0x005718a0` | `FUN_005718a0` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; grid owner rebind vtbl+0x18 | High (role/CF) | none | WQ-008 residual |
| `CVOGStore_TryAddItemQty_Inferred` | function | `aa_00588290` / `0x00588290` | `FUN_00588290` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; store stack-or-place add | High (role/CF) | none | WQ-008 residual |
| `CVOGCharacter_TryType1aSimpleExchange_Inferred` | function | `aa_00531570` / `0x00531570` | `FUN_00531570` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; type 0x1a simple exchange craft | High (role/CF) | none | WQ-008 residual |
| `CVOGCharacter_TryType1aCraft_Inferred` | function | `aa_005316c0` / `0x005316c0` | `FUN_005316c0` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; type 0x1a multi craft | High (role/CF) | none | WQ-008 residual |
| `InventoryGrid_MoveItemFootprint_Inferred` | function | `aa_00570af0` / `0x00570af0` | `FUN_00570af0` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; move footprint CanPlace+clear+stamp | High (role/CF) | none | WQ-008 residual |
| `InventoryGrid_CanPlaceItem` | function | `aa_005715d0` / `0x005715d0` | `FUN_005715d0` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; CanPlace probe InvSize | High | none | WQ-008 residual |
| `UI_QuickBarSlotButton_CanCastBoundSkill_Inferred` | function | `aa_00829190` / `0x00829190` | `FUN_00829190` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; QB skill readiness predicate | High (role/CF) | none | WQ-008 residual |
| `InventoryGrid_RemoveItemByCoid` | function | `aa_00571d80` / `0x00571d80` | `FUN_00571d80` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; FindByCoid+Remove qty1 | High | none | WQ-008 residual |
| `InventoryGrid_ScalarDeletingDtor` | function | `aa_00573910` / `0x00573910` | `FUN_00573910` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; MSVC scalar dtor grid | High | none | WQ-008 residual |
| `Outpost_GetScheduleEntryValueAtCursor_Inferred` | function | `aa_00607550` / `0x00607550` | `FUN_00607550` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; outpost schedule entry+4 | High (role/CF) | none | WQ-008 residual |
| `Client_CastFirstHardpointSkillFlag200_Inferred` | function | `aa_008c4fc0` / `0x008c4fc0` | `FUN_008c4fc0` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; host hardpoint skill flag 0x200 cast | High (role/CF) | none | WQ-008 residual |
| `UI_Window_OnCommand_Class8_Inferred` | function | `aa_0082f510` / `0x0082f510` | `FUN_0082f510` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; UI OnCommand class-8 dispatch | High (role/CF) | none | WQ-008 residual |
| `InventoryGrid_RemoveItemAtXY` | function | `aa_00571db0` / `0x00571db0` | `FUN_00571db0` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; cell XY remove wrapper | High | none | WQ-008 residual |
| `Client_RecvOpenAvailableGadgetResponse` | function | `aa_0080d570` / `0x0080d570` | `FUN_0080d570` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; S2C 0x20A8 open gadget slot | High | none | WQ-008 residual |
| `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` | function | `aa_0085ce20` / `0x0085ce20` | `FUN_0085ce20` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; hover RE/tinker/gadget tooltip | High (role/CF) | none | WQ-008 residual |
| `Client_UI_CraftHost_BindObjectByTfid_Inferred` | function | `aa_008e5ce0` / `0x008e5ce0` | `FUN_008e5ce0` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; craft host TFID bind | High (role/CF) | none | WQ-008 residual |
| `TargetFilter_FindNearestWorldObjByCbidList_Inferred` | function | `aa_0092adf0` / `0x0092adf0` | `FUN_0092adf0` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; nearest world obj CBID list + locker gate | High (role/CF) | none | WQ-008 residual |
| `Client_UseInventoryItemByCoid` | function | `aa_00941f50` / `0x00941f50` | `FUN_00941f50` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; UI COID cargo use | High | none | WQ-008 residual |
| `Character_SumCommodityTfidRowCost_Inferred` | function | `aa_00522710` / `0x00522710` | `FUN_00522710` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; commodity TFID row cost sum | High (role/CF) | none | WQ-008 residual |
| `InventoryGrid_SetDirtyFlag_Inferred` | function | `aa_005706d0` / `0x005706d0` | `FUN_005706d0` | inventory-transfer | `client::inventory` | dual A/B 2026-08-04; grid dirty +0x21 / bit0x20000 | High (role/CF) | none | WQ-008 residual |

### Rename history (2026-08-04 WQ-008 residual)

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-08-04 | aa_005718a0 | `FUN_005718a0` | `InventoryGrid_SetOwner_Inferred` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_00588290 | `FUN_00588290` | `CVOGStore_TryAddItemQty_Inferred` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_00531570 | `FUN_00531570` | `CVOGCharacter_TryType1aSimpleExchange_Inferred` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_005316c0 | `FUN_005316c0` | `CVOGCharacter_TryType1aCraft_Inferred` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_00570af0 | `FUN_00570af0` | `InventoryGrid_MoveItemFootprint_Inferred` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_005715d0 | `FUN_005715d0` | `InventoryGrid_CanPlaceItem` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_00829190 | `FUN_00829190` | `UI_QuickBarSlotButton_CanCastBoundSkill_Inferred` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_00571d80 | `FUN_00571d80` | `InventoryGrid_RemoveItemByCoid` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_00573910 | `FUN_00573910` | `InventoryGrid_ScalarDeletingDtor` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_00607550 | `FUN_00607550` | `Outpost_GetScheduleEntryValueAtCursor_Inferred` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_008c4fc0 | `FUN_008c4fc0` | `Client_CastFirstHardpointSkillFlag200_Inferred` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_0082f510 | `FUN_0082f510` | `UI_Window_OnCommand_Class8_Inferred` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_00571db0 | `FUN_00571db0` | `InventoryGrid_RemoveItemAtXY` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_0080d570 | `FUN_0080d570` | `Client_RecvOpenAvailableGadgetResponse` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_0085ce20 | `FUN_0085ce20` | `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_008e5ce0 | `FUN_008e5ce0` | `Client_UI_CraftHost_BindObjectByTfid_Inferred` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_0092adf0 | `FUN_0092adf0` | `TargetFilter_FindNearestWorldObjByCbidList_Inferred` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_00941f50 | `FUN_00941f50` | `Client_UseInventoryItemByCoid` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_00522710 | `FUN_00522710` | `Character_SumCommodityTfidRowCost_Inferred` | WQ-008 residual dual evidence |
| 2026-08-04 | aa_005706d0 | `FUN_005706d0` | `InventoryGrid_SetDirtyFlag_Inferred` | WQ-008 residual dual evidence |

## 2026-08-04 WQ-009 residual dual renames (evidence-only)

Append-only skills residual batch (nested callees of dualed cast paths + skill-bank neighborhood). `_Inferred` = retail symbol not recovered; product-named units omit suffix when Ghidra/RTTI sealed.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `Rng_CopyUnitTableWindow_Inferred` | function | `aa_0051b720` / `0x0051b720` | `FUN_0051b720` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `VehicleCrew_ContainsMember_Inferred` | function | `aa_005749d0` / `0x005749d0` | `FUN_005749d0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `Object_CopyTfid16At228_Inferred` | function | `aa_0040aff0` / `0x0040aff0` | `FUN_0040aff0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `CVOGHBSkill_Virus_OnHeartBeat` | function | `aa_0061fdf0` / `0x0061fdf0` | `FUN_0061fdf0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High | none | WQ-009 residual |
| `Object_IsWorldPickupType_Inferred` | function | `aa_005130e0` / `0x005130e0` | `FUN_005130e0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `Client_CycleHostileTarget_Inferred` | function | `aa_00943340` / `0x00943340` | `FUN_00943340` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `Client_SelectNearestHostileInRange_Inferred` | function | `aa_00943520` / `0x00943520` | `FUN_00943520` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `Object_ResolveTfIdVtbl1dc_Inferred` | function | `aa_004bb0d0` / `0x004bb0d0` | `FUN_004bb0d0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `Object_EnsureIntKeyMapAt0x15c_Inferred` | function | `aa_005190c0` / `0x005190c0` | `FUN_005190c0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred` | function | `aa_00519280` / `0x00519280` | `FUN_00519280` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `Gfx_BindMatDiffuseAmbientEmissive_Inferred` | function | `aa_005194f0` / `0x005194f0` | `FUN_005194f0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `EnsureFactionsLookupLoaded` | function | `aa_005197b0` / `0x005197b0` | `FUN_005197b0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High | none | WQ-009 residual |
| `Object_OnDeath` | function | `aa_00519d80` / `0x00519d80` | `FUN_00519d80` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High | none | WQ-009 residual |
| `Faction_LookupById` | function | `aa_0051a120` / `0x0051a120` | `FUN_0051a120` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High | none | WQ-009 residual |
| `Object_CreateFromEmbeddedCbid_Inferred` | function | `aa_0051b230` / `0x0051b230` | `FUN_0051b230` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `Object_LazyFillMatColorVecFromMesh_Inferred` | function | `aa_0051b2a0` / `0x0051b2a0` | `FUN_0051b2a0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `Object_ApplyMaterialBank_Inferred` | function | `aa_0051b310` / `0x0051b310` | `FUN_0051b310` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `ServerCreateFromPacket` | function | `aa_0051b350` / `0x0051b350` | `FUN_0051b350` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High | none | WQ-009 residual |
| `Object_LoadCloneBaseSkillTrio_Inferred` | function | `aa_0051b550` / `0x0051b550` | `FUN_0051b550` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |
| `Object_CreateOrRecreateSkillHash_Inferred` | function | `aa_00518e30` / `0x00518e30` | `FUN_00518e30` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 residual |

### Rename history (2026-08-04 WQ-009 residual)

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-08-04 | aa_0051b720 | `FUN_0051b720` | `Rng_CopyUnitTableWindow_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_005749d0 | `FUN_005749d0` | `VehicleCrew_ContainsMember_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_0040aff0 | `FUN_0040aff0` | `Object_CopyTfid16At228_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_0061fdf0 | `FUN_0061fdf0` | `CVOGHBSkill_Virus_OnHeartBeat` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_005130e0 | `FUN_005130e0` | `Object_IsWorldPickupType_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_00943340 | `FUN_00943340` | `Client_CycleHostileTarget_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_00943520 | `FUN_00943520` | `Client_SelectNearestHostileInRange_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_004bb0d0 | `FUN_004bb0d0` | `Object_ResolveTfIdVtbl1dc_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_005190c0 | `FUN_005190c0` | `Object_EnsureIntKeyMapAt0x15c_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_00519280 | `FUN_00519280` | `MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_005194f0 | `FUN_005194f0` | `Gfx_BindMatDiffuseAmbientEmissive_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_005197b0 | `FUN_005197b0` | `EnsureFactionsLookupLoaded` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_00519d80 | `FUN_00519d80` | `Object_OnDeath` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_0051a120 | `FUN_0051a120` | `Faction_LookupById` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_0051b230 | `FUN_0051b230` | `Object_CreateFromEmbeddedCbid_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_0051b2a0 | `FUN_0051b2a0` | `Object_LazyFillMatColorVecFromMesh_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_0051b310 | `FUN_0051b310` | `Object_ApplyMaterialBank_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_0051b350 | `FUN_0051b350` | `ServerCreateFromPacket` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_0051b550 | `FUN_0051b550` | `Object_LoadCloneBaseSkillTrio_Inferred` | WQ-009 residual dual evidence |
| 2026-08-04 | aa_00518e30 | `FUN_00518e30` | `Object_CreateOrRecreateSkillHash_Inferred` | WQ-009 residual dual evidence |

## 2026-08-04 WQ-009 depth residual dual renames (evidence-only)

Append-only skills depth residual batch (nested callees beyond WQ-009 residual: skill-hash recreate/ctor, Virus ctor/SharedHB, tree min/max/rotates, map erase, crew insert/clear, presence flags, TraversalUnlock, OnEnd, RNG sample, combat chat, convoy Invite/Kick UI, nameplate color, world-clock phase). `_Inferred` = retail symbol not recovered.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `SkillCNDHash_Recreate_Inferred` | function | `aa_004cbdc0` / `0x004cbdc0` | `FUN_004cbdc0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |
| `SkillCNDHash_Ctor_Inferred` | function | `aa_0051dd60` / `0x0051dd60` | `FUN_0051dd60` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |
| `StdTree_Min_Isnil29` | function | `aa_0051b5d0` / `0x0051b5d0` | `FUN_0051b5d0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High | none | WQ-009 depth residual |
| `CVOGHBSkill_Virus_Ctor` | function | `aa_0061f940` / `0x0061f940` | `FUN_0061f940` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High | none | WQ-009 depth residual |
| `CVOGHBSkill_SharedOnHeartBeat_Inferred` | function | `aa_0061b6f0` / `0x0061b6f0` | `FUN_0061b6f0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |
| `StdTree_Lrotate_Isnil29` | function | `aa_004192a0` / `0x004192a0` | `FUN_004192a0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High | none | WQ-009 depth residual |
| `StdTree_Rrotate_Isnil29_Inferred` | function | `aa_004192f0` / `0x004192f0` | `FUN_004192f0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |
| `VehicleCrew_InsertMember_Inferred` | function | `aa_005755b0` / `0x005755b0` | `FUN_005755b0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |
| `Skill_ComputeEffectPresenceFlags_Inferred` | function | `aa_00627be0` / `0x00627be0` | `FUN_00627be0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |
| `List_TraversalUnlock` | function | `aa_0040c700` / `0x0040c700` | `FUN_0040c700` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High | none | WQ-009 depth residual |
| `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` | function | `aa_00578ce0` / `0x00578ce0` | `FUN_00578ce0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |
| `Rng_SampleUnitFloat_Inferred` | function | `aa_007a4170` / `0x007a4170` | `FUN_007a4170` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |
| `StdTree_Max_Isnil29_Inferred` | function | `aa_00421b50` / `0x00421b50` | `FUN_00421b50` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |
| `VehicleCrew_ClearMemberObject_Inferred` | function | `aa_00574a90` / `0x00574a90` | `FUN_00574a90` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |
| `Map_EraseRange` | function | `aa_0051c7c0` / `0x0051c7c0` | `FUN_0051c7c0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High | none | WQ-009 depth residual |
| `Map_EraseRange_B` | function | `aa_0051d880` / `0x0051d880` | `FUN_0051d880` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High | none | WQ-009 depth residual |
| `Client_CombatChat_EmitEventLine_Inferred` | function | `aa_007ffef0` / `0x007ffef0` | `FUN_007ffef0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |
| `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` | function | `aa_0082fb30` / `0x0082fb30` | `FUN_0082fb30` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |
| `Ui_ResolveEntityNameColor_Inferred` | function | `aa_00930fc0` / `0x00930fc0` | `FUN_00930fc0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |
| `WorldClock_GetQuarterPhase01_Inferred` | function | `aa_00553dd0` / `0x00553dd0` | `FUN_00553dd0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth residual |

### Rename history (2026-08-04 WQ-009 depth residual)

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-08-04 | aa_004cbdc0 | `FUN_004cbdc0` | `SkillCNDHash_Recreate_Inferred` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_0051dd60 | `FUN_0051dd60` | `SkillCNDHash_Ctor_Inferred` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_0051b5d0 | `FUN_0051b5d0` | `StdTree_Min_Isnil29` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_0061f940 | `FUN_0061f940` | `CVOGHBSkill_Virus_Ctor` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_0061b6f0 | `FUN_0061b6f0` | `CVOGHBSkill_SharedOnHeartBeat_Inferred` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_004192a0 | `FUN_004192a0` | `StdTree_Lrotate_Isnil29` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_004192f0 | `FUN_004192f0` | `StdTree_Rrotate_Isnil29_Inferred` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_005755b0 | `FUN_005755b0` | `VehicleCrew_InsertMember_Inferred` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_00627be0 | `FUN_00627be0` | `Skill_ComputeEffectPresenceFlags_Inferred` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_0040c700 | `FUN_0040c700` | `List_TraversalUnlock` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_00578ce0 | `FUN_00578ce0` | `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_007a4170 | `FUN_007a4170` | `Rng_SampleUnitFloat_Inferred` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_00421b50 | `FUN_00421b50` | `StdTree_Max_Isnil29_Inferred` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_00574a90 | `FUN_00574a90` | `VehicleCrew_ClearMemberObject_Inferred` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_0051c7c0 | `FUN_0051c7c0` | `Map_EraseRange` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_0051d880 | `FUN_0051d880` | `Map_EraseRange_B` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_007ffef0 | `FUN_007ffef0` | `Client_CombatChat_EmitEventLine_Inferred` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_0082fb30 | `FUN_0082fb30` | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_00930fc0 | `FUN_00930fc0` | `Ui_ResolveEntityNameColor_Inferred` | WQ-009 depth residual dual evidence |
| 2026-08-04 | aa_00553dd0 | `FUN_00553dd0` | `WorldClock_GetQuarterPhase01_Inferred` | WQ-009 depth residual dual evidence |

## 2026-08-04 WQ-009 depth-2 residual dual renames (evidence-only)

Nested callees beyond WQ-009 depth (SkillCNDHash destroy/alloc, presence store/score, name palette/band, convoy menu populate, crew back-link, tree erase/insert isnil29 families, creature load skills, map free-subtree/erase/tidy).

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| SkillCNDHash_DestroyBucketTable_Inferred | function | aa_004cba60 / 0x004cba60 | FUN_004cba60 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual |
| SkillCNDHash_AllocBucketTable_Inferred | function | aa_004cb410 / 0x004cb410 | FUN_004cb410 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual |
| Skill_StoreEffectPresenceFlags_Inferred | function | aa_0054fec0 / 0x0054fec0 | FUN_0054fec0 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual |
| Skill_ComputeEffectScore_Inferred | function | aa_00627ec0 / 0x00627ec0 | FUN_00627ec0 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual |
| Ui_NameColorPalette_WriteArgb_Inferred | function | aa_00930f40 / 0x00930f40 | FUN_00930f40 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual |
| Ui_NameColorLevelBand_CopyFloat4_Inferred | function | aa_0092d580 / 0x0092d580 | FUN_0092d580 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual |
| UI_InteractionMenu_PopulateTargetButtons_Inferred | function | aa_0082fe20 / 0x0082fe20 | FUN_0082fe20 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual |
| Object_SetCrewHostBackLink_Inferred | function | aa_00520330 / 0x00520330 | FUN_00520330 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual |
| StdTree_EraseAndRebalance_Isnil29_Inferred | function | aa_004cb740 / 0x004cb740 | FUN_004cb740 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual |
| StdTree_InsertAndRebalance_Isnil29_Inferred | function | aa_004cbb60 / 0x004cbb60 | FUN_004cbb60 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual (insert clone B; same role family as 00406c40) |
| StdTree_EraseAndRebalance_Val28_Isnil29_Inferred | function | aa_00603830 / 0x00603830 | FUN_00603830 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual |
| StdTree_InsertAndRebalance_Val28_Isnil29_Inferred | function | aa_00603c90 / 0x00603c90 | FUN_00603c90 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual |
| StdTree_InsertAndRebalance_Isnil29_Inferred | function | aa_00406c40 / 0x00406c40 | FUN_00406c40 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual (insert clone A) |
| Map_EraseNode_B | function | aa_00409220 / 0x00409220 | FUN_00409220 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High | none | WQ-009 depth-2 residual |
| Object_CreateCreatureLoadSkills_Inferred | function | aa_004c8f00 / 0x004c8f00 | FUN_004c8f00 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual |
| Map_FreeSubtree_Isnil29 | function | aa_0051bbc0 / 0x0051bbc0 | FUN_0051bbc0 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High | none | WQ-009 depth-2 residual |
| Map_FreeSubtree_B | function | aa_0051be90 / 0x0051be90 | FUN_0051be90 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High | none | WQ-009 depth-2 residual |
| Map_EraseRange_Isnil1d_Inferred | function | aa_0051d700 / 0x0051d700 | FUN_0051d700 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-2 residual |
| Map_EraseRange_Isnil15 | function | aa_0051d7c0 / 0x0051d7c0 | FUN_0051d7c0 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High | none | WQ-009 depth-2 residual |
| Map_Tidy_FreeHead | function | aa_0051da30 / 0x0051da30 | FUN_0051da30 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-2 residual dual 2026-08-04 | High | none | WQ-009 depth-2 residual |

### Rename history (2026-08-04 WQ-009 depth-2 residual)

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-08-04 | aa_004cba60 | FUN_004cba60 | SkillCNDHash_DestroyBucketTable_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_004cb410 | FUN_004cb410 | SkillCNDHash_AllocBucketTable_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_0054fec0 | FUN_0054fec0 | Skill_StoreEffectPresenceFlags_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_00627ec0 | FUN_00627ec0 | Skill_ComputeEffectScore_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_00930f40 | FUN_00930f40 | Ui_NameColorPalette_WriteArgb_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_0092d580 | FUN_0092d580 | Ui_NameColorLevelBand_CopyFloat4_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_0082fe20 | FUN_0082fe20 | UI_InteractionMenu_PopulateTargetButtons_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_00520330 | FUN_00520330 | Object_SetCrewHostBackLink_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_004cb740 | FUN_004cb740 | StdTree_EraseAndRebalance_Isnil29_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_004cbb60 | FUN_004cbb60 | StdTree_InsertAndRebalance_Isnil29_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_00603830 | FUN_00603830 | StdTree_EraseAndRebalance_Val28_Isnil29_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_00603c90 | FUN_00603c90 | StdTree_InsertAndRebalance_Val28_Isnil29_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_00406c40 | FUN_00406c40 | StdTree_InsertAndRebalance_Isnil29_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_00409220 | FUN_00409220 | Map_EraseNode_B | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_004c8f00 | FUN_004c8f00 | Object_CreateCreatureLoadSkills_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_0051bbc0 | FUN_0051bbc0 | Map_FreeSubtree_Isnil29 | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_0051be90 | FUN_0051be90 | Map_FreeSubtree_B | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_0051d700 | FUN_0051d700 | Map_EraseRange_Isnil1d_Inferred | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_0051d7c0 | FUN_0051d7c0 | Map_EraseRange_Isnil15 | WQ-009 depth-2 residual dual evidence |
| 2026-08-04 | aa_0051da30 | FUN_0051da30 | Map_Tidy_FreeHead | WQ-009 depth-2 residual dual evidence |

## 2026-08-04 WQ-009 depth-3 residual dual renames (evidence-only)

Nested callees beyond WQ9E: SkillCNDHash freelist release + scalar dtor; StdTree buynode Val24 isnil29 twins; aggro/TFID map erase callers; map insert-or-find/hint; map free-subtree/erase-node/tidy isnil1d/isnil15 families; host mode flag; convoy leader slot; world-clock sky blend.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| SkillCNDHash_ReleaseChainsToFreelist_Inferred | function | aa_004cb680 / 0x004cb680 | FUN_004cb680 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| StdTree_Buynode_Isnil29_Val24_Inferred | function | aa_005a2de0 / 0x005a2de0 | FUN_005a2de0 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| StdTree_Buynode_Val24_Isnil29_Inferred | function | aa_00407e30 / 0x00407e30 | FUN_00407e30 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| Object_AggroMap_DecayOrPurge_Inferred | function | aa_004c8610 / 0x004c8610 | FUN_004c8610 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| Object_TFIDMap_FindFirstLive_EraseDead_Inferred | function | aa_004c8780 / 0x004c8780 | FUN_004c8780 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| StdTree_EraseRange_Isnil29_Inferred | function | aa_004cbaa0 / 0x004cbaa0 | FUN_004cbaa0 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| StdMap_InsertOrFind_IntKey_Isnil29_Inferred | function | aa_004cbe20 / 0x004cbe20 | FUN_004cbe20 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| StdMap_InsertOrFind_PairKey_Isnil29_Inferred | function | aa_004cbee0 / 0x004cbee0 | FUN_004cbee0 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| StdTree_InsertHint_Isnil29_Inferred | function | aa_004cc220 / 0x004cc220 | FUN_004cc220 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| Map_FreeSubtree_Isnil1d | function | aa_0051be10 / 0x0051be10 | FUN_0051be10 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High | none | WQ-009 depth-3 residual |
| Map_EraseNode_Isnil1d_Inferred | function | aa_0051c880 / 0x0051c880 | FUN_0051c880 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| Map_FreeSubtree_Isnil15 | function | aa_0051be50 / 0x0051be50 | FUN_0051be50 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High | none | WQ-009 depth-3 residual |
| Map_EraseNode_Isnil15 | function | aa_0051ce00 / 0x0051ce00 | FUN_0051ce00 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High | none | WQ-009 depth-3 residual |
| Map_Tidy_FreeHead_Isnil1d_Inferred | function | aa_0051e120 / 0x0051e120 | FUN_0051e120 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| SkillCNDHash_ScalarDeletingDtor_Inferred | function | aa_0051de60 / 0x0051de60 | FUN_0051de60 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| Map_Tidy_FreeHead_B | function | aa_0051e180 / 0x0051e180 | FUN_0051e180 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High | none | WQ-009 depth-3 residual |
| Object_SetHostModeFlag_Inferred | function | aa_0051f880 / 0x0051f880 | FUN_0051f880 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| ConvoyRoster_GetLeaderMember_Inferred | function | aa_00574880 / 0x00574880 | FUN_00574880 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| WorldClock_GetSkyBlendAmount_Inferred | function | aa_00553cd0 / 0x00553cd0 | FUN_00553cd0 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-3 residual |
| Map_EraseRange_Isnil15_B | function | aa_0051d940 / 0x0051d940 | FUN_0051d940 | skills-abilities | client::skill | dual A/B 2026-08-04; WQ-009 depth-3 residual dual 2026-08-04 | High | none | WQ-009 depth-3 residual |

### Rename history (2026-08-04 WQ-009 depth-3 residual)

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-08-04 | aa_004cb680 | FUN_004cb680 | SkillCNDHash_ReleaseChainsToFreelist_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_005a2de0 | FUN_005a2de0 | StdTree_Buynode_Isnil29_Val24_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_00407e30 | FUN_00407e30 | StdTree_Buynode_Val24_Isnil29_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_004c8610 | FUN_004c8610 | Object_AggroMap_DecayOrPurge_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_004c8780 | FUN_004c8780 | Object_TFIDMap_FindFirstLive_EraseDead_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_004cbaa0 | FUN_004cbaa0 | StdTree_EraseRange_Isnil29_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_004cbe20 | FUN_004cbe20 | StdMap_InsertOrFind_IntKey_Isnil29_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_004cbee0 | FUN_004cbee0 | StdMap_InsertOrFind_PairKey_Isnil29_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_004cc220 | FUN_004cc220 | StdTree_InsertHint_Isnil29_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_0051be10 | FUN_0051be10 | Map_FreeSubtree_Isnil1d | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_0051c880 | FUN_0051c880 | Map_EraseNode_Isnil1d_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_0051be50 | FUN_0051be50 | Map_FreeSubtree_Isnil15 | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_0051ce00 | FUN_0051ce00 | Map_EraseNode_Isnil15 | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_0051e120 | FUN_0051e120 | Map_Tidy_FreeHead_Isnil1d_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_0051de60 | FUN_0051de60 | SkillCNDHash_ScalarDeletingDtor_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_0051e180 | FUN_0051e180 | Map_Tidy_FreeHead_B | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_0051f880 | FUN_0051f880 | Object_SetHostModeFlag_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_00574880 | FUN_00574880 | ConvoyRoster_GetLeaderMember_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_00553cd0 | FUN_00553cd0 | WorldClock_GetSkyBlendAmount_Inferred | WQ-009 depth-3 residual dual evidence |
| 2026-08-04 | aa_0051d940 | FUN_0051d940 | Map_EraseRange_Isnil15_B | WQ-009 depth-3 residual dual evidence |

## 2026-08-04 WQ-009 depth-4 residual dual renames (evidence-only)

Nested callees beyond WQ9F: free-subtree isnil29 clones, SkillCNDHash complete dtor, predecessor + pair-key less, map operator[]/find TFID, aggro export, map free/tidy isnil15_B, escort ctor, class display lookup, env day-cycle sky blend, vector Ufill/insert-one, CNDHash 00a2c2e4 alloc/destroy.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `StdTree_FreeSubtree_Isnil29_Inferred` | function | `aa_004cb550` / `0x004cb550` | `FUN_004cb550` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual (free-subtree erase-range free) |
| `SkillCNDHash_CompleteDtor_Inferred` | function | `aa_0051de80` / `0x0051de80` | `FUN_0051de80` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual |
| `StdTree_Predecessor_Isnil29_Inferred` | function | `aa_004cb4f0` / `0x004cb4f0` | `FUN_004cb4f0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual |
| `StdPairKey_Less_HiSignedLoUnsigned_Inferred` | function | `aa_00401480` / `0x00401480` | `FUN_00401480` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual |
| `StdMap_OperatorIndex_Tfid_Isnil29_Inferred` | function | `aa_004cc400` / `0x004cc400` | `FUN_004cc400` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual |
| `Object_AggroMap_ExportToIntKeyMap_Inferred` | function | `aa_004c9380` / `0x004c9380` | `FUN_004c9380` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual |
| `Map_FreeSubtree_Isnil15_B` | function | `aa_0051bed0` / `0x0051bed0` | `FUN_0051bed0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High | none | WQ-009 depth-4 residual |
| `Map_Tidy_FreeHead_Isnil15_B` | function | `aa_0051e1b0` / `0x0051e1b0` | `FUN_0051e1b0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High | none | WQ-009 depth-4 residual |
| `CVOGHBMissionEscort_ctor` | function | `aa_006507c0` / `0x006507c0` | `FUN_006507c0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High | none | WQ-009 depth-4 residual |
| `LookupClassDisplayName_Inferred` | function | `aa_0051f940` / `0x0051f940` | `FUN_0051f940` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual |
| `Env_DayCycle_ApplySkyBlendAndLight_Inferred` | function | `aa_004912c0` / `0x004912c0` | `FUN_004912c0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual |
| `SkillSet_Vector_UninitializedFillN_0x18_Inferred` | function | `aa_00406f00` / `0x00406f00` | `FUN_00406f00` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual |
| `StdMap_Find_Tfid_Isnil29_Inferred` | function | `aa_004cba00` / `0x004cba00` | `FUN_004cba00` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual |
| `StdTree_FreeSubtree_Isnil29_Inferred` | function | `aa_00406c00` / `0x00406c00` | `FUN_00406c00` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual (free-subtree phys/tree free clone) |
| `StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred` | function | `aa_00406de0` / `0x00406de0` | `FUN_00406de0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual |
| `StdVector_UninitializedFillN_Elem0x28_Inferred` | function | `aa_00406e50` / `0x00406e50` | `FUN_00406e50` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual |
| `StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred` | function | `aa_00406e70` / `0x00406e70` | `FUN_00406e70` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual |
| `StdVector_UninitializedFillN_Elem12_Inferred` | function | `aa_00406ee0` / `0x00406ee0` | `FUN_00406ee0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-4 residual |
| `CNDHash_AllocBucketTable_00a2c2e4` | function | `aa_00406f20` / `0x00406f20` | `FUN_00406f20` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High | none | WQ-009 depth-4 residual |
| `CNDHash_DestroyBucketTable_00a2c2e4` | function | `aa_00406fc0` / `0x00406fc0` | `FUN_00406fc0` | skills-abilities | `client::skill` | dual A/B 2026-08-04; WQ-009 depth-4 residual dual 2026-08-04 | High | none | WQ-009 depth-4 residual |

### Rename history (2026-08-04 WQ-009 depth-4 residual)

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-08-04 | aa_004cb550 | `FUN_004cb550` | `StdTree_FreeSubtree_Isnil29_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_0051de80 | `FUN_0051de80` | `SkillCNDHash_CompleteDtor_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_004cb4f0 | `FUN_004cb4f0` | `StdTree_Predecessor_Isnil29_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_00401480 | `FUN_00401480` | `StdPairKey_Less_HiSignedLoUnsigned_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_004cc400 | `FUN_004cc400` | `StdMap_OperatorIndex_Tfid_Isnil29_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_004c9380 | `FUN_004c9380` | `Object_AggroMap_ExportToIntKeyMap_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_0051bed0 | `FUN_0051bed0` | `Map_FreeSubtree_Isnil15_B` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_0051e1b0 | `FUN_0051e1b0` | `Map_Tidy_FreeHead_Isnil15_B` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_006507c0 | `FUN_006507c0` | `CVOGHBMissionEscort_ctor` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_0051f940 | `FUN_0051f940` | `LookupClassDisplayName_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_004912c0 | `FUN_004912c0` | `Env_DayCycle_ApplySkyBlendAndLight_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_00406f00 | `FUN_00406f00` | `SkillSet_Vector_UninitializedFillN_0x18_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_004cba00 | `FUN_004cba00` | `StdMap_Find_Tfid_Isnil29_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_00406c00 | `FUN_00406c00` | `StdTree_FreeSubtree_Isnil29_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_00406de0 | `FUN_00406de0` | `StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_00406e50 | `FUN_00406e50` | `StdVector_UninitializedFillN_Elem0x28_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_00406e70 | `FUN_00406e70` | `StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_00406ee0 | `FUN_00406ee0` | `StdVector_UninitializedFillN_Elem12_Inferred` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_00406f20 | `FUN_00406f20` | `CNDHash_AllocBucketTable_00a2c2e4` | WQ-009 depth-4 residual dual evidence |
| 2026-08-04 | aa_00406fc0 | `FUN_00406fc0` | `CNDHash_DestroyBucketTable_00a2c2e4` | WQ-009 depth-4 residual dual evidence |

## 2026-08-04 WQ-009 depth-5 residual dual renames (evidence-only)

Nested callees beyond WQ9G: CNDHash freelist/ctor/dtor/recreate 00a2c2* family; vector InsertN/ConstructN/PushBack strides; Map_EraseRange_C; InsertHint isnil21; env day-cycle frame tick; pending ghost TFID assign; tree iterator++/buynode/buyhead; POD construct 0x138.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred` | function | `aa_004085e0` / `0x004085e0` | `FUN_004085e0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `StdVector_InsertN_Elem0x28_Inferred` | function | `aa_00408050` / `0x00408050` | `FUN_00408050` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `StdVector_ConstructN_Elem0x28_Inferred` | function | `aa_00409d40` / `0x00409d40` | `FUN_00409d40` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `StdVector_InsertN_Elem12_Inferred` | function | `aa_004082f0` / `0x004082f0` | `FUN_004082f0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred` | function | `aa_00406220` / `0x00406220` | `FUN_00406220` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred` | function | `aa_004062a0` / `0x004062a0` | `FUN_004062a0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `CNDHash_Ctor_00a2c2b0` | function | `aa_004063a0` / `0x004063a0` | `FUN_004063a0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High | none | WQ-009 depth-5 residual |
| `CNDHash_Dtor_00a2c2b0` | function | `aa_00406420` / `0x00406420` | `FUN_00406420` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High | none | WQ-009 depth-5 residual |
| `CNDHash_Recreate_00a2c2e4` | function | `aa_004195d0` / `0x004195d0` | `FUN_004195d0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High | none | WQ-009 depth-5 residual |
| `CVOGHBMissionEscort_ReactionFactory_Inferred` | function | `aa_0060c860` / `0x0060c860` | `FUN_0060c860` | missions-progression | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `Map_EraseRange_C` | function | `aa_00407d70` / `0x00407d70` | `FUN_00407d70` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High | none | WQ-009 depth-5 residual |
| `StdTree_InsertHint_Isnil21_Inferred` | function | `aa_00406560` / `0x00406560` | `FUN_00406560` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `Client_FrameTick_EnvDayCycleAndSystems_Inferred` | function | `aa_00942e20` / `0x00942e20` | `FUN_00942e20` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `Client_AssignPendingGhostByObjectTfid_Inferred` | function | `aa_00807550` / `0x00807550` | `FUN_00807550` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `StdTree_IteratorIncrement_Isnil31` | function | `aa_00408590` / `0x00408590` | `FUN_00408590` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High | none | WQ-009 depth-5 residual |
| `StdVector_InsertN_Elem0x10_Inferred` | function | `aa_00408640` / `0x00408640` | `FUN_00408640` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `PodCopyConstruct_Elem0x138_Inferred` | function | `aa_00408880` / `0x00408880` | `FUN_00408880` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred` | function | `aa_004088f0` / `0x004088f0` | `FUN_004088f0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `StdTree_Buynode_Val16_Isnil21_Inferred` | function | `aa_00408990` / `0x00408990` | `FUN_00408990` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |
| `StdTree_BuyHeadNode_Isnil29_Inferred` | function | `aa_00408a30` / `0x00408a30` | `FUN_00408a30` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-5 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-5 residual |

### Rename history (2026-08-04 WQ-009 depth-5 residual)

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-08-04 | aa_004085e0 | `FUN_004085e0` | `CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_00408050 | `FUN_00408050` | `StdVector_InsertN_Elem0x28_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_00409d40 | `FUN_00409d40` | `StdVector_ConstructN_Elem0x28_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_004082f0 | `FUN_004082f0` | `StdVector_InsertN_Elem12_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_00406220 | `FUN_00406220` | `StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_004062a0 | `FUN_004062a0` | `StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_004063a0 | `FUN_004063a0` | `CNDHash_Ctor_00a2c2b0` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_00406420 | `FUN_00406420` | `CNDHash_Dtor_00a2c2b0` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_004195d0 | `FUN_004195d0` | `CNDHash_Recreate_00a2c2e4` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_0060c860 | `FUN_0060c860` | `CVOGHBMissionEscort_ReactionFactory_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_00407d70 | `FUN_00407d70` | `Map_EraseRange_C` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_00406560 | `FUN_00406560` | `StdTree_InsertHint_Isnil21_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_00942e20 | `FUN_00942e20` | `Client_FrameTick_EnvDayCycleAndSystems_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_00807550 | `FUN_00807550` | `Client_AssignPendingGhostByObjectTfid_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_00408590 | `FUN_00408590` | `StdTree_IteratorIncrement_Isnil31` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_00408640 | `FUN_00408640` | `StdVector_InsertN_Elem0x10_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_00408880 | `FUN_00408880` | `PodCopyConstruct_Elem0x138_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_004088f0 | `FUN_004088f0` | `StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_00408990 | `FUN_00408990` | `StdTree_Buynode_Val16_Isnil21_Inferred` | WQ-009 depth-5 residual dual evidence |
| 2026-08-04 | aa_00408a30 | `FUN_00408a30` | `StdTree_BuyHeadNode_Isnil29_Inferred` | WQ-009 depth-5 residual dual evidence |

## 2026-08-04 WQ-009 depth-6 residual dual renames (evidence-only)

Nested callees beyond WQ9H: freelist slab vector teardown; ConstructN/PodCopy; isnil21 insert-or-find + insert-rebalance + node ctor; POD placement 0x138; host CNDHash traverse teardown+recreate; list incsizes; UI vehicle/widget scalar dtors; xform assign; field-block copy; CS init; ptr-vec shell ctor.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `FreelistSlabVector_Teardown_Inferred` | function | `aa_00416e80` / `0x00416e80` | `FUN_00416e80` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `StdVector_ConstructN_Elem12_Inferred` | function | `aa_00409db0` / `0x00409db0` | `FUN_00409db0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `StdVector_PodCopyElement_0x28_Inferred` | function | `aa_00409f30` / `0x00409f30` | `FUN_00409f30` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `StdTree_InsertAndRebalance_Isnil21_Inferred` | function | `aa_00407200` / `0x00407200` | `FUN_00407200` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `StdMap_InsertOrFind_PairKey_Isnil21_Inferred` | function | `aa_00407060` / `0x00407060` | `FUN_00407060` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `StdTree_NodeCtor_Val16_Isnil21_Inferred` | function | `aa_004099b0` / `0x004099b0` | `FUN_004099b0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred` | function | `aa_0040a6e0` / `0x0040a6e0` | `FUN_0040a6e0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred` | function | `aa_007fe640` / `0x007fe640` | `FUN_007fe640` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `StdList_Incsize_Max1fffffff` | function | `aa_00416010` / `0x00416010` | `FUN_00416010` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High | none | WQ-009 depth-6 residual |
| `Class_00a6f61c_ScalarDeletingDtor` | function | `aa_004160b0` / `0x004160b0` | `FUN_004160b0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High | none | WQ-009 depth-6 residual |
| `CWndVehicle_ScalarDeletingDtor` | function | `aa_004160d0` / `0x004160d0` | `FUN_004160d0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High | none | WQ-009 depth-6 residual |
| `CWidgetRotateVehicle_ScalarDeletingDtor` | function | `aa_004160f0` / `0x004160f0` | `FUN_004160f0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High | none | WQ-009 depth-6 residual |
| `Class_00a9bbe8_CompleteDtor_Inferred` | function | `aa_00416110` / `0x00416110` | `FUN_00416110` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `XformState_AssignSelectiveByFlags_Inferred` | function | `aa_00416160` / `0x00416160` | `FUN_00416160` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `FieldBlock_CopyFrom_ClearFlags0xBC_Inferred` | function | `aa_00416240` / `0x00416240` | `FUN_00416240` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `Class_00a7000c_ScalarDeletingDtor_Inferred` | function | `aa_00416350` / `0x00416350` | `FUN_00416350` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `Mem_ZeroSixDwords_Ecx_Inferred` | function | `aa_00416370` / `0x00416370` | `FUN_00416370` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `CriticalSection_Initialize_SehToHresult_Ecx_Inferred` | function | `aa_00416390` / `0x00416390` | `FUN_00416390` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred` | function | `aa_00416590` / `0x00416590` | `FUN_00416590` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |
| `Class_00a70524_ScalarDeletingDtor_Inferred` | function | `aa_004165f0` / `0x004165f0` | `FUN_004165f0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-6 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-6 residual |

### Rename history (2026-08-04 WQ-009 depth-6 residual)

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-08-04 | aa_00416e80 | `FUN_00416e80` | `FreelistSlabVector_Teardown_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_00409db0 | `FUN_00409db0` | `StdVector_ConstructN_Elem12_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_00409f30 | `FUN_00409f30` | `StdVector_PodCopyElement_0x28_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_00407200 | `FUN_00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_00407060 | `FUN_00407060` | `StdMap_InsertOrFind_PairKey_Isnil21_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_004099b0 | `FUN_004099b0` | `StdTree_NodeCtor_Val16_Isnil21_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_0040a6e0 | `FUN_0040a6e0` | `PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_007fe640 | `FUN_007fe640` | `Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_00416010 | `FUN_00416010` | `StdList_Incsize_Max1fffffff` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_004160b0 | `FUN_004160b0` | `Class_00a6f61c_ScalarDeletingDtor` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_004160d0 | `FUN_004160d0` | `CWndVehicle_ScalarDeletingDtor` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_004160f0 | `FUN_004160f0` | `CWidgetRotateVehicle_ScalarDeletingDtor` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_00416110 | `FUN_00416110` | `Class_00a9bbe8_CompleteDtor_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_00416160 | `FUN_00416160` | `XformState_AssignSelectiveByFlags_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_00416240 | `FUN_00416240` | `FieldBlock_CopyFrom_ClearFlags0xBC_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_00416350 | `FUN_00416350` | `Class_00a7000c_ScalarDeletingDtor_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_00416370 | `FUN_00416370` | `Mem_ZeroSixDwords_Ecx_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_00416390 | `FUN_00416390` | `CriticalSection_Initialize_SehToHresult_Ecx_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_00416590 | `FUN_00416590` | `PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred` | WQ-009 depth-6 residual dual evidence |
| 2026-08-04 | aa_004165f0 | `FUN_004165f0` | `Class_00a70524_ScalarDeletingDtor_Inferred` | WQ-009 depth-6 residual dual evidence |

## 2026-08-04 WQ-009 depth-7 residual dual renames (evidence-only)

Nested callees beyond WQ9I: PodCopy Elem12 + uninit_copy 0x28; UI complete dtors (CWndVehicle/WaypointIcon/Chatlog/Tutorial); MeshHost upload + ShopVeh swap; tree min/buyhead/predecessor/node-ctor/free-subtree families; HkArray free; GfxParam lookup.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `StdVector_PodCopyElement_Elem12_Inferred` | function | `aa_00409f50` / `0x00409f50` | `FUN_00409f50` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `StdVector_UninitializedCopy_Elem0x28_Inferred` | function | `aa_0040a520` / `0x0040a520` | `FUN_0040a520` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `CWndVehicle_CompleteDtor` | function | `aa_00834520` / `0x00834520` | `FUN_00834520` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High | none | WQ-009 depth-7 residual |
| `CWndWaypointIcon_CompleteDtor` | function | `aa_00832fa0` / `0x00832fa0` | `FUN_00832fa0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High | none | WQ-009 depth-7 residual |
| `CMenuChatlog_CompleteDtor` | function | `aa_008327f0` / `0x008327f0` | `FUN_008327f0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High | none | WQ-009 depth-7 residual |
| `CWndTutorial_CompleteDtor` | function | `aa_0097a8a0` / `0x0097a8a0` | `FUN_0097a8a0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High | none | WQ-009 depth-7 residual |
| `MeshHost_UploadXformPosNormAndIB16_Inferred` | function | `aa_00634c50` / `0x00634c50` | `FUN_00634c50` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `ShopVehObject_SwapSelectState_ESI_EDI_Inferred` | function | `aa_00833160` / `0x00833160` | `FUN_00833160` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `Class_00a733ec_ScalarDeletingDtor_Inferred` | function | `aa_00416f00` / `0x00416f00` | `FUN_00416f00` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `StdTree_Min_Isnil31` | function | `aa_00409160` / `0x00409160` | `FUN_00409160` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High | none | WQ-009 depth-7 residual |
| `StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred` | function | `aa_00409180` / `0x00409180` | `FUN_00409180` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `StdMap_StringKey_EraseAndRebalance_Inferred` | function | `aa_004094c0` / `0x004094c0` | `FUN_004094c0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `StdTree_BuyHeadNode_Isnil2D_Inferred` | function | `aa_00409780` / `0x00409780` | `FUN_00409780` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `StdTree_Predecessor_Isnil29_Edx_Inferred` | function | `aa_00409820` / `0x00409820` | `FUN_00409820` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` | function | `aa_00409880` / `0x00409880` | `FUN_00409880` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred` | function | `aa_004098d0` / `0x004098d0` | `FUN_004098d0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred` | function | `aa_00409920` / `0x00409920` | `FUN_00409920` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred` | function | `aa_00409970` / `0x00409970` | `FUN_00409970` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `HkArray_Elem8_FreeIfOwned_Inferred` | function | `aa_00409a00` / `0x00409a00` | `FUN_00409a00` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |
| `GfxParam_LookupAndWrite_Inferred` | function | `aa_00409a30` / `0x00409a30` | `FUN_00409a30` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-7 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-7 residual |

### Rename history (2026-08-04 WQ-009 depth-7 residual)

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-08-04 | aa_00409f50 | `FUN_00409f50` | `StdVector_PodCopyElement_Elem12_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_0040a520 | `FUN_0040a520` | `StdVector_UninitializedCopy_Elem0x28_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00834520 | `FUN_00834520` | `CWndVehicle_CompleteDtor` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00832fa0 | `FUN_00832fa0` | `CWndWaypointIcon_CompleteDtor` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_008327f0 | `FUN_008327f0` | `CMenuChatlog_CompleteDtor` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_0097a8a0 | `FUN_0097a8a0` | `CWndTutorial_CompleteDtor` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00634c50 | `FUN_00634c50` | `MeshHost_UploadXformPosNormAndIB16_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00833160 | `FUN_00833160` | `ShopVehObject_SwapSelectState_ESI_EDI_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00416f00 | `FUN_00416f00` | `Class_00a733ec_ScalarDeletingDtor_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00409160 | `FUN_00409160` | `StdTree_Min_Isnil31` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00409180 | `FUN_00409180` | `StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_004094c0 | `FUN_004094c0` | `StdMap_StringKey_EraseAndRebalance_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00409780 | `FUN_00409780` | `StdTree_BuyHeadNode_Isnil2D_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00409820 | `FUN_00409820` | `StdTree_Predecessor_Isnil29_Edx_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00409880 | `FUN_00409880` | `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_004098d0 | `FUN_004098d0` | `StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00409920 | `FUN_00409920` | `StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00409970 | `FUN_00409970` | `StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00409a00 | `FUN_00409a00` | `HkArray_Elem8_FreeIfOwned_Inferred` | WQ-009 depth-7 residual dual evidence |
| 2026-08-04 | aa_00409a30 | `FUN_00409a30` | `GfxParam_LookupAndWrite_Inferred` | WQ-009 depth-7 residual dual evidence |

## 2026-08-04 WQ-009 depth-8 residual dual renames (evidence-only)

Nested callees beyond WQ9J: uninit_copy trampoline; string destroy; erase-range free parents; buynode/construct-empty; insert-or-find EBX; erase isnil31; UI complete-dtor chain (buffered/window/menu/dialog); shop reindex; factories; L/R rotate isnil2d; uninit_copy Elem12.

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `StdVector_UninitCopyTrampoline_Elem0x28_Inferred` | function | `aa_00409ae0` / `0x00409ae0` | `FUN_00409ae0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `StdTree_DestroyStringAt0C_Inferred` | function | `aa_00409b80` / `0x00409b80` | `FUN_00409b80` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred` | function | `aa_00407b70` / `0x00407b70` | `FUN_00407b70` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred` | function | `aa_00407f90` / `0x00407f90` | `FUN_00407f90` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred` | function | `aa_00404180` / `0x00404180` | `FUN_00404180` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `StdTree_ConstructEmpty_Isnil31_Inferred` | function | `aa_00405f20` / `0x00405f20` | `FUN_00405f20` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `StdTree_ConstructEmpty_Isnil2D_Inferred` | function | `aa_00406190` / `0x00406190` | `FUN_00406190` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred` | function | `aa_00405bd0` / `0x00405bd0` | `FUN_00405bd0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `StdTree_EraseAndRebalance_Isnil31_Inferred` | function | `aa_00408ed0` / `0x00408ed0` | `FUN_00408ed0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `CWndVehicle_DerivedTeardown_EDI` | function | `aa_00833d50` / `0x00833d50` | `FUN_00833d50` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High | none | WQ-009 depth-8 residual |
| `CNDUIWndBuffered_CompleteDtor` | function | `aa_0078ca80` / `0x0078ca80` | `FUN_0078ca80` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High | none | WQ-009 depth-8 residual |
| `CNDUIWindow_CompleteDtor` | function | `aa_007b5be0` / `0x007b5be0` | `FUN_007b5be0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High | none | WQ-009 depth-8 residual |
| `CVOGMenu_CompleteDtor` | function | `aa_0082d540` / `0x0082d540` | `FUN_0082d540` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High | none | WQ-009 depth-8 residual |
| `CNDUIDialog_CompleteDtor` | function | `aa_00792c20` / `0x00792c20` | `FUN_00792c20` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High | none | WQ-009 depth-8 residual |
| `ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred` | function | `aa_0083ac90` / `0x0083ac90` | `FUN_0083ac90` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `Class_00a733ec_Factory_WithFreeCallback_Inferred` | function | `aa_00416830` / `0x00416830` | `FUN_00416830` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `Class_00a733ec_Factory_NullFreeCallback_Inferred` | function | `aa_004168c0` / `0x004168c0` | `FUN_004168c0` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `StdTree_LeftRotate_Isnil2D_Inferred` | function | `aa_0044e010` / `0x0044e010` | `FUN_0044e010` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `StdTree_Rrotate_Isnil2D_Inferred` | function | `aa_0042a840` / `0x0042a840` | `FUN_0042a840` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |
| `StdVector_UninitializedCopy_Elem12_Inferred` | function | `aa_0040a590` / `0x0040a590` | `FUN_0040a590` | skills-abilities | `client` | dual A/B 2026-08-04; WQ-009 depth-8 residual dual 2026-08-04 | High (role/CF) | none | WQ-009 depth-8 residual |

### Rename history (2026-08-04 WQ-009 depth-8 residual)

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-08-04 | aa_00409ae0 | `FUN_00409ae0` | `StdVector_UninitCopyTrampoline_Elem0x28_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_00409b80 | `FUN_00409b80` | `StdTree_DestroyStringAt0C_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_00407b70 | `FUN_00407b70` | `StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_00407f90 | `FUN_00407f90` | `StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_00404180 | `FUN_00404180` | `StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_00405f20 | `FUN_00405f20` | `StdTree_ConstructEmpty_Isnil31_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_00406190 | `FUN_00406190` | `StdTree_ConstructEmpty_Isnil2D_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_00405bd0 | `FUN_00405bd0` | `StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_00408ed0 | `FUN_00408ed0` | `StdTree_EraseAndRebalance_Isnil31_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_00833d50 | `FUN_00833d50` | `CWndVehicle_DerivedTeardown_EDI` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_0078ca80 | `FUN_0078ca80` | `CNDUIWndBuffered_CompleteDtor` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_007b5be0 | `FUN_007b5be0` | `CNDUIWindow_CompleteDtor` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_0082d540 | `FUN_0082d540` | `CVOGMenu_CompleteDtor` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_00792c20 | `FUN_00792c20` | `CNDUIDialog_CompleteDtor` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_0083ac90 | `FUN_0083ac90` | `ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_00416830 | `FUN_00416830` | `Class_00a733ec_Factory_WithFreeCallback_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_004168c0 | `FUN_004168c0` | `Class_00a733ec_Factory_NullFreeCallback_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_0044e010 | `FUN_0044e010` | `StdTree_LeftRotate_Isnil2D_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_0042a840 | `FUN_0042a840` | `StdTree_Rrotate_Isnil2D_Inferred` | WQ-009 depth-8 residual dual evidence |
| 2026-08-04 | aa_0040a590 | `FUN_0040a590` | `StdVector_UninitializedCopy_Elem12_Inferred` | WQ-009 depth-8 residual dual evidence |

## 2026-08-05 WQ-009 depth-9 residual dual renames (evidence-only)

Nested callees beyond WQ9K: isnil131 iterator++/erase-rebalance; out_of_range ctor; L/R rotate + max isnil31; RDTSC timer stamp; UI complete-dtor chain leaves (buffered teardown, clear owned, gfx window, text layout, refptr@294, nested layout); CVOGMenu CNDHash traverse-delete; StdList clear ESI; dialog child-hash teardown; shop list slot bind/orient helpers. STL/UI helpers under residual depth (not product skill English).

| Canonical name | Kind | Stable ID / address | Original / decompiler name | System | Namespace proposal | Evidence | Confidence | Aliases | Notes |
|----------------|------|---------------------|----------------------------|--------|---------------------|----------|------------|---------|-------|
| `StdTree_IteratorIncrement_Isnil131` | function | `aa_00404000` / `0x00404000` | `FUN_00404000` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High | none | WQ-009 depth-9 residual |
| `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` | function | `aa_00408ad0` / `0x00408ad0` | `FUN_00408ad0` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `Std_OutOfRange_CtorFromString` | function | `aa_00401bc0` / `0x00401bc0` | `FUN_00401bc0` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High | none | WQ-009 depth-9 residual |
| `StdTree_Lrotate_Isnil31_Inferred` | function | `aa_00403e90` / `0x00403e90` | `FUN_00403e90` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `StdTree_Rrotate_Isnil31_Inferred` | function | `aa_00403ee0` / `0x00403ee0` | `FUN_00403ee0` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High | none | WQ-009 depth-9 residual |
| `StdTree_Max_Isnil31` | function | `aa_004043e0` / `0x004043e0` | `FUN_004043e0` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High | none | WQ-009 depth-9 residual |
| `RdtscTimer_StampAndArm_Inferred` | function | `aa_0076c4d0` / `0x0076c4d0` | `FUN_0076c4d0` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `CNDUIWndBuffered_TeardownBufferedOwned_Inferred` | function | `aa_0078c3d0` / `0x0078c3d0` | `FUN_0078c3d0` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `CNDUIWindow_ClearOwnedObject_Inferred` | function | `aa_007a8580` / `0x007a8580` | `FUN_007a8580` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `ObjectCsList_DestroyAll_Inferred` | function | `aa_00424060` / `0x00424060` | `FUN_00424060` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High | none | WQ-009 depth-9 residual |
| `gfxUIWindow_CompleteDtor` | function | `aa_00759de0` / `0x00759de0` | `FUN_00759de0` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `UiTextLayout_CompleteDtor_Inferred` | function | `aa_00797d70` / `0x00797d70` | `FUN_00797d70` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred` | function | `aa_007aec70` / `0x007aec70` | `FUN_007aec70` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `CNDUIWindow_ReleaseTextLayoutAndNested_Inferred` | function | `aa_007aff00` / `0x007aff00` | `FUN_007aff00` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred` | function | `aa_0082ce20` / `0x0082ce20` | `FUN_0082ce20` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `StdList_Clear_ESI` | function | `aa_00415e90` / `0x00415e90` | `FUN_00415e90` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `CNDUIDialog_TeardownChildHash_Inferred` | function | `aa_007917c0` / `0x007917c0` | `FUN_007917c0` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred` | function | `aa_0083a860` / `0x0083a860` | `FUN_0083a860` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred` | function | `aa_0083a880` / `0x0083a880` | `FUN_0083a880` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |
| `ShopVehList_BindSlotFromListIndexIfMismatch_Inferred` | function | `aa_0083abf0` / `0x0083abf0` | `FUN_0083abf0` | skills-abilities | `client` | dual A/B 2026-08-05; WQ-009 depth-9 residual dual 2026-08-05 | High (role/CF) | none | WQ-009 depth-9 residual |

### Rename history (2026-08-05 WQ-009 depth-9 residual)

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-08-05 | aa_00404000 | `FUN_00404000` | `StdTree_IteratorIncrement_Isnil131` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_00408ad0 | `FUN_00408ad0` | `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_00401bc0 | `FUN_00401bc0` | `Std_OutOfRange_CtorFromString` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_00403e90 | `FUN_00403e90` | `StdTree_Lrotate_Isnil31_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_00403ee0 | `FUN_00403ee0` | `StdTree_Rrotate_Isnil31_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_004043e0 | `FUN_004043e0` | `StdTree_Max_Isnil31` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_0076c4d0 | `FUN_0076c4d0` | `RdtscTimer_StampAndArm_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_0078c3d0 | `FUN_0078c3d0` | `CNDUIWndBuffered_TeardownBufferedOwned_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_007a8580 | `FUN_007a8580` | `CNDUIWindow_ClearOwnedObject_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_00424060 | `FUN_00424060` | `ObjectCsList_DestroyAll_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_00759de0 | `FUN_00759de0` | `gfxUIWindow_CompleteDtor` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_00797d70 | `FUN_00797d70` | `UiTextLayout_CompleteDtor_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_007aec70 | `FUN_007aec70` | `CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_007aff00 | `FUN_007aff00` | `CNDUIWindow_ReleaseTextLayoutAndNested_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_0082ce20 | `FUN_0082ce20` | `CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_00415e90 | `FUN_00415e90` | `StdList_Clear_ESI` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_007917c0 | `FUN_007917c0` | `CNDUIDialog_TeardownChildHash_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_0083a860 | `FUN_0083a860` | `ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_0083a880 | `FUN_0083a880` | `ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred` | WQ-009 depth-9 residual dual evidence |
| 2026-08-05 | aa_0083abf0 | `FUN_0083abf0` | `ShopVehList_BindSlotFromListIndexIfMismatch_Inferred` | WQ-009 depth-9 residual dual evidence |

### Mega residual dual names (2026-08-05)

Append-only batch for mega residual dual units (MEGA-001..140 complete; final residual `0x00589bc0` sealed MERGE-MEGA-005). Canonical names from dual `A_aa_*` review filenames; `_Inferred` retained where agents used it.

| `CVOGCharacter_CleanupDraggingObject` | function | `aa_00520dc0` / `0x00520dc0` | `FUN_00520dc0` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Character_CountType1aCraftableBatches` | function | `aa_00522060` / `0x00522060` | `FUN_00522060` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Character_GiveItemByCbid_Inventory_Inferred` | function | `aa_005310a0` / `0x005310a0` | `FUN_005310a0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Skill_HB_RescheduleStatus_Inferred` | function | `aa_005787a0` / `0x005787a0` | `FUN_005787a0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Skill_HB_ApplyHeatDelta_Inferred` | function | `aa_00589bc0` / `0x00589bc0` | `FUN_00589bc0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 MERGE-MEGA-005 | High (role/CF) | none | mega residual |
| `Skill_HB_ApplyHpDelta_Inferred` | function | `aa_00589c70` / `0x00589c70` | `FUN_00589c70` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Skill_HB_ApplyShieldPool_Inferred` | function | `aa_00589d90` / `0x00589d90` | `FUN_00589d90` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Skill_HB_ApplyShortAndFloater_Inferred` | function | `aa_0058cc40` / `0x0058cc40` | `FUN_0058cc40` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Skill_HB_ApplyMultiArgEffect_Inferred` | function | `aa_0058d8e0` / `0x0058d8e0` | `FUN_0058d8e0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Tracker_SetActiveMissionObjective_Inferred` | function | `aa_0092a590` / `0x0092a590` | `FUN_0092a590` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Host_DualCNDHash_TraverseNextObject_Inferred` | function | `aa_004bae00` / `0x004bae00` | `FUN_004bae00` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Item_TryConcatStackWithPeer` | function | `aa_00513eb0` / `0x00513eb0` | `FUN_00513eb0` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CVOGCharacter_RewardInventoryList_PushBack_Inferred` | function | `aa_0052b350` / `0x0052b350` | `FUN_0052b350` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Skill_HB_ClearPtrVectorAt6b0_Inferred` | function | `aa_00578ac0` / `0x00578ac0` | `FUN_00578ac0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CVOGHBAIDriver_AxisPark_Inferred` | function | `aa_005d73a0` / `0x005d73a0` | `FUN_005d73a0` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Skill_HB_CopyTfid16At668_Inferred` | function | `aa_0061b960` / `0x0061b960` | `FUN_0061b960` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |
| `CVOGHBMoveVehicle_OnEnd` | function | `aa_00636ba0` / `0x00636ba0` | `FUN_00636ba0` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `ActionMap_FindSlotByKeyMod_Inferred` | function | `aa_007f6db0` / `0x007f6db0` | `FUN_007f6db0` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `ActionMap_ClearAllSlotBindFields_Inferred` | function | `aa_007f74a0` / `0x007f74a0` | `FUN_007f74a0` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_SkillHB_OnEndUiCleanup_Inferred` | function | `aa_00802b70` / `0x00802b70` | `FUN_00802b70` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `MissionUI_ParkDriveAxes_Inferred` | function | `aa_0092f090` / `0x0092f090` | `FUN_0092f090` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_LoadKeymapIni` | function | `aa_0092f710` / `0x0092f710` | `FUN_0092f710` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_SortTargetListByViewAngle_Inferred` | function | `aa_00930360` / `0x00930360` | `FUN_00930360` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred` | function | `aa_009373e0` / `0x009373e0` | `FUN_009373e0` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `ObjectiveNode_IsEligibleForTracker_Inferred` | function | `aa_0059dc50` / `0x0059dc50` | `FUN_0059dc50` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `hkDefaultAnalogDriverInput_FilterSteer_Inferred` | function | `aa_005fdf20` / `0x005fdf20` | `FUN_005fdf20` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_Interact_OpenCVOGStore_Inferred` | function | `aa_00938670` / `0x00938670` | `FUN_00938670` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Host_LookupObjectByKey_PairTable30_Inferred` | function | `aa_0040afb0` / `0x0040afb0` | `FUN_0040afb0` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CNDHash_TraverseToNext_ListNext20` | function | `aa_004bc530` / `0x004bc530` | `FUN_004bc530` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `MatchTargetEval_DefaultReturnFalse_Inferred` | function | `aa_004cc820` / `0x004cc820` | `FUN_004cc820` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CVOGObjectiveRequirement_Patrol_EventAction_Inferred` | function | `aa_0060e800` / `0x0060e800` | `FUN_0060e800` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `UI_CraftHost_BindResolvedObject_Inferred` | function | `aa_008e5990` / `0x008e5990` | `FUN_008e5990` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_InteractWorldClick_SoftCastAlt_Inferred` | function | `aa_0091a350` / `0x0091a350` | `FUN_0091a350` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdTree_EraseAndRebalance_Isnil29_RetC_Inferred` | function | `aa_00402850` / `0x00402850` | `FUN_00402850` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Item_ValidateGadgetAttach_Inferred` | function | `aa_00513400` / `0x00513400` | `FUN_00513400` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Item_ValidateTinkerKitUse_Inferred` | function | `aa_00513c10` / `0x00513c10` | `FUN_00513c10` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `TtPhantom_CtorFromAabbDesc_Inferred` | function | `aa_00581220` / `0x00581220` | `FUN_00581220` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred` | function | `aa_0060df70` / `0x0060df70` | `FUN_0060df70` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred` | function | `aa_006c6c50` / `0x006c6c50` | `FUN_006c6c50` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred` | function | `aa_00402b30` / `0x00402b30` | `FUN_00402b30` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdTree_LowerBound_StringKey_Isnil131_Inferred` | function | `aa_00403c60` / `0x00403c60` | `FUN_00403c60` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CsSList_RemoveFirstByPredicate_Inferred` | function | `aa_00405920` / `0x00405920` | `FUN_00405920` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdSort_RanItStride16_Inferred` | function | `aa_00409bd0` / `0x00409bd0` | `FUN_00409bd0` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdVector_ConstructN_Elem0x10_Inferred` | function | `aa_00409e20` / `0x00409e20` | `FUN_00409e20` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Character_SelectInventoryGridByMode_Inferred` | function | `aa_00522020` / `0x00522020` | `FUN_00522020` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `MissionDialog_StampResponseSlot_Inferred` | function | `aa_008aa510` / `0x008aa510` | `FUN_008aa510` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdTree_InsertAndRebalance_Isnil31_Inferred` | function | `aa_00403250` / `0x00403250` | `FUN_00403250` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdTree_Buynode_Val32_Isnil31_Inferred` | function | `aa_00403f30` / `0x00403f30` | `FUN_00403f30` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CVOGPhysics_WriteNotFullyReadyOut_Inferred` | function | `aa_00404e00` / `0x00404e00` | `FUN_00404e00` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Item_RequiresBindOrTradeLock` | function | `aa_00513fc0` / `0x00513fc0` | `FUN_00513fc0` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_NpcMissionDialog_ApplyPanelMode_Inferred` | function | `aa_008ab550` / `0x008ab550` | `FUN_008ab550` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdList_DefaultCtor_Inferred` | function | `aa_004023f0` / `0x004023f0` | `FUN_004023f0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Object_Store16At80_Inferred` | function | `aa_00404c60` / `0x00404c60` | `FUN_00404c60` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `SkillSet_CopyBackward_0x18` | function | `aa_00409ed0` / `0x00409ed0` | `FUN_00409ed0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |
| `SkillSet_Vector_UninitializedCopy_0x18_Inferred` | function | `aa_0040a600` / `0x0040a600` | `FUN_0040a600` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Inventory_ValidateEquipmentChange_Inferred` | function | `aa_004f6a80` / `0x004f6a80` | `FUN_004f6a80` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CVOGWaypoint_DoFollowObjectShortcutsUpdate` | function | `aa_005d5cc0` / `0x005d5cc0` | `FUN_005d5cc0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `MissionDialog_SetNpcObjectAndNameCaption_Inferred` | function | `aa_008aa4b0` / `0x008aa4b0` | `FUN_008aa4b0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdList_PushBack_Val0x28_Inferred` | function | `aa_004025e0` / `0x004025e0` | `FUN_004025e0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Math_Vec3_Length_Sqrt_Inferred` | function | `aa_00404c00` / `0x00404c00` | `FUN_00404c00` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `InventoryGrid_CompleteDtor` | function | `aa_005725a0` / `0x005725a0` | `FUN_005725a0` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |
| `SoftCastHitList_CoreFillAndRegister_Inferred` | function | `aa_006ca890` / `0x006ca890` | `FUN_006ca890` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `MedalUI_RefreshPagedAchievementSlots_Inferred` | function | `aa_0090cbc0` / `0x0090cbc0` | `FUN_0090cbc0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdMap_StringKey_InsertOrFind_Via401db0_Inferred` | function | `aa_00401c50` / `0x00401c50` | `FUN_00401c50` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `BasicStringFlag_CtorFromStringAndChar_Inferred` | function | `aa_00401d30` / `0x00401d30` | `FUN_00401d30` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdTree_InsertAndRebalance_Isnil2D_Inferred` | function | `aa_00401db0` / `0x00401db0` | `FUN_00401db0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdList_Destroy_FreeHead_ViaClearEsi_Inferred` | function | `aa_00402280` / `0x00402280` | `FUN_00402280` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred` | function | `aa_004d2e50` / `0x004d2e50` | `FUN_004d2e50` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CVOGObject_EvalChildDeliverObjectiveInteract_Inferred` | function | `aa_004d3ba0` / `0x004d3ba0` | `FUN_004d3ba0` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `VOGPhysics_SphereQueryCollect_Ctor_Inferred` | function | `aa_005ebec0` / `0x005ebec0` | `FUN_005ebec0` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |
| `PhysicsShape_Sphere_CtorFromRadius_Inferred` | function | `aa_006c7fa0` / `0x006c7fa0` | `FUN_006c7fa0` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `UI_InteractionMenu_RebuildPopupShell_Inferred` | function | `aa_0082d2b0` / `0x0082d2b0` | `FUN_0082d2b0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `UI_InteractionMenu_AddSendTell_Inferred` | function | `aa_0082f810` / `0x0082f810` | `FUN_0082f810` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `UI_InteractionMenu_AddIgnoreToggle` | function | `aa_0082f8d0` / `0x0082f8d0` | `FUN_0082f8d0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `UI_InteractionMenu_AddFriendsToggle` | function | `aa_0082f9a0` / `0x0082f9a0` | `FUN_0082f9a0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `UI_InteractionMenu_AddClanInviteOrKick_Inferred` | function | `aa_0082fa60` / `0x0082fa60` | `FUN_0082fa60` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `UI_InteractionMenu_AddTrade_Inferred` | function | `aa_0082fc40` / `0x0082fc40` | `FUN_0082fc40` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `MissionDialog_SetTurnInReadyFlag_Inferred` | function | `aa_008aa490` / `0x008aa490` | `FUN_008aa490` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdTree_Buynode_StringByte_Isnil2D_Inferred` | function | `aa_00401f40` / `0x00401f40` | `FUN_00401f40` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `BasicStringFlag_CopyCtor_EdiSrc_Inferred` | function | `aa_00402040` / `0x00402040` | `FUN_00402040` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdList_BuyNode_Dword_Seh` | function | `aa_00418700` / `0x00418700` | `FUN_00418700` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |
| `StdVector_DwordSize_EaxVec_Inferred` | function | `aa_00401c30` / `0x00401c30` | `FUN_00401c30` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |
| `StdMap_Find_Tfid_Isnil29_EaxMap_Inferred` | function | `aa_00402ae0` / `0x00402ae0` | `FUN_00402ae0` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `UI_InteractionMenu_AddNameplateLabel_Inferred` | function | `aa_0082fd50` / `0x0082fd50` | `FUN_0082fd50` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_UI_CraftHost_ResetRecipePanel_Inferred` | function | `aa_008e2d60` / `0x008e2d60` | `FUN_008e2d60` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `UI_CloseRelatedChrome_Inferred` | function | `aa_0090d400` / `0x0090d400` | `FUN_0090d400` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `MissionTracker_ResetUiStateFields_Inferred` | function | `aa_00929c00` / `0x00929c00` | `FUN_00929c00` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Tracker_ClearOwnedPtrVectorAt11c_Inferred` | function | `aa_0092a3d0` / `0x0092a3d0` | `FUN_0092a3d0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdList_PushFront_DwordFromEax_Inferred` | function | `aa_004027f0` / `0x004027f0` | `FUN_004027f0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `InventoryGrid_ClearItemsAndReEmptyCells_Inferred` | function | `aa_00570f70` / `0x00570f70` | `FUN_00570f70` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CVOGObjective_ProbeEligibilityCode_Inferred` | function | `aa_0059db80` / `0x0059db80` | `FUN_0059db80` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `InventoryGrid_SetSecondaryOwner_Inferred` | function | `aa_00573900` / `0x00573900` | `FUN_00573900` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CVOGHBAI_DecEntityA4SecondaryCounter_Inferred` | function | `aa_005cc560` / `0x005cc560` | `FUN_005cc560` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_Input_KeyDown_UiGateAndForward_Inferred` | function | `aa_00790020` / `0x00790020` | `FUN_00790020` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `MedalUi_ApplyAchievementSlotButton_Inferred` | function | `aa_0090c9a0` / `0x0090c9a0` | `FUN_0090c9a0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_Input_FindFirstActiveUiWindowTable5_Inferred` | function | `aa_0090d390` / `0x0090d390` | `FUN_0090d390` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_Input_DismissUiWindowTable5_Inferred` | function | `aa_0090dab0` / `0x0090dab0` | `FUN_0090dab0` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_Vehicle_StopHbAndZeroLongitudinal_Inferred` | function | `aa_00914c20` / `0x00914c20` | `FUN_00914c20` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_UI_RefreshInventoryWindows_Inferred` | function | `aa_00933310` / `0x00933310` | `FUN_00933310` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Character_GetEquipTfidTableCount_Inferred` | function | `aa_00522000` / `0x00522000` | `FUN_00522000` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |
| `TtPhantom_castRay` | function | `aa_00580ed0` / `0x00580ed0` | `FUN_00580ed0` | input-drive-control | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `MedalUI_PrepClearButtonSlots_Inferred` | function | `aa_0090c700` / `0x0090c700` | `FUN_0090c700` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `MedalUI_CountDisplayableEntries_Inferred` | function | `aa_0090c810` / `0x0090c810` | `FUN_0090c810` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Item_TinkerPrerequisiteGate_Inferred` | function | `aa_00513bc0` / `0x00513bc0` | `FUN_00513bc0` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `MissionSelect_ClearRowWidgetVectors_Inferred` | function | `aa_008ab340` / `0x008ab340` | `FUN_008ab340` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Item_GetTinkerSkillOrCap_Inferred` | function | `aa_00521eb0` / `0x00521eb0` | `FUN_00521eb0` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_NpcMissionDialogHost_Ctor_Inferred` | function | `aa_008ac3f0` / `0x008ac3f0` | `FUN_008ac3f0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Item_PatenteeMatchesCharacterOrEmpty_Inferred` | function | `aa_00522950` / `0x00522950` | `FUN_00522950` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `UI_MissionDialog_SetResponseCountAndRebuild_Inferred` | function | `aa_008ac890` / `0x008ac890` | `FUN_008ac890` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CNDHash_TraversalLock_Set_Inferred` | function | `aa_00402c40` / `0x00402c40` | `FUN_00402c40` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |
| `SoftCastHitList_CtorInitBuffer_Inferred` | function | `aa_0040c410` / `0x0040c410` | `FUN_0040c410` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred` | function | `aa_0040c6b0` / `0x0040c6b0` | `FUN_0040c6b0` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CNDHash_TraversalLock` | function | `aa_00411e10` / `0x00411e10` | `FUN_00411e10` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CNDHash_TraverseToNext_RegEdiEsi` | function | `aa_00411e40` / `0x00411e40` | `FUN_00411e40` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `SoftCastHitList_QuickSortRange_KeyFloat14_Inferred` | function | `aa_00489f20` / `0x00489f20` | `FUN_00489f20` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `SoftCastHitList_SortIfCountGt1_Inferred` | function | `aa_0048a060` / `0x0048a060` | `FUN_0048a060` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Character_ComputeReverseEngineerSuccessFraction_Inferred` | function | `aa_0052e640` / `0x0052e640` | `FUN_0052e640` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Character_TownInventoryFallback_Inferred` | function | `aa_004ce5c0` / `0x004ce5c0` | `FUN_004ce5c0` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Math_RoundFloatToInt_MissionXpBias_Inferred` | function | `aa_0040dab0` / `0x0040dab0` | `FUN_0040dab0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |
| `StdTree_EraseRange_Val12_InventoryGrid_Inferred` | function | `aa_00573700` / `0x00573700` | `FUN_00573700` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `gfxUIWindow_DetachParent_Inferred` | function | `aa_00756be0` / `0x00756be0` | `FUN_00756be0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `UiTextLayout_Finalize_Inferred` | function | `aa_00797530` / `0x00797530` | `FUN_00797530` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `UiOwnedBlock_CompleteBeforeDelete_Inferred` | function | `aa_00988710` / `0x00988710` | `FUN_00988710` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Character_GetXpRemainingToMaxLevelSoftCap_Inferred` | function | `aa_004111d0` / `0x004111d0` | `FUN_004111d0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `UI_InventoryWindow_TryEquipOrLockedToast_Inferred` | function | `aa_00861200` / `0x00861200` | `FUN_00861200` | inventory-transfer | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdList_PushBack_Dword_Inferred` | function | `aa_00402d10` / `0x00402d10` | `FUN_00402d10` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdList_Resize_EsiList_EaxCount_Inferred` | function | `aa_00402dd0` / `0x00402dd0` | `FUN_00402dd0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdVector_DestroyRuns_0x80_Inferred` | function | `aa_004271c0` / `0x004271c0` | `FUN_004271c0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |
| `gfxUIWindow_ScalarDeletingDtor` | function | `aa_004401b0` / `0x004401b0` | `FUN_004401b0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |
| `StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred` | function | `aa_00440ab0` / `0x00440ab0` | `FUN_00440ab0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred` | function | `aa_00440c90` / `0x00440c90` | `FUN_00440c90` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdTree_FreeSubtree_Isnil11_Inferred` | function | `aa_00440d20` / `0x00440d20` | `FUN_00440d20` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Client_UI_CreateNDUIDialogs_InstallHost_Inferred` | function | `aa_0093e7e0` / `0x0093e7e0` | `FUN_0093e7e0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdList_InsertN_BeforeNode_Dword_Inferred` | function | `aa_004034c0` / `0x004034c0` | `FUN_004034c0` | missions-progression | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdTree_EraseAll_Shell10_Inferred` | function | `aa_00441720` / `0x00441720` | `FUN_00441720` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `StdTree_EraseRange_Isnil11_Inferred` | function | `aa_00441960` / `0x00441960` | `FUN_00441960` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `Math_Vec3Length_Inferred` | function | `aa_0040d020` / `0x0040d020` | `FUN_0040d020` | interaction-activation | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High (role/CF) | none | mega residual |
| `CVOGMenu_ScalarDeletingDtor` | function | `aa_004166d0` / `0x004166d0` | `FUN_004166d0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |
| `CNDUIWindow_ScalarDeletingDtor` | function | `aa_00423e50` / `0x00423e50` | `FUN_00423e50` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |
| `CNDUIDialog_ScalarDeletingDtor` | function | `aa_004280d0` / `0x004280d0` | `FUN_004280d0` | skills-abilities | `client` | dual A/B 2026-08-05; mega residual dual 2026-08-05 | High | none | mega residual |

### Rename history (2026-08-05 mega residual)

| Date | Entity | From | To | Reason |
|------|--------|------|-----|--------|
| 2026-08-05 | aa_00520dc0 | `FUN_00520dc0` | `CVOGCharacter_CleanupDraggingObject` | mega residual dual evidence |
| 2026-08-05 | aa_00522060 | `FUN_00522060` | `Character_CountType1aCraftableBatches` | mega residual dual evidence |
| 2026-08-05 | aa_005310a0 | `FUN_005310a0` | `Character_GiveItemByCbid_Inventory_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_005787a0 | `FUN_005787a0` | `Skill_HB_RescheduleStatus_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00589bc0 | `FUN_00589bc0` | `Skill_HB_ApplyHeatDelta_Inferred` | mega residual dual evidence MERGE-MEGA-005 |
| 2026-08-05 | aa_00589c70 | `FUN_00589c70` | `Skill_HB_ApplyHpDelta_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00589d90 | `FUN_00589d90` | `Skill_HB_ApplyShieldPool_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0058cc40 | `FUN_0058cc40` | `Skill_HB_ApplyShortAndFloater_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0058d8e0 | `FUN_0058d8e0` | `Skill_HB_ApplyMultiArgEffect_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0092a590 | `FUN_0092a590` | `Tracker_SetActiveMissionObjective_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004bae00 | `FUN_004bae00` | `Host_DualCNDHash_TraverseNextObject_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00513eb0 | `FUN_00513eb0` | `Item_TryConcatStackWithPeer` | mega residual dual evidence |
| 2026-08-05 | aa_0052b350 | `FUN_0052b350` | `CVOGCharacter_RewardInventoryList_PushBack_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00578ac0 | `FUN_00578ac0` | `Skill_HB_ClearPtrVectorAt6b0_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_005d73a0 | `FUN_005d73a0` | `CVOGHBAIDriver_AxisPark_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0061b960 | `FUN_0061b960` | `Skill_HB_CopyTfid16At668_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00636ba0 | `FUN_00636ba0` | `CVOGHBMoveVehicle_OnEnd` | mega residual dual evidence |
| 2026-08-05 | aa_007f6db0 | `FUN_007f6db0` | `ActionMap_FindSlotByKeyMod_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_007f74a0 | `FUN_007f74a0` | `ActionMap_ClearAllSlotBindFields_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00802b70 | `FUN_00802b70` | `Client_SkillHB_OnEndUiCleanup_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0092f090 | `FUN_0092f090` | `MissionUI_ParkDriveAxes_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0092f710 | `FUN_0092f710` | `Client_LoadKeymapIni` | mega residual dual evidence |
| 2026-08-05 | aa_00930360 | `FUN_00930360` | `Client_SortTargetListByViewAngle_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_009373e0 | `FUN_009373e0` | `Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0059dc50 | `FUN_0059dc50` | `ObjectiveNode_IsEligibleForTracker_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_005fdf20 | `FUN_005fdf20` | `hkDefaultAnalogDriverInput_FilterSteer_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00938670 | `FUN_00938670` | `Client_Interact_OpenCVOGStore_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0040afb0 | `FUN_0040afb0` | `Host_LookupObjectByKey_PairTable30_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004bc530 | `FUN_004bc530` | `CNDHash_TraverseToNext_ListNext20` | mega residual dual evidence |
| 2026-08-05 | aa_004cc820 | `FUN_004cc820` | `MatchTargetEval_DefaultReturnFalse_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0060e800 | `FUN_0060e800` | `CVOGObjectiveRequirement_Patrol_EventAction_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_008e5990 | `FUN_008e5990` | `UI_CraftHost_BindResolvedObject_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0091a350 | `FUN_0091a350` | `Client_InteractWorldClick_SoftCastAlt_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00402850 | `FUN_00402850` | `StdTree_EraseAndRebalance_Isnil29_RetC_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00513400 | `FUN_00513400` | `Item_ValidateGadgetAttach_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00513c10 | `FUN_00513c10` | `Item_ValidateTinkerKitUse_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00581220 | `FUN_00581220` | `TtPhantom_CtorFromAabbDesc_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0060df70 | `FUN_0060df70` | `CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_006c6c50 | `FUN_006c6c50` | `CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00402b30 | `FUN_00402b30` | `StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00403c60 | `FUN_00403c60` | `StdTree_LowerBound_StringKey_Isnil131_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00405920 | `FUN_00405920` | `CsSList_RemoveFirstByPredicate_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00409bd0 | `FUN_00409bd0` | `StdSort_RanItStride16_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00409e20 | `FUN_00409e20` | `StdVector_ConstructN_Elem0x10_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00522020 | `FUN_00522020` | `Character_SelectInventoryGridByMode_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_008aa510 | `FUN_008aa510` | `MissionDialog_StampResponseSlot_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00403250 | `FUN_00403250` | `StdTree_InsertAndRebalance_Isnil31_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00403f30 | `FUN_00403f30` | `StdTree_Buynode_Val32_Isnil31_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00404e00 | `FUN_00404e00` | `CVOGPhysics_WriteNotFullyReadyOut_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00513fc0 | `FUN_00513fc0` | `Item_RequiresBindOrTradeLock` | mega residual dual evidence |
| 2026-08-05 | aa_008ab550 | `FUN_008ab550` | `Client_NpcMissionDialog_ApplyPanelMode_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004023f0 | `FUN_004023f0` | `StdList_DefaultCtor_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00404c60 | `FUN_00404c60` | `Object_Store16At80_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00409ed0 | `FUN_00409ed0` | `SkillSet_CopyBackward_0x18` | mega residual dual evidence |
| 2026-08-05 | aa_0040a600 | `FUN_0040a600` | `SkillSet_Vector_UninitializedCopy_0x18_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004f6a80 | `FUN_004f6a80` | `Inventory_ValidateEquipmentChange_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_005d5cc0 | `FUN_005d5cc0` | `CVOGWaypoint_DoFollowObjectShortcutsUpdate` | mega residual dual evidence |
| 2026-08-05 | aa_008aa4b0 | `FUN_008aa4b0` | `MissionDialog_SetNpcObjectAndNameCaption_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004025e0 | `FUN_004025e0` | `StdList_PushBack_Val0x28_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00404c00 | `FUN_00404c00` | `Math_Vec3_Length_Sqrt_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_005725a0 | `FUN_005725a0` | `InventoryGrid_CompleteDtor` | mega residual dual evidence |
| 2026-08-05 | aa_006ca890 | `FUN_006ca890` | `SoftCastHitList_CoreFillAndRegister_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0090cbc0 | `FUN_0090cbc0` | `MedalUI_RefreshPagedAchievementSlots_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00401c50 | `FUN_00401c50` | `StdMap_StringKey_InsertOrFind_Via401db0_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00401d30 | `FUN_00401d30` | `BasicStringFlag_CtorFromStringAndChar_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00401db0 | `FUN_00401db0` | `StdTree_InsertAndRebalance_Isnil2D_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00402280 | `FUN_00402280` | `StdList_Destroy_FreeHead_ViaClearEsi_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004d2e50 | `FUN_004d2e50` | `CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004d3ba0 | `FUN_004d3ba0` | `CVOGObject_EvalChildDeliverObjectiveInteract_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_005ebec0 | `FUN_005ebec0` | `VOGPhysics_SphereQueryCollect_Ctor_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_006c7fa0 | `FUN_006c7fa0` | `PhysicsShape_Sphere_CtorFromRadius_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0082d2b0 | `FUN_0082d2b0` | `UI_InteractionMenu_RebuildPopupShell_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0082f810 | `FUN_0082f810` | `UI_InteractionMenu_AddSendTell_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0082f8d0 | `FUN_0082f8d0` | `UI_InteractionMenu_AddIgnoreToggle` | mega residual dual evidence |
| 2026-08-05 | aa_0082f9a0 | `FUN_0082f9a0` | `UI_InteractionMenu_AddFriendsToggle` | mega residual dual evidence |
| 2026-08-05 | aa_0082fa60 | `FUN_0082fa60` | `UI_InteractionMenu_AddClanInviteOrKick_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0082fc40 | `FUN_0082fc40` | `UI_InteractionMenu_AddTrade_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_008aa490 | `FUN_008aa490` | `MissionDialog_SetTurnInReadyFlag_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00401f40 | `FUN_00401f40` | `StdTree_Buynode_StringByte_Isnil2D_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00402040 | `FUN_00402040` | `BasicStringFlag_CopyCtor_EdiSrc_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00418700 | `FUN_00418700` | `StdList_BuyNode_Dword_Seh` | mega residual dual evidence |
| 2026-08-05 | aa_00401c30 | `FUN_00401c30` | `StdVector_DwordSize_EaxVec_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00402ae0 | `FUN_00402ae0` | `StdMap_Find_Tfid_Isnil29_EaxMap_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0082fd50 | `FUN_0082fd50` | `UI_InteractionMenu_AddNameplateLabel_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_008e2d60 | `FUN_008e2d60` | `Client_UI_CraftHost_ResetRecipePanel_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0090d400 | `FUN_0090d400` | `UI_CloseRelatedChrome_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00929c00 | `FUN_00929c00` | `MissionTracker_ResetUiStateFields_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0092a3d0 | `FUN_0092a3d0` | `Tracker_ClearOwnedPtrVectorAt11c_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004027f0 | `FUN_004027f0` | `StdList_PushFront_DwordFromEax_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00570f70 | `FUN_00570f70` | `InventoryGrid_ClearItemsAndReEmptyCells_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0059db80 | `FUN_0059db80` | `CVOGObjective_ProbeEligibilityCode_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00573900 | `FUN_00573900` | `InventoryGrid_SetSecondaryOwner_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_005cc560 | `FUN_005cc560` | `CVOGHBAI_DecEntityA4SecondaryCounter_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00790020 | `FUN_00790020` | `Client_Input_KeyDown_UiGateAndForward_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0090c9a0 | `FUN_0090c9a0` | `MedalUi_ApplyAchievementSlotButton_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0090d390 | `FUN_0090d390` | `Client_Input_FindFirstActiveUiWindowTable5_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0090dab0 | `FUN_0090dab0` | `Client_Input_DismissUiWindowTable5_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00914c20 | `FUN_00914c20` | `Client_Vehicle_StopHbAndZeroLongitudinal_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00933310 | `FUN_00933310` | `Client_UI_RefreshInventoryWindows_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00522000 | `FUN_00522000` | `Character_GetEquipTfidTableCount_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00580ed0 | `FUN_00580ed0` | `TtPhantom_castRay` | mega residual dual evidence |
| 2026-08-05 | aa_0090c700 | `FUN_0090c700` | `MedalUI_PrepClearButtonSlots_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0090c810 | `FUN_0090c810` | `MedalUI_CountDisplayableEntries_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00513bc0 | `FUN_00513bc0` | `Item_TinkerPrerequisiteGate_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_008ab340 | `FUN_008ab340` | `MissionSelect_ClearRowWidgetVectors_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00521eb0 | `FUN_00521eb0` | `Item_GetTinkerSkillOrCap_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_008ac3f0 | `FUN_008ac3f0` | `Client_NpcMissionDialogHost_Ctor_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00522950 | `FUN_00522950` | `Item_PatenteeMatchesCharacterOrEmpty_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_008ac890 | `FUN_008ac890` | `UI_MissionDialog_SetResponseCountAndRebuild_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00402c40 | `FUN_00402c40` | `CNDHash_TraversalLock_Set_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0040c410 | `FUN_0040c410` | `SoftCastHitList_CtorInitBuffer_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0040c6b0 | `FUN_0040c6b0` | `CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00411e10 | `FUN_00411e10` | `CNDHash_TraversalLock` | mega residual dual evidence |
| 2026-08-05 | aa_00411e40 | `FUN_00411e40` | `CNDHash_TraverseToNext_RegEdiEsi` | mega residual dual evidence |
| 2026-08-05 | aa_00489f20 | `FUN_00489f20` | `SoftCastHitList_QuickSortRange_KeyFloat14_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0048a060 | `FUN_0048a060` | `SoftCastHitList_SortIfCountGt1_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0052e640 | `FUN_0052e640` | `Character_ComputeReverseEngineerSuccessFraction_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004ce5c0 | `FUN_004ce5c0` | `Character_TownInventoryFallback_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0040dab0 | `FUN_0040dab0` | `Math_RoundFloatToInt_MissionXpBias_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00573700 | `FUN_00573700` | `StdTree_EraseRange_Val12_InventoryGrid_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00756be0 | `FUN_00756be0` | `gfxUIWindow_DetachParent_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00797530 | `FUN_00797530` | `UiTextLayout_Finalize_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00988710 | `FUN_00988710` | `UiOwnedBlock_CompleteBeforeDelete_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004111d0 | `FUN_004111d0` | `Character_GetXpRemainingToMaxLevelSoftCap_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00861200 | `FUN_00861200` | `UI_InventoryWindow_TryEquipOrLockedToast_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00402d10 | `FUN_00402d10` | `StdList_PushBack_Dword_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00402dd0 | `FUN_00402dd0` | `StdList_Resize_EsiList_EaxCount_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004271c0 | `FUN_004271c0` | `StdVector_DestroyRuns_0x80_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004401b0 | `FUN_004401b0` | `gfxUIWindow_ScalarDeletingDtor` | mega residual dual evidence |
| 2026-08-05 | aa_00440ab0 | `FUN_00440ab0` | `StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00440c90 | `FUN_00440c90` | `StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00440d20 | `FUN_00440d20` | `StdTree_FreeSubtree_Isnil11_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0093e7e0 | `FUN_0093e7e0` | `Client_UI_CreateNDUIDialogs_InstallHost_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004034c0 | `FUN_004034c0` | `StdList_InsertN_BeforeNode_Dword_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00441720 | `FUN_00441720` | `StdTree_EraseAll_Shell10_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_00441960 | `FUN_00441960` | `StdTree_EraseRange_Isnil11_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_0040d020 | `FUN_0040d020` | `Math_Vec3Length_Inferred` | mega residual dual evidence |
| 2026-08-05 | aa_004166d0 | `FUN_004166d0` | `CVOGMenu_ScalarDeletingDtor` | mega residual dual evidence |
| 2026-08-05 | aa_00423e50 | `FUN_00423e50` | `CNDUIWindow_ScalarDeletingDtor` | mega residual dual evidence |
| 2026-08-05 | aa_004280d0 | `FUN_004280d0` | `CNDUIDialog_ScalarDeletingDtor` | mega residual dual evidence |

| UI_InventoryWindow_OnItemClickDispatch_Inferred | fn | 0x008612b0 | FUN_008612b0 | inventory/UI | gap-close dual 2026-08-05 | High | _Inferred |

| Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred | fn | 0x008c50f4 | FUN_008c50f4 | inventory/UI | gap-close dual 2026-08-05 | High | _Inferred |
