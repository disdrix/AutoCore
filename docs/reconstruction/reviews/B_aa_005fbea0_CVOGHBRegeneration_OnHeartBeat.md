# Review B (skeptical / adversarial): `aa_005fbea0` CVOGHBRegeneration_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fbea0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005fbea0_CVOGHBRegeneration_OnHeartBeat.md` |
| **Verdict** | **accept-with-gaps** on CF; **High** no-dt + period contract |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | dt * rate continuous | **Falsified — discrete full rate per HB pulse** |
| 2 | 16ms period | **Falsified — 3s/5s ctor** |
| 3 | HP only | **Falsified — power/heat/shield** |
| 4 | Finished bit-exact rates | **Overstated — helper residual** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| No-dt pulse model | High | Double regen if wrongly *dt |
| Dirty masks | High | Client pool desync |
| Debounce ticks | Tentative | Instant shield/heat wrong |
| 3s/5s period | High | Regen spam |

---

## 3. Cross-check against raw

```
resolve vehicle;
HP+=race; power+=rate clamp dirty;
heat debounce/cool dirty; shield debounce/regen dirty;
RescheduleAfterFire.
Clean ≡ raw CF; helpers named in plate.
```

---

## 4. Surviving contract for AutoCore

```
Regeneration_OnHeartBeat:
  discrete combat-pool pulse at 3s/5s — full authored rates, NO dt
  dirty Power/Heat/Shield masks for net sync
  AutoCore VehicleCombatPool must match pulse model not frame * rate
  pair with Regeneration_ctor period by race
```

---

## 5. Open questions

1. Dual A/B Regeneration_ctor if still missing (period map).
2. Cross-check VehicleCombatPool.cs constants.
3. Live heat/shield debounce timing.

**Verdict:** **accept-with-gaps** on CF; **High** no-dt + period contract
