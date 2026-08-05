# Review B (skeptical / adversarial): `Client_EnqueueCombatFloater_INFERRED` @ `0x00402620`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402620` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00402620_Client_EnqueueCombatFloater_INFERRED.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Fixed array no grow | Falsified — grow path |
| 2 | Element size 0x20 | Falsified — 0x38 |
| 3 | Awards XP | Falsified — UI queue only |
| 4 | Fully typed floater struct | Overstated — INFERRED |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0x38 element + begin/end/cap | High | Corrupt floater queue |
| UI only not grant | High | Double-count XP if mistaken |
| Type=3 XP at caller | High | Wrong floater category |

---

## 3. Cross-check against raw

```
EnqueueCombatFloater(queue, value):
  if room: FUN_00404600 at end; end+=0x38
  else: FUN_00402e20 grow/push
  UI feedback queue.
```

---

## 4. Surviving contract for AutoCore

```
EnqueueCombatFloater(queue*, payload):
  append 0x38-byte floater; XP path uses type 3.
  Do not treat as AddExperience.
```

---

## 5. Open questions

1. Type CombatFloaterType enum fully.
2. Seal host object for char vehicle floater list.

**Verdict:** **accept-with-gaps**
