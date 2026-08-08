# Function record: StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041ba30` |
| **Canonical name** | `StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred` |
| **Ghidra name** | `FUN_0041ba30` |
| **Address** | `0x0041ba30`–`0x0041bbc5` inclusive (**406 B** / `0x196`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21 char-key family) |
| **Wave** | R12-011 OWN-ONLY dual 2026-08-05 |
| **Parent dual** | `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007) |
| **Dual start** | 2646 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_0041ba30`
- Scaffold alias: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0041ba30`
- Structural: `StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred` (product demangle open)

## Purpose

Always-allocate map/set node insert + RB rebalance for the **char-key isnil@+0x21** node family (node **0x24**, color@**+0x20**, key char @**+0x0C**). Throws `"map/set<T> too long"` when `size ≥ 0x0CCCCCCB`. Uses residual buynode `0041d860` and dualed L/R rotates `0050e9f0` / `005a27f0`. Parent residual InsertOrFind-style `0041a570` supplies placement (char compare).

## Signature

```c
Node** __thiscall StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred(
    /*ECX*/ MapShell* map,
    Node** out,
    char addLeft,
    Node* where,
    const void* value);
// RET 0x10; *out = new node; EAX = out; root blackened
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x0041d860` | buynode node0x24 / isnil21 | buynode (undualed; raw sealed) |
| `0x0041a570` | char-key InsertOrFind parent | caller (2 sites; undualed) |
| `0x0050e9f0` | `StdTree_Lrotate_Isnil21_Inferred` | Lrotate (dualed R10-030) |
| `0x005a27f0` | `StdTree_Rrotate_Isnil21_Inferred` | Rrotate (dualed R11-007) |
| `0x00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | peer Val16/node0x28 always-insert (do **not** merge) |
| `0x00406c40` | `StdTree_InsertAndRebalance_Isnil29_Inferred` | peer family isnil@+0x29 |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0041ba30_FUN_0041ba30.md`
- Annotated: `docs/reconstruction/raw/aa_0041ba30_FUN_0041ba30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0041ba30.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0041ba30_StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0041ba30_StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-0041ba30-r12-report.md`

## Callers / callees

| **Callers (1)** | `FUN_0041a570` — 2 UNCONDITIONAL_CALL (`0041a5c9`, `0041a600`) |
| **Callees** | `FUN_0041d860`, `FUN_0050e9f0`, `FUN_005a27f0`, length_error path (`00401a40` / `_CxxThrowException` / `basic_string`) |

## Confidence

| Claim | Level |
|---|---|
| Role always-insert + rebalance | **High** |
| ABI / RET 0x10 / size gate `0x0CCCCCCB` | **High** (bytes sealed; not Runtime Confirmed) |
| Layout color@+0x20 isnil@+0x21 node 0x24 char@+0x0C | **High** (buynode raw + rebalance offsets + parent compare) |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
