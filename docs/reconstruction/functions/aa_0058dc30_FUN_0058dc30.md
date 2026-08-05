# Function record: MapFloatTfid_EraseNode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058dc30` |
| **Canonical name** | `MapFloatTfid_EraseNode_Inferred` |
| **Ghidra name** | `FUN_0058dc30` |
| **Address** | `0x0058dc30`–`0x0058dee5` (Ghidra truncated end `0x0058deb6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared tree helper / MapFloatTfid |
| **Calling convention** | MSVC `__thiscall` (ECX=tree; 2 stack args; `ret 8`) |
| **Completion status** | **Sealed** — dual A/B W25-A 2026-07-29; CF/string/layout High; out-it stack slots Probable |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- `FUN_0058dc30`
- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_0058dc30` (legacy scaffold — **rejected**)

## Purpose

Single-node erase for the **MapFloatTfid** MSVC red-black map (isnil `+0x29`): reject nil iterators, unlink, rebalance if black, free node, decrement size, write out iterator.

## Signature

```c
void __thiscall MapFloatTfid_EraseNode_Inferred(
    void* tree /* head@+4, size@+8 */,
    void* out_it /* iterator* */,
    void* node);
// ret 8
```

## Behavioral summary (sealed)

1. If `node+0x29` (isnil) → throw `"invalid map/set<T> iterator"`.
2. `FUN_004cb270` integrity; splice replacement child; rewire parent / head root.
3. Fix head begin (`FUN_0051b5d0`) / rbegin (`FUN_00421b50`).
4. If erased color black (`+0x28 == 1`): RB fixup loop + `FUN_004192a0` / `FUN_004192f0` rotates.
5. `operator_delete(node)`; if `size>0` then `size--`; store out iterator; `ret 8`.

## Callers / callees

| Direction | Address / name | Role |
|---|---|---|
| Caller | `FUN_0058df60` / `MapFloatTfid_EraseRange_Inferred` | sole CODE xref |
| Callee | `FUN_004cb270` | pre-erase check |
| Callee | `FUN_0051b5d0` / `FUN_00421b50` | leftmost / rightmost |
| Callee | `FUN_004192a0` / `FUN_004192f0` | rotates |
| Callee | `operator_delete` | free node |
| Callee | `_CxxThrowException` | nil iterator |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| MSVC map erase identity | **High** | throw string + RB pattern |
| isnil `+0x29` / color `+0x28` | **High** | decomp + prologue `cmp [eax+0x29]` |
| size-- + ret 8 | **High** | epilogue bytes (decomp missed) |
| Sole caller EraseRange | **High** | xrefs |
| Family MapFloatTfid naming | **High** | sibling duals 0058da00 / 0058df60 |
| Exact out-it stack slot map | **Probable** | bytes show write; symbolic slots open |
| Overall static CF | **High** | dual W25-A |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0058dc30_FUN_0058dc30.md` |
| Annotated | `raw/aa_0058dc30_FUN_0058dc30.annotated.md` |
| Clean | `reconstructed-exact/MapFloatTfid_EraseNode_Inferred.cpp` |
| Clean twin | `reconstructed-exact/FUN_0058dc30.cpp` |
| Dual A | `reviews/A_aa_0058dc30_MapFloatTfid_EraseNode_Inferred.md` |
| Dual B | `reviews/B_aa_0058dc30_MapFloatTfid_EraseNode_Inferred.md` |
| Range parent | `A/B_aa_0058df60_MapFloatTfid_EraseRange_Inferred.md` |
| Free subtree | `A/B_aa_0058da00_MapFloatTfid_FreeSubtree_Isnil29_Inferred.md` |

## Open questions

- PDB / product symbol for the map type (float→TFID inferred from gather family).
- Full contract of `FUN_004cb270`.
