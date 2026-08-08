# System map: Skills & abilities (client)

| Field | Value |
|---|---|
| System | Skill cast request, quick-bar, local validation, targets, status effects |
| Priority | **High** (user-triggered actions) |
| Program | `autoassault.exe` |
| Status | Map from named Ghidra symbols + decompiles; cast-core dual reviews started |
| Bit-for-bit | Deferred |

## Scope

Client cast initiation, quick-bar activation, local validate/range/target, gather targets, apply local status FX. Server authority for real damage/outcomes not claimed here.

## Known entry points

| Address | Symbol | Role | Unit status |
|--------:|--------|------|-------------|
| `0x00921b50` | `Client_QuickBarActivateSkillSlot` | Quick-bar slot activate | dual-reviewed (prior) |
| `0x00941590` | `Client_RequestCastSkill` | Request cast | **human-refined + dual residual 2026-07-29** (`reviews/a_00941590.md`) |
| `0x009418e0` | `Client_CastSkillFromQuickBarSlot` | Cast from slot | dual-reviewed (prior) |
| `0x0093bac0` | `Client_PromptSkillTargetSelect` | Target-select chrome; **`client+0x30c0` pending skill** | **dual A/B strengthened 2026-07-29** (`reviews/a_0093bac0.md`) |
| `0x00941ac0` | `Client_CastAfterPrompt` | Complete prompt: `*(client+0x30c0)` â†’ `RequestCastSkill` â†’ clear | **dual A/B sealed 2026-07-29** (`reviews/a_00941ac0.md`) |
| `0x0093b3a0` | `Client_Skill_ResolveCastTarget` | Player TFID resolve | **human-refined + dual residual 2026-07-29** (`reviews/a_0093b3a0.md`) |
| `0x009436c0` | `Client_QuickBar_ActivateSlot` | Hotbar slot dispatcher | **human-refined + dual review** |
| `0x008a0ed0` | `QuickBar_SelectPage_Inferred` | QB page 0..9 select (mode-1 / pageÂ± / refresh) | **dual A/B 2026-07-29** (accept-with-gaps; `_Inferred`) |
| `0x00520890` | `CVOGCharacter_SetQuickBarItem` | Bind item COID to bar | human-refined (trivial) |
| `0x0051a790` | `Skill_LocalCastValidate` | Local pre-cast checks | **human-refined + dual review** |
| `0x00550300` | `Skill_ResolveTargetList` | TFID list + outFlags | **human-refined + dual residual 2026-07-29** (`reviews/a_00550300.md`) |
| `0x0051aa00` | `Skill_ApplyStatusEffectLocal` | Local 0x2031 apply | **human-refined + dual review** |
| `0x00519200` | `Skill_StartCastAgainHeartbeat` | Optimistic type-8 HB | **human-refined + dual A/B quality refresh (ABI sealed)** |
| `0x0051e240` | `CVOGHBOKToCastAgain_ctor` | CD duration HB ctor | **human-refined + dual residual 2026-07-29** (`reviews/a_0051e240.md`) â€” ABI RET 0xC / owner-skill / insert sealed |
| `0x00553650` | `Skill_ValidateTargetForSkill` | Target legality (handler + HB list) | **human-refined + dual A/B** |
| `0x005532e0` | `Skill_ValidateTarget_HBSkillListener` | HB skill-base list predicate for ValidateTarget | named (string+RTTI) |
| `0x005788d0` | `CVOGHBSkillBase_ctor` | Skill HB base ctor; ValidateTarget notify=1; attach=target | **named (RTTI Confirmed) + dual residual sealed 2026-07-29** |
| `0x0054ff00` | `Skill_FilterTargetForResolveList_Inferred` | ResolveTargetList filter; outFlags 4/8/0x10 | **named (_Inferred) + dual A/B** |
| `0x0058c0a0` | `Skill_RangeCheckTargetForResolveList_Inferred` | Range helper after filter; return 0 â†’ bit2 | **named (_Inferred) + dual A/B** |
| `0x005538a0` | `Skill_ApplyEffectsOnTarget_Inferred` | Combat/effect apply on resolved TFID; events 4/0xc/0xe/5/6 | **named (_Inferred) + dual A/B** |
| `0x00553240` | `Skill_AccuracyHitCheck_Inferred` | Accuracy hit/miss (`skill+0x24`, `-1` auto-hit; `(roll%100)*0.01`) | **named (_Inferred) + dual A/B 2026-07-29** |
| `0x005531d0` | `Skill_AccuracyScore_Inferred` | Accuracy score (attacker short bonus + `skill+0x24` â†’ `Skill_NonCreatureCastAutoHit`) | **named (_Inferred) + dual A/B 2026-07-29** |
| `0x004f8b80` | `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` | ResolveCastTarget alt TFID helper | **named (_Inferred) + dual A/B** |
| `0x004e2600` | `CNDDoubleList_InvokePredicateAndRemove_Inferred` | CS list walk/remove (ValidateTarget consumer) | **named (_Inferred) + dual A/B** |
| `0x00606d70` | `Outpost_CastSkillsForFaction` | Outpost faction skill bank cast | named (string); calls ValidateTarget |
| `0x006070e0` | `Outpost_CastSkillsForBeaconShare` | Outpost beacon-share skill cast (ratio `+0x24c`, mode-0 targets, flag polarity â‰  Faction) | **named + dual A/B 2026-07-29** (accept-with-gaps) |
| `0x0054c570` | `CVOGReaction_ResolveSkillTargets` | Ranked skill materialize (map missâ†’null; +0x5f6 rank) | **human-refined + dual residual 2026-07-29** |
| `0x0058d330` | `Skill_GatherTargetsInArea` | Area gather | dual residual 2026-07-29; **mode table CF sealed** (accept-with-gaps; English names INFERRED) |
| `0x004d09a0` | `CVOGReaction_CastSkillOnTarget` | Cast reaction packer (0x2031 local buffer; **no wire in unit**) | **dual residual sealed 2026-07-29** (accept-with-gaps) |
| `0x00811170` | `Client_RecvSkillStatusEffect` | S2C status effect 0x2031 | **human-refined + dual; opcode/framing + ApplyEffects thiscall sealed 2026-07-29 wave2** |
| `0x005d1280` | `NPC_TryCastSkillFromSet` | AI cast from skill-set | **human-refined + dual residual 2026-07-29** (accept-with-gaps; entry roles+stride sealed) |
| `0x005208c0` | `CVOGCharacter_SetQuickBarSkill` | Bind skill to bar | human-refined (trivial) |
| `0x005312c0` | `CVOGCharacter_AddSkillPoints` | Skill points | â€” |

