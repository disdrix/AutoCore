# Function record: FUN_004cbaa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbaa0` |
| **Canonical name** | `StdTree_EraseRange_Isnil29_Inferred` |
| **Ghidra name** | `FUN_004cbaa0` |
| **Address** | `0x004cbaa0`–`0x004cbb54` exclusive (**180 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (isnil@+0x29) |
| **Completion status** | **accept-with-gaps** — dual A/B 2026-08-04 WQ9F-C; see named record |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC map/set **range erase** for isnil@+0x29 nodes via free-subtree `FUN_004cb550` + single erase `StdTree_EraseAndRebalance_Isnil29_Inferred`.

## Signature

```c
void __thiscall FUN_004cbaa0(void *map, void **outIt, void *first, void *last); // RET 0x0C
```

## Artifacts

- Named record: `docs/reconstruction/functions/aa_004cbaa0_StdTree_EraseRange_Isnil29_Inferred.md`
- Raw: `docs/reconstruction/raw/aa_004cbaa0_FUN_004cbaa0.md`
- Annotated: `docs/reconstruction/raw/aa_004cbaa0_FUN_004cbaa0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil29_Inferred.cpp`
- Dual A/B: `reviews/A|B_aa_004cbaa0_StdTree_EraseRange_Isnil29_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow | **High** |
| Canonical name | **Inferred** structural |
