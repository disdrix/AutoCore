# Review A (reconstruction fidelity): `aa_0095ae10` Client_LoadGraphicsIniKeys

| Field | Value |
|---|---|
| **Stable ID** | `aa_0095ae10` |
| **VA** | `0x0095ae10` |
| **Canonical name** | `Client_LoadGraphicsIniKeys` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0095ae10_Client_LoadGraphicsIniKeys.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_LoadGraphicsIniKeys.cpp` |
| Raw | `docs/reconstruction/raw/aa_0095ae10_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Load large graphics/UI INI key table including SET_NEW_MISSION_ACTIVE and FULL_QUICKBAR_RED plus CINCAM_* camera keys. Client config registration only.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| SET_NEW_MISSION_ACTIVE key string | High | String |
| FULL_QUICKBAR_RED key string | High | String |
| CINCAM_* keys present | High | String evidence |
| Table registration; no gameplay tick | High | Loader CF |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Register many INI key→handler/storage bindings | Yes |

---

## 4. Gaps

1. Default values / value types per key.
2. Where SET_NEW_MISSION_ACTIVE is consumed at runtime.

**Verdict:** **accept-with-gaps**
