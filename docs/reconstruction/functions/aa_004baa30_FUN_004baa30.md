# Function record: FUN_004baa30

Scaffold twin of `functions/aa_004baa30_StdMap_EraseIterator_Inferred.md`.

| Field | Value |
|---|---|
| **Stable ID** | `aa_004baa30` |
| **Canonical name** | `StdMap_EraseIterator_Inferred` (INFERRED) |
| **Ghidra name** | `FUN_004baa30` |
| **Address** | `0x004baa30` |
| **Body range** | `0x004baa30`–`0x004bace5` (694 B sealed; Ghidra end `004bacb6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CRT / MSVC STL `_Tree` erase |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + throw string + ABI sealed; K/V types open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004baa30_StdMap_EraseIterator_Inferred.md`, `reviews/B_aa_004baa30_StdMap_EraseIterator_Inferred.md` |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_004baa30`
- Scaffold: `Named_CalleeOf_…_004baa30`
- Named: `StdMap_EraseIterator_Inferred`

## Purpose

MSVC **`map`/`set` single-iterator erase**: nil → throw `"invalid map/set<T> iterator"`; else unlink, RB rebalance, `operator_delete`, size--.

## Signature

```c
void __thiscall FUN_004baa30(void *map /*ECX*/, void *out_it /*stack*/, void *node /*stack*/);
// ret 8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004baa30_FUN_004baa30.md`
- Annotated: `docs/reconstruction/raw/aa_004baa30_FUN_004baa30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004baa30.cpp`
- Named: `docs/reconstruction/reconstructed-exact/StdMap_EraseIterator_Inferred.cpp`
- Named record: `docs/reconstruction/functions/aa_004baa30_StdMap_EraseIterator_Inferred.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004baa30-00979290-w23i-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller | `0x004bacf0` | `StdMap_EraseRange_Inferred` |
| Callee | rotations / min-max / delete | see named record |

## Confidence

| Claim | Level |
|---|---|
| Control flow + throw string | **High** |
| thiscall `ret 8` | **High** |
| isnil `+0x15` / color `+0x14` | **High** |
| Product / K-V types | **Open** |
