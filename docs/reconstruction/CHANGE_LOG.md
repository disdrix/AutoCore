# Change Log

## 2026-08-04 — WQ-007 residual dual seal (parent)

- Highest-priority non-deferred work item **WQ-007** (missions-progression, priority 96): dual residual undualed callees on MissionDialog / journal / GiveMission / CompleteObjective call chains (16 VAs, 8 OWN-ONLY agents WQ7R-A…H).
- Units: multi-active mission tip; dialog header caption; response-button build/clear; markup→richtext; token expand `[$name/class/race/credits/level]`; race/class display names; mselect entry ctor; dword vector push/insert; key-code display + action-map bind format; UseItem apply (GiveMission residual); MissionEscort OnHeartBeat (CompleteObjective/FailMission residual).
- Dual unique A∩B **2193 → 2209** (+16).
- Independent ADV: WQ7R-A PASS, WQ7R-C PASS, WQ7R-D PASS.
- Ledgers lockstep: **all 16** in `VERIFICATION_MATRIX.md` (+ summary 53 rows); **all 16** in `NAMING_REGISTRY.md` (2026-08-04 batch + rename history); **all 16** entry points in `systems/missions-progression.md`.
- Clean rewrites (not Ghidra paste): `CVOGHBMissionEscort_OnHeartBeat.cpp`, `MissionDialog_ParseMarkupToRichText_Inferred.cpp` (+ FUN twins).
- Experiments **108 passed** ×2. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-08-04_wq007_residual_partition_map.md`.

## 2026-08-04 — multi-agent wave 38 merge (parent)

- Concurrent OWN-ONLY duals (33 agents W38-A…AG, **65 VAs**): undualed callees of dualed managers — AssPreloader helpers (ext bucket, pop-front, erase), stoChunkReader text/binary readers + soft-skip, GBOD nested (phyBoundingBox, phySkeleton, CPDefinition/MorphWeight, bitvec, vector resizes), GfxDevice_Reset nested chain (effect factory lost/reset, buffered views, IB/VB factories, texture factory, stats monitor, present log, state cache), EffEffect find-param/create-load, media preload string vec, CSoundManager `.ogg`/`_lxx.ogg` append, map/tree iterators.
- Dual unique A∩B **2128 → 2193** (+65).
- Independent ADV spot-checks: W38-H PASS-WITH-FINDINGS (float3 stream order fixed to +0x14→+0x20→+0x00), W38-Q PASS, W38-AG PASS.
- Experiments **108 passed** ×2. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-08-04_wave38_partition_map.md`.

## 2026-08-04 — multi-agent wave 37 merge (parent)

- Concurrent OWN-ONLY duals (32 agents W37-A…AF, **63 VAs**): high-mention nested callees of dualed manager paths + wave36 residual PalToolNoMap pair (`0x0098fd80`/`0x0098df00`); includes AssPreloader drain/ctor, stoFileOSFile_Open, MissionTree media preload walk, GuardedVector dtor, StdVector Elem28/BasicStringW/RcElem28 helpers, CNDHash reclaim twins, GfxBody GBOD unserialize, GfxDevice_Reset, List_RemoveAll, loot tally, Object unload entry, Xform/scale, map insert/find, and related workers.
- Dual unique A∩B **2065 → 2128** (+63). Wave36 residual duals closed inside W37-A.
- Independent ADV spot-checks: W37-A (PASS-WITH-ISSUE — stage-2 WireColor prose corrected to green), W37-C PASS, W37-E PASS (+ sealed empty DDS quality suffix).
- Experiments **108 passed** ×2. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-08-04_wave37_partition_map.md`.

## 2026-07-29 — multi-agent wave 35 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W35-A…T, 40 VAs): GuardedVector EraseFirstEqual ThiscallRange; AssPreloader ProcessKeyRingStep; CircularSentinel Alloc0x14/0x10; NDResourceCache Ctor + CompleteDtor; Class 00aa05cc Ctor; Sto UnserialFactoryMap A/B GetInstance; NestedHash0x10 StaticOnceGet; HostPtrTable12 Bootstrap EDI; GfxMesh BuildNonInteriorEdgeIB; Host DrainPendingNfxEventQueue; RefCountedPtr3Flags DefaultCtor; StdList AllocSentinel 0x30; GlyphCache PlacementCtor; FourCCFnPtrMap TryInsert; Palantir BaseCtor + ResetDevice + ScalarDeletingDtor; PalantirSub10 DestroyOwnedPtrVecAndComUninit; StdUninitCopy/FillN/CopyBackward Pod28; Pod28 FillAssign; StdVector Resize Pod28; RcElem28 CopyCtor + UninitializedCopy + FillN + DestroyRange + AssignFill + AssignBackward; StdVector Resize/InsertOne RcElem28; GfxDevice Ctor; HostAux40 Ctor; Host34/54 NestedHash0xC Ctors; StdVector UninitializedCopy/FillN Elem28.
- Dual unique A∩B **1987 → 2027** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave35_partition_map.md`.
## 2026-07-29 — multi-agent wave 34 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W34-A…T, 40 VAs): Fs DeleteDirTreeRecursive; SpeedTreeRT ComputeTree; IdvFileError Ctor MsgBracketErrno; AssPathList ListBasenames FilterPush; EffDeviceEffect BindEffectParams; StdString OperatorPlus Char; NestedHashBag Ctor family (0x28/0x14/0x10/0x30/0xC/0x18 sentinels); Mem FillDwordN FromSrc; HeadBag Ctor Sentinel0x14; BasicString UninitializedFillN; Fs ReadPathListFileToStringVec; StringTable FindOrIntern u16; CNDAssetStringTable Unserialize; StringVec PushBackIfAbsent EnsureTrailingDirSep; StringVecShell TidyAndClearGlobal; Palantir CompleteDtor; BasicString CopyBackward 0x1c; GuardedVector EraseRange Thiscall + ResizeZeroFill; ParticleFluidPhase Ctor + InitFluidBumpChild + CreateFluidParticles + CreateLiquidChild; AnimEventVec InsertN; StdVector InsertN Pod28/RcElem28/Elem28/CountEcx/ValueEdx/BasicStringW; StdVector AssignFrom BasicString; CNDUIWndBuffered Ctor; PalantirEnv TearDefaultLights.
- Dual unique A∩B **1947 → 1987** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave34_partition_map.md`.
## 2026-07-29 — multi-agent wave 33 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W33-A…T, 40 VAs): StdTree Tidy FreeHead Bare Val12; Class 009c7948 ScalarDeletingDtor; CircularSentinel Alloc0x28; PtrVecShell InitFill; Fs PathIsDirectory Stat + ListDirBasenames; StringVec PushBack + Tidy; Fs ExpandPathSpecToStringVec; AssPackManager AddDirectoryTree + ExtractPackEntry + AddOrReplaceFile; StdString OperatorPlus Cstr/String; StdUninitCopy/FillN BasicString; StdVector DestroyRange/UninitializedCopy BasicString; BasicString FillAssignRange + CopyBackward Thunk; StdVector Elem28 Size; GuardedVector RingAssignForward + RingFillFromPtr + RingAssignBackwardChecked + Resize Thiscall + AssignLinearRangeAt; AssPreloader EnqueueEligibleFromCacheKeySpan + RetireStaleNeverLoaded; PodU32U8 StoreByValue; SideHost PushKeyFlag0/1; AssManager EnsureAssPreloader; AssPack ReleaseBlock Coalesce; Fs Path EnsureExtension; ListTrackedCtx ClearDestroyAndReset; PoolHost Acquire0x40; HostAux14 Ctor; ParticleFluidPhase Init; CVOGEnvironmentDistort/Reflect Enable.
- Dual unique A∩B **1907 → 1947** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave33_partition_map.md`.
## 2026-07-29 — multi-agent wave 32 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W32-A…T, 40 VAs): BasicString CopyEnsureTrailingDirSep; StringVec InsertOne; StdVector InsertN BasicString; StdTree Tidy FreeHead Val12 + EraseRange Val12; Class 009c7948 CompleteDtor; AssResolverA NestedHash Ctor; Fs DirRecurseCollectLeafPaths; AssResolverCore HeadBag Ctor; AssPackManager CompactPackFile; GuardedVector AssignDwordIfNonNull + InsertN Thiscall + PushBackLocked Thiscall + InsertRange + InsertRange Thiscall; MissionHost CollectMediaPreloads; Object CollectAllGraphicsPreloads; Weather NfxListFillOrActivate; AssPreloader TryPreloadChildAssets + EnqueueKeyAndDeps + ExpandDepsAndEnqueue + PreloadWorkerLoop; FillPreloadList; PreloadDep CollectTransitiveKeys; Pod8 CopyIfNonNull + PodU32U8 StoreSplit/CopyIfNonNull; GuardedVector PushBackLocked Stride2 U32U8; AssManager SweepTrackedAssets; HostBase DefaultCtor + EnsureAuxPtrs; StdList AllocSentinel 0xC; ListTrackedCtx Ctor; PalantirEnv ApplyDefaultScalars + RebuildDefaultLights + InitEffectTextures; WaterPhase Ctor + RegisterToken; CVOGPhaseDistort ctor; CVOGEnvironmentReflect ctor.
- Dual unique A∩B **1867 → 1907** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave32_partition_map.md`.
## 2026-07-29 — multi-agent wave 31 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W31-A…T, 40 VAs): StdTree FreeSubtree Val12 + StdTreeHost PtrVal CompleteDtor; OwningSList ClearDestroy ScalarDtor; EmptyDtorStub; GfxBody CompleteDtor; Host EnsureRegionCellOwned + ClearListTrackedOwnedInRect; Ctx ClearListTrackedOwnedAtScaledXY; Class 009c7938 ScalarDeletingDtor; StringVec PushFront EnsureTrailingDirSep; Palantir StartPreloadThread; ResourceCache SetField10AndConfigure; AssManager ResolverA Ctor + AssResolverCore Ctor; AssPackManager OpenPackFile; Client CompileEffectsBootstrap; GuardedVector PushBack/Front Thiscall + PushBack Stride2 U32x2/U32U8; AssPreloader EnqueueEligibleFromRing + IsKeyTrackedRecursive; Elem0x28 DefaultCtor; MapChild RebuildHostElemsAndIntGrid; CNDHash FreeBuckets twins; Host ResetHashQueuesVectors; StdMap LowerBound Tfid Isnil29; GfxView Ctor + SetNear; PalantirEnv Ctor + InitPhases; EnvSlot SetActiveBumpGen; Client InitRenderEngine; ObjectCsList CompleteDtor + Base ScalarDeletingDtor + ClearDestroyNoNode4; CVOGCharacter TryClearMissionCounterIfPositive; Client DebugCmd AddDisciplinePoints; Object UnloadGraphics.
- Dual unique A∩B **1827 → 1867** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave31_partition_map.md`.
## 2026-07-29 — multi-agent wave 30 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W30-A…T, 40 VAs): GuardedVector GrowBlockMap Thiscall/Stride2 + ContainsFirstEqual + PopFront + PopBack + PushBackLocked; Owner ClearDestroyGuardedPtrDequeAt28; AssManager InitPrecompileAndResolvers; PerfStatRings CommitAndTrim; StdList AllocSentinel 0x18; Client InitPalantirViewBundle; ObjectCsList ClearDestroy; CNDHash Recreate 009cb45c/009cb450; CVOGSpawnPoint ActivateFromStream; Object SetMissionStateFx; CVOGCharacter SetMissionCounter; PhysHost AttachObject + IslandHost Ctor; WorldObj UnbindOrDefer; Object FactoryRegisterListed + CompositeStopTypeF MIEntry; StdTree EraseAndRebalance Val12 + StdMap InsertOrFind IntKey peers; CrazyTaxi AccumulateLegTime; Client TryInventoryAutoMergePartialStacks Notify; Obj 009d95b4 ScalarDeletingDtor + DefaultCtor + CtorPopulate; StdTree Clear PtrVal Vtbl0C; ListTrackedObj CompleteDtor; Host Clear/Rebuild Elem0x28Array; Emitter ReleaseToFreelist; ObjectMotion SlotEmptyDtor + HostTeardown; CVOGHBAICreatureBase PathlessIdleRoam; Object TFIDMapLookupOrRelatedMatch; CVOGHB SlewFacingYaw OnHeartBeat.
- Dual unique A∩B **1787 → 1827** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave30_partition_map.md`.
## 2026-07-29 — multi-agent wave 29 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W29-A…T, 40 VAs): GuardedVector InsertN + ClearAndSwap + PushFront + PushBack; StdDeque ThrowTooLong; AssManager RemoveResolver + ReleaseOwnedResolvers; Map TreeInsert Val12 EsiBuy; StdTree Dec Val12; InventoryGrid AutoMergePartialStacks; Elem0x28 CompleteDtor; Class 009c7a1c ScalarDeletingDtor + Ctor; Object SharedBase Dtor; Object 009d33c4 Ctor + ScalarDeletingDtor; Color ClampRoundPackBGRA; Env ApplyFogShaderAndReflect; Object FwriteColorFields; UI FormatObjectDifficultyTier; CNDHash AllocBucketTable twins; CVOGHBAI EngageSelectTargetFromOwnerTFID; StdMap FreeSubtree + Dtor + InsertAlways IntKey; Object TeardownSecondaryFxList + RemovePrimaryFxEntry; StopTypeF MIThunk; CVOGHB FixedPeriod1 ctor; CVOGHBActivatePlayer OnEnd + EndOrDestroy; StdTree OperatorIndex Val12; LinkPair QuickSort DualKey; PhysHost ReconcileLinkPairs; PhysMgr AttachBody; WorldObj UnregisterAndRelease; PhysHost MergeSortedPairList; WorldObj AttachRegisterHost + SnapshotHostRefsAndUnbind.
- Dual unique A∩B **1747 → 1787** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave29_partition_map.md`.
## 2026-07-29 — multi-agent wave 28 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W28-A…T, 40 VAs): GuardedVector RingCopyElements + GrowAssignRangeCore + GrowBlockMap + RingAssignBackward + EraseFirstEqual + Resize + RingFillRange; BitStream HuffmanAlphabet CopyRange; Color LerpU8x3 + PackFloat4 Scale255 + LerpPackedARGB; Object ResolveTargetViaReaction; Object SetEnhancedStateFlag; CVOGHBActivatePlayer ctor; Object TeardownOwnedFxLists + StopTypeF ReloadEventVariant; Emitter UpdateTick; ObjectMotion SlotReleaseToFreelist; CNDHash Ctor 009cb45c + 009cb450; CVOGHB SlewFacingYaw ctor + CVOGHBAI ProfileType4 ctor; Object SetMode278 SelectFromTFID228; CVOGHBAI InvokeVtbl4c AimOffset Flag1; Class 009c7a1c CompleteDtor + Object 009d33c4 CompleteDtor; Obj BodyDtor SetVtbl DestroyStdListAt10; StdTree Inc/Min/Max Val12; StdMap EraseRange + InsertOrFind IntKey + InsertHint Val12; LinkPair CanonAndSort; LocalWorklist16 Init + Release; PhysSim LtBroadPhase; Map EraseRange Val12; StdTree Buynode Val12 EsiValue; StdMap InsertOrFind Val12 UintKey.
- Dual unique A∩B **1707 → 1747** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave28_partition_map.md`.
## 2026-07-29 — multi-agent wave 27 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W27-A…T, 40 VAs): FUN_0090f490 + FUN_008335a0 (math callers); BitStream HuffmanTree CopyRange; GuardedVector RingCopyRange + EraseRange + GrowAssignRange; NDSpecialFX StopFinalize; ObjectMotion SlotListTick + AdvanceStage + ApplyStageParams + SyncChildPoseHF; Object ActivatePlayerEnqueueHB; Object ResolveStoredTFID Vtbl1dc + PhysModeFromStoredTFID; GameUtils ParseRagDollBoneCount; Object CacheAIProfileFields TypeMask; Object EnsurePrimaryHBAI FromAIProfile; CVOGHBAI ProfileType4 DoLogic; Math Float3 IsFiniteIEEE + QuatExtractForwardZ OutFirst; CNDHash Remove 009cc1f0; StdList Destroy FreeHead; COList ScalarDeletingDestructor + Constructor; CVOGObject ComputeOutcomeRolls; Phys CommitPairListStorage; LinkPair SortedDiffWalk; LocalWorklist Release; WorldObj ReattachLinksGuarded + RehomeLinksFromSnapshot; WorldMgr RebindAllObjects; Map TreeInsert Val12 EsiBuy; StdTree Erase/Insert Val12 family clones (004e4130, 00539210, 005399f0, 00567450, 00573250, 00573510, 005ae4e0, 005ae990).
- Dual unique A∩B **1667 → 1707** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave27_partition_map.md`.
## 2026-07-29 — multi-agent wave 26 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W26-A…T, 40 VAs): Math Vec3NearlyEqual AbsRel + QuatNearlyEqual DoubleCover + QuatNormalize; BitStream HuffmanAlphabetEnsureCapacity + HuffmanTree EnsureCapacity + HuffmanAssignCodes; Perf QpcBeginNamed; WorldObj UnbindLinks + BindLinks; CVOGObject ApplyModeFlag RebindSwitchHBAI; Object SetTFID ApplyPhysMode Rebind; GameUtils createRagDoll; GuardedVector CopyAssign; NDSpecialFX List1e0 AnyFlag10 + LivenessDone; ObjectMotion SlotTick; Emitter SpawnOnIntervalTick; ThreadSafeObjectList ScalarDeletingDtor; CVOGSectorMap Destructor; COList Destructor; Object ApplySingleFxSlot NoSlotFilter ThenTeardown; NDSpecialFX Child ApplyFxToggle SlotFilter; CVOGObject FxPhysStartStop IfSlotNeg; Client CreateObjectFromCbidPacket + ProcessSectorUpdate; Material ReleaseAndNullField0x18; CVOGGraphicsBase PostLoadScaleAndSelectFx; Host AIProfileMap GetOrReset; Map LowerBoundFindByIntKey Isnil65; CVOGHBAI UpdateAimOffset; CNDHash ValueClearOwnedPtrs + Ctor 009ce1a0; StdTree Lrotate/Rrotate Val12; UI MissionJournal BuildMSelectChrome; TNL NetClassRepInstance Dtor; Client ApplyVehicleSwitch; CVOGCharacter TickUseObjectPending; CVOGHBPendingUseObject Stop + OnHeartBeat.
- Dual unique A∩B **1627 → 1667** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave26_partition_map.md`.
## 2026-07-29 — multi-agent wave 25 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W25-A…T, 40 VAs): CVOGCharacter ResolveUseObjectPending; MapFloatTfid EraseNode; Client Camera Modes257 ChaseUpdate + ModeDispatchUpdate; ThreadSafeObjectList Dtor; OleDb EnsureColumnInfoAndEnterBindings; Object ApplyDualFxSlots SlotFilterWild; NDSpecialFX ForEachHostPtrTablePair ApplyFxToggle; Character SwitchVehicle; Vehicle ActivateHardpointWeapons; CNDHash ReclaimAll ValueOwning + AllocBucketTable; Map TreeInsertAndRebalance Val12; UI MissionJournal ApplyStatusCompleteLabel; Object SurfaceDistance3D; CNDHash scalar dtor 009cfa7c; Mission ComputeObjectiveXpAsFloat; atexit NetClassRep rpcMsgGuaranteedOrdered; Object PlayPickupSpecialFX; CVOGHBAICreatureBase DoLogic; VehiclePhys Mode2Helper Ctor; Drive CollisionListener PrepBodyContact; EmptyBase Ctor ReturnThis; Item GetCycleTimeMs Scaled; hkAnalogDI CopyStringByKey; Vector InsertN 0x10; Skill HB SpawnEntities ctor; RefCountedPtr DefaultCtor; Phys StackDesc ResetFlag0 Float1000; Net SockaddrIn InitZero; netAddress CopyAssign; _com_error ScalarDeletingDtor; DES BuildIPFPLookupTables; Snd UpdateSounds UpdateSoundRegions; GuardedVector AssignTo; stoChunk ConvertToInteger; stoChunkReader ReadTextToken + ReadQuotedTag; Math FloatNearlyEqual AbsRel; BitStream HuffmanBuildTables.
- Dual unique A∩B **1587 → 1627** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave25_partition_map.md`.
## 2026-07-29 — multi-agent wave 24 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W24-A…T, 40 VAs): NDAssetImage ReleaseOwnedBuffers; NDSpecialFX BindHostRefreshAndWalkRelated; OleDb AllocCtxBlock; WorldObj RebindActivate; NDSpecialFX HostTick; ObjectMotion IntegrateStep; Client Camera DefaultModeUpdate; NDSpecialFX ForEachOwnedBit7 ApplyFxToggle; Object EntityBase Ctor; LogicUiEventQueue Resize; OleDb AllocBindingsBuf EnterBuild; CVOGSectorMap Constructor; Object SetRaceIdOwnerChain; Object DoFullInit; Skill InsertActiveCastBinding; CNDHash FreeBuckets; StdTree Buynode Val12; UI QuickBar AssignItemOrMacro / AssignItem; UI MissionJournal SelectMission / Row ApplySelection; CVOGCharacter TryEvalInteractObjectivesNearObject; CVOGRegionMissions ResyncMissionObjectives; MissionStagingTree EraseRange; CNDHash Dtor 009cfa7c; FreelistSlabVector dtor; SkillDef BuildFxMasterName; CloneBase Load; Tree RotateLeft/Right Isnil15; ActionManager NotifyListenersAndCompact; ActionHost RemoveReverseListEntry; Vehicle DeactivateHardpointWeapons; Client RecvObjectResolveWeaponReset 0x201c; WeaponHitResultVec PushBack; AnimSlot Ctor + BindResourceFromPath; ThreadSafeObjectList PopFront; Client ItemPickup AutoGatherTick; MapFloatTfid FreeSubtree Isnil29.
- Dual unique A∩B **1547 → 1587** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave24_partition_map.md`.

## 2026-07-29 — multi-agent wave 23 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W23-A…T, 40 VAs): RefCountedSlot ReleaseAndClear; NDAssetImage WriteAlphaPlaneByte; LogicUiEventQueue InsertN; Tree RotateRight; OleDb BuildBindingsAllocRow; NDAssetImage TransferFields; UI QuickBarSlotButton AssignSkill; StdVector InsertN Dword CountEcx; StdList Incsize; Client FlushWorldObjectState; StdMap InsertOrFind isnil15; Client LoadSkillsFX; Drive CollisionListener PlayCollisionEffect; CLoadNode initSpecialFX; NDSpecialFX DeactivateClear; CVOGObject Tick; StdMap EraseIterator; ClientSpecialEvent Respawn TeardownAirlift; EntityHost ApplyNestedLocalPosition; UI AppendItemRequirements; Object EntityMidBase Ctor; Combat ComputeBaseCritChance FromHost; PhysSim LtSimulate Collide; CNDHash InsertDualKey; CVOGReaction ScanPendingDeliverAndRegisterLinks; RbTree InitEmptyHeader Node1c; Client UI MapView DrawMarkers/Entities FOV overlay; Math QuatInverseRotateDelta; Client Map RaySegmentHitDistance; ActionManager UnregisterAndRelease; GetModifierSkillID; NDSpecialFX ExpandVehicleHardpointSlots; CVOGHBBase ScalarDeletingDtor; Object IsLevelLessThan6; CVOGHBBase AppendRemainingText; CVOGHBSkillBase DefaultCtor; CVOGHBRespawnCharacter ctor; CVOGHBMissionPatrol ctor; LockedList TryAdvanceIterator Loot.
- Dual unique A∩B **1507 → 1547** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave23_partition_map.md`.

