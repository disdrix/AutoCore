# Review B (skeptical / adversarial): `aa_0053b760` CNDHash_scalar_dtor_009cfa64

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b760` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053b760_CNDHash_scalar_dtor_009cfa64.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Same ownership as `009cfa4c` scalar | **Falsified** — body uses **owning** FreeBuckets `00539090` |
| 2 | Wrapper frees values itself | **Falsified** — value free is in reclaim under FreeBuckets |
| 3 | Always `operator_delete` object | **Falsified** — `flags & 1` |
| 4 | Vector deleting | **Falsified** — bit0 only |
| 5 | Merges with FreeBuckets VA | **Falsified** — distinct wrapper |

---

## 2. Surviving contract

```
void* CNDHash_scalar_dtor_009cfa64(this, flags) {
  CNDHash_Dtor_009cfa64(this); // owning teardown
  if (flags & 1) operator_delete(this);
  return this;
}
```

**Verdict:** **accept**
