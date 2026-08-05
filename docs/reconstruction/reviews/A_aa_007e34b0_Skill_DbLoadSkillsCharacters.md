# Review A (reconstruction fidelity): `aa_007e34b0` Skill_DbLoadSkillsCharacters

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e34b0` |
| **VA** | `0x007e34b0` |
| **Canonical name** | `Skill_DbLoadSkillsCharacters` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007e34b0_Skill_DbLoadSkillsCharacters.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007e34b0_FUN_007e34b0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_DbLoadSkillsCharacters.cpp` |
| Child loader | `Skill_DbLoadSkillElements.cpp` (`aa_007d9440`) |
| System | `docs/reconstruction/systems/skills-abilities.md` |

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ADO bulk-load of `//vSkillsCharacters/row` | **High** | Literal XPath/query string in raw |
| Columns include IDSkill + prereq1..3 | **High** | Multiple string refs |
| Calls skill-element child loader | **High** | Direct call to `0x007d9440` |
| Class/race filter columns present | **High** | IDClass / IDRace strings |
| Target/status-effect field population | **Medium** | Column names present; full layout OPEN |
| param_1 is query/connection context | **Medium** | `char*` surface; COM unaff registers residual |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Function symbol rename only (body CF) | **Yes** |
| No modernization of COM/ADO loops | **Yes** |
| Plate documents strings + callees | **Yes** |

---

## 4. Gaps

1. Full skill-row struct offsets still decompiler-shaped (unaff_EBX/ESI).
2. COM error paths (`_com_issue_error`) not typed.
3. Relationship to runtime skill tree insertion helpers (`FUN_0041*`) not fully named.

**Verdict:** Human name + plate faithful to string evidence. Manager ingest role clear. **accept-with-gaps.**