## 2026-07-29 — multi-agent wave 22 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W22-A…T, 40 VAs): Combat ComputeCritChance; Skill ApplyBoundStatusMotionTable; StdTree IteratorIncrement isnil49; Object SharedBase Ctor; InventoryGrid CommitPlacementMap; Object WriteComposedMatrix; QuickBar RebindPageColumns; BitStream GrowForBits; StdMap string/int key InsertNodeAndRebalance; Ui WriteFormatColorD3d; UiWidget TeardownIfActive; Win32 ThrowLastErrorAsHresult; UiToast UninitializedCopy 0x98 (×2 helpers); CVOGObject JustCreatedInit; LogicUiEventQueue InsertOneGrowPath; Drive CollisionListener Contact; CVOGHBRecreateObject RecreateOwner; CVOGCreature SlewFacingYaw; CNDHash FreelistPop Node0x28; UI ItemDetailPanel Refresh; gfxVertexBufferImpl Allocate; Com BstrHolder Release; Com LoaderCtx NestedTeardown; SkillRow UninitializedFillN 0x934; OleDb RowBufZeroAndCreateAccessor; TNL GroupReactionCall UnpackData; StdTree IteratorDecrement; NDAssetImage TGA row decode / RLE / by-format; CxImage Create; stoChunkReader TextReadU32 + ReadU32 ModeDispatch; RbTree InitEmptyHeader; SkillSet UninitializedCopy 0x18; Phy CPConnectionPair ReleaseClear; Mem FillDwordN / MoveDwordRange ReturnEnd.
- Dual unique A∩B **1467 → 1507** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave22_partition_map.md`.

## 2026-07-29 — multi-agent wave 21 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W21-A…T, 40 VAs): CVOGHBBase dtor + EndOrDestroy soft-mark epilogue; Object ApplyFxWithTargetBind; InventoryGrid RePlaceItems; Skill HB FireTail FxTargetAndPeriodStamp; BitStream writeString; HandlerTable58 FindById6c; CNDHash Insert 009ce0a0; StdDeque ThrowTooLong; Character ClearEquippedRaceItemTfId; Client IsLocalMissionJournalReady; CVOGCreature ctor; StdMap InsertWithHint IntKey; XmlAttr FetchParseLong StoreByteIfOk; Skill ApplyBoundStatusMotionIfPresent; Vehicle ApplyHardpointFireMask; Combat RollCritMultiplier; TimerHost GetTimeFloat; AnimSlot SetTime; CVOGObjective SetCompleteCount; TNL NetClassRepInstance Ctor; Mem CopyBytes; GfxVBHolder ReplaceAndAllocate; Rng Source ExtractU32; Mem Move200B Blocks; CSoundManager ProbeSoundFileExists; NDResource DecRef; HashMap FindIterator; Bounds AccumulateTransformedLocal; RbTree AllocEmptyNode 0x30; StdMap StringKey InsertOrFind; ActionMap TrySetSlotBind; Client TryBindActiveMissionTracker; UI MissionPanel SyncSlotVisibilityAndLayout; CDlgQuickBar CreateChildWidgets + CycleSelectValidColumn; UiHost FindTrackedPairNode + RefreshTrackedNodeWidgets; UI RefinePanel InsertCommodityListRow; NpcMissionDialog TeardownChildWidgetLists.
- Dual unique A∩B **1427 → 1467** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave21_partition_map.md`.

