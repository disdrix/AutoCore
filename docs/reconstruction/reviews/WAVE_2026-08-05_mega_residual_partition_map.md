# Partition map - MEGA residual dual seal (2026-08-05)

| Field | Value |
|-------|-------|
| Work item | Mega residual dual partition from EXP-M / EXP-I / EXP-S / EXP-X / EXP-GAP / EXP-D explore worklists |
| Dual start | **2428** unique A/B |
| Rule | **One write owner per VA** (MEGA-NNN owns exactly one VA) |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; **no Launcher** |
| Rationale | Nested undualed callees of dualed WQ-001..009 managers; user-facing / state-mutating preferred; residual STL of dualed parents retained |
| Inputs | `wave_worklist_EXP-{M,I,S,X,GAP,D}.md` |
| Filters | Dedup highest-P; drop A/B dualed; drop depth-9 claimed set; drop Unwind/Catch/import thunks; drop trivial return-1 / EmptyStub |
| Count | **140** VAs / **140** agents |
| Cap | ~140 (quality pool after filters was 164; dropped lowest-priority residual leaves) |
| Terminal | **false** |

## Hard filters applied

1. **Dedup across lists** - same VA kept once at highest priority (sources merged).
2. **Already dualed A/B dropped:** `0x004c4e20`, `0x0058c3b0`.
3. **Depth-9 claimed set dropped (already dualed):**
   `00404000,00408ad0,00401bc0,00403e90,00403ee0,004043e0,0076c4d0,0078c3d0,007a8580,00424060,00759de0,00797d70,007aec70,007aff00,0082ce20,00415e90,007917c0,0083a860,0083a880,0083abf0`
4. **Trivial / non-VA dropped:** `0x00570710` (always-true post-merge), `0x004648a0` (EmptyStub), GAP catalog non-concrete rows (vtbl implementer catalogs, unbound call-site offsets without function entry VAs), EXP-D non-VA bundles / already-dual awareness rows.
5. **Prefer** user-facing / state-mutating over pure STL; STL residual leaves of dualed parents kept when still undualed.
6. **Rank by priority**, take top **140** (quality pool 164; 24 lowest deferred).

## Priority normalization

| Source scale | Normalized |
|--------------|------------|
| EXP-M / EXP-I / EXP-GAP numeric 1-100 | as-is (pure-math demote where noted) |
| EXP-S P0 / P1 / P2 / P3 | 95 / 84-86 / 70-74 / 62-68 |
| EXP-X High / Med-High / Med / Low-Med / Low | 91-93 / 86-87 / 76 / 66 / 55 |
| EXP-D P0 / P1 / P2 | 94 / 82 / 70 |

## Ownership (1 VA each)

