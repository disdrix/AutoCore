# Annotated low-level: FUN_0045cce0 → StdVector_EraseRange_Pod28

| Field | Value |
|---|---|
| Stable ID | `aa_0045cce0` |
| VA | `0x0045cce0`–`0x0045cd2b` exclusive (**75 B**) |
| System | MSVC POD vector erase stride **0x1c** |
| Date | 2026-07-29 W36-L |
| Canonical | `StdVector_EraseRange_Pod28` (**Inferred**) |

## Machine-level notes

- **4 stack args**, **RET 0x10**, return **out_it*** in EAX.
- Stride sealed: `ADD 0x1C` + `ECX=7` + `rep movsd` (or 7 dword stores in decompile).
- Empty range (first==last): no end mutate; still `*out=first`.
- last==end: truncate only (`end = first`).
- last < end: forward shift `[last,end) → [first,…)`.
- Leaf. Callers: resize shrink (`0045c4b0`) and `FUN_00466df0` (W36-P pair).
- Reject scaffold `Named_CalleeOf_*anmTrackMaster*0045cce0`.

## Pseudocode (annotated)

```c
// stack: (vec*, out_it*, first, last); RET 0x10; returns out_it*
Pod28** StdVector_EraseRange_Pod28(
    StdVectorPod28* vec,
    Pod28** out_it,
    Pod28* first,
    Pod28* last)
{
  if (first != last) {
    Pod28* end = vec->end;           // +8
    Pod28* dest = first;
    while (last != end) {
      // copy 7 dwords: *dest = *last; advance both by 0x1c
      *dest++ = *last++;
    }
    vec->end = dest;
  }
  *out_it = first;
  return out_it;
}
```

## Related (not owned)

| VA | Role |
|---|---|
| `0x0045c4b0` | `StdVector_Resize_Pod28` shrink caller (W35-M) |
| `0x0045cd30` | `StdVector_InsertN_Pod28` next symbol (W34-P) |
| `0x00466df0` | other erase parent (W36-P OWN) |
