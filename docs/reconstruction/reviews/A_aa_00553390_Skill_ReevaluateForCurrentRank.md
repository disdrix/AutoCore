# Review A (reconstruction fidelity): `aa_00553390` Skill_ReevaluateForCurrentRank

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553390` |
| **VA** | `0x00553390` |
| **Canonical name** | `Skill_ReevaluateForCurrentRank` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00553390_Skill_ReevaluateForCurrentRank.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Recompute skill runtime from current rank: reads rank **`+0x5f6`**, skill id **`+0x5fc`**, calls `Skill_EvaluateRankedElements` (and helper `FUN_00627be0`), updates targeting flags **`+0x624`**. VERIFIED Evaluate call with id+rank. Invoked after init, set-rank, and template copy.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00553390_Skill_ReevaluateForCurrentRank.md` (or `aa_00553390_FUN_00553390.md`) |
| Annotated | `docs/reconstruction/raw/aa_00553390_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ReevaluateForCurrentRank.cpp` |
| Function record | `docs/reconstruction/functions/aa_00553390_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Uses +0x5f6 rank and +0x5fc id` | High | Plate VERIFIED |
| `Calls Skill_EvaluateRankedElements` | High | Callee |
| `Updates targeting flags +0x624` | High | Plate |
| `FUN_00627be0 secondary helper` | Medium | Unnamed |
| `No network` | High | Local recompute |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Rank/id → Evaluate → flags update | Yes |
| No invented XP grant | Yes |

---

## 5. Gaps / open

1. Exact +0x624 flag bit meanings.
2. FUN_00627be0 identity.

**Verdict:** **accept-with-gaps**
