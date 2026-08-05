# Review A (reconstruction fidelity): `aa_00402e20` CombatFloaterQueue_InsertOne_GrowPath_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402e20` |
| **VA** | `0x00402e20` |
| **Canonical name** | `CombatFloaterQueue_InsertOne_GrowPath_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00402e20_CombatFloaterQueue_InsertOne_GrowPath_Inferred.md` |
| **System** | `missions-progression` / combat floater UI (kill XP feedback) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Slow path for `Client_EnqueueCombatFloater_INFERRED`: when the floater vector has no free 0x38-byte slots (or begin is null), compute the insert index from `(insertPtr - begin) / 0x38`, call `CombatFloaterVector_InsertN_0x38` to grow/insert **one** element from the payload, then write the resulting slot pointer into the caller out-param.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Ghidra decompile | `0x00402e20` (batch) |
| Raw | `docs/reconstruction/raw/aa_00402e20_FUN_00402e20.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00402e20.cpp` |
| Parent dual | `reviews/A_aa_00402620_Client_EnqueueCombatFloater_INFERRED.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Element size **0x38** | **High** | `(end-begin)/0x38`, index `* 0x38` |
| Inserts **count=1** via `FUN_00403680` | **High** | Literal `1` |
| Returns new slot via `*out = begin + index*0x38` | **High** | After insert |
| Grow/reallocate owned by callee `0x00403680` | **High** | Body only indexes + delegates |
| Name INFERRED (product name open) | **Tentative** | Scaffold was `FUN_00402e20` |

---

## 4. Control flow: decompile

```
thiscall InsertOneGrow(queue, outSlot**, insertPtr, payload*):
  if begin != 0 && (end-begin)/0x38 != 0:
    index = (insertPtr - begin) / 0x38
  else:
    index = 0
  VectorInsertN(insertPtr, 1, payload)   // FUN_00403680
  *outSlot = begin + index * 0x38
```

Matches parent enqueue slow path; not an XP grant.

---

## 5. Gaps / open

1. Full 0x38 floater field map (type/value/TFID layout).
2. Whether insertPtr always equals current `end` from enqueue (caller contract).

**Verdict:** **accept-with-gaps**
