# Function record: FUN_0051bed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bed0` |
| **Canonical name** | `Map_FreeSubtree_Isnil15_B` (prefer named record) |
| **Address** | `0x0051bed0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (isnil@+0x15 free-subtree) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** 2026-08-04 (WQ9G-D) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Scaffold alias for `Map_FreeSubtree_Isnil15_B`. See named function record.

## Signature (sealed)

```c
void Map_FreeSubtree_Isnil15_B(void *node); // stack; RET 4
```

## Artifacts

- Named record: `docs/reconstruction/functions/aa_0051bed0_Map_FreeSubtree_Isnil15_B.md`
- Raw (+ re-verify): `docs/reconstruction/raw/aa_0051bed0_FUN_0051bed0.md`
- Annotated: `docs/reconstruction/raw/aa_0051bed0_FUN_0051bed0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_FreeSubtree_Isnil15_B.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051bed0.cpp`
- Review A/B: `docs/reconstruction/reviews/A|B_aa_0051bed0_Map_FreeSubtree_Isnil15_B.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `Map_EraseRange_Isnil15_B` `0x0051d940` | full clear @ `0x0051d95c` |
| Caller | self | right recurse |
| Callee | `operator_delete` | |

## Confidence

| Claim | Level |
|---|---|
| Prefer named `Map_FreeSubtree_Isnil15_B` | **High** |
| Byte-correct left-walk free algebra | **Confirmed** |
| Runtime / bit-exact | Open |
