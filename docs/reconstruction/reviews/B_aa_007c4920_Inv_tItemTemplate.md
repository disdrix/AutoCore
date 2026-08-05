# Review B (skeptical / adversarial): `aa_007c4920` Inv_tItemTemplate

| Field | Value |
|---|---|
| **Stable ID** | `aa_007c4920` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007c4920_Inv_tItemTemplate.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | UI inventory texture path only | Falsified — template table |
| 2 | Is tLootTable | Falsified — item templates |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Template schema | High | Wrong item stats |
| ID key collisions with CBID | Medium | Lookup bugs |

---

## 3. Cross-check against raw

```
Inv_tItemTemplate: load //tItemTemplate/row
Residual COM. Large schema open.
```

---

## 4. Surviving contract for AutoCore

```
Item template bring-up for AutoCore inventory/loot.
```

---

## 5. Open questions

1. Diff against inventory-catalog JSON fields.

**Verdict:** **accept-with-gaps**
