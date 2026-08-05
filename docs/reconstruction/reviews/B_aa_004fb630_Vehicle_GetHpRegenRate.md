# Review B (skeptical / adversarial): `aa_004fb630` Vehicle_GetHpRegenRate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fb630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004fb630_Vehicle_GetHpRegenRate.md` |
| **Verdict** | **accept** on CF; dual-base names residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Reads power plant | Falsified — race-item only |
| 2 | Returns 1 when null | Falsified — returns 0 (creature wrapper returns 1) |
| 3 | Writes pool state | Falsified — pure getter |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x270 / +0x3FA layout | High | Wrong HP regen on tick |
| Null → 0 contract | High | NPE or phantom regen |
| Dual-base walk detail | Medium | Wrong clonebase field |

---

## 3. Cross-check against raw

```
pRace = veh+0x270; if null return 0;
walk dual-base → clonebase+0xAC → sub+0x3C → (i16)+0x3FA.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
GetHpRegenRate(veh) → i16 race HP regen or 0:
  pure getter for combat-pool OnTick
  AutoCore vehicle HP regen pulse
```

---

## 5. Open questions

1. Confirm UI scale g_flDisplayRateScaleOneThird not applied here.
2. Xref all OnTick callers.

**Verdict:** **accept** on CF; dual-base names residual
