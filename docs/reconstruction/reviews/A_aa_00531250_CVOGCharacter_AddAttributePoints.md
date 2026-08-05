# Review A (reconstruction fidelity): `aa_00531250` CVOGCharacter_AddAttributePoints

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531250` |
| **VA** | `0x00531250` |
| **Canonical name** | `CVOGCharacter_AddAttributePoints` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00531250_CVOGCharacter_AddAttributePoints.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Twin of `AddSkillPoints` for **attribute-point pool** short at `char+0x6cc`:

1. If current **&lt;** new value: LogicUI type **`0x23`** with entity ids `+0x164/+0x168`.
2. Dirty `char+0x634 |= 0x40`.
3. **Assign** `*(short*)(this+0x6cc) = param_2`.

`__thiscall`. Called from `CompleteObjective` advance/final alongside skill points.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00531250_CVOGCharacter_AddAttributePoints.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_AddAttributePoints.cpp` |
| Function record | `docs/reconstruction/functions/aa_00531250_CVOGCharacter_AddAttributePoints.md` |
| Twin | `CVOGCharacter_AddSkillPoints` `aa_005312c0` |
| Caller | `CVOGReaction_CompleteObjective` `aa_00533f90` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Pool short `+0x6cc` | **High** | Body |
| LogicUI type `0x23` | **High** | Constant (skill uses 0x21) |
| Dirty `\| = 0x40` | **High** | Shared with skill |
| Assignment not `+=` | **High** | Same attack surface as skill |
| Clean ≡ raw | **High** | Scaffold only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Compare / toast / dirty / assign | **Yes** |
| Only offset + LogicUI type differ from skill twin | **Yes** |

---

## 5. Gaps

1. Absolute vs delta at CompleteObjective call sites.
2. LogicUI 0x23 handler semantics.
3. Runtime attribute-point reward path.
4. Shared dirty 0x40 consumers with skill.

**Verdict:** Twin set-with-toast CF faithful. **accept-with-gaps.**