## 2026-07-29 — multi-agent wave 20 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W20-A…T, 40 VAs): CVOGHB targeting-link complete dtor; Client AppFrameTick; SkillElementTypeMap TreeInsertAndRebalance; PhysSim MergeHosts; Outpost PreRecastBankWalk; MT19937 Extract; stoChunkWriter WriteU32; Outpost CaptureOutpost; phyBone shared install + qs copy; mission tracker HUD refresh; UI inventory panel message handler; StdVector ThrowTooLong twin; UiToast UninitializedFillN; Mem MoveDwordRange ToExclusiveEnd; Weapon SelectMultiTargets; FxCache ApplyWithNfxEnsure + EnsureMasterAndResolve; OLE IAccessor CreateAccessor free bindings; BitStream writeQuantizedSignedInt + readString; NDAssetImage Flip + FlipHorizontal; std::length_error ctor; StdList BuyNode; CVOGObject SetGfxBodyLink Mode1; StdMap FreeSubtree; Skill HB SpawnEntities Precheck; CVOGObject GetActivePositionPtr; Item CharacterMeetsUseReqs; Host ScreenToTerrainHitNotify; CsSList ContainsPayload; Skill ApplyMultiTargetHits; Client SelectHostileUnderScreenPick; HandlerTable FindById; CVOGHBBase EndOrDestroy hard unlink; InventoryGrid SortAndRepack; CVOGHBBase SetPartnerLink; Object RefreshSkillHash; SkillTree RemoveBySkillId.
- Dual unique A∩B **1387 → 1427** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave20_partition_map.md`.

## 2026-07-29 — multi-agent wave 19 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W19-A…T, 40 VAs): MT19937 Seed; Vehicle UpdateWeaponHardpoints3; StdVector ThrowTooLong; StdFill DwordRange; Mem MoveDwordRange; Client DispatchUiEventQueue; CNDHash BucketChainTouchRepair; Profiler ScopeLeave; Object RegisterListed; Skill SpawnTemplateAndStartHB; CloneBase AllocAndLoadByType; Character HostModeGateForObjectV210; CVOGHBWakeupSkill ctor; targeting-link scalar dtor; Item SetCustomized + SumEquippedComponentValues; Map EraseNode; Client InteractPrompt SetTarget; CVOGCharacter SetLevelWithFlags; StdMap InsertOrFindByIntKey; Tree RotateLeft; CNDHash reclaim owning/non-owning variants; SkillElementTypeMap InsertOrFind; WorldCast setup+dispatch; PhysSim FlushPendingBodyPairs; Object PurgeSkillHBListChain; Map Tree Predecessor; Outpost UpdateBeaconShareRatio; Host ActionList Push; CVOGHBAIBase SetFloat; DES S-box + P-perm tables; stoChunkWriter WriteI32; stoChunkReader PeekChunkTag; NDResource Ctor; Client ApplyPairRelativeTransform; NDXml FinishLoadResult; StatusFlag GetDisplayName; Client SendInventoryEquipC2S.
- Dual unique A∩B **1347 → 1387** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave19_partition_map.md`.

## 2026-07-29 — multi-agent wave 18 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W18-A…T, 40 VAs): stoChunk stream Ensure/ReadBytes/ReadU32; CVOGHBBase empty vfunc; CsSList append payload; Client SendGlobalPacket; SkillDefMap GetGlobal; Object LoadOrReplaceAnimSlot; OLE CommandExecute IRowset; NDResource default type token; CircularPtrBuf Grow; Math Matrix4x4 Set16; CSoundManager tick hard-kill/regions + RequestPlay + mission-complete sound; NDSpecialFX Ctor; Profiler ScopeEnter; Creature GetPerception; Client InitInstance; CVOGHBWakeupSkill Fire; cast-state teardown; CompleteRegionMissions; CNDHash reclaim/InsertAlways/unlink u64; MT19937 Twist; interact prompt refresh; Map ConstructIntKeyNode; Audio LinearGainToMilliBels; OwnedPtrTable Clear; Timer CalibrateTscPerSec; StdVector PushBack12 / Dword InsertN; hardpoint mode match; optional TRS matrix; character create apply attach vehicle; RB tree alloc empty node; skill HB spawn entities; Object ResolveCoid vtbl+0x1e8; AllocateNewObjectFromCbid.
- Dual unique A∩B **1307 → 1347** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave18_partition_map.md`.

## 2026-07-29 — multi-agent wave 17 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W17-A…T, 40 VAs): dual-key list find; mission dialog control dispatch; Vec3_Copy; CVOGRegionMissions ctor; Client InteractWorldClickHub; Net SockaddrIn_Init; stoChunkReader LeaveChunk/readF32/soft-skip + writer indent + stream header16; GameData LookupCloneBaseByCbid; Object HasFlag8SelfOrLinked; Character TryEquipItem; UI DefaultMessageHandler; errReport Dispatch; MSXML NamedNodeMap GetNamedItemText; Client ClearObjectReferences; ClientCamera ApplyModeDistanceBand; NDXml GetLoaderSingleton; Creature GetTheory; Object EnqueueDeferredOnce; CVOGLootGenerator GetOrCreate; CNDHash freelist reclaim; CVOGHBToken OnEnd; Path GetFileName + PathMap HasBasename; Client DismissModalPrompt; UI QuickBar SetSelected; `_CxxThrowException`; Math CopyFloat4; Object GetTargetAccuracyBase; EmptyRet; Phys ActionBase ctor; Map InsertNodeAndRebalance IntKey; CVOGObjectiveRequirement ctor; Profiler TimerBlock/Zone ctors; Object ResolveTfIdVtbl1d4; Client TeardownGameplaySession.
- Dual unique A∩B **1267 → 1307** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed** (fixed `FUN_004a0b90.cpp` undefined4 gate). Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave17_partition_map.md`.

## 2026-07-29 — multi-agent wave 16 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W16-A…T, 40 VAs): weapon try-fire + apply-damage; CVOGPhysics apply point impulse; dword fill-n; loot catalog type→row + RNG bias + int-range merge; vehicle paint color ensure; sector-map character-enter level index; combat floater copy range 0x38; locked-list insert tail; OLE walk active bindings; std vector insert-one; std tree alloc node 0x1c; CSoundManager stopSound/ctor/erase named record; circular ptr push 0x14; hash COID lookup; CVOGHBAICreatureBase::DoMovement; COM clear slot + ReleaseIfNonNull; stoChunkWriter WriteFormatted; NDSpecialFX instantiate + ParseXmlEventNode; MBCS from wide; interact SelectBestPickTarget; UseItem MatchTargetCore; CNDHash u64 bucket find; IsPlayerTargetingLinkAndDestroy; mission interact offer staging; `_com_raise_error`; Net SockaddrIn InitInvalid; netSocket GetPeerAddress + Address trivial dtor; Timer RDTSC seconds; character skill-bag upsert/reapply; UI toast construct-n 0x98; vector erase-range dword; FourCC dword→std::string.
- Dual unique A∩B **1227 → 1267** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave16_partition_map.md`.

## 2026-07-29 — multi-agent wave 15 merge (parent)

- Concurrent OWN-ONLY duals on loot catalog residual, combat floater relocate, vehicle track/soft-pose/create-msg, sector equip leave/remove/paint, garage refine/filter, mission EnsureXml string twins + objective XML + continent markers, XML parse helpers, FreeBuckets/scalar dtors, COM/vector/world enroll, skill DB load nested OLE/COM, multi-hit combat nested, vehicle net skills HB vector residual, skill apply/math leaves.
- Dual unique A **1131 → 1227** (+96). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave15_partition_map.md`.

## 2026-07-29 — multi-agent wave 14 merge (parent)

- Concurrent OWN-ONLY duals on loot generate residual (profile/mod/quality/catalog/hit/deferred), medal table load + CNDHash recreate/insert, mission complete rebind/register, vehicle net map/deque, container grow/locale/COM, character hash recreate/dtor, combat floater/level-up residual, skill def tree/XML, mission staging tree, inventory COID residual, drive secondary fire/enter-world nested, net skills HB pack/unpack, UI hash recreate/gauge ctors.
- Dual unique A **1041 → 1131** (+90). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave14_partition_map.md`.

## 2026-07-29 — multi-agent wave 13 merge (parent)

- Concurrent OWN-ONLY duals on SpecialFX residual, multi-target combat apply, FxMaster catalog/XML load, radial force impulse, vehicle ghost net residual, kill-loot/credit/convoy chain, audio freelist/path/busy, CNDHash RemoveAll/AllocBuckets twins, skill RNG/string-pool, medal/reward complete path, equip nested melee/FX, container/list/vector helpers.
- Dual unique A **949 → 1041** (+92). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave13_partition_map.md`.

## 2026-07-29 — multi-agent wave 12 merge (parent)

- Concurrent OWN-ONLY duals on SpecialFX residual, weapon FX pack, CSoundManager family, select/garage UI, phys action lists, cast FormatFailure/CD map helpers, inventory cell/window/equip hooks, VehicleNet unpack + BitStream string cache, NDUI widget ctors, CNDHash ctor/alloc/removeAll, DB enter/leave for XP ensure wrappers, mission resource/event gates.
- Dual unique A **883 → 949** (+66). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave12_partition_map.md`.

## 2026-07-29 — multi-agent wave 11 merge (parent)

- Concurrent OWN-ONLY duals on weapon/FX fire chain, inventory sheet rebuild (lock/iterate/clear/collect page), select UI residual, combat-pool level scale, flipper HB + phys register, CNDHash remove/destroy/freelist family, mission pending-objective ensure + node dtors/integrity walk.
- Dual unique A **842 → 883** (+41). Imports **201** (FF25 pool exhausted). Thunks **67** (E9 pool exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave11_partition_map.md`.

## 2026-07-29 — multi-agent wave 10 merge (parent)

- Concurrent OWN-ONLY duals on GatherTargetsInArea chain, mission CNDHash insert twins, physics prepare/activate/setPosition, transform/ortho/cast-ray math, inventory sheet/hash UI, toast grow/locale, targeting HB vtbls, client input residual (unstick/HB park/select), VehicleNet soft pose integrate/apply, weapon fire helper, float-keyed target maps.
- Dual unique A **783 → 842** (+59). Imports **188 → 201** (pure FF25). Thunks ledger formalized (67 pure E9).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave10_partition_map.md`.

## 2026-07-29 — multi-agent wave 9 merge (parent)

- Concurrent OWN-ONLY duals on DriveControlTick physics chain, HF sample, quat basis extractors, targeting HB, progress dismiss, mod-chip lookup, inventory sheet UI, locale/string pool, GiveMission toast/blob/hash, profiler internals, CNDHash insert/remove, skill-load insert.
- Dual unique A **745 → 783** (+38). Imports **177 → 188** (pure FF25).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave9_partition_map.md`.

## 2026-07-29 — multi-agent wave 8 merge (parent)

