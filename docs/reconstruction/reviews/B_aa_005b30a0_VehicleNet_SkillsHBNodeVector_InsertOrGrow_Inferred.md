# Review B (skeptical / adversarial): `aa_005b30a0` VehicleNet_SkillsHBNodeVector_InsertOrGrow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b30a0` |
| **VA** | `0x005b30a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b30a0_VehicleNet_SkillsHBNodeVector_InsertOrGrow_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always reallocates | **Partial** | always calls grow-insert helper; helper may in-place if room (other branches) |
| 2 | Linked-list splice | **Falsified** | contiguous 0xC vector index math |
| 3 | Packs wire bits | **Falsified** | collector only |
| 4 | Inserts N from wire count | **Falsified** | hard-coded count **1** |
| 5 | Multiple VehicleNet callers | **Falsified** | sole `005b3110` |

---

## 2. Surviving contract

```
InsertOrGrow(vec, out_it, pos, value):
  idx = size ? (pos-begin)/12 : 0
  ReallocInsert(pos, 1, value)   // FUN_005b2df0
  *out_it = begin + idx*12
```

**Verdict:** **accept-with-gaps**
