# Review B (skeptical / adversarial): `aa_00402e20` CombatFloaterQueue_InsertOne_GrowPath_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402e20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00402e20_CombatFloaterQueue_InsertOne_GrowPath_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | This function awards kill XP | **Falsified** — queue insert only; award is `AddExperience` |
| 2 | Element size is 0x20 / 0x10 | **Falsified** — stride **0x38** |
| 3 | Always reallocates | **Overstated** — reallocate path inside `FUN_00403680` only when capacity insufficient |
| 4 | Index always from empty vector | **Falsified** — when size≠0 uses `(insert-begin)/0x38` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0x38 stride + index math | High | Corrupt floater queue / wrong slot |
| UI-only role | High | Double-count XP if mistaken for grant |
| Delegates to InsertN | High | Missing grow side effects |

---

## 3. Cross-check against raw

```
index = size? (insert-begin)/0x38 : 0
InsertN(insert, 1, payload)
*out = begin + index*0x38
```

Parent: only when fast-path capacity check fails.

---

## 4. Surviving contract for AutoCore

```
CombatFloaterQueue.InsertOneGrow(outSlot, insertAt, payload):
  index from insertAt relative to begin (0 if empty)
  VectorInsertN(0x38, count=1)
  outSlot = begin + index*0x38
Do not treat as Experience grant.
```

---

## 5. Open questions

1. Floater POD layout (14 dwords).
2. Multi-insert callers beyond enqueue count=1.

**Verdict:** **accept-with-gaps**
