# Verification Matrix

Status codes: `Y` = yes/evidence present Â· `P` = partial Â· `N` = no/open Â· `N/A` = not applicable

**Scope note:** Rows cover selected high-priority function records under `functions/aa_*.md` (including DriveControlTick `aa_009223b0`, which has a full unit record). This is **not** full program coverage of `autoassault.exe`.

**Verification policy:** Runtime, binary/instruction diff, and bit-exact equivalence are **N / open** for all units below until re-proven. Readable reconstruction â‰  verified. No unit is marked complete.

## Functions

| Stable ID | Canonical name | System | Pri | Raw | Boundary | Sig | Types | CF | DF | Sidefx | Callers | Callees | Layout | State | Comm | Persist | Runtime | Diff | Ind.rev | Skep.rev | Docs | Overall status | Open issues | Last reviewed |
|-----------|----------------|--------|-----|-----|----------|-----|-------|----|----|--------|---------|---------|--------|-------|------|---------|---------|------|---------|----------|------|-----------------|-------------|---------------|
| aa_00507950 | CVOGHBList_Tick | heartbeat | 88 | Y | Y | Y | P | Y | Y | Y | Y | Y | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B 2026-07-29; promote+layout+Remove&0x10 sealed | runtime; diff; vtbl+0x18 English; forced-delta producers | 2026-07-29 |
| aa_005081c0 | CVOGHBBase_Start | heartbeat | 88 | Y | Y | Y | P | Y | Y | Y | Y | Y | Y | Y | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B accept; +0x21 dormant + vtbl+4 tail OnStart sealed | runtime; diff; bit-exact; full Enqueue-pairing audit; OnStart English | 2026-07-29 |
| aa_006070e0 | Outpost_CastSkillsForBeaconShare | skills-abilities | 82 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B sealed (ratio gate + mode-0 + flag polarity ≠ Faction); not complete | runtime; diff; bit-exact; vfunc English; invalid-log vs free CF | 2026-07-29 |
| aa_004d09a0 | CVOGReaction_CastSkillOnTarget | skills-abilities | 74 | Y | Y | P | P | Y | P | Y | Y | Y | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed (no-wire-in-unit + layout); not complete | runtime; diff; bit-exact; wire emit unit open | 2026-07-29 |
| aa_00611f20 | CVOGObjectiveRequirement_Collect_Action | missions-progression | 88 | Y | Y | P | P | Y | P | Y | P | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B | runtime; full convoy CF in raw | 2026-07-29 |
| aa_00611290 | Deliver_OnInventoryEvent_Inferred | missions-progression | 84 | Y | Y | P | P | Y | Y | Y | P | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B; name Inferred | eventType 4 enum | 2026-07-29 |
| aa_00610f20 | Deliver_CargoReady_Inferred | missions-progression | 84 | Y | Y | Y | P | Y | Y | Y | P | Y | Y | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed (+0x23 polarity/authorship + RET8 ABI) | runtime; diff; bit-exact; PDB name; server RequireItemToComplete polarity | 2026-07-29 |
| aa_00524520 | FindActiveObjectiveIdForInteract | interaction-activation | 90 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | P | P | N/A | N | N | Y | Y | Y | **partial** — dual A/B; id not bool | runtime; 59d9c0 arity | 2026-07-29 |
| aa_005245d0 | FindActiveObjectiveIdForPick | interaction-activation | 90 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B; sibling +0x44 | runtime; +0x44 implementers | 2026-07-29 |
| aa_005711c0 | InventoryGrid_CountItemsByCbid | inventory-transfer | 88 | Y | Y | P | P | Y | Y | Y | Y | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed (Broken bit19 + TraversalLock) | runtime; diff; bit-exact | 2026-07-29 |
| aa_00611940 | CVOGObjectiveRequirement_Collect_Eval | missions-progression | 88 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed (ABI RET8 + double Count + inv vs 0x2071) | runtime; diff; bit-exact | 2026-07-29 |
| aa_006124b0 | CVOGObjectiveRequirement_Collect_SlotAction | missions-progression | 88 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed (ABI RET10 + stack0 char + double Count + fmt VAs) | runtime; diff; bit-exact; name blob +0x92 English | 2026-07-29 |
| aa_00613910 | CVOGObjectiveRequirement_Kill_Eval | missions-progression | 88 | Y | Y | Y | P | Y | Y | Y | Y | N/A | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed (formula + dual-writer provenance) | runtime; diff; bit-exact | 2026-07-29 |
| aa_0060e0f0 | CVOGObjectiveRequirement_Patrol_Eval | missions-progression | 86 | Y | Y | Y | P | Y | Y | Y | Y | N/A | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed (Laps + absolute slot) | runtime; diff; bit-exact; server zero-edge normalize | 2026-07-29 |
| aa_007fdfb0 | Client_ShowModalPrompt | missions-progression | 90 | Y | Y | P | P | Y | Y | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed (Yes/No + OK/Cancel widget bind) | runtime; diff; bit-exact; flagB matrix | 2026-07-29 |
| aa_00930d70 | Client_SendUseObject_IfInteractable | interaction-activation | 86 | Y | Y | Y | P | Y | Y | Y | P | Y | Y | P | P | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed (gates + e98 char + explicit IDObjective store; 0 not −1 static) | wire 0 vs −1 product; flag/type English; net +0xc78 identity | 2026-07-29 |
| aa_009197a0 | Client_FindFirstObjectInRadius | interaction-activation | 88 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B sealed (15f callers + first-in-radius CF; not min-distance) | runtime; predicate vfunc+0x64; PDB name; multi-obj order | 2026-07-29 |
| aa_004f3620 | VehicleEntity_SetHandbrake | input-drive-control | 89 | Y | Y | Y | P | Y | Y | Y | Y | N/A | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed (ungated +0x61c; consumers; bypass writers) | runtime; diff; bit-exact open | 2026-07-29 |
| aa_004f3a30 | Vehicle_CreateCargoInventoryFromPageCount | inventory-transfer | 76 | Y | Y | Y | P | Y | Y | Y | Y | Y | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B accept-with-gaps; not complete | runtime; diff; bit-exact open; +0x2ac English; grid+0x58 type | 2026-07-29 |
| aa_004f5620 | VehicleEntity_SetSteerInput | input-drive-control | 92 | Y | Y | Y | P | Y | Y | Y | Y | N/A | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** â€” not complete | wobj type; runtime; diff; bit-exact open; suppress-bit meanings; soft polarity is caller-layer | 2026-07-23 |
| aa_004fbc10 | VehicleEntity_PushDriveAxesToController | input-drive-control | 93 | Y | Y | Y | P | Y | Y | Y | Y | P | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed 2026-07-29 (thr/HB bridge + reverse ceiling + speed-cap polarity) | runtime; diff; FUN_004c4e20 body; fStack_40 live init | 2026-07-29 |
| aa_004f5650 | VehicleEntity_SetLongitudinalInput | input-drive-control | 90 | Y | Y | Y | P | Y | Y | Y | P | N/A | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** â€” dual A/B accept-with-gaps; not complete | runtime; diff; bit-exact open; same UF gate questions as SetSteerInput | 2026-07-28 |
| aa_0051a790 | Skill_LocalCastValidate | skills-abilities | 76 | Y | Y | P | P | Y | P | Y | Y | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** â€” human-refined + dual review; not complete | runtime; diff; bit-exact open; prototype plate names falsified; codes 10â€“12 tentative | 2026-07-23 |
| aa_00519200 | Skill_StartCastAgainHeartbeat | skills-abilities | 88 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B quality refresh; ABI RET 0x8 + type-8 sealed | runtime; diff; bit-exact; caller double-start / live stacking | 2026-07-29 |
| aa_0051aa00 | Skill_ApplyStatusEffectLocal | skills-abilities | 84 | Y | Y | Y | P | Y | Y | Y | Y | Y | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed 2026-07-29 (0x2031 map, 0x11 wire/local, WakeupSkill RTTI, overlay offsets) | runtime; diff; bit-exact; +0x614 bit0 English; FUN_00514e20 product | 2026-07-29 |
| aa_0051e240 | CVOGHBOKToCastAgain_ctor | skills-abilities | 90 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual 2026-07-29: ABI RET 0xC + owner/skill + insert pack sealed | runtime; diff; bit-exact; vfunc/+0x6b4 English; GetSkillCdMod body | 2026-07-29 |
| aa_00550300 | Skill_ResolveTargetList | skills-abilities | 90 | Y | Y | P | P | Y | Y | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual 2026-07-29 sealed Filter/RangeCheck + outFlags writers; not complete | runtime; diff; Gather ABI; +0x624 English | 2026-07-29 |
| aa_005d1280 | NPC_TryCastSkillFromSet | skills-abilities | 85 | Y | Y | P | P | Y | P | Y | Y | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual 2026-07-29; entry roles+stride 0x18 sealed; pads INFERRED | runtime; packing asm; return type; world+0x7e | 2026-07-29 |
| aa_00811170 | Client_RecvSkillStatusEffect | skills-abilities | 88 | Y | Y | Y | P | Y | P | Y | Y | P | P | P | Y | N/A | N | N | Y | Y | Y | **partial** — dual A/B; opcode 0x2031 + EAX/ECX framing + ApplyEffects thiscall sealed wave2 | runtime; diff; FUN product names; sector `'c'` emit; world alias | 2026-07-29 |
| aa_00553240 | Skill_AccuracyHitCheck_Inferred | skills-abilities | 86 | Y | Y | Y | P | Y | Y | Y | Y | Y | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B; skill thiscall + sentinel -1 + (roll%100)*0.01 sealed | runtime; diff; score helper 005531d0/004ceba0 product; roll domain | 2026-07-29 |
| aa_005531d0 | Skill_AccuracyScore_Inferred | skills-abilities | 86 | Y | Y | Y | P | Y | Y | Y | Y | Y | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B; skill thiscall RET0xC + float ST0 + cebao pack sealed | runtime; diff; cebao product; 004c4140 English; 0082731b envelope | 2026-07-29 |
| aa_0052aa20 | CVOGCharacter_HasCompletedMission | missions-progression | 70 | Y | P | P | P | P | P | P | P | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** â€” dual A/B; not complete | runtime; diff; bit-exact open; continent/+0xfc/mode-gate semantics | 2026-07-23 |
| aa_0052da30 | CVOGReaction_FailMission | missions-progression | 88 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual: Notify this/body + drain table High; accept-with-gaps lifecycle | runtime; diff; bit-exact; dirty 0x10 readers; FUN_005307e0 dual | 2026-07-29 |
| aa_00531b00 | CVOGMission_AddActiveObjective | missions-progression | 80 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** â€” human-refined + dual tightened A/B; not complete | runtime; diff; bit-exact open; helper English names; vcall+0x28 id; dirty consumers (arity/+0x548/+0x55c sealed 2026-07-29) | 2026-07-29 |
| aa_00525bd0 | Client_FindObjectiveMatchingTarget | missions-progression | 86 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** â€” human-refined + dual review; not complete | runtime; diff; MatchTarget helpers open | 2026-07-23 |
| aa_005327c0 | CVOGReaction_GiveMission | missions-progression | 82 | Y | Y | Y | P | Y | Y | Y | P | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual 2026-07-29; insert roles/+0x544 High; not complete | runtime; diff; bit-exact; +0x544/+0x530 product English; mode object +0xa8 | 2026-07-29 |
| aa_00532b60 | CVOGCharacter_SearchAutoMissions | missions-progression | 75 | Y | P | P | P | P | P | P | P | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** â€” dual A/B; not complete | runtime; diff; bit-exact open; unaff_ESI; auto-flag vs toast field | 2026-07-23 |
| aa_00533f90 | CVOGReaction_CompleteObjective | missions-progression | 96 | Y | Y | Y | P | Y | Y | Y | Y | P | P | Y | N/A | N/A | N | N | Y | Y | Y | **partial** â€” human-refined + dual review; not complete | runtime; diff; bit-exact open; FUN_* callees; flag +0x7e polarity | 2026-07-23 |
| aa_00534920 | CVOGCharacter_EvaluatePendingObjectives | missions-progression | 90 | Y | Y | Y | P | Y | Y | Y | Y | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed 2026-07-29 (slot+CompleteCount+twin+7-callers); not complete | runtime; diff; bit-exact; def+0x138 English; flag names; kind product enum | 2026-07-29 |
| aa_00536080 | CVOGCharacter_CompleteMissionObjectives | missions-progression | 78 | Y | Y | Y | P | Y | Y | Y | Y | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B accept-with-gaps (2026-07-29); not complete | runtime; diff; bit-exact open; mission wrap-up callee-side; sole callers prereq reason=1 | 2026-07-29 |
| aa_00536540 | CVOGCharacter_CheckMissionPrerequisites | missions-progression | 86 | Y | Y | Y | P | Y | Y | Y | Y | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual edges sealed 2026-07-29 (call matrix + RequirementsNegative + prep NPC/AutoAssign); not complete | runtime; diff; bit-exact open; FUN_0052c700 English; XP server authority; client-cmd duals | 2026-07-29 |
| aa_005462b0 | CVOGCharacter_CheckMissionRequirements | missions-progression | 82 | Y | Y | P | P | Y | P | Y | Y | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B residual 2026-07-29 (Ored/Negative/Discipline/Event/ABI sealed); not complete | runtime; diff; bit-exact open; FUN product symbols; server Negative port | 2026-07-29 |
| aa_0054c570 | CVOGReaction_ResolveSkillTargets | skills-abilities | 88 | Y | Y | P | P | Y | P | Y | Y | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed 2026-07-29; not complete | runtime; diff; bit-exact open; name misnomer (materialize not targets); map/ctor FUN_* names | 2026-07-29 |
| aa_00553650 | Skill_ValidateTargetForSkill | skills-abilities | 75 | Y | P | P | P | P | P | P | P | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** â€” dual A/B; not complete | runtime; diff; bit-exact open; handler +0x5f0 / vtbl+0x44 identity | 2026-07-23 |
| aa_00570720 | InventoryGrid_AllocateCellArray_Inferred | inventory-transfer | 74 | Y | Y | P | P | Y | P | Y | Y | P | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B strengthened 2026-07-29; not complete | runtime; diff; bit-exact open; name inferred; empty 8B/-1 + pageH sealed | 2026-07-29 |
| aa_005713a0 | InventoryGrid_FindFreeSlot | inventory-transfer | 82 | Y | Y | P | P | Y | P | Y | Y | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B strengthened 2026-07-29; not complete | runtime; diff; bit-exact open; CanPlace cross-check sealed | 2026-07-29 |
| aa_00571620 | InventoryGrid_PlaceItemFootprint | inventory-transfer | 79 | Y | Y | Y | P | Y | Y | Y | Y | P | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed stamp/ABI 2026-07-29; not complete | runtime; diff; bit-exact open; reject type names open; invType caller-side | 2026-07-29 |
| aa_00572650 | InventoryGrid_ctor_Inferred | inventory-transfer | 73 | Y | P | P | P | P | P | P | P | P | P | P | N/A | N/A | N | N | N | N | P | **partial** â€” not complete | runtime; diff; bit-exact open; dual review pending; name inferred | 2026-07-23 |
| aa_0058d330 | Skill_GatherTargetsInArea | skills-abilities | 74 | Y | P | P | P | Y | P | P | Y | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual 2026-07-29; mode table CF sealed; not complete | runtime; diff; bit-exact open; mode English/PDB names INFERRED | 2026-07-29 |
| aa_0059dde0 | Mission_ComputeObjectiveXp | missions-progression | 92 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed map-node/callers 2026-07-29; not complete | runtime; diff; bit-exact open; table payloads; scaler edges | 2026-07-29 |
| aa_0059df20 | Mission_ComputeObjectiveCredits | missions-progression | 92 | Y | Y | Y | P | Y | Y | Y | Y | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — human-refined + dual residual 2026-07-29; not complete | runtime; diff; bit-exact open; full WAD row dump (schema/Ensure*/ROUND sealed) | 2026-07-29 |
| aa_00809460 | Client_RecvObjectiveState | missions-progression | 90 | Y | Y | Y | P | Y | Y | Y | Y | P | P | P | P | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed (slot float + FUN_0092ce90 UI + no EvaluatePending) | runtime; diff; bit-exact; per-type Action map; UI class names | 2026-07-29 |
| aa_0080ff00 | Client_RecvCompleteDynamicObjective | missions-progression | 90 | Y | Y | Y | P | Y | Y | Y | P | Y | P | P | P | N/A | N | N | N | N | Y | **partial** â€” human-refined; not complete | runtime; diff; bit-exact open; req type-3 enum; UI helper names | 2026-07-23 |
| aa_00811be0 | Client_RecvInventoryGrabResponse | inventory-transfer | 86 | Y | Y | Y | P | Y | Y | Y | Y | P | P | P | P | N/A | N | N | Y | Y | Y | **partial** — dual residual 2026-07-29; dispatch/ABI/fields/helpers sealed; not complete | runtime; diff; bit-exact; busy DAT clear site; PDB helper names | 2026-07-29 |
| aa_00813730 | Client_RecvInventoryDropResponse | inventory-transfer | 86 | Y | Y | Y | P | Y | P | Y | Y | P | P | P | P | N/A | N | N | Y | Y | Y | **partial** — dual residual 2026-07-29; opcode 0x2037 + EAX EAX/EBX Confirmed; not complete | runtime; diff; bit-exact; swap/concat depth; place ECX | 2026-07-29 |
| aa_004fadb0 | Inventory_SerializeAddItemPacket | inventory-transfer | 82 | Y | Y | Y | P | Y | Y | Y | Y | P | P | P | P | N/A | N | N | Y | Y | Y | **partial** â€” human-refined + dual review; not complete | runtime; diff; bit-exact open; stack-mode helpers | 2026-07-23 |
| aa_004fe1b0 | Vehicle_EquipPowerPlant | inventory-transfer | 85 | Y | Y | Y | P | Y | Y | Y | Y | P | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** â€” human-refined + dual review; not complete | runtime; diff; bit-exact open; bind FUN_* names | 2026-07-23 |
| aa_00502090 | Vehicle_SetEquippedArmor | inventory-transfer | 80 | Y | Y | Y | P | Y | Y | Y | P | P | Y | P | N/A | N/A | N | N | N | N | Y | **partial** â€” human-refined; not complete | runtime; diff; bit-exact open; dual review not required this vertical | 2026-07-23 |
| aa_00502460 | Vehicle_SetEquippedRaceItem | inventory-transfer | 80 | Y | Y | Y | P | Y | Y | Y | P | P | Y | P | N/A | N/A | N | N | N | N | Y | **partial** â€” human-refined; not complete | runtime; diff; bit-exact open; dual review not required this vertical | 2026-07-23 |
| aa_00530df0 | Client_SendInventoryAddItem | inventory-transfer | 81 | Y | Y | P | P | Y | Y | Y | P | Y | P | P | P | N/A | N | N | N | N | Y | **partial** â€” human-refined; not complete | runtime; diff; bit-exact open; operator_delete noreturn | 2026-07-23 |
| aa_005721c0 | CVOGReaction_RemoveInventoryItem | inventory-transfer | 78 | Y | Y | Y | P | Y | Y | Y | P | P | P | P | N/A | N/A | N | N | N | N | Y | **partial** â€” human-refined; not complete | runtime; diff; bit-exact open; temp-list structure | 2026-07-23 |
| aa_00813bf0 | Client_RecvInventoryUnequipNotify | inventory-transfer | 88 | Y | Y | Y | P | Y | Y | Y | Y | Y | Y | P | P | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed demux+class map; not complete | runtime; diff; bit-exact open; residual scratch a_00813bf0 | 2026-07-29 |
| aa_00813f40 | Client_RecvInventoryEquip | inventory-transfer | 94 | Y | Y | Y | P | Y | Y | Y | Y | Y | Y | P | P | N/A | N | N | Y | Y | Y | **partial** — dual A/B strengthened 2026-07-29; dual-path class map + wheelset/armor/slots sealed static | runtime; diff; bit-exact open; optional FUN renames | 2026-07-29 |
| aa_00815070 | Client_RecvNpcMissionDialog | missions-progression | 92 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | P | P | N/A | N | N | Y | Y | Y | **partial** — dual residual strengthen 2026-07-29; count **u8** + EBX framing sealed | runtime; diff; bit-exact; FUN product names open | 2026-07-29 |
| aa_008151a0 | Client_RecvInventoryAddItem | inventory-transfer | 77 | Y | Y | P | P | Y | P | P | P | P | P | P | P | N/A | N | N | N | N | Y | **partial** â€” human-refined plate; not complete | runtime; diff; bit-exact open; dual review pending | 2026-07-23 |
| aa_0085f1d0 | Client_UI_InventoryWindow_GetPageHeight | inventory-transfer | 72 | Y | Y | Y | P | Y | Y | N/A | Y | N/A | Y | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** � dual A/B sealed (pageH leaf for Drop Y); not complete | runtime multi-page; typeHost RTTI; retail name; diff | 2026-07-29 |
| aa_00860a50 | Client_UI_InventoryDropToGrid | inventory-transfer | 80 | Y | Y | P | P | Y | P | Y | P | P | P | P | P | N/A | N | N | Y | Y | Y | **partial** â€” human-refined plate + dual review; not complete | runtime; diff; bit-exact open | 2026-07-23 |
| aa_00860e20 | Client_SendInventoryGrab_FromGrid | inventory-transfer | 80 | Y | Y | P | P | Y | P | Y | P | P | P | P | P | N/A | N | N | Y | Y | Y | **partial** â€” human-refined plate + dual review; not complete | runtime; diff; bit-exact open | 2026-07-23 |
| aa_008ae130 | Client_UpdateMissionJournal | missions-progression | 84 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — residual dual sealed (iterator++ + Active/New partition); not complete | runtime; diff; bit-exact open; hash node +0x8 English | 2026-07-29 |
| aa_008ae7c0 | Client_MissionDialogHandleButton | missions-progression | 92 | Y | Y | Y | P | Y | Y | Y | P | P | P | P | P | N/A | N | N | Y | Y | Y | **partial** — 0x206E fill sealed; send via Flush `aa_008ab8f0`; abandon dual-id High (EAX 0x4e46/stack 0x4e47); static e2e→CHAIN abandon_failmission | runtime live; diff; bit-exact; Accepted polarity | 2026-07-29 |
| aa_008ac7a0 | Client_MaybeShowMultiActiveMissionTip_Inferred | missions-progression | 88 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B + ADV PASS 2026-08-04; tip 0x20 if ≥2 active | runtime; payload field English | 2026-08-04 |
| aa_008aaf60 | Client_MissionDialog_SetHeaderCaption_Inferred | missions-progression | 90 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B + ADV PASS; +0x1d8 arity sealed | runtime; widget class English | 2026-08-04 |
| aa_008aab00 | MissionDialog_ParseMarkupToRichText_Inferred | missions-progression | 90 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B + ADV PASS; color/tag matrix sealed | runtime; key-table product English | 2026-08-04 |
| aa_005465c0 | Mission_ExpandPlayerTokenPlaceholders_Inferred | missions-progression | 88 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B + ADV PASS; five tokens sealed | runtime; vtbl English | 2026-08-04 |
| aa_0060d630 | CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress | missions-progression | 92 | Y | Y | Y | P | Y | Y | Y | P | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B 2026-08-04; GiveMission residual on re-eval | runtime; server authority | 2026-08-04 |
| aa_006508d0 | CVOGHBMissionEscort_OnHeartBeat | missions-progression | 90 | Y | Y | Y | P | Y | Y | Y | P | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B 2026-08-04; CompleteObjective/FailMission residual | runtime; vtable bind | 2026-08-04 |
| aa_008ac110 | UI_MissionDialog_BuildResponseButtons_Inferred | missions-progression | 88 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B 2026-08-04; response strip rebuild | runtime; widget English | 2026-08-04 |
| aa_008aa610 | UI_MissionPanel_SyncListScrollbar_Inferred | missions-progression | 84 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B 2026-08-04; scrollbar pages formula | runtime | 2026-08-04 |
| aa_008aa560 | MissionDialog_ClearResponseButtonSlots_Inferred | missions-progression | 86 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B 2026-08-04; 8-slot TFID/widget wipe | runtime; TFID English | 2026-08-04 |
| aa_00829ec0 | UI_MissionJournal_MSelectEntry_Ctor_Inferred | missions-progression | 84 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B 2026-08-04; mselect entry 0x510 ctor | runtime; class English | 2026-08-04 |
| aa_00411180 | StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred | missions-progression | 78 | Y | Y | Y | P | Y | Y | Y | Y | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B + ADV PASS; journal vec consumers among 9 callers | runtime; multi-domain | 2026-08-04 |
| aa_0040b6d0 | StdVector_InsertOne_RebindIt_Via419880_Inferred | missions-progression | 76 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B 2026-08-04; push_back grow path | runtime | 2026-08-04 |
| aa_00521800 | Character_GetRaceDisplayName_Inferred | missions-progression | 82 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B 2026-08-04; [$race] Human/Mutant/Biomek | runtime; ephemeral ring | 2026-08-04 |
| aa_00521900 | Character_GetClassDisplayName_Inferred | missions-progression | 82 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B 2026-08-04; [$class] via FUN_0051f940 | runtime; class table | 2026-08-04 |
| aa_007f5120 | Input_KeyCodeToDisplayName | missions-progression | 80 | Y | Y | Y | P | Y | Y | Y | Y | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B 2026-08-04; DIK/mouse/joy display names | runtime; multi-domain | 2026-08-04 |
| aa_007f9160 | ActionMap_FormatSlotBindDisplay | missions-progression | 82 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B 2026-08-04; MOD+KEY format for [$key] | runtime | 2026-08-04 |
| aa_008ab8f0 | Client_MissionDialog_FlushPreparedResponse | missions-progression | 92 | Y | Y | Y | P | Y | Y | Y | P | Y | P | P | P | N/A | N | N | Y | Y | Y | **partial** — **0x206E send + UF-011 sealed (static)**; dual A/B accept-with-gaps | runtime live; state0 dual-send; bit-exact | 2026-07-29 |
| aa_008abd70 | Client_NpcDialog_PrepareResponseOpcode | missions-progression | 93 | Y | Y | Y | P | Y | Y | Y | P | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual: +0x650=0x206E + ESI/ECX framing + sole Show caller sealed; not complete | runtime; UI FUN_* names; title sprintf; cancel-flush peer | 2026-07-29 |
| aa_00911840 | Client_UiModalDispatch (abandon slice) | missions-progression | 88 | Y | Y | Y | P | Y | Y | Y | P | P | P | P | P | N/A | N | N | Y | Y | Y | **partial** â€” case 0x4e46â†’0x20B2 size 0x18 sealed; full switch not refined | runtime; FUN_007fdfb0 Yes/No pairing | 2026-07-29 |
| aa_0080b100 | Client_RecvFailMission | missions-progression | 90 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | P | P | N/A | N | N | Y | Y | Y | **partial** — UF-012 framing dual residual sealed High (opcode+regs+body; return-ignored; EAX clobber; UI tail) | runtime; bit-exact; FUN_005307e0 dual; DAT_00d1ad10/FUN_0092fd00 product | 2026-07-29 |
| aa_009438f0 | Client_ShowNpcMissionDialogUI | missions-progression | 90 | Y | Y | Y | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** â€” dual residual 2026-07-29: EAX asm + +0x64c handoff sealed; not complete | runtime; diff; chrome FUN_*; +0x648 writer; orphan 0x00924608 | 2026-07-29 |
| aa_00921b50 | Client_QuickBarActivateSkillSlot | skills-abilities | 90 | Y | Y | P | P | Y | Y | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual 2026-07-29: callers 0/1 + visible-list slot + 0x2030 pack/send sealed; not complete | runtime; diff; bit-exact; aim stack residual; +0x615 bit0 product name | 2026-07-29 |
| aa_0093b3a0 | Client_Skill_ResolveCastTarget | skills-abilities | 94 | Y | Y | P | P | Y | P | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual 2026-07-29: hardpoint this/reload/sentinel content + outFlags 4/8 + active-bind pA sealed; not complete | runtime; diff; secondary FUN_* callers; skill+0x614 full glossary; slot-table product word | 2026-07-29 |
| aa_009436c0 | Client_QuickBar_ActivateSlot | skills-abilities | 85 | Y | Y | P | P | Y | P | Y | P | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** â€” human-refined + dual review; not complete | runtime; diff; power window math; type enum seal; FUN_* callees | 2026-07-23 |
| aa_005208c0 | CVOGCharacter_SetQuickBarSkill | skills-abilities | 70 | Y | Y | Y | P | Y | Y | Y | P | N/A | Y | P | N/A | N/A | N | N | N | N | Y | **partial** â€” human-refined trivial setter; not complete | runtime; dual review not required | 2026-07-23 |
| aa_00520890 | CVOGCharacter_SetQuickBarItem | skills-abilities | 70 | Y | Y | Y | P | Y | Y | Y | P | N/A | Y | P | N/A | N/A | N | N | N | N | Y | **partial** â€” human-refined trivial setter; not complete | runtime; dual review not required | 2026-07-23 |
| aa_00941590 | Client_RequestCastSkill | skills-abilities | 90 | Y | Y | P | P | Y | Y | Y | Y | Y | P | P | P | N/A | N | N | Y | Y | Y | **partial** — dual residual 2026-07-29: skillId +0x18 + HB/FX unaff sealed; not complete | runtime; diff; bit-exact; client+0xe04 product type | 2026-07-29 |
| aa_009418e0 | Client_CastSkillFromQuickBarSlot | skills-abilities | 77 | Y | Y | P | P | Y | P | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** â€” human-refined + dual review; not complete | runtime; diff; bit-exact open | 2026-07-23 |
| aa_009223b0 | Client_Input_DriveControlTick | input-drive-control | 88 | Y | Y | P | P | Y | P | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — soft-steer body High; camera locals≠steer sealed High (camera_refresh dual); not complete | runtime; diff; bit-exact; UF-006 labels; UF-003 skills/airborne | 2026-07-29 |
| aa_0054ff00 | Skill_FilterTargetForResolveList_Inferred | skills-abilities | 86 | Y | Y | P | P | Y | Y | Y | Y | P | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B; outFlags 4/8/0x10 sealed | runtime; flag English; bit 0x10 UX; name Inferred | 2026-07-29 |
| aa_004f8b80 | Vehicle_ResolveFirstHardpointOccupantTfid_Inferred | skills-abilities | 84 | Y | Y | P | P | Y | Y | P | Y | N/A | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B accept-with-gaps; name Inferred | runtime; hardpoint product name; stabilizer alias | 2026-07-29 |
| aa_004e2600 | CNDDoubleList_InvokePredicateAndRemove_Inferred | skills-abilities | 80 | Y | Y | P | P | Y | Y | Y | P | P | P | N/A | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B; CNDDoubleList family High; method Inferred | runtime; product method name; CVOGHBList identity | 2026-07-29 |
| aa_005788d0 | CVOGHBSkillBase_ctor | skills-abilities | 90 | Y | Y | Y | P | Y | Y | Y | Y | Y | P | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual residual sealed (ValidateTarget attach=target + type tag + period) | runtime; skill blob glossary; arg4/arg7 English; reject free | 2026-07-29 |
| aa_004f50d0 | Vehicle_FireAllPrimaryWeapons_Inferred | combat | 88 | Y | Y | Y | P | Y | Y | Y | Y | Y | Y | P | N/A | N/A | N | N | Y | Y | Y | **partial** — dual A/B accept-with-gaps; 3-slot +0x260 vtbl+0x38 → FUN_0056d520 OR-return sealed | runtime; diff; bit-exact; product name; FUN_0056d520 dual | 2026-07-29 |

