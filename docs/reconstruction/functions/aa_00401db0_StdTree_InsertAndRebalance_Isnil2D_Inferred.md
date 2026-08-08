# Function record: StdTree_InsertAndRebalance_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401db0` |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil2D_Inferred` |
| **Ghidra symbol** | `FUN_00401db0` |
| **Address** | `0x00401db0`–`0x00401f31` exclusive (**385 B** / `0x181`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression (call-chain); body = STL map-set isnil@+0x2D insert |
| **Wave** | MEGA-066 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_00401db0`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Attempting_00401db0` (**narrow** — reject as product)

## Purpose

Always-allocate map/set node insert + RB rebalance for the **isnil@+0x2D** node family (node **0x30**, color@**+0x2C**, isnil@**+0x2D**, string @**+0x0C**). Throws `"map/set<T> too long"` when `size > 0x7FFFFFD`. Uses dualed isnil2D L/R rotates. Parent `FUN_00401c50` performs string-key insert-or-find.

## Signature

```c
// EDI = map; ECX = where; RET 0x0C
void StdTree_InsertAndRebalance_Isnil2D_Inferred(
    /*EDI*/ MapShell* map,
    /*ECX*/ Node* where,
    Node** out,
    char addLeft,
    const void* value);
// *out = new node; root blackened
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x0044e010` | `StdTree_LeftRotate_Isnil2D_Inferred` | left rotate (dualed) |
| `0x0042a840` | `StdTree_Rrotate_Isnil2D_Inferred` | right rotate (dualed) |
| `0x00401f40` | buynode 0x30 | allocator/ctor (residual) |
| `0x00401c50` | parent insert-or-find | string key (residual) |
| `0x00430b60` | `StdMap_StringKey_InsertNodeAndRebalance` | clone peer (dualed) |
| `0x00406c40` | `StdTree_InsertAndRebalance_Isnil29_Inferred` | different family |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00401db0_FUN_00401db0.md`
- Annotated: `docs/reconstruction/raw/aa_00401db0_FUN_00401db0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil2D_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00401db0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00401db0_StdTree_InsertAndRebalance_Isnil2D_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00401db0_StdTree_InsertAndRebalance_Isnil2D_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00401db0_FUN_00401db0.md`

## Callers / callees

| **Callers (1)** | `FUN_00401c50` (2 UNCONDITIONAL_CALL sites `0x00401cb6`, `0x00401cfe`) |
| **Callees** | `FUN_00401f40`, `StdTree_LeftRotate_Isnil2D_Inferred`, `StdTree_Rrotate_Isnil2D_Inferred`, length_error path |

## Confidence

| Claim | Level |
|---|---|
| Role always-insert + rebalance | High |
| ABI EDI=map / ECX=where / RET 0x0C / max-size imm | Confirmed |
| Layout color@+0x2C isnil@+0x2D node 0x30 | Confirmed |
| Product English | Open (`_Inferred`) |
