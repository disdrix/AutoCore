# Annotated low-level: FUN_006cac60 → LinkPair_QuickSort_DualKey_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_006cac60` |
| VA | `0x006cac60` |
| System | phys / bind link-pair dual-key quicksort |
| Date | 2026-07-29 (W29-Q OWN-ONLY dual) |
| Body | `0x006cac60`–`0x006cad2f` exclusive (**207** B) |
| ABI | `__cdecl`; `(array, lo, hi, unused)`; void; plain `ret` |

## Machine-level notes

- Source: raw capture + live Ghidra decompile/read_memory (no `disassemble_bytes`).
- 16-byte stack alignment prologue (`and esp, 0xfffffff0`).
- Self-recursive left partition; right via outer-loop tail (MSVC-style qsort).
- 4th arg unused (propagated from CanonAndSort `count & 0xffffff00`).
- Pair stride 8; compare keys at object `+4` unsigned (both pair members).

## Pseudocode (annotated)

```c
// __cdecl
void LinkPair_QuickSort_DualKey(LinkPair8* array, int lo, int hi, uint32_t unused)
{
    (void)unused;
    for (;;) {
        int mid = (lo + hi) >> 1;
        void* pivotA = array[mid].a;
        void* pivotB = array[mid].b;
        int i = lo, j = hi;
        do {
            uint32_t pA = Key4(pivotA), pB = Key4(pivotB);
            while (Less(array[i], pA, pB)) ++i;   // (a+4, b+4) < pivot
            while (Less_rev(array[j], pA, pB)) --j; // pivot < (a+4, b+4)
            if (j < i) break;
            if (j != i) SwapPair(array[i], array[j]);
            --j; ++i;
        } while (i <= j);
        if (lo < j)
            LinkPair_QuickSort_DualKey(array, lo, j, unused);
        lo = i;
        if (hi <= i)
            return;
        // else continue with [i, hi]
    }
}
```

## Call graph

| Direction | Symbol |
|---|---|
| Callee | self (left recurse) |
| Callers | `FUN_006cad30` LinkPair_CanonAndSort_Inferred; self |

## Seal confidence

| Claim | Level |
|---|---|
| CF + cdecl ABI | High |
| Dual-key unsigned @+4 | High |
| Stride 8 full-pair swap | High |
| param_4 unused | High |
| Product pointee type | Open |
