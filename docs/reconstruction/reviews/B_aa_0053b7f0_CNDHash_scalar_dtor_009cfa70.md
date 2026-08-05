# Review B (skeptical / adversarial): `aa_0053b7f0` CNDHash_scalar_dtor_009cfa70

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b7f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053b7f0_CNDHash_scalar_dtor_009cfa70.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Owning like `009cfa64` scalar | **Falsified** — body FreeBuckets is non-owning `0053b880` |
| 2 | Always heap-frees object | **Falsified** — `flags & 1` |
| 3 | Frees values in this wrapper | **Falsified** — no reclaim here; body does not delete values |
| 4 | Vector deleting | **Falsified** — bit0 only |
| 5 | Same VA as FreeBuckets | **Falsified** — distinct `0053b7f0` vs `0053b880` |

---

## 2. Surviving contract

```
void* CNDHash_scalar_dtor_009cfa70(this, flags) {
  CNDHash_Dtor_009cfa70(this); // non-owning FreeBuckets + slabs
  if (flags & 1) operator_delete(this);
  return this;
}
// Values: external lifetime — do not assume dtor frees payloads
```

**Verdict:** **accept**
