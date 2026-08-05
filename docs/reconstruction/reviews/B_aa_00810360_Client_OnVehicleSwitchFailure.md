# Review B (skeptical / adversarial): `Client_OnVehicleSwitchFailure` @ `0x00810360`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810360` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00810360_Client_OnVehicleSwitchFailure.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Switches chassis on failure path | Falsified — failure UX |
| 2 | Only one failure reason | Weak — multi-string plate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Chassis switch fail UX | High | Silent fail |
| Inventory fit messaging | High | Wrong player action |

---

## 3. Cross-check against raw

```
OnVehicleSwitchFailure: reason→toast (not found / fit).
```

---

## 4. Surviving contract for AutoCore

```
OnVehicleSwitchFailure: client vehicle switch errors.
```

---

## 5. Open questions

1. Wire to vehicle switch C2S response codes.

**Verdict:** **accept-with-gaps**
