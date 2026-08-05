# Annotated low-level: TFID_NotEquals

| Field | Value |
|---|---|
| Stable ID | `aa_0040b150` |
| VA | `0x0040b150` |
| System | `tfid-identity` |
| Date | `2026-07-23` scaffold; dual residual `2026-07-29` |

## Machine-level notes

- Source: raw capture for `aa_0040b150` + live `read_memory` body.
- **Calling convention:** `__cdecl` — `pA = [esp+4]`, `pB = [esp+8]`, plain `ret`.
- **Compare key (ObjectId):** dword `@+0`, dword `@+4`, byte `@+8` only.
- **Polarity:** all three match → return `0`; any mismatch → return `1`.
- Equal path uses `mov eax,1` + `test` + `sete` + `mov al,cl` to yield `0` (invert).
- Unequal path uses `xor eax,eax` + same `sete` invert to yield `1`.
- Twin `TFID_EqualsObjectId` (`0x00404aa0`) same loads/cmps, direct returns without `sete`.
- **Not** full `memcmp` of 16-byte TFID — tail `+9…+15` ignored.
- Leaf: no callees, no DAT_ reads.
- Prefer body bytes if decompiler ever conflicts; currently decomp matches.

## Pseudocode (annotated copy of raw)

```c
int __cdecl TFID_NotEquals(void *pA, void *pB)
{
  // ObjectId key only — not full TFID_16
  if (((*(int *)pA == *(int *)pB)
    && (*(int *)((int)pA + 4) == *(int *)((int)pB + 4)))
    && (*(char *)((int)pA + 8) == *(char *)((int)pB + 8))) {
    return 0; // equal
  }
  return 1;   // not equal
}
```

## Port contract

```
return !(a.i32_0==b.i32_0 && a.i32_4==b.i32_4 && a.i8_8==b.i8_8)
```

## Open questions

- Product names for the three compared fields (layout sibling).
- Catalog of invalid-sentinel globals used by callers (caller-local).
