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
| `0x00941ac0` | `Client_CastAfterPrompt` | Complete prompt: `*(client+0x30c0)` → `RequestCastSkill` → clear | **dual A/B sealed 2026-07-29** (`reviews/a_00941ac0.md`) |
| `0x0093b3a0` | `Client_Skill_ResolveCastTarget` | Player TFID resolve | **human-refined + dual residual 2026-07-29** (`reviews/a_0093b3a0.md`) |
| `0x009436c0` | `Client_QuickBar_ActivateSlot` | Hotbar slot dispatcher | **human-refined + dual review** |
| `0x008a0ed0` | `QuickBar_SelectPage_Inferred` | QB page 0..9 select (mode-1 / page± / refresh) | **dual A/B 2026-07-29** (accept-with-gaps; `_Inferred`) |
| `0x00520890` | `CVOGCharacter_SetQuickBarItem` | Bind item COID to bar | human-refined (trivial) |
| `0x0051a790` | `Skill_LocalCastValidate` | Local pre-cast checks | **human-refined + dual review** |
| `0x00550300` | `Skill_ResolveTargetList` | TFID list + outFlags | **human-refined + dual residual 2026-07-29** (`reviews/a_00550300.md`) |
| `0x0051aa00` | `Skill_ApplyStatusEffectLocal` | Local 0x2031 apply | **human-refined + dual review** |
| `0x00519200` | `Skill_StartCastAgainHeartbeat` | Optimistic type-8 HB | **human-refined + dual A/B quality refresh (ABI sealed)** |
| `0x0051e240` | `CVOGHBOKToCastAgain_ctor` | CD duration HB ctor | **human-refined + dual residual 2026-07-29** (`reviews/a_0051e240.md`) — ABI RET 0xC / owner-skill / insert sealed |
| `0x00553650` | `Skill_ValidateTargetForSkill` | Target legality (handler + HB list) | **human-refined + dual A/B** |
| `0x005532e0` | `Skill_ValidateTarget_HBSkillListener` | HB skill-base list predicate for ValidateTarget | named (string+RTTI) |
| `0x005788d0` | `CVOGHBSkillBase_ctor` | Skill HB base ctor; ValidateTarget notify=1; attach=target | **named (RTTI Confirmed) + dual residual sealed 2026-07-29** |
| `0x0054ff00` | `Skill_FilterTargetForResolveList_Inferred` | ResolveTargetList filter; outFlags 4/8/0x10 | **named (_Inferred) + dual A/B** |
| `0x0058c0a0` | `Skill_RangeCheckTargetForResolveList_Inferred` | Range helper after filter; return 0 → bit2 | **named (_Inferred) + dual A/B** |
| `0x005538a0` | `Skill_ApplyEffectsOnTarget_Inferred` | Combat/effect apply on resolved TFID; events 4/0xc/0xe/5/6 | **named (_Inferred) + dual A/B** |
| `0x00553240` | `Skill_AccuracyHitCheck_Inferred` | Accuracy hit/miss (`skill+0x24`, `-1` auto-hit; `(roll%100)*0.01`) | **named (_Inferred) + dual A/B 2026-07-29** |
| `0x005531d0` | `Skill_AccuracyScore_Inferred` | Accuracy score (attacker short bonus + `skill+0x24` → `Skill_NonCreatureCastAutoHit`) | **named (_Inferred) + dual A/B 2026-07-29** |
| `0x004f8b80` | `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` | ResolveCastTarget alt TFID helper | **named (_Inferred) + dual A/B** |
| `0x004e2600` | `CNDDoubleList_InvokePredicateAndRemove_Inferred` | CS list walk/remove (ValidateTarget consumer) | **named (_Inferred) + dual A/B** |
| `0x00606d70` | `Outpost_CastSkillsForFaction` | Outpost faction skill bank cast | named (string); calls ValidateTarget |
| `0x006070e0` | `Outpost_CastSkillsForBeaconShare` | Outpost beacon-share skill cast (ratio `+0x24c`, mode-0 targets, flag polarity ≠ Faction) | **named + dual A/B 2026-07-29** (accept-with-gaps) |
| `0x0054c570` | `CVOGReaction_ResolveSkillTargets` | Ranked skill materialize (map miss→null; +0x5f6 rank) | **human-refined + dual residual 2026-07-29** |
| `0x0058d330` | `Skill_GatherTargetsInArea` | Area gather | dual residual 2026-07-29; **mode table CF sealed** (accept-with-gaps; English names INFERRED) |
| `0x004d09a0` | `CVOGReaction_CastSkillOnTarget` | Cast reaction packer (0x2031 local buffer; **no wire in unit**) | **dual residual sealed 2026-07-29** (accept-with-gaps) |
| `0x00811170` | `Client_RecvSkillStatusEffect` | S2C status effect 0x2031 | **human-refined + dual; opcode/framing + ApplyEffects thiscall sealed 2026-07-29 wave2** |
| `0x005d1280` | `NPC_TryCastSkillFromSet` | AI cast from skill-set | **human-refined + dual residual 2026-07-29** (accept-with-gaps; entry roles+stride sealed) |
| `0x005208c0` | `CVOGCharacter_SetQuickBarSkill` | Bind skill to bar | human-refined (trivial) |
| `0x005312c0` | `CVOGCharacter_AddSkillPoints` | Skill points | — |

