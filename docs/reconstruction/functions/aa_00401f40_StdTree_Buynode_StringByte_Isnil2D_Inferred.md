# Function record: StdTree_Buynode_StringByte_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401f40` |
| **Canonical name** | `StdTree_Buynode_StringByte_Isnil2D_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00401f40` |
| **Address** | `0x00401f40`–`0x00401fbf` exclusive (**127 B** / `0x7F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | SEH + `operator_new(0x30)` + null-safe ctor + `RET 0x14` |
| **System** | MSVC `std::_Tree` node allocation (isnil@+0x2d) |
| **Agent** | MEGA-079 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` buynode for the **isnil@+0x2d** family with **string (0x1c) + mapped byte** value at `+0x0c`. Allocates **0x30**, constructs links + value + color + isnil=0 via ctor `FUN_00401fe0` / value `FUN_00402040`. Returns null on OOM. Sole caller is insert/rebalance `FUN_00401db0` (string `"map/set<T> too long"`; color walks @+0x2c; rotates isnil2D).

## Signature

```c
NodeIsnil2D_StringByte* __stdcall StdTree_Buynode_StringByte_Isnil2D_Inferred(
    NodeIsnil2D_StringByte* left,
    NodeIsnil2D_StringByte* parent,
    NodeIsnil2D_StringByte* right,
    const StringByteVal* value,
    uint8_t color);
// RET 0x14
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0c | `basic_string` key (0x1c) |
| +0x28 | mapped byte |
| +0x29..+0x2b | pad (alignment before color) |
| +0x2c | color (0 red / 1 black) |
| +0x2d | isnil (forced 0) |
| size | **0x30** |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `FUN_00401db0` @ `0x00401e16` (insert + rebalance) |
| Parent of insert | `FUN_00401c50` string-key insert-or-find |
| Alloc | `operator_new(0x30)` @ `0x00489892` |
| Construct | `FUN_00401fe0` @ `0x00401fe0` |
| Value | `FUN_00402040` @ `0x00402040` |
| Family | BuyHead `00409780`; ConstructEmpty `00406190`; Lrot `0044e010`; Rrot `0042a840` |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `RET 0x14` via `read_memory` (`C2 14 00`).
- Disasm seals 5 stack args + EDI value passthrough into ctor.
- Insert passes `(head, where, head, value, 0)` → red node; size++ outside.
- Prior chain-of-caller scaffold names **rejected** (`Named_CalleeOf_*Mis_*`).

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Buynode_StringByte_Isnil2D_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00401f40.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_00401f40.cpp`
- Raw: `docs/reconstruction/raw/aa_00401f40_FUN_00401f40.md`
- Annotated: `docs/reconstruction/raw/aa_00401f40_FUN_00401f40.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00401f40_StdTree_Buynode_StringByte_Isnil2D_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00401f40_StdTree_Buynode_StringByte_Isnil2D_Inferred.md`
- Ghidra FUN record: `docs/reconstruction/functions/aa_00401f40_FUN_00401f40.md`
- Report: `docs/agents/task-dual-ab-00401f40-mega-079-report.md`
