# Review B (skeptical / adversarial): `aa_004d3980` CVOGSectorMap_StepTriggers

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d3980` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004d3980_CVOGSectorMap_StepTriggers.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Creature AI step | Falsified — triggers |
| 2 | Ignores +0x58 | Falsified — gate present |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Active flag | High | Dead triggers |
| Iterator stability | Medium | Miss/double fire |

---

## 3. Cross-check against raw

```
StepTriggers: iterate active triggers; vtbl+0x50; post process.
```

---

## 4. Surviving contract for AutoCore

```
Client trigger pulse during sector step.
```

---

## 5. Open questions

1. Cross-check Documentation/TRIGGER_SYSTEM.md.

**Verdict:** **accept-with-gaps**
