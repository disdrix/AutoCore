# Review B (skeptical / adversarial): `aa_007e7940` Inv_dcArmor_Open

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e7940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007e7940_Inv_dcArmor_Open.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Runtime equip armor on vehicle | Falsified — DB open |
| 2 | Loot roll | Falsified — table load |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Column mapping | High | Wrong armor stats |
| Damage sub-table link | Medium | Missing resist |

---

## 3. Cross-check against raw

```
dcArmor_Open: DBReader armor rows + dcDamage insert.
```

---

## 4. Surviving contract for AutoCore

```
Armor definition load for clonebase. AutoCore DB import path.
```

---

## 5. Open questions

1. Sample armor CBID column dump.

**Verdict:** **accept-with-gaps**