### Confidence by dimension â€” aa_004f5620

| Dimension | Level |
|-----------|-------|
| Function boundary | Confirmed |
| Signature (thiscall, this, float) | High |
| Parameter meaning (steer axis) | High |
| Return meaning (void) | Confirmed |
| Control flow | Confirmed |
| Data flow | High |
| Field layout (+0x618) | High |
| Naming | High (Ghidra symbol + behavior) |
| Side effects | Confirmed (single gated store) |
| State-machine role | Probable (axis sample source) |
| External behavior | High for write; Probable for lock |
| Threading | Unknown (assumed main/client tick) |
| Ownership | Tentative (entity owns fields) |
| Authority | Unknown |
| Overall interpretation | High for gate+store; Probable for lock semantics |

## Systems

| System | Map | Entry points | State transitions | Failure paths | Deps documented | Gaps listed | Status |
|--------|-----|--------------|-------------------|---------------|-----------------|-------------|--------|
| input-drive-control | Y | Y | P | P | Y | Y | **partial** â€” high priority; not complete |
| inventory-transfer | Y | Y | P | P | P | Y | **partial** â€” high priority; not complete |
| skills-abilities | Y | Y | P | P | P | Y | **partial** â€” high priority; not complete |
| missions-progression | Y | Y | P | P | P | Y | **partial** — high priority; WQ-007 residual duals 2026-08-04; not complete |

