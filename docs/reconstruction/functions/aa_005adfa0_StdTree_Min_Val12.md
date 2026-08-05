# Function record: StdTree_Min_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005adfa0` |
| **Canonical name** | `StdTree_Min_Val12` (inferred) |
| **Ghidra symbol** | `FUN_005adfa0` |
| **Address** | `0x005adfa0` |
| **Body** | `0x005adfa0`–`0x005adfba` exclusive (**26** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std `_Tree` min / leftmost (Val12) |
| **Completion status** | **Sealed** — dual A/B accept (W28-O 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_005adfa0`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_005adfa0` (**narrow** — shared helper)
- Twin: `StdTree_Max_Val12` (`aa_00418bf0`)

## Purpose

Return the leftmost non-nil node of the subtree rooted at `node` (MSVC `_Tree_min`). Val12 erase paths use this to recompute the tree head's left link (`begin` / leftmost) when the erased node was leftmost.

## Signature (sealed)

```c
// __cdecl; stack = node*; returns node* in EAX; RET
int32_t *StdTree_Min_Val12(int32_t *node);
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

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005adfa0_FUN_005adfa0.md` (+ W28-O append)
- Annotated: `docs/reconstruction/raw/aa_005adfa0_FUN_005adfa0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Min_Val12.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005adfa0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005adfa0_StdTree_Min_Val12.md`
- Review B: `docs/reconstruction/reviews/B_aa_005adfa0_StdTree_Min_Val12.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | *(none — leaf)* |
| **Callers (6)** | `FUN_004188e0`, `FUN_004e4130`, `FUN_005399f0`, `FUN_00573250`, `FUN_005ae990`, `FUN_005e15a0` |
| **Xrefs** | 6 (call) |

## Confidence

| Claim | Level |
|---|---|
| Body size + `C3` ret | **High** (`read_memory`) |
| Tree_min semantics (bytes) | **High** |
| Return `node*` in EAX | **High** (callers assign; EAX leave) |
| Val12 isnil@+0x19 | **High** (paired Val12 family) |
| Decompiler void CF | **Rejected** (defect) |
| Name product English / demangle | **Inferred** |
| Runtime / differential | Open |
