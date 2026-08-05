# Review A (reconstruction fidelity): `aa_0060d060` CVOGObjectiveRequirement_UseItem_SlotAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d060` |
| **VA** | `0x0060d060` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_SlotAction` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060d060_CVOGObjectiveRequirement_UseItem_SlotAction.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**UI/progress text** for slot: resolve name string via FUN_007a6de0(req+0x20), format "%s: %i / %i" with current=(int)slotFloat and required=req+0x50, strncat into caller buffer, return appended length.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_0060d060_CVOGObjectiveRequirement_UseItem_SlotAction.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_UseItem_SlotAction.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| sprintf pattern name: cur / req | **High** | raw |
| cur from state slot float→int | **High** | raw |
| req count +0x50 | **High** | raw |
| name from +0x20 via FUN_007a6de0 | **High** | raw |
| strncat to param_4 with param_5 cap | **High** | raw |
| return strlen-style length | **High** | pointer delta |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Format + strcat + length | **Yes** |

---

## 5. Gaps

1. FUN_007a69d0 preamble purpose.
2. Display name field vs PrimaryUseText.

**Verdict:** accept-with-gaps.
