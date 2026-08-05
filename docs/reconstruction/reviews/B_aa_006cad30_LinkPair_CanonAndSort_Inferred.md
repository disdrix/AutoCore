# Review B (skeptical / adversarial): `aa_006cad30` LinkPair_CanonAndSort_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cad30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W28-Q) |
| **Counterpart** | `reviews/A_aa_006cad30_LinkPair_CanonAndSort_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + function metadata (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is the sorted dual-range **merge** (`006caaa0`) | **Falsified** — this only canon+sort; merge is sibling |
| 2 | Sorts single pointers (not pairs) | **Falsified** — stride **8**, dual pointers |
| 3 | Compare uses object identity / raw pointer | **Falsified** — compares `*(uint*)(p+4)` |
| 4 | thiscall / ret N | **Falsified** — **cdecl**, plain `ret` |
| 5 | Always calls qsort | **Falsified** — only if original count **> 1** |
| 6 | `param_2 & 0xffffff00` is a sort mode flag consumed by qsort | **Weakened** — `FUN_006cac60` does not use 4th arg in decompile; low-byte clear is dead/unused arg |
| 7 | Legacy VOG_DEBUG name is product | **Narrow** — scaffold only |
| 8 | Single-call site | **Falsified** — **6** xrefs / 4 callers; dual invoke in commit |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Canon then sort CF | **High** | unsorted merge → wrong bind delta |
| Key @ object+4 unsigned | **High** | order inversion |
| cdecl ABI | **High** | stack corruption |
| Pipeline role (pre-merge) | **High** | skip sort → 006caaa0 incorrect |
| Product type | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
if count==0 return
for i in 0..count-1:
  if b.key4 < a.key4: swap(a,b)
if count > 1: qsort_pairs(array, 0, count-1)
ret
```

Clean must **not** invent signed key compares, 4-byte stride, or merge semantics.

---

## 4. Surviving contract for AutoCore

```csharp
// Prepare pair lists before sorted dual-range walk / storage commit
void CanonAndSort(Span<(Obj a, Obj b)> pairs)
{
    for (int i = 0; i < pairs.Length; i++)
        if (pairs[i].b.Key4 < pairs[i].a.Key4)
            (pairs[i].a, pairs[i].b) = (pairs[i].b, pairs[i].a);
    if (pairs.Length > 1)
        QuickSortPairsByDualKey4(pairs);
}
```

Bind/unbind ports must run this (or equivalent) on **both** side lists before `LinkPair_SortedDiffWalk`.

---

## 5. Open questions

1. Exact object type / meaning of field +4.  
2. Whether equal keys within a pair are stable under swap (no swap when equal — sealed).  
3. Full dual of `FUN_006cac60`.

**Verdict:** **accept**
