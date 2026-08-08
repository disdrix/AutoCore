# Function record: StdTree_InsertAndRebalance_Val16_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a3500` |
| **Canonical name** | `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` |
| **Ghidra name** | `FUN_005a3500` |
| **Address** | `0x005a3500`–`0x005a36ea` inclusive (**491 B** / `0x1EB`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (Val16 / isnil@+0x21) |
| **Wave** | R12-031 OWN-ONLY dual 2026-08-05 |
| **Parent dual** | `0x005a27f0` `StdTree_Rrotate_Isnil21_Inferred` |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** (never Runtime Confirmed) |

## Alias history

- Ghidra: `FUN_005a3500`
- Structural: `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` (product demangle open; twin of dualed `0x004e37e0`)

## Purpose

Always-allocate map/set node insert + RB rebalance for the **isnil@+0x21** node family (node **0x28**, color@**+0x20**, Val16 @+0x10). Throws `"map/set<T> too long"` when `size ≥ 0x0FFFFFFE`. Uses residual buynode `004e2b80` and dualed L/R rotates `0050e9f0` / `005a27f0` (one L path inlined). Parent residual `FUN_005a3be0` supplies placement / uniqueness.

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
| `0x004e2b80` | buynode residual | `operator_new(0x28)` Val16 isnil21 |
| `0x0050e9f0` | `StdTree_Lrotate_Isnil21_Inferred` | L rotate (dualed) |
| `0x005a27f0` | `StdTree_Rrotate_Isnil21_Inferred` | R rotate (parent dual R11-007) |
| `0x004e37e0` | same structural name (R12-012) | near-byte twin (caller `004e48b0`) |
| `0x00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | peer always-insert (buynode `00408990`) |
| `0x005a3be0` | residual InsertOrFind-style | sole caller (2 sites) |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_005a3500_FUN_005a3500.md`
- Annotated: `docs/reconstruction/raw/aa_005a3500_FUN_005a3500.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val16_Isnil21_005a3500_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005a3500.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005a3500_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005a3500_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-005a3500-r12-report.md`

## Callers / callees

| **Callers (1)** | `FUN_005a3be0` — 2 UNCONDITIONAL_CALL (`005a3c49`, `005a3c8a`) |
| **Callees** | `FUN_004e2b80`, `FUN_0050e9f0`, `FUN_005a27f0` (×2), length_error path |

## Confidence

| Claim | Level |
|---|---|
| Role always-insert + rebalance | **High** |
| ABI / RET 0x10 / size gate `0x0FFFFFFE` | **High** (bytes sealed) |
| Layout color@+0x20 isnil@+0x21 node 0x28 Val16 | **High** (buynode + isnil imm) |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
