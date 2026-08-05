# Annotated low-level: FUN_006cad30 / LinkPair_CanonAndSort_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_006cad30` |
| VA | `0x006cad30` |
| Body | `0x006cad30`–`0x006cad7f` exclusive (**79** B) |
| Canonical name | `LinkPair_CanonAndSort_Inferred` |
| Ghidra | `FUN_006cad30` |
| System | phys / bind link-pair list prep |
| Date | 2026-07-29 (W28-Q OWN-ONLY dual) |

## Machine-level notes

- **cdecl**: `push edi; mov edi,[esp+0xc]` loads count; plain `ret`.
- Element stride **8**: two `int*` at +0 / +4.
- Per-pair swap when `*(uint*)(right+4) < *(uint*)(left+4)`.
- `mov byte ptr [esp+count],0` clears low byte of count before push as unused 4th arg to `FUN_006cac60`.
- `FUN_006cac60`: recursive quicksort, dual-key compare on `(pair[0]+4, pair[1]+4)`.
- Callers (bind/unbind/island commit) invoke **twice** — once per side list.

## Pseudocode (annotated)

```c
// LinkPair_CanonAndSort_Inferred
// array: count entries of { Object* a; Object* b; }  // 8 bytes
// order within pair and across array by Object::key @ +4 (unsigned)
void LinkPair_CanonAndSort(Pair8* array, int count)  // __cdecl
{
  if (count == 0) return;

  for (int i = 0; i < count; ++i) {
    Object* a = array[i].a;
    Object* b = array[i].b;
    if (b->key4 < a->key4) {   // unsigned
      array[i].a = b;
      array[i].b = a;
    }
  }

  // MSVC: zero low byte of stack count; unused depth/arg to qsort
  uint unused = (uint)count & 0xffffff00;
  if (count > 1)
    LinkPair_QuickSort(array, 0, count - 1, unused);  // FUN_006cac60
}
```

## Open questions

- Product type of pointed objects (phys body / world-obj link id @ +4).
- Full dual seal of nested `FUN_006cac60` (not OWN this wave).
- Runtime / bit-exact open.
