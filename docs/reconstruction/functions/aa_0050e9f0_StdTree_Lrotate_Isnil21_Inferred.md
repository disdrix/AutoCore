# Function record: StdTree_Lrotate_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050e9f0` |
| **Canonical name** | `StdTree_Lrotate_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_0050e9f0` |
| **Address** | `0x0050e9f0`–`0x0050ea3d` inclusive (**78 B** / `0x4E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21 family) |
| **Wave** | R10-030 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias history

- Ghidra: `FUN_0050e9f0`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Updat_0050e9f0` (**narrow/wrong** — shared helper)
- Structural: `StdTree_Lrotate_Isnil21_Inferred` (product demangle open)

## Purpose

Left-rotate about tree node `x` for the small-node red-black family (isnil @ `+0x21`, color @ `+0x20`, node **0x28** / Val16). Classical `_Lrotate`: promote `x->right` to `x`'s position; `x` becomes left child of that node. Shared by dualed InsertAndRebalance isnil21 and many other map shells.

## Signature (sealed)

```c
// __thiscall; ECX = tree*; stack = node* x; void; RET 4
void __thiscall StdTree_Lrotate_Isnil21_Inferred(int32_t tree, int32_t x);
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
| `0x005a27f0` | Rrotate isnil21 | twin rotate (residual) |
| `0x00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | parent consumer (dualed WQ9I-B) |
| `0x00408990` | `StdTree_Buynode_Val16_Isnil21_Inferred` | family buynode (dualed) |
| `0x004192a0` | `StdTree_Lrotate_Isnil29` | peer Lrotate (isnil@+0x29; dualed) |
| `0x0044e010` | `StdTree_LeftRotate_Isnil2D_Inferred` | peer Lrotate (isnil@+0x2D; dualed) |
| `0x00403e90` | `StdTree_Lrotate_Isnil31_Inferred` | peer Lrotate (isnil@+0x31; dualed) |

## Artifacts

- Raw (+ R10-030 re-verify): `docs/reconstruction/raw/aa_0050e9f0_FUN_0050e9f0.md`
- Annotated: `docs/reconstruction/raw/aa_0050e9f0_FUN_0050e9f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Lrotate_Isnil21_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0050e9f0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0050e9f0_StdTree_Lrotate_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0050e9f0_StdTree_Lrotate_Isnil21_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0050e9f0_FUN_0050e9f0.md`
- Report: `docs/agents/task-dual-ab-0050e9f0-r10-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | *(none — leaf)* |
| **Callers (14)** | `FUN_00405650`, `FUN_00407200`, `FUN_0041ba30`, `FUN_004e37e0`, `FUN_004e3e70`, `FUN_00511950`, `FUN_00511c00`, `FUN_0059d300`, `FUN_005a2ea0`, `FUN_005a3500`, `FUN_005a4590`, `FUN_005a4950`, `FUN_005ae2f0`, `FUN_005ae6d0` |
| **Xrefs** | 30 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| Left-rotate semantics | **High** |
| isnil@+0x21 family | **High** |
| ABI thiscall + RET 4 | **High** |
| Name product English / demangle | **Inferred** |
| Runtime / differential | Open |
