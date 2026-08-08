# Function record: StdTree_NodeCtor_Val16_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004099b0` |
| **Canonical name** | `StdTree_NodeCtor_Val16_Isnil21_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_004099b0` |
| **Address** | `0x004099b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004099b0`–`0x004099f3` exclusive (**67 B** / `0x43`) |
| **System** | MSVC `std::_Tree` node construct |
| **Agent** | WQ9I-C OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

Thiscall constructor for **isnil@+0x21** nodes with **16-byte value** at `+0x10`. Invoked only from dualed buynode `StdTree_Buynode_Val16_Isnil21_Inferred` (`0x00408990`) after `operator_new(0x28)`. Sets left/parent/right, copies four dwords, stores color @+0x20, forces isnil=0 @+0x21. Returns `this` in EAX.

## Signature

```c
NodeIsnil21* __thiscall StdTree_NodeCtor_Val16_Isnil21_Inferred(
    NodeIsnil21* self,
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
| +0x0C | untouched |
| +0x10 | value (4× dword / Val16) |
| +0x20 | color (0 red / 1 black) |
| +0x21 | isnil (forced 0) |
| size | **0x28** (alloc in buynode) |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | dualed `StdTree_Buynode_Val16_Isnil21_Inferred` (`0x00408990`) @ `0x004089e8` |
| Upstream insert | `FUN_00407200` (via buynode) |
| Contrast | head shell `0x00408a30` (isnil29); Val24 buynodes |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `RET 0x14` via `read_memory` / disasm.
- Buynode dual (WQ9H-J) already documented this unit as residual construct helper.
- Leaf; no callees.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_Val16_Isnil21_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_004099b0.cpp`
- Raw: `docs/reconstruction/raw/aa_004099b0_FUN_004099b0.md`
- Annotated: `docs/reconstruction/raw/aa_004099b0_FUN_004099b0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_004099b0_StdTree_NodeCtor_Val16_Isnil21_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004099b0_StdTree_NodeCtor_Val16_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-00407060-004099b0-wq9ic-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / Val16 / isnil21 | **High** |
| Product value English | Open |
| Runtime | Open |
