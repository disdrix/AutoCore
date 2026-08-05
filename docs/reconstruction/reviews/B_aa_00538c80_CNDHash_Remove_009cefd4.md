# Review B (skeptical / adversarial): `aa_00538c80` CNDHash_Remove_009cefd4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538c80` |
| **VA** | `0x00538c80` |
| **Canonical name** | `CNDHash_Remove_009cefd4` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path B |
| **Counterpart** | `reviews/A_aa_00538c80_CNDHash_Remove_009cefd4.md` |
| **Live tools** | Independent `force_decompile` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This remove frees payload | **Falsified** — value cleared before delete test |
| 2 | Algorithm unique vs other removes | **Falsified** — vtbl-only specialization |
| 3 | Lock aborts | **Falsified** |
| 4 | RelockContinentObject is only consumer | **Open** — one sealed direct caller |

**Verdict:** **accept-with-gaps.** Accept A.