## Behavioral flow

```
QuickBar / RequestCast
  â†’ Skill_LocalCastValidate (eSkillResponses)
  â†’ Client_Skill_ResolveCastTarget
       â†’ Skill_ResolveTargetList (count + outFlags)
  â†’ optional Skill_StartCastAgainHeartbeat (client optimistic)
  â†’ C2S 0x2030
  â†’ S2C 0x2031 Client_RecvSkillStatusEffect
       â†’ Skill_ApplyStatusEffectLocal (delay / cancel 0x11 / FX)

NPC / reaction:
  NPC_TryCastSkillFromSet or reaction
  â†’ LocalCastValidate (sim) + ResolveTargetList
  â†’ Skill_LocalRangeTargetCheck + Skill_ValidateTargetForSkill
  â†’ CVOGReaction_CastSkillOnTarget â†’ optional ApplyStatusEffectLocal

Outpost:
  Outpost_CastSkillsForFaction / Outpost_CastSkillsForBeaconShare
  â†’ ResolveSkillTargets + ResolveObjectTarget
  â†’ Skill_ValidateTargetForSkill â†’ CastSkillOnTarget
```

## Call graph summary

- DriveControlTick also calls QuickBarActivateSkillSlot on some modes (secondary path).
- `Skill_ResolveTargetList` callers: ResolveCastTarget, CastSkillOnTarget, NPC_TryCastSkillFromSet.
- `Skill_ApplyStatusEffectLocal` callers: RecvSkillStatusEffect, CastSkillOnTarget.

## Data flow / state owners

Skill runtime objects, category cooldown maps, quick-bar slot widgets, cast bindings, type-8 cast-again HB, active-skill HB (`0x674`).

**Client pending target-select (sealed 2026-07-29):** `client+0x30c0` = pending skill id while `Client_PromptSkillTargetSelect` skill path is active (also multi-mode dword for RE/tinker/gadget UI); `client+0x30c4` = show-prompt char. Enter: `CastSkillFromQuickBarSlot` when skill flags `0x800` set and `0x20` clear. Complete: `Client_CastAfterPrompt` (`0x00941ac0`) â€” EDI=client, ESI=TFID (`obj+0x160`), stack=aim*; `CastBlockFeedback` then `RequestCastSkill(*(client+0x30c0), TFIDâ€¦, aim)` then Prompt(`-1`,0). Gate: `DAT_00d1d900 != -1` (**absolute** of `client+0x30c0`). ESC: `Client_Input_OnKeyDown_MatchAction` â†’ Prompt(`-1`,0) only (no RequestCast).

