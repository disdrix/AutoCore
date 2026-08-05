# Review B (skeptical / adversarial): `aa_004d6c80` CVOGSectorMap_StepTo

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d6c80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004d6c80_CVOGSectorMap_StepTo.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only physics PostPhysX | Falsified — creature/trigger orchestrator |
| 2 | Single fixed 1 step always | Falsified — multi-substep |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Substep formula | High | Sim rate wrong |
| +0x7d mode | High | Wrong branch |

---

## 3. Cross-check against raw

```
StepTo(map,dt): pre; substep creatures; StepTriggers (or alt).
```

---

## 4. Surviving contract for AutoCore

```
Primary sector tick driver. AutoCore should call creature then trigger
  in same order.
```

---

## 5. Open questions

1. Diff substep count vs server tick policy.

**Verdict:** **accept-with-gaps**
