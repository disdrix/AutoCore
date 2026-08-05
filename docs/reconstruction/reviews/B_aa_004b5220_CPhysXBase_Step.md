# Review B (skeptical / adversarial): `aa_004b5220` CPhysXBase_Step

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b5220` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004b5220_CPhysXBase_Step.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Unlimited re-entry every call | Falsified — this[2] gate |
| 2 | Variable dt from param | Falsified — constant |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| One-shot flag | High | Never steps / steps once |
| dt constant | Medium | Sim rate wrong |

---

## 3. Cross-check against raw

```
CPhysXBase::Step: if *this && !flag: scene step(1/30, mode); flag=1.
```

---

## 4. Surviving contract for AutoCore

```
PhysX scene step wrapper for client CPhysXBase.
```

---

## 5. Open questions

1. Who clears this[2] to allow next step.

**Verdict:** **accept-with-gaps**
