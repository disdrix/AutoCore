# Review B (skeptical / adversarial): `aa_00825520` QuickBar_UpdateSkillSlotCooldownGauge

| Field | Value |
|---|---|
| **Stable ID** | `aa_00825520` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00825520_QuickBar_UpdateSkillSlotCooldownGauge.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Arms category CD | Falsified — UI read |
| 2 | Always category path | Falsified — +0x628 branch |
| 3 | Item QB gauge only | Falsified — skill slot |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual CD sources | High | Wrong gauge |
| +0x550 bind | High | Null gauge |
| Fill formula | Tentative | Visual wrong |

---

## 3. Cross-check against raw

```
if gates && skill: if casting fields else GetCategoryCooldownRemaining; set gauge.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
UpdateSkillSlotCooldownGauge(button):
  QB skill CD UI; pair GetCategoryCooldownRemaining + SetIsCastingFlag
  AutoCore client quickbar
```

---

## 5. Open questions

1. Seal gauge math.
2. Name DAT_00d1b6d8.

**Verdict:** **accept-with-gaps**
