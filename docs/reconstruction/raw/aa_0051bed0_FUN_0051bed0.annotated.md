# Annotated low-level: Map_FreeSubtree_Isnil15_B (FUN_0051bed0)

| Field | Value |
|---|---|
| Stable ID | `aa_0051bed0` |
| VA | `0x0051bed0`–`0x0051bf05` exclusive (**53 B**) |
| Canonical | `Map_FreeSubtree_Isnil15_B` |
| System | STL / map-set (WQ-009 skill residual; Map_EraseRange_Isnil15_B free helper) |
| Date | 2026-08-04 WQ9G-D OWN dual |

## Machine-level notes

- Source: raw capture + live re-verify for `aa_0051bed0`.
- **Bytes authority:** decompiler omits left-child walk; reconstruct from `read_memory`.
- isnil@**+0x15**; left@**+0**; right@**+8**.
- ABI: stack node*; **ret 4**; ECX preserved/threaded unused (`mov ebx,ecx`).
- Sole external caller: dualed `Map_EraseRange_Isnil15_B` full-clear path (`head->parent` = root).
- Twin CF (different VA): dualed `Map_FreeSubtree_Isnil15` @ `0x0051be50` (caller `Map_EraseRange_Isnil15`).

## Pseudocode (byte-corrected)

```c
// Ghidra plate (misleading left-walk omission):
//   if (!isnil) { free(right); operator_delete(self); }

// Byte-correct MSVC free-subtree (isnil@+0x15):
void Map_FreeSubtree_Isnil15_B(void *node)
{
  if (*(char *)((int)node + 0x15) != 0)
    return;

  for (;;) {
    Map_FreeSubtree_Isnil15_B(*(void **)((char *)node + 8)); // right
    {
      void *left = *(void **)node;                   // left @ +0
      operator_delete(node);
      node = left;
    }
    if (*(char *)((int)node + 0x15) != 0)
      break;
  }
}
```

## Call graph

| Direction | Target | Notes |
|---|---|---|
| Caller | `Map_EraseRange_Isnil15_B` `0x0051d940` | full clear only @ `0x0051d95c` |
| Caller | self | right-child recurse @ `0x0051bee7` |
| Callee | `operator_delete` | after left snapshot |

## Open questions

- Exact map instantiation / value dtor (delete-only; no inlined value dtor observed).
- Why separate clone vs dualed `Map_FreeSubtree_Isnil15` (`0x0051be50`) — compilation unit / map type.
- Runtime / bit-exact open.
