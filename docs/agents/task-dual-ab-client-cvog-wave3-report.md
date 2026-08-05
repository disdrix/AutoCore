# Dual A/B review batch wave 3 — remaining Client_* / CVOG* (cap 20)

**Date:** 2026-07-23  
**Scope:** `docs/reconstruction/reconstructed-exact` named units matching `Client_*` or `CVOG*` that lacked **both** `A_aa_*` and `B_aa_*` under `docs/reconstruction/reviews/`.  
**Excluded:** Launcher (never).  
**Cap:** 20 pairs (40 files).  
**Continues:** prior client/CVOG, HBAI/HB, TacArc/Map/Terrain dual waves.

## Selection

Pre-batch filter scan: **63** clean `Client_*` / `CVOG*` units missing both A+B  
(after concurrent TacArc/Map/Terrain leftovers: chunk/waypoint duals already present).

This batch prioritized:

1. Remaining **CVOG** managers (sector load, map variables, physics, vehicle combat, reaction helpers, roads)
2. **Input** ActionMap / key-down / edge poll chain
3. **Mission UI** HUD refresh / convoy notify / reward toast / hide dialog
4. **First-time tips** bit + maybe-show
5. **QuickBar skill activate** (C2S `0x2030`)

## Pairs written

| # | Stable ID | Name | A verdict | B notes |
|---|---|---|---|---|
| 1 | `aa_004dc510` | CVOGSectorMap_LoadMapFile | accept-with-gaps | trigger COIDs +0xE7D8/E0/E8/F0 |
| 2 | `aa_005afd40` | CVOGVariable_EvaluateComputed | accept-with-gaps | type+0x40; 0xB/0xC hashes; type8 RNG |
| 3 | `aa_0040d260` | CVOGPhysics_ApplyImpulseVector | accept-with-gaps | body+0x3c vtbl+0x50; readiness |
| 4 | `aa_004f9570` | CVOGPlayerVehicle_UpdateTurretAiming | accept-with-gaps | +0x340/+0x344; aim math open |
| 5 | `aa_005fb6a0` | CVOGVehicle_GetWeaponSlotTransform | accept-with-gaps | slot stride 0xC0; even-slot branch |
| 6 | `aa_004e4870` | CVOGReaction_BuildTextParams | **accept** | list insert this+0x04 only |
| 7 | `aa_007a4330` | CVOGReaction_RandomUnitScalar | **accept** | **misnomer** — RNG singleton* |
| 8 | `aa_005e6c40` | CVOGRoadNode_ParseWidthFromTexName | **accept** | last `_` atof → +0x164 |
| 9 | `aa_007f9110` | Client_ActionMap_Init | **accept** | vtbl+zeros+names+DIK |
| 10 | `aa_007f7570` | Client_InitActionDisplayNames | **accept** | strings only; no DIK |
| 11 | `aa_00911030` | Client_Input_OnKeyDown_MatchAction | accept-with-gaps | ESC; shift 0x2A; edge+held |
| 12 | `aa_00925d60` | Client_Input_PollBoundActions | accept-with-gaps | edge consume; QB 0x2030 path |
| 13 | `aa_008066f0` | Client_UpdateObjectiveDisplayHud | accept-with-gaps | mode +0xd1c; Level/Money |
| 14 | `aa_0093a940` | Client_RefreshOpenMissionUiWindows | accept-with-gaps | multi-panel +0x3d8; MSXML |
| 15 | `aa_00944770` | Client_NotifyActiveMissionChanged | accept-with-gaps | convoy leader toast only |
| 16 | `aa_00801760` | Client_MaybeShowFirstTimeTip | accept-with-gaps | +0xD30 bits; hide-all bit31 |
| 17 | `aa_0040ff80` | Client_SetFirstTimeTipBit | **accept** | OR bit id&lt;0x80 at +0xD30 |
| 18 | `aa_00921b50` | Client_QuickBarActivateSkillSlot | accept-with-gaps | C2S **0x2030** size 0x28 |
| 19 | `aa_0092ce50` | Client_HideMissionDialogIfOpen | **accept** | game+0x107c hide/layout |
| 20 | `aa_008ac540` | Client_ShowMissionRewardChatToast | accept-with-gaps | toast only; hash +0x538 |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **`CVOGReaction_RandomUnitScalar` is misnamed:** returns RNG object* (`DAT_00d20c1c`) via once-init — **not** a float unit scalar. Consumers: map var type **8**, terrain solid UV variants.
2. **Map variable types:** `+0x40` type / `+0x4c` value; **0xB** active mission hash `char+0x540`; **0xC** active objective `+0x548`; type **8** uses shared RNG ushort stream × Value × `DAT_00aaa638`.
3. **Sector load trigger COIDs:** OnKill `+0xE7D8`, PerPlayerLoad `+0xE7E0`, CreatorLoad `+0xE7E8`, LastTeam `+0xE7F0` — feed DoPlayer/DoCreator on-load.
4. **Weapon slot stride `0xC0`** from table `veh+0x80`; even-slot special when `+0xc>2`.
5. **ApplyImpulseVector:** rigid body `phys+0x3c`, apply via body vtbl **+0x50**; readiness `+0x44` path.
6. **Input chain:** ActionMap_Init → display names + DIK defaults; OnKeyDown sets held/edge; PollBoundActions consumes edges (QB / UI / UseObject); DriveControlTick is separate held thr/steer/HB.
7. **QuickBar skill:** client sends **C2S 0x2030** (0x28 bytes) with skill id `skill+0x5fc`, TFID from ResolveCastTarget; skip hidden `skill+0x615` bit0.
8. **First-time tips:** bits at `char+0xD30` (id&lt;0x80); hide-all via signed FirstFlags1 bit31 marks without dialog; persist via SendUpdateFirstTimeFlags / account FirstFlags1..4.
9. **Reward chat toast is display-only** — already-received via `char+0x538`; do not confuse with AddExperience grant path.

## Not done (remaining backlog)

Post-batch: **43** still missing both A+B — **all remaining are `Client_*`** (no `CVOG*` left in this filter without duals).

Mostly: failure/toast UI (`On*Failure`, `Show*Message`), debug dumps, login/auth disconnect UX, INI loaders, remaining mission chrome (`RefreshMissionDialogChrome`, `BuildNpcMissionDialogWidgets`), interact icons, skill train UI, joy custom INI.

Next batch: same filter, cap 20; prefer interact / skill / mission chrome over pure failure toasts if prioritizing gameplay.

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (40 new files this wave)
- Writer: `tmp/write_dual_reviews_client_cvog_wave3.py` + `tmp/run_dual_wave3.py`
- Report: `docs/agents/task-dual-ab-client-cvog-wave3-report.md`
- No Launcher touched; no servers started.