- Concurrent OWN-ONLY duals on DriveControlTick / RequestCast / Grab / ResolveTargets / Equip callees missing A/B.
- Dual unique A **701 → 745** (+44). Imports **171 → 177** (pure FF25).
- Highlights: world-pos ptr, physics angular/vector apply, gated local pos, HF sample/march, CVOGHBBase_Stop, SetSelectedTarget, Weapon fire flags, mod-chip use `0x202c`, random up-kick, timed progress bar, chat toast sink, NDError_Log (enable==1), Profiler enter/leave, SkillDef map materialize, vehicle equip spine, inventory sheet UI.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave8_partition_map.md`.

## 2026-07-29 — multi-agent waves 6–7 merge (parent)

- **Wave 5 residual closed:** `0x00504c70` setDrivingInputs/throttle, `0x00512870` EnsureQuestBaseCredits, `0x00571b80` InventoryGrid_RemoveItem dual-sealed.
- **Wave 6 duals:** UI CreateChildWidgets (Arena/Trade/CharSheet), NDUIWindow/NDXml load chain, stoChunk Begin/End/Open/readF32, NDSpecialFX, TimedAction, Respawn Update, AttrPointClick (0x205A), DES full Feistel chain, gfx GPCE/INDX/VERT, vog_LogMessage, AutoPatrol `0x00929ec0`.
- **Wave 7 duals:** BitStream quant float, EnterChunkScope, Object_ResolveFromTFID, VehicleNet_PackUpdate, EMSG Damage `0x2023`, TNL ByteBuffer/Socket, 17 hk vehicle components, UI tooltip stats, special-event ctors, COM helpers.
- **Trivial-batch:** imports **121→171** (+ pure IAT); thunks **56→67** (+ pure E9).
- Dual unique A **~613 → 701**. Experiments **108 passed**. Inventory still none=0 / terminal **false**.
- Partitions: `WAVE_2026-07-29_wave6_partition_map.md`, `wave7_…`.

## 2026-07-29 — multi-agent wave 6 launch + wave 5 merge (parent)

- **Wave 5 merge (partial):** dual unique A **~613** (A files ~626); most wave5 map VAs dual-sealed; residual dual gaps at launch: `0x00504c70` throttle, `0x00512870` EnsureQuestBaseCredits, `0x00571b80` occupancy sibling.
- Inventory restamp: **25666** accounted (`full` 17158 + `trivial-batch` 8508, `none=0`). `terminal_full_coverage=false`.
- **Wave 6 launch:** ~35 concurrent OWN-ONLY dual agents on domain gaps (UI dialogs, NDXml/NDUIWindow, chunk IO, SpecialFX, TimedAction, Respawn, inventory swap log, DES chain, gfx buffers) + import/thunk trivial-batch expanders.
- Partition: `reviews/WAVE_2026-07-29_wave6_partition_map.md`.
- Honesty: dual ~613 ≪ 25666; stamp ≠ dual depth; do not claim complete.

## 2026-07-29 — multi-agent wave 5 launch (parent)

- Concurrent OWN-ONLY duals on named high-priority missing A/B (HBSkillListener, Outpost cast, TFID, CNDHash, quest tables, HB list, inventory stack/broken, mission map helpers) + CRT/thunk body-proven trivial-batch agents.
- Partition: `reviews/WAVE_2026-07-29_wave5_partition_map.md`.
- Terminal bar unchanged: dual depth ≪ live 25666; stamp ≠ complete.

## 2026-07-29 — verification panel + wave 4 (parent)

- Verification package: multi-agent partitions, sample wave3 trio **8/8 PASS**, ledger honesty, experiments **96 OK**.
- Live Ghidra count **25666** (legacy 26256 stale); inventory **25666** accounted (
one=0); dual A/B **~600** ≪ universe.
- Terminal full coverage remains **false**. Plan Deviations restored terminal bar.
- Wave4 concurrent duals: CastAfterPrompt, accuracy chain, equip arm, inventory COID/list, journal ready, staging tree, fire/heat, camera apply, item pickup 0x2055, Hide≠Flush, category CD remaining, etc.



## 2026-07-29 — multi-agent wave 3 merge (parent)

- ~40 concurrent OWN-ONLY duals on high-priority callees missing A/B. Dual pairs ~560→~586.
- **UF-010** invoker sealed: `FUN_007fca10` → vtbl+0x440 → Flush; **UF-011** sealed: no +0x650 clear; cancel can flush unfilled 0x206E.
- New duals include: CanPlace, FindFreeForItem, Drop hit-test, Turn-in ready, staging map, region missions getter, Cast-block, PromptTarget, UseInventoryItem 0x2045, Chat 0x2021, primary weapons, max-speed, SetDriveAxes, Kill_Precheck.
- Experiments: 76 OK. Honesty: deep duals ≪ 26256; stamp ≠ dual depth.

## 2026-07-29 — multi-agent wave 3 launch (parent)

- **Mandatory concurrency:** ~40 OWN-ONLY dual agents on high-priority callees missing A/B (flush UF-010/011, mission/skill/inventory helpers).
- Partition: `reviews/WAVE_2026-07-29_wave3_partition_map.md`. Parent merges ledgers only.
- Honesty: inventory stamp ≠ full dual depth; finite run = durable dual advance + cold resume; remaining deep duals ≪ ~26256.

## 2026-07-29 — multi-agent wave 2 merge (parent)



- **~60 concurrent residual dual agents completed** (skills / input / inventory / interact / missions) + wave1 relaunches (NPC TryCast, QB Activate, FlushPrepared).

- **UF-013..017 closed** (static doc lag); **UF-007 sealed High** (MoveToTarget ≡ SetSteer `0xC7`); **UF-010 invoker sealed** (Flush vtbl+0x440 via FUN_007fca10); UF-006 label still open; UF-011 cancel flush open.

- High dual seals include: ValidateTarget AL; FormatFailure table; UseObject `0x2072`; IfInteractable; Grab/Drop pack; FindFree/Place index; Collect/Deliver +0x23; Prerequisites; Prepare/Flush/UiModal; CompleteObjective; Recv paths; LocalCast G0–G9; Resolve outFlags 1/2; Filter 4/8/0x10; Range bit2; hardpoint TFID; PushDriveAxes; SetSteer/Long/HB; naming scan 0 conflicts.

- Honesty: deep dual units ≪ 26256; runtime only with Launcher approval. Experiment suite → scratch `recon_experiments.txt`.



## 2026-07-29 — DriveControlTick camera look-offset residual (strengthen)



- **OWN camera only** on `Client_Input_DriveControlTick` `0x009223b0` / `aa_009223b0`: dual A/B `*_camera_refresh.md` strengthened (not full re-dual; soft-steer dual body untouched).

- Separation sealed High on four axes: storage / gate / value domain / consumer; SECTION 7 bind-site interleave matrix; soft look ±0.2 (`local_d4`) ≠ soft steer ±0.5 (`+0x618`).

- Live re-decompile + re-`read_memory` (0.03/0.2/5/11 + alt floats). Function record + `systems/input-drive-control.md` + UF-003 partial + scratch `tmp/a_camera_dct.md`.

- **No** WORK_QUEUE/RESUME/ACTIVE_WORK. **No Launcher.**



## 2026-07-29 — mandatory multi-agent wave 2 launch (parent)



- **~60 concurrent residual dual agents** with isolated VA ownership across skills / input / inventory / interact / missions + meta doc-lag (UF-013..016) + naming scan.

- Wave1 still finishing: NPC_TryCast `0x005d1280`, QuickBarActivate `0x00921b50`, FlushPrepared `0x008ab8f0`.

- Parent owns merge of `WORK_QUEUE` / `RESUME` / `UNRESOLVED_FINDINGS` / matrix; children do not edit those.

- Honesty: inventory stamp ACCOUNTED 25664 ≠ deep dual-verified depth; continue priority residual only.



## 2026-07-29 — UF-016 doc lag note (parent meta)



- Stale same-day CHANGE_LOG bullets that said abandon modal Yes/No pairing "Probable" are superseded by UF-009 High seal (EAX 0x4e46 / stack 0x4e47). Do not re-open UF-009 from those log lines.

- Parent multi-agent wave continues residual duals; inventory stamp ≠ full dual depth.



## 2026-07-29 — Client_RequestCastSkill dual residual (`aa_00941590`)



- **OWN ONLY** `0x00941590` / `Client_RequestCastSkill`. Scratch: `reviews/a_00941590.md`. **No WORK_QUEUE/RESUME.**

- **Sealed (asm):** packet `+0x18 skillId` = formal stack `nSkillId` (decomp false-omitted store); Resolve third arg = `&seedTfid` not `&nSkillId`; HB `__thiscall(entity, skill, chargeMs)` — `unaff_EBX` phantom; FX vtbl+0x238 arg2 = skill id — `unaff_retaddr` phantom; charge forced 0 on this path.

- Role seal: `client+0xe04` world/sim object + `+0x7e` optimistic-HB gate (product type name open). Dual builders vs QB activate documented.

- Dual A/B + function record + clean pack plate + matrix + skills map. **No Launcher.**



## 2026-07-29 — Client_ShowModalPrompt dual residual (`aa_007fdfb0`)



- **OWN ONLY** `0x007fdfb0` dual residual. Scratch: `reviews/a_007fdfb0.md`. **No WORK_QUEUE/RESUME.**

- Sealed OK/Cancel widget bind **High**: `CDlgPopup` (`i_d_pop`) children `CNDUICtrlButton` at `+0x550` OK / `+0x554` Cancel; program via `FUN_008a7150`/`FUN_008a7100` (`vtbl+0x74` → `button+0xec`); asm `MOV EDI,EBP` before Cancel.

- `flagA` → blocker chrome (`FUN_008a7090` / `panel+0x530`); `flagB` unused in body.

- Dual A/B + function record + clean plate + matrix row + UF-009 note. **No Launcher.**



## 2026-07-29 — Client_UpdateMissionJournal residual dual (aa_008ae130)



- **OWN ONLY** `0x008ae130`: residual dual sealed Active/New id partition + callee roles.

- **`FUN_00568200` falsified as id-collect** — live body is tree **iterator++** (`is_nil` @ `+0x49`); journal site `LEA ECX,[ESP+0x14]`.

- **`CVOGReaction_FailMissionNotify` at this site** = Vector_PushDword only (no fail/mutation); dual LEA destinations Active `ESP+0x24` vs New `ESP+0x34`.

- **Partition:** hash `char+0x540` hit ∧ `[node+0x8]!=0` → Active; else New (same `char+0x50c` walk).

- Entry ctor `FUN_00829ec0` / XML `i_d_npc_2d_btn_mselect.xml`; widget ids `0x9c4f` base.

- Dual A/B rewritten; clean/annotated/function record; matrix; system map gap line; scratch `tmp/a_008ae130.md`. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 — Client_RecvInventoryGrabResponse dual residual (`aa_00811be0`)



- **OWN ONLY** `0x00811be0` dual residual. **No WORK_QUEUE/RESUME. No Launcher.**

- **Dispatch Confirmed:** PacketDispatch `case 0x2035`/`0x2039` → this VA; sole xref call `0x008159b0` (`MOV EBX,ESI; MOV EAX,EBP; CALL`).

- **ABI Confirmed:** prologue `MOV ESI,EAX`; packet `EBX`; clear `client+0xb6`.

- **Packet map sealed:** invType **`+0x18`** (asm `MOV DL,[EBX+0x18]` — decompiler omitted), count `+0x1c`, SplitFlag `+0x20`, split COID `+0x28`, success `+0x38`.

- **Simple arm not thin:** `FUN_0093d6e0` = cursor apply (item EAX, invType DL, client+count stack); grid remove inside helper.

- **Helpers:** `FUN_00512160` thiscall SetCoidIdentity on new stack; `FUN_007fc150` cursor UI clear ≠ `DAT_00d1a8f6` (busy clear external).

- Dual A/B + function record + annotated + clean plate; matrix row; scratch `tmp/a_00811be0.md`.



## 2026-07-29 — CVOGReaction_GiveMission dual residual (`aa_005327c0`)



- Residual only (no WORK_QUEUE/RESUME; no clean wholesale rewrite): scratch `reviews/a_005327c0.md`.

- Sealed call-site this: FUN_0053c360 to +0x540 then optional **+0x544** (not same-hash double); FUN_0053c660 to **+0x530**; FUN_00538b20 remove +0x538; FUN_00538a40 tree +0x508.

- Helper roles High: CNDHash_Insert/Remove (strings), MissionDef_EnsureXmlLoaded (FUN_00547920 ECX=def), 0x30 blob init, AddActiveObjective 2-arg thiscall.

- Def **byte** gates: +0x130 obj count, +0xAC repeatable (-1), +0xF8 toast, +0x100 secondary insert, +0x168 XML loaded.

- Dual A/B + function record + annotated corrections; light clean plate comments only. **No Launcher.**





## 2026-07-29 â€” dual residual `aa_005462b0` CVOGCharacter_CheckMissionRequirements



- **OWN ONLY** `0x005462b0` dual residual. Scratch: `reviews/a_005462b0.md`. **No WORK_QUEUE/RESUME.**

- Sealed: ABI **2-arg thiscall** (`RET 4`; one-push call sites); `+0x120`/`+0x124` = **RequirementsOred** / **RequirementsNegative** truth table; `+0x104`/`+0x108`/`+0x118` = Discipline / DisciplineValue / RequirementEventId; `FUN_0052ada0` char resource map `@+0x584/+0x588`; `FUN_005405e0` event-vector membership.

- Dual A/B refresh; function record; clean plate; matrix row; missions-progression dual line. **No Launcher.**



## 2026-07-29 â€” Client_Skill_ResolveCastTarget dual residual (`aa_0093b3a0`)



- **OWN ONLY** `0x0093b3a0` / `Client_Skill_ResolveCastTarget`. Scratch: `reviews/a_0093b3a0.md` (+ `tmp/a_0093b3a0.md`). **No WORK_QUEUE/RESUME.**

- **Sealed:** `FUN_004f8b80` â†’ `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred`; outFlags bit4/8 writers â†’ filter `0x0054ff00` (consumer link); active-bind `pA` â†’ `activeBindScratch` (asm Confirmed); sticky is **silent invalid**, not binding-TFID promote.

- Durable: clean/annotated/function record, dual A/B residual close, VERIFICATION_MATRIX, skills map. **No Launcher.**



## 2026-07-29 â€” dual residual `aa_0052da30` CVOGReaction_FailMission



- **OWN ONLY** `0x0052da30`: sealed Notify **`ECX = char+0x560`** (asm `LEA ECX,[ESI+0x560]`), Notify body = **u32 vector push** (not teardown), end-quest triple `+0x564/+0x568/+0x56c`, per-caller drain table (S2C/`006508d0` yes; Patrol/Kill/`0060e800` no).

- Strengthened dual A/B + function record + annotated + clean plate; scratch `tmp/a_0052da30.md`; matrix open-issues cell; NAMING `charEndQuestIdVector`.

- Still open: dirty `0x10` readers, `FUN_005307e0` dual unit, runtime/bit-exact. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 â€” Client_ShowNpcMissionDialogUI dual residual (`aa_009438f0`)



- **OWN ONLY** `0x009438f0` dual residual strengthen. Scratch `tmp/a_009438f0.md`. **No WORK_QUEUE/RESUME.**

- Live Ghidra â‰¡ raw; clean CF preserved. Sealed: **EAX mission-key** at three call sites (Recv always `EAX=-1` mode=1; HandleButton state3 `dialog+0x518+idx*8`; list `entry+0x500`); chrome mode **`dialog+0x510`** (`int*[0x144]` 1/2); turn-in flag **`dialog+0x64c`** via `FUN_008aa760` from `FUN_0052b420`; Prepare 0x206E chain.

- Distinct from HandleButton router **`+0x648`** (not written here). Dual A/B + function record + clean plate + matrix. Verdict **accept-with-gaps**. **No Launcher.**





## 2026-07-29 â€” Mission_ComputeObjectiveXp dual residual seal (aa_0059dde0)



- **OWN ONLY** `0x0059dde0` `Mission_ComputeObjectiveXp`: dual residual (map iterator, callers, exact-match, bias).

- **Map seal:** helpers `ret 8` thiscall(out,key); after call EAX=out-it*, `*EAX`=node*; key `+0xc`, payload `+0x10`; nil `+0x15`/`+0x1d`; exact key missâ†’0; L-1 same node* (no double-deref). `unaff_EDI` noise.

- **Caller seal:** xrefs â€” CompleteObjective grant (+bias `0x00aaa6d0`=0.5001f); toastÃ—2 + `FUN_0051f510` presentation only. No advance path.

- Dual A/B â†’ **accept-with-gaps**; function record + annotated + clean plate; matrix row. Scratch `tmp/a_0059dde0.md`.

- **No WORK_QUEUE/RESUME. No Launcher.**

## 2026-07-29 â€” Skill_GatherTargetsInArea dual residual (`aa_0058d330`)



- **OWN ONLY** `0x0058d330` `Skill_GatherTargetsInArea`. **No WORK_QUEUE / RESUME.**

- **Sealed:** gather-mode table CF for `param_8` (0/1/2/3/4/6/7/8/9/10/0xb) from body + `FUN_0058a810` + literal callers + `CloneBaseObjectType` (Veh/Cre/Char). Query flag ladder; pass-1 6/7/10; self allow; skill `+0x60c`/`+0x610` ABI via ResolveTargetList.

- English/PDB mode names remain **INFERRED**. Spatial helper renames out of ownership.

- Dual A/B strengthened; function record + annotated + clean plate; matrix; systems map. Scratch `reviews/a_0058d330.md`. **No Launcher.**



## 2026-07-29 â€” dual residual `aa_0052da30` CVOGReaction_FailMission



- **OWN ONLY** `0x0052da30`: sealed Notify **`ECX = char+0x560`** (asm `LEA ECX,[ESI+0x560]`), Notify body = **u32 vector push** (not teardown), end-quest triple `+0x564/+0x568/+0x56c`, per-caller drain table (S2C/`006508d0` yes; Patrol/Kill/`0060e800` no).

- Strengthened dual A/B + function record + annotated + clean plate; scratch `tmp/a_0052da30.md`; matrix open-issues cell; NAMING `charEndQuestIdVector`.

- Still open: dirty `0x10` readers, `FUN_005307e0` dual unit, runtime/bit-exact. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 â€” Client_RecvInventoryEquip dual residual (aa_00813f40)



- **OWN ONLY** `0x00813f40`: opcode **0x203C**/size **0x40** sealed (sole PacketDispatch xref `0x0081597c`); framing **PUSH ESI + EAX client** (`56 8b c5 e8â€¦`).

- **Hardpoint class map sealed:** ornament `FUN_004fe620` `+0x26c`; plant named; melee `FUN_004fe800` `+0x264`; weapon attach `FUN_004fe110`â†’`Vehicle_AttachWeapon`; **wheelset case 0x10** `FUN_004ff510`â†’`Vehicle_SetWheelset` `+0x258`; armor `FUN_00502180`â†’`Vehicle_SetEquippedArmor`. Prior â€œwheelset not in switchâ€ **falsified**.

- Local path: `FUN_00502e90` is full equip dispatcher (not UI-only). Dual A/B + function record + annotated + clean plate; matrix; inventory-transfer map. Scratch `tmp/a_00813f40.md`. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 â€” CVOGReaction_ResolveSkillTargets dual residual (`aa_0054c570`)



- **Asm seal:** `__cdecl` (skillId, rankPacked); map this `DAT_00b04734`; null = **miss** vs end `DAT_00b04738` (not "cached"); `new 0x630` + ctor `FUN_0054f3c0` + `REP MOVSD 0x18c` from `node+0x10`; rank via `Skill_SetRankAndReevaluate` (`RET 4`, store `+0x5f6`).

- **Falsified:** target-list interpretation; plate "already cached"; decomp `unaff_DI` rank arg.

- Dual A/B refreshed (**accept-with-gaps**); clean/annotated/function record; scratch `tmp/a_0054c570.md`; raw re-verify append. **No** WORK_QUEUE / RESUME. **No Launcher.**



## 2026-07-29 â€” `aa_00534920` EvaluatePendingObjectives dual tighten



- **OWN ONLY** `0x00534920` `CVOGCharacter_EvaluatePendingObjectives` dual A/B tighten. **No WORK_QUEUE/RESUME.**

- **Sealed:** `FUN_0059d880` = objective **CompleteCount** getter `*(obj+0x164)` (body + `FUN_005468c0` `<CompleteCount>` XML dump). Collect: `(count!=0 && count<=success) || allTrue`, and `obj+0x138==0`.

- **Plate falsifications fixed in dual/annotated/clean:** continent gate polarity (`+0x7e != 0` **and** `+0xf6 == 0`); precheck does **not** skip eval (only action/LogicUI); deferred CompleteObjective force **0** after unlock.

- Caller context kinds documented (5 Money, 6 post-complete, 7 combat, 9/10, 0xb patrol). Open: `+0x138` English, flag names, sealed kind enum, runtime.

- Artifacts: A/B, function record, clean, annotated, raw version note, matrix, registry, systems map. Scratch `tmp/a_00534920.md`. **No Launcher.**



## 2026-07-29 â€” Client_RecvNpcMissionDialog residual dual strengthen (aa_00815070)



- **OWN ONLY** `0x00815070`: count width + opcode/framing dual residual.

- **Count sealed:** client loop bound is **u8** at `packet+0x18` (`CMP BYTE` / `MOVZX BYTE`); AutoCore i32 LE write remains OK for counts 0â€“255 (low byte used).

- **Opcode sealed:** S2C **0x206D** â†’ sole `Client_PacketDispatch` case/xref call `0x00815af4`.

- **Framing sealed:** `PUSH EBP; MOV EBX,ESI; CALL` + `RET 4` stdcall (packet in EBX, not EAX).

- FUN residual **roles** for `FUN_004bb070` / `FUN_0052d8b0` / `FUN_0053fff0` / `FUN_0052c700` (product names open).

- Dual A/B strengthened; function record + annotated + clean plate; chain `reviews/CHAIN_2026-07-29_s2c_206d_npcmissiondialog.md`; matrix row; scratch `tmp/a_00815070.md`. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 â€” Kill_Eval dual residual seal (aa_00613910)



- **OWN ONLY** `0x00613910` `CVOGObjectiveRequirement_Kill_Eval`: dual residual from 2026-07-23 open gaps.

- **Asm seal:** `MOVZX slot@+8`; `CVTSI2SS required@+0x18`; progress `[state+slot*4+4]`; `COMISS` + complete unless progress < required; `RET 8`; param_2 unread; no stores/calls.

- **Provenance seal:** pure reader; writers are `RecvObjectiveState` `0x00809460` (0x2071 absolute `state[1..4]`) and `Kill_Precheck` `0x00613b50` (`+=` same layout; early-outs via vtbl+0x8 Eval). Filters not in Eval.

- Dual A/B â†’ **accept** (runtime/diff open); function record + annotated + clean plate; raw re-verify append; matrix row.

- Scratch `tmp/a_00613910.md`. **No WORK_QUEUE/RESUME. No Launcher. No Precheck dual ownership.**



## 2026-07-29 Ã¢â‚¬â€ Client_RecvFailMission dual residual seal (aa_0080b100)



- **OWN ONLY** `0x0080b100`: dual residual Ã¢â‚¬â€ opcode dispatch (UF-012) + register contract.

- **Opcode sealed:** S2C **0x20B2** Ã¢â€ â€™ sole `Client_PacketDispatch` xref call `0x00815d97`.

- **Framing sealed:** call site `MOV EAX,ESI; MOV ECX,EBP; CALL 0x0080b100` (image `8b c6 8b cd e8 64 53 ff ff`); body FailMission + `FUN_005307e0` thiscall on `*(client+0xe98)`; missionId `[EAX+0x10]`; UI tail jmp `vtbl+0x448`.

- Dual A/B strengthened; function record + annotated + clean plate; chain residual item 2 closed; UF-012 sealed; matrix row; naming High. Scratch `tmp/a_0080b100.md`. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 â€” dual residual `aa_004f3620` VehicleEntity_SetHandbrake



- **OWN ONLY** `0x004f3620` dual residual. **No WORK_QUEUE/RESUME.**

- Sealed: live re-decompile **â‰¡ raw** â€” ungated `*(u8*)(entity+0x61c)=on` (no `0xC7` vs SetSteer/Longitudinal).

- Sealed consumers: PushDriveAxes â†’ `ctrl+0x24`; calcWheelTorque rear Ã—0.5; hard-stop `+0x109` can force ctrl HB without reading entity HB.

- Sealed bypass: MoveToTarget **direct** `+0x61c` (not a SetHandbrake caller â€” prior record corrected); SetDriveAxes bundled store.

- Caller inventory via live xrefs (DriveControlTick, PollBoundActions, AI/UI packs). Dual A/B + function/annotated/clean + matrix. Scratch `reviews/a_004f3620.md`. **No Launcher.**





## 2026-07-29 Ã¢â‚¬â€ Skill_ResolveTargetList dual residual (`0x00550300`)



- **OWN ONLY** `aa_00550300`: link `Skill_FilterTargetForResolveList_Inferred` `0x0054ff00` + RangeCheck `0x0058c0a0`.

- **Sealed:** outFlags writers (bit1/2 this body; 4/8/0x10 Filter); invalid-TFID wipe Ã¢â€°Â¡ `g_abTfidInvalid_A15870`; `+0x614` Self/Ally/Enemy/Minion/Ground via FormatTargetFilterTooltip; no ValidateTargetForSkill callee.

- Scratch `reviews/a_00550300.md`; clean plate helper renames; dual A/B residual notes; matrix row. **No** WORK_QUEUE/RESUME. **No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ PushDriveAxesToController dual residual (`0x004fbc10`)



- **OWN ONLY** `VehicleEntity_PushDriveAxesToController` `aa_004fbc10` / `0x004fbc10`: strengthen thin wave2 dual A/B.

- Sealed static residuals: thr/HB bridge gates; `DAT_00a0f734=0.9` **positive** ceiling only; speed-cap operands `local_3c < entity+0x10c`; overspeed thr-zero by **travel polarity** (not Ã¢â‚¬Å“opposingÃ¢â‚¬Â); controller layout Ã¢â€°Â  Havok VA (`ctrl+0x24` u8 HB); steer `+0x618` out-of-band.

- Three-rep: function record + annotated + clean plate comments (CF unchanged). Scratch `tmp/a_004fbc10.md`. Matrix row. **No** WORK_QUEUE/RESUME. **No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ CompleteMissionObjectives dual A/B spot-check (`aa_00536080`)



- **OWN ONLY** `0x00536080` dual. **No WORK_QUEUE/RESUME.**

- Live decompile Ã¢â€°Â¡ raw; sole callers Prerequisites Ãƒâ€”2 (`0x005365ae` / `0x00536722`) both `uReason=1` (asm `PUSH 1`).

- Dual A/B strengthened (accept-with-gaps): bulk force objectives only; reason-forward sealed; count-0Ã¢â€ â€™1; plate Ã¢â‚¬Å“reason Ã¢Ë†â€™1Ã¢â‚¬Â falsified for arg4; EvaluatePending reason-0 residual dropped.

- Artifacts: `reviews/A|B_aa_00536080_*`, function record, annotated, clean plate, matrix row, scratch `tmp/a_00536080.md`. **No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ LocalCast residual `aa_00518c20` FUN_00518c20 leave-FUN dual



- **OWN ONLY** `0x00518c20`: lazy map shell at **`this+0x68`** (`operator_new(0xc)` + `FUN_0058d9c0` head, size `+8=0`). Twin of `Skill_GetCategoryCooldownMap` (`+0x6c`); no string/RTTI.

- **Xrefs:** 7 sites / 4 funcs Ã¢â‚¬â€ `Skill_LookupActiveCastBinding`, `Skill_ClearCastBindingAndMaybeRestartCd`, `FUN_00518ca0`, `Skill_LocalCastValidate` (`*(map+8)!=0` + form Ã¢â€ â€™ code 10). Exclusive LocalCast **falsified**.

- Dual A/B **leave-FUN** (block `Skill_GetActiveCastBindingMap[_Inferred]`); function record + annotated + clean plate; scratch `tmp/a_00518c20.md`; skills residual close. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ CVOGReaction_CastSkillOnTarget dual residual (aa_004d09a0)



- **OWN ONLY** `0x004d09a0` dual if weak. **No WORK_QUEUE/RESUME.**

- Sealed: **no network send in unit** (callees = ResolveFromTFID / ResolveTargetList / ApplyStatusEffectLocal / heap only).

- Sealed: targets TFID base **+0x40** (mana cursor +0x50); size `n*0x18+0x58` base includes terminator; Apply `(size-0x40)/0x18` Ã¢â€ â€™ n+1.

- Sealed: resolveFlags 0xd/0xe map is **local only** Ã¢â‚¬â€ never written to packet+0x14; status is 0/`'c'` from param_10 only; return always 0.

- Named callers: `NPC_TryCastSkillFromSet`, Outpost faction/beacon, `Skill_CVOGHBSkill_Summon`, `FUN_004d1b80` (+ bulk).

- Dual A/B strengthen; function record; annotated + clean plate; chain `reviews/CHAIN_2026-07-29_castskillontarget_0x2031_packer.md`; systems map + matrix. Scratch `tmp/a_004d09a0.md`. **No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ dual residual `aa_0060e0f0` CVOGObjectiveRequirement_Patrol_Eval



- **OWN ONLY** `0x0060e0f0` dual residual. **No WORK_QUEUE/RESUME.**

- Sealed: `req+0x24` = **Laps** (GetFlags image `mov eax,[esi+0x24]` Ã¢â€ â€™ `<Laps>%i`); `req+0xd0` = waypoint/target count; product = needed pads; slot float = **absolute** pad count (`comiss`/`cvtsi2ss` image Ã¢â€°Â¡ raw).

- Zero-product edge: Eval completes when `slotFloat >= 0`; Action returns `1.0`; server `NeededCount` may normalize Laps/targets (port note only).

- Dual A/B refresh; function record; clean plate; annotated; scratch `reviews/a_0060e0f0.md`; matrix row. **No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ FindActiveObjectiveIdForPick dual (aa_005245d0)



- **OWN ONLY** `0x005245d0`: sibling of FindActiveObjectiveIdForInteract; same `char+0x548` walk / id `@+0x10`; match via `FUN_0059da10` (**vtbl+0x44**).

- Three-rep + dual A/B; Ghidra rename `CVOGCharacter_FindActiveObjectiveIdForPick` (**Probable**); prior scaffold `Ã¢â‚¬Â¦ForInteractAlt`.

- Callers (3): `Client_InteractClickPickTarget`, `FUN_00925820` (select-only), `FUN_00490070`.

- Artifacts: raw/annotated/clean/function record/reviews A|B; registry + matrix + interaction-activation; scratch `tmp/a_005245d0.md`. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ Client_RecvSkillStatusEffect opcode/FUN residual dual strengthen (aa_00811170)



- **Opcode sealed:** S2C **0x2031** Ã¢â€ â€™ sole `Client_PacketDispatch` case/xref call `0x0081589c`.

- **Framing sealed:** call site `MOV EAX,ESI; MOV ECX,EBP; CALL 0x00811170` (image `8b c6 8b cd e8Ã¢â‚¬Â¦`); packet in EAX, client in ECX.

- **FUN residual surface:** roles for list-lock trio, map find/erase, `FUN_0054b480` global map (Ã¢â€°Â  GetCategoryCooldownMap), chat/log helpers; `'c'` path cross-links `Skill_ApplyEffectsOnTarget_Inferred` (`0x005538a0`). Remaining FUN product names open.

- Dual A/B strengthened; function record + annotated + clean plate; chain `reviews/CHAIN_2026-07-29_s2c_2031_skillstatuseffect.md`; matrix row updated. Scratch `tmp/a_00811170.md`. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ dual residual `aa_00813730` Client_RecvInventoryDropResponse (Agent A)



- **Opcode seal Confirmed:** `Client_PacketDispatch` `case 0x2037`/`0x203b` Ã¢â€ â€™ `Client_RecvInventoryDropResponse` (live Ghidra re-decompile + xref `0x008159c2`); body early-outs `0x203b` only.

- Live body re-decompile Ã¢â€°Â¡ raw; base field plate cross-checked vs PACKET STRUCTURES + `InventoryDropResponsePacket.Write`.

- Strengthened A dual + annotated + function record + clean plate dual refs; matrix row; scratch `tmp/a_00813730.md`.

- Open: swap/concat depth, place ECX thiscall recovery, AutoCore omit of `@+0x28`/`@+0x38`, runtime. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ DriveControlTick camera look-offset residual



- **OWN camera only** inside `Client_Input_DriveControlTick` `0x009223b0`: dual A/B `*_camera_refresh.md` (not full re-dual); locals `local_d*` vs steer `+0x618` sealed High CF; look steps `read_memory` 0.03/0.2/5/11.

- Amended function record + `systems/input-drive-control.md` camera residual; UF-003 partial; scratch `tmp/a_camera_dct.md`. **No** WORK_QUEUE/RESUME. **No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ skill FUN residual renames + WQ-004 soft-steer dual refresh



- **Skills evidence-only:** `0x004f8b80` Vehicle_ResolveFirstHardpointOccupantTfid_Inferred; `0x0054ff00` Skill_FilterTargetForResolveList_Inferred (outFlags 4/8/0x10); `0x004e2600` CNDDoubleList_InvokePredicateAndRemove_Inferred; `0x005788d0` CVOGHBSkillCast_ctor_Inferred. Dual A/B each; left FUN_005169c0/00518c20 (no string).

- **WQ-004 soft-steer:** dual refresh soft/analog; UF-006 CF High / label Probable; experiments `drive_soft_steer_constants.py`.

- Durable: skills map open Q, NAMING, RESUME. **No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ Skill_ApplyEffectsOnTarget_Inferred (`0x005538a0`)



- **Skills residual:** `FUN_005538a0` Ã¢â€ â€™ `Skill_ApplyEffectsOnTarget_Inferred` (`_Inferred`; no product string). Combat/effect apply core: ResolveObjectTarget + events 4/0xc/0xe/5/6 + handler `+0x5f0` vtbl+0x2c. Callers sealed (ApplyStatusEffectLocal delay&lt;1, Recv null-source `'c'`, active-skill HB `FUN_00606180`, etc.). Dual A/B accept. Scratch `tmp/a_005538a0.md`. No WORK_QUEUE/RESUME edit.



## 2026-07-29 Ã¢â‚¬â€ Collect_Action + Deliver duals + FindActiveObjectiveIdForInteract



- **Collect_Action** `aa_00611f20` / `0x00611f20`: three-rep + dual A/B; kill-loot vs inventory event; CountItemsByCbid bridge.

- **Deliver cargo readiness:** `aa_00611290` OnInventoryEvent type-4; `aa_00610f20` CargoReady predicate; both `_Inferred` names; duals.

- **Interact objective id:** `aa_00524520` FindActiveObjectiveIdForInteract (not bool); helper `aa_0059d9c0` MatchTargetEvaluators; duals.

- Experiments structural tests extended; suite re-run OK. **No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ Inventory collect bridge + interaction + modal pairing + skills ValidateTarget



- **InventoryÃ¢â€ â€collect:** `InventoryGrid_CountItemsByCbid` `0x005711c0` + `CVOGObjectiveRequirement_Collect_Eval` `0x00611940` (cargo `char+0x250Ã¢â€ â€™+0x2b0`); chain `CHAIN_2026-07-29_inventory_collect.md`; duals A/B; experiments `inventory_collect_bridge.py`.

- **WQ-006 interaction:** system map `interaction-activation.md`; UseObject `0x2072` duals; IfInteractable objective-id find (not bool); SYS-INTERACT active/partial.

- **UF-009 modal pairing High:** `Client_ShowModalPrompt` `0x007fdfb0` Ã¢â‚¬â€ abandon open loads **EAX=0x4e46** (Yes) + stack **0x4e47** (No); asm at HandleButton call site.

- **Skills:** `Skill_ValidateTargetForSkill` asm ABI sealed (wrapper AL polarity inverted vs handler 1=reject); evidence renames HBSkillListener, Outpost cast helpers.

- **Missions:** CheckMissionPrerequisites dual refresh (mutator not pure check).

- **Inventory grab/drop:** dual A/B quality refresh; opcodes 0x2034/0x2036 Confirmed.

- Durable: WORK_QUEUE WQ-006..009, SYSTEM_INDEX, NAMING, RESUME. Experiments suite OK. **No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ Seal C2S 0x206E + abandonÃ¢â€ â€™FailMission (static)



- **0x206E send site sealed:** `Client_NpcDialog_PrepareResponseOpcode` (`0x008abd70`) sets `dialog+0x650=0x206E`; `Client_MissionDialogHandleButton` state 1 fills payload only; **`Client_MissionDialog_FlushPreparedResponse`** (`aa_008ab8f0` / `0x008ab8f0`, was `FUN_008ab8f0`) sends size **0x20** from `+0x650` via `DAT_00d1b4b8` vtbl+0x18 (asm + vtable DATA `0x00a4a95c`). Chain: `reviews/CHAIN_2026-07-29_c2s_206e_seal.md`.

- **AbandonÃ¢â€ â€™FailMission sealed (static):** HandleButton state 2 stashes `DAT_00d1b4b4`, modal `0x4e47`; `FUN_00911840` case **`0x4e46`** sends C2S **`0x20B2`** size **0x18**; `CVOGReaction_FailMission` apply + dual refresh; `Client_RecvFailMission` (`aa_0080b100`) duals. Chain: `reviews/CHAIN_2026-07-29_abandon_failmission.md`. Residual: modal Yes/No pairing Probable; runtime open.

- Artifacts: `reconstructed-exact/Client_MissionDialog_FlushPreparedResponse.cpp`, `Client_UiModalDispatch_AbandonConfirm.cpp`; experiments `mission_dialog_c2s.py` + tests (**17** new; full suite **44 OK**).

- Updated: NAMING_REGISTRY, VERIFICATION_MATRIX, systems/missions-progression, WORK_QUEUE WQ-007, RESUME, function records, dual A/B for flush/abandon/FailMission. **No Launcher.**



## 2026-07-28 Ã¢â‚¬â€ Skeptic gap fix: matrix + WORK_QUEUE dual sync



- `VERIFICATION_MATRIX.md`: Ind.rev/Skep.rev=Y + Last reviewed 2026-07-28 for GiveMission, CheckMissionRequirements, SetLongitudinalInput, RecvSkillStatusEffect, DriveControlTick, NPC_TryCastSkillFromSet; removed false Ã¢â‚¬Å“map-only / no function recordÃ¢â‚¬Â claim for `aa_009223b0`.

- `WORK_QUEUE.md` WQ-003: dual A/B present (accept-with-gaps); residual runtime/diff only. WQ-004: unit + dual present (not queued raw capture).



## 2026-07-28 Ã¢â‚¬â€ NPC_TryCastSkillFromSet human refine + dual status sync



- **Address `0x005d1280` / `aa_005d1280`:** dual A/B already present (accept-with-gaps); clean comments refined (9-stage plate + open links); function record + skills-abilities unit status updated from scaffold.

- Open gaps left on system map: seal `NPCSkillSetEntry` (0x18), cast-result return type, server-only `world+0x7e`, live AI cast capture, threat scalar.

- Artifacts: `reconstructed-exact/NPC_TryCastSkillFromSet.cpp`, `functions/aa_005d1280_NPC_TryCastSkillFromSet.md`, `reviews/A|B_aa_005d1280_NPC_TryCastSkillFromSet.md`. **No Launcher.**



## 2026-07-28 Ã¢â‚¬â€ Client_RecvSkillStatusEffect refine (aa_00811170)



- **Clean plate:** removed non-authoritative empty stub; single full decomp body retained (behavior-preserving). Strengthened plate comments: packet layout (0x9a0 / 0x2031), status gate `{0,'c',0x11}`, local-caster TFID match, unresolved FUN_* list.

- **Dual A/B:** strengthened confidence tables + open questions (opcode seal, `'c'` semantics, FUN_* residual surface). Verdict remains **accept-with-gaps**.

- **Function record / annotated / skills system map:** status Ã¢â€ â€™ human-refined + dual review.

- **No Launcher.** Paths: `reconstructed-exact/Client_RecvSkillStatusEffect.cpp`, `reviews/A_aa_00811170_*`, `reviews/B_aa_00811170_*`, `functions/aa_00811170_*`.



## 2026-07-28 Ã¢â‚¬â€ `aa_005462b0` CheckMissionRequirements dual A/B strengthen

- Strengthened dual reviews for `CVOGCharacter_CheckMissionRequirements` (`0x005462b0`): body-backed mission-def offsets (+0x90 race, +0x92 faction, +0x94/+0x98 level, +0x104/+0x108 currency, +0x118 flag, +0x9c prereqs; +0x120/+0x124 mode CF); pure eligibility gate (no side effects); dual status accept-with-gaps.



## 2026-07-28 Ã¢â‚¬â€ inv-place inventoryType/grid offsets (`aa_00571620`)



- Confirmed **three representations** + **dual A/B** already present for

  `InventoryGrid_PlaceItemFootprint` (`aa_00571620` / `0x00571620`): raw,

  annotated, clean `InventoryGrid_PlaceItemFootprint.cpp`, A/B reviews

  (`accept-with-gaps`).

- Documented **raw-only** offsets: DropResponse `inventoryType` @ packet

  **`+0x1a`** (cases 1/3/5/6 Ã¢â€ â€™ grid `+0x2b0` / `+0xcbc` / `+0xce0` / TFID+`0xce0`);

  place X/Y `@+0x18/+0x19`; InventoryGrid `+0x04/+0x08/+0x0c/+0x10/+0x14/+0x18/+0x1c/+0x24/+0x28`

  (cells 8 B, empty `0xFFFFFFFF`); clonebase InvSize `+0x406/+0x407`.

- Place unit does **not** read inventoryType (caller resolves grid). Stamp loop

  formula still unsealed (`unaff_SI` / `bStack_8`).

- Updated: function record, `systems/inventory-transfer.md`, `OBJECT_LAYOUTS.md`,

  VERIFICATION_MATRIX row. **No Launcher.**



## 2026-07-28 Ã¢â‚¬â€ CVOGReaction_GiveMission dual A/B spot-check (`aa_005327c0`)

- Confirmed three layers: raw/annotated `raw/aa_005327c0_*`, clean `reconstructed-exact/CVOGReaction_GiveMission.cpp`, function record `functions/aa_005327c0_*`. Refreshed dual reviews `A_aa_005327c0_*` / `B_aa_005327c0_*` (purpose, High/Probable/Tentative, open questions, CF cleanÃ¢â€°Â¡raw). CF fix: outer already-active (`+0x540` hit) returns **0** (not 1); inner Ã¢â‚¬Å“Already had missionÃ¢â‚¬Â returns **1**. Param renames evidence-only. Verdict: **accept-with-gaps** (client CF High). No Launcher.



## 2026-07-28 Ã¢â‚¬â€ SetLongitudinalInput `aa_004f5650` dual confirm

- Confirmed three representations (raw/annotated/clean) + dual A_/B_ for `VehicleEntity_SetLongitudinalInput` @ `0x004f5650` (gate **0xC7**, store **+0x614**, wobj-null allow); sign convention cross-check vs `systems/input-drive-control.md` (**Accelerate = Ã¢Ë†â€™1** caller-owned; CF unchanged). Dual status: **present**, verdict **accept-with-gaps**. No Launcher.



## 2026-07-23 Ã¢â‚¬â€ Experience_*/Tech/Serialize/DB dual A/B (34 units)



- **New modern dual reviews** (A reconstruction + B skeptical) for remaining

  `Experience_*` helpers, `Character_GetTechForPoolCalcs`, both

  `CreateSimpleObject_Serialize*`, `DB_ReadPowerPlantSpecific`, plus **24** other

  high-value named managers still missing duals (cap priority + 25 others;

  never Launcher):

  - **Experience:** `GetCreatureXpForLevel` (missÃ¢â€ â€™0), `GetCumulativeThreshold`

    (missÃ¢â€ â€™0x7FFFFFFF), `XpToReachRelativeLevel` (+0xc54 / +0x730 formula),

    three `Ensure*TableLoaded_INFERRED` twins

  - **Tech / serialize / DB:** Tech clamp **[1,250]** with pre-cap 200;

    CreateSimpleObject **0x2012/0xD8** primary vs Variant2 this-base split;

    power-plant **0xC** row Ã¢â€ â€™ clonebase **+0xB0..+0xBA**

  - **XP-adjacent fill:** Outpost pulse XP + percent tables, StdMap lower_bound,

    `Mission_tExperienceLevel` / `tQuestXPLookup` / `tCreatureExperienceLevel` /

    `tContinentExploredAreas` loaders

  - **Loot / item / vehicle:** `Inv_tLoot*` / generate id+type / credits / pickup /

    `tItemTemplate` / `vLootBaseItems`, `Drive_tVehicleTemplate`, loot prefix map,

    heat-mult map (Ã¢â€°Â  ApplyShotHeat), map erase, creature graphics, sector map save

- Notable skeptical hits: never conflate creature-XP miss 0 with cumulative

  sentinel 0x7FFFFFFF; Serialize vs Variant2 this-bases differ; Ensure bodies do

  not show ready-flag writes; rlWeaponHeatMultiplier is table ops not fire cost.

- Report: `docs/agents/task-dual-ab-exp-tech-serialize-db-report.md`. **No Launcher.**



## 2026-07-23 Ã¢â‚¬â€ Net_*/CLoad*/Phy_*/hkDefault*/Weapon_* dual A/B (30 units)



- **New modern dual reviews** (A reconstruction + B skeptical) for remaining high-value

  named managers missing both A_/B_ pairs (cap 30; prefer Net/CLoad/Phy; never Launcher):

  - **Net/Ghost:** `UnpackGhostUpdate` (+ sibling `005b17b0`), `PackInitialCharacterUpdate`,

    `GhostConnection`, `getUpdatePriority`, `NetObject_SetMaskBits` (OR + dirty list),

    `GhostObject_OnGhostAdd`, `InitNetworking_sector`

  - **CLoad:** full `CLoadQueue_Update` + `CLoadNode` stage pipeline (`initPreload` /

    `initAnim` / `initPhysics` / `initFull` / `initAI` / post-create / selection / barriers)

  - **Phy/CPhysX:** `CollectAllPhysicsPreloads`, `Start_ReinitPhysics`, `Inside_InitPhysics`,

    `Preload_ReloadRigidBody`, `BoundingVolumeFactory_CreateFromTag`, `CPhysXBase_Step` /

    `RenderResults`

  - **Drive companions:** `hkDefaultAnalogDriverInput_calcReverse` / `calcStatus`,

    `hkDefaultBrake_update` (WI-MOV-005)

  - **Weapon heat:** `CanFireHeatCheck` (heat +0x150 vs max +0x244), `ApplyShotHeatAndPowerCost` (type 0xE)

- Notable skeptical hits: ghost unpack VAs must stay split from VehicleNet; SetMaskBits is OR

  not replace; initAI vtbl+0xc0 attaches HBAI while recalculate only sets +0x64; CPhysX Step is

  one-shot ~1/30; weapon costs gate on owner type 0xE.

- Report: `docs/agents/task-dual-ab-net-cload-phy-report.md`. **No Launcher.**



## 2026-07-23 Ã¢â‚¬â€ Vehicle thin + Skill_Uses_* dual A/B (25 units)



- **New modern dual reviews** for remaining thin **Vehicle_*** / **VehicleEntity_***

  combat-pool and drive-axis units, all **Skill_Uses_*** string aliases, and related

  fills (cap 25):

  - **Regen getters:** `GetHpRegenRate` (+0x3FA), `GetShieldRegenRate` (+0x4B6),

    `GetPowerRegenRate` (plant+0xB8 / default 1), `GetCoolRate` (plant+adjust)

  - **Combat/drive thin:** `IsAnyWeaponFiring` (turret+3 HP, flag +0xC7),

    `SetHandbrake` (ungated +0x61c), `SetFlag_109` (+0x109 meaning open),

    `Creature_GetHpRegenFromEquippedRaceItem` (creature+0x250 glue)

  - **Skill ledger:** real `SkillSet_GetEntryCount` (stride 0x18) + 9 `Skill_Uses_*`

    aliases (explicitly **not** product drop-ins for EnsureLoaded / ResolveTargets)

  - **Physics/net fill:** `torqueCurve2D`, `calcWheelTorque`, `tickSubsystems`

    (framework this), `VehicleAction_ctor`, airStabilization, TriggerReplay,

    ReconcilePrediction

- Notable skeptical hits: Skill_Uses VAs Ã¢â€°Â  thin/real namesakes; tickSubsystems

  `this` is hkVehicleFramework; SetHandbrake has no 0xC7 gate.

- Report: `docs/agents/task-dual-ab-vehicle-thin-skill-uses-report.md`. **No Launcher.**



## 2026-07-23 Ã¢â‚¬â€ Plate-driven domain FUN_* aliases full address range (200 units)



- **200 domain-named clean aliases** for remaining `FUN_*` units across full VA range with

  PURPOSE/READABILITY embedded-string evidence (skipped if non-CalleeOf alias already present).

- Domains: `CVOG*` loot/graphics/AI/waypoint, `CLoadNode_*` init pipeline, `Inv_*` loot/item tables/UI,

  `Mission_*` quest UI/position, `Combat_*` weapon/target/damage, `Phy_*` / `Gfx_*` FX, `Net_*` ghost,

  `Skill_*` phantom cast / sc UI, `Drive_*` speed particles, `UI_*` chrome, data-cursor `Named_dc*`.

- `FUN_*.cpp` originals retained; function records got `## Alias` human names where present.

