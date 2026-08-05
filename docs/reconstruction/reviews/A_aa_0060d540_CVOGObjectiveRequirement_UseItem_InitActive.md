# Review A (reconstruction fidelity): `aa_0060d540` CVOGObjectiveRequirement_UseItem_InitActive

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d540` |
| **VA** | `0x0060d540` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_InitActive` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060d540_CVOGObjectiveRequirement_UseItem_InitActive.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On activate (continent +0x7e): optionally **give primary** item CBID@+0x18 if GiveAtStart +0x24; optionally **give secondary** CBID@+0x2c if GiveAtStart +0x31. Qty = 1 if MultipleUse flag set else RepeatCount +0x50. Failures log via FUN_007a4480 with mission strings.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_0060d540_CVOGObjectiveRequirement_UseItem_InitActive.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_UseItem_InitActive.cpp` |
| Give helper | `FUN_005310a0` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Continent gate +0x7e | **High** | raw |
| Primary path +0x18/-1 and +0x24 | **High** | raw |
| Secondary path +0x2c/-1 and +0x31 | **High** | raw |
| Qty: MultipleUse +0x25/+0x32 → 1 else +0x50 | **High** | raw |
| Log on give failure | **High** | string present |
| Does not set progress slot | **High** | no slot write |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Continent gate | **Yes** |
| Primary give | **Yes** |
| Secondary give | **Yes** |

---

## 5. Gaps

1. FUN_005310a0 exact give semantics (inventory vs mail).
2. Client-only give vs server authority.

**Verdict:** accept-with-gaps.
