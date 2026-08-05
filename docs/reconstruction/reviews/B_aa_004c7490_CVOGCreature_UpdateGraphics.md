# Review B (skeptical / adversarial): `aa_004c7490` CVOGCreature_UpdateGraphics

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c7490` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004c7490_CVOGCreature_UpdateGraphics.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Server sim authority | Falsified — client graphics |
| 2 | Awards XP | Falsified — graphics |
| 3 | Serializes 0x2012 packet | Falsified — UpdateGraphics |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Call timing vs create | Medium | Missing model |
| Helper identities | Medium | Incomplete port |

---

## 3. Cross-check against raw

```
CVOGCreature_UpdateGraphics:
  visual refresh cascade via FUN_004e87* family
Client-only. Residual names.
```

---

## 4. Surviving contract for AutoCore

```
Creature visual update; low priority for AutoCore server unless client.
```

---

## 5. Open questions

1. Defer unless client graphics parity needed.

**Verdict:** **accept-with-gaps**