- **Not** `Named_CalleeOf_*`. Report:

  `docs/reconstruction/coverage/plate_domain_rename_full_range_report.txt`. **No Launcher.**



## 2026-07-23 Ã¢â‚¬â€ Plate-driven domain FUN_* aliases [0x00600000, 0x00a00000) (100 units)



- **100 domain-named clean aliases** for `FUN_*` units at VA in `[0x00600000, 0x00a00000)` with

  PURPOSE/READABILITY embedded-string evidence (skipped if non-CalleeOf alias already present).

- Domains: `CVOG*` trigger/screen, `Phy_*` init/reinit physics, `Net_Nazgul_*` / ghost pack-unpack,

  `LCD_*` Logitech LCD, `Snd_*` streaming music, `Inv_*` loot tables/UI, `Mission_*` XP/quest tables,

  `Drive_*` vehicle/wheel templates, `Combat_*` weapons/respawn, `UI_*` arena/mail/clan/chat,

  `Gfx_*` NDAsset/FX, `CNDAssetStringTable_*`, data-cursor `Named_dc*`.

- `FUN_*.cpp` originals retained; function records got `## Alias` human names where present.

- **Not** `Named_CalleeOf_*`. Report:

  `docs/reconstruction/coverage/plate_domain_rename_6m_a0_report.txt`. **No Launcher.**



