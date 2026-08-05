# Review A (reconstruction fidelity): `aa_005355e0` Character_MaybeRefreshCombatState_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005355e0` |
| **VA** | `0x005355e0` |
| **Canonical name** | `Character_MaybeRefreshCombatState_Inferred` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005355e0_Character_MaybeRefreshCombatState_Inferred.md` |
| **System** | `combat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

After vehicle combat-pool regen tick: accumulate **64-bit elapsed ms** on character (`+0x928/+0x92c`), stamp GetTickCount at `+0x8dc`, set dirty bit `+0x634 |= 1`, and if linked object `vbase+0xa8` non-null call `CVOGCharacter_EvaluatePendingObjectives(..., kind=7, flElapsedMs, ...)`. Caller: `VehicleCombatPool_OnTick`. **Not** kill XP. Minor combat/UI/objective refresh after regen pulse.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005355e0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005355e0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_MaybeRefreshCombatState_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_005355e0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 64-bit elapsed acc +0x928/+0x92c | High | Clean plate |
| Dirty |=1 at +0x634 | High | Clean |
| Tick stamp +0x8dc | High | Clean |
| Objective kind 7 with elapsed float | High | Callee |
| Gated on vbase+0xa8 link | High | Clean |
| Unsigned float path uses 2^32 constant | Medium | DAT residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| acc+=delta; dirty; stamp; maybe EvaluatePendingObjectives(7) | Yes |
| No XP grant here | Yes |

---

## 5. Gaps / open

1. Seal objective type-7 meaning.
2. Confirm vbase+0xa8 is vehicle link.

**Verdict:** **accept-with-gaps**
