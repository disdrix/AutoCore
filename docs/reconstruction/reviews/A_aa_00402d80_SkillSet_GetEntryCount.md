# Review A (reconstruction fidelity): `aa_00402d80` SkillSet_GetEntryCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402d80` |
| **VA** | `0x00402d80` |
| **Canonical name** | `SkillSet_GetEntryCount` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00402d80_SkillSet_GetEntryCount.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** |

---

## 1. Purpose

Real thin NPC skill-set size helper: if vector begin at **skillSet+0x4** is null → **0**; else `(end - begin) / 0x18` where end is **+0x8**. Entry stride **0x18** = `NPCSkillSetEntry`. This is the **true** `SkillSet_GetEntryCount` body; many `Skill_Uses_SkillSet_GetEntryCount*` clean units are **string-alias bulk** that only *mention* this name and must not be confused with this VA.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00402d80_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00402d80_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillSet_GetEntryCount.cpp` |
| Function record | `docs/reconstruction/functions/aa_00402d80_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Stride 0x18 entry size` | High | Clean body |
| `Begin +0x4 / end +0x8` | High | Vector layout |
| `Null begin → 0` | High | Early out |
| `Canonical thin unit vs Skill_Uses_* aliases` | High | Naming ledger |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| null begin → 0; else (end-begin)/0x18 | Yes |
| No invent capacity field | Yes |

---

## 5. Gaps / open

1. Type plate for NPCSkillSetEntry 0x18.
2. Xref NPC_TryCastSkillFromSet consumers.

**Verdict:** **accept**
