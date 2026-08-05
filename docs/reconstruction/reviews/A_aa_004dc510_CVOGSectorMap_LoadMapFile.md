# Review A (reconstruction fidelity): `aa_004dc510` CVOGSectorMap_LoadMapFile

| Field | Value |
|---|---|
| **Stable ID** | `aa_004dc510` |
| **VA** | `0x004dc510` |
| **Canonical name** | `CVOGSectorMap_LoadMapFile` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004dc510_CVOGSectorMap_LoadMapFile.md` |
| **System tag** | `sector-map` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_LoadMapFile.cpp` |
| Raw | `docs/reconstruction/raw/aa_004dc510_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Load sector map (.fam/.fat). Streams header fields including m_coidPerPlayerLoadTrigger @ sector+0xE7E0, m_coidCreatorLoadTrigger @ +0xE7E8, m_coidOnKillTrigger @ +0xE7D8, m_coidLastTeamTrigger @ +0xE7F0 via FUN_00514320 named property reads, then object payload. Feeds DoPlayerOnLoadTrigger / DoCreatorLoadTrigger TFIDs. Large body (~269 lines).

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Named props: PerPlayerLoadTrigger → +0xe7e0 | High | FUN_00514320 |
| CreatorLoadTrigger → +0xe7e8 | High | Body |
| OnKillTrigger → +0xe7d8 | High | Body |
| LastTeamTrigger → +0xe7f0 | High | Body |
| .fam / .fat path strings | High | Callee context |
| Objects loaded after header COIDs | Medium | Size / loops |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Open/stream → header COID props → object mass | Yes |

---

## 4. Gaps

1. Full object deserialization format.
2. param_3/param_4 load flags.
3. Error paths / version gates.

**Verdict:** **accept-with-gaps**
