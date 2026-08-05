# Function record: UI_MissionDialog_BuildResponseButtons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac110` |
| **Canonical name** | `UI_MissionDialog_BuildResponseButtons_Inferred` |
| **Ghidra symbol** | `FUN_008ac110` |
| **Address** | `0x008ac110`–`0x008ac318` exclusive (**520** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / mission dialog |
| **Completion status** | **Dual A/B sealed** (WQ7R-B 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- `FUN_008ac110`
- `Mission_i_d_npc_2d_btn_response_xml_008ac110` (legacy string-derived)

## Purpose

Build the NPC mission dialog **response button** strip: grid of NDUI children loaded from `i_d_npc_2d_btn_response.xml`, ids `0x9C46+i`, scaled for 1600×1200 design space.

## Signature (recovered)

```c
// EDI = MissionDialogUi*  (not ECX thiscall in body)
void UI_MissionDialog_BuildResponseButtons_Inferred(void);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008ac110_FUN_008ac110.md`
- Annotated: `docs/reconstruction/raw/aa_008ac110_FUN_008ac110.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_MissionDialog_BuildResponseButtons_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_008ac110.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_008ac110_UI_MissionDialog_BuildResponseButtons_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008ac110_UI_MissionDialog_BuildResponseButtons_Inferred.md`
- Dual report: `docs/agents/task-dual-ab-008ac110-008aa610-wq7rb-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `Client_BuildNpcMissionDialogWidgets`, `Client_ShowNpcMissionDialogUI`, `Client_UpdateMissionJournal`, `FUN_008ac3f0`, `FUN_008ac890` |
| Callees | `FUN_008aa560`, `operator_new`, `FUN_0079c860`, child/dialog vtbls |

## Confidence

| Claim | Level |
|---|---|
| Control flow + grid math | **High** |
| Last-alone flag + row Y (bytes over decomp) | **High** |
| Design scale 1600×1200 | **High** |
| Parameter/product names | **Inferred** |
| Runtime / bit-exact | Open |
