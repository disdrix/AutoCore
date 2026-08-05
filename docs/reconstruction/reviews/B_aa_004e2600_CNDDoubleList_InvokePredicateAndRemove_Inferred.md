# Review B (skeptical / adversarial): `aa_004e2600` CNDDoubleList_InvokePredicateAndRemove_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2600` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e2600_CNDDoubleList_InvokePredicateAndRemove_Inferred.md` |
| **Verdict** | **accept-with-gaps** on product method name |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is skill-only list walk | **Falsified** — reactions/spawn/creature callers |
| 2 | Product method name recovered | **Holds as false** — RTTI is class family, not this VA |
| 3 | Always CNDDoubleList not CVOGHBList | **Unproven** — CVOGHBList_ctor also CS@+4; may share/embed layout |
| 4 | Always removes matched nodes | **Holds** — unlink+destroy is unconditional on match |
| 5 | stopFlag ends walk only after match | **Holds** — outer loop checks stop after remove |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Behavioral CF (walk/remove) | **Confirmed** | Wrong HB scan |
| CNDDoubleList family | **High** | Wrong container type in port |
| Exact method symbol | Tentative | Cosmetic |
| Identity with CVOGHBList | Open | Wrong field offsets if wrapper differs |

---

## 3. Surviving contract

```
InvokePredicateAndRemove(list, pred, ctx, nullPayloadFlag):
  lock list.cs
  if list.busy: unlock; return
  for node in list:
    if pred(node.payload, ctx, &stop):
      unlink(node); destroy(node)
      if stop: break
  unlock
```

ValidateTarget passes `Skill_ValidateTarget_HBSkillListener` as pred.

---

## 4. Residual uncertainty

| # | Item | Blocks utility seal? |
|---|---|---|
| R1 | Method mangling | No |
| R2 | CVOGHBList vs CNDDoubleList | Mild for non-HB lists |
| R3 | busy flag semantics | Mild |

---

## 5. Concrete checks

1. Re-decompile body.
2. Callers include ValidateTarget + non-skill paths.
3. RTTI search for CNDDoubleList family.
4. Compared layout to CVOGHBList_ctor CS placement.

---

## 6. Verdict

**accept-with-gaps** — behavior sealed; keep `_Inferred` until demangled method name appears.
