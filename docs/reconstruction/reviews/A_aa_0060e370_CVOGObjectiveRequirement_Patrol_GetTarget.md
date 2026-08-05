# Review A (reconstruction fidelity): `aa_0060e370` CVOGObjectiveRequirement_Patrol_GetTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e370` |
| **VA** | `0x0060e370` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_GetTarget` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060e370_CVOGObjectiveRequirement_Patrol_GetTarget.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fill out-target blob with **next patrol waypoint** from progress. Null state → 0. If progress ≥ weight*required → 0 (done). Else index = progress % requiredVisits; write TFID pair from +0x30+i*8, flag +0x10→out+0xea, +0x14→out[0x3b], +0x28→*out.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_0060e370_CVOGObjectiveRequirement_Patrol_GetTarget.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Patrol_GetTarget.cpp` |
| Server | `MissionPatrolProgress / ObjectiveStateBuilder` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Null state fail | **High** | raw |
| Done when weight*required <= (int)slotFloat | **High** | raw |
| index = progress % required (+0xd0) | **High** | raw |
| TFID lo/hi at +0x30/+0x34 stride 8 | **High** | raw |
| Flag/dist copies +0x10/+0x14/+0x28 | **High** | raw |
| Clean ≡ raw | **High** | refined plate |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null gate | **Yes** |
| Done gate | **Yes** |
| Modulo index + writes | **Yes** |

---

## 5. Gaps

1. out structure full layout beyond written fields.
2. Cast float→int truncation vs floor.

**Verdict:** accept-with-gaps.
