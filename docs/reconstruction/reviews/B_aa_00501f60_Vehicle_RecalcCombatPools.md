# Review B (skeptical / adversarial): `aa_00501f60` Vehicle_RecalcCombatPools

| Field | Value |
|---|---|
| **Stable ID** | `aa_00501f60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00501f60_Vehicle_RecalcCombatPools.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always full heal | Falsified — ratio scale |
| 2 | Ignores +0x2ac | Falsified — skip |
| 3 | Recalcs all pools in body | Overstated — HP path dominant |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CalcMaxHitPoints nest | High | Stale max HP |
| +0x2ac skip | High | Special vehicle wrong HP |
| Current scale ratio | Tentative | HP jump on equip |

---

## 3. Cross-check against raw

```
if !special && owner ok: dirty; CalcMaxHP; set max; scale current.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
RecalcCombatPools(veh):
  post-equip HP recompute; pair CalcMaxHitPoints / SetEquippedArmor
  AutoCore equip HP
```

---

## 5. Open questions

1. Confirm shield/power not in this body.
2. Test equip armor live.

**Verdict:** **accept-with-gaps**