## External effects

Network cast packets (`0x2030`/`0x2031`); UI cooldowns; combat floaters (related).

## Dependencies

- Input system for key binds
- Targeting / TFID resolve
- Vehicle skill cooldown modifier (`0x0052a9b0`)

## Evidence

Ghidra symbols + 2026-07-23 decompiles; topic `docs/topic-extractions/skill-cast.md`; dual reviews under `reviews/aa_0051a790_*`, `aa_00550300_*`, `aa_0051aa00_*`.

## Confidence

| Area | Level |
|------|-------|
| Named entry addresses | High |
| LocalCastValidate gate ladder | High CF / open ABI plate names |
| ValidateTargetForSkill wrapper ABI | **Confirmed** (asm + callers; dual accept) |
| ResolveTargetList + outFlags | High CF; **bits 1/2 this body; 4/8/0x10 Filter; bit2 via RangeCheck**; residual `reviews/a_00550300.md` |
| ApplyStatusEffectLocal delay branch | High CF; skill layout overlay open |
| Full cast state machine | Partial |
| Runtime | Open |

## Open questions

- ~~Who ORs outFlags bits 4 and 8~~ **Closed 2026-07-29:** `Skill_FilterTargetForResolveList_Inferred` `0x0054ff00` (sole caller ResolveTargetList) ORs **4 / 8 / 0x10**
- ~~Who produces outFlags bit 2 zero-signal~~ **Closed 2026-07-29:** `Skill_RangeCheckTargetForResolveList_Inferred` `0x0058c0a0` (return `g_flZero` â†’ ResolveTargetList ORs bit **2**)
- Seal LocalCastValidate prototype with assembly
- Skill runtime layout vs CVOGHBBase mis-type in ApplyStatusEffectLocal
- Client Recv success vs optimistic CD (do not double-start HB)
- ~~Seal `FUN_004f8b80`~~ **Closed 2026-07-29:** `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` (ResolveCastTarget alt TFID)
- **NPC_TryCastSkillFromSet (`0x005d1280`):** ~~seal entry stride + used field roles~~ **partial 2026-07-29:** stride **0x18 Confirmed**; roles skillId/delayMs/sRank/hpMin/hpMax **High**; pads **INFERRED** no string. Still open: packing asm formal; exact cast-result return type; confirm server-only `world+0x7e`; live AI cast capture (set index / HP-band pick); threat scalar `owner+0x124` vs AI combat
- **Closed 2026-07-29 â€” `Skill_ValidateTargetForSkill`:** wrapper return **1=valid / 0=reject** (callers); formals **(skill this, target, notifyFlag)**; primary gate handler `+0x5F0` vtbl `+0x44(target,skill,0)` rejects on **1**; accept path walks `target+0xB0` via `CNDDoubleList_InvokePredicateAndRemove_Inferred` (`0x004e2600`) + `Skill_ValidateTarget_HBSkillListener`. Not the player RequestCast primary gate.
- ~~`FUN_005788d0` skill-HB ctor~~ **Closed 2026-07-29:** **`CVOGHBSkillBase_ctor`** â€” RTTI **Confirmed** `".?AVCVOGHBSkillBase@@"` (COL `0x00aaede0` â†’ type_info `0x00af8cec` on vtbl `PTR_FUN_009d3fdc`); ValidateTarget notify=1; **attach subject = target** (not source); type tag `+0x1c=1` for HBSkillListener; period floor on accept only; supersedes mistaken `CVOGHBSkillCast_ctor_Inferred`
- ~~`FUN_004e2600` product name~~ **Closed (Inferred):** `CNDDoubleList_InvokePredicateAndRemove_Inferred` â€” method mangling still open
- **Closed 2026-07-29 leave-FUN `FUN_005169c0` (`0x005169c0`):** no string/RTTI; lazy-get `*(this+0x64)` â†’ `operator_new(0x14)` zero `+4â€¦+0x10`; callers **LocalCastValidate** (busy `+0x10`â†’6) + **ClearActiveCastCounterAndQueueId** + **FUN_0052c780** â€” exclusive LocalCastValidate **falsified**; do **not** promote `Skill_LazyAllocBusySlot_Inferred`; dual A/B leave-FUN
- **Closed 2026-07-29 leave-FUN `FUN_00518c20` (`0x00518c20`):** no string/RTTI; lazy-get `*(this+0x68)` â†’ `operator_new(0xc)` + `FUN_0058d9c0` empty map shell (twin of `Skill_GetCategoryCooldownMap` @ `+0x6c`); callers **LookupActiveCastBinding** + **ClearCastBindingAndMaybeRestartCd** + **FUN_00518ca0** + **LocalCastValidate** (`*(map+8)!=0` + form â†’10) â€” exclusive LocalCast **falsified**; do **not** promote `Skill_GetActiveCastBindingMap[_Inferred]`; dual A/B leave-FUN
- Still open: product type of `skill+0x5F0` handler; full vtbl+0x44 catalog; unbound call sites `0x0057c976` / `0x0057ca3c` / `0x006074f2`; vehicle+0x260 hardpoint vs stabilizer product word; exact CNDDoubleList method symbol

