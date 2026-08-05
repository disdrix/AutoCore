# Review B (skeptical / adversarial): `CVOGObjectiveRequirement_UseItem_Eval` @ `0x0060cfe0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060cfe0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0060cfe0_CVOGObjectiveRequirement_UseItem_Eval.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Required count at +0x18 like Kill | **Falsified — UseItem +0x50** |
| 2 | Eval consumes item | **Falsified — pure compare** |
| 3 | Strict < at equality | **Falsified — <=** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Offset +0x50 | High | Never complete use objectives |

---

## 3. Surviving contract for AutoCore

```
UseItem_Eval(req,_,state):
  return (float)req.repeatCount(+0x50) <= state.slotFloat[slot]
```

---

## 4. Open questions

1. Confirm SlotAction / RecvObjectiveState same slot. → **Sealed yes** in residual refresh 2026-07-29 (`B_aa_0060cfe0_…_residual.md`; byte-identical formula; Recv `state[1..4]` ← packet slots).
2. Absolute vs delta on 0x2071 → **Sealed absolute** (same residual; Recv pure assign).
3. Runtime multi-use capture still open.

**Verdict:** accept-with-gaps (static residuals closed 2026-07-29).
