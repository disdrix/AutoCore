# Function record: StdTree_BuyHeadNode_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408a30` |
| **Canonical name** | `StdTree_BuyHeadNode_Isnil29_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00408a30` |
| **Address** | `0x00408a30` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00408a30`–`0x00408ab9` inclusive (**138 B** / `0x8A`) |
| **System** | MSVC `std::_Tree` head/sentinel allocation |
| **Agent** | WQ9H-J OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

Allocate one **0x30** tree node and initialize links to null, **color=black** @+0x28, **isnil=0** @+0x29. All four callers install it as map/set **head**: force isnil=1, self-link L/P/R, zero host size@+8. Does **not** copy Val24 payload.

## Signature

```c
NodeIsnil29* StdTree_BuyHeadNode_Isnil29_Inferred(void);
// bare RET; EAX = node*
```

## Layout (this unit writes)

| Offset | Field | Init |
|---|---|---|
| +0x00 | left | 0 |
| +0x04 | parent | 0 |
| +0x08 | right | 0 |
| +0x10..+0x27 | value (Val24) | untouched |
| +0x28 | color | **1** (black) |
| +0x29 | isnil | **0** (callers → 1) |
| size | | **0x30** |

## Call graph

| Role | Target |
|---|---|
| **Callers (4)** | `FUN_00405b40`, `FUN_00405e60`, `FUN_00405fb0`, `FUN_004d98f0` |
| Alloc | `operator_new(0x30)` |
| Contrast | Val16 buynode `0x00408990`; Val24 buynode `0x00407e30` |

## Evidence summary

- Live decompile ≡ raw CF; bare `RET`; color/isnil stores sealed via `read_memory`.
- Caller pattern uniform: head@+4, isnil1, self-link, size0.
- Reject Client-constructor chain-of-caller scaffold name.
- Partition freelist neighborhood residual by VA; machine CF is StdTree head shell.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_BuyHeadNode_Isnil29_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00408a30.cpp`
- Raw: `docs/reconstruction/raw/aa_00408a30_FUN_00408a30.md`
- Annotated: `docs/reconstruction/raw/aa_00408a30_FUN_00408a30.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00408a30_StdTree_BuyHeadNode_Isnil29_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00408a30_StdTree_BuyHeadNode_Isnil29_Inferred.md`
- Report: `docs/agents/task-dual-ab-00408990-00408a30-wq9hj-report.md`