## Verification gaps

Runtime cast trace; binary diff; StartCastAgain dual residual. RecvSkillStatusEffect dual + opcode/framing sealed 2026-07-29. NPC dual residual complete 2026-07-29 (accept-with-gaps; entry roles+stride sealed; pads INFERRED). Residual LocalCast lazy-alloc helpers **`FUN_005169c0` / `FUN_00518c20` dual leave-FUN** (behavior sealed; names withheld).

## Next recommended work

1. ~~Name `FUN_0058c0a0` (range helper after filter)~~ **Closed 2026-07-29:** `Skill_RangeCheckTargetForResolveList_Inferred` â€” sole caller ResolveTargetList; return 0 â†’ outFlags bit2; dual A/B accept
2. ~~Full refine RecvSkillStatusEffect~~ **partial close 2026-07-29 wave2:** opcode **0x2031** + EAX/ECX framing + null+`'c'` **ApplyEffects thiscall arg map** sealed; still open sector `'c'` emit matrix + runtime + remaining FUN product names
3. FormatFailureMessage string table for eSkillResponses
4. ~~Power-path constants on QuickBar_ActivateSlot type-5~~ **Closed 2026-07-29 (reclassified):** type-5 is **chat-macro bank** (`DAT_00d177c8` + `FUN_00941fb0`/`0x2021`); window `int64(payload)+3000 âˆˆ [0,14]` (`0xfffff447 = UINT32_MAX-3000`); packing `(idx*3+0x645)*8 â‰¡ type+8`. Dual residual A/B + `tmp/a_009436c0.md`. Product enum string + chat arg ABI still open.
5. Live AI cast capture for `NPC_TryCastSkillFromSet` (entry roles+stride residual sealed 2026-07-29; packing pads still INFERRED)
6. Catalog skill handler vtbl+0x44 implementations (ValidateTarget legality bodies)
7. LocalCastValidate residuals `FUN_005169c0` / `FUN_00518c20` only if string/RTTI/strong exclusive plate appears (both dual leave-FUN closed 2026-07-29; reopen only on new evidence)
8. ~~`FUN_005538a0`~~ **Closed 2026-07-29:** `Skill_ApplyEffectsOnTarget_Inferred` (call graph + combat events; dual A/B)


## WQ-009 residual duals (2026-08-04)

| Address | Symbol | Notes |
|--------:|--------|-------|
| `0x0051b720` | `Rng_CopyUnitTableWindow_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x005749d0` | `VehicleCrew_ContainsMember_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x0040aff0` | `Object_CopyTfid16At228_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x0061fdf0` | `CVOGHBSkill_Virus_OnHeartBeat` | WQ-009 residual dual 2026-08-04 |
| `0x005130e0` | `Object_IsWorldPickupType_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x00943340` | `Client_CycleHostileTarget_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x00943520` | `Client_SelectNearestHostileInRange_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x004bb0d0` | `Object_ResolveTfIdVtbl1dc_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x005190c0` | `Object_EnsureIntKeyMapAt0x15c_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x00519280` | `MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x005194f0` | `Gfx_BindMatDiffuseAmbientEmissive_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x005197b0` | `EnsureFactionsLookupLoaded` | WQ-009 residual dual 2026-08-04 |
| `0x00519d80` | `Object_OnDeath` | WQ-009 residual dual 2026-08-04 |
| `0x0051a120` | `Faction_LookupById` | WQ-009 residual dual 2026-08-04 |
| `0x0051b230` | `Object_CreateFromEmbeddedCbid_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x0051b2a0` | `Object_LazyFillMatColorVecFromMesh_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x0051b310` | `Object_ApplyMaterialBank_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x0051b350` | `ServerCreateFromPacket` | WQ-009 residual dual 2026-08-04 |
| `0x0051b550` | `Object_LoadCloneBaseSkillTrio_Inferred` | WQ-009 residual dual 2026-08-04 |
| `0x00518e30` | `Object_CreateOrRecreateSkillHash_Inferred` | WQ-009 residual dual 2026-08-04 |


## WQ-009 depth residual duals (2026-08-04)

