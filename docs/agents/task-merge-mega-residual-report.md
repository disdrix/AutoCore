# MERGE-MEGA - Mega residual dual seal (parent)

| Field | Value |
|-------|-------|
| Agent | MERGE-MEGA |
| Date | 2026-08-05 |
| Wave | Mega residual dual seal |
| Partition | `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` |
| Dual unique A/B | **2428 -> 2567** (+139) |
| Mega sealed | **139 / 140** |
| Open residual | `0x00589bc0` MEGA-005 `Skill_HB_ApplyHeatDelta` |
| ADV | `ADV_mega_spotcheck.md` **8/8 PASS** |
| Terminal | **false** |
| Runtime Confirmed | **none** |

## Scope

Parent lockstep only. OWN agents MEGA-001..140 dual-sealed 139 VAs (one open). No re-dual of sealed units. No Launcher.

## Counts

| Metric | Value |
|--------|------:|
| Partition VAs | 140 |
| Dual A/B mega | **139** |
| Open mega residual | **1** |
| Pre-mega dual unique | 2428 |
| Post-mega dual unique (filesystem A/B) | **2567** |
| Matrix function rows | 324 -> **463** (+139) |
| Verdicts | accept 14 / accept-with-gaps 125 |

### By system (mega dualed)

| System | Dualed | Open |
|--------|-------:|-----:|
| missions-progression | 41 | 0 |
| skills-abilities | 36 | 1 (`0x00589bc0`) |
| inventory-transfer | 23 | 0 |
| interaction-activation | 23 | 0 |
| input-drive-control | 16 | 0 |

## Open residual

| Agent | VA | Hint | Reason |
|-------|-----|------|--------|
| MEGA-005 | `0x00589bc0` | Skill_HB_ApplyHeatDelta | A+B dual files not present under `reviews/` at parent merge; not invented |

## Sealed units (139)