## 2026-07-23 Ã¢â‚¬â€ Plate-driven domain FUN_* aliases under 0x00500000 (50 units)



- **50 domain-named clean aliases** for `FUN_*` units at VA `< 0x00500000` with

  PURPOSE/READABILITY embedded-string evidence (skipped if non-CalleeOf alias already present).

- Domains: `CVOG*` sector/map step paths, `CPhysXBase_*` / `Phy_*`, `Gfx_*` (FX/PNG/BMP/particles),

  `Net_Nazgul_*`, `Sto_*`, `Snd_*`/`Anim_*` preloads, `Util_HashList*`, `Zlib_*`, `Skill_NonCreatureCastAutoHit`.

- `FUN_*.cpp` originals retained; function records got `## Alias` human names.

- **Not** `Named_CalleeOf_*`. Report:

  `docs/reconstruction/coverage/plate_domain_rename_under_500k_report.txt`. **No Launcher.**



## 2026-07-23 Ã¢â‚¬â€ Mission_*/Skill_*/Inv_*/Drive_* dual A/B (30 units)



- **New modern dual reviews** (A reconstruction + B skeptical) for highest-value

  `Mission_*` / `Skill_*` / `Inv_*` / `Drive_*` clean units missing both A_/B_ pairs (cap 30):

  - **Mission:** `ComputeObjectiveCredits`, `ClaimSelectedReward` (C2S 0x20c6 seed),

    `HandleEndQuest`, `BuildMissionDetailPanel`, `BuildMissionXmlPath`, `StreamMissionStrings`

  - **Skill cast stack:** `LocalCastValidate`, `LocalRangeTargetCheck`, `ValidateTargetForSkill`,

    `ResolveTargetList`, `GatherTargetsInArea` (TFID stride 0x10), cast bookkeeping

    (`SetIsCastingFlag`, `Lookup/Clear` bind, `QueueDeferredCastId`, `StartCastAgainHeartbeat`),

    rank/runtime (`EvaluateRankedElements`, `CopyRuntimeFieldsFromTemplate`, `EnsureLoadedInTree`),

    `ApplyStatusEffectLocal` (0x2031), summon HB, tooltip formatter

  - **Inv:** equip clonebase slot validate, craft affordability, post-random integrity, RE client path

  - **Drive:** `MoveToTarget3DPoint` (thr/steer/HB axes), water FX, vehicle collision listener