| Address | Symbol | Notes |
|--------:|--------|-------|
| `0x004cbdc0` | `SkillCNDHash_Recreate_Inferred` | WQ-009 depth residual dual 2026-08-04 |
| `0x0051dd60` | `SkillCNDHash_Ctor_Inferred` | WQ-009 depth residual dual 2026-08-04 |
| `0x0051b5d0` | `StdTree_Min_Isnil29` | WQ-009 depth residual dual 2026-08-04 |
| `0x0061f940` | `CVOGHBSkill_Virus_Ctor` | WQ-009 depth residual dual 2026-08-04 |
| `0x0061b6f0` | `CVOGHBSkill_SharedOnHeartBeat_Inferred` | WQ-009 depth residual dual 2026-08-04 |
| `0x004192a0` | `StdTree_Lrotate_Isnil29` | WQ-009 depth residual dual 2026-08-04 |
| `0x004192f0` | `StdTree_Rrotate_Isnil29_Inferred` | WQ-009 depth residual dual 2026-08-04 |
| `0x005755b0` | `VehicleCrew_InsertMember_Inferred` | WQ-009 depth residual dual 2026-08-04 |
| `0x00627be0` | `Skill_ComputeEffectPresenceFlags_Inferred` | WQ-009 depth residual dual 2026-08-04 |
| `0x0040c700` | `List_TraversalUnlock` | WQ-009 depth residual dual 2026-08-04 |
| `0x00578ce0` | `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` | WQ-009 depth residual dual 2026-08-04 |
| `0x007a4170` | `Rng_SampleUnitFloat_Inferred` | WQ-009 depth residual dual 2026-08-04 |
| `0x00421b50` | `StdTree_Max_Isnil29_Inferred` | WQ-009 depth residual dual 2026-08-04 |
| `0x00574a90` | `VehicleCrew_ClearMemberObject_Inferred` | WQ-009 depth residual dual 2026-08-04 |
| `0x0051c7c0` | `Map_EraseRange` | WQ-009 depth residual dual 2026-08-04 |
| `0x0051d880` | `Map_EraseRange_B` | WQ-009 depth residual dual 2026-08-04 |
| `0x007ffef0` | `Client_CombatChat_EmitEventLine_Inferred` | WQ-009 depth residual dual 2026-08-04 |
| `0x0082fb30` | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` | WQ-009 depth residual dual 2026-08-04 |
| `0x00930fc0` | `Ui_ResolveEntityNameColor_Inferred` | WQ-009 depth residual dual 2026-08-04 |
| `0x00553dd0` | `WorldClock_GetQuarterPhase01_Inferred` | WQ-009 depth residual dual 2026-08-04 |


## WQ-009 depth-2 residual duals (2026-08-04)

| Address | Symbol | Notes |
|--------:|--------|-------|
| 0x004cba60 | SkillCNDHash_DestroyBucketTable_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x004cb410 | SkillCNDHash_AllocBucketTable_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x0054fec0 | Skill_StoreEffectPresenceFlags_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x00627ec0 | Skill_ComputeEffectScore_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x00930f40 | Ui_NameColorPalette_WriteArgb_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x0092d580 | Ui_NameColorLevelBand_CopyFloat4_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x0082fe20 | UI_InteractionMenu_PopulateTargetButtons_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x00520330 | Object_SetCrewHostBackLink_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x004cb740 | StdTree_EraseAndRebalance_Isnil29_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x004cbb60 | StdTree_InsertAndRebalance_Isnil29_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x00603830 | StdTree_EraseAndRebalance_Val28_Isnil29_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x00603c90 | StdTree_InsertAndRebalance_Val28_Isnil29_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x00406c40 | StdTree_InsertAndRebalance_Isnil29_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x00409220 | Map_EraseNode_B | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x004c8f00 | Object_CreateCreatureLoadSkills_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x0051bbc0 | Map_FreeSubtree_Isnil29 | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x0051be90 | Map_FreeSubtree_B | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x0051d700 | Map_EraseRange_Isnil1d_Inferred | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x0051d7c0 | Map_EraseRange_Isnil15 | WQ-009 depth-2 residual dual 2026-08-04 |
| 0x0051da30 | Map_Tidy_FreeHead | WQ-009 depth-2 residual dual 2026-08-04 |


## WQ-009 depth-3 residual duals (2026-08-04)

| Address | Symbol | Notes |
|--------:|--------|-------|
| 0x004cb680 | SkillCNDHash_ReleaseChainsToFreelist_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x005a2de0 | StdTree_Buynode_Isnil29_Val24_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x00407e30 | StdTree_Buynode_Val24_Isnil29_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x004c8610 | Object_AggroMap_DecayOrPurge_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x004c8780 | Object_TFIDMap_FindFirstLive_EraseDead_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x004cbaa0 | StdTree_EraseRange_Isnil29_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x004cbe20 | StdMap_InsertOrFind_IntKey_Isnil29_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x004cbee0 | StdMap_InsertOrFind_PairKey_Isnil29_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x004cc220 | StdTree_InsertHint_Isnil29_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x0051be10 | Map_FreeSubtree_Isnil1d | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x0051c880 | Map_EraseNode_Isnil1d_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x0051be50 | Map_FreeSubtree_Isnil15 | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x0051ce00 | Map_EraseNode_Isnil15 | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x0051e120 | Map_Tidy_FreeHead_Isnil1d_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x0051de60 | SkillCNDHash_ScalarDeletingDtor_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x0051e180 | Map_Tidy_FreeHead_B | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x0051f880 | Object_SetHostModeFlag_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x00574880 | ConvoyRoster_GetLeaderMember_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x00553cd0 | WorldClock_GetSkyBlendAmount_Inferred | WQ-009 depth-3 residual dual 2026-08-04 |
| 0x0051d940 | Map_EraseRange_Isnil15_B | WQ-009 depth-3 residual dual 2026-08-04 |


## WQ-009 depth-4 residual duals (2026-08-04)

| Address | Symbol | Notes |
|--------:|--------|-------|
| `0x004cb550` | `StdTree_FreeSubtree_Isnil29_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x0051de80` | `SkillCNDHash_CompleteDtor_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x004cb4f0` | `StdTree_Predecessor_Isnil29_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x00401480` | `StdPairKey_Less_HiSignedLoUnsigned_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x004cc400` | `StdMap_OperatorIndex_Tfid_Isnil29_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x004c9380` | `Object_AggroMap_ExportToIntKeyMap_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x0051bed0` | `Map_FreeSubtree_Isnil15_B` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x0051e1b0` | `Map_Tidy_FreeHead_Isnil15_B` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x006507c0` | `CVOGHBMissionEscort_ctor` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x0051f940` | `LookupClassDisplayName_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x004912c0` | `Env_DayCycle_ApplySkyBlendAndLight_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x00406f00` | `SkillSet_Vector_UninitializedFillN_0x18_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x004cba00` | `StdMap_Find_Tfid_Isnil29_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x00406c00` | `StdTree_FreeSubtree_Isnil29_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x00406de0` | `StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x00406e50` | `StdVector_UninitializedFillN_Elem0x28_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x00406e70` | `StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x00406ee0` | `StdVector_UninitializedFillN_Elem12_Inferred` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x00406f20` | `CNDHash_AllocBucketTable_00a2c2e4` | WQ-009 depth-4 residual dual 2026-08-04 |
| `0x00406fc0` | `CNDHash_DestroyBucketTable_00a2c2e4` | WQ-009 depth-4 residual dual 2026-08-04 |


## WQ-009 depth-5 residual duals (2026-08-04)

| Address | Symbol | Notes |
|--------:|--------|-------|
| `0x004085e0` | `CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x00408050` | `StdVector_InsertN_Elem0x28_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x00409d40` | `StdVector_ConstructN_Elem0x28_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x004082f0` | `StdVector_InsertN_Elem12_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x00406220` | `StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x004062a0` | `StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x004063a0` | `CNDHash_Ctor_00a2c2b0` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x00406420` | `CNDHash_Dtor_00a2c2b0` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x004195d0` | `CNDHash_Recreate_00a2c2e4` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x0060c860` | `CVOGHBMissionEscort_ReactionFactory_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x00407d70` | `Map_EraseRange_C` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x00406560` | `StdTree_InsertHint_Isnil21_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x00942e20` | `Client_FrameTick_EnvDayCycleAndSystems_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x00807550` | `Client_AssignPendingGhostByObjectTfid_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x00408590` | `StdTree_IteratorIncrement_Isnil31` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x00408640` | `StdVector_InsertN_Elem0x10_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x00408880` | `PodCopyConstruct_Elem0x138_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x004088f0` | `StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x00408990` | `StdTree_Buynode_Val16_Isnil21_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |
| `0x00408a30` | `StdTree_BuyHeadNode_Isnil29_Inferred` | WQ-009 depth-5 residual dual 2026-08-04 |


## WQ-009 depth-6 residual duals (2026-08-04)

| Address | Symbol | Notes |
|--------:|--------|-------|
| `0x00416e80` | `FreelistSlabVector_Teardown_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x00409db0` | `StdVector_ConstructN_Elem12_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x00409f30` | `StdVector_PodCopyElement_0x28_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x00407060` | `StdMap_InsertOrFind_PairKey_Isnil21_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x004099b0` | `StdTree_NodeCtor_Val16_Isnil21_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x0040a6e0` | `PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x007fe640` | `Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x00416010` | `StdList_Incsize_Max1fffffff` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x004160b0` | `Class_00a6f61c_ScalarDeletingDtor` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x004160d0` | `CWndVehicle_ScalarDeletingDtor` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x004160f0` | `CWidgetRotateVehicle_ScalarDeletingDtor` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x00416110` | `Class_00a9bbe8_CompleteDtor_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x00416160` | `XformState_AssignSelectiveByFlags_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x00416240` | `FieldBlock_CopyFrom_ClearFlags0xBC_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x00416350` | `Class_00a7000c_ScalarDeletingDtor_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x00416370` | `Mem_ZeroSixDwords_Ecx_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x00416390` | `CriticalSection_Initialize_SehToHresult_Ecx_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x00416590` | `PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |
| `0x004165f0` | `Class_00a70524_ScalarDeletingDtor_Inferred` | WQ-009 depth-6 residual dual 2026-08-04 |


