# Review B (skeptical / adversarial): `aa_0053b650` CNDHash_scalar_dtor_009cfa58

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b650` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053b650_CNDHash_scalar_dtor_009cfa58.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Same body dtor as `009cfa4c` | **Falsified** — calls `0053b670`, not `0053b560` |
| 2 | Always heap-frees | **Falsified** — `flags & 1` gate |
| 3 | Vector deleting | **Falsified** — bit0 only |
| 4 | Is FreeBuckets | **Falsified** — wrapper only |

---

## 2. Surviving contract

```
void* CNDHash_scalar_dtor_009cfa58(this, flags) {
  CNDHash_Dtor_009cfa58(this); // 0053b670
  if (flags & 1) operator_delete(this);
  return this;
}
```

**Verdict:** **accept**
