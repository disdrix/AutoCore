# Review B (skeptical / adversarial): `aa_0040fb90` StdList_AllocEmptySentinel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040fb90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040fb90_StdList_AllocEmptySentinel_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Returns void | Callers `x = FUN_0040fb90()` | **Falsified** void — EAX = node |
| 2 | Constructs full `std::list` object | No size/allocator stores | **Survives** as sentinel-only |
| 3 | Domain = missions only | Broad xref surface | **Falsified** |
| 4 | Null `operator_new` still links | Guards on non-null before stores | **Survives** partial |
| 5 | Node size 0x10 | `new(0xc)` | **Falsified** 0x10 |

---

## 2. Live ≡ raw

force_decompile ≡ scaffold. SEH present.

---

## 3. Surviving contract

```
// → EAX = 0xc sentinel, next=prev=self (if alloc ok)
```

**Verdict:** **accept-with-gaps**.