## Behavioral flow

```
QuickBar / RequestCast
  → Skill_LocalCastValidate (eSkillResponses)
  → Client_Skill_ResolveCastTarget
       → Skill_ResolveTargetList (count + outFlags)
  → optional Skill_StartCastAgainHeartbeat (client optimistic)
  → C2S 0x2030
  → S2C 0x2031 Client_RecvSkillStatusEffect
       → Skill_ApplyStatusEffectLocal (delay / cancel 0x11 / FX)

NPC / reaction:
  NPC_TryCastSkillFromSet or reaction
  → LocalCastValidate (sim) + ResolveTargetList
  → Skill_LocalRangeTargetCheck + Skill_ValidateTargetForSkill
  → CVOGReaction_CastSkillOnTarget → optional ApplyStatusEffectLocal

Outpost:
  Outpost_CastSkillsForFaction / Outpost_CastSkillsForBeaconShare
  → ResolveSkillTargets + ResolveObjectTarget
  → Skill_ValidateTargetForSkill → CastSkillOnTarget
```

## Call graph summary

- DriveControlTick also calls QuickBarActivateSkillSlot on some modes (secondary path).
- `Skill_ResolveTargetList` callers: ResolveCastTarget, CastSkillOnTarget, NPC_TryCastSkillFromSet.
- `Skill_ApplyStatusEffectLocal` callers: RecvSkillStatusEffect, CastSkillOnTarget.

## Data flow / state owners

Skill runtime objects, category cooldown maps, quick-bar slot widgets, cast bindings, type-8 cast-again HB, active-skill HB (`0x674`).

