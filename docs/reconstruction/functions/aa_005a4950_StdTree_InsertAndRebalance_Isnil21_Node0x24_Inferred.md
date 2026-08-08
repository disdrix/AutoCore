# Function record: StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4950` |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred` |
| **Ghidra symbol** | `FUN_005a4950` |
| **Address** | `0x005a4950`–`0x005a4b3a` inclusive (**491 B** / `0x1EB`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21, node **0x24**) |
| **Wave** | R12-033 OWN-ONLY dual 2026-08-05 (dual start 2646) |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias history

- Ghidra: `FUN_005a4950`
- Structural: `StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred` (product demangle open)
- Reject: merge with `StdTree_InsertAndRebalance_Isnil21_Inferred` (`00407200`, node 0x28 Val16)

## Purpose

Always-allocate map/set node insert + RB rebalance for the **isnil@+0x21 / node 0x24** family (color@**+0x20**, u32 key @+0x0C, vector-like value via buynode). Throws `"map/set<T> too long"` when `size >= 0x0CCCCCCB`. Uses residual buynode `005a4870` and dualed L/R rotates `0050e9f0` / `005a27f0`. Parent InsertOrFind-style `005a4b70` supplies placement (u32 key lower-bound).

## Signature (sealed)

```c
// __thiscall; ECX = map*; stack = out**, addLeft, where*, value*; void; RET 0x10
void __thiscall StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred(
    MapShellIsnil21_0x24* map,
    NodeIsnil21_0x24** out,
    char addLeft,
    NodeIsnil21_0x24* where,
    const void* value);
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C | key (u32) |
| +0x10 | value payload start (vector-like; buynode `005a4870` + `005a42d0`) |
| +0x20 | color |
| +0x21 | isnil |
| node size | **0x24** (`operator_new` in buynode) |
| tree+4 | head; head+4 = root; tree+8 = size |

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x005a4870` | buynode node 0x24 isnil21 | residual (not dualled OWN) |
| `0x005a4b70` | InsertOrFind-style u32 key | sole caller (not dualled OWN) |
| `0x0050e9f0` | `StdTree_Lrotate_Isnil21_Inferred` | twin Lrotate (R10-030 dualed) |
| `0x005a27f0` | `StdTree_Rrotate_Isnil21_Inferred` | twin Rrotate (R11-007 dualed; parent dual) |
| `0x00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | peer always-insert (node **0x28** Val16) |
| `0x00408990` | `StdTree_Buynode_Val16_Isnil21_Inferred` | peer-family buynode (0x28) |

## Artifacts

- Raw (+ R12-033 re-verify): `docs/reconstruction/raw/aa_005a4950_FUN_005a4950.md`
- Annotated: `docs/reconstruction/raw/aa_005a4950_FUN_005a4950.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005a4950.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005a4950_StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005a4950_StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_005a4950_FUN_005a4950.md`
- Report: `docs/agents/task-dual-ab-005a4950-r12-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | `FUN_005a4870`, `FUN_0050e9f0`, `FUN_005a27f0`, length_error path / `_CxxThrowException` |
| **Callers (1)** | `FUN_005a4b70` (2 call sites @ `005a4bc9`, `005a4c00`) |
| **Xrefs** | 2 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| Always-insert + RB semantics | **High** |
| isnil@+0x21 / color@+0x20 / node 0x24 | **High** |
| ABI thiscall + RET 0x10 | **High** |
| Name product English / demangle | **Inferred** |
| Runtime / differential | Open |
