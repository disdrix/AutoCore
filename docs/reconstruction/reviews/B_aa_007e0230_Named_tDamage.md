# Review B (skeptical / adversarial): `aa_007e0230` Named_tDamage

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e0230` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007e0230_Named_tDamage.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Applies HP damage to vehicle | Falsified — table load |
| 2 | Loot generate | Falsified — damage defs |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Row layout | High | Wrong damage types |
| Fail HRESULT | Medium | Silent empty table |

---

## 3. Cross-check against raw

```
tDamage: DBReader damage definitions. Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
Combat damage type table load; required before weapon/armor open.
```

---

## 5. Open questions

1. Link from dcWeapon/dcArmor inserts.

**Verdict:** **accept-with-gaps**
