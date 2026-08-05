# Function record: StdTree_Erase_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573250` |
| **Canonical name** | `StdTree_Erase_Val12` (Inferred) / `Map_EraseNode_Val12` |
| **Ghidra name** | `FUN_00573250` |
| **Address** | `0x00573250` |
| **Body range** | `0x00573250`–`0x00573506` exclusive (**694** B / `0x2B6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map single-node erase (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + string + post-delete tail sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00573250_StdTree_Erase_Val12.md`, `reviews/B_aa_00573250_StdTree_Erase_Val12.md` (2026-07-29 W27-S) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00573250`
- `Map_EraseNode_Val12` (structural synonym; peer of `Map_EraseNode` @ `0x0051cb40` with Val12 layout)

## Purpose

Erase one non-nil Val12 red-black tree node: throw on isnil, advance out-iterator to successor, unlink + rebalance, `operator_delete`, `size--`, publish successor.

## Signature

```c
void __thiscall StdTree_Erase_Val12(
    MapShell_Val12* map,       // ECX; +0x04 head, +0x08 size
    MapNode_Val12** outIt,      // *outIt = successor after erase
    MapNode_Val12* node);       // node to erase
// RET 8
```

## Algorithm

1. If `node->isnil` → throw `"invalid map/set<T> iterator"`.
2. Successor via `FUN_005ae0b0` into out-iterator slot.
3. Unlink node; update root / leftmost / rightmost (`FUN_005adfa0` / `FUN_00418bf0` as needed).
4. If erased was black → RB fixup (`FUN_00573170` / `FUN_00418c10`).
5. `operator_delete(node)`; if `size>0` then `size--`; `*outIt = succ`; ret 8.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00573250_FUN_00573250.md`
- Annotated: `docs/reconstruction/raw/aa_00573250_FUN_00573250.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Erase_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00573250.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00573250-00573510-w27s-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005ae0b0`, `FUN_005adfa0`, `FUN_00418bf0`, `FUN_00573170`, `FUN_00418c10`, `operator_delete`, STL string/exception, `_CxxThrowException` |
| **Callers** | `FUN_00573700`, `FUN_00572ab0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw (main path) | **High** |
| `ret 8` + thiscall ECX=map | **High** (byte epilogue) |
| Val12 / color@+0x18 / isnil@+0x19 | **High** |
| Throw string + isnil gate | **High** |
| Post-delete size-- + *outIt | **High** (bytes; decomp drops tail) |
| Two-child transplant full fidelity | **Medium** (Ghidra "unreachable" blocks) |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Peer erase (different layout): `aa_0051cb40` `Map_EraseNode` (isnil@+0x29)
- Rotates: `aa_00573170` `StdTree_Lrotate_Val12`, `aa_00418c10` `StdTree_Rrotate_Val12` (W26-Q)
- Insert twin family: `aa_00573510` `StdTree_InsertAndRebalance_Val12`
