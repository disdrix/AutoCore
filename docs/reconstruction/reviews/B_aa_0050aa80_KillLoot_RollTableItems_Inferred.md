# Review B (skeptical / adversarial): `aa_0050aa80` KillLoot_RollTableItems_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050aa80` |
| **VA** | `0x0050aa80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0050aa80_KillLoot_RollTableItems_Inferred.md` |
| **System** | missions-progression / combat death loot |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Same algorithm as `00509010` | Different: table iterator + list out vs global hash walk | **Falsified** as alias |
| 2 | Chance uses `1/65536` unit float | Uses **integer** `u16 % 10000` vs short threshold | **Falsified** |
| 3 | Always inserts every GiveItem | Race + quality band can destroy without insert | **Falsified** |
| 4 | Return 0 means no items | 0 only on empty wrap; 1 on iterator complete even if zero inserts | **Survives** |
| 5 | `0x50` is decimal 50 item cap | Hex **0x50 = 80** level/quality clamp | **Survives as 80** |
| 6 | Zone lookup optional | Defaults lo=0 hi=80 if zone miss | **Survives** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| End-of-iter return 1 | **High** | Infinite loop port bug |
| %10000 chance | **High** | Rate off by ~6.5× if confused with 65536 |
| Race gate | **High** | Wrong-faction loot |
| List insert path | **High** | Leaked / missing items |
| Quality formula | **Probable** | Bad band filter |
| 00509c70 meaning | **Tentative** | Silent affix errors |

---

## 3. Cross-check

Live ≡ raw. Parent: `FUN_0050aa80(typeId, param_3[0x29], raceFromOwnerDef+0x532, &list)` then walks list assigning scatter TFID via `FUN_00521510`.

---

## 4. Surviving contract

```
// Roll items from table into outList; return 1 when iteration ends.
int RollTableLootItems(TableKey k, Object* ctx, RaceId race, List* out);
// Chance: (rng16 % 10000) <= row.chanceShort
// Do NOT use float unit scale here. Do NOT treat return as item count.
```

---

## 5. What would overturn

1. Proof `FUN_004e1830` is not end-iterator (would invert loop).
2. Evidence quality fields are not level-like band vs zone 0x138/0x13c.
3. Second static caller with different contract.

**Verdict:** **accept-with-gaps.**
