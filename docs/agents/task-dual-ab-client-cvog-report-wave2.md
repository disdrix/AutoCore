# Dual A/B review batch wave 2 — Client_Recv* / Client_Send* / CVOG* (cap 20)

**Date:** 2026-07-23  
**Scope:** `docs/reconstruction/reconstructed-exact` named units matching `Client_Recv*`, `Client_Send*`, `CVOG*` that lacked **both** `A_aa_*` and `B_aa_*` under `docs/reconstruction/reviews/`.  
**Excluded:** Launcher (never).  
**Cap:** 20 pairs (40 files).  
**Continues:** `docs/agents/task-dual-ab-client-cvog-report.md` (wave 1; ~92 remaining).

## Selection

Prefer units with **no** dual reviews. Prioritized:

1. Remaining **Client_Recv*** without duals (2): CharacterLevel, GiveCredits  
2. Gameplay **CVOG*** managers: XP/level, explore bits, create/spawn, sector load triggers, interact FX, cast-again HB (18)

Pre-batch: **99** of 188 candidates missing both A+B (wave-1 report ~92; drift from extra scaffold units / recount).  
Post-batch: **~109 with both A+B**, **~79 still missing** (99 − 20).

## Pairs written

| # | Stable ID | Name | A verdict | B notes |
|---|---|---|---|---|
| 1 | `aa_00810f00` | Client_RecvCharacterLevel | accept-with-gaps | absolute snapshot 0x2017; EAX packet |
| 2 | `aa_0080cac0` | Client_RecvGiveCredits | accept-with-gaps | additive int64; ESI/EDI framing |
| 3 | `aa_005330e0` | CVOGCharacter_LevelDown | accept-with-gaps | no research reverse; current-row lookup |
| 4 | `aa_0052b310` | CVOGCharacter_IsAreaExplored | accept-with-gaps | 1..32 bit test; no XP |
| 5 | `aa_005326b0` | CVOGCharacter_SetAreaExploredBit | accept-with-gaps | missing entry unlock+return; LogicUI 0x20 |
| 6 | `aa_004ce340` | CVOGCharacter_WeaponAllowsKillXpBonus | **accept** | no weapon scan; +0x100/+0xac gate |
| 7 | `aa_004d80b0` | CVOGCombat_CalculateAndAwardKillXP | accept-with-gaps | global scalar BSS 0; spree 5% |
| 8 | `aa_004da630` | CVOGCombat_OnDeathAwardKillXp | accept-with-gaps | convoy ≤4 ~300f; loot tail open |
| 9 | `aa_00533c30` | CVOGReaction_AddExperience | accept-with-gaps | personal scalar; +0x7e level loops |
| 10 | `aa_004c5c30` | CVOGCreature_PostCreateFromPacket | accept-with-gaps | dual-base negative this; elite FX |
| 11 | `aa_004c8b60` | CVOGCreature_SetupGraphics | accept-with-gaps | Y − rlFlyingHeight type 0x12 |
| 12 | `aa_0052f650` | CVOGCharacter_SerializeCreatePacket | accept-with-gaps | field map vs Apply open |
| 13 | `aa_0053cd20` | CVOGCharacter_CreateFromPacket_Thunk0xC0 | **accept** | trampoline → ApplyCreateFromPacket |
| 14 | `aa_00564290` | CVOGSpawnPoint_CreateTemplateVehicle | accept-with-gaps | terrain height + waypoint |
| 15 | `aa_00564700` | CVOGSpawnPoint_SetObjectActiveState | accept-with-gaps | NPC vs non-NPC; helpers open |
| 16 | `aa_005179a0` | CVOGObject_SetInteractSpecialFX | **accept** | +0x130 teardown/attach |
| 17 | `aa_004d35c0` | CVOGSectorMap_AddCharacter | accept-with-gaps | always player on-load trigger |
| 18 | `aa_004cdcc0` | CVOGSectorMap_DoPlayerOnLoadTrigger | accept-with-gaps | TFID E7E0/E4; every add |
| 19 | `aa_004cdd20` | CVOGSectorMap_DoCreatorLoadTrigger | accept-with-gaps | once +0x74; TFID E7E8/EC |
| 20 | `aa_0051e240` | CVOGHBOKToCastAgain_ctor | accept-with-gaps | duration formula; 500ms clamp; type 8 |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **CharacterLevel (0x2017) vs GiveCredits (0x205E):** level packet is **absolute** snapshot (ApplyCharacterLevelPacket); credits are **additive** int64. Do not mix on login restore.
2. **AddExperience kernel:** personal scalar `+0xc54`, max-level soft cap, level loops only when local `+0x7e`. KillPath spree ≠ GiveXP path.
3. **Kill XP client scalar:** `g_flGlobalKillXpScalar` @ `0x00B037F8` is BSS **0** in retail image → local CalculateAndAward often yields 0; server authority or scalar patch required for live numbers.
4. **LevelDown:** reverses skill/attrib from **current** row; **does not** reverse research `+0x580`.
5. **Explore bits:** pure fog flags; **no XP** in Set/IsAreaExplored. Missing continent entry: Unlock then return without bit write same call.
6. **WeaponAllowsKillXpBonus:** name is historical — field gate only (`+0x100`, mode `+0xac!=2`), reused for mission hash policy.
7. **Sector load hooks:** AddCharacter always fires **player** on-load TFID; **creator** once via `+0x74` and distinct TFID pair.
8. **SetupGraphics height:** subtracts `rlFlyingHeight` for creature type 0x12 (pairs with CreateCreature add) — NPC_SPAWN_HEIGHT critical.
9. **OKToCastAgain:** `duration = round(ceil(cd * equipMod)) + chargeDelay`; clamp 500ms when pool `+0x6b4>0`; HB type 8.

## Not done (remaining backlog)

~79 Client_Recv/Send/CVOG units still lack dual A+B (mostly HBAI/HBBase/HBList, terrain, tacarc, objective-requirement leaves, remaining map/variable helpers). Next batch: same filter, cap 20; no Client_Recv/Send left in this filter.

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (40 new files)
- One-shot writer (tmp): `tmp/write_dual_reviews_batch2.py`
- No Launcher touched; no servers started.
