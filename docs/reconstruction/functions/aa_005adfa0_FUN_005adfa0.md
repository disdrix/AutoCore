# Function record: FUN_005adfa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005adfa0` |
| **Canonical name** | `FUN_005adfa0` (Ghidra scaffold) |
| **Sealed name** | `StdTree_Min_Val12` — see `aa_005adfa0_StdTree_Min_Val12.md` |
| **Address** | `0x005adfa0` |
| **Body** | `0x005adfa0`–`0x005adfba` exclusive (**26** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std `_Tree` min / leftmost (Val12) |
| **Completion status** | **Sealed** — dual A/B accept (W28-O 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Structural: `StdTree_Min_Val12`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_005adfa0` (**narrow**)

## Purpose

Leftmost non-nil of subtree (MSVC `_Tree_min`). Prefer named record `aa_005adfa0_StdTree_Min_Val12.md`.

## Signature (sealed)

```c
// __cdecl; stack = node*; returns node* in EAX; RET
int32_t *FUN_005adfa0(int32_t *node);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005adfa0_FUN_005adfa0.md` (+ W28-O append)
- Annotated: `docs/reconstruction/raw/aa_005adfa0_FUN_005adfa0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_005adfa0.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/StdTree_Min_Val12.cpp`
- Named record: `docs/reconstruction/functions/aa_005adfa0_StdTree_Min_Val12.md`
- Review A/B: `docs/reconstruction/reviews/{A,B}_aa_005adfa0_StdTree_Min_Val12.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | *(none — leaf)* |
| **Callers (6)** | `FUN_004188e0`, `FUN_004e4130`, `FUN_005399f0`, `FUN_00573250`, `FUN_005ae990`, `FUN_005e15a0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from **bytes** | **High** |
| Decompiler void presentation | **Rejected** (defect; do not port) |
| Types / name demangle | **Inferred** / Open |
