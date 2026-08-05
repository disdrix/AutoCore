# Function record: Mission_ExpandPlayerTokenPlaceholders_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005465c0` |
| **Canonical name** | `Mission_ExpandPlayerTokenPlaceholders_Inferred` |
| **Ghidra name** | `FUN_005465c0` |
| **Address** | `0x005465c0`–`0x005467f5` (566 B measured) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Classification** | worker |
| **Dual** | WQ7R-D 2026-08-04 — **accept-with-gaps** |
| **Name confidence** | Inferred (strong string evidence; no product plate on function) |

## Role

Mission dialog / UI string prep: replace-all of five fixed player placeholders from character state. Not a free-form token parser.

## Token sources

| Token | Source |
|---|---|
| `[$name]` | vtbl `+0x160` |
| `[$class]` | `FUN_00521900` (WQ7R-F) |
| `[$race]` | `FUN_00521800` (WQ7R-F) |
| `[$credits]` | i64 `(+0x720) − (+0x728)` |
| `[$level]` | vtbl `+0x27c` |

## See also

- Ghidra twin record: `aa_005465c0_FUN_005465c0.md`
- Race/class getters: `aa_00521800`, `aa_00521900` (WQ7R-F)
- Dialog consumer: `FUN_008aaf60` (WQ7R-A)
