# Review B (skeptical / adversarial): `aa_0053b2b0` CNDHash_RemoveAll_009cefd4

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b2b0` |
| **VA** | `0x0053b2b0` |
| **Canonical name** | `CNDHash_RemoveAll_009cefd4` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053b2b0_CNDHash_RemoveAll_009cefd4.md` |
| **Live tools** | batch decompile + family compare |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Owning clear (delete values) | Value zero only; freelist nodes | **Falsified** |
| 2 | Same stamp as mission RemoveAll | `009cefd4` ≠ `009cf024` | **Falsified** merge |
| 3 | Exclusive mask loop | `u <= mask` | **Falsified** |

---

## 2. Surviving contract

```
RemoveAll_009cefd4 ≡ RemoveAll family with node vtbl stamp 009cefd4.
Pairs with insert 0053c560 / remove 00538c80 continent family.
```

**Verdict:** **accept-with-gaps.** Accept A.
