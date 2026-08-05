# Review B (skeptical): `aa_007c0350` Mission_DbLoadQuestsAndObjectives

| Field | Value |
|---|---|
| **Stable ID** | `aa_007c0350` |
| **VA** | `0x007c0350` |
| **Canonical name** | `Mission_DbLoadQuestsAndObjectives` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Skeptical / adversarial |
| **Counterpart** | `reviews/A_aa_007c0350_Mission_DbLoadQuestsAndObjectives.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. What could be wrong

| Risk | Severity | Assessment |
|---|---|---|
| “Quests” vs in-game “Missions” terminology | Low | Retail DB uses Quest; product UI says Mission. Name keeps DB term for fidelity. |
| Assumes single table for all mission kinds | Med | Only these two views proven here. |
| Claims XP formula lives here | High if claimed | **Not claimed** — only column ingest of intXP etc. |
| Overstates completeness of plate | Low | Plate is evidence-driven. |

---

## 2. Evidence that holds

- Dual view strings are unambiguous mission definition load.
- Skill/attrib/credit reward columns match known mission reward model.
- Size (~37KB) consistent with nested row materialization.

---

## 3. Required follow-ups

1. Name `FUN_007b8*` insert helpers.
2. Cross-link objective ID fields to CompleteObjective paths.
3. Confirm load order vs region mission packaging.

**Verdict:** Rename justified as mission data manager ingest. **accept-with-gaps.**
