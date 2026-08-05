# Review B (skeptical / adversarial): `aa_00538e00` CNDHash_Destroy_via_00537f30

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538e00` |
| **VA** | `0x00538e00` |
| **Canonical name** | `CNDHash_Destroy` (via `00537f30`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path B |
| **Counterpart** | `reviews/A_aa_00538e00_CNDHash_Destroy_via_00537f30.md` |
| **Live tools** | Independent `force_decompile` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Destroy is just remove | **Falsified** — deletes out value on success |
| 2 | `operator_delete` never returns (Ghidra) | **Falsified** — standard CRT free returns |
| 3 | Miss still deletes | **Falsified** — `0x80004005` < 0 skips delete |
| 4 | Lock aborts destroy | **Falsified** |
| 5 | Param is value not key | **Falsified** — passed as remove key; slot becomes value |

**Verdict:** **accept-with-gaps.** Accept A.
