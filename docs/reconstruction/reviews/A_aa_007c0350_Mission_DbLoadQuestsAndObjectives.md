# Review A (reconstruction fidelity): `aa_007c0350` Mission_DbLoadQuestsAndObjectives

| Field | Value |
|---|---|
| **Stable ID** | `aa_007c0350` |
| **VA** | `0x007c0350` |
| **Canonical name** | `Mission_DbLoadQuestsAndObjectives` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007c0350_Mission_DbLoadQuestsAndObjectives.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007c0350_FUN_007c0350.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_DbLoadQuestsAndObjectives.cpp` |
| System | `docs/reconstruction/systems/missions-progression.md` |
| Related | `Mission_ComputeObjectiveXp`, `Mission_Client_HandleEndQuest` |

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Loads `//vQuests/row` | **High** | Literal |
| Nested `//vQuestObjectives/row` | **High** | Literal |
| Reward columns XP/credits/attrib/skill pts | **High** | intXP, intCredits, intAttribPoints, intSkillPoints |
| Objective name/map/sequence fields | **High** | strObjectiveName, strMapName, tinSequence |
| Insert helpers `FUN_007b8*` own table storage | **Medium** | Call present; not fully renamed |
| param_1 query context | **Medium** | `char*` __fastcall surface |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Rename + plate only | **Yes** |
| Large unreachable-block warnings retained | **Yes** |
| No invented CF | **Yes** |

---

## 4. Gaps

1. Quest vs objective struct layouts not sealed.
2. LayerIndex / ContinentObject wiring to sector maps OPEN.
3. Relationship to region-mission tables (`CVOGRegionMissions`) not traced here.

**Verdict:** Primary mission definition ingest. **accept-with-gaps.**
