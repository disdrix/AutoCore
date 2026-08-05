# Review A (reconstruction fidelity): `aa_00812de0` Client_OnServerConnectionTerminated

| Field | Value |
|---|---|
| **Stable ID** | `aa_00812de0` |
| **VA** | `0x00812de0` |
| **Canonical name** | `Client_OnServerConnectionTerminated` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00812de0_Client_OnServerConnectionTerminated.md` |
| **System tag** | `auth` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_OnServerConnectionTerminated.cpp` |
| Raw | `docs/reconstruction/raw/aa_00812de0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Server connection terminated / GM force-quit path; Accept returns to login screen. Strings: Connection to server terminated / return to login screen.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Connection terminated string | High | String |
| Return to login on Accept | High | Plate |
| Related to force-quit family | High | Similar to GlobalForceQuit |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Show terminated dialog → login on accept | Yes |

---

## 4. Gaps

1. Diff vs OnGlobalForceQuitDialog triggers.

**Verdict:** **accept**
