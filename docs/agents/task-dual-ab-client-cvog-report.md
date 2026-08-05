# Dual A/B review batch — Client_Recv* / Client_Send* / CVOG* (cap 20)

**Date:** 2026-07-23  
**Scope:** `docs/reconstruction/reconstructed-exact` named units matching `Client_Recv*`, `Client_Send*`, `CVOG*` that lacked **both** `A_aa_*` and `B_aa_*` under `docs/reconstruction/reviews/`.  
**Excluded:** Launcher (never).  
**Cap:** 20 pairs (40 files).

## Selection

Prefer units with **no** dual reviews. Prioritized:

1. All remaining **Client_Recv*** / **Client_Send*** without duals (11)
2. Gameplay-relevant **CVOG*** managers (create/level/quickbar/interact/spawn) (9)

Pre-batch: ~112 of 188 candidates missing both A+B.  
Post-batch: **96 with both A+B**, **92 still missing** (188 − 20 = expected reduction).

## Pairs written

| # | Stable ID | Name | A verdict | B notes |
|---|---|---|---|---|
| 1 | `aa_0080ff00` | Client_RecvCompleteDynamicObjective | accept-with-gaps | force-complete always; opcode plate-only |
| 2 | `aa_008146b0` | Client_RecvCreateCharacter | accept-with-gaps | extended QB via in_AL; seal flag |
| 3 | `aa_008092a0` | Client_RecvGroupReactionCall | accept-with-gaps | 0x206C batch; SetVariable vs fire |
| 4 | `aa_00811170` | Client_RecvSkillStatusEffect | accept-with-gaps | reject empty stub; use full body |
| 5 | `aa_0080cc50` | Client_RecvSpecialEvent | accept-with-gaps | TFID must be character coid |
| 6 | `aa_0092ce00` | Client_SendInstantRepairRequest | accept-with-gaps | 0x20B6 size 4 only |
| 7 | `aa_00826720` | Client_SendQuickBarUpdateFromUi | accept-with-gaps | 0x2062; page*10+col |
| 8 | `aa_007fc100` | Client_SendQuickBarUpdateWithSlot | accept-with-gaps | CL slot packing open |
| 9 | `aa_0092c6d0` | Client_SendUpdateFirstTimeFlags | accept-with-gaps | 0x20B1; char+0xD30 |
| 10 | `aa_00916740` | Client_SendUseObject | accept-with-gaps | 0x2072 + objective or -1 |
| 11 | `aa_00930d70` | Client_SendUseObject_IfInteractable | accept-with-gaps | gates; objective field gap |
| 12 | `aa_00507000` | CVOG_CreateFromPacketDispatch | accept-with-gaps (trampoline) | real work in FUN_004ff850 |
| 13 | `aa_00531e90` | CVOGCharacter_ApplyCharacterLevelPacket | accept-with-gaps | absolute currency/XP; HP gated |
| 14 | `aa_00534bd0` | CVOGCharacter_ApplyCreateFromPacket | accept-with-gaps | schema not fully sealed |
| 15 | `aa_005237a0` | CVOGCharacter_CreateFromPacket | accept-with-gaps | negative this layout open |
| 16 | `aa_00520890` | CVOGCharacter_SetQuickBarItem | **accept** | trivial store + dirty |
| 17 | `aa_005208c0` | CVOGCharacter_SetQuickBarSkill | **accept** | trivial store + dirty |
| 18 | `aa_004d7640` | CVOGObject_EvalInteractStateFromChildren | accept-with-gaps | type 0x12; priority matrix open |
| 19 | `aa_004d5aa0` | CVOGObject_EvalOfferableMissionInteractState | accept-with-gaps | states 6/7 offer icons |
| 20 | `aa_00564f60` | CVOGSpawnPoint_CreateCreature | accept-with-gaps | height path cross-check NPC_SPAWN_HEIGHT |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **CompleteDynamicObjective (0x2070):** always force-completes; do **not** skip when active-hash miss; do **not** emit 0x2070 on dialog deliver turn-in.
2. **SpecialEvent (0x20A9):** fast path TFID is **character** coid at `game+0xe98`, not vehicle — live silent no-op if wrong.
3. **CharacterLevel:** absolute currency/XP/level — sparse packets wipe fields; HP gated, mana always.
4. **QuickBar C2S 0x2062:** FromUi derives slot from page*10+column; WithSlot uses absolute CL — keep distinct.
5. **UseObject siblings:** unconditional path fills objective via `FindObjectiveMatchingTarget`; IfInteractable may leave objective field unset — wire-check before port.
6. **CreateFromPacketDispatch:** trampoline only — follow `FUN_004ff850` / ApplyCreateFromPacket.
7. **SkillStatusEffect clean:** empty stub is non-authoritative; full decomp body is CF source.

## Not done (remaining backlog)

~92 Client_Recv/Send/CVOG units still lack dual A+B (HB/AI, terrain, tacarc, objective-requirement leaf methods, etc.). Next batch can continue same filter, cap 20.

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (40 new files)
- One-shot writer (tmp): `tmp/write_dual_reviews_batch.py`
- No Launcher touched; no servers started.
