# Function record: Experience_GetCumulativeThreshold

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052c860` |
| **Canonical name** | `Experience_GetCumulativeThreshold` |
| **Address** | `0x0052c860` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__cdecl` |
| **Completion status** | **Human-refined clean** — map lower_bound + sentinel annotated; loader body open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Return cumulative XP threshold for a level from `tExperienceLevel.intExperience` (map entry `+0x10`). Lazy-loads the level table if not ready. Missing key → `0x7FFFFFFF` sentinel (stops level-up loops in `AddExperience`).

## Signature

```c
unsigned __cdecl Experience_GetCumulativeThreshold(unsigned short wLevel);
```

## Behavioral summary

1. If `g_nExperienceLevelTableReady == 0` → `Experience_EnsureLevelTableLoaded_INFERRED()`.
2. `std::map`-style `lower_bound` by int key `wLevel`.
3. Re-check ready flag (second lazy init).
4. If iterator node == end → return `0x7FFFFFFF`.
5. Else return `*(uint*)(node + 0x10)`.

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | High | Named; exclusive threshold API |
| Control flow | High | Short body; dual lazy-init preserved |
| Entry `+0x10` = intExperience | High | plate + XP.md + LevelUp row layout |
| Map / loader implementation | Probable | inferred names; MSVC map ABI |
| Overall | **High (static)** | Small pure lookup |

## Open questions

- Exact type of `g_pExperienceLevelMap_INFERRED` (std::map vs custom).
- Whether second ready-check is intentional re-entrancy or decompiler artifact of inlined path.
- Full row layout beyond `+0x10` (skill/attrib at `+0x14` from LevelUp unit).

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0052c860_Experience_GetCumulativeThreshold.md` |
| Annotated | `raw/aa_0052c860_Experience_GetCumulativeThreshold.annotated.md` |
| Clean | `reconstructed-exact/Experience_GetCumulativeThreshold.cpp` |
| Caller | `functions/aa_00533c30_CVOGReaction_AddExperience.md` |
| Prior art | `docs/XP.md` |
