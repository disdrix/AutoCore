# Function record: StdTree_Buynode_Isnil21_Node0x24_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4870` |
| **Canonical name** | `StdTree_Buynode_Isnil21_Node0x24_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_005a4870` |
| **Address** | `0x005a4870` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x005a4870`–`0x005a48f5` inclusive (**134 B** / `0x86`) |
| **System** | MSVC `std::_Tree` node allocation |
| **Agent** | R13-008 OWN-ONLY dual 2026-08-05 (dual start **2686**) |
| **Parent dual** | `0x005a4590` StdTree_EraseAndRebalance_Isnil21_Inferred (R12-032) |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` buynode for the **isnil@+0x21 / node 0x24** family. Allocates **0x24**, stores left/parent/right, copies **u32 key** from `*value` to `+0x0C`, copy-constructs a **vector-like dword payload** at `+0x10` via residual `FUN_005a42d0` (heap begin/end/cap @ **+0x14/+0x18/+0x1c**), writes **color@+0x20** and **isnil=0@+0x21**. Returns null on OOM. Sole caller: dualed always-insert `FUN_005a4950`.

## Signature

```c
NodeIsnil21_0x24* __stdcall StdTree_Buynode_Isnil21_Node0x24_Inferred(
    NodeIsnil21_0x24* left,
    NodeIsnil21_0x24* parent,
    NodeIsnil21_0x24* right,
    const ValueU32Vec* value,  // key + vector-like
    uint8_t color);
// RET 0x14
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C | key (u32) |
| +0x10 | payload base (vector-like object) |
| +0x14 | heap begin (vector) |
| +0x18 | heap end |
| +0x1C | heap cap |
| +0x20 | color (0 red / 1 black) |
| +0x21 | isnil (forced 0) |
| size | **0x24** |

## Call graph

| Role | Target | Status |
|---|---|---|
| **Caller (1)** | `FUN_005a4950` always-insert isnil21 node0x24 | dualed R12-033 |
| Alloc | `operator_new(0x24)` | CRT |
| Payload ctor | `FUN_005a42d0` | residual |
| Sibling erase | `005a4590` StdTree_EraseAndRebalance_Isnil21 | dualed R12-032 (parent) |
| Peer Val16 buynode | `00408990` (node 0x28) | dualed; **do not merge** |
| Peer Val24 isnil29 | `00407e30` / `005a2de0` (node 0x30) | dualed; **do not merge** |

## Evidence summary

- Live decompile ≡ raw CF; body bounds via `get_function_by_address` (`005a4870`–`005a48f5`).
- Epilogue `RET 0x14` + color/isnil stores sealed via `read_memory` / `disassemble_function`.
- Sole xref: UNCONDITIONAL_CALL from insert @ `0x005a49e2`.
- Product demangle open → `_Inferred`. Runtime Confirmed **not claimed**.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Isnil21_Node0x24_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_005a4870.cpp`
- Raw: `docs/reconstruction/raw/aa_005a4870_FUN_005a4870.md`
- Annotated: `docs/reconstruction/raw/aa_005a4870_FUN_005a4870.annotated.md`
- Scaffold function: `docs/reconstruction/functions/aa_005a4870_FUN_005a4870.md`
- Review A: `docs/reconstruction/reviews/A_aa_005a4870_StdTree_Buynode_Isnil21_Node0x24_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005a4870_StdTree_Buynode_Isnil21_Node0x24_Inferred.md`
- Report: `docs/agents/task-dual-ab-005a4870-r13-report.md`
