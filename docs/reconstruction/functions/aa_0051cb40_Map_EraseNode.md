# Function record: Map_EraseNode

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051cb40` |
| **Canonical name** | `Map_EraseNode` |
| **Ghidra name** | `FUN_0051cb40` |
| **Address** | `0x0051cb40`–`0x0051cdf5` (**694 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-07-29 (W19-I OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC red-black tree **single-node erase** for the large-node family (`isnil@+0x29`, `color@+0x28`, `key@+0x10`). Throws `"invalid map/set<T> iterator"` on nil. Writes successor to `*pOutIt` and decrements `map->size@+0x08`.

## Signature (byte-sealed)

```c
void __thiscall Map_EraseNode(
    void *map,        // ECX — head @ +4, size @ +8
    void **pOutIt,    // stack0 — successor out
    void *pNode);     // stack1 — node to erase
// RET 8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051cb40_FUN_0051cb40.md`
- Annotated: `docs/reconstruction/raw/aa_0051cb40_FUN_0051cb40.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_EraseNode.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051cb40.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051cb40_Map_EraseNode.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051cb40_Map_EraseNode.md`
- Alias record: `docs/reconstruction/functions/aa_0051cb40_FUN_0051cb40.md`
- Rejected scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGHBAIBase_GetTargetFromAggro_0051cb40.cpp`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `Skill_ClearCastBindingAndMaybeRestartCd` | `0x0051a756` |
| Caller | `FUN_0051c7c0` / `FUN_0051d880` | range erase wrappers |
| Caller | `CVOGHBAIBase_GetTargetFromAggro` | `0x0063914a` |
| Callee | `FUN_004cb270` | successor (isnil@+0x29) |
| Callee | `FUN_0051b5d0` / `FUN_00421b50` | min / max for begin/end |
| Callee | `FUN_004192a0` / `FUN_004192f0` | rotations |
| Callee | `operator_delete` | free node (falls through) |
| Callee | `_CxxThrowException` | invalid iterator |

## Confidence

| Claim | Level |
|---|---|
| STL erase role + throw string | **Confirmed** |
| ABI `thiscall` + `ret 8` + size-- | **Confirmed** (bytes) |
| Node isnil@+0x29 / color@+0x28 | **Confirmed** |
| Family with `Map_ExactFindByIntKey` | **High** |
| Product/PDB symbol | Open (`Map_EraseNode` structural) |
| Runtime / image diff | Open |
