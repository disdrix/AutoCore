# Function record: StdTree_Rrotate_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418c10` |
| **Canonical name** | `StdTree_Rrotate_Val12` (inferred) |
| **Ghidra symbol** | `FUN_00418c10` |
| **Address** | `0x00418c10` |
| **Body** | `0x00418c10`–`0x00418c62` exclusive (**82** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std `_Tree` right-rotate (Val12) |
| **Completion status** | **Sealed** — dual A/B accept (W26-Q 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00418c10`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_00418c10` (**narrow** — shared helper)
- Twin: `StdTree_Lrotate_Val12` (`aa_00573170`)

## Purpose

Right-rotate about tree node `x` for Val12 red-black nodes (isnil @ `+0x19`). Classical `_Rrotate`: promote `x->left` to `x`'s position; `x` becomes right child of that node. Shared by the same Val12 insert/erase rebalance family as Lrotate.

## Signature (sealed)

```c
// __thiscall; ECX = tree*; stack = node* x; void; RET 4
void __thiscall StdTree_Rrotate_Val12(int32_t tree, int32_t *x);
```

## Layout

Same Val12 node / tree head layout as `StdTree_Lrotate_Val12`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00418c10_FUN_00418c10.md` (+ W26-Q append)
- Annotated: `docs/reconstruction/raw/aa_00418c10_FUN_00418c10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Rrotate_Val12.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00418c10.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00418c10_StdTree_Rrotate_Val12.md`
- Review B: `docs/reconstruction/reviews/B_aa_00418c10_StdTree_Rrotate_Val12.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | *(none — leaf)* |
| **Callers (13)** | `FUN_004188e0`, `FUN_0044a8c0`, `FUN_004e4130`, `FUN_0051c1c0`, `FUN_00539210`, `FUN_005399f0`, `FUN_00567450`, `FUN_00573250`, `FUN_00573510`, `FUN_005ae4e0`, `FUN_005ae990`, `FUN_005e13b0`, `FUN_005e15a0` |
| **Xrefs** | 32 |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| Right-rotate semantics | **High** |
| Val12 node (isnil@+0x19) | **High** |
| ABI thiscall + RET 4 | **High** |
| Name product English / demangle | **Inferred** |
| Runtime / differential | Open |
