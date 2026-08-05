# Review B (skeptical / adversarial): `aa_004f7e10` Vehicle_EnsureRegenerationHeartbeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f7e10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004f7e10_Vehicle_EnsureRegenerationHeartbeat.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always creates new | Falsified — ensure once |
| 2 | 30 ms weapon track | Falsified — combat pool |
| 3 | Finished period seal in this body | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x27C slot | High | Double HB or none |
| Context gates | High | Regen never starts |
| Period | Tentative | Wrong tick rate |

---

## 3. Cross-check against raw

```
if slot empty and context: create combat pool HB.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
EnsureRegenerationHeartbeat(veh):
  combat pool HB ensure; pair ActivateEnterWorld / Get*RegenRate
  AutoCore regen
```

---

## 5. Open questions

1. Unify with ActivateEnterWorld period table.
2. Live regen tick interval.

**Verdict:** **accept-with-gaps**
