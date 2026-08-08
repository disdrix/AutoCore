# Function record: StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409180` |
| **Canonical name** | `StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00409180` |
| **Address** | `0x00409180` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00409180`–`0x00409209` exclusive (**137 B** / `0x89`) |
| **System** | MSVC `std::_Tree` head/sentinel allocation |
| **Agent** | WQ9J-F OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

Allocate one **0x38** tree node and initialize links to null, **color=black** @+0x30, **isnil=0** @+0x31. Sole caller `FUN_00405f20` installs it as map/set **head**: force isnil=1, self-link L/P/R, zero host size@+8. Does **not** copy value payload.

## Signature

```c
NodeIsnil31_Size0x38* StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred(void);
// bare RET; EAX = node*
```

## Layout (this unit writes)

| Offset | Field | Init |
|---|---|---|
| +0x00 | left | 0 |
| +0x04 | parent | 0 |
| +0x08 | right | 0 |
| +0x0C..+0x2F | value (Val36) | untouched |
| +0x30 | color | **1** (black) |
| +0x31 | isnil | **0** (caller → 1) |
| size | | **0x38** |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `FUN_00405f20` @ `0x00405f3a` |
| Alloc | `operator_new(0x38)` |
| Contrast | isnil29 head `0x00408a30` (0x30); isnil21 empty `0x004088f0` (0x28); isnil31 iterator++ `0x00408590` |

## Evidence summary

- Live decompile ≡ raw CF; bare `RET`; color/isnil stores sealed via `read_memory`.
- Caller pattern: head@+4, isnil1, self-link, size0.
- Reject Client-constructor chain-of-caller scaffold name.
- Partition residual by VA; machine CF is StdTree head shell for isnil@+0x31 / 0x38.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00409180.cpp`
- Raw: `docs/reconstruction/raw/aa_00409180_FUN_00409180.md`
- Annotated: `docs/reconstruction/raw/aa_00409180_FUN_00409180.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00409180_StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00409180_StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred.md`
- Report: `docs/agents/task-dual-ab-00409180-004094c0-wq9jf-report.md`
