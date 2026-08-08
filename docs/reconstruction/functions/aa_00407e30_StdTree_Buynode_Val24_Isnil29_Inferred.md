# Function record: StdTree_Buynode_Val24_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407e30` |
| **Canonical name** | `StdTree_Buynode_Val24_Isnil29_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00407e30` |
| **Address** | `0x00407e30` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00407e30`–`0x00407eb4` exclusive (**132 B** / `0x84`) |
| **System** | MSVC `std::_Tree` node allocation |
| **Agent** | WQ9F-B OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` buynode for the **isnil@+0x29** family with **24-byte (6 dword) value** at `+0x10`. Allocates **0x30**, constructs links + value + color + isnil=0 via `FUN_004098d0`. Returns null on OOM. Used exclusively by dualed always-insert `StdTree_InsertAndRebalance_Isnil29_Inferred` (`0x00406c40`).

## Signature

```c
NodeIsnil29* __stdcall StdTree_Buynode_Val24_Isnil29_Inferred(
    NodeIsnil29* left,
    NodeIsnil29* parent,
    NodeIsnil29* right,
    const uint32_t value6[6],
    uint8_t color);
// RET 0x14
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x10 | value (6× int32 / Val24) |
| +0x28 | color (0 red / 1 black) |
| +0x29 | isnil (forced 0) |
| size | **0x30** |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `StdTree_InsertAndRebalance_Isnil29_Inferred` (`0x00406c40`) |
| Alloc | `operator_new(0x30)` |
| Construct | `FUN_004098d0` |
| Twin | `FUN_005a2de0` (same layout; inlined; no SEH) |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `RET 0x14` via `read_memory` / disasm.
- Insert passes `(head, where, head, value, 0)` → red node.
- Family sealed by dualed insert + rotates isnil29; color/isnil offsets match erase peers.
- Prior chain-of-caller scaffold names **narrow**.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val24_Isnil29_Inferred.cpp`
- Raw: `docs/reconstruction/raw/aa_00407e30_FUN_00407e30.md`
- Annotated: `docs/reconstruction/raw/aa_00407e30_FUN_00407e30.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00407e30_StdTree_Buynode_Val24_Isnil29_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00407e30_StdTree_Buynode_Val24_Isnil29_Inferred.md`
- Report: `docs/agents/task-dual-ab-00407e30-004c8610-wq9fb-report.md`