| Agent | VA | P | System | Parent dual / context | Name hint |
|-------|-----|---|--------|----------------------|-----------|
| MEGA-001 | `0x00520dc0` | 96 | inventory-transfer | `named manager` | CVOGCharacter_CleanupDraggingObject |
| MEGA-002 | `0x00522060` | 96 | inventory-transfer | `0x005316c0` | Character_CountType1aCraftableBatches |
| MEGA-003 | `0x005310a0` | 96 | missions-progression | `0x0060d630,0x0060d540` | UseItem give-by-cbid / GiveItemByCbid+inventory |
| MEGA-004 | `0x005787a0` | 95 | skills-abilities | `0x0061b6f0` | Skill_HB_RescheduleStatus |
| MEGA-005 | `0x00589bc0` | 95 | skills-abilities | `0x0061b6f0` | Skill_HB_ApplyHeatDelta |
| MEGA-006 | `0x00589c70` | 95 | skills-abilities | `0x0061b6f0` | Skill_HB_ApplyHpDelta |
| MEGA-007 | `0x00589d90` | 95 | skills-abilities | `0x0061b6f0` | Skill_HB_ApplyShieldPool |
| MEGA-008 | `0x0058cc40` | 95 | skills-abilities | `0x0061b6f0` | Skill_HB_ApplyShortAndFloater |
| MEGA-009 | `0x0058d8e0` | 95 | skills-abilities | `0x0061b6f0` | Skill_HB_ApplyMultiArgEffect |
| MEGA-010 | `0x0092a590` | 95 | missions-progression | `0x0092fd00` | Tracker_SetActiveMissionObjective |
| MEGA-011 | `0x004bae00` | 94 | interaction-activation | `0x00490070` | pick-list / SelectBestPick residual |
| MEGA-012 | `0x00513eb0` | 94 | inventory-transfer | `0x00813730` | Item_TryConcatStackWithPeer |
| MEGA-013 | `0x0052b350` | 94 | missions-progression | `0x004d08c0` | Reward inventory list insert |
| MEGA-014 | `0x00578ac0` | 94 | skills-abilities | `0x00578ce0` | Skill_HB_ClearPtrVectorAt6b0 |
| MEGA-015 | `0x005d73a0` | 94 | input-drive-control | `HB AI follow` | AI axis park SetSteer/Long/HB+Push |
| MEGA-016 | `0x0061b960` | 94 | skills-abilities | `0x0061b6f0` | Skill_HB_CopyTfid16At668 |
| MEGA-017 | `0x00636ba0` | 94 | input-drive-control | `SetSteer caller` | axis-park: SetSteer(0)+PushDriveAxes |
| MEGA-018 | `0x007f6db0` | 94 | input-drive-control | `0x00911030` | ActionMap slot override lookup |
| MEGA-019 | `0x007f74a0` | 94 | input-drive-control | `0x007f8720` | ActionMap slot-field clear / prologue |
| MEGA-020 | `0x00802b70` | 94 | skills-abilities | `0x00578ce0` | Client_SkillHB_OnEndUiCleanup |
| MEGA-021 | `0x0092f090` | 94 | input-drive-control | `0x009438f0` | Mission-UI axis park thr0/steer0/HB1 |
| MEGA-022 | `0x0092f710` | 94 | input-drive-control | `keymap load` | keymap.ini loader |
| MEGA-023 | `0x00930360` | 94 | skills-abilities | `0x00943340` | Client_SortTargetListByViewAngle |
| MEGA-024 | `0x009373e0` | 94 | input-drive-control | `dialog UI park` | dialog gate thr0+steer0+HB |
| MEGA-025 | `0x0059dc50` | 93 | missions-progression | `0x0092fd00` | Objective-node eligibility gate for tracker |
| MEGA-026 | `0x005fdf20` | 93 | input-drive-control | `drive axis pipeline` | filtered steer / calcStatus |
| MEGA-027 | `0x00938670` | 93 | interaction-activation | `0x009247b0` | SetLongitudinal(0)+HB/flag109 interact |
| MEGA-028 | `0x0040afb0` | 92 | interaction-activation | `0x00925820` | resolve object* from soft-cast hit table |
| MEGA-029 | `0x004bc530` | 92 | interaction-activation | `0x004bae00` | TraversalLock walk payload node+0xc |
| MEGA-030 | `0x004cc820` | 92 | missions-progression | `0x0059d9c0` | MatchTarget eval stub default |
| MEGA-031 | `0x0060e800` | 92 | missions-progression | `0x0052da30 consumers` | Requirement Action fail-distance/flag (Patrol) |
| MEGA-032 | `0x008e5990` | 92 | inventory-transfer | `0x008e5ce0` | UI_CraftHost_BindResolvedObject |
| MEGA-033 | `0x0091a350` | 92 | interaction-activation | `0x00925820` | soft-cast / clear-select alternate |
| MEGA-034 | `0x00402850` | 91 | input-drive-control | `0x00911030` | OnKeyDown_MatchAction nested |
| MEGA-035 | `0x00513400` | 91 | inventory-transfer | `0x0085ce20` | Item_ValidateGadgetAttach |
| MEGA-036 | `0x00513c10` | 91 | inventory-transfer | `0x0085ce20` | Item_ValidateTinkerKitUse |
| MEGA-037 | `0x00581220` | 91 | interaction-activation | `0x004ea350` | GetObjectsInArea mode-1 box/list |
| MEGA-038 | `0x0060df70` | 91 | missions-progression | `caller of 0x0060d630` | UseItem object-event dispatch (9/10) |
| MEGA-039 | `0x006c6c50` | 91 | interaction-activation | `0x004ea350` | area-query filter bit test |
| MEGA-040 | `0x00402b30` | 90 | missions-progression | `NotifyActiveMissionChanged` | Named_CalleeOf NotifyActiveMissionChanged |
| MEGA-041 | `0x00403c60` | 90 | skills-abilities | `0x QuickBar_ActivateSlot` | QuickBar_ActivateSlot nested |
| MEGA-042 | `0x00405920` | 90 | inventory-transfer | `SendInventoryAddItem` | SendInventoryAddItem nested |
| MEGA-043 | `0x00409bd0` | 90 | interaction-activation | `0x00925d60` | PollBoundActions nested |
| MEGA-044 | `0x00409e20` | 90 | interaction-activation | `0x00925d60` | PollBoundActions nested |
| MEGA-045 | `0x00522020` | 90 | inventory-transfer | `0x00941b20` | Character_SelectInventoryGridByMode |
| MEGA-046 | `0x008aa510` | 90 | missions-progression | `0x009438f0` | Mission dialog response-slot clear / TFID stamp |
| MEGA-047 | `0x00403250` | 89 | missions-progression | `NotifyActiveMissionChanged` | Nested under NotifyActiveMissionChanged |
| MEGA-048 | `0x00403f30` | 89 | missions-progression | `NotifyActiveMissionChanged` | Nested under NotifyActiveMissionChanged |
| MEGA-049 | `0x00404e00` | 89 | skills-abilities | `RecvSkillStatusEffect` | RecvSkillStatusEffect nested |
| MEGA-050 | `0x00513fc0` | 89 | inventory-transfer | `0x00941b20` | Item_RequiresBindOrTradeLock |
| MEGA-051 | `0x008ab550` | 89 | missions-progression | `0x009438f0` | Select a Mission multi-mission panel fill |
| MEGA-052 | `0x004023f0` | 88 | missions-progression | `CVOGReaction_Dispatch` | Named_CalleeOf CVOGReaction_Dispatch |
| MEGA-053 | `0x00404c60` | 88 | skills-abilities | `skill invalid path` | Skill invalid creature/template string |
| MEGA-054 | `0x00409ed0` | 88 | skills-abilities | `SkillSet_GetEntryCount` | Named_CalleeOf SkillSet_GetEntryCount |
| MEGA-055 | `0x0040a600` | 88 | skills-abilities | `SkillSet_GetEntryCount` | Sibling SkillSet consumer |
| MEGA-056 | `0x004f6a80` | 88 | inventory-transfer | `0x00862d90,0x00862c00` | Inventory_HasSpaceForItem |
| MEGA-057 | `0x005d5cc0` | 88 | skills-abilities | `named plate` | CVOGHBAIWaypoint_DoFollowObjectShortcutsUpdate |
| MEGA-058 | `0x008aa4b0` | 88 | missions-progression | `0x009438f0` | dialog helper before thr/steer park |
| MEGA-059 | `0x004025e0` | 87 | missions-progression | `CVOGReaction_TransferMap` | Named_CalleeOf CVOGReaction_TransferMap |
| MEGA-060 | `0x00404c00` | 87 | missions-progression | `Mission Inventory plate` | Mission_Look_in_your_Mission_Inventory |
| MEGA-061 | `0x005725a0` | 87 | inventory-transfer | `0x00573910` | InventoryGrid_CompleteDtor |
| MEGA-062 | `0x006ca890` | 87 | interaction-activation | `0x0055e1e0` | soft-cast hit-list core |
| MEGA-063 | `0x0090cbc0` | 87 | missions-progression | `0x0080ff00` | Post-force-complete medal UI refresh |
| MEGA-064 | `0x00401c50` | 86 | missions-progression | `null dialog chain` | Mission_Attempting_to_open_null_dialog nested |
| MEGA-065 | `0x00401d30` | 86 | missions-progression | `null dialog chain` | Mission null dialog nested |
| MEGA-066 | `0x00401db0` | 86 | missions-progression | `null dialog chain` | Mission null dialog nested |
| MEGA-067 | `0x00402280` | 86 | missions-progression | `createNDUIDialogs` | Mission_createNDUIDialogs nested |
| MEGA-068 | `0x004d2e50` | 86 | interaction-activation | `0x004d7640` | child active/complete mission interact eval |
| MEGA-069 | `0x004d3ba0` | 86 | interaction-activation | `0x004d7640` | child/offer mission interact eval |
| MEGA-070 | `0x005ebec0` | 86 | interaction-activation | `0x004ea350` | sphere query collect |
| MEGA-071 | `0x006c7fa0` | 86 | interaction-activation | `0x004ea350` | sphere-shape setup (mode-2) |
| MEGA-072 | `0x0082d2b0` | 86 | skills-abilities | `0x0082fe20` | UI_InteractionMenu_RebuildPopupShell |
| MEGA-073 | `0x0082f810` | 86 | skills-abilities | `0x0082fe20` | UI_InteractionMenu_AddSendTell |
| MEGA-074 | `0x0082f8d0` | 86 | skills-abilities | `0x0082fe20` | UI_InteractionMenu_AddIgnoreToggle |
| MEGA-075 | `0x0082f9a0` | 86 | skills-abilities | `0x0082fe20` | UI_InteractionMenu_AddFriendsToggle |
| MEGA-076 | `0x0082fa60` | 86 | skills-abilities | `0x0082fe20` | UI_InteractionMenu_AddClanInviteOrKick |
| MEGA-077 | `0x0082fc40` | 86 | skills-abilities | `0x0082fe20` | UI_InteractionMenu_AddTrade |
| MEGA-078 | `0x008aa490` | 86 | missions-progression | `0x009438f0` | Dialog pre-present setup |
| MEGA-079 | `0x00401f40` | 85 | missions-progression | `null dialog chain` | Mission null dialog nested |
| MEGA-080 | `0x00402040` | 85 | missions-progression | `null dialog chain` | Mission null dialog nested |
| MEGA-081 | `0x00418700` | 85 | missions-progression | `0x0052b350` | Reward list node insert helper |
| MEGA-082 | `0x00401c30` | 84 | input-drive-control | `vehicle name plate` | Drive vehicle-name invalid plate |
| MEGA-083 | `0x00402ae0` | 84 | interaction-activation | `SendRespawnInSector` | Named_CalleeOf SendRespawnInSector |
| MEGA-084 | `0x0082fd50` | 84 | skills-abilities | `0x0082fe20` | UI_InteractionMenu_AddNameplateLabel |
| MEGA-085 | `0x008e2d60` | 84 | inventory-transfer | `0x008e5990` | UI_CraftHost_ResetRecipePanel |
| MEGA-086 | `0x0090d400` | 84 | skills-abilities | `0x0082fe20` | UI_CloseRelatedChrome |
| MEGA-087 | `0x00929c00` | 84 | missions-progression | `0x0092a590` | Tracker UI/state companion |
| MEGA-088 | `0x0092a3d0` | 84 | missions-progression | `0x0092a590` | Tracker clear/reset helper |
| MEGA-089 | `0x004027f0` | 83 | missions-progression | `RecvCreateCharacter` | Named_CalleeOf RecvCreateCharacter |
| MEGA-090 | `0x00570f70` | 83 | inventory-transfer | `0x005725a0` | InventoryGrid_FreeCellArray |
| MEGA-091 | `0x0059db80` | 83 | missions-progression | `0x0059dc50` | Nested eligibility probe |
| MEGA-092 | `0x00573900` | 82 | inventory-transfer | `0x004f3a30` | InventoryGrid_SetSecondaryOwner |
| MEGA-093 | `0x005cc560` | 82 | input-drive-control | `0x005d73a0` | follow-up after AI axis park |
| MEGA-094 | `0x00790020` | 82 | input-drive-control | `0x00911030` | key normalize / UI gate |
| MEGA-095 | `0x0090c9a0` | 82 | missions-progression | `0x0090cbc0` | Medal UI apply/toggle |
| MEGA-096 | `0x0090d390` | 82 | input-drive-control | `0x00911030` | Post-match branch callee OnKeyDown |
| MEGA-097 | `0x0090dab0` | 82 | input-drive-control | `0x0090d390` | Nested OnKeyDown helper |
| MEGA-098 | `0x00914c20` | 82 | input-drive-control | `stop/unstick` | stop HB + SetLongitudinal(0) |
| MEGA-099 | `0x00933310` | 81 | inventory-transfer | `0x0080d570` | Client_UI_RefreshInventoryWindows |
| MEGA-100 | `0x00522000` | 80 | inventory-transfer | `0x008e5ce0` | Character_GetEquipTfidTableCount |
| MEGA-101 | `0x00580ed0` | 80 | input-drive-control | `DriveControlTick secondary` | CVOGMap_CastRay / cast terrain sibling |
| MEGA-102 | `0x0090c700` | 80 | missions-progression | `0x0090cbc0` | Medal UI prep |
| MEGA-103 | `0x0090c810` | 80 | missions-progression | `0x0090cbc0` | Medal UI query/alloc |
| MEGA-104 | `0x00513bc0` | 79 | inventory-transfer | `0x00513c10` | Item_TinkerPrerequisiteGate |
| MEGA-105 | `0x008ab340` | 79 | missions-progression | `0x008ab550` | Select-mission list row helper |
| MEGA-106 | `0x00521eb0` | 78 | inventory-transfer | `0x00513c10` | Character_GetTinkerSkillOrCap |
| MEGA-107 | `0x008ac3f0` | 78 | missions-progression | `0x008ab8f0/0x009438f0 host` | Mission dialog host ctor |
| MEGA-108 | `0x00522950` | 77 | inventory-transfer | `0x0085ce20` | UI_ItemHover_FormatCraftStatus |
| MEGA-109 | `0x008ac890` | 77 | missions-progression | `peer 0x008ac110` | Response chrome rebuild peer |
| MEGA-110 | `0x00402c40` | 76 | interaction-activation | `0x0091b8d0` | TraversalLock set (fastcall) |
| MEGA-111 | `0x0040c410` | 76 | interaction-activation | `0x00925820` | soft-cast hit-list ctor / buffer init |
| MEGA-112 | `0x0040c6b0` | 76 | interaction-activation | `0x0091b8d0` | TraverseToNext TFID* node+0xc |
| MEGA-113 | `0x00411e10` | 76 | interaction-activation | `0x0091b8d0` | CNDHash TraversalLock set |
| MEGA-114 | `0x00411e40` | 76 | interaction-activation | `0x0091b8d0` | TraverseToNext payload node+8 |
| MEGA-115 | `0x00489f20` | 76 | interaction-activation | `0x0048a060` | hit-list sort implementation |
| MEGA-116 | `0x0048a060` | 76 | interaction-activation | `0x00925820` | sort soft-cast hits (count>1) |
| MEGA-117 | `0x0052e640` | 76 | inventory-transfer | `0x0085ce20` | UI_ItemHover_ApplyTooltipText |
| MEGA-118 | `0x004ce5c0` | 75 | inventory-transfer | `0x00862c00` | Character_TownInventoryFallback |
| MEGA-119 | `0x0040dab0` | 74 | missions-progression | `0x008ac540` | float XP to int for reward toast |
| MEGA-120 | `0x00573700` | 74 | inventory-transfer | `0x005725a0` | InventoryGrid_DestroyItemList |
| MEGA-121 | `0x00756be0` | 74 | skills-abilities | `0x00759de0` | gfxUIWindow_DetachParent |
| MEGA-122 | `0x00797530` | 74 | skills-abilities | `0x00797d70` | UiTextLayout_Finalize |
| MEGA-123 | `0x00988710` | 74 | skills-abilities | `0x00759de0` | UiOwnedBlock_CompleteBeforeDelete |
| MEGA-124 | `0x004111d0` | 73 | missions-progression | `0x008ac540` | Level-cap clamp for XP toast |
| MEGA-125 | `0x00861200` | 73 | inventory-transfer | `0x00941b20` | UI_InventoryWindow_OnEquipCommand |
| MEGA-126 | `0x00402d10` | 72 | missions-progression | `DebugListMissionsStatus` | Debug mission list nested |
| MEGA-127 | `0x00402dd0` | 72 | missions-progression | `DebugListMissionsStatus` | Debug mission list nested |
| MEGA-128 | `0x004271c0` | 72 | skills-abilities | `0x00797d70` | StdVector_DestroyRuns_0x80 |
| MEGA-129 | `0x004401b0` | 72 | skills-abilities | `0x00759de0` | gfxUIWindow_ScalarDeletingDtor |
| MEGA-130 | `0x00440ab0` | 72 | skills-abilities | `0x00759de0` | StdTree_ClearShell_At04 |
| MEGA-131 | `0x00440c90` | 72 | skills-abilities | `0x00759de0` | StdTree_ClearShell_At10 |
| MEGA-132 | `0x00440d20` | 72 | skills-abilities | `0x00759de0` | StdTree_ClearShell_AtA4 |
| MEGA-133 | `0x0093e7e0` | 72 | missions-progression | `UI init dialog host` | Client UI init dialog host install |
| MEGA-134 | `0x004034c0` | 71 | missions-progression | `DebugListMissionsStatus` | Debug mission list nested |
| MEGA-135 | `0x00441720` | 71 | skills-abilities | `0x00759de0` | StdTree_EraseAll_Shell10 |
| MEGA-136 | `0x00441960` | 71 | skills-abilities | `0x00759de0` | StdTree_EraseAll_ShellA4 |
| MEGA-137 | `0x0040d020` | 70 | interaction-activation | `0x009247b0` | pick ray/dist scale (pure math; demoted) |
| MEGA-138 | `0x004166d0` | 70 | skills-abilities | `0x0082d540` | CVOGMenu_ScalarDeletingDtor |
| MEGA-139 | `0x00423e50` | 70 | skills-abilities | `0x007b5be0` | CNDUIWindow_ScalarDeletingDtor |
| MEGA-140 | `0x004280d0` | 70 | skills-abilities | `0x00792c20` | CNDUIDialog_ScalarDeletingDtor |

