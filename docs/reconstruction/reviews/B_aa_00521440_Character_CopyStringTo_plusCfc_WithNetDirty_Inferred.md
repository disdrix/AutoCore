# Review B (skeptical / adversarial): `aa_00521440` Character_CopyStringTo_plusCfc_WithNetDirty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521440` |
| **VA** | `0x00521440` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00521440_Character_CopyStringTo_plusCfc_WithNetDirty_Inferred.md` |
| **Evidence** | Live decompile; sibling setters |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Change-detect skips copy when equal | **Falsified** | always loops |
| 2 | ORs `char+0x634` dirty bit | **Falsified** | not in body (siblings do) |
| 3 | Destination is not `+0xcfc` | **Falsified** | `param_1 + 0xcfc` delta |
| 4 | Uses `strncpy` with fixed N | **Falsified** | open-ended until NUL |
| 5 | Dirties vehicle net | **Falsified** | only character net chain |
| 6 | Mask is heat/combat on vehicle | **Open/misapply** | same numeric `0x20000000` as vehicle HeatMask but different NetObject |
| 7 | Field is definitely display name | **Open** | Probable only; not string-table proven |

---

## 2. Surviving contract

```
Character_CopyStringTo_plusCfc(self, src):
  strcpy(self+0xcfc, src)   // unbounded until NUL
  if charNet: NetObject_SetMaskBits(charNet, 0x20000000, 0)
```

**Verdict:** **accept-with-gaps**
