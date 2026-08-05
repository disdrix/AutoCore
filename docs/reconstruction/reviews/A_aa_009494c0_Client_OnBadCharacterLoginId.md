# Review A (reconstruction fidelity): `aa_009494c0` Client_OnBadCharacterLoginId

| Field | Value |
|---|---|
| **Stable ID** | `aa_009494c0` |
| **VA** | `0x009494c0` |
| **Canonical name** | `Client_OnBadCharacterLoginId` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_009494c0_Client_OnBadCharacterLoginId.md` |
| **System tag** | `auth` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_OnBadCharacterLoginId.cpp` |
| Raw | `docs/reconstruction/raw/aa_009494c0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Reject play/login when character ID is invalid. Toast: 'Bad character ID on attempted login.'

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Bad character ID string | High | String |
| Client reject UX | High | Body purpose |
| No invent of character | High | Error path |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Show bad-ID failure message | Yes |

---

## 4. Gaps

1. Caller conditions for invalid ID.

**Verdict:** **accept**
