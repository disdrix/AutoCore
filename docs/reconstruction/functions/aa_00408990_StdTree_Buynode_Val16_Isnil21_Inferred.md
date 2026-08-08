# Function record: StdTree_Buynode_Val16_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408990` |
| **Canonical name** | `StdTree_Buynode_Val16_Isnil21_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00408990` |
| **Address** | `0x00408990` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00408990`–`0x00408a13` inclusive (**132 B** / `0x84`) |
| **System** | MSVC `std::_Tree` node allocation |
| **Agent** | WQ9H-J OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` buynode for the **isnil@+0x21** family with **16-byte (4 dword) value** at `+0x10`. Allocates **0x28**, constructs links + value + color + isnil=0 via `FUN_004099b0`. Returns null on OOM. Used exclusively by insert/rebalance `FUN_00407200`.

## Signature

```c
NodeIsnil21* __stdcall StdTree_Buynode_Val16_Isnil21_Inferred(
    NodeIsnil21* left,
    NodeIsnil21* parent,
    NodeIsnil21* right,
    const uint32_t value4[4],
    uint8_t color);
// RET 0x14
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x10 | value (4× int32 / Val16) |
| +0x20 | color (0 red / 1 black) |
| +0x21 | isnil (forced 0) |
| size | **0x28** |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `FUN_00407200` (insert/rebalance; undualed residual) |
| Alloc | `operator_new(0x28)` |
| Construct | `FUN_004099b0` |
| Contrast | Val24/isnil29 buynode `0x00407e30`; head shell `0x00408a30` |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `RET 0x14` via `read_memory` / disasm.
- Insert passes `(head, where, head, value, 0)` → red node; color checks @+0x20.
- Partition VA neighborhood was CNDHash/freelist residual; machine CF is StdTree buynode.
- Prior generic scaffold names **narrow**.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val16_Isnil21_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00408990.cpp`
- Raw: `docs/reconstruction/raw/aa_00408990_FUN_00408990.md`
- Annotated: `docs/reconstruction/raw/aa_00408990_FUN_00408990.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00408990_StdTree_Buynode_Val16_Isnil21_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00408990_StdTree_Buynode_Val16_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-00408990-00408a30-wq9hj-report.md`