| VA | Canonical name | A verdict | System |
|----|----------------|-----------|--------|
| `0x00520dc0` | `CVOGCharacter_CleanupDraggingObject` | accept-with-gaps | inventory-transfer |
| `0x00522060` | `Character_CountType1aCraftableBatches` | accept-with-gaps | inventory-transfer |
| `0x005310a0` | `Character_GiveItemByCbid_Inventory_Inferred` | accept-with-gaps | missions-progression |
| `0x005787a0` | `Skill_HB_RescheduleStatus_Inferred` | accept-with-gaps | skills-abilities |
| `0x00589c70` | `Skill_HB_ApplyHpDelta_Inferred` | accept-with-gaps | skills-abilities |
| `0x00589d90` | `Skill_HB_ApplyShieldPool_Inferred` | accept-with-gaps | skills-abilities |
| `0x0058cc40` | `Skill_HB_ApplyShortAndFloater_Inferred` | accept-with-gaps | skills-abilities |
| `0x0058d8e0` | `Skill_HB_ApplyMultiArgEffect_Inferred` | accept-with-gaps | skills-abilities |
| `0x0092a590` | `Tracker_SetActiveMissionObjective_Inferred` | accept-with-gaps | missions-progression |
| `0x004bae00` | `Host_DualCNDHash_TraverseNextObject_Inferred` | accept-with-gaps | interaction-activation |
| `0x00513eb0` | `Item_TryConcatStackWithPeer` | accept-with-gaps | inventory-transfer |
| `0x0052b350` | `CVOGCharacter_RewardInventoryList_PushBack_Inferred` | accept-with-gaps | missions-progression |
| `0x00578ac0` | `Skill_HB_ClearPtrVectorAt6b0_Inferred` | accept-with-gaps | skills-abilities |
| `0x005d73a0` | `CVOGHBAIDriver_AxisPark_Inferred` | accept-with-gaps | input-drive-control |
| `0x0061b960` | `Skill_HB_CopyTfid16At668_Inferred` | accept | skills-abilities |
| `0x00636ba0` | `CVOGHBMoveVehicle_OnEnd` | accept-with-gaps | input-drive-control |
| `0x007f6db0` | `ActionMap_FindSlotByKeyMod_Inferred` | accept-with-gaps | input-drive-control |
| `0x007f74a0` | `ActionMap_ClearAllSlotBindFields_Inferred` | accept-with-gaps | input-drive-control |
| `0x00802b70` | `Client_SkillHB_OnEndUiCleanup_Inferred` | accept-with-gaps | skills-abilities |
| `0x0092f090` | `MissionUI_ParkDriveAxes_Inferred` | accept-with-gaps | input-drive-control |
| `0x0092f710` | `Client_LoadKeymapIni` | accept-with-gaps | input-drive-control |
| `0x00930360` | `Client_SortTargetListByViewAngle_Inferred` | accept-with-gaps | skills-abilities |
| `0x009373e0` | `Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred` | accept-with-gaps | input-drive-control |
| `0x0059dc50` | `ObjectiveNode_IsEligibleForTracker_Inferred` | accept-with-gaps | missions-progression |
| `0x005fdf20` | `hkDefaultAnalogDriverInput_FilterSteer_Inferred` | accept-with-gaps | input-drive-control |
| `0x00938670` | `Client_Interact_OpenCVOGStore_Inferred` | accept-with-gaps | interaction-activation |
| `0x0040afb0` | `Host_LookupObjectByKey_PairTable30_Inferred` | accept-with-gaps | interaction-activation |
| `0x004bc530` | `CNDHash_TraverseToNext_ListNext20` | accept-with-gaps | interaction-activation |
| `0x004cc820` | `MatchTargetEval_DefaultReturnFalse_Inferred` | accept-with-gaps | missions-progression |
| `0x0060e800` | `CVOGObjectiveRequirement_Patrol_EventAction_Inferred` | accept-with-gaps | missions-progression |
| `0x008e5990` | `UI_CraftHost_BindResolvedObject_Inferred` | accept-with-gaps | inventory-transfer |
| `0x0091a350` | `Client_InteractWorldClick_SoftCastAlt_Inferred` | accept-with-gaps | interaction-activation |
| `0x00402850` | `StdTree_EraseAndRebalance_Isnil29_RetC_Inferred` | accept-with-gaps | input-drive-control |
| `0x00513400` | `Item_ValidateGadgetAttach_Inferred` | accept-with-gaps | inventory-transfer |
| `0x00513c10` | `Item_ValidateTinkerKitUse_Inferred` | accept-with-gaps | inventory-transfer |
| `0x00581220` | `TtPhantom_CtorFromAabbDesc_Inferred` | accept-with-gaps | interaction-activation |
| `0x0060df70` | `CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred` | accept-with-gaps | missions-progression |
| `0x006c6c50` | `CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred` | accept-with-gaps | interaction-activation |
| `0x00402b30` | `StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred` | accept-with-gaps | missions-progression |
| `0x00403c60` | `StdTree_LowerBound_StringKey_Isnil131_Inferred` | accept-with-gaps | skills-abilities |
| `0x00405920` | `CsSList_RemoveFirstByPredicate_Inferred` | accept-with-gaps | inventory-transfer |
| `0x00409bd0` | `StdSort_RanItStride16_Inferred` | accept-with-gaps | interaction-activation |
| `0x00409e20` | `StdVector_ConstructN_Elem0x10_Inferred` | accept-with-gaps | interaction-activation |
| `0x00522020` | `Character_SelectInventoryGridByMode_Inferred` | accept-with-gaps | inventory-transfer |
| `0x008aa510` | `MissionDialog_StampResponseSlot_Inferred` | accept-with-gaps | missions-progression |
| `0x00403250` | `StdTree_InsertAndRebalance_Isnil31_Inferred` | accept-with-gaps | missions-progression |
| `0x00403f30` | `StdTree_Buynode_Val32_Isnil31_Inferred` | accept-with-gaps | missions-progression |
| `0x00404e00` | `CVOGPhysics_WriteNotFullyReadyOut_Inferred` | accept-with-gaps | skills-abilities |
| `0x00513fc0` | `Item_RequiresBindOrTradeLock` | accept-with-gaps | inventory-transfer |
| `0x008ab550` | `Client_NpcMissionDialog_ApplyPanelMode_Inferred` | accept-with-gaps | missions-progression |
| `0x004023f0` | `StdList_DefaultCtor_Inferred` | accept-with-gaps | missions-progression |
| `0x00404c60` | `Object_Store16At80_Inferred` | accept-with-gaps | skills-abilities |
| `0x00409ed0` | `SkillSet_CopyBackward_0x18` | accept | skills-abilities |
| `0x0040a600` | `SkillSet_Vector_UninitializedCopy_0x18_Inferred` | accept-with-gaps | skills-abilities |
| `0x004f6a80` | `Inventory_ValidateEquipmentChange_Inferred` | accept-with-gaps | inventory-transfer |
| `0x005d5cc0` | `CVOGWaypoint_DoFollowObjectShortcutsUpdate` | accept-with-gaps | skills-abilities |
| `0x008aa4b0` | `MissionDialog_SetNpcObjectAndNameCaption_Inferred` | accept-with-gaps | missions-progression |
| `0x004025e0` | `StdList_PushBack_Val0x28_Inferred` | accept-with-gaps | missions-progression |
| `0x00404c00` | `Math_Vec3_Length_Sqrt_Inferred` | accept-with-gaps | missions-progression |
| `0x005725a0` | `InventoryGrid_CompleteDtor` | accept | inventory-transfer |
| `0x006ca890` | `SoftCastHitList_CoreFillAndRegister_Inferred` | accept-with-gaps | interaction-activation |
| `0x0090cbc0` | `MedalUI_RefreshPagedAchievementSlots_Inferred` | accept-with-gaps | missions-progression |
| `0x00401c50` | `StdMap_StringKey_InsertOrFind_Via401db0_Inferred` | accept-with-gaps | missions-progression |
| `0x00401d30` | `BasicStringFlag_CtorFromStringAndChar_Inferred` | accept-with-gaps | missions-progression |
| `0x00401db0` | `StdTree_InsertAndRebalance_Isnil2D_Inferred` | accept-with-gaps | missions-progression |
| `0x00402280` | `StdList_Destroy_FreeHead_ViaClearEsi_Inferred` | accept-with-gaps | missions-progression |
| `0x004d2e50` | `CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred` | accept-with-gaps | interaction-activation |
| `0x004d3ba0` | `CVOGObject_EvalChildDeliverObjectiveInteract_Inferred` | accept-with-gaps | interaction-activation |
| `0x005ebec0` | `VOGPhysics_SphereQueryCollect_Ctor_Inferred` | accept | interaction-activation |
| `0x006c7fa0` | `PhysicsShape_Sphere_CtorFromRadius_Inferred` | accept-with-gaps | interaction-activation |
| `0x0082d2b0` | `UI_InteractionMenu_RebuildPopupShell_Inferred` | accept-with-gaps | skills-abilities |
| `0x0082f810` | `UI_InteractionMenu_AddSendTell_Inferred` | accept-with-gaps | skills-abilities |
| `0x0082f8d0` | `UI_InteractionMenu_AddIgnoreToggle` | accept-with-gaps | skills-abilities |
| `0x0082f9a0` | `UI_InteractionMenu_AddFriendsToggle` | accept-with-gaps | skills-abilities |
| `0x0082fa60` | `UI_InteractionMenu_AddClanInviteOrKick_Inferred` | accept-with-gaps | skills-abilities |
| `0x0082fc40` | `UI_InteractionMenu_AddTrade_Inferred` | accept-with-gaps | skills-abilities |
| `0x008aa490` | `MissionDialog_SetTurnInReadyFlag_Inferred` | accept-with-gaps | missions-progression |
| `0x00401f40` | `StdTree_Buynode_StringByte_Isnil2D_Inferred` | accept-with-gaps | missions-progression |
| `0x00402040` | `BasicStringFlag_CopyCtor_EdiSrc_Inferred` | accept-with-gaps | missions-progression |
| `0x00418700` | `StdList_BuyNode_Dword_Seh` | accept | missions-progression |
| `0x00401c30` | `StdVector_DwordSize_EaxVec_Inferred` | accept | input-drive-control |
| `0x00402ae0` | `StdMap_Find_Tfid_Isnil29_EaxMap_Inferred` | accept-with-gaps | interaction-activation |
| `0x0082fd50` | `UI_InteractionMenu_AddNameplateLabel_Inferred` | accept-with-gaps | skills-abilities |
| `0x008e2d60` | `Client_UI_CraftHost_ResetRecipePanel_Inferred` | accept-with-gaps | inventory-transfer |
| `0x0090d400` | `UI_CloseRelatedChrome_Inferred` | accept-with-gaps | skills-abilities |
| `0x00929c00` | `MissionTracker_ResetUiStateFields_Inferred` | accept-with-gaps | missions-progression |
| `0x0092a3d0` | `Tracker_ClearOwnedPtrVectorAt11c_Inferred` | accept-with-gaps | missions-progression |
| `0x004027f0` | `StdList_PushFront_DwordFromEax_Inferred` | accept-with-gaps | missions-progression |
| `0x00570f70` | `InventoryGrid_ClearItemsAndReEmptyCells_Inferred` | accept-with-gaps | inventory-transfer |
| `0x0059db80` | `CVOGObjective_ProbeEligibilityCode_Inferred` | accept-with-gaps | missions-progression |
| `0x00573900` | `InventoryGrid_SetSecondaryOwner_Inferred` | accept-with-gaps | inventory-transfer |
| `0x005cc560` | `CVOGHBAI_DecEntityA4SecondaryCounter_Inferred` | accept-with-gaps | input-drive-control |
| `0x00790020` | `Client_Input_KeyDown_UiGateAndForward_Inferred` | accept-with-gaps | input-drive-control |
| `0x0090c9a0` | `MedalUi_ApplyAchievementSlotButton_Inferred` | accept-with-gaps | missions-progression |
| `0x0090d390` | `Client_Input_FindFirstActiveUiWindowTable5_Inferred` | accept-with-gaps | input-drive-control |
| `0x0090dab0` | `Client_Input_DismissUiWindowTable5_Inferred` | accept-with-gaps | input-drive-control |
| `0x00914c20` | `Client_Vehicle_StopHbAndZeroLongitudinal_Inferred` | accept-with-gaps | input-drive-control |
| `0x00933310` | `Client_UI_RefreshInventoryWindows_Inferred` | accept-with-gaps | inventory-transfer |
| `0x00522000` | `Character_GetEquipTfidTableCount_Inferred` | accept | inventory-transfer |
| `0x00580ed0` | `TtPhantom_castRay` | accept-with-gaps | input-drive-control |
| `0x0090c700` | `MedalUI_PrepClearButtonSlots_Inferred` | accept-with-gaps | missions-progression |
| `0x0090c810` | `MedalUI_CountDisplayableEntries_Inferred` | accept-with-gaps | missions-progression |
| `0x00513bc0` | `Item_TinkerPrerequisiteGate_Inferred` | accept-with-gaps | inventory-transfer |
| `0x008ab340` | `MissionSelect_ClearRowWidgetVectors_Inferred` | accept-with-gaps | missions-progression |
| `0x00521eb0` | `Item_GetTinkerSkillOrCap_Inferred` | accept-with-gaps | inventory-transfer |
| `0x008ac3f0` | `Client_NpcMissionDialogHost_Ctor_Inferred` | accept-with-gaps | missions-progression |
| `0x00522950` | `Item_PatenteeMatchesCharacterOrEmpty_Inferred` | accept-with-gaps | inventory-transfer |
| `0x008ac890` | `UI_MissionDialog_SetResponseCountAndRebuild_Inferred` | accept-with-gaps | missions-progression |
| `0x00402c40` | `CNDHash_TraversalLock_Set_Inferred` | accept | interaction-activation |
| `0x0040c410` | `SoftCastHitList_CtorInitBuffer_Inferred` | accept-with-gaps | interaction-activation |
| `0x0040c6b0` | `CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred` | accept-with-gaps | interaction-activation |
| `0x00411e10` | `CNDHash_TraversalLock` | accept-with-gaps | interaction-activation |
| `0x00411e40` | `CNDHash_TraverseToNext_RegEdiEsi` | accept-with-gaps | interaction-activation |
| `0x00489f20` | `SoftCastHitList_QuickSortRange_KeyFloat14_Inferred` | accept-with-gaps | interaction-activation |
| `0x0048a060` | `SoftCastHitList_SortIfCountGt1_Inferred` | accept-with-gaps | interaction-activation |
| `0x0052e640` | `Character_ComputeReverseEngineerSuccessFraction_Inferred` | accept-with-gaps | inventory-transfer |
| `0x004ce5c0` | `Character_TownInventoryFallback_Inferred` | accept-with-gaps | inventory-transfer |
| `0x0040dab0` | `Math_RoundFloatToInt_MissionXpBias_Inferred` | accept | missions-progression |
| `0x00573700` | `StdTree_EraseRange_Val12_InventoryGrid_Inferred` | accept-with-gaps | inventory-transfer |
| `0x00756be0` | `gfxUIWindow_DetachParent_Inferred` | accept-with-gaps | skills-abilities |
| `0x00797530` | `UiTextLayout_Finalize_Inferred` | accept-with-gaps | skills-abilities |
| `0x00988710` | `UiOwnedBlock_CompleteBeforeDelete_Inferred` | accept-with-gaps | skills-abilities |
| `0x004111d0` | `Character_GetXpRemainingToMaxLevelSoftCap_Inferred` | accept-with-gaps | missions-progression |
| `0x00861200` | `UI_InventoryWindow_TryEquipOrLockedToast_Inferred` | accept-with-gaps | inventory-transfer |
| `0x00402d10` | `StdList_PushBack_Dword_Inferred` | accept-with-gaps | missions-progression |
| `0x00402dd0` | `StdList_Resize_EsiList_EaxCount_Inferred` | accept-with-gaps | missions-progression |
| `0x004271c0` | `StdVector_DestroyRuns_0x80_Inferred` | accept | skills-abilities |
| `0x004401b0` | `gfxUIWindow_ScalarDeletingDtor` | accept | skills-abilities |
| `0x00440ab0` | `StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred` | accept-with-gaps | skills-abilities |
| `0x00440c90` | `StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred` | accept-with-gaps | skills-abilities |
| `0x00440d20` | `StdTree_FreeSubtree_Isnil11_Inferred` | accept-with-gaps | skills-abilities |
| `0x0093e7e0` | `Client_UI_CreateNDUIDialogs_InstallHost_Inferred` | accept-with-gaps | missions-progression |
| `0x004034c0` | `StdList_InsertN_BeforeNode_Dword_Inferred` | accept-with-gaps | missions-progression |
| `0x00441720` | `StdTree_EraseAll_Shell10_Inferred` | accept-with-gaps | skills-abilities |
| `0x00441960` | `StdTree_EraseRange_Isnil11_Inferred` | accept-with-gaps | skills-abilities |
| `0x0040d020` | `Math_Vec3Length_Inferred` | accept-with-gaps | interaction-activation |
| `0x004166d0` | `CVOGMenu_ScalarDeletingDtor` | accept | skills-abilities |
| `0x00423e50` | `CNDUIWindow_ScalarDeletingDtor` | accept | skills-abilities |
| `0x004280d0` | `CNDUIDialog_ScalarDeletingDtor` | accept | skills-abilities |

