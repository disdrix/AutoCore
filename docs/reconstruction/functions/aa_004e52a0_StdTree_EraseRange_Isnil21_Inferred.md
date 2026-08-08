# Function record: StdTree_EraseRange_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e52a0` |
| **Canonical name** | `StdTree_EraseRange_Isnil21_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_004e52a0` |
| **Address** | `0x004e52a0` |
| **Body** | `0x004e52a0`–`0x004e5353` (**180 B** / `0xB4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / MSVC `_Tree` range erase isnil@`+0x21` |
| **Completion status** | **Dual-reviewed** R13-025 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Parent dual** | `0x004e3e70` `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Partition** | R13 → R13-025 |
| **Dual start** | 2686 |
| **Terminal** | false |

## Purpose

MSVC-style red-black **range erase** `[first, last)` on an isnil21 tree/map facade (`head@+4`, `size@+8`). Full-tree path frees via `FUN_004e2e40` and resets the sentinel; partial path uses in-order successor + single-node erase `FUN_004e3e70`.

## Signature

```c
// ECX = map/tree facade; stack out_it*, first*, last*; RET 0x0C; void
void __thiscall StdTree_EraseRange_Isnil21_Inferred(
    MapShell_Isnil21* map,
    MapNode_Isnil21** outIt,
    MapNode_Isnil21* first,
    MapNode_Isnil21* last);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004da160` @ `0x004da2b4`; `FUN_004e73f0` @ `0x004e7402` |
| Callees | `FUN_004e2e40` (free-subtree isnil21); `FUN_004e3e70` / `StdTree_EraseAndRebalance_Isnil21_Inferred` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e52a0_FUN_004e52a0.md`
- Annotated: `docs/reconstruction/raw/aa_004e52a0_FUN_004e52a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil21_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004e52a0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004e52a0_StdTree_EraseRange_Isnil21_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004e52a0_StdTree_EraseRange_Isnil21_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_004e52a0_FUN_004e52a0.md`
- Sibling clone: `FUN_004e4e10` (same CF; free=`004e2e00`; R13-024 OWN)
- Val12 peer: `aa_0040d700` `StdTree_EraseRange_Val12`
- Parent erase: `aa_004e3e70` `StdTree_EraseAndRebalance_Isnil21_Inferred`

## Confidence

| Claim | Level |
|---|---|
| Control flow full vs partial | **High** |
| ABI ECX + 3 stack + RET 0x0C | **High** |
| isnil@+0x21 successor | **High** |
| Full free via `004e2e40` + head reset | **High** |
| Product map T demangle | **Low** |
| Value dtor on full free path | **Med** (owned by free/erase callees; plain delete on parent dual) |
