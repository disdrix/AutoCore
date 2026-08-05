# Review A (reconstruction fidelity): `aa_004e2600` CNDDoubleList_InvokePredicateAndRemove_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2600` |
| **VA** | `0x004e2600` |
| **Canonical name** | `CNDDoubleList_InvokePredicateAndRemove_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004e2600_CNDDoubleList_InvokePredicateAndRemove_Inferred.md` |
| **System** | skills-abilities (generic) |
| **Verdict** | **accept** under `_Inferred` method name |

---

## 1. Purpose

Critical-section protected walk of an intrusive double-linked list. Invokes a predicate on each payload; on match unlinks and destroys the node; stops early if predicate sets a stop flag. Used by many systems; skills path is `Skill_ValidateTargetForSkill` → `target+0xB0` with `Skill_ValidateTarget_HBSkillListener`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e2600_FUN_004e2600.md` |
| Annotated | `docs/reconstruction/raw/aa_004e2600_CNDDoubleList_InvokePredicateAndRemove_Inferred.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDDoubleList_InvokePredicateAndRemove_Inferred.cpp` |
| RTTI | `CNDDoubleList@PAVCVOGHBBase` / Node / Ptr strings |
| Skills consumer | `Skill_ValidateTargetForSkill` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CS @ +4; head +0x1c; count +0x24; busy +0x28 | **Confirmed** | decompile |
| Callback signature (payload, ctx, &stop) | **Confirmed** | |
| Unlink + vtbl destroy on match | **Confirmed** | |
| Not skill-exclusive | **Confirmed** | many callers |
| Class family CNDDoubleList | **High** | RTTI strings + shape |
| Exact method mangling | Inferred | `_Inferred` required |

---

## 4. ValidateTarget interaction

Listener may return non-zero to remove / stop. Prior plate idea that this is "UI feedback on reject" is **false** (already falsified in ValidateTarget dual) — this is list machinery on the accept path.

---

## 5. Gaps

1. Exact C++ method name.
2. Whether CVOGHBList is a thin wrapper vs alias of this layout.
3. Full caller taxonomy outside skills.

**Verdict:** **accept** for utility role + `_Inferred` CNDDoubleList naming.

---

## Checklist

| Check | Result |
|---|---|
| CS list CF | **Pass** |
| ValidateTarget consumer | **Pass** |
| Skill-specific name avoided | **Pass** |
| Verdict | **accept** |