Names verified from live `A_aa_*` / `B_aa_*` review filenames (139/139 pairs present; 1 VA missing both).

## Ledger updates (parent)

1. `docs/reconstruction/VERIFICATION_MATRIX.md` - +139 function rows; summary **463**; mega residual dual index section
2. `docs/reconstruction/NAMING_REGISTRY.md` - mega residual rename table + 139 rename-history lines
3. `docs/reconstruction/systems/missions-progression.md` - mega residual section (41)
4. `docs/reconstruction/systems/inventory-transfer.md` - mega residual section (23)
5. `docs/reconstruction/systems/skills-abilities.md` - mega residual section (36 + open note)
6. `docs/reconstruction/systems/interaction-activation.md` - mega residual section (23)
7. `docs/reconstruction/systems/input-drive-control.md` - mega residual section (16)
8. `docs/reconstruction/WORK_QUEUE.md` - dual count 2567; mega residual seal note
9. `docs/reconstruction/RESUME.md` - dual 2567; next action open residual / next wave
10. `docs/reconstruction/CHANGE_LOG.md` - prepend mega residual parent entry
11. `docs/reconstruction/COVERAGE_LEDGER.md` - dual **2567**
12. `docs/reconstruction/coverage/progress.json` - dual_ab_pairs / dual_depth 2567
13. `docs/reconstruction/PROJECT_STATE.md` - last updated mega residual
14. `docs/reconstruction/ACTIVE_WORK.md` - mega nearly complete; open residual listed
15. `docs/agents/task-merge-mega-residual-report.md` - this report

## Notes

- Batch is nested residual of dualed managers across five high-priority systems (not a single-system depth wave).
- Residual gaps remain product demangle / runtime / bit-exact on most accept-with-gaps units.
- Do not invent dual for `0x00589bc0`; re-dispatch OWN dual if still needed.
- Next: optional dual for open residual; else next undualed residual claim; runtime only with Launcher approval.

