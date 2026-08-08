# Function record: StdTree_InsertAndRebalance_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403250` |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil31_Inferred` |
| **Ghidra symbol** | `FUN_00403250` |
| **Address** | `0x00403250`–`0x004033d1` inclusive (**386 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression nest / STL map-set helpers (isnil@+0x31 family) |
| **Wave** | MEGA-047 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_00403250`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Client_NotifyActiveMissionChanged_00403250` (**narrow** — reject as product)

## Purpose

Always-allocate map/set node insert + RB rebalance for the **isnil@+0x31** node family (node **0x38**, color@**+0x30**, value **0x20** @+0x10). Throws `"map/set<T> too long"` when `size >= 0x7fffffe`. Uses dualed Lrotate isnil31 + residual Rrotate. Parent `FUN_00402b30` performs insert-or-find (uint key @ +0x10). Nested under NotifyActiveMissionChanged call chain only as shared STL helper.

## Signature

```c
// EDI = map*; ECX = where*; stack (out**, addLeft, value*); RET 0xC
Node** StdTree_InsertAndRebalance_Isnil31_Inferred(
    /*EDI*/ MapShell* map,
    /*ECX*/ Node* where,
    Node** out,
    char addLeft,
    const void* value);
// *out = new node; root blackened; EAX = out
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x00403e90` | `StdTree_Lrotate_Isnil31_Inferred` | left rotate (dualed WQ9L-B) |
| `0x00403ee0` | Rrotate isnil31 | right rotate (residual) |
| `0x00403f30` | buynode 0x38 | allocator/ctor (MEGA-048 nest) |
| `0x00402b30` | parent insert-or-find | caller (MEGA-040) |
| `0x00408ed0` | `StdTree_EraseAndRebalance_Isnil31_Inferred` | erase peer (shared rotates) |
| `0x00406c40` | `StdTree_InsertAndRebalance_Isnil29_Inferred` | peer family (isnil@+0x29) |
| `0x00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | peer family (isnil@+0x21) |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00403250_FUN_00403250.md`
- Annotated: `docs/reconstruction/raw/aa_00403250_FUN_00403250.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil31_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00403250.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00403250_StdTree_InsertAndRebalance_Isnil31_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00403250_StdTree_InsertAndRebalance_Isnil31_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00403250_FUN_00403250.md`

## Callers / callees

| **Callers (1)** | `FUN_00402b30` (2 UNCONDITIONAL_CALL sites) |
| **Callees** | `FUN_00403f30`, `StdTree_Lrotate_Isnil31_Inferred`, `FUN_00403ee0`, length_error path |

## Confidence

| Claim | Level |
|---|---|
| Role always-insert + rebalance | High |
| ABI EDI=map / ECX=where / RET 0xC / max-size imm | Confirmed |
| Layout color@+0x30 isnil@+0x31 node 0x38 | Confirmed |
| Product English | Open (`_Inferred`) |
