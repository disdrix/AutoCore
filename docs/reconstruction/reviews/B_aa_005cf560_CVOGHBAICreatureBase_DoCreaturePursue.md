# Review B (skeptical / adversarial): `aa_005cf560` CVOGHBAICreatureBase_DoCreaturePursue

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cf560` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005cf560_CVOGHBAICreatureBase_DoCreaturePursue.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Player drive control | Falsified — creature HBAI |
| 2 | Loot generator | Falsified — pursue AI |
| 3 | Always attacks | Falsified — pursue movement path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Owner/target slots | High | Wrong chase target |
| Distance gate +0x124 | High | Stuck / overshoot |
| Float residual | Medium | Nav jitter |

---

## 3. Cross-check against raw

```
DoCreaturePursue(ai): resolve target; distance vs +0x124; chase helpers.
Clean ≡ raw CF; residual float locals.
```

---

## 4. Surviving contract for AutoCore

```
NPC pursue stage for combat AI. AutoCore NPC drive should preserve
  range/target vtbl use.
```

---

## 5. Open questions

1. Pair with DoCreatureAttack / engage states if present.

**Verdict:** **accept-with-gaps**
