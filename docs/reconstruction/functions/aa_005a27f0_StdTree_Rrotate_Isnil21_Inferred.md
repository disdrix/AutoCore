# Function record: StdTree_Rrotate_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a27f0` |
| **Canonical name** | `StdTree_Rrotate_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_005a27f0` |
| **Address** | `0x005a27f0`–`0x005a2841` inclusive (**82 B** / `0x52`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21 family) |
| **Wave** | R11-007 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias history

- Ghidra: `FUN_005a27f0`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Updat_005a27f0` (**narrow/wrong** — shared helper)
- Structural: `StdTree_Rrotate_Isnil21_Inferred` (product demangle open)

## Purpose

Right-rotate about tree node `x` for the small-node red-black family (isnil @ `+0x21`, color @ `+0x20`, node **0x28** / Val16). Classical `_Rrotate`: promote `x->left` to `x`'s position; `x` becomes right child of that node. Shared by dualed InsertAndRebalance isnil21 and many other map shells.

## Signature (sealed)

```c
// __thiscall; ECX = tree*; stack = node* x; void; RET 4
void __thiscall StdTree_Rrotate_Isnil21_Inferred(int32_t tree, int32_t *x);
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x20 | color |
| +0x21 | isnil |
| tree+4 | head; head+4 = root |

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x0050e9f0` | `StdTree_Lrotate_Isnil21_Inferred` | twin Lrotate (R10-030 dualed) |
| `0x00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | parent consumer (dualed WQ9I-B) |
| `0x00408990` | `StdTree_Buynode_Val16_Isnil21_Inferred` | family buynode (dualed) |
| `0x004192f0` | `StdTree_Rrotate_Isnil29_Inferred` | peer Rrotate (isnil@+0x29; dualed) |
| `0x0042a840` | `StdTree_Rrotate_Isnil2D_Inferred` | peer Rrotate (isnil@+0x2D; dualed) |
| `0x00403ee0` | `StdTree_Rrotate_Isnil31_Inferred` | peer Rrotate (isnil@+0x31; dualed) |

## Artifacts

- Raw (+ R11-007 re-verify): `docs/reconstruction/raw/aa_005a27f0_FUN_005a27f0.md`
- Annotated: `docs/reconstruction/raw/aa_005a27f0_FUN_005a27f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Rrotate_Isnil21_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005a27f0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005a27f0_StdTree_Rrotate_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005a27f0_StdTree_Rrotate_Isnil21_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_005a27f0_FUN_005a27f0.md`
- Report: `docs/agents/task-dual-ab-005a27f0-r11-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | *(none — leaf)* |
| **Callers (14)** | `FUN_00405650`, `FUN_00407200`, `FUN_0041ba30`, `FUN_004e37e0`, `FUN_004e3e70`, `FUN_00511950`, `FUN_00511c00`, `FUN_0059d300`, `FUN_005a2ea0`, `FUN_005a3500`, `FUN_005a4590`, `FUN_005a4950`, `FUN_005ae2f0`, `FUN_005ae6d0` |
| **Xrefs** | 35 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| Right-rotate semantics | **High** |
| isnil@+0x21 family | **High** |
| ABI thiscall + RET 4 | **High** |
| Name product English / demangle | **Inferred** |
| Runtime / differential | Open |