- Notable skeptical hits: credits formula is delta-only (no +0x720 write); claim opcode payload open;

  MoveToTarget UF-007 gate residual; LocalCastValidate is client precheck not server authority.

- Report: `docs/agents/task-dual-ab-mission-skill-inv-drive-report.md`. **No Launcher.**



## 2026-07-23 Ã¢â‚¬â€ Auth*/AuthClient_*/BitStream_* dual A/B remaining (8 units)



- **New modern dual reviews** for the **8** unique VAs still missing both A_/B_ under

  Auth* / AuthClient_* / BitStream_* clean filters (cap 40; AuthClient_* + BitStream_* already complete):

  - **Trace:** `authMessageTrace` receive `0x00727b70`, send `0x00727c00`

  - **Login UX:** `FormatUnknownAccountChatLine`, `RequireAccountName`,

    `i_d_fesh_*` shard select, `i_d_fet_*` account entry (+ password XML)

  - **Auth state:** `No_authentication_key` `0x009332b0`, `Setup_of_CNDAuthClient_failed` `0x008223e0` (init + fail branch)

- Notable skeptical hits: fesh Ã¢â€°Â  fet screens; Setup_* is constructor not fail-only;

  authMessageTrace is log-only; `0x6900` arg on missing-key path unsealed.

- Post-batch: **0** Auth*/AuthClient_*/BitStream_* clean units missing duals.

  Report: `docs/agents/task-dual-ab-auth-bitstream-report.md`. **No Launcher.**



## 2026-07-23 Ã¢â‚¬â€ Client_*/CVOG* dual A/B wave 3 (20 units)



- **New modern dual reviews** (A reconstruction + B skeptical) for remaining clean

  `Client_*` / `CVOG*` managers that lacked both A_/B_ pairs (cap 20):

  - **CVOG:** `SectorMap_LoadMapFile`, `Variable_EvaluateComputed`, `Physics_ApplyImpulseVector`,

    `PlayerVehicle_UpdateTurretAiming`, `Vehicle_GetWeaponSlotTransform`, `Reaction_BuildTextParams`,

    `Reaction_RandomUnitScalar` (RNG singleton misnomer), `RoadNode_ParseWidthFromTexName`

  - **Input:** `ActionMap_Init`, `InitActionDisplayNames`, `Input_OnKeyDown_MatchAction`,

    `Input_PollBoundActions`

  - **Mission/UI:** `UpdateObjectiveDisplayHud`, `RefreshOpenMissionUiWindows`,

    `NotifyActiveMissionChanged`, `HideMissionDialogIfOpen`, `ShowMissionRewardChatToast`

  - **Tips / skills:** `MaybeShowFirstTimeTip`, `SetFirstTimeTipBit`, `QuickBarActivateSkillSlot` (C2S 0x2030)

- Notable skeptical hits: RandomUnitScalar is not a float; map var types 0xB/0xC use active hashes;

  reward toast is display-only (+0x538); QB skill path is 0x28-byte 0x2030.

- Post-batch: **43** Client_* still dual-missing; **no CVOG*** left without duals in filter.

  Report: `docs/agents/task-dual-ab-client-cvog-wave3-report.md`. **No Launcher.**



## 2026-07-23 Ã¢â‚¬â€ CVOGObjectiveRequirement_* dual A/B wave (14 units)



