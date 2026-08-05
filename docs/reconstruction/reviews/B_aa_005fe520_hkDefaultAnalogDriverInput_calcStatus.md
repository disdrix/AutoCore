# Review B (skeptical / adversarial): `aa_005fe520` hkDefaultAnalogDriverInput_calcStatus

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe520` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005fe520_hkDefaultAnalogDriverInput_calcStatus.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Writes wheel torques | Falsified — status only |
| 2 | Ignores reverse | Falsified — calls calcReverse |
| 3 | Steer from entity+0x618 directly here | Falsified — FUN_005fdf20 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pedal split brake/accel | High | No brake/accel |
| HB copy +0x24→+0x18 | High | Handbrake ignored |
| AA ownership | Medium | Dead status path |

---

## 3. Cross-check against raw

```
calcStatus: +0xc brake, +0x10 accel, +0x14 steer, +0x18 HB, +0x19 reverse.
```

---

## 4. Surviving contract for AutoCore

```
Stock hk driver status; AA VehicleAction may supply parallel axes.
```

---

## 5. Open questions

1. Diff live: does applyAction rely on this status or entity axes only.

**Verdict:** **accept-with-gaps**