## WQ-009 depth-7 residual duals (2026-08-04)

| Address | Symbol | Notes |
|--------:|--------|-------|
| `0x00409f50` | `StdVector_PodCopyElement_Elem12_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x0040a520` | `StdVector_UninitializedCopy_Elem0x28_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00834520` | `CWndVehicle_CompleteDtor` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00832fa0` | `CWndWaypointIcon_CompleteDtor` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x008327f0` | `CMenuChatlog_CompleteDtor` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x0097a8a0` | `CWndTutorial_CompleteDtor` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00634c50` | `MeshHost_UploadXformPosNormAndIB16_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00833160` | `ShopVehObject_SwapSelectState_ESI_EDI_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00416f00` | `Class_00a733ec_ScalarDeletingDtor_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00409160` | `StdTree_Min_Isnil31` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00409180` | `StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x004094c0` | `StdMap_StringKey_EraseAndRebalance_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00409780` | `StdTree_BuyHeadNode_Isnil2D_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00409820` | `StdTree_Predecessor_Isnil29_Edx_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00409880` | `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x004098d0` | `StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00409920` | `StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00409970` | `StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00409a00` | `HkArray_Elem8_FreeIfOwned_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |
| `0x00409a30` | `GfxParam_LookupAndWrite_Inferred` | WQ-009 depth-7 residual dual 2026-08-04 |


