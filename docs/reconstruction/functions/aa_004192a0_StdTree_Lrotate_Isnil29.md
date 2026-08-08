# Function record: StdTree_Lrotate_Isnil29

| Field | Value |
|---|---|
| **Stable ID** | `aa_004192a0` |
| **Canonical name** | `StdTree_Lrotate_Isnil29` (inferred) |
| **Ghidra symbol** | `FUN_004192a0` |
| **Address** | `0x004192a0` |
| **Body** | `0x004192a0`–`0x004192ed` exclusive (**77** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std `_Tree` left-rotate (isnil@+0x29) |
| **Completion status** | **Sealed** — dual A/B accept (WQ9D-C 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_004192a0`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_CVOGHBAIBase_GetTargetFromAggro_004192a0` (**narrow** — shared helper)
- Twin: `FUN_004192f0` Rrotate (isnil@+0x29; sibling partition OWN)
- Peer Val12: `StdTree_Lrotate_Val12` (`aa_00573170`, isnil@+0x19)

## Purpose

Left-rotate about tree node `x` for the large-node red-black family (isnil @ `+0x29`, color @ `+0x28`). Classical `_Lrotate`: promote `x->right` to `x`'s position; `x` becomes left child of that node. Shared by `Map_EraseNode` and insert/rebalance paths.

## Signature (sealed)

```c
// __thiscall; ECX = tree*; stack = node* x; void; RET 4
void __thiscall StdTree_Lrotate_Isnil29(int32_t tree, int32_t x);
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x28 | color |
| +0x29 | isnil |
| tree+4 | head; head+4 = root |

## Artifacts

- Raw (+ WQ9D-C re-verify): `docs/reconstruction/raw/aa_004192a0_FUN_004192a0.md`
- Annotated: `docs/reconstruction/raw/aa_004192a0_FUN_004192a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Lrotate_Isnil29.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_004192a0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004192a0_StdTree_Lrotate_Isnil29.md`
- Review B: `docs/reconstruction/reviews/B_aa_004192a0_StdTree_Lrotate_Isnil29.md`
- Scaffold record: `docs/reconstruction/functions/aa_004192a0_FUN_004192a0.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | *(none — leaf)* |
| **Callers (10)** | `FUN_00406c40`, `FUN_00409220`, `FUN_004cb740`, `FUN_004cbb60`, `Map_EraseNode` (`0051cb40`), `FUN_0058da40`, `FUN_0058dc30`, `FUN_005a3310`, `FUN_00603830`, `FUN_00603c90` |
| **Xrefs** | 21 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| Left-rotate semantics | **High** |
| isnil@+0x29 family | **High** |
| ABI thiscall + RET 4 | **High** |
| Name product English / demangle | **Inferred** |
| Runtime / differential | Open |
