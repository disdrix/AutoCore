# Review A (reconstruction fidelity): `aa_008221e0` Client_OnAuthDisconnected

| Field | Value |
|---|---|
| **Stable ID** | `aa_008221e0` |
| **VA** | `0x008221e0` |
| **Canonical name** | `Client_OnAuthDisconnected` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008221e0_Client_OnAuthDisconnected.md` |
| **System tag** | `auth` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_OnAuthDisconnected.cpp` |
| Raw | `docs/reconstruction/raw/aa_008221e0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Auth OnDisconnected path — surfaces login-failure toast/dialog (Failed to login!). Client auth UX only.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| OnDisconnected string path | High | String |
| Failed to login toast/dialog | High | String |
| No sector gameplay mutation | High | Auth UX |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Disconnect event → show failure UX | Yes |

---

## 4. Gaps

1. Exact dialog widget vs toast helper.
2. Interaction with ShowLoginFailureDialog.

**Verdict:** **accept**
