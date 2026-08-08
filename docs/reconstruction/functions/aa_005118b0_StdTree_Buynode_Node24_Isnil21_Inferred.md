# Function record: StdTree_Buynode_Node24_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005118b0` |
| **Canonical name** | `StdTree_Buynode_Node24_Isnil21_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_005118b0` |
| **Address** | `0x005118b0`–`0x00511935` inclusive (**134 B** / `0x86`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (Node24 isnil@+0x21 family) |
| **Wave** | R13-030 OWN-ONLY dual 2026-08-05 |
| **Parent dual** | `0x00511950` `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` (R12-014) |
| **Partition** | `WAVE_2026-08-05_r13_residual_partition_map.md` → R13-030 |
| **Dual start** | 2686 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_005118b0`
- Structural: `StdTree_Buynode_Node24_Isnil21_Inferred` (product demangle open)
- **Not** `StdTree_Buynode_Val16_Isnil21_Inferred` (peer `0x00408990`, node 0x28 / Val16)

## Purpose

MSVC-style `_Tree` buynode for the **Node24 / isnil@+0x21** family. Allocates **0x24**, writes left/parent/right, copies **int key** from `*value` to **+0x0C**, copy-constructs vector-like payload at **+0x10** via residual `FUN_005114e0`, sets **color** at **+0x20** from arg, forces **isnil=0** at **+0x21**. Returns null on OOM. Sole caller is parent always-insert `0x00511950` (passes red color `0`).

## Signature

```c
Node24Isnil21* __stdcall StdTree_Buynode_Node24_Isnil21_Inferred(
    Node24Isnil21* left,
    Node24Isnil21* parent,
    Node24Isnil21* right,
    const ValueIntKeyVec* value,
    uint8_t color);
// RET 0x14; EAX = node* | null
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C | int key |
| +0x10 | vector-like payload (elem stride 0x10; residual ctor) |
| +0x20 | color (0 red / 1 black) |
| +0x21 | isnil (forced 0) |
| size | **0x24** |

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x00511950` | `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` | sole caller (parent dual R12-014) |
| `0x005114e0` | vector payload copy-construct | nested residual (R13-029) |
| `0x00408990` | `StdTree_Buynode_Val16_Isnil21_Inferred` | peer Val16 / node 0x28 (dualed WQ9H-J) |
| `0x00407e30` / `0x005a2de0` | Val24 isnil29 buynodes | other family (node 0x30 / isnil@+0x29) |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_005118b0_FUN_005118b0.md`
- Annotated: `docs/reconstruction/raw/aa_005118b0_FUN_005118b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Node24_Isnil21_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005118b0.cpp`
- Function (scaffold id): `docs/reconstruction/functions/aa_005118b0_FUN_005118b0.md`
- Dual A: `docs/reconstruction/reviews/A_aa_005118b0_StdTree_Buynode_Node24_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005118b0_StdTree_Buynode_Node24_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-005118b0-r13-report.md`

## Callers / callees

| **Callers (1)** | `FUN_00511950` — 1 UNCONDITIONAL_CALL xref @ `0x005119e2` |
| **Callees** | `operator_new` (`0x00489892`), `FUN_005114e0` (`0x005114e0`) |

## Confidence

| Claim | Level |
|---|---|
| Role buynode Node24 isnil21 | **High** |
| ABI stdcall / RET 0x14 / new(0x24) | **High** |
| Layout color@+0x20 isnil@+0x21 key@+0x0C | **High** |
| Distinct from Val16 peer `00408990` | **High** |
| Product English / value_type demangle | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