## WQ-009 depth-8 residual duals (2026-08-04)

| Address | Symbol | Notes |
|--------:|--------|-------|
| `0x00409ae0` | `StdVector_UninitCopyTrampoline_Elem0x28_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x00409b80` | `StdTree_DestroyStringAt0C_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x00407b70` | `StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x00407f90` | `StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x00404180` | `StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x00405f20` | `StdTree_ConstructEmpty_Isnil31_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x00406190` | `StdTree_ConstructEmpty_Isnil2D_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x00405bd0` | `StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x00408ed0` | `StdTree_EraseAndRebalance_Isnil31_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x00833d50` | `CWndVehicle_DerivedTeardown_EDI` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x0078ca80` | `CNDUIWndBuffered_CompleteDtor` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x007b5be0` | `CNDUIWindow_CompleteDtor` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x0082d540` | `CVOGMenu_CompleteDtor` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x00792c20` | `CNDUIDialog_CompleteDtor` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x0083ac90` | `ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x00416830` | `Class_00a733ec_Factory_WithFreeCallback_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x004168c0` | `Class_00a733ec_Factory_NullFreeCallback_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x0044e010` | `StdTree_LeftRotate_Isnil2D_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x0042a840` | `StdTree_Rrotate_Isnil2D_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |
| `0x0040a590` | `StdVector_UninitializedCopy_Elem12_Inferred` | WQ-009 depth-8 residual dual 2026-08-04 |

## WQ-009 depth-9 residual duals (2026-08-05)

Nested residual beyond WQ9K (depth-8). Includes **STL/UI helpers under residual depth** (map/tree isnil31/isnil131, list clear, UI complete-dtor leaves, shop list bind/orient) â€” not product skill English.

