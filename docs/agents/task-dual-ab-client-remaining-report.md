# Dual A/B review batch — ALL remaining Client_* (finish backlog)

**Date:** 2026-07-23  
**Scope:** All remaining `Client_*` clean units under `docs/reconstruction/reconstructed-exact` that lacked **both** standard `A_aa_*` and `B_aa_*` under `docs/reconstruction/reviews/`.  
**Excluded:** Launcher (never).  
**Count:** **43 pairs** (86 files). No 20-cap — finishes wave3 backlog.

## Selection

Pre-batch filter (name-pattern duals missing): **44** `Client_*`.  
Skipped **1** already dual-reviewed under nonstandard names:

| Stable ID | Name | Existing |
|---|---|---|
| `aa_0080ae70` | Client_AwardKillExperience | `A_aa_0080ae70_review.md` / `B_aa_0080ae70_review.md` |

Remaining **43** written with standard `A_aa_<addr>_<Name>.md` / `B_aa_*` naming.

Post-batch: **0** `Client_*` clean units missing both A and B (including address-based match for AwardKillExperience).

## Pairs written

| # | Stable ID | Name | A verdict | B notes |
|---|---|---|---|---|
| 1 | `aa_0081c4d0` | Client_BuildInterfaceOptionsDialog | accept-with-gaps | QB drag-shift + auto-set new mission options UI |
| 2 | `aa_008ad240` | Client_BuildNpcMissionDialogWidgets | accept-with-gaps | heavy MSXML; race with CompleteObjective |
| 3 | `aa_008b96d0` | Client_ChatMacroQuickPhrases | accept-with-gaps | combat callout chat macros |
| 4 | `aa_00941b20` | Client_ConfirmEquipOrCustomizeItem | accept-with-gaps | town/space/permanent-customize gates |
| 5 | `aa_00955eb0` | Client_DebugDumpEntityCombatStats | **accept** | debug dump only |
| 6 | `aa_00954670` | Client_DebugDumpMissionsAndObjectives | **accept** | debug dump only |
| 7 | `aa_009572e0` | Client_DebugListMissionsStatus | **accept** | debug list only |
| 8 | `aa_00402620` | Client_EnqueueCombatFloater_INFERRED | accept-with-gaps | 0x38 elems; XP type=3 at callers |
| 9 | `aa_00723820` | Client_GetMissionCompleteAudioTable | **accept** | once-init DAT_00d20210 |
| 10 | `aa_0080abc0` | Client_HandleConvoyInviteDeclined | accept-with-gaps | reason→toast map |
| 11 | `aa_0091ee20` | Client_INC_ContactCountdownTick | accept-with-gaps | 0x2073 / 0x20B6 option branches |
| 12 | `aa_0095ae10` | Client_LoadGraphicsIniKeys | accept-with-gaps | SET_NEW_MISSION_ACTIVE key |
| 13 | `aa_009365e0` | Client_LoadVogIniConfig | accept-with-gaps | VOG.ini auth/display |
| 14 | `aa_004bb0a0` | Client_LookupObjectByTfid_Inferred | accept-with-gaps | ResolveObjectTarget + vtbl+0x1dc |
| 15 | `aa_0080f7a0` | Client_NotifyConvoyActiveMissionChanged | accept-with-gaps | convoy-leader toast sibling |
| 16 | `aa_008abd70` | Client_NpcDialog_PrepareResponseOpcode | accept-with-gaps | C2S **0x206E** at dialog+0x650 |
| 17 | `aa_008221e0` | Client_OnAuthDisconnected | **accept** | login-fail UX |
| 18 | `aa_009494c0` | Client_OnBadCharacterLoginId | **accept** | bad char ID toast |
| 19 | `aa_008096c0` | Client_OnGlobalForceQuitDialog | accept-with-gaps | multi-login/GM force-quit |
| 20 | `aa_00809c70` | Client_OnInventoryModifyMissingObject | **accept** | missing-object toast |
| 21 | `aa_00809d20` | Client_OnInventoryModifyMissingObjectAlt | **accept** | sibling same string |
| 22 | `aa_0080a410` | Client_OnRefineryAddItemFailure | **accept** | refinery add fail toast |
| 23 | `aa_0080e360` | Client_OnRefineryRemoveItemFailure | accept-with-gaps | multi-reason remove fail |
| 24 | `aa_0080df40` | Client_OnReverseEngineerFailure | accept-with-gaps | RE skill/room/mats fails |
| 25 | `aa_00812de0` | Client_OnServerConnectionTerminated | **accept** | terminated → login |
| 26 | `aa_0080fea0` | Client_OnServerNotAcceptingLogins | **accept** | server closed toast |
| 27 | `aa_00810360` | Client_OnVehicleSwitchFailure | accept-with-gaps | chassis fit / not found |
| 28 | `aa_00726d00` | Client_PlayNamedInterfaceSound | accept-with-gaps | named cue + CS slots |
| 29 | `aa_0093bac0` | Client_PromptSkillTargetSelect | **accept** | target-or-ESC prompt |
| 30 | `aa_0092f4d0` | Client_RefreshLocalCharacterLevelUi | accept-with-gaps | clonebase +0x531/+0x532 HUD |
| 31 | `aa_009306a0` | Client_RefreshMissionDialogChrome | **accept** | game+0x10b0 + FUN_008a05a0 |
| 32 | `aa_00959230` | Client_RegisterDebugSlashCommands | **accept** | debugmissions/castskill/… |
| 33 | `aa_0090b9c0` | Client_SetAnnouncementLabelTextures | **accept** | mission/level/item/medal .dds |
| 34 | `aa_00951e70` | Client_ShowDriverSitHumorMessages | **accept** | easter-egg sit/exit lines |
| 35 | `aa_00931db0` | Client_ShowEquipFailureMessage | accept-with-gaps | reason switch → toasts |
| 36 | `aa_0094caa0` | Client_ShowInventoryFullAcceptMessage | accept-with-gaps | toast **or** C2S **0x208f** |
| 37 | `aa_0080c3c0` | Client_ShowLoginFailureDialog | **accept** | generic login fail |
| 38 | `aa_0093c700` | Client_ShowVendorBuyFailureMessage | accept-with-gaps | stock/full/afford |
| 39 | `aa_00897170` | Client_SkillTrainUiRequest_INFERRED | accept-with-gaps | **0x2059** + optional **0x2062** QB |
| 40 | `aa_0093a3d0` | Client_StanceOrGadgetActivatePath | accept-with-gaps | INFERRED; slots +0xd58; cast-again |
| 41 | `aa_00637c20` | Client_UnpackSpecialMessage | accept-with-gaps | TNL unpack; 0x206c path |
| 42 | `aa_0091b8d0` | Client_UpdateNpcInteractIcons | accept-with-gaps | states 0–8; CoreMission 6/7 |
| 43 | `aa_0081e700` | Client_WriteJoyCustomIni | **accept** | joy_custom.ini Drive+QB template |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **NpcDialog response C2S is 0x206E** (`dialog+0x650`); payload missionId + accepted + npc TFID16 — not 0x2070.
2. **Skill train UI** sends **SkillIncrement 0x2059** and may auto-fill first empty QuickBar then **QuickBarUpdate 0x2062** (empty = item COID `FFFFFFFF`/`FFFFFFFF` and skillId `-1`).
3. **INC countdown** option `+0xc30`: `0` → RespawnInSector **0x2073**, `1` → InstantRepair **0x20B6**, `2` transfer fee-gated.
4. **ShowInventoryFullAcceptMessage** is not toast-only: on fit path sends **0x208f** (0x18) with char TFID; vehicle@`char+0x250` required.
5. **UpdateNpcInteractIcons** state **6 vs 7** from CoreMission flag `mission def+0x169`; FX only when `object+0x4c==0` — race risk with CompleteObjective MSXML.
6. **RefreshMissionDialogChrome** uses chrome root **`game+0x10b0`** (distinct from dialog **`+0x107c`**).
7. **RefreshLocalCharacterLevelUi** copies clonebase **`+0x531/+0x532`** and vtbl **`+0x27c`** into `game+0xeec/+0xee4/+0xee8` — not money.
8. **EnqueueCombatFloater**: queue `+0x04/+0x08/+0x0C`, element **0x38**; XP floater type **3** at GiveXP callers.
9. Many remaining units are **client error/toast UX** (auth disconnect, inventory missing object, refinery/RE/vendor/equip fails) — no server authority.

## Not done

**None** for `Client_*` dual A/B backlog.  
`Client_AwardKillExperience` already dual-reviewed (`*_review.md` names); optional rename to standard `A_aa_*_Client_AwardKillExperience.md` left alone to avoid duplicate pairs.

Other non-`Client_*` clean families may still lack duals if outside this filter.

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (86 new files)
- Writer: `tmp/write_dual_reviews_client_remaining.py`
- Report: `docs/agents/task-dual-ab-client-remaining-report.md`
- No Launcher touched; no servers started.
