# Review B (skeptical / adversarial): `aa_007ca4e0` Inv_tLootTable

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ca4e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007ca4e0_Inv_tLootTable.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Runtime inventory UI only | Falsified — data loader |
| 2 | Single-item equip path | Falsified — table load |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Table schema | High | Wrong loot drops |
| Load failure handling | Medium | Empty loot |

---

## 3. Cross-check against raw

```
Inv_tLootTable:
  load //tLootTable/row via DBReader cascade
Residual COM/FUN_*. Clean CF shape ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Loot table bring-up for AutoCore drop generation.
```

---

## 5. Open questions

1. Document row fields against inventory catalog.

**Verdict:** **accept-with-gaps**
