# Review A (reconstruction fidelity): `aa_005312c0` CVOGCharacter_AddSkillPoints

| Field | Value |
|---|---|
| **Stable ID** | `aa_005312c0` |
| **VA** | `0x005312c0` |
| **Canonical name** | `CVOGCharacter_AddSkillPoints` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005312c0_CVOGCharacter_AddSkillPoints.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Update character **skill-point pool short** at `char+0x6ce` (mission advance/complete path):

1. If current pool **&lt;** new value: send LogicUI packet type **`0x21`** with entity ids from `this`+base `+0x164/+0x168`.
2. Always: dirty `char+0x634 |= 0x40`.
3. Always: **store** `*(short*)(this+0x6ce) = param_2` (assignment of the short argument).

`__thiscall`. Called from `CVOGReaction_CompleteObjective` on advance and final branches. Despite the name, the body is a **set** of the pool short, with toast when increasing.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005312c0_CVOGCharacter_AddSkillPoints.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_AddSkillPoints.cpp` |
| Function record | `docs/reconstruction/functions/aa_005312c0_CVOGCharacter_AddSkillPoints.md` |
| Twin | `CVOGCharacter_AddAttributePoints` `aa_00531250` (parallel CF) |
| Caller | `CVOGReaction_CompleteObjective` `aa_00533f90` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Pool short at `+0x6ce` | **High** | Load/compare/store |
| Dirty bit `+0x634 \|= 0x40` | **High** | Same family as mission dirty 0x10 |
| LogicUI type `0x21` on increase | **High** | Constant |
| Store is assignment not `+=` | **High** | Critical CF |
| Callers pass absolute pool or delta | **Tentative** | Name says delta; body sets absolute |
| Clean ≡ raw | **High** | Scaffold typing only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Compare current &lt; param | **Yes** |
| LogicUI 0x21 + entity pair | **Yes** |
| Dirty \|= 0x40 | **Yes** |
| Assign `+0x6ce = param_2` | **Yes** |

---

## 5. Gaps

1. Whether CompleteObjective passes **absolute** pool or expects add (callee does set).
2. LogicUI packet layout beyond type + two dwords.
3. Dirty 0x40 consumer list.
4. Runtime skill-point toast on mission complete.

**Verdict:** Set-with-toast CF faithful; name “Add” is misleading vs body. **accept-with-gaps.**
