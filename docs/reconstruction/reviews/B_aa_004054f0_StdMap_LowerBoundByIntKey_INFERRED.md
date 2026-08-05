# Review B (skeptical / adversarial): `aa_004054f0` StdMap_LowerBoundByIntKey_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_004054f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004054f0_StdMap_LowerBoundByIntKey_INFERRED.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Hash map not tree | Falsified — tree walk + color/nil |
| 2 | String keys | Falsified — int *pKey |
| 3 | Mutates map structure | Falsified — read-only lower_bound |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Node layout [3]=key | High | Wrong lookups |
| End sentinel semantics | High | Miss → wrong default |

---

## 3. Cross-check against raw

```
LowerBoundByIntKey(map, &out, &key):
  RB walk; out = first node with key>= or end
Used by XP threshold maps. Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
Shared int-key lower_bound for AutoCore table maps if porting client maps.
```

---

## 5. Open questions

1. Diff vs Map_LowerBoundFindByIntKey naming split.

**Verdict:** **accept-with-gaps**
