# Review B (skeptical): `aa_007e34b0` Skill_DbLoadSkillsCharacters

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e34b0` |
| **VA** | `0x007e34b0` |
| **Canonical name** | `Skill_DbLoadSkillsCharacters` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Skeptical / adversarial |
| **Counterpart** | `reviews/A_aa_007e34b0_Skill_DbLoadSkillsCharacters.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. What could be wrong

| Risk | Severity | Assessment |
|---|---|---|
| Name overclaims “manager” ownership of all skills | Med | Function is **definition ingest**, not cast runtime. Name says DbLoad — OK. |
| Confuses character skills vs vehicle/gadget skills | Med | View is `vSkillsCharacters` — character-scoped. Documented. |
| Prereq columns misread as runtime edges | Low | Strings only prove column presence; graph build is callee-side. |
| Body not re-authored | Low | Intentional: plate + rename only. |

---

## 2. Evidence that holds

- Query path `//vSkillsCharacters/row` unique and high-signal.
- `IDSkillPrerequisite1..3` set is diagnostic of skill tree data.
- Child call into `//tSkillElements` loader is consistent with element list ownership.

---

## 3. Required follow-ups (not blockers for rename)

1. Map each ADO field get to a typed skill-def offset table.
2. Confirm whether this path also loads ranks or only base defs.
3. Link callers in SYSTEM_INDEX / skills-abilities.md.

**Verdict:** Rename justified. Do not treat as full skill system port. **accept-with-gaps.**
