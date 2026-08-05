# Function record: UI_MissionJournal_ApplyStatusCompleteLabel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829ac0` |
| **Canonical name** | `UI_MissionJournal_ApplyStatusCompleteLabel_Inferred` |
| **Ghidra name** | `FUN_00829ac0` |
| **Address** | `0x00829ac0` |
| **Body range** | `0x00829ac0`–`0x00829aff` exclusive (**64** B / `0x40`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / missions-progression / mission journal |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes + ABI + string sealed; product flag semantics open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00829ac0_UI_MissionJournal_ApplyStatusCompleteLabel_Inferred.md`, `reviews/B_aa_00829ac0_UI_MissionJournal_ApplyStatusCompleteLabel_Inferred.md` (2026-07-29 W25-G) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00829ac0`
- `Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_00829ac0` (legacy chain seed)
- W24-J sketch "RefreshObjectiveList" — **superseded / falsified** by this dual

## Purpose

Store complete-flag byte on the mission-journal panel (`+0x4fd`) and update the status widget (`+0x50c`) text to clear or `"(complete)"`, then refresh the widget.

## Signature

```c
// Register ABI (decomp shape)
void FUN_00829ac0(void); // ESI=JournalPanel*, AL=completeFlag

// Explicit form
void UI_MissionJournal_ApplyStatusCompleteLabel_Inferred(
    JournalPanel* panel, uint8_t completeFlag);
// plain ret; or tail-jmp status->vtbl+0x34c
```

## Algorithm

1. `status = panel->statusWidget (+0x50c)`; `panel->completeFlag (+0x4fd) = AL`.
2. If `status == null` return.
3. If AL == 0: `SetText(status, null, 1, 1)` via vtbl+0x1d8.
4. Else: `SetText(status, "(complete)", 1, 1)`.
5. Reload status; tail to vtbl+0x34c refresh.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00829ac0_FUN_00829ac0.md`
- Annotated: `docs/reconstruction/raw/aa_00829ac0_FUN_00829ac0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_MissionJournal_ApplyStatusCompleteLabel_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00829ac0.cpp`
- Legacy alias: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_00829ac0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0051c1c0-00829ac0-w25g-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | indirect only: status `vtbl+0x1d8` (SetText), `vtbl+0x34c` (Refresh, tail) |
| **Callers** | `UI_MissionJournal_SelectMission_Inferred` @ `0x00829b20` (after `CVOGCharacter_IsMissionJournalReady`); `FUN_00829ce0` @ status build |

## Confidence

| Claim | Level |
|---|---|
| Control flow + full body bytes | **High** |
| ESI panel / AL flag ABI | **High** |
| Offsets +0x4fd / +0x50c | **High** |
| String `"(complete)"` @ `0x00a7496c` | **High** |
| SetText args (text,1,1) both arms | **High** (bytes) |
| Status widget identity (build path) | **High** |
| Product English name | **Inferred** |
| AL = mission-complete vs journal-ready | **Probable** (SelectMission feeds IsMissionJournalReady AL) |
| Construct-time caller AL intent | **Tentative** |
| Runtime / differential | Open |

## Related

- Parent select: `aa_00829b20` `UI_MissionJournal_SelectMission_Inferred` (W24-J)
- Ready predicate: `aa_0052b3b0` `CVOGCharacter_IsMissionJournalReady`
- Journal update parent: `aa_008ae130` `Client_UpdateMissionJournal`
