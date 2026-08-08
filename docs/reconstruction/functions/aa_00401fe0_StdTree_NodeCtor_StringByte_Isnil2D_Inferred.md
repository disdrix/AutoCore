# Function record: StdTree_NodeCtor_StringByte_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401fe0` |
| **Canonical name** | `StdTree_NodeCtor_StringByte_Isnil2D_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00401fe0` |
| **Address** | `0x00401fe0`–`0x0040203a` exclusive (**90 B** / `0x5A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | SEH + links L/P/R + value copy + color + isnil0 + `RET 0xC` |
| **System** | MSVC `std::_Tree` node construct (isnil@+0x2d) |
| **Agent** | R10-004 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` **node construct** (no allocation) for the **isnil@+0x2d** family with **string (0x1c) + mapped byte** value at `+0x0c`. Sets links + color@+0x2c + isnil=0@+0x2d via value helper `FUN_00402040`. Sole caller is dualed buynode `FUN_00401f40` (after `operator_new(0x30)`); insert/rebalance residual `FUN_00401db0` uses color@+0x2c and isnil2D rotates.

## Signature

```c
// Hybrid __usercall: ECX=parent, EDX=right, EDI=value*,
// stack: node, left, color; RET 0xC; EAX = node*
NodeIsnil2D_StringByte* StdTree_NodeCtor_StringByte_Isnil2D_Inferred(
    NodeIsnil2D_StringByte* node,
    NodeIsnil2D_StringByte* parent,
    NodeIsnil2D_StringByte* right,
    NodeIsnil2D_StringByte* left,
    const StringByteVal* value,
    uint8_t color);
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
| **Caller (1)** | `FUN_00401f40` `StdTree_Buynode_StringByte_Isnil2D_Inferred` @ `0x00401f94` |
| Grandparent insert | `FUN_00401db0` insert + rebalance |
| Insert-or-find | `FUN_00401c50` string-key |
| Value | `FUN_00402040` `BasicStringFlag_CopyCtor_EdiSrc_Inferred` |
| Family | BuyHead `00409780`; ConstructEmpty `00406190`; Lrot `0044e010`; Rrot `0042a840` |
| Contrast | Val24 isnil29 NodeCtor `00409880` / `004098d0` — do not merge |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `RET 0xC` via `read_memory` (`C2 0C 00`).
- Disasm seals hybrid ABI + EDI value passthrough into dualed value copy.
- Buynode passes node/left/color stack + ECX parent + EDX right + EDI value.
- Prior chain-of-caller scaffold names **rejected** (`Named_CalleeOf_*Nam_*`).

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_StringByte_Isnil2D_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00401fe0.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00401fe0.cpp`
- Raw: `docs/reconstruction/raw/aa_00401fe0_FUN_00401fe0.md`
- Annotated: `docs/reconstruction/raw/aa_00401fe0_FUN_00401fe0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00401fe0_StdTree_NodeCtor_StringByte_Isnil2D_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00401fe0_StdTree_NodeCtor_StringByte_Isnil2D_Inferred.md`
- Ghidra FUN record: `docs/reconstruction/functions/aa_00401fe0_FUN_00401fe0.md`
- Report: `docs/agents/task-dual-ab-00401fe0-r10-report.md`

## Gaps

1. Product/PDB demangle for host map.
2. Insert / insert-or-find residual duals (not OWN).
3. Runtime / bit-exact / differential.

## Port note (AutoCore)

Port as **in-place node construct** for isnil@**+0x2d** nodes (size **0x30**, **string+byte** @+0x0c/+0x28). Hybrid register ABI at native sites; ordinary ctor in managed code. Pair with dualed buynode `00401f40` and dualed value `00402040`. Do **not** allocate inside this unit; do **not** treat as mission-dialog UI.
