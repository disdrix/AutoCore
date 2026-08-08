# Function record: StdMap_InsertOrFind_IntKey_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbe20` |
| **Canonical name** | `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_004cbe20` |
| **Address** | `0x004cbe20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004cbe20`–`0x004cbed8` exclusive (**184 B** / `0xB8`) |
| **System** | MSVC `std::map` insert-or-find |
| **Agent** | WQ9F-D OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style unique **insert-or-find** for trees with **color @ +0x28** / **isnil @ +0x29**. Signed **int32** key at value dword0 / node **+0x10**. On miss, always-insert via dualed `StdTree_InsertAndRebalance_Isnil29_Inferred` (`0x004cbb60`). On hit, `{it, inserted=0}` without rewriting mapped payload.

## Signature

```c
void __thiscall StdMap_InsertOrFind_IntKey_Isnil29_Inferred(
    MapShell_Isnil29 *map,             // ECX
    InsertPair_Isnil29 *out,           // { Node* it; bool inserted; }
    const Val_IntKey_Isnil29 *value);  // key @ +0
// RET 8
```

## Layout / constants

| Item | Value |
|---|---|
| Key | signed int32 @ node+0x10 |
| isnil / color | +0x29 / +0x28 |
| Node size (insert) | `0x30` (via `004cbb60` buynode) |
| Compare | signed (`SETL`) |

## Call graph

| Role | Target |
|---|---|
| **Callers (2)** | `FUN_004c9380` @ `0x004c93d1`; `FUN_00518ca0` Skill_InsertActiveCastBinding @ `0x00518cda` |
| Insert+RB | `StdTree_InsertAndRebalance_Isnil29_Inferred` `0x004cbb60` |
| Predecessor | `FUN_004cb4f0` (residual) |

## Evidence summary

- Live decompile ≡ raw CF; RET 8 + SETL + isnil@+0x29 sealed via `read_memory`.
- Insert worker dual sealed WQ9E-E.
- Scaffold GetTargetFromAggro product alias **reject**.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_IntKey_Isnil29_Inferred.cpp`
- Raw: `docs/reconstruction/raw/aa_004cbe20_FUN_004cbe20.md`
- Annotated: `docs/reconstruction/raw/aa_004cbe20_FUN_004cbe20.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_004cbe20_StdMap_InsertOrFind_IntKey_Isnil29_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004cbe20_StdMap_InsertOrFind_IntKey_Isnil29_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_004cbe20_FUN_004cbe20.md`