## Deliverables per owned VA

1. Live decompile + read_memory (no disassemble_bytes). Prefer `disassemble_function` only if decompiler ABI is clearly wrong.
2. Trio: refresh raw (append re-verify section only - never wipe original capture) + annotated + **clean reconstructed-exact with meaningful names**.
3. Dual A_aa_* + B_aa_* with evidence, confirmations, residual gaps; verdict accept / accept-with-gaps / reject.
4. Function records (FUN + named when evidence).
5. **No parent ledger edits** (VERIFICATION_MATRIX, NAMING_REGISTRY, WORK_QUEUE, RESUME, ACTIVE_WORK, CHANGE_LOG, COVERAGE_LEDGER, progress.json, system maps).
6. Report: `docs/agents/task-dual-ab-<va>-megaNNN-report.md`.
7. Prefer domain names with string/RTTI evidence; else `_Inferred`. Never invent product names.

## Parent merge requirements (mandatory)

After duals land, parent MUST lockstep for **every** dualed VA:
- `VERIFICATION_MATRIX.md` row
- `NAMING_REGISTRY.md` entry + rename-history line
- Matching `systems/<system>.md` residual table entry
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER / ACTIVE_WORK

## Full VA list (script order = agent order)

Also: `docs/reconstruction/tmp/mega_residual_va_list.txt` (one `0x........` per line).

