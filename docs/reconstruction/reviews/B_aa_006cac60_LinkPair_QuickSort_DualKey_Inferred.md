# Review B (skeptical / adversarial): `aa_006cac60` LinkPair_QuickSort_DualKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cac60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W29-Q) |
| **Counterpart** | `reviews/A_aa_006cac60_LinkPair_QuickSort_DualKey_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + function metadata (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is the canon step (per-pair swap) | **Falsified** — canon is parent `006cad30`; this only partitions/sorts |
| 2 | Sorts single pointers (4-byte stride) | **Falsified** — stride **8**, swaps both dwords |
| 3 | Compare uses raw pointer identity | **Falsified** — compares `*(uint*)(obj+4)` on both members |
| 4 | thiscall / ret N | **Falsified** — **cdecl**, plain `ret`; call sites `add esp,0x10` |
| 5 | Recurses both sides always | **Weakened** — left recurses when `lo < j`; right via **outer-loop tail** (no second recursive call) |
| 6 | 4th arg is a sort mode / depth limit | **Falsified** — decompile never reads `param_4`; dead pass-through |
| 7 | Stable sort | **Not claimed** — classic qsort; equal dual-keys may reorder |
| 8 | Legacy VOG_DEBUG name is product | **Narrow** — scaffold only |
| 9 | Multi-entry shared library sort | **Falsified** — only CanonAndSort + self (2 xrefs) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual-key partition CF | **High** | unsorted merge → wrong bind delta |
| Key @ object+4 unsigned | **High** | order inversion |
| cdecl 4-arg ABI | **High** | stack corruption |
| param_4 unused | **High** | inventing phantom mode flag |
| Product type | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
loop:
  mid = (lo+hi)>>1
  pivot = (array[mid].a, array[mid].b)
  i=lo, j=hi
  partition on (Key4(a), Key4(b)) unsigned lexicographic
  swap full 8-byte pairs
  if lo < j: recurse(array, lo, j, unused)
  lo = i
  if hi <= i: return
  // else continue [i, hi]
```

Clean must **not** invent single-key-only compare, 4-byte element stride, or consume 4th arg as a flag.

---

## 4. Surviving contract for AutoCore

```csharp
// Dual-key quicksort of link pairs (post-canon). Keys are unsigned dword at obj+4.
void QuickSortPairs(Span<LinkPair8> a, int lo, int hi)
{
    // mid pivot; partition; left recurse; right via loop
    // Must match lexicographic (a.Key4, b.Key4) order used by SortedDiffWalk.
}
```

Bind/unbind ports must sort with the **same dual-key** as the merge walk (`006caaa0`); single-key sort will mis-align equal primary keys.

---

## 5. Open questions

1. Exact object type / meaning of field +4.  
2. Whether equal dual-key pairs need stable order (not required by bytes).  
3. Why parent clears low byte of unused arg (compiler artifact).

**Verdict:** **accept**
