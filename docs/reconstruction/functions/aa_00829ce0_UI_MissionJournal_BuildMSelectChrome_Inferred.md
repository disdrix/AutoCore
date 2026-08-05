# Function record: UI_MissionJournal_BuildMSelectChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829ce0` |
| **Canonical name** | `UI_MissionJournal_BuildMSelectChrome_Inferred` |
| **Ghidra name** | `FUN_00829ce0` |
| **Address** | `0x00829ce0` |
| **Body span** | `00829ce0`–`00829e80` exclusive (**416** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / mission journal |
| **Completion status** | **Dual A/B sealed** (W26-R 2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00829ce0_UI_MissionJournal_BuildMSelectChrome_Inferred.md`, `reviews/B_aa_00829ce0_UI_MissionJournal_BuildMSelectChrome_Inferred.md` |

## Alias

- Scaffold: `FUN_00829ce0`
- Prior auto: `Mission_i_d_npc_2d_btn_mselect_btn_mission_xml_00829ce0`

## Purpose

Construct-time (or rebuild) path for mission-journal **mselect** chrome widgets. Branches on category-mode byte at `+0x4FC`. Mission mode creates button / status / title and reapplies the complete label using the flag already stored at `+0x4FD`. Category mode creates only the category title skin.

Closes residual from W25-G: construct path **does** set AL from `+0x4FD` before calling `UI_MissionJournal_ApplyStatusCompleteLabel_Inferred` (`FUN_00829ac0`).

## Signature

```c
void __fastcall UI_MissionJournal_BuildMSelectChrome_Inferred(MissionJournalPanel* panel);
// ECX = this; SEH frame; plain ret
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00829ce0_FUN_00829ce0.md`
- Annotated: `docs/reconstruction/raw/aa_00829ce0_FUN_00829ce0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_MissionJournal_BuildMSelectChrome_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00829ce0.cpp`
- Prior string clean: `docs/reconstruction/reconstructed-exact/Mission_i_d_npc_2d_btn_mselect_btn_mission_xml_00829ce0.cpp` (superseded by named plate)
- Scaffold record: `docs/reconstruction/functions/aa_00829ce0_FUN_00829ce0.md`

## Callers / callees

**Callees:** `FUN_00792600`, `operator_new`, `FUN_0079c860`, `FUN_007b5dd0`, `FUN_00829ac0`.

**Callers:** DATA at `0x00a748c0` only (indirect / vtbl-adjacent).

**Peers:** `UI_MissionJournal_ApplyStatusCompleteLabel_Inferred` (`00829ac0`), `UI_MissionJournal_SelectMission_Inferred` (`00829b20`), entry ctor context via `Client_UpdateMissionJournal` (`008ae130` dual).

## Confidence

| Claim | Level |
|---|---|
| Widget build CF + offsets | **Confirmed** |
| Construct AL handoff to `00829ac0` | **Confirmed** |
| Role = mselect chrome builder | **High** (XML + offsets + peers) |
| Product C++ method name | **Inferred** |

## Dual verdict

**accept-with-gaps**
