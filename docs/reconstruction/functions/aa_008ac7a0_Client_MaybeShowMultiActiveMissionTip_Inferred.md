# Function record: Client_MaybeShowMultiActiveMissionTip_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac7a0` |
| **Canonical name** | `Client_MaybeShowMultiActiveMissionTip_Inferred` |
| **Ghidra name** | `FUN_008ac7a0` |
| **Address** | `0x008ac7a0`–`0x008ac884` |
| **System** | `missions-progression` |
| **Dual** | A/B 2026-08-04 WQ7R-A — **accept-with-gaps** |
| **Runtime Confirmed** | No (`terminal_coverage=false`) |

## Naming rationale

- **Mission domain** via sole caller `Client_MissionDialogHandleButton` accept path + hash `+0x540` (active missions).
- **Tip** via sealed callee `Client_MaybeShowFirstTimeTip(0x20)`.
- **Multi-active** via count threshold `≥ 2`.
- **`_Inferred`**: no PDB/product English for tip `0x20` or payload fields `+0xf8/+0xfc`.

## See also

- Ghidra twin record: `aa_008ac7a0_FUN_008ac7a0.md`
- Report: `docs/agents/task-dual-ab-008ac7a0-008aaf60-wq7ra-report.md`
