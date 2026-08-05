# Review B (skeptical / adversarial): `aa_004fb600` Vehicle_GetShieldRegenRate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fb600` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004fb600_Vehicle_GetShieldRegenRate.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same field as HP regen | Falsified — +0x4B6 ≠ +0x3FA |
| 2 | Applies debounce here | Falsified — pure read |
| 3 | Defaults to plant rate | Falsified — race-item only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x4B6 shield field | High | Wrong shield regen |
| Shared walk with HP getter | High | Layout drift breaks both |
| Null → 0 | High | Phantom shield regen |

---

## 3. Cross-check against raw

```
identical walk to GetHpRegenRate; return (i16)sub+0x4B6 or 0.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
GetShieldRegenRate(veh) → i16 race shield regen or 0:
  pure getter; OnTick applies after empty-shield debounce
  AutoCore vehicle shield regen pulse
```

---

## 5. Open questions

1. Pair unit test with GetHpRegenRate walk.
2. Confirm short signedness vs UI.

**Verdict:** **accept**
