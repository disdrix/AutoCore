# Review B (skeptical / adversarial): `aa_004d4da0` CVOGSectorMap_StepCreatures

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d4da0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004d4da0_CVOGSectorMap_StepCreatures.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Steps triggers only | Falsified — creatures |
| 2 | Never deletes | Falsified — Autodeleting path |
| 3 | Uses map+0xe898 only | Falsified — list at e720 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| List bounds | High | Skip/UAF creatures |
| Timeout constant | High | Early/late despawn |
| Faction gate | Medium | Wrong autodelete |

---

## 3. Cross-check against raw

```
StepCreatures(map,dt): for creatures: maybe autodelete; FUN_004c2f40; flush.
```

---

## 4. Surviving contract for AutoCore

```
Client creature sim slice. AutoCore sector tick should preserve
  autodelete + step split.
```

---

## 5. Open questions

1. Live: foreign creature timeout behavior.

**Verdict:** **accept-with-gaps**
