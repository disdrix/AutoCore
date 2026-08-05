# Review A (reconstruction fidelity): `aa_00723820` Client_GetMissionCompleteAudioTable

| Field | Value |
|---|---|
| **Stable ID** | `aa_00723820` |
| **VA** | `0x00723820` |
| **Canonical name** | `Client_GetMissionCompleteAudioTable` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00723820_Client_GetMissionCompleteAudioTable.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_GetMissionCompleteAudioTable.cpp` |
| Raw | `docs/reconstruction/raw/aa_00723820_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** One-time init of mission-complete audio/UI table at DAT_00d20210 (flag DAT_00d20630 bit0). FUN_00723510 init + atexit. Called with names mission_complete_3 / mission_complete_5 from CVOGReaction_CompleteObjective.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Once-init via DAT_00d20630 | 1 | High | Body |
| Table at DAT_00d20210 | High | Body |
| FUN_00723510 init | High | Callee |
| _atexit cleanup LAB_009c3700 | High | Body |
| Used from CompleteObjective audio names | High | Plate |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if flag clear: set flag; init table; atexit; return table* | Yes |

---

## 4. Gaps

1. Exact table entry layout / name→cue mapping.

**Verdict:** **accept**
