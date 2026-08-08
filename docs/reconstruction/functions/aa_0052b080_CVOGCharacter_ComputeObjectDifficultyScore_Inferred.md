# Function record (named): CVOGCharacter_ComputeObjectDifficultyScore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b080` |
| **Inferred name** | `CVOGCharacter_ComputeObjectDifficultyScore_Inferred` |
| **Ghidra name** | `FUN_0052b080` |
| **VA** | `0x0052b080` |
| **System** | `skills-abilities` |
| **Dual** | R13-035 A/B accept-with-gaps (2026-08-05, dual start 2686) |
| **Terminal** | **false** |

See sibling record `aa_0052b080_FUN_0052b080.md` for full seals, callers, and artifacts.

```c
float __thiscall CVOGCharacter_ComputeObjectDifficultyScore_Inferred(
    void *character /*ECX*/,
    void *targetObject /*stack*/);
// RET 4; float on ST0
```

**Port note:** score only — do not fold UI tier strings/colors here. Use same resource map as `GetResourceBalanceByType` (`character+0x584`). Constants: base **100**, step **6**, max gap **15**. Under-level and gap>15 both return **0.0**; UI distinguishes Impossible via a separate balance compare.
