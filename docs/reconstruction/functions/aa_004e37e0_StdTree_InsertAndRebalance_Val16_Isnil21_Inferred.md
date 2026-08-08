# Function record: StdTree_InsertAndRebalance_Val16_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e37e0` |
| **Canonical name** | `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` |
| **Ghidra name** | `FUN_004e37e0` |
| **Address** | `0x004e37e0`–`0x004e39ca` inclusive (**491 B** / `0x1EB`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21 family) |
| **Wave** | R12-012 OWN-ONLY dual 2026-08-05 (dual start 2646) |
| **Parent dual** | `0x005a27f0` `StdTree_Rrotate_Isnil21_Inferred` |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |
| **Runtime** | **Open** — never Runtime Confirmed |

## Alias history

- Ghidra: `FUN_004e37e0`
- Scaffold: `Named_CalleeOf_Named_CalleeOf_CVOGReaction_UpdateRepairStationP_004e37e0`
- Structural: `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` (product demangle open)

## Purpose

Always-allocate map/set node insert + red-black rebalance for the **isnil@+0x21** node family (node **0x28**, color@**+0x20**, Val16 @+0x10). Throws `"map/set<T> too long"` when `size >= 0x0FFFFFFE`. Uses residual buynode `FUN_004e2b80` and dualed/peer rotates `0050e9f0` (L) / `005a27f0` (R). Sole parent shell `FUN_004e48b0` supplies placement (insert-or-find; no compare in this unit).

## Signature

```c
void __thiscall StdTree_InsertAndRebalance_Val16_Isnil21_Inferred(
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
| `0x004e2b80` | Val16 buynode clone (`FUN_004e2b80`) | buynode (scaffold; residual) |
| `0x00408990` | `StdTree_Buynode_Val16_Isnil21_Inferred` | peer buynode (same layout; other insert clone) |
| `0x00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | peer always-insert clone (buynode `00408990`) |
| `0x0050e9f0` | `StdTree_Lrotate_Isnil21_Inferred` | left rotate |
| `0x005a27f0` | `StdTree_Rrotate_Isnil21_Inferred` | right rotate (parent dual) |
| `0x004e48b0` | InsertOrFind shell (residual) | sole caller (2 sites) |

## Artifacts

- Raw (+ R12-012 re-verify): `docs/reconstruction/raw/aa_004e37e0_FUN_004e37e0.md`
- Annotated: `docs/reconstruction/raw/aa_004e37e0_FUN_004e37e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.cpp`
- Clean twin scaffold: `docs/reconstruction/reconstructed-exact/FUN_004e37e0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004e37e0_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004e37e0_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-004e37e0-r12-report.md`

## Callers / callees

| **Callers (1)** | `FUN_004e48b0` — 2 xrefs (`004e4919`, `004e495a`) |
| **Callees** | `FUN_004e2b80`, `FUN_0050e9f0`, `FUN_005a27f0`, length_error / `_CxxThrowException` |

## Confidence

| Claim | Level |
|---|---|
| Role always-insert + rebalance | **High** |
| ABI / RET 0x10 / size gate `0x0FFFFFFE` | **High** (byte-sealed) |
| Layout color@+0x20 isnil@+0x21 node 0x28 Val16 | **High** (buynode + rebalance offsets) |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
