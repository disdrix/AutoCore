# Function record: StdTree_InsertAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407200` |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil21_Inferred` |
| **Ghidra name** | `FUN_00407200` |
| **Address** | `0x00407200`–`0x00407395` inclusive (**406 B** / `0x196`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21 family) |
| **Wave** | WQ9I-B OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_00407200`
- Structural: `StdTree_InsertAndRebalance_Isnil21_Inferred` (product demangle open)

## Purpose

Always-allocate map/set node insert + RB rebalance for the **isnil@+0x21** node family (node **0x28**, color@**+0x20**, Val16 @+0x10). Throws `"map/set<T> too long"` when `size ≥ 0xFFFFFFE`. Uses dualed buynode `00408990` and residual L/R rotates `0050e9f0` / `005a27f0`. Parents dualed InsertHint `00406560` and residual InsertOrFind `00407060` supply placement.

## Signature

```c
void __thiscall StdTree_InsertAndRebalance_Isnil21_Inferred(
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
| `0x00408990` | `StdTree_Buynode_Val16_Isnil21_Inferred` | buynode (dualed WQ9H-J) |
| `0x00406560` | `StdTree_InsertHint_Isnil21_Inferred` | parent hint shell (dualed WQ9H-F) |
| `0x00407060` | InsertOrFind isnil21 | parent (WQ9I-C residual) |
| `0x0050e9f0` | Lrotate color@+0x20 | rotate leaf |
| `0x005a27f0` | Rrotate color@+0x20 | rotate leaf |
| `0x00406c40` | `StdTree_InsertAndRebalance_Isnil29_Inferred` | peer family (isnil@+0x29) |
| `0x004099b0` | node construct Val16 | nested by buynode (WQ9I-C) |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00407200_FUN_00407200.md`
- Annotated: `docs/reconstruction/raw/aa_00407200_FUN_00407200.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil21_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00407200.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00407200_StdTree_InsertAndRebalance_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00407200_StdTree_InsertAndRebalance_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-00409f30-00407200-wq9ib-report.md`

## Callers / callees

| **Callers (2)** | `FUN_00406560` (7 sites), `FUN_00407060` (2 sites) — 9 xrefs total |
| **Callees** | `FUN_00408990`, `FUN_0050e9f0`, `FUN_005a27f0`, length_error path (`00401a40` / throw) |

## Confidence

| Claim | Level |
|---|---|
| Role always-insert + rebalance | **High** |
| ABI / RET 0x10 / size gate | **Confirmed** |
| Layout color@+0x20 isnil@+0x21 node 0x28 | **Confirmed** (buynode dual + rebalance offsets) |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
