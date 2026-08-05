# Review A (reconstruction fidelity): `aa_00553480` Skill_CopyRuntimeFieldsFromTemplate

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553480` |
| **VA** | `0x00553480` |
| **Canonical name** | `Skill_CopyRuntimeFieldsFromTemplate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00553480_Skill_CopyRuntimeFieldsFromTemplate.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Copy skill runtime fields from template skill def: flags `+0x614/+0x618`, channels `+0x60c/+0x610/+0x620`, bytes `+0x5f4..+0x5fb`, name/string block from template `+0x1a5`, rank short from float `template+0xf4` → `runtime+0x174`, clear `+0x628` casting and `+0x170/+0x178`, then `Skill_ReevaluateForCurrentRank`. Clone/instantiate skill runtime from template.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00553480_Skill_CopyRuntimeFieldsFromTemplate.md` (or `aa_00553480_FUN_00553480.md`) |
| Annotated | `docs/reconstruction/raw/aa_00553480_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_CopyRuntimeFieldsFromTemplate.cpp` |
| Function record | `docs/reconstruction/functions/aa_00553480_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Copies +0x614 targeting flags` | High | Body |
| `Copies cost/cd related dwords` | High | Body |
| `Rank from float +0xf4 → +0x174` | High | Body |
| `Clears casting +0x628` | High | Body |
| `ReevaluateForCurrentRank after` | High | Callee |
| `Template → runtime instantiate` | High | Purpose |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Field copy block → clear cast → reevaluate | Yes |
| No invented network | Yes |

---

## 5. Gaps / open

1. Full field dictionary meanings.
2. String block length at +0x1a5.

**Verdict:** **accept-with-gaps**
