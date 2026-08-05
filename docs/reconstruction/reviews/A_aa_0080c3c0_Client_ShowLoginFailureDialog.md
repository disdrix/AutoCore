# Review A (reconstruction fidelity): `aa_0080c3c0` Client_ShowLoginFailureDialog

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080c3c0` |
| **VA** | `0x0080c3c0` |
| **Canonical name** | `Client_ShowLoginFailureDialog` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0080c3c0_Client_ShowLoginFailureDialog.md` |
| **System tag** | `auth` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_ShowLoginFailureDialog.cpp` |
| Raw | `docs/reconstruction/raw/aa_0080c3c0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Show generic login-failure dialog after auth/sector login attempt fails. Strings: 'Failed to login! Please try again in a moment.' / temp login-failure message.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Failed to login string | High | String |
| Generic failure dialog | High | Purpose |
| Auth UX | High | System |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Show failure dialog / related UI cleanup | Yes |

---

## 4. Gaps

1. All call sites (auth vs sector).

**Verdict:** **accept**
