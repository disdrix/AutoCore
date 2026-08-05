# Review A (reconstruction fidelity): `aa_005fff20` PtrArray_CompactNulls_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fff20` |
| **VA** | `0x005fff20` |
| **Canonical name** | `PtrArray_CompactNulls_Inferred` (structural; product name open) |
| **Ghidra name** | `FUN_005fff20` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_005fff20_PtrArray_CompactNulls_Inferred.md` |
| **System** | container / pointer vector compact |
| **Live tools** | `batch_decompile` 0x005fff20; many `0062a*` / `006000*` callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**In-place compact** of a thin pointer array header in **EAX**:

| Off | Field |
|---|---|
| `[0]` / `+0` | `void **data` |
| `[1]` / `+4` | `int count` |

Algorithm (reverse walk):

1. `i = count - 1` … down to `0`.
2. If `data[i] == NULL`:
   - `count--`
   - Shift left: for `j = i .. count-1`: `data[j] = data[j+1]`
3. Leave capacity/storage alone (no free of holes beyond overwrite).

Removes null entries while preserving relative order of non-nulls. Customcc: object in **EAX** (not ECX thiscall).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / annotated / clean | `raw/aa_005fff20_*`, `reconstructed-exact/FUN_005fff20.cpp` |
| Function record | `functions/aa_005fff20_FUN_005fff20.md` |
| Callers | `FUN_00600080` family, `FUN_0062a3d0`… pack |
| Live | reverse index; null test; memmove-style dword shifts |

**Three-rep:** present.

---

## 3. Recovered CF

```c
// customcc: EAX = { void **data; int count; }
void PtrArray_CompactNulls(PtrArray *a)
{
  for (int i = a->count - 1; i >= 0; --i) {
    if (a->data[i] == 0) {
      a->count--;
      for (int j = i; j < a->count; ++j)
        a->data[j] = a->data[j + 1];
    }
  }
}
```

---

## 4. Confidence

| Claim | Level |
|---|---|
| Header is `{data*, count}` | **High** |
| Null slots removed; order of survivors kept | **Confirmed** |
| Reverse scan | **Confirmed** |
| No allocator calls | **Confirmed** |
| EAX customcc | **High** (decompiler `in_EAX`) |
| Product name | **Tentative** |

---

## 5. Gaps

1. Exact product type / capacity field if any beyond this unit.
2. Whether concurrent callers assume stable indices after compact.
3. Runtime open.

**Verdict:** **accept-with-gaps**
