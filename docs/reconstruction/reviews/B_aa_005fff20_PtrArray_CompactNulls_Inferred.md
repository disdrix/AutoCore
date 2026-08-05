# Review B (skeptical / adversarial): `aa_005fff20` PtrArray_CompactNulls_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fff20` |
| **VA** | `0x005fff20` |
| **Canonical name** | `PtrArray_CompactNulls_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005fff20_PtrArray_CompactNulls_Inferred.md` |
| **Live tools** | batch decompile |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Frees null-slot storage | No free/delete; only shifts | **Falsified** |
| 2 | Forward scan only | Loop decrements from count-1 | **Falsified** |
| 3 | Drops non-null entries | Only acts when `data[i]==0` | **Falsified** |
| 4 | ECX thiscall | `in_EAX` object | **Falsified** thiscall assumption |
| 5 | Shrinks capacity | Only decrements count | **Falsified** |

---

## 2. Surviving contract

```
CompactNulls(a={data,count}):
  for i = count-1 .. 0:
    if data[i]==0:
      count--; shift data[i..count) left by 1
```

**Verdict:** **accept-with-gaps.** Accept A.
