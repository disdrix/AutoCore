# Review B (skeptical / adversarial): `aa_004da630` CVOGCombat_OnDeathAwardKillXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_004da630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004da630_CVOGCombat_OnDeathAwardKillXp.md` |
| **Verdict** | **accept-with-gaps** on award CF; **needs-more-evidence** on loot/credit tail |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always awards only killer | **Falsified — convoy multi-award path** |
| 2 | Unlimited convoy radius | **Falsified — ~300f gate** |
| 3 | No loot after XP | **Falsified — credits/loot tail** |
| 4 | Finished exact port | **Overstated — huge FUN_* tail** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Participation product | High | Wrong XP split |
| Convoy range/count | High | Missed/extra awards |
| Template XPPercent | High | Flat wrong XP |
| Loot tail | Tentative | Missing drops |

---

## 3. Cross-check against raw

```
if !killer: return;
resolve char; snapshot victim pos; kind 0xe/0x12;
build mult = XPPercent * share * ...;
solo CalculateAndAward(count=0) OR convoy loop dist<~300 count<=4;
then credits/loot if flags allow.
Clean preserves phases; many helpers FUN_*.
```

---

## 4. Surviving contract for AutoCore

```
OnDeathAwardKillXp(lootCtx, killerObj, victimObj):
  resolve killer character; compute participation mult (XPPercent × share × convoy)
  solo or in-range convoy (≤4, ~300f) → CalculateAndAwardKillXP
  then local credits/loot side effects
Do not skip convoy split when flag set. Keep XP before loot ordering.
```

---

## 5. Open questions

1. Exact damage-share source fields.
2. Full credit formula and CBID loot tables.
3. Unreachable block 0x004dad5f significance (if any).
4. Runtime convoy kill capture.

**Verdict:** **accept-with-gaps** on award CF; **needs-more-evidence** on loot/credit tail
