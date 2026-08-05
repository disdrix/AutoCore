# Review B (skeptical / adversarial): `aa_005afbc0` CVOGMap_SetVariable

| Field | Value |
|---|---|
| **Stable ID** | `aa_005afbc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005afbc0_CVOGMap_SetVariable.md` |
| **Verdict** | **accept-with-gaps** on CF; notify residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Creates on miss | **Falsified — silent return** |
| 2 | No listeners | **Falsified — +0x58 range** |
| 3 | Lookup-only no write | **Falsified — stores +0x48** |
| 4 | Finished notify ABI | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Write +0x48 | High | Var not updated |
| Listener fan-out | High | Missed reaction hooks |
| No create-on-miss | High | Assume auto-create fails |
| FUN_004cd3b0 | Tentative | UI/sync miss |

---

## 3. Cross-check against raw

```
hash find; if hit: +0x48=val; optional log; FUN_004cd3b0; for listeners Resolve+vtbl+0x13c.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
SetVariable(map, id, value, ctx):
  update existing only; fan-out listeners
  RecvGroupReactionCall variable path uses this
  AutoCore: mission/logic vars must pre-exist in map data
  pair LookupVariable
```

---

## 5. Open questions

1. Name FUN_004cd3b0 and vtbl+0x13c.
2. Confirm no insert path elsewhere.

**Verdict:** **accept-with-gaps** on CF; notify residual
