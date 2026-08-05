# Annotated low-level: StdMap_EraseIterator_Inferred (`FUN_004baa30`)

| Field | Value |
|---|---|
| Stable ID | `aa_004baa30` |
| VA | `0x004baa30`–`0x004bace5` (694 B sealed; Ghidra lists end `004bacb6`) |
| Canonical name | `StdMap_EraseIterator_Inferred` |
| Ghidra name | `FUN_004baa30` |
| System | CRT / MSVC STL `_Tree` erase (shared; NDSpecialFX map clear path) |
| Date | 2026-07-29 (W23-I dual seal) |

## Machine-level notes

- Source: raw capture + live W23-I `decompile_function` / `read_memory` / callers.
- **Role:** MSVC-style **`map`/`set` single-iterator erase** — nil throw, unlink, RB rebalance, free node, size--.
- **STL seal:** throw string `"invalid map/set<T> iterator"` @ `0x00a152f0` (sibling of `"map/set<T> too long"` family).
- **Node layout (MSVC `_Tree_node`):**
  - `[0]` left*, `[1]` parent*, `[2]` right*
  - `+0x14` color (`0` red / `1` black) — also accessed as `(char)node[5]`
  - `+0x15` isnil sentinel flag
  - payload after header (type residual)
- **Map facade:** `this+4` = head/sentinel node*; `this+8` = size (decremented in epilogue).
- **ABI:** `__thiscall`; ECX = map*; stack: out-iterator storage + node*; **`ret 8`**.
- **Callee cluster:** rotations `FUN_004e22d0` / `FUN_006753b0`; min/max walks `FUN_004e12a0` / `FUN_00421b70`; pre-delete advance `FUN_00673070`; `operator_delete(node)`.
- **Caller:** only `FUN_004bacf0` (`StdMap_EraseRange_Inferred`) partial-range loop — successor computed **before** this erase.
- **Hazard:** Ghidra marks `operator_delete` noreturn → body end truncated at call; sealed epilogue continues through size-- / `*out` / SEH / `ret 8`.
- Prefer assembly for epilogue and for color/isnil offsets when decompiler flattens SEH dead blocks.

## Recovered CF (byte-aligned)

```c
// __thiscall  ret 8
// this = map { head* @+4, size @+8 }
// stack: void **out_it (or iterator shadow), Node *node
void StdMap_EraseIterator_Inferred(void *map, void **out_it /*stack*/, Node *node /*stack*/)
{
    // SEH frame LAB_009a16a2
    if (node->isnil /* +0x15 */) {
        // build std::string("invalid map/set<T> iterator") + exception
        // _CxxThrowException(..., &DAT_00acc34c)  // noreturn
    }
    FUN_00673070(); // advance/out-it prep (register state)

    // compute replacement child (right if present else left), rewire parent links
    // update head->parent (root), head->left (begin), head->right (rbegin) if needed
    // if erased node was black: RB fixup loop with left/right rotates
    //   (FUN_004e22d0 / FUN_006753b0) until root or red

    operator_delete(node);
    if (map->size /* +8 */ > 0)
        map->size--;
    // *out_it write from precomputed successor state
    // SEH restore; ret 8
}
```

## Call graph (OWN context)

| Direction | VA | Name |
|---|---|---|
| Caller | `0x004bacf0` | `StdMap_EraseRange_Inferred` |
| Callee | `0x00673070` | iterator advance / out prep (residual) |
| Callee | `0x004e12a0` | tree min / leftmost |
| Callee | `0x00421b70` | tree max / rightmost |
| Callee | `0x004e22d0` | rotate (one direction) |
| Callee | `0x006753b0` | rotate (other direction) |
| Callee | CRT | `operator_delete`, `_CxxThrowException`, `basic_string`/`exception` |
| Sibling | `0x004ba770` | `StdMap_FreeSubtree_Isnil15_Inferred` (full destroy, no throw) |
| Sibling | `0x004bacf0` | range erase (loops this) |

## Open questions

1. Product / PDB export name (`std::_Tree<...>::erase`).
2. Exact mapped key/value types at NDSpecialFX `@+0x228` instantiation.
3. Precise semantics of `FUN_00673070` out-iterator write operands (stack slots sealed; name open).
4. Runtime / bit-exact — open.
