# Review A (reconstruction fidelity): `aa_0060cfe0` CVOGObjectiveRequirement_UseItem_Eval

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060cfe0` |
| **VA** | `0x0060cfe0` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_Eval` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060cfe0_CVOGObjectiveRequirement_UseItem_Eval.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

UseItem **eval** (vtable **+0x8**). Completes when slot float ≥ required use count int@**req+0x50** (RepeatCount from SerializeXml).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_0060cfe0_CVOGObjectiveRequirement_UseItem_Eval.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_UseItem_Eval.cpp` |
| SerializeXml | `RepeatCount → +0x50` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Threshold (float)req+0x50 | **High** | raw |
| Slot byte +0x08 | **High** | raw |
| <= complete | **High** | raw |
| Same pattern as Kill/Patrol eval family | **High** | family |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Compare/return | **Yes** |

---

## 5. Gaps

1. Absolute vs delta use counts on 0x2071. → **Sealed absolute** in residual refresh 2026-07-29 (`A_aa_0060cfe0_…_residual.md`; Recv assigns, Eval/SlotAction read-only).
2. Shared slot with SlotAction / Recv → **Sealed** same residual (identical `state+4+slot*4`).
3. Runtime / differential still open.

**Verdict:** accept-with-gaps (static residuals closed 2026-07-29).
