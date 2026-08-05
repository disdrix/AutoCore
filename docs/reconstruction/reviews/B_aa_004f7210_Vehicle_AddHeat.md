# Review B (skeptical / adversarial): `aa_004f7210` Vehicle_AddHeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f7210` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004f7210_Vehicle_AddHeat.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Clamp to MaxHeat only | Falsified — 2×MaxHeat |
| 2 | No network dirty | Falsified — HeatMask |
| 3 | Always sinks all heat | Falsified — conditional |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Clamp range | High | Heat overflow/underflow |
| HeatMask dirty | High | Client desync heat |
| Sink path | Tentative | Wrong divert |

---

## 3. Cross-check against raw

```
floor cool; maybe sink; CurrentHeat+=d; clamp; dirty HeatMask.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
AddHeat(veh, delta):
  heat pool mutator; pair CalcHeatMaximum / combat pool HB
  AutoCore combat heat
```

---

## 5. Open questions

1. Fix delta arg naming in clean.
2. Live heat bar vs 2× max.

**Verdict:** **accept-with-gaps**
