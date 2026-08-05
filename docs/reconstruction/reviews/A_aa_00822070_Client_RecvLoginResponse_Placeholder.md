# Review A (reconstruction fidelity): `aa_00822070` Client_RecvLoginResponse_Placeholder

| Field | Value |
|---|---|
| **Stable ID** | `aa_00822070` |
| **VA** | `0x00822070` |
| **Canonical name** | `Client_RecvLoginResponse_Placeholder` |
| **System** | auth-login-ui |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00822070_Client_RecvLoginResponse_Placeholder.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00822070_Client_RecvLoginResponse_Placeholder.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00822070_Client_RecvLoginResponse_Placeholder.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvLoginResponse_Placeholder.cpp` |
| String evidence | `OnConnectionFailed / Could not connect to the authentication server` |

---

## 2. Purpose (from unit)

Connection-failed path: OnConnectionFailed log; reset UI; dual toasts (login failed + auth server connect).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Connection failure not credential failure | **High** | Strings |
| Double toast sequence | **High** |  |
| Name Placeholder understates — real handler | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| global gates DAT_00d1b77c/780 | **Yes** (clean ≡ raw scaffold) |
| log OnConnectionFailed code | **Yes** (clean ≡ raw scaffold) |
| UI reset if widgets present and DAT_00d1b1e4==0 | **Yes** (clean ≡ raw scaffold) |
| toast login failed; vt+0x34c; FUN_007fc360; toast auth connect fail | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. DAT_00d1b1e4 flag meaning
2. FUN_007fc360 role

**Verdict:** **accept-with-gaps**
