# Review B (skeptical / adversarial): `aa_005b3300` HBBuffer_GrowRealloc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3300` |
| **VA** | `0x005b3300` |
| **Canonical name** | `HBBuffer_GrowRealloc_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b3300_HBBuffer_GrowRealloc_Inferred.md` |
| **Live tools** | batch decompile; CVOGHBList_ctor parent |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always frees old buffer | Free only if `(int)cap >= 0` | **Falsified** always-free |
| 2 | Free size uses raw signed cap | Masks `0x7fffffff` | **Falsified** |
| 3 | Updates live count | Only writes data + cap | **Falsified** |
| 4 | HBList-only helper | Many non-HB callers | **Falsified** exclusive ownership |
| 5 | Stride ignored | Multiplies both alloc and copy | **Attack fails** |

---

## 2. Surviving contract

```
GrowRealloc(buf, newCap, stride):
  n = heap.alloc(newCap*stride, tag=0x12)
  copy n <- buf.data  (count*stride)
  if buf.cap >= 0: heap.free(buf.data, (cap&~sign)*stride, 0x12)
  buf.data = n; buf.cap = newCap
```

**Verdict:** **accept-with-gaps.** Accept A.
