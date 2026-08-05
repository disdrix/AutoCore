# Review B (skeptical / adversarial): `aa_00638ec0` CVOGHBAIBase_GetTargetFromAggro

| Field | Value |
|---|---|
| **Stable ID** | `aa_00638ec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00638ec0_CVOGHBAIBase_GetTargetFromAggro.md` |
| **Verdict** | **accept-with-gaps** on CF; list/faction details open |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | World spatial scan | **Falsified — aggro list path** |
| 2 | No range check | **Falsified — +0x4c8 radius** |
| 3 | Always returns first list entry | **Falsified — filters + range** |
| 4 | Finished exact list ABI | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Aggro vs spatial choice | High | Wrong target selection policy |
| Radius +0x4c8 | High | Pull range wrong |
| Faction filters | Tentative | Friendly fire / ignore hostiles |

---

## 3. Cross-check against raw

```
owner=this+0x18; validate;
build aggro list; radius=+0x4c8;
foreach: resolve; faction; hostile; range;
return first valid or null after cleanup.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
GetTargetFromAggro(hbai):
  select from hate list within attack radius after faction/hostile filters
  use when sticky aggro preferred over FindTargetToAttack scan
  server aggro table should feed equivalent pick
```

---

## 5. Open questions

1. Name FUN_005134e0 hostile check.
2. Document list node +0x29 flag walk.

**Verdict:** **accept-with-gaps** on CF; list/faction details open
