# Review A (reconstruction fidelity): `aa_0054b4a0` Skill_EvaluateRankedElements

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054b4a0` |
| **VA** | `0x0054b4a0` |
| **Canonical name** | `Skill_EvaluateRankedElements` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0054b4a0_Skill_EvaluateRankedElements.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Evaluate skill template elements for current rank: load template element list; for each equation type write runtime cost/cooldown(`+0x10` ms VERIFIED)/charge(`+0x14`)/range/damage channels. Uses rank offset `skill+0x174`. Core of skill rank scaling — must match for AutoCore skill power.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0054b4a0_Skill_EvaluateRankedElements.md` (or `aa_0054b4a0_FUN_0054b4a0.md`) |
| Annotated | `docs/reconstruction/raw/aa_0054b4a0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_EvaluateRankedElements.cpp` |
| Function record | `docs/reconstruction/functions/aa_0054b4a0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Per-element equation eval` | High | Purpose |
| `Cooldown write runtime+0x10 ms` | High | VERIFIED |
| `Charge channel +0x14` | High | Plate |
| `Rank offset skill+0x174` | High | Param |
| `Cost/range/damage channels` | High | Purpose |
| `Not cast validation` | High | Scope |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Load elements → eval types → write runtime fields | Yes |
| No invented cast net | Yes |

---

## 5. Gaps / open

1. Full equation type opcode table.
2. Damage channel exact offsets.

**Verdict:** **accept-with-gaps**
