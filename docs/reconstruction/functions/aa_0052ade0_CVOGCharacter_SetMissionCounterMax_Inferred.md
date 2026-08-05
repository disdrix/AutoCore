# Function record: CVOGCharacter_SetMissionCounterMax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052ade0` |
| **Canonical name** | `CVOGCharacter_SetMissionCounterMax_Inferred` |
| **Ghidra symbol** | `FUN_0052ade0` |
| **Address** | `0x0052ade0`–`0x0052ae21` (**66 B**) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | `missions-progression` (mission-adjacent) |
| **Completion status** | **Dual complete (accept-with-gaps)** W37-P |

## Purpose

Set Val12 mapped field **`node+0x10`** (inferred **max**) for an existing counter key, clamped to not exceed **`node+0x14`** (current, written by Set/Add), and mark character dirty **`0x40`**. Does not create entries.

## Signature

```c
void __thiscall CVOGCharacter_SetMissionCounterMax_Inferred(
    int character, uint32_t key, int32_t value); /* ret 8 */
```

## Related sealed siblings

| VA | Name | Field |
|---|---|---|
| `0x005305b0` | `CVOGCharacter_SetMissionCounter` | write `+0x14` (insert on miss) |
| `0x00530610` | `CVOGCharacter_AddMissionCounter` | `+= +0x14` |
| `0x0052ada0` | GetResourceBalance path | read `+0x10` |

## Artifacts

- See `aa_0052ade0_FUN_0052ade0.md`
- Agent report: `docs/agents/task-dual-ab-0045dd60-0052ade0-w37p-report.md`