| Address | Symbol | Notes |
|--------:|--------|-------|
| `0x00404000` | `StdTree_IteratorIncrement_Isnil131` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x00408ad0` | `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x00401bc0` | `Std_OutOfRange_CtorFromString` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x00403e90` | `StdTree_Lrotate_Isnil31_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x00403ee0` | `StdTree_Rrotate_Isnil31_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x004043e0` | `StdTree_Max_Isnil31` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x0076c4d0` | `RdtscTimer_StampAndArm_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x0078c3d0` | `CNDUIWndBuffered_TeardownBufferedOwned_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x007a8580` | `CNDUIWindow_ClearOwnedObject_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x00424060` | `ObjectCsList_DestroyAll_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x00759de0` | `gfxUIWindow_CompleteDtor` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x00797d70` | `UiTextLayout_CompleteDtor_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x007aec70` | `CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x007aff00` | `CNDUIWindow_ReleaseTextLayoutAndNested_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x0082ce20` | `CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x00415e90` | `StdList_Clear_ESI` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x007917c0` | `CNDUIDialog_TeardownChildHash_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x0083a860` | `ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x0083a880` | `ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |
| `0x0083abf0` | `ShopVehList_BindSlotFromListIndexIfMismatch_Inferred` | WQ-009 depth-9 residual dual 2026-08-05 |

## Mega residual duals (2026-08-05)

Nested undualed callees of dualed WQ-009 managers (Skill_HB apply cascade, status reschedule, target sort, quickbar nested, UI/STL residual leaves).

37 dualed units from mega residual partition (MEGA-001..140 complete). Parent merge: dual unique 2428→2568. Runtime Confirmed: none. Terminal: false.

| Address | Symbol | Notes |
|--------:|--------|-------|
| `0x005787a0` | `Skill_HB_RescheduleStatus_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00589bc0` | `Skill_HB_ApplyHeatDelta_Inferred` | mega residual dual 2026-08-05 MERGE-MEGA-005 (accept-with-gaps); residual closed |
| `0x00589c70` | `Skill_HB_ApplyHpDelta_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00589d90` | `Skill_HB_ApplyShieldPool_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0058cc40` | `Skill_HB_ApplyShortAndFloater_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0058d8e0` | `Skill_HB_ApplyMultiArgEffect_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00578ac0` | `Skill_HB_ClearPtrVectorAt6b0_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0061b960` | `Skill_HB_CopyTfid16At668_Inferred` | mega residual dual 2026-08-05 (accept) |
| `0x00802b70` | `Client_SkillHB_OnEndUiCleanup_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00930360` | `Client_SortTargetListByViewAngle_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00403c60` | `StdTree_LowerBound_StringKey_Isnil131_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00404e00` | `CVOGPhysics_WriteNotFullyReadyOut_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00404c60` | `Object_Store16At80_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00409ed0` | `SkillSet_CopyBackward_0x18` | mega residual dual 2026-08-05 (accept) |
| `0x0040a600` | `SkillSet_Vector_UninitializedCopy_0x18_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x005d5cc0` | `CVOGWaypoint_DoFollowObjectShortcutsUpdate` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0082d2b0` | `UI_InteractionMenu_RebuildPopupShell_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0082f810` | `UI_InteractionMenu_AddSendTell_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0082f8d0` | `UI_InteractionMenu_AddIgnoreToggle` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0082f9a0` | `UI_InteractionMenu_AddFriendsToggle` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0082fa60` | `UI_InteractionMenu_AddClanInviteOrKick_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0082fc40` | `UI_InteractionMenu_AddTrade_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0082fd50` | `UI_InteractionMenu_AddNameplateLabel_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0090d400` | `UI_CloseRelatedChrome_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00756be0` | `gfxUIWindow_DetachParent_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00797530` | `UiTextLayout_Finalize_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00988710` | `UiOwnedBlock_CompleteBeforeDelete_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x004271c0` | `StdVector_DestroyRuns_0x80_Inferred` | mega residual dual 2026-08-05 (accept) |
| `0x004401b0` | `gfxUIWindow_ScalarDeletingDtor` | mega residual dual 2026-08-05 (accept) |
| `0x00440ab0` | `StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00440c90` | `StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00440d20` | `StdTree_FreeSubtree_Isnil11_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00441720` | `StdTree_EraseAll_Shell10_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00441960` | `StdTree_EraseRange_Isnil11_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x004166d0` | `CVOGMenu_ScalarDeletingDtor` | mega residual dual 2026-08-05 (accept) |
| `0x00423e50` | `CNDUIWindow_ScalarDeletingDtor` | mega residual dual 2026-08-05 (accept) |
| `0x004280d0` | `CNDUIDialog_ScalarDeletingDtor` | mega residual dual 2026-08-05 (accept) |

Open residual within mega: **none** — final residual `0x00589bc0` MEGA-005 `Skill_HB_ApplyHeatDelta_Inferred` dual A/B sealed (accept-with-gaps); mega **140/140** complete.
