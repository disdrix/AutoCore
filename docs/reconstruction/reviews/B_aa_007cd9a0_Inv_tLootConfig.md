# Review B (skeptical / adversarial): `aa_007cd9a0` Inv_tLootConfig

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cd9a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007cd9a0_Inv_tLootConfig.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is tLootTable | Falsified — config sibling |
| 2 | Generates items at runtime | Falsified — load only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Config field meanings | Medium | Wrong loot mode |

---

## 3. Cross-check against raw

```
Inv_tLootConfig: load //tLootConfig/row
Sibling data bring-up. Residual COM.
```

---

## 4. Surviving contract for AutoCore

```
Loot generation config table for AutoCore.
```

---

## 5. Open questions

1. Cross-ref Inv_ConvoyLootMode and generators.

**Verdict:** **accept-with-gaps**
