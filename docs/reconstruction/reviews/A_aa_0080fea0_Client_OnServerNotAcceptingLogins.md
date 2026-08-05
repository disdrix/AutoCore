# Review A (reconstruction fidelity): `aa_0080fea0` Client_OnServerNotAcceptingLogins

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080fea0` |
| **VA** | `0x0080fea0` |
| **Canonical name** | `Client_OnServerNotAcceptingLogins` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0080fea0_Client_OnServerNotAcceptingLogins.md` |
| **System tag** | `auth` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_OnServerNotAcceptingLogins.cpp` |
| Raw | `docs/reconstruction/raw/aa_0080fea0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** S2C notify: server temporarily not accepting logins. Toast: 'The server is not accepting logins at this time...'

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Not accepting logins string | High | String |
| S2C notify purpose | High | Plate |
| UX only | High | No retry loop in unit |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Show not-accepting-logins toast/dialog | Yes |

---

## 4. Gaps

1. Opcode binding.

**Verdict:** **accept**
