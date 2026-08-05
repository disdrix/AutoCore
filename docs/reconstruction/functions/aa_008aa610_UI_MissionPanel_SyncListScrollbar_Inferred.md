# Function record: UI_MissionPanel_SyncListScrollbar_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa610` |
| **Canonical name** | `UI_MissionPanel_SyncListScrollbar_Inferred` |
| **Ghidra symbol** | `FUN_008aa610` |
| **Address** | `0x008aa610`–`0x008aa758` exclusive (**328** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / mission panel |
| **Completion status** | **Dual A/B sealed** (WQ7R-B 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- `FUN_008aa610`
- `Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_008aa610` (legacy)

## Purpose

After mission list rebuild, sync panel scrollbar (`+0x700`) from list (`+0x6E0`): hide if unused, else set page count (`+0x704`), thumb `1/pages`, and normalized position.

## Signature (recovered)

```c
// ESI = MissionUiPanel*
void UI_MissionPanel_SyncListScrollbar_Inferred(void);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008aa610_FUN_008aa610.md`
- Annotated: `docs/reconstruction/raw/aa_008aa610_FUN_008aa610.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_MissionPanel_SyncListScrollbar_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_008aa610.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_008aa610_UI_MissionPanel_SyncListScrollbar_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008aa610_UI_MissionPanel_SyncListScrollbar_Inferred.md`
- Dual report: `docs/agents/task-dual-ab-008ac110-008aa610-wq7rb-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_008aaf60` (only code xref) |
| Callees | list/bar virtuals only (no direct FUN_* callees) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + page formula | **High** |
| Offsets + sole caller | **High** |
| Vtbl product English | Tentative |
| Runtime / bit-exact | Open |
