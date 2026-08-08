# Function record: StdTree_InsertAndRebalance_Node24_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00511950` |
| **Canonical name** | `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` |
| **Ghidra name** | `FUN_00511950` |
| **Address** | `0x00511950`–`0x00511b3a` inclusive (**491 B** / `0x1EB`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21 Node24 family) |
| **Wave** | R12-014 OWN-ONLY dual 2026-08-05 |
| **Parent dual** | `0x005a27f0` `StdTree_Rrotate_Isnil21_Inferred` (R11-007) |
| **Partition** | `WAVE_2026-08-05_r12_residual_partition_map.md` → R12-014 |
| **Dual start** | 2646 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_00511950`
- Structural: `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` (product demangle open)
- **Not** `StdTree_InsertAndRebalance_Isnil21_Inferred` (that is peer `0x00407200` Val16/node0x28)

## Purpose

Always-allocate map/set node insert + RB rebalance for the **Node24 / isnil@+0x21** family (node **0x24**, color@**+0x20**, int key @+0x0C + vector payload). Throws `"map/set<T> too long"` when `size ≥ 0xCCCCCCB`. Uses residual buynode `005118b0` and dualed L/R rotates `0050e9f0` / `005a27f0` (one Lrotate path inlined). Sole caller residual InsertOrFind `00511b40` supplies placement via int-key lower-bound.

## Signature

```c
void __thiscall StdTree_InsertAndRebalance_Node24_Isnil21_Inferred(
    /*ECX*/ MapShell* map,
    Node** out,
    char addLeft,
    Node* where,
    const void* value);
// RET 0x10; *out = new node; root blackened
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x005118b0` | buynode Node24 isnil21 | nested residual (`operator_new(0x24)`) |
| `0x00511b40` | InsertOrFind int-key shell | sole caller (residual) |
| `0x0050e9f0` | `StdTree_Lrotate_Isnil21_Inferred` | Lrotate (dualed R10-030) |
| `0x005a27f0` | `StdTree_Rrotate_Isnil21_Inferred` | Rrotate (dualed R11-007 parent) |
| `0x00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | peer Val16/node0x28 (dualed WQ9I-B) |
| `0x00406c40` | `StdTree_InsertAndRebalance_Isnil29_Inferred` | peer other isnil family |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00511950_FUN_00511950.md`
- Annotated: `docs/reconstruction/raw/aa_00511950_FUN_00511950.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Node24_Isnil21_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00511950.cpp`
- Function (scaffold id): `docs/reconstruction/functions/aa_00511950_FUN_00511950.md`
- Dual A: `docs/reconstruction/reviews/A_aa_00511950_StdTree_InsertAndRebalance_Node24_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00511950_StdTree_InsertAndRebalance_Node24_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-00511950-r12-report.md`

## Callers / callees

| **Callers (1)** | `FUN_00511b40` — 2 UNCONDITIONAL_CALL xrefs |
| **Callees** | `FUN_005118b0`, `FUN_0050e9f0`, `FUN_005a27f0`, length_error path |

## Confidence

| Claim | Level |
|---|---|
| Role always-insert + rebalance | **High** |
| ABI / RET 0x10 / size gate 0xCCCCCCB | **High** |
| Layout color@+0x20 isnil@+0x21 node 0x24 | **High** |
| Distinct from Val16 peer `00407200` | **High** |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
