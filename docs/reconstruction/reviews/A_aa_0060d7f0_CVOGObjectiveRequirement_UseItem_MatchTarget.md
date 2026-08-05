# Review A (reconstruction fidelity): `aa_0060d7f0` CVOGObjectiveRequirement_UseItem_MatchTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d7f0` |
| **VA** | `0x0060d7f0` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_MatchTarget` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060d7f0_CVOGObjectiveRequirement_UseItem_MatchTarget.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**MatchTarget** trampoline (vtable **+0x38**): sole body calls **FUN_0060d460** then returns. Real match criteria live in the helper (not unit-reconstructed). Called from FindObjectiveMatchingTarget.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_0060d7f0_CVOGObjectiveRequirement_UseItem_MatchTarget.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_UseItem_MatchTarget.cpp` |
| Caller | `Client_FindObjectiveMatchingTarget` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Single call FUN_0060d460 | **High** | raw |
| No local logic | **High** | raw |
| Vtable role MatchTarget | **High** | from FindObjective review |
| Helper body open | **High** | explicit gap |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Trampoline only | **Yes** |

---

## 5. Gaps

1. Seal FUN_0060d460 (item/object key compare).
2. Arg/return ABI for MatchTarget (decompiler void).

**Verdict:** accept-with-gaps.
