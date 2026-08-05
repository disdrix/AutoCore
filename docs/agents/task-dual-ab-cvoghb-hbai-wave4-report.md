# Dual A/B review batch wave 4 — remaining CVOGHBAI* / CVOGHB* (cap 12)

**Date:** 2026-07-23  
**Scope:** The **12** `CVOGHBAI*` / `CVOGHB*` clean units listed as still missing both `A_aa_*` and `B_aa_*` after wave 3 (`task-dual-ab-cvoghb-hbai-report.md`).  
**Excluded:** Launcher (never).  
**Cap:** 12 pairs (24 files).  
**Prior:** Wave 3 HBAI/HB managers (20 pairs).

## Selection

Exact backlog from wave 3 “Not done”:

1. HBAI ctors: Default, Bot, CharacterOrMine, WalkingCreatureTurreted  
2. HBBase helpers: AttachOwnerObject, GetRemainingSeconds, SetPeriodAndCounter, StampLastFireTime  
3. HBList_ctor  
4. MissionPatrol Fn3 / Fn6  
5. Regeneration_ctor  

Pre-batch: **12** missing both A+B.  
Post-batch: **0** of this backlog remaining (filter re-scan after write).

## Pairs written

| # | Stable ID | Name | A verdict | B notes |
|---|---|---|---|---|
| 1 | `aa_0063c940` | CVOGHBAIBase_Default_ctor | **accept** | fallback 0xD0; WalkingTurreted parent |
| 2 | `aa_005d3cf0` | CVOGHBAIBot_ctor | **accept** | AICode 3; CreatureBase; 0x100 |
| 3 | `aa_0063d0b0` | CVOGHBAICharacterOrMine_ctor | accept-with-gaps | mid 0x110; Driver parent; float seeds |
| 4 | `aa_00639830` | CVOGHBAIWalkingCreatureTurreted_ctor | **accept** | AICode 6; 0xD0; factory skips profile trio |
| 5 | `aa_005083b0` | CVOGHBBase_AttachOwnerObject | **accept** | +0x18 owner; +0xB0 list gates |
| 6 | `aa_00508280` | CVOGHBBase_GetRemainingSeconds | accept-with-gaps | UI s remaining; period offset residual |
| 7 | `aa_005081a0` | CVOGHBBase_SetPeriodAndCounter | **accept** | +0x0C / optional +0x10 |
| 8 | `aa_00508270` | CVOGHBBase_StampLastFireTime | **accept** | lastFire = client tick |
| 9 | `aa_00507d10` | CVOGHBList_ctor | accept-with-gaps | CS; active≥1000; pending≥100 |
| 10 | `aa_00650e50` | CVOGHBMissionPatrol_Fn3 | accept-with-gaps | resolve + Eval 0xb / FailMission |
| 11 | `aa_00650de0` | CVOGHBMissionPatrol_Fn6 | accept-with-gaps | soft progress; no FailMission; FUN_005083f0 |
| 12 | `aa_005fbdb0` | CVOGHBRegeneration_ctor | accept-with-gaps | −1000 sentinel; **3s/5s** race map |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **Factory ctor chain complete:** Default → WalkingTurreted parent; Bot → CreatureBase; CharacterOrMine mid (1/4) is Driver parent (5); sizes **0x100 / 0x110 / 0xD0** confirmed on leaves.
2. **AICode 6 skips profile trio** at factory; Default shares WalkingTurreted mid + `FUN_0063a700(0)` + `[0x1f]=1.0`.
3. **AttachOwnerObject:** HB `+0x18` owner; owner list only when `owner+0xB0` non-null; detach then attach helpers.
4. **SetPeriodAndCounter** writes **+0x0C** (and optional **+0x10** only). Regeneration sets **pulse ms at +0x08** after `(-1000,true)` — dual field layout residual vs TryFire Ghidra `nPeriodMs` name.
5. **StampLastFireTime** is a one-liner seed for cast-again / manual arm; TryFire also stamps on successful OnHeartBeat.
6. **GetRemainingSeconds** is **UI-only** (ms→s); multi-counter inflates remaining; not list schedule authority.
7. **HBList_ctor:** critical section spin 4000; active floor **1000** / pending floor **100**; seeds `g_dwClientTickMs`.
8. **Regeneration_ctor period map:** override or race Human/Biomek/Tribe → **3000** else **5000**; still **not 16** (Remove status). Reinforces OnHeartBeat no-dt pulse contract for `VehicleCombatPool.cs`.
9. **MissionPatrol_Fn3 vs Fn6:** Fn3 can **FailMission** or progress (`EvaluatePendingObjectives` type **0xb**) after `ResolveObjectTarget`; Fn6 is soft progress + always `FUN_005083f0` cleanup — no fail. Tick still owns TFID/party match; distance/resolve not assumed finished in Tick alone.
10. **CharacterOrMine** seeds four floats `[0x38..0x3b]=1.0` and clears large mid zero block — required before trusting Driver_DoLogic field map.

## Not done / residual (not dual-missing)

Wave-4 named backlog duals are **complete**. Open technical residuals (do not block dual presence):

| Residual | Notes |
|---|---|
| HB layout `+0x08` pulse vs `+0x0C` sentinel | Unify names across TryFire / Reschedule / GetRemaining / Regeneration plates |
| `FUN_0063a700` / `FUN_005083f0` / list grow helpers | Still FUN_* |
| MissionPatrol packed `+0x24` / `DAT_00af5174` / char `+0xfc` | Semantics open |
| Mid HBAI `[0x30..0x43]` names | Driver/Character port risk |
| Runtime / bit-exact / differential | Still deferred on all units |

Next batch: other filter (non-HBAI/HB) units still missing dual A+B; no Launcher.

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (24 new files)
- One-shot writer (tmp): `tmp/write_dual_reviews_hbai_wave4.py`
- Report: `docs/agents/task-dual-ab-cvoghb-hbai-wave4-report.md`
- No Launcher touched; no servers started.
