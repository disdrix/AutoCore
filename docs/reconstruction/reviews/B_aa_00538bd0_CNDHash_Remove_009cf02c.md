# Review B (skeptical / adversarial): `aa_00538bd0` CNDHash_Remove_009cf02c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538bd0` |
| **VA** | `0x00538bd0` |
| **Canonical name** | `CNDHash_Remove_009cf02c` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path B |
| **Counterpart** | `reviews/A_aa_00538bd0_CNDHash_Remove_009cf02c.md` |
| **Live tools** | Independent `force_decompile` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Distinct algorithm from `00538b20` | **Falsified** — same CF; only vtbl constant differs |
| 2 | Removes and frees value | **Falsified** — no delete; out transfers ownership |
| 3 | Lock aborts | **Falsified** |
| 4 | `004e2ca0` is Lookup | **Falsified** — unlinks |
| 5 | CompleteObjective uses optional out null | **Open** site-level residual |

---

## 2. Surviving contract

Same as `CNDHash_Remove` sealed dual at `0x00538b20` with vtbl `009cf02c`.

**Verdict:** **accept-with-gaps.** Accept A.
