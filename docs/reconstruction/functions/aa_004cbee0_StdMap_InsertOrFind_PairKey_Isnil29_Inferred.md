# Function record: StdMap_InsertOrFind_PairKey_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbee0` |
| **Canonical name** | `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_004cbee0` |
| **Address** | `0x004cbee0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004cbee0`–`0x004cbfb2` exclusive (**210 B** / `0xD2`) |
| **System** | MSVC `std::map` insert-or-find |
| **Agent** | WQ9F-D OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

Unique insert-or-find for **isnil@+0x29** maps with **pair key**: signed **hi** primary (node+0x14 / value[1]), unsigned **lo** secondary (node+0x10 / value[0]). Miss → dualed `StdTree_InsertAndRebalance_Isnil29_Inferred`. Hit → no mapped rewrite.

## Signature

```c
void __thiscall StdMap_InsertOrFind_PairKey_Isnil29_Inferred(
    MapShell_Isnil29 *map,              // ECX
    InsertPair_Isnil29 *out,
    const Val_PairKey_Isnil29 *value);  // lo@+0, hi@+4
// RET 8
```

## Layout / constants

| Item | Value |
|---|---|
| Key lo | uint32 @ node+0x10 (unsigned cmp) |
| Key hi | int32 @ node+0x14 (signed cmp, primary) |
| isnil / color | +0x29 / +0x28 |
| Node size (insert) | `0x30` |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `FUN_004cc220` @ `0x004cc3ae` (hint-insert fallthrough) |
| Insert+RB | `0x004cbb60` dualed |
| Predecessor | `FUN_004cb4f0` residual |

## Evidence summary

- Live decompile ≡ raw CF; RET 8; pair order sealed by JG/JL + unsigned JAE.
- Same insert worker family as int-key peer `004cbe20`.
- Scaffold VOG_DEBUG product alias **reject**.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_PairKey_Isnil29_Inferred.cpp`
- Raw: `docs/reconstruction/raw/aa_004cbee0_FUN_004cbee0.md`
- Annotated: `docs/reconstruction/raw/aa_004cbee0_FUN_004cbee0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_004cbee0_StdMap_InsertOrFind_PairKey_Isnil29_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004cbee0_StdMap_InsertOrFind_PairKey_Isnil29_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_004cbee0_FUN_004cbee0.md`
