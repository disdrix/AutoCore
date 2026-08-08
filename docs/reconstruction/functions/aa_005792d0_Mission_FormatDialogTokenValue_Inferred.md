# Function record: Mission_FormatDialogTokenValue_Inferred (`FUN_005792d0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005792d0` |
| **Canonical name** | `Mission_FormatDialogTokenValue_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_005792d0` |
| **Address** | `0x005792d0`–`0x00579584` (**693 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Classification** | worker |
| **Dual** | R10-014 2026-08-05 — **accept-with-gaps** |
| **Name confidence** | Inferred (strong structural + string + dualed helper evidence; no product plate on function) |

## Role

Mission dialog token-walk helper: resolve **one** typed token descriptor into a display string for the parent builder `FUN_00579fb0`.

## Type map (structural)

| Type | Role |
|---|---|
| 0 | Float / map variable → `sprintf` |
| 1 | Object display name (`vtbl+0x160`) |
| 2 | Class name of object (`0x00521900`) |
| 3 | Race name of object (`0x00521800`) |
| 4 | Faction → race of character, else stub string @ `0x009d4104` |
| 5 | Character/entity display name |
| 6 | Class of character — **writes then returns 0** |

## Related (not owned)

| VA | Name / note |
|---|---|
| `0x00579fb0` | parent token-walk string builder (residual) |
| `0x00578f80` | segment/token parse helper used by parent (residual) |
| `0x00521800` | `Character_GetRaceDisplayName_Inferred` (dualed) |
| `0x00521900` | `Character_GetClassDisplayName_Inferred` (dualed) |
| `0x005465c0` | `Mission_ExpandPlayerTokenPlaceholders_Inferred` — different fixed-placeholder path |

## See also

- Ghidra twin record: `aa_005792d0_FUN_005792d0.md`
- Dual report: `docs/agents/task-dual-ab-005792d0-r10-report.md`
