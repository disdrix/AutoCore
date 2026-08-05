# Dual A/B review batch wave 3 — CVOGHBAI* / CVOGHB* managers (cap 20)

**Date:** 2026-07-23  
**Scope:** `docs/reconstruction/reconstructed-exact` named units matching `CVOGHBAI*` / `CVOGHB*` that lacked **both** `A_aa_*` and `B_aa_*` under `docs/reconstruction/reviews/`.  
**Excluded:** Launcher (never).  
**Cap:** 20 pairs (40 files).  
**Prior waves:** Client_Recv/Send/CVOG gameplay (`task-dual-ab-client-cvog-report.md`, `task-dual-ab-client-cvog-report-wave2.md`).

## Selection

Prefer **manager** units with **no** dual reviews. Prioritized:

1. **HBAI factory + Driver stack** (CreateByAICode, DoLogic, ReturnToNormalLocation, DoVehiclePursue, DecideHeading, FireWeapons, GetTargetFromAggro, key ctors) — 10  
2. **HB list / base lifecycle** (List Tick/Enqueue, TryFire/Start/Reschedule/ctor) — 6  
3. **HB subclasses** (OKToCastAgain OnStart/OnEnd, Regeneration_OnHeartBeat, MissionPatrol_Tick) — 4  

Pre-batch: **32** of CVOGHBAI*/CVOGHB* clean units missing both A+B.  
Post-batch: **12** still missing both A+B (32 − 20).

Already had duals (skipped): `CVOGHBOKToCastAgain_ctor`, `CVOGHBAICreatureBase_OnHeartBeat`, `CVOGHBAIBase_FindTargetToAttack`.

## Pairs written

| # | Stable ID | Name | A verdict | B notes |
|---|---|---|---|---|
| 1 | `aa_005d3d10` | CVOGHBAI_CreateByAICode | accept-with-gaps | AICode→class map; Character redirect scalars |
| 2 | `aa_005d7750` | CVOGHBAIDriver_DoLogic | accept-with-gaps | +0x26c 0/1/2; FireWeapons always |
| 3 | `aa_005d6e80` | CVOGHBAIDriver_ReturnToNormalLocation | accept-with-gaps | path-vs-pursue gate for DoLogic |
| 4 | `aa_005cfb60` | CVOGHBAICreatureBase_DoVehiclePursue | accept-with-gaps | FPU helpers; ground/air offset |
| 5 | `aa_005d0840` | CVOGHBAICreatureBase_DecideHeading | accept-with-gaps | dt-limited turn; constants open |
| 6 | `aa_005d7100` | CVOGHBAIFollowVehicle_FireWeapons | accept-with-gaps | may-fire + arc masks; angles open |
| 7 | `aa_00638ec0` | CVOGHBAIBase_GetTargetFromAggro | accept-with-gaps | aggro list vs spatial FindTarget |
| 8 | `aa_005d3b30` | CVOGHBAIBase_ctor | accept-with-gaps | base vtbl + zeros; layout names open |
| 9 | `aa_005d3c40` | CVOGHBAICreatureBase_ctor | **accept** | Base chain; size 0x100 |
| 10 | `aa_0063cb50` | CVOGHBAIDriver_ctor | **accept** | CharacterOrMine + Driver vtbl; 0x110 |
| 11 | `aa_00507950` | CVOGHBList_Tick | accept-with-gaps | TryFire; Remove &0x10; pending promote |
| 12 | `aa_005078f0` | CVOGHBList_Enqueue | accept-with-gaps | pending CS; E_INVALIDARG |
| 13 | `aa_005082c0` | CVOGHBBase_TryFire | accept-with-gaps | **16≠regen period**; −1000 sentinel |
| 14 | `aa_005081c0` | CVOGHBBase_Start | **accept** | clear dormant + OnStart only |
| 15 | `aa_00508350` | CVOGHBBase_RescheduleAfterFire | accept-with-gaps | counter vs −1000; 16 token |
| 16 | `aa_00508200` | CVOGHBBase_ctor | **accept** | dormant=1; lastFire=tick |
| 17 | `aa_0051e390` | CVOGHBOKToCastAgain_OnStart | accept-with-gaps | SetIsCasting(1)+stamp |
| 18 | `aa_0051e3b0` | CVOGHBOKToCastAgain_OnEnd | accept-with-gaps | SetIsCasting(0)+cleanup |
| 19 | `aa_005fbea0` | CVOGHBRegeneration_OnHeartBeat | accept-with-gaps | no-dt pulse; 3s/5s; dirty masks |
| 20 | `aa_00650f90` | CVOGHBMissionPatrol_Tick | accept-with-gaps | TFID match; +0xc54 semantics open |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **Driver AI is client sim:** `DoLogic` state machine on `owner+0x26c` (idle/engage/combat). Server should ghost `AiCombatState`; do not assume client tick is authority.
2. **Weapons decoupled from drive:** `FireWeapons` always runs at end of DoLogic — idle path-following drivers still shoot when geometry + may-fire allow.
3. **Path vs pursue:** combat pursue only when `ReturnToNormalLocation` does not handle (map path preferred). NPC_DRIVING path-combat gate.
4. **Factory sizes:** Creature/Bot 0x100; Character/Mine/Driver 0x110; WalkingTurreted/Default 0xD0. AICode is int (float bit-pattern in decomp).
5. **HB 16ms myth:** `g_dwTimedActionDefaultPeriodMs` (16) is **Remove status / list delay token**, not combat regen. Regen period is **3000/5000** from `CVOGHBRegeneration_ctor`.
6. **Combat pool pulse model:** `Regeneration_OnHeartBeat` applies **full rates per pulse (no dt)**. AutoCore `VehicleCombatPool.cs` must not frame-scale if mirroring this path.
7. **TryFire −1000 sentinel:** `nPeriodMs == -1000` skips elapsed gate (combat-pool always-ready schedule); RescheduleAfterFire returns Continue for same sentinel.
8. **Start ≠ Enqueue:** `CVOGHBBase_Start` only clears dormant + OnStart; callers must Enqueue into pending for Tick promote.
9. **OKToCastAgain lifecycle:** OnStart sets casting flag + stamp; OnEnd clears casting; duration math already dual-reviewed on ctor.
10. **MissionPatrol_Tick:** TFID-local/party gate before progress; sibling Fn3/Fn6 may own distance — do not assume this body is full patrol formula.

## Not done (remaining CVOGHB* backlog)

**12** units still lack both A+B:

| Name | Notes |
|---|---|
| `CVOGHBAIBase_Default_ctor` | factory fallback |
| `CVOGHBAIBot_ctor` | AICode 3 |
| `CVOGHBAICharacterOrMine_ctor` | mid parent for Driver |
| `CVOGHBAIWalkingCreatureTurreted_ctor` | AICode 6 |
| `CVOGHBBase_AttachOwnerObject` | owner slot |
| `CVOGHBBase_GetRemainingSeconds` | UI/CD overlay |
| `CVOGHBBase_SetPeriodAndCounter` | period seed |
| `CVOGHBBase_StampLastFireTime` | stamp helper |
| `CVOGHBList_ctor` | list init |
| `CVOGHBMissionPatrol_Fn3` / `Fn6` | patrol siblings |
| `CVOGHBRegeneration_ctor` | 3s/5s period map |

Next batch: remaining 12 HB/HBAI + any other filter, cap 20; no Launcher.

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (40 new files)
- One-shot writer (tmp): `tmp/write_dual_reviews_hbai_wave3.py`
- Report: `docs/agents/task-dual-ab-cvoghb-hbai-report.md`
- No Launcher touched; no servers started.
