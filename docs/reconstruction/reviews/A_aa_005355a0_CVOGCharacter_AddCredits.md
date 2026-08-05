# Review A (reconstruction fidelity): `aa_005355a0` CVOGCharacter_AddCredits

| Field | Value |
|---|---|
| **Stable ID** | `aa_005355a0` |
| **VA** | `0x005355a0` |
| **Canonical name** | `CVOGCharacter_AddCredits` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005355a0_CVOGCharacter_AddCredits.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Add a **signed int64** delta into character money and re-evaluate money-related pending objectives:

1. `*(int64*)(this+0x720) += nAmountDelta` (split lo/hi with carry at `+0x724`).
2. `EvaluatePendingObjectives(this, 5 /*Money*/, (float)delta, 0, 0)`.
3. Return new absolute money at `+0x720`.

`__thiscall`. Money is Globes/Bars/Scrip/Clink base-1000 (external docs). Callers include GiveCredits packet path and mission credit awards.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005355a0_CVOGCharacter_AddCredits.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_AddCredits.cpp` |
| Function record | `docs/reconstruction/functions/aa_005355a0_CVOGCharacter_AddCredits.md` |
| Sibling dual | `A_/B_aa_0080cac0` GiveCredits packet (calls this) |
| Pending eval | `aa_00534920` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Additive int64 at `+0x720/+0x724` | **High** | CARRY4 lo/hi |
| Not absolute set | **High** | Contrast absolute money packets elsewhere |
| Eval type **5** = money context | **Probable** | Plate inferred; only usage evidence |
| Float cast of delta for eval | **High** | Raw `(float)nAmountDelta` |
| Return new absolute | **High** | Post-add load |
| Clean ≡ raw CF | **High** | Scaffold whitespace only |
| Base-1000 currency semantics | **External** | Not proven in body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Int64 add with carry | **Yes** |
| EvaluatePendingObjectives(5, float, 0, 0) | **Yes** |
| Return money | **Yes** |
| No clamps / min money | **Yes** |

---

## 5. Gaps

1. Enum seal for pending type `5`.
2. Negative delta / underflow behavior (wrap vs clamp) not constrained in body.
3. Runtime GiveCredits / mission credit dual-path open.
4. Clean file is still scaffold-formatted (extra blank lines) — CF OK.

**Verdict:** Money add + pending hook CF faithful. **accept-with-gaps.**
