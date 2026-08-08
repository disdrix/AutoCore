# Function record (named): DisciplineDefMap_TryCopyPayloadById_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b040` |
| **Inferred name** | `DisciplineDefMap_TryCopyPayloadById_Inferred` |
| **Ghidra name** | `FUN_0052b040` |
| **VA** | `0x0052b040` |
| **System** | `skills-abilities` |
| **Dual** | R12-020 A/B accept-with-gaps (2026-08-05) |
| **Terminal** | **false** |

See sibling record `aa_0052b040_FUN_0052b040.md` for full seals, callers, and artifacts.

```c
uint8_t __cdecl DisciplineDefMap_TryCopyPayloadById_Inferred(int disciplineId, void *outPayload0x1FC);
```

**Port note:** map lookup + POD copy only; do not treat as SkillDefMap; out buffer must be ≥ `0x1FC`; return bool; no thiscall.
