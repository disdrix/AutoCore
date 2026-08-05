# Annotated low-level: FUN_005ae0b0 / StdTree_Inc_Val12

| Field | Value |
|---|---|
| Stable ID | `aa_005ae0b0` |
| VA | `0x005ae0b0`–`0x005ae0fb` exclusive (**75 B**) |
| System | std red-black tree / map iterator (Val12) |
| Date | 2026-07-29 (W28-N re-verify) |

## Machine-level notes

- Leaf; bare `C3` RET; ECX = `node**` (iterator).
- isnil gate at `node+0x19`; right @ `+8`; parent @ `+4`; left @ `+0` — **Val12** family.
- Two successor paths:
  1. **Right subtree exists (not nil):** start at right; walk **left** while left not nil; store that node.
  2. **No right:** walk **parent** while current is parent's right; store parent (may be nil header).
- If `*it` already nil: fall through no-op (iterator at end).
- Full body hex (75 B): see raw re-verify section.
- **No** `disassemble_bytes`; CF from decompile + full-body `read_memory`.

## Pseudocode (annotated)

```c
// ECX = iterator (node**); advances *it to in-order successor
void __fastcall StdTree_Inc_Val12(StdTreeNode_Val12 **it)
{
  StdTreeNode_Val12 *node = *it;
  if (node->isnil != 0)
    return; // end / nil — no-op

  StdTreeNode_Val12 *right = node->right;
  if (right->isnil == 0) {
    // successor = leftmost of right subtree
    StdTreeNode_Val12 *p = right;
    while (p->left->isnil == 0)
      p = p->left;
    *it = p;
    return;
  }

  // walk up while coming from right child
  StdTreeNode_Val12 *parent = node->parent;
  while (parent->isnil == 0 && *it == parent->right) {
    *it = parent;
    parent = parent->parent;
  }
  *it = parent;
}
```

## Callers (erase / successor consumers)

`FUN_004188e0`, `FUN_0040d5b0`, `FUN_004e4130`, `FUN_005399f0`, `FUN_0053a8e0`,
`FUN_00572ab0`, `FUN_00573250`, `FUN_005ae990` (StdTree_EraseNode_Val12), `FUN_005e15a0`.

## Open questions

- Product/MSVC demangle per map instantiation.
- Whether any non-Val12 clone exists with different isnil offset (do not merge blindly).
- Runtime / bit-exact — open.
