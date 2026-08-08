# Function record: StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404180` |
| **Canonical name** | `StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00404180` |
| **Address** | `0x00404180` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00404180`–`0x00404202` exclusive (**130 B** / `0x82`) |
| **System** | MSVC `std::_Tree` node allocation |
| **Agent** | WQ9K-C OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` buynode for the **isnil@+0x29** family with **24-byte (6 dword) value** at `+0x10`. Allocates **0x30**, constructs links + value + color + isnil=0 via **EAX-this** ctor `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` (`0x00409880`). Returns null on OOM. Sole caller is insert/rebalance `FUN_004069f0` (string `"map/set<T> too long"`; color walks @+0x28).

## Signature

```c
NodeIsnil29* __stdcall StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred(
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
| **Caller (1)** | `FUN_004069f0` @ `0x00406a56` (insert + rebalance) |
| Alloc | `operator_new(0x30)` |
| Construct | `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` (`0x00409880`) |
| Twin | `StdTree_Buynode_Val24_Isnil29_Inferred` (`0x00407e30`) — thiscall ctor path |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `RET 0x14` via `read_memory` (`C2 14 00`).
- Disasm seals register ABI into EAX-this ctor (EAX/ECX/EDX + 3 stack).
- Insert passes `(head, where, head, value, 0)` → red node; size++ outside.
- Prior chain-of-caller scaffold names **rejected** (`Named_CalleeOf_*Client_RecvSpecial*`).

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00404180.cpp`
- Raw: `docs/reconstruction/raw/aa_00404180_FUN_00404180.md`
- Annotated: `docs/reconstruction/raw/aa_00404180_FUN_00404180.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00404180_StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00404180_StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.md`
- Report: `docs/agents/task-dual-ab-00404180-00405f20-wq9kc-report.md`