```
0x00520dc0
0x00522060
0x005310a0
0x005787a0
0x00589bc0
0x00589c70
0x00589d90
0x0058cc40
0x0058d8e0
0x0092a590
0x004bae00
0x00513eb0
0x0052b350
0x00578ac0
0x005d73a0
0x0061b960
0x00636ba0
0x007f6db0
0x007f74a0
0x00802b70
0x0092f090
0x0092f710
0x00930360
0x009373e0
0x0059dc50
0x005fdf20
0x00938670
0x0040afb0
0x004bc530
0x004cc820
0x0060e800
0x008e5990
0x0091a350
0x00402850
0x00513400
0x00513c10
0x00581220
0x0060df70
0x006c6c50
0x00402b30
0x00403c60
0x00405920
0x00409bd0
0x00409e20
0x00522020
0x008aa510
0x00403250
0x00403f30
0x00404e00
0x00513fc0
0x008ab550
0x004023f0
0x00404c60
0x00409ed0
0x0040a600
0x004f6a80
0x005d5cc0
0x008aa4b0
0x004025e0
0x00404c00
0x005725a0
0x006ca890
0x0090cbc0
0x00401c50
0x00401d30
0x00401db0
0x00402280
0x004d2e50
0x004d3ba0
0x005ebec0
0x006c7fa0
0x0082d2b0
0x0082f810
0x0082f8d0
0x0082f9a0
0x0082fa60
0x0082fc40
0x008aa490
0x00401f40
0x00402040
0x00418700
0x00401c30
0x00402ae0
0x0082fd50
0x008e2d60
0x0090d400
0x00929c00
0x0092a3d0
0x004027f0
0x00570f70
0x0059db80
0x00573900
0x005cc560
0x00790020
0x0090c9a0
0x0090d390
0x0090dab0
0x00914c20
0x00933310
0x00522000
0x00580ed0
0x0090c700
0x0090c810
0x00513bc0
0x008ab340
0x00521eb0
0x008ac3f0
0x00522950
0x008ac890
0x00402c40
0x0040c410
0x0040c6b0
0x00411e10
0x00411e40
0x00489f20
0x0048a060
0x0052e640
0x004ce5c0
0x0040dab0
0x00573700
0x00756be0
0x00797530
0x00988710
0x004111d0
0x00861200
0x00402d10
0x00402dd0
0x004271c0
0x004401b0
0x00440ab0
0x00440c90
0x00440d20
0x0093e7e0
0x004034c0
0x00441720
0x00441960
0x0040d020
0x004166d0
0x00423e50
0x004280d0
```

