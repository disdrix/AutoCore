# Review B (skeptical / adversarial): `aa_0056d160` Weapon_FireHelper_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056d160` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0056d160_Weapon_FireHelper_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Always fires | Gates on +0xc7/+0xcb, heat, suppress param_3, counters | **Falsified always** |
| 2 | Vehicle-only | Also UI/path callers; ghost unpack among them | **Not vehicle-only** |
| 3 | Single code path | Bit7 of +0xc4 splits A/B | **Falsified single** |
| 4 | Field3 is raw heat | `(1 - +0xdc)*0.5` | **Scaled residual English** |
| 5 | Skill cast | Weapon message builders + heat check | **Falsified skill** |

---

## 2. Surviving contract

```
Weapon_FireHelper(w, ?, suppress):
  if !(w.c4 & 0x80):
    // primary fire message path (type-4 pack) unless suppress
  else:
    // heat/muzzle state machine + attachment type-4 side effects
```

**Verdict:** **accept-with-gaps**