- **New modern dual reviews** (A reconstruction + B skeptical) for all clean

  `CVOGObjectiveRequirement_*` units that lacked A_/B_ pairs (14/14, under 30-pair cap):

  - **Kill:** `Eval` `0x00613910`, `Precheck` `0x00613b50`

  - **Patrol:** `Eval` `0x0060e0f0`, `Action` `0x0060e120`, `GetFlags` `0x0060e260`,

    `GetTarget` `0x0060e370`, `InitActive` `0x0060e3d0`, `GetSomething` `0x0060e9e0`

  - **UseItem:** `Eval` `0x0060cfe0`, `InitActive` `0x0060d540`, `MatchTarget` `0x0060d7f0`,

    `OnComplete` `0x0060cfd0`, `SerializeXml` `0x0060d800`, `SlotAction` `0x0060d060`

- Notable skeptical hits: eval family is pure compare (not mutators); UseItem required count is

  `+0x50` (not KillÃ¢â‚¬â„¢s `+0x18`); Patrol_GetFlags is XML dump not bitflags; MatchTarget is trampoline

  to `FUN_0060d460`; OnComplete is empty ret; Kill_Precheck has unaff_EBP / param_3 alias gaps.

- Function records linked to duals; `systems/missions-progression.md` dual table extended.

  Runtime/diff/bit-exact still open. **No Launcher.**



## 2026-07-23 Ã¢â‚¬â€ Low-priority systems readable plates (physics / networking / lighting)



- Human-refined clean plates (Purpose / CF summary / key offsets / dual-review links) for **20** existing units:

  - **BitStream_***: `writeBits`, `readBits`, `writeFlag`, `readFlag`, `writeInt`, `readInt`, `writeQuantizedFloat`

  - **Client_SendSectorPacket** `0x00807460`, **Client_RecvBroadcast** `0x00810a80`

  - **CVOGPhysics_ApplyImpulseVector** `0x0040d260`

  - **gfx***: `GeometryPiece` Serialize/Unserialize, `IndexBufferImpl` S/U, `VertexBufferImpl` S/U

  - **phy***: `phyBone_unserialize`, `phyBoneSharedData_unserialize`, `Phy_BoundingVolumeFactory_CreateFromTag`

  - **Named_gfxLightManager** shutdown path `0x0074e3e0`

- Ghidra plate comments set/updated for BitStream family, sector send/recv, CVOGPhysics, gfxLightManager.

- Dual reviews for `BitStream_writeBits` and `Client_SendSectorPacket` **already present** (A_/B_ accept-with-gaps) Ã¢â‚¬â€ not recreated.

- Function records system tags + purpose lines updated. Runtime/diff/bit-exact still open. **No Launcher.**



## 2026-07-23 Ã¢â‚¬â€ Mission progression dual A/B wave (9 units)



- **New modern dual reviews** (A reconstruction + B skeptical) for units that lacked A_/B_ pairs:

  `HasCompletedMission` `0x0052aa20`, `CompleteMissionObjectives` `0x00536080`,

  `EvaluatePendingObjectives` `0x00534920`, `SearchAutoMissions` `0x00532b60`,

  `AddCredits` `0x005355a0`, `AddSkillPoints` `0x005312c0`, `AddAttributePoints` `0x00531250`,

  `AddActiveObjective` `0x00531b00` (upgraded from prior reconstruction/skeptical),

  `EvalActiveObjectiveInteractState` `0x004d3ef0`.

- Notable skeptical hits: skill/attrib Ã¢â‚¬Å“Add*Ã¢â‚¬Â are **assign** not `+=`; HasCompleted is not naÃƒÂ¯ve hash OR;

  SearchAuto skips via manual +0x538 walk (not HasCompletedMission API); CompleteMissionObjectives

  forwards `uReason` (not fixed Ã¢Ë†â€™1 on 4th arg).

- Matrix Ind.rev/Skep.rev set Y for the five matrix-listed mission units; dual table in

  `systems/missions-progression.md` updated. Runtime/diff/bit-exact still open. No Launcher.



## 2026-07-23 Ã¢â‚¬â€ AI managers human-readability (HBAI / HB / spawn / map-path)



- Human-refined clean plates (Purpose / CF summary / key offsets / callees) for AI managers already named under `reconstructed-exact`:

  `CVOGHBAI*` (factory, base, creature, driver, follow, find-target, aggro, ctors),

  `CVOGHB*` (base list/try-fire/reschedule, regeneration, OKToCastAgain, mission-patrol),

  `CVOGSpawn*`, `CVOGMapPath_AdvanceAndSteer`, `AI_CheckSlotTimerReady`.

- System tags normalized to `npc-ai / HBAI`, `heartbeat / timed-actions`, `heartbeat / combat-pool`, `npc-ai / spawn`, `npc-ai / map-path` as appropriate.

- **New dual reviews** (were missing): `A_/B_aa_005d0310_CVOGHBAICreatureBase_OnHeartBeat`, `A_/B_aa_00639210_CVOGHBAIBase_FindTargetToAttack` (accept-with-gaps / needs-more-evidence on helpers).

- Behavior preserved; runtime/diff/bit-exact still open. No Launcher / no disassemble_bytes.



## 2026-07-23 - input-drive-control human-readability (keybind + input clean)



- Human-refined cleans: Client_ActionMap_Init, Client_InitDefaultKeybinds, Client_InitActionDisplayNames (force_decompile recovery of failed raw), Client_Input_OnKeyDown_MatchAction, Client_Input_PollBoundActions (stripped corrupt prefix), Drive_CVOGVehicle_MoveToTarget3DPoint (+ _004fc650 twin).

- Param renames where clear: ActionMap object pActionMap (ESI/EDI/EAX register pass); OnKeyDown pClient.

- Section banners: keybind DIK groups (Inventory / QB / Shift-QB / helpers); display-name drive axes (Accelerate/Reverse/Steer/Soft/Brake); OnKeyDown ESC vs table scan.

- Dual reviews new for keybind init: A_/B_aa_007f8720_Client_InitDefaultKeybinds (accept-with-gaps / needs-more-evidence). Main tick dual reviews already present (A_/B_aa_009223b0).

- Raw append for aa_007f7570 force_decompile recovery. Function records updated for keybind/init/display/OnKeyDown units.

- Drive thr/steer DIK defaults not sealed in InitDefaultKeybinds body (helpers open). Setter cleans (SetSteer/Long/HB/Push/SetDriveAxes) already refined - left intact.



## 2026-07-23 Ã¢â‚¬â€ Mission dialog / journal / objective chain readability



- Human-refined clean plates + inline comments for dialog/journal/objective hubs:

  `Client_ShowNpcMissionDialogUI`, `Client_UpdateMissionJournal`,

  `Client_FindObjectiveMatchingTarget`, `CVOGObjectiveRequirement_{UseItem,Patrol,Kill}_Eval`,

  `Patrol_GetTarget`, `UseItem_MatchTarget`.

- Already-refined hubs linked to new duals: `RecvNpcMissionDialog`, `MissionDialogHandleButton`,

  `RecvObjectiveState`, `AddActiveObjective` (prior duals).

- **New dual reviews (A reconstruction + B skeptical):**

  `RecvObjectiveState` `0x00809460`, `MissionDialogHandleButton` `0x008ae7c0`,

  `RecvNpcMissionDialog` `0x00815070`, `UpdateMissionJournal` `0x008ae130`,

  `ShowNpcMissionDialogUI` `0x009438f0`, `FindObjectiveMatchingTarget` `0x00525bd0`.

- Matrix + `systems/missions-progression.md` entry points / dual table updated.

- Behavior preserved; runtime/diff/bit-exact still open. No Launcher / no disassemble_bytes.



## 2026-07-23 Ã¢â‚¬â€ Inventory + skills human-readability wave



- Human-refined clean plates (Purpose / CF summary / key offsets / dual-review links) for inventory + skills Client_* / SetQuickBar units.

- Full refine (names + CF): `Client_Skill_ResolveCastTarget` `0x0093b3a0`, `Client_QuickBar_ActivateSlot` `0x009436c0`, `CVOGCharacter_SetQuickBarSkill` / `SetQuickBarItem`.

- Plate upgrades (behavior-preserving): Recv Grab/Drop/Add/Unequip/Use*, Send Grab/Drop/Add/Unequip*, UI DropToGrid / ItemClickDispatch, QuickBarActivateSkillSlot.

- Param renames where roles clear only: ItemClickDispatch `param_1`Ã¢â€ â€™`pWidget`; SendInventoryAddItem `param3`Ã¢â€ â€™`mergeContext`; ActivateSlot/ResolveCastTarget formals named.

- **New dual reviews:** `A_/B_aa_0093b3a0_Client_Skill_ResolveCastTarget`, `A_/B_aa_009436c0_Client_QuickBar_ActivateSlot`. Prior aa_* duals already on Grab/Drop/DropToGrid/RequestCast/CastFromQB/QBActivateSkillSlot.

- Behavior preserved; runtime/diff/bit-exact still open.



## 2026-07-23 Ã¢â‚¬â€ Manager readability pass (missions / skills / inventory / drive)



- Refined plates + control-flow summaries on manager units: `Client_PacketDispatch`, `Client_AwardKillExperience`, `CVOGCombat_CalculateAndAwardKillXP`, `CVOGReaction_CompleteObjective`, `Client_RecvInventoryEquip`, `Client_RequestCastSkill`, `Client_CastSkillFromQuickBarSlot`, `Client_Input_DriveControlTick`.

- Param renames only where roles clear: PacketDispatch `pCtx`/`pPacket`/`pPayload`; DriveControlTick `pClient`/`pVehicle`. Behavior preserved.

- New A_/B_ dual reviews (with confidence tables) for PacketDispatch, CompleteObjective, RecvInventoryEquip, RequestCastSkill, CastSkillFromQuickBarSlot. Prior A/B kept for AwardKillExperience, CalculateAndAwardKillXP, DriveControlTick.



## 2026-07-23 Ã¢â‚¬â€ Skill cast chain refine + dual reviews



- Cast chain: `LocalCastValidate` `0x0051a790`, `ResolveTargetList` `0x00550300`, `ApplyStatusEffectLocal` `0x0051aa00`, `StartCastAgainHeartbeat` `0x00519200`, `CVOGHBOKToCastAgain_ctor` `0x0051e240`, plus notes for `RecvSkillStatusEffect` / `NPC_TryCastSkillFromSet`.

- Human-refined annotated + clean + function records for ResolveTargetList, ApplyStatusEffectLocal, StartCastAgain, ctor; LocalCastValidate already refined.

- **Dual reviews (reconstruction accept-with-gaps + skeptical needs-more-evidence):** LocalCastValidate (prior), ResolveTargetList (new), ApplyStatusEffectLocal (new).

- Ghidra callers: ResolveTargetList also used by `Client_Skill_ResolveCastTarget` `0x0093b3a0` (player path); Apply by Recv + CastSkillOnTarget.

- Matrix rows + NAMING_REGISTRY + `systems/skills-abilities.md` flow updated. Runtime/diff still open.



## 2026-07-23 Ã¢â‚¬â€ CompleteObjective vertical (human-refine + dual reviews)



- Finished CompleteObjective vertical five units: `CVOGReaction_CompleteObjective` `0x00533f90`, `Mission_ComputeObjectiveXp` `0x0059dde0`, `Mission_ComputeObjectiveCredits` `0x0059df20`, `Client_RecvCompleteDynamicObjective` `0x0080ff00`, `Client_RecvObjectiveState` `0x00809460`.

- Human-refined clean C++ for all five (Xp/Credits/RecvCompleteDynamic from scaffold; CompleteObjective + RecvObjectiveState already refined Ã¢â‚¬â€ caller note fix on CompleteObjective).

- Dual reviews: CompleteObjective (pre-existing accept-with-gaps / needs-more-evidence); ComputeObjectiveXp (new reconstruction + skeptical).

- Upgraded annotated layers for Xp / Credits / RecvCompleteDynamic; function records to human-refined status.

- Verification matrix rows added/updated for the five; runtime/diff/bit-exact remain open.



## 2026-07-23 Ã¢â‚¬â€ Full-coverage goal wave (managers)



- Replanned toward full-coverage goal without claiming completion: **~36** durable units vs **~26256** Ghidra functions.

- WORK_QUEUE: kept WQ-001..006 + WQ-PHY; marked **WQ-003** SetLongitudinalInput **partial** (raw/annotated/clean/record exist; reviews/runtime open).

- Added high-priority manager items: **WQ-007** missions (96), **WQ-008** inventory (94), **WQ-009** skills (93).

- Physics **WQ-PHY** remains **deferred**.

- ACTIVE_WORK Ã¢â€ â€™ multi-system wave (missions + inventory + skills) with exact dual-review next steps.

- RESUME / PROJECT_STATE updated for wave focus and incomplete-coverage snapshot.



## 2026-07-23 Ã¢â‚¬â€ Bootstrap + input-drive-control unit



- Created required durable state files under `docs/reconstruction/`.

- Ensured directories: `architecture/`, `systems/`, `functions/`, `types/`, `evidence/`, `experiments/`, `reviews/`, `raw/`, `reconstructed-exact/`, `modernized-reference/`.

- Indexed prior physics and inventory/motion RE without erasure.

- Selected system `input-drive-control`; unit `aa_004f5620`.

- Added raw/annotated/clean/function artifacts for SetSteerInput (see those paths).

- Added system map `systems/input-drive-control.md`.

- Added pure-gate experiment + tests under `experiments/`.

- Verification matrix: runtime/diff open; unit status partial after independent reviews.

- Reviews: reconstruction accept-with-gaps; skeptical needs-more-evidence on lock naming / soft polarity / full pythonÃ¢â€°Â¡retail.

- Post-review: rename lockÃ¢â€ â€™suppress; document intermediate-null fault; UF-006..008.