## Summary counts

| Metric | Count |
|--------|------:|
| Function rows total | **53** (was 37; +16 WQ-007 residual 2026-08-04) |
| Rows from `functions/aa_*.md` | 53 |
| Map-only rows (no unit file yet) | 0 |
| Overall status **complete** | 0 |
| Overall status **partial** | 53 |
| Runtime = N / open | 53 |
| Diff = N / open | 53 |
| Bit-exact sealed | 0 |
| Ind.rev = Y | dualed units including WQ-007 residual batch (all 16 have A/B; ADV sample on A/C/D) |
| Skep.rev = Y | same set as Ind.rev for dualed units |
| Systems indexed partial/high | 4 |
| Full program coverage claimed | **No** |

### By system (unit records only)

| System | Unit rows |
|--------|----------:|
| input-drive-control | 4 (`aa_004f3620`, `aa_004f5620`, `aa_004f5650`, `aa_009223b0`) |
| inventory-transfer | 12 |
| skills-abilities | 8 |
| missions-progression | **29** (was 13; +16 residual duals 2026-08-04) |

## Rules

- Do not claim full verification when runtime/diff/bit-exact are N/open.
- Do not claim full program coverage from this matrix; it tracks selected reconstructed units only.
- Readable â‰  verified. Status remains **partial** until dual review + runtime + diff criteria are met.
- Important units with reviews under `reviews/` set **Ind.rev** / **Skep.rev** to Y only when those review files exist.
- Update this matrix whenever units, reviews, or system maps change.
