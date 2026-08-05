# Review B (skeptical / adversarial): `aa_00419140` Vehicle_SetCurrentShield

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419140` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00419140_Vehicle_SetCurrentShield.md` |
| **Verdict** | **accept** on CF; caller mask contract documented |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Dirtiest mask itself | Falsified — no SetMaskBits |
| 2 | Unclamped store | Falsified — clamp CF |
| 3 | Also sets HP | Falsified — shield only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x144/+0x148 layout | High | Wrong shield pool |
| Caller must dirty mask | High | Client desync |
| Clamp edges | High | Negatives / overcap |

---

## 3. Cross-check against raw

```
n = clamp(nNew, 0, MaxShield); CurrentShield = n.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
SetCurrentShield(veh, n):
  shield current only; caller diries 0x04000000
  AutoCore shield combat
```

---

## 5. Open questions

1. Audit callers for mask dirty.
2. Unit test clamp edges.

**Verdict:** **accept** on CF; caller mask contract documented
