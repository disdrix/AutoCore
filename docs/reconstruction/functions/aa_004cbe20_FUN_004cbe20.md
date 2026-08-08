# Function record: FUN_004cbe20

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbe20` |
| **Canonical name** | `FUN_004cbe20` (see named record) |
| **Named** | `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` |
| **Address** | `0x004cbe20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004cbe20`–`0x004cbed8` exclusive (**184 B**) |
| **System** | MSVC std::map insert-or-find (isnil@+0x29) |
| **Agent** | WQ9F-D OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Alias

- Preferred: `StdMap_InsertOrFind_IntKey_Isnil29_Inferred`
- Reject product: `Named_CalleeOf_…_GetTargetFromAggro_004cbe20`

## Purpose

Signed-int-key unique insert-or-find shell over dualed always-insert `StdTree_InsertAndRebalance_Isnil29_Inferred`.

## Signature

```c
void __thiscall FUN_004cbe20(
    MapShell_Isnil29 *map,       // ECX
    InsertPair_Isnil29 *out,     // +4
    const Val_IntKey *value);    // +8
// RET 8
```

## Callers / callees

| Role | Target |
|---|---|
| Callers | `FUN_004c9380`, `FUN_00518ca0` (Skill_InsertActiveCastBinding_Inferred) |
| Insert | `FUN_004cbb60` / StdTree_InsertAndRebalance_Isnil29_Inferred |
| Predecessor | `FUN_004cb4f0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cbe20_FUN_004cbe20.md`
- Annotated: `docs/reconstruction/raw/aa_004cbe20_FUN_004cbe20.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_IntKey_Isnil29_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004cbe20.cpp`
- A/B: `docs/reconstruction/reviews/A|B_aa_004cbe20_StdMap_InsertOrFind_IntKey_Isnil29_Inferred.md`
- Named record: `docs/reconstruction/functions/aa_004cbe20_StdMap_InsertOrFind_IntKey_Isnil29_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| CF + ABI | High |
| Signed int key / equal-no-write | High |
| Product English | Open (`_Inferred`) |
