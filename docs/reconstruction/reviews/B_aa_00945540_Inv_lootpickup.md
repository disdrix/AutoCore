# Review B (skeptical / adversarial): `aa_00945540` Inv_lootpickup

| Field | Value |
|---|---|
| **Stable ID** | `aa_00945540` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00945540_Inv_lootpickup.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Generates new random loot | Falsified — pickup existing |
| 2 | DB loader | Falsified — runtime |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pickup authority rules | High | Dup/steal loot |
| Inventory full handling | Medium | Lost loot |

---

## 3. Cross-check against raw

```
Inv_lootpickup:
  world/corpse loot → inventory transfer path
Residual helpers. Clean CF present.
```

---

## 4. Surviving contract for AutoCore

```
Loot pickup for AutoCore sector inventory commands.
```

---

## 5. Open questions

1. Map to sector loot packet handlers.

**Verdict:** **accept-with-gaps**
