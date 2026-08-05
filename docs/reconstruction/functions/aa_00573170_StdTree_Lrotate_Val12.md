# Function record: StdTree_Lrotate_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573170` |
| **Canonical name** | `StdTree_Lrotate_Val12` (inferred) |
| **Ghidra symbol** | `FUN_00573170` |
| **Address** | `0x00573170` |
| **Body** | `0x00573170`–`0x005731BE` exclusive (**78** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std `_Tree` left-rotate (Val12) |
| **Completion status** | **Sealed** — dual A/B accept (W26-Q 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00573170`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_00573170` (**narrow** — shared helper)
- Twin: `StdTree_Rrotate_Val12` (`aa_00418c10`)

## Purpose

Left-rotate about tree node `x` for Val12 red-black nodes (isnil @ `+0x19`). Classical `_Lrotate`: promote `x->right` to `x`'s position; `x` becomes left child of that node. Used by insert/erase rebalance for every Val12 map/set that shares this instantiation.

## Signature (sealed)

```c
// __thiscall; ECX = tree*; stack = node* x; void; RET 4
void __thiscall StdTree_Lrotate_Val12(int32_t tree, int32_t x);
```

## Layout

| Offset | Field |
|---|---|
| node+0 | left |
| node+4 | parent |
| node+8 | right |
| node+0x0c | value[12] |
| node+0x18 | color |
| node+0x19 | isnil |
| tree+4 | `_Myhead` |
| head+4 | root (`_Parent`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00573170_FUN_00573170.md` (+ W26-Q append)
- Annotated: `docs/reconstruction/raw/aa_00573170_FUN_00573170.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Lrotate_Val12.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00573170.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00573170_StdTree_Lrotate_Val12.md`
- Review B: `docs/reconstruction/reviews/B_aa_00573170_StdTree_Lrotate_Val12.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | *(none — leaf)* |
| **Callers (13)** | `FUN_004188e0`, `FUN_0044a8c0`, `FUN_004e4130`, `FUN_0051c1c0`, `FUN_00539210`, `FUN_005399f0`, `FUN_00567450`, `FUN_00573250`, `FUN_00573510`, `FUN_005ae4e0`, `FUN_005ae990`, `FUN_005e13b0`, `FUN_005e15a0` |
| **Xrefs** | 26 |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| Left-rotate semantics | **High** |
| Val12 node (isnil@+0x19) | **High** (paired with sealed buynode) |
| ABI thiscall + RET 4 | **High** |
| Name product English / demangle | **Inferred** |
| Runtime / differential | Open |
