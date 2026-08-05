# Review B (skeptical / adversarial): `aa_00810670` Inv_LootCredits

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810670` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00810670_Inv_LootCredits.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Spawns physical loot items | Falsified — credits path |
| 2 | Is DB tLootTable loader | Falsified — runtime/credits |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Credit amount source | High | Wrong copper awards |
| Client vs server authority | Medium | Dup/exploit risk |

---

## 3. Cross-check against raw

```
Inv_LootCredits:
  loot credit award/display path (plate loot_credits)
Formula residual. Clean CF present.
```

---

## 4. Surviving contract for AutoCore

```
Loot credit economy surface for AutoCore currency sync.
```

---

## 5. Open questions

1. Trace packet to GiveCredits handler.

**Verdict:** **accept-with-gaps**
