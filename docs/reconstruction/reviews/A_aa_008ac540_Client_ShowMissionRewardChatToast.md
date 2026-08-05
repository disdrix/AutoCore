# Review A (reconstruction fidelity): `aa_008ac540` Client_ShowMissionRewardChatToast

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac540` |
| **VA** | `0x008ac540` |
| **Canonical name** | `Client_ShowMissionRewardChatToast` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008ac540_Client_ShowMissionRewardChatToast.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_ShowMissionRewardChatToast.cpp` |
| Raw | `docs/reconstruction/raw/aa_008ac540_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** XP/credits reward chat toast for mission/objective completion. Uses objective+0x14c mission def; missionId at def+0xac must not be -1 for completed path. CNDHash_LookupByKey(char+0x538, missionId) → already-received branch. Else Mission_ComputeObjectiveXp + FUN_0051f510 scaler; clamp FUN_004111d0 when char+0x6b4<1. Client presentation of reward numbers — not authority grant.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| mission def via objective+0x14c | High | Plate |
| missionId def+0xac; skip if -1 | High | Plate |
| already-received via hash char+0x538 | High | LookupByKey |
| Mission_ComputeObjectiveXp + scaler FUN_0051f510 | High | Callees |
| Level-cap clamp when +0x6b4<1 | Medium | Plate |
| Toast/chat only, not AddExperience | Medium | Purpose |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Resolve mission → already? toast variant : compute XP/credits toast | Yes |

---

## 4. Gaps

1. Exact toast string templates.
2. Credits path symmetry with XP.
3. Relationship to Recv path that also grants.

**Verdict:** **accept-with-gaps**
