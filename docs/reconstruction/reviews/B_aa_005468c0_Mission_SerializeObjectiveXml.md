# Review B (skeptical / adversarial): `aa_005468c0` Mission_SerializeObjectiveXml

| Field | Value |
|---|---|
| **Stable ID** | `aa_005468c0` |
| **VA** | `0x005468c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005468c0_Mission_SerializeObjectiveXml.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Evaluates pending objectives at runtime | **Falsified** — fprintf only |
| 2 | CompleteCount is computed here | **Falsified** — pure getter call `FUN_0059d880` |
| 3 | Writes mission-def (not objective) | **Falsified** — `<Objective …>` strings + evaluator array at obj `+0x158` |
| 4 | Mutates CompleteCount | **Falsified** — read-only getter |
| 5 | Unrelated to EvaluatePending residual | **Falsified** — **primary string proof** for CompleteCount name used by pending dual |
| 6 | Bit-exact runtime dump observed | **Fail** |

---

## 2. Decisive CompleteCount link

```c
uVar2 = FUN_0059d880(); // this = objective def
fprintf(file, "\t\t<CompleteCount>%i</CompleteCount>\r\n", uVar2);
```

Getter body returns `*(obj+0x164)`. EvaluatePending dual CALL uses same getter for success threshold — **cross-unit sealed**.

---

## 3. Port risks

| Risk | Impact |
|---|---|
| Use serializer as eval logic | Wrong runtime path |
| Wrong CompleteCount offset | Threshold bugs in eval port |

**Verdict:** Accept as offline XML dump + field dictionary. Not a runtime evaluator.
