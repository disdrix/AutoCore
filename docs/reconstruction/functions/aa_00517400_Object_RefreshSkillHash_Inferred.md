# Function record: Object_RefreshSkillHash_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00517400` |
| **Canonical name** | `Object_RefreshSkillHash_Inferred` |
| **Ghidra name** | `FUN_00517400` |
| **Address** | `0x00517400` |
| **Body range** | `0x00517400`–`0x00517675` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00517400_Object_RefreshSkillHash_Inferred.md`, `reviews/B_aa_00517400_Object_RefreshSkillHash_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W20-T) |

## Alias

- `FUN_00517400` (Ghidra)
- `Named_VOG_DEBUG_STOP_00517400` (auto string alias — **misleading**; prefer RefreshSkillHash)
- Scaffold path `functions/aa_00517400_FUN_00517400.md` (superseded by this record)

## Purpose

Traverse host skill **hash** under lock; per skill optionally clear sibling cast HBs (flag 0), optionally reload skill def, reevaluate rank, refresh MB display name at `skill+0x1a5`. End: unlock; maybe `FUN_00516a00(0)`.

## Signature

```c
void Object_RefreshSkillHash_Inferred(void *pHost, char bReloadSkillDef);  // __cdecl
```

## Algorithm

1. If `pHost==null` return.
2. Lock `*(pHost+0x70)+0x1d`.
3. For each hash node skill:
   - If gates + `skill+0x615&1`: InvokePredicateAndRemove on `*(pHost+0xB0)` with pred `0x00512bb0`, skillId, TFID `pHost+0x160`, flag 0.
   - If `bReloadSkillDef`: load+install def for skillId.
   - `Skill_ReevaluateForCurrentRank(skill)`.
   - Wide→MB; `FUN_0054f430(skill, mb)` → `skill+0x1a5`.
4. Unlock; if gates → `FUN_00516a00(pHost, 0)`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00517400_FUN_00517400.md`
- Annotated: `docs/reconstruction/raw/aa_00517400_FUN_00517400.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_RefreshSkillHash_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00517400.cpp`
- Legacy alias plate: `reconstructed-exact/Named_VOG_DEBUG_STOP_00517400.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00517400-0052db50-w20t-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callers** | `FUN_00517df0` @ `0x00518044`, `0x0051804e` only |
| **Callees** | `CNDDoubleList_InvokePredicateAndRemove_Inferred`, pred `0x00512bb0`, `Skill_ReevaluateForCurrentRank`, `FUN_0054f430`, `FUN_00516a00`, `FUN_007e26e0`, `FUN_0054a290`, SEH/CRT helpers |

## Confidence

| Claim | Level |
|---|---|
| cdecl + bare ret | **High** |
| Hash lock/traverse | **High** |
| Inline sibling clear flag 0 | **High** |
| Name → `skill+0x1a5` | **High** |
| Product/PDB symbol | Open |

## Related

- `aa_00514e20` Skill_SiblingCastClear
- `aa_00512bb0` Skill_SiblingCastClearPredicate
- `aa_0052db50` SkillTree_RemoveBySkillId_Inferred
- `aa_00553390` Skill_ReevaluateForCurrentRank
- `aa_00516a00` (post-refresh cast re-fire; not dualled here)
