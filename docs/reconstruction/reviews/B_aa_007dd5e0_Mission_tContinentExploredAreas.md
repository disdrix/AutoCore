# Review B (skeptical / adversarial): `aa_007dd5e0` Mission_tContinentExploredAreas

| Field | Value |
|---|---|
| **Stable ID** | `aa_007dd5e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007dd5e0_Mission_tContinentExploredAreas.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | TGA map geometry loader | Falsified — metadata table only |
| 2 | Runtime SetAreaExploredBit | Falsified — data load |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| intXPLevel mapping | High | Wrong area XP |
| Continent/area keys | High | Missed first-visit |

---

## 3. Cross-check against raw

```
Mission_tContinentExploredAreas:
  load //tContinentExploredAreas/row metadata
Not geometry. Residual COM.
```

---

## 4. Surviving contract for AutoCore

```
Area explore XP metadata bring-up.
```

---

## 5. Open questions

1. Cross-check AutoCore DB import schema.

**Verdict:** **accept-with-gaps**
