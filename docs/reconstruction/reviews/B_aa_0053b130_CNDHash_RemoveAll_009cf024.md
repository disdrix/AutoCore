# Review B (skeptical / adversarial): `aa_0053b130` CNDHash_RemoveAll_009cf024

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b130` |
| **VA** | `0x0053b130` |
| **Canonical name** | `CNDHash_RemoveAll` (`009cf024`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path B |
| **Counterpart** | `reviews/A_aa_0053b130_CNDHash_RemoveAll_009cf024.md` |
| **Live tools** | Independent `force_decompile` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | RemoveAll frees all values | **Falsified** — only zeros value, freelists node |
| 2 | Loop is `u < mask` | **Falsified** — `u <= mask` (mask is often 2^n-1 style power field at +8) |
| 3 | Lock aborts | **Falsified** |
| 4 | Clears freelist | **Falsified** — **fills** freelist from live nodes |
| 5 | No callers ⇒ dead code | **Open** — string xref family; may be vtbl |

Note: `+0x08` is `1<<bits` from Recreate twins — used as **inclusive** upper index; table size is mask+1 buckets. Residual: confirm table allocation length == mask+1 at ctor.

**Verdict:** **accept-with-gaps.** Accept A.
