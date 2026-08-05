# Function record: StdMap_EraseIterator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004baa30` |
| **Canonical name** | `StdMap_EraseIterator_Inferred` |
| **Ghidra name** | `FUN_004baa30` |
| **Address** | `0x004baa30` |
| **Body range** | `0x004baa30`–`0x004bace5` (694 bytes sealed) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CRT / MSVC STL `_Tree` erase (shared; NDSpecialFX map via range parent) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes + ABI + throw string sealed; product symbol / K-V open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004baa30_StdMap_EraseIterator_Inferred.md`, `reviews/B_aa_004baa30_StdMap_EraseIterator_Inferred.md` (2026-07-29 W23-I) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_004baa30`
- Scaffold chain name `Named_CalleeOf_…_004baa30`
- Sibling range: `StdMap_EraseRange_Inferred` @ `0x004bacf0`
- Sibling free: `StdMap_FreeSubtree_Isnil15_Inferred` @ `0x004ba770`

## Purpose

MSVC-style **`_Tree::erase(const_iterator)`** for `map`/`set`:

1. If `node->isnil` (`+0x15`) → throw `"invalid map/set<T> iterator"`.
2. Advance/out-it prep (`FUN_00673070`).
3. Splice replacement child; rewire parent / root / begin / rbegin.
4. If erased color black → RB fixup with rotations.
5. `operator_delete(node)`; if `map->size > 0` then `--size`; write out iterator; `ret 8`.

## Signature

```c
void __thiscall StdMap_EraseIterator_Inferred(
    void *map,       // ECX — head* @+4, size @+8
    void *out_it,    // stack — iterator shadow / out
    void *node);     // stack — node* to erase
// ret 8
```

## Algorithm

See annotated + clean. Epilogue size-- is **byte-sealed** and missing from decompiler due to false noreturn on `operator_delete`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004baa30_FUN_004baa30.md`
- Annotated: `docs/reconstruction/raw/aa_004baa30_FUN_004baa30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_EraseIterator_Inferred.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_004baa30.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004baa30_FUN_004baa30.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004baa30-00979290-w23i-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller | `0x004bacf0` | `StdMap_EraseRange_Inferred` (only) |
| Callee | `0x00673070` | pre-delete iterator advance |
| Callee | `0x004e12a0` | leftmost |
| Callee | `0x00421b70` | rightmost |
| Callee | `0x004e22d0` | rotate A |
| Callee | `0x006753b0` | rotate B |
| Callee | CRT | `operator_delete`, throw chain |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| STL erase identity (throw string) | **High** |
| thiscall `ret 8` | **High** |
| isnil/color offsets | **High** |
| Epilogue size-- | **High** (bytes; decomp miss) |
| Product / PDB / K-V types | **Open** |
| Runtime / differential | Open |
