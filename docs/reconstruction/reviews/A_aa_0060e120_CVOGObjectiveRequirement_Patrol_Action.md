# Review A (reconstruction fidelity): `aa_0060e120` CVOGObjectiveRequirement_Patrol_Action

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e120` |
| **VA** | `0x0060e120` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_Action` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060e120_CVOGObjectiveRequirement_Patrol_Action.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Patrol **action / progress fraction** (vtable **+0x20** style). Returns progress ratio slotFloat / (required*weight), clamped to 1.0; if denominator 0 returns g_flOne.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_0060e120_CVOGObjectiveRequirement_Patrol_Action.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Patrol_Action.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| denom = +0xd0 * +0x24 | **High** | shared with Eval |
| Zero denom → 1.0 | **High** | early return g_flOne |
| ratio = slotFloat/denom; clamp ≤ 1 | **High** | raw |
| param_3 is state pointer (retyped as float by decompiler) | **High** | (int)param_3 + 4 + slot*4 |
| float10 return | **High** | x87 return |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Zero denom | **Yes** |
| Divide + clamp | **Yes** |

---

## 5. Gaps

1. Caller uses fraction for UI bar vs LogicUI type 4 only.
2. g_flOne symbol address not required for server port.

**Verdict:** accept-with-gaps.