**Client pending target-select (sealed 2026-07-29):** `client+0x30c0` = pending skill id while `Client_PromptSkillTargetSelect` skill path is active (also multi-mode dword for RE/tinker/gadget UI); `client+0x30c4` = show-prompt char. Enter: `CastSkillFromQuickBarSlot` when skill flags `0x800` set and `0x20` clear. Complete: `Client_CastAfterPrompt` (`0x00941ac0`) — EDI=client, ESI=TFID (`obj+0x160`), stack=aim*; `CastBlockFeedback` then `RequestCastSkill(*(client+0x30c0), TFID…, aim)` then Prompt(`-1`,0). Gate: `DAT_00d1d900 != -1` (**absolute** of `client+0x30c0`). ESC: `Client_Input_OnKeyDown_MatchAction` → Prompt(`-1`,0) only (no RequestCast).

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
- ~~Who produces outFlags bit 2 zero-signal~~ **Closed 2026-07-29:** `Skill_RangeCheckTargetForResolveList_Inferred` `0x0058c0a0` (return `g_flZero` → ResolveTargetList ORs bit **2**)
- Seal LocalCastValidate prototype with assembly
- Skill runtime layout vs CVOGHBBase mis-type in ApplyStatusEffectLocal
- Client Recv success vs optimistic CD (do not double-start HB)
- ~~Seal `FUN_004f8b80`~~ **Closed 2026-07-29:** `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` (ResolveCastTarget alt TFID)
- **NPC_TryCastSkillFromSet (`0x005d1280`):** ~~seal entry stride + used field roles~~ **partial 2026-07-29:** stride **0x18 Confirmed**; roles skillId/delayMs/sRank/hpMin/hpMax **High**; pads **INFERRED** no string. Still open: packing asm formal; exact cast-result return type; confirm server-only `world+0x7e`; live AI cast capture (set index / HP-band pick); threat scalar `owner+0x124` vs AI combat
- **Closed 2026-07-29 — `Skill_ValidateTargetForSkill`:** wrapper return **1=valid / 0=reject** (callers); formals **(skill this, target, notifyFlag)**; primary gate handler `+0x5F0` vtbl `+0x44(target,skill,0)` rejects on **1**; accept path walks `target+0xB0` via `CNDDoubleList_InvokePredicateAndRemove_Inferred` (`0x004e2600`) + `Skill_ValidateTarget_HBSkillListener`. Not the player RequestCast primary gate.
- ~~`FUN_005788d0` skill-HB ctor~~ **Closed 2026-07-29:** **`CVOGHBSkillBase_ctor`** — RTTI **Confirmed** `".?AVCVOGHBSkillBase@@"` (COL `0x00aaede0` → type_info `0x00af8cec` on vtbl `PTR_FUN_009d3fdc`); ValidateTarget notify=1; **attach subject = target** (not source); type tag `+0x1c=1` for HBSkillListener; period floor on accept only; supersedes mistaken `CVOGHBSkillCast_ctor_Inferred`
- ~~`FUN_004e2600` product name~~ **Closed (Inferred):** `CNDDoubleList_InvokePredicateAndRemove_Inferred` — method mangling still open
- **Closed 2026-07-29 leave-FUN `FUN_005169c0` (`0x005169c0`):** no string/RTTI; lazy-get `*(this+0x64)` → `operator_new(0x14)` zero `+4…+0x10`; callers **LocalCastValidate** (busy `+0x10`→6) + **ClearActiveCastCounterAndQueueId** + **FUN_0052c780** — exclusive LocalCastValidate **falsified**; do **not** promote `Skill_LazyAllocBusySlot_Inferred`; dual A/B leave-FUN
- **Closed 2026-07-29 leave-FUN `FUN_00518c20` (`0x00518c20`):** no string/RTTI; lazy-get `*(this+0x68)` → `operator_new(0xc)` + `FUN_0058d9c0` empty map shell (twin of `Skill_GetCategoryCooldownMap` @ `+0x6c`); callers **LookupActiveCastBinding** + **ClearCastBindingAndMaybeRestartCd** + **FUN_00518ca0** + **LocalCastValidate** (`*(map+8)!=0` + form →10) — exclusive LocalCast **falsified**; do **not** promote `Skill_GetActiveCastBindingMap[_Inferred]`; dual A/B leave-FUN
- Still open: product type of `skill+0x5F0` handler; full vtbl+0x44 catalog; unbound call sites `0x0057c976` / `0x0057ca3c` / `0x006074f2`; vehicle+0x260 hardpoint vs stabilizer product word; exact CNDDoubleList method symbol

## Verification gaps

Runtime cast trace; binary diff; StartCastAgain dual residual. RecvSkillStatusEffect dual + opcode/framing sealed 2026-07-29. NPC dual residual complete 2026-07-29 (accept-with-gaps; entry roles+stride sealed; pads INFERRED). Residual LocalCast lazy-alloc helpers **`FUN_005169c0` / `FUN_00518c20` dual leave-FUN** (behavior sealed; names withheld).

## Next recommended work

1. ~~Name `FUN_0058c0a0` (range helper after filter)~~ **Closed 2026-07-29:** `Skill_RangeCheckTargetForResolveList_Inferred` — sole caller ResolveTargetList; return 0 → outFlags bit2; dual A/B accept
2. ~~Full refine RecvSkillStatusEffect~~ **partial close 2026-07-29 wave2:** opcode **0x2031** + EAX/ECX framing + null+`'c'` **ApplyEffects thiscall arg map** sealed; still open sector `'c'` emit matrix + runtime + remaining FUN product names
3. FormatFailureMessage string table for eSkillResponses
4. ~~Power-path constants on QuickBar_ActivateSlot type-5~~ **Closed 2026-07-29 (reclassified):** type-5 is **chat-macro bank** (`DAT_00d177c8` + `FUN_00941fb0`/`0x2021`); window `int64(payload)+3000 ∈ [0,14]` (`0xfffff447 = UINT32_MAX-3000`); packing `(idx*3+0x645)*8 ≡ type+8`. Dual residual A/B + `tmp/a_009436c0.md`. Product enum string + chat arg ABI still open.
5. Live AI cast capture for `NPC_TryCastSkillFromSet` (entry roles+stride residual sealed 2026-07-29; packing pads still INFERRED)
6. Catalog skill handler vtbl+0x44 implementations (ValidateTarget legality bodies)
7. LocalCastValidate residuals `FUN_005169c0` / `FUN_00518c20` only if string/RTTI/strong exclusive plate appears (both dual leave-FUN closed 2026-07-29; reopen only on new evidence)
8. ~~`FUN_005538a0`~~ **Closed 2026-07-29:** `Skill_ApplyEffectsOnTarget_Inferred` (call graph + combat events; dual A/B)
