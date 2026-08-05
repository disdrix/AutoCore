# Review B (skeptical / adversarial): `CVOGObjectiveRequirement_UseItem_InitActive` @ `0x0060d540`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d540` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0060d540_CVOGObjectiveRequirement_UseItem_InitActive.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always gives both items | **Falsified — gated by -1 and GiveAtStart flags** |
| 2 | Qty always RepeatCount | **Falsified — MultipleUse forces 1** |
| 3 | Failure aborts mission | **Falsified — log only** |
| 4 | Works offline continent | **Falsified — +0x7e gate** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Flag/offset map | High | Missing starter items |
| FUN_005310a0 side effects | Medium | Duped items if server also gives |

---

## 3. Surviving contract for AutoCore

```
UseItem_InitActive(req, stateObj):
  if !continent[+0x7e]: return
  maybe Give(primaryCBID, qty)
  maybe Give(secondaryCBID, qty)
```

---

## 4. Open questions

1. Server give-at-start parity.
2. PrimaryCOID path not in InitActive (serialize only).

**Verdict:** accept-with-gaps.
