# Review B (skeptical / adversarial): `aa_00538d50` CNDHash_Remove_009cefdc

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538d50` |
| **VA** | `0x00538d50` |
| **Canonical name** | `CNDHash_Remove_009cefdc` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path B |
| **Counterpart** | `reviews/A_aa_00538d50_CNDHash_Remove_009cefdc.md` |
| **Live tools** | Independent `force_decompile` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Distinct CF from `00538bd0` | **Falsified** — only vtbl differs |
| 2 | Frees value | **Falsified** — no delete |
| 3 | Lock aborts | **Falsified** |

**Verdict:** **accept-with-gaps.** Accept A.
