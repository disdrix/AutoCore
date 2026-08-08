# Function record: StdTree_InsertAndRebalance_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406c40` |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil29_Inferred` |
| **Ghidra symbol** | `FUN_00406c40` |
| **Address** | `0x00406c40`–`0x00406dd5` exclusive (**405 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x29 family) |
| **Wave** | WQ9E-G OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_00406c40`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGClient_00406c40` (**narrow** — reject as product)

## Purpose

Always-allocate map/set node insert + RB rebalance for the **isnil@+0x29** node family (node **0x30**, color@**+0x28**, value **0x18** @+0x10). Throws `"map/set<T> too long"` when `size > 0x0AAAAAA8`. Uses dualed L/R rotates. Parent `FUN_00406040` performs insert-or-find (uint key @ +0x10).

## Signature

```c
void __thiscall StdTree_InsertAndRebalance_Isnil29_Inferred(
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
| `0x004192a0` | `StdTree_Lrotate_Isnil29` | left rotate |
| `0x004192f0` | `StdTree_Rrotate_Isnil29_Inferred` | right rotate |
| `0x00407e30` | buynode 0x30 | allocator/ctor |
| `0x00406040` | parent insert-or-find | caller |
| `0x00438140` | `StdTree_InsertAndRebalance_Val8_Isnil15_Inferred` | peer family (isnil@+0x15) |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00406c40_FUN_00406c40.md`
- Annotated: `docs/reconstruction/raw/aa_00406c40_FUN_00406c40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil29_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00406c40.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00406c40_StdTree_InsertAndRebalance_Isnil29_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00406c40_StdTree_InsertAndRebalance_Isnil29_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00406c40_FUN_00406c40.md`

## Callers / callees

| **Callers (1)** | `FUN_00406040` (2 UNCONDITIONAL_CALL sites) |
| **Callees** | `FUN_00407e30`, `StdTree_Lrotate_Isnil29`, `StdTree_Rrotate_Isnil29_Inferred`, length_error path |

## Confidence

| Claim | Level |
|---|---|
| Role always-insert + rebalance | High |
| ABI / RET 0x10 / max-size imm | Confirmed |
| Layout color@+0x28 isnil@+0x29 node 0x30 | Confirmed |
| Product English | Open (`_Inferred`) |
