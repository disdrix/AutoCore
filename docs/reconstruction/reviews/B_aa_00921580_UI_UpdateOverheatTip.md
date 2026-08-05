# Review B (skeptical / adversarial): `aa_00921580` UI_UpdateOverheatTip

| Field | Value |
|---|---|
| **Stable ID** | `aa_00921580` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00921580_UI_UpdateOverheatTip.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Writes heat | Falsified — UI only |
| 2 | Uses weapon-local heat field only | Falsified — vehicle pools |
| 3 | Blocks fire | Falsified — tip only; fire gate elsewhere |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x150/+0x244 | High | Wrong overheat UI |
| Floater vs first-time tip split | Medium | Spam tips |

---

## 3. Cross-check against raw

```
UpdateOverheatTip(dt): if vehicle heat vs max → tip/floater/LED.
Clean ≡ raw; residual half-max glue.
```

---

## 4. Surviving contract for AutoCore

```
Client overheat presentation; mirrors CanFire heat fields.
```

---

## 5. Open questions

1. A/B live: heat>=max shows Weapons Overheated!.

**Verdict:** **accept-with-gaps**
