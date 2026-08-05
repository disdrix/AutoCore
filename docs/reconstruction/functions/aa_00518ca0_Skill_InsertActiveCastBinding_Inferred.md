# Function record: Skill_InsertActiveCastBinding_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518ca0` |
| **Canonical name** | `Skill_InsertActiveCastBinding_Inferred` |
| **Address** | `0x00518ca0`–`0x00518ce4` (**0x44** bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Dual A/B present** (2026-07-29 W24-H) — accept-with-gaps |
| **Name status** | Role-inferred; no product string/RTTI on body |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `FUN_00518ca0` | Ghidra scaffold |
| `Named_CalleeOf_Skill_Skill_d_has_invalid_frequency_d_00518ca0` | **Reject** (parent frequency log string ≠ this body) |

## Purpose

Insert **skillId → TFID16** into the active-cast binding map at **mapOwner+0x68**:

1. Pack stack args into 0x18-byte local (`skillId` @+0, pad gap @+4, TFID @+8…+0x14).
2. `map = FUN_00518c20(mapOwner)` — lazy empty-tree shell (leave-FUN sibling).
3. `FUN_004cbe20(map, &outPair, &local)` — map insert-or-find by int key; result discarded.

## Signature

```c
void __thiscall Skill_InsertActiveCastBinding_Inferred(
    void *mapOwner,  // ECX
    int skillId,
    uint32_t tfid0, uint32_t tfid1, uint32_t tfid2, uint32_t tfid3);
// ret 0x14
```

## Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| Caller (sole) | `Skill_HB_FireTail_FxTargetAndPeriodStamp` | site `0x00578c55` |
| Callee | `FUN_00518c20` | map get `+0x68` |
| Callee | `FUN_004cbe20` | map insert-or-find |

## Family

| Sibling | Role |
|---|---|
| `FUN_00518c20` | leave-FUN lazy map get |
| `Skill_LookupActiveCastBinding` | find → out TFID16 |
| `Skill_ClearCastBindingAndMaybeRestartCd` | find/erase + optional restart |
| `Skill_LocalCastValidate` | non-empty map size gate |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00518ca0_FUN_00518ca0.md`
- Annotated: `docs/reconstruction/raw/aa_00518ca0_FUN_00518ca0.annotated.md`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_00518ca0.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/Skill_InsertActiveCastBinding_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00518ca0_Skill_InsertActiveCastBinding_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00518ca0_Skill_InsertActiveCastBinding_Inferred.md`
- FUN_ record: `docs/reconstruction/functions/aa_00518ca0_FUN_00518ca0.md`

## Confidence

| Claim | Level |
|---|---|
| CF pack → get map → insert | **Confirmed** |
| `__thiscall` + `ret 0x14` + ECX owner | **Confirmed** (bytes) |
| Key=skillId, value=TFID16 @ node+0x18 | **High** (siblings + pack) |
| Role name `_Inferred` | **High** |
| Product/PDB symbol | **Open** |
| Pad dword semantics | **Open** |
