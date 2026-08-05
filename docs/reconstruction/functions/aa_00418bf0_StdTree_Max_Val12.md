# Function record: StdTree_Max_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418bf0` |
| **Canonical name** | `StdTree_Max_Val12` (inferred) |
| **Ghidra symbol** | `FUN_00418bf0` |
| **Address** | `0x00418bf0` |
| **Body** | `0x00418bf0`–`0x00418c0b` exclusive (**27** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std `_Tree` max / rightmost (Val12) |
| **Completion status** | **Sealed** — dual A/B accept (W28-O 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00418bf0`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_00418bf0` (**narrow** — shared helper)
- Twin: `StdTree_Min_Val12` (`aa_005adfa0`)
- Neighbor: `StdTree_Rrotate_Val12` @ `0x00418c10`

## Purpose

Return the rightmost non-nil node of the subtree rooted at `node` (MSVC `_Tree_max`). Val12 erase paths use this to recompute the tree head's right link (`end` predecessor / rightmost) when the erased node was rightmost.

## Signature (sealed)

```c
// __cdecl; stack = node*; returns node* in EAX; RET
int32_t *StdTree_Max_Val12(int32_t *node);
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

- Raw: `docs/reconstruction/raw/aa_00418bf0_FUN_00418bf0.md` (+ W28-O append)
- Annotated: `docs/reconstruction/raw/aa_00418bf0_FUN_00418bf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Max_Val12.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00418bf0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00418bf0_StdTree_Max_Val12.md`
- Review B: `docs/reconstruction/reviews/B_aa_00418bf0_StdTree_Max_Val12.md`

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
| Tree_max semantics (bytes) | **High** |
| Return `node*` in EAX | **High** (callers assign; EAX leave) |
| Val12 isnil@+0x19 | **High** (paired Val12 family) |
| Decompiler void CF | **Rejected** (defect) |
| Name product English / demangle | **Inferred** |
| Runtime / differential | Open |