## Counts by system

| System | VAs |
|--------|----:|
| missions-progression | 41 |
| skills-abilities | 37 |
| inventory-transfer | 23 |
| interaction-activation | 23 |
| input-drive-control | 16 |
| **Total** | **140** |

## Top 10 priorities

| Rank | Agent | VA | P | Hint |
|-----:|-------|-----|---|------|
| 1 | MEGA-001 | `0x00520dc0` | 96 | CVOGCharacter_CleanupDraggingObject |
| 2 | MEGA-002 | `0x00522060` | 96 | Character_CountType1aCraftableBatches |
| 3 | MEGA-003 | `0x005310a0` | 96 | UseItem give-by-cbid / GiveItemByCbid+inventory |
| 4 | MEGA-004 | `0x005787a0` | 95 | Skill_HB_RescheduleStatus |
| 5 | MEGA-005 | `0x00589bc0` | 95 | Skill_HB_ApplyHeatDelta |
| 6 | MEGA-006 | `0x00589c70` | 95 | Skill_HB_ApplyHpDelta |
| 7 | MEGA-007 | `0x00589d90` | 95 | Skill_HB_ApplyShieldPool |
| 8 | MEGA-008 | `0x0058cc40` | 95 | Skill_HB_ApplyShortAndFloater |
| 9 | MEGA-009 | `0x0058d8e0` | 95 | Skill_HB_ApplyMultiArgEffect |
| 10 | MEGA-010 | `0x0092a590` | 95 | Tracker_SetActiveMissionObjective |

## Deferred (post-cap, still undualed - not owned this wave)

After ranking **164** unique undualed candidates, **24** lowest-priority residual leaves were deferred (mostly pure STL tidy/dtor, pure sqrt, vehicle flag notify, physics-deferred wheel units, debug-slash nested, low-value trampolines). Re-queue if parent dual residual still open after this wave.

## Honesty / shortfall

- Quality pool after hard filters: **164** unique undualed VAs (no invented addresses).
- Selected: **140** (cap ~140) - **above** 100 target.
- Dual filesystem check on 2026-08-05: only 2 explore-list VAs already A/B (`004c4e20`, `0058c3b0`).
- Non-concrete GAP catalog entries (vtbl implementer catalogs, unbound call sites without function entry VAs) were **not** invented into the map.

## Verdict language

accept / accept-with-gaps / reject. Never claim runtime Confirmed without Launcher. Terminal false.

## Agent isolation rules

1. Each MEGA-NNN may write duals **only** for its owned VA.
2. Do not dual callees of your VA (exclusive map - each residual VA has one owner).
3. Do not edit parent ledgers; dual plates + function records + agent report only.
4. Prefer Ghidra decompile + read_memory; no Launcher; no disassemble_bytes as primary path.

