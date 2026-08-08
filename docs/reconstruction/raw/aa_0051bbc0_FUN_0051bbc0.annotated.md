# Annotated low-level: Map_FreeSubtree_Isnil29 (FUN_0051bbc0)

| Field | Value |
|---|---|
| Stable ID | `aa_0051bbc0` |
| VA | `0x0051bbc0`–`0x0051bbf4` (**53 B**) |
| System | STL map free-subtree (isnil@+0x29) |
| Date | 2026-08-04 WQ9E-H |
| Canonical | `Map_FreeSubtree_Isnil29` |

## Machine-level notes

- Decompiler **wrong/incomplete**: omits left-walk loop; marks operator_delete noreturn.
- Bytes: right-recursive free + left iterate + RET 4; isnil @ +0x29.
- ECX = tree_base threaded (unused in body); stack = node*.
- Sole external caller: Map_EraseRange full-clear (`0x0051c7dc`).

## Byte-corrected pseudocode

```c
void __fastcall Map_FreeSubtree_Isnil29(void *tree_base, void *node)
{
  if (*(char *)((int)node + 0x29) != 0)
    return;
  for (;;) {
    Map_FreeSubtree_Isnil29(tree_base, *(void **)((int)node + 8));
    {
      void *left = *(void **)node;
      operator_delete(node);
      node = left;
    }
    if (*(char *)((int)node + 0x29) != 0)
      break;
  }
}
```

## Open questions

- Product map`<K,V>` type / value size.
- Whether all hosts of Map_EraseRange share value layout.
