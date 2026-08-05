# Review B (skeptical / adversarial): `aa_0058cd60` Skill_GatherTargetsRadiusMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058cd60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0058cd60_Skill_GatherTargetsRadiusMap_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Identical to GatherTargetsInArea | Separate entry; shared tree helpers | **Sibling, not alias** |
| 2 | Returns only interactables always | Mode/filter params change set | **Falsified always** |
| 3 | Skill-system exclusive | Input/interact callers | **Falsified exclusive** |
| 4 | Flat array only | Float-key RB map intermediate | **Falsified** |
| 5 | No vehicle special case | type 0x0e + CVOGVehicle RTTI | **Falsified** |

---

## 2. Surviving contract

```
GatherTargetsRadiusMap(selfTfid, world, self, origin, radius, modes...):
  map = empty float→tfid tree
  for obj in world list: filter → if in radius insert by dist
  dump / return picks; destroy map
```

**Verdict:** **accept-with-gaps**
