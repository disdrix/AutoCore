# Annotated low-level: CNDHash_LookupByKey

| Field | Value |
|---|---|
| Stable ID | `aa_005b0920` |
| VA | `0x005b0920` |
| System | shared CNDHash container |
| Date | 2026-07-29 (dual A/B seal; scaffold 2026-07-23) |

## Machine-level notes

- **ABI:** `__thiscall(this, uint key)`, `RET 4`, return value* / NULL in EAX.
- **Leaf:** no callees; no traversal-lock check (`+0x1d` unused here).
- **Hash:** `index = mask(+0x08) & key` only.
- **Bucket:** `buckets(+0x10)[index]` is a **header**; chain head at header `+0x04`.
- **Node:** key `+0x10`, next `+0x0c`, value `+0x08` (return).
- Prefer bytes when decompiler adds redundant post-match null test — both agree on outcomes.
- Plate “USContinentUnlocked” is one consumer among 200+ call sites.

## Pseudocode (annotated)

```c
/* CNDHash_LookupByKey — sealed 2026-07-29
 * this+0x08: uint32 mask
 * this+0x10: BucketHdr** buckets
 * BucketHdr+0x04: Node* head
 * Node+0x08: void* value
 * Node+0x0c: Node* next
 * Node+0x10: uint32 key
 */
void * __thiscall CNDHash_LookupByKey(void *this, uint key)
{
  int node;
  /* bucketHdr = buckets[mask & key]; node = bucketHdr->head */
  node = *(int *)(*(int *)(*(int *)((int)this + 0x10)
                           + (*(uint *)((int)this + 8) & key) * 4) + 4);
  if (node != 0) {
    while (key != *(uint *)(node + 0x10)) {
      node = *(int *)(node + 0xc);
      if (node == 0) {
        return (void *)0x0;
      }
    }
    if (node != 0) { /* always true after match from non-null node */
      return *(void **)(node + 8);  /* value, not node */
    }
  }
  return (void *)0x0;
}
```

## Open questions

- Full CNDHash / node object sizes and ctor (mask power-of-two invariant).
- Exhaustive product map of every hash instance offset at call sites.
- Runtime confirmation / bit-exact.
