# Annotated low-level: StdTree_Min_Val12 (FUN_005adfa0)

| Field | Value |
|---|---|
| Stable ID | `aa_005adfa0` |
| VA | `0x005adfa0` |
| Body | `0x005adfa0`–`0x005adfba` exclusive (**26** B) |
| Canonical | `StdTree_Min_Val12` (inferred) |
| Ghidra | `FUN_005adfa0` |
| System | MSVC std `_Tree` min / leftmost (Val12 node) |
| Date | 2026-07-29 (W28-O seal; scaffold 2026-07-23) |

## Machine-level notes

- **ABI:** **`__cdecl`**; one stack arg `node*`; returns **`node*`** in **EAX**; pure **`ret`** (`C3`).
- **Leaf:** 0 callees.
- **Node layout (Val12 / 0x1c):** `left@0`, `parent@4`, `right@8`, value 12 B @ `+0x0c`, `color@+0x18`, **`isnil@+0x19`**.
- **Semantics:** classical MSVC `_Tree_min(node)`:
  1. If `node->left` is isnil → return `node`
  2. Else walk left while child is non-nil; return last non-nil
- **Pair:** `StdTree_Max_Val12` @ `0x00418bf0` (right walk).
- **Decompiler caveat:** live decompile is **void** and walks into the nil sentinel — **incorrect**. Prefer body hex / clean.
- **Shared:** 6 callers — Val12 erase paths that recompute `head->left` (begin / leftmost) after unlink.

## Pseudocode (byte-accurate)

```c
// __cdecl; node* → node*  (Tree_min / leftmost non-nil of subtree)
int32_t *StdTree_Min_Val12(int32_t *node)
{
  int32_t *left = (int32_t *)*node;           /* node->left */
  if (*(char *)((int)left + 0x19) != '\0')    /* left isnil */
    return node;
  do {
    node = left;
    left = (int32_t *)*node;
  } while (*(char *)((int)left + 0x19) == '\0');
  return node;
}
```

## Body hex

```
8b4424048b0880791900750e8d6424008bc18b088079190074f6c3
```

## Live vs raw

- Live 2026-07-29 decompile ≡ 2026-07-23 raw (same defective void CF).
- **Seal uses `read_memory` bytes**, not decompiler return type.

## Open questions

- Product / MSVC demangle per map instantiation.
- Runtime / bit-exact golden not run.
