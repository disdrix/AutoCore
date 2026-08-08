# Function record: StdMap_InsertOrFind_PairKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407060` |
| **Canonical name** | `StdMap_InsertOrFind_PairKey_Isnil21_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00407060` |
| **Address** | `0x00407060` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00407060`–`0x00407133` exclusive (**211 B** / `0xD3`) |
| **System** | MSVC `std::map` insert-or-find (pair key, isnil@+0x21) |
| **Agent** | WQ9I-C OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style unique insert-or-find for maps whose nodes use **isnil@+0x21** and a **two-dword pair key** (signed hi primary @+0x14, unsigned lo secondary @+0x10). Walks from root, inserts via `FUN_00407200` on miss, returns `{it,0}` on equal without rewriting value. Sole caller: dualed `StdTree_InsertHint_Isnil21_Inferred` (`0x00406560`) when hint path cannot prove an open neighbor slot.

## Signature

```c
void __thiscall StdMap_InsertOrFind_PairKey_Isnil21_Inferred(
    MapShell_Isnil21 *map,
    InsertPair *out,           // { Node* it; uint8_t inserted; }
    const Val_PairKey *value);
// RET 0x8
```

## Layout (node)

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x10 | key_lo (unsigned secondary) |
| +0x14 | key_hi (signed primary) |
| +0x18..+0x1c | mapped (Val16 remainder) |
| +0x20 | color |
| +0x21 | isnil |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | dualed `StdTree_InsertHint_Isnil21_Inferred` (`0x00406560`) @ `0x004066ee` |
| Insert | `FUN_00407200` (WQ9I-B OWN residual) |
| Pred | `FUN_005adff0` |
| Compare peer leaf | dualed `StdPairKey_Less_HiSignedLoUnsigned_Inferred` (`0x00401480`) |
| Family peer | dualed `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` (`0x004cbee0`) |

## Evidence summary

- Live decompile ≡ raw CF; **RET 0x8** ×3 via `read_memory` / disasm.
- Hi signed (`JG`/`JL`), lo unsigned (`JAE`/`JNC`); equal path `inserted=0`.
- Partition residual of InsertHint isnil21 (WQ9H-F gap).

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_PairKey_Isnil21_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00407060.cpp`
- Raw: `docs/reconstruction/raw/aa_00407060_FUN_00407060.md`
- Annotated: `docs/reconstruction/raw/aa_00407060_FUN_00407060.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00407060_StdMap_InsertOrFind_PairKey_Isnil21_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00407060_StdMap_InsertOrFind_PairKey_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-00407060-004099b0-wq9ic-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / isnil21 / pair-key | **High** |
| Product pair English | Open |
| Runtime | Open |
