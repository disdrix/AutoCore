# Review A (reconstruction fidelity): `aa_005b3300` HBBuffer_GrowRealloc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3300` |
| **VA** | `0x005b3300` |
| **Canonical name** | `HBBuffer_GrowRealloc_Inferred` (structural; product name open) |
| **Ghidra name** | `FUN_005b3300` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_005b3300_HBBuffer_GrowRealloc_Inferred.md` |
| **System** | heartbeat / generic growable buffer (CVOGHBList + many) |
| **Live tools** | `batch_decompile` 0x005b3300; callers include `CVOGHBList_ctor` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Realloc / grow** a 3-dword buffer header held in **EBX** (decompiler `unaff_EBX`):

| Off (dwords) | Role |
|---|---|
| `[0]` | data pointer |
| `[1]` | live element count (or used size in elems) |
| `[2]` | capacity (may have high bit `0x80000000` as “uninitialized/sentinel”) |

Body:

1. `newData = (*DAT_00b05060 + 0x10)(param_2 * param_3, 0x12)` — allocator vcall; size = **newCap × stride**, tag **`0x12`**.
2. `FUN_006380a0(newData, oldData, oldCount * param_3)` — copy **oldCount × stride** bytes.
3. If `(int)oldCap >= 0` → free old: `(*DAT_00b05060 + 0x14)(oldData, (oldCap & 0x7fffffff) * param_3, 0x12)`.
4. `data = newData`; `cap = param_2` (new capacity in elements).

**Registers (live / decompiler):**

- **EBX** = buffer triple*
- **param_2** = new capacity (elements)
- **param_3** = element stride (bytes)
- **param_1** unused / clobbered in decompiler (ignore for CF)

Primary known parent: `CVOGHBList_ctor` grows active (≥1000) and pending (≥100) lists. Also many other callers (graphics/HB/tick helpers).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / annotated / clean | `raw/aa_005b3300_*`, `reconstructed-exact/FUN_005b3300.cpp` |
| Function record | `functions/aa_005b3300_FUN_005b3300.md` |
| Parent dual | `A_aa_00507d10_CVOGHBList_ctor` |
| Live | allocator tag `0x12`; free gated on `cap >= 0` |

**Three-rep:** present. Clean ≡ raw ≡ live CF (register EBX is real; naming open).

---

## 3. Recovered CF

```c
// customcc: EBX = Buf{void* data; int count; int cap}
// stack/reg: newCap, stride
void GrowRealloc(Buf *b, int newCap, int stride)
{
  void *n = Alloc(newCap * stride, 0x12);      // vcall +0x10
  MemCopy(n, b->data, b->count * stride);      // FUN_006380a0
  if ((int)b->cap >= 0)
    Free(b->data, (b->cap & 0x7fffffff) * stride, 0x12); // vcall +0x14
  b->data = n;
  b->cap  = newCap;
}
```

---

## 4. Confidence

| Claim | Level |
|---|---|
| Triple layout data/count/cap | **High** |
| Alloc size = newCap × stride | **Confirmed** |
| Copy size = count × stride | **Confirmed** |
| Free skipped when cap signed-negative (sentinel) | **Confirmed** |
| Cap high-bit stripped on free size | **Confirmed** (`& 0x7fffffff`) |
| Allocator global `DAT_00b05060` | **High** |
| Product name / exact Buf type | **Tentative** |
| `param_1` semantics | **Open** (unused in body) |

---

## 5. Gaps

1. Identity of `DAT_00b05060` heap interface.
2. Full calling convention (EBX fixed; other args reg vs stack).
3. Whether count is updated here (no — only data+cap).

**Verdict:** **accept-with-gaps**
