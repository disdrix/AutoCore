# Function record: Client_MissionDialog_SetHeaderCaption_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aaf60` |
| **Canonical name** | `Client_MissionDialog_SetHeaderCaption_Inferred` |
| **Ghidra name** | `FUN_008aaf60` |
| **Address** | `0x008aaf60`–`0x008ab098` |
| **System** | `missions-progression` |
| **Dual** | A/B 2026-08-04 WQ7R-A — **accept-with-gaps** |
| **Runtime Confirmed** | No (`terminal_coverage=false`) |

## Naming rationale

- **Mission dialog** via callers `Client_ShowNpcMissionDialogUI` / `Client_UpdateMissionJournal` and dialog offsets `+0x6e0` / `+0x648`.
- **Header caption** via string resolve + widget text vcalls + clear-vs-set branch on EDI.
- **`_Inferred`**: no PDB/string product name for the function or widget class.

## See also

- Ghidra twin record: `aa_008aaf60_FUN_008aaf60.md`
- Report: `docs/agents/task-dual-ab-008ac7a0-008aaf60-wq7ra-report.md`
