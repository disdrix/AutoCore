# Review A (reconstruction fidelity): `aa_00412730` Skill_Uses_SkillSet_GetEntryCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_00412730` |
| **VA** | `0x00412730` |
| **Canonical name** | `Skill_Uses_SkillSet_GetEntryCount` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00412730_Skill_Uses_SkillSet_GetEntryCount.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

String-driven human alias for bulk unit at **0x00412730** (Ghidra `FUN_00412730`). Primary evidence: embedded/keyword string **"SkillSet_GetEntryCount"** — used for reconstruction indexing / coverage ledger, **not** a second copy of the thin vector-length helper at `aa_00402d80`. Body is large (~300 lines) `__thiscall` with multi-arg workspace; CF accepted as bulk capture only. Prefer `SkillSet_GetEntryCount` for product math.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00412730_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00412730_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_Uses_SkillSet_GetEntryCount.cpp` |
| Function record | `docs/reconstruction/functions/aa_00412730_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `String alias evidence SkillSet_GetEntryCount` | High | Clean plate |
| `VA ≠ thin GetEntryCount 0x00402d80` | High | Address split |
| `Large multi-arg body` | High | CF size |
| `Not product-equivalent to thin helper` | High | Ledger policy |
| `Callee graph residual FUN_*` | Medium | Unnamed helpers |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Bulk body preserved from raw | Yes |
| No invent thin-vector rewrite | Yes |

---

## 5. Gaps / open

1. Do not port body as GetEntryCount.
2. Optional: demote alias weight in coverage.

**Verdict:** **accept-with-gaps**
