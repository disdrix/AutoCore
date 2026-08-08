# Function record (named): CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b140` |
| **Inferred name** | `CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred` |
| **Ghidra name** | `FUN_0052b140` |
| **VA** | `0x0052b140` |
| **System** | `skills-abilities` |
| **Dual** | R13-036 A/B accept-with-gaps (2026-08-05, dual start 2686) |
| **Terminal** | **false** |

See sibling record `aa_0052b140_FUN_0052b140.md` for full seals, callers, and artifacts.

```c
uint8_t __thiscall CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred(
    void *character /* ECX */,
    int disciplineId /* stack0 */);
// RET 4; bool AL
```

**Port note:** DisciplineDef find+copy on map `@0x00b045b0`, min level via nested vtbl `+0x27c` vs def`+0x26`, then **OR** of five alternate prereq slots (nested try-copy + `GetResourceBalanceByType`) or all ids `-1`. Do **not** AND slots. Do **not** merge with SkillDefMap. Product English open → `_Inferred`. Never Runtime Confirmed this pass.
