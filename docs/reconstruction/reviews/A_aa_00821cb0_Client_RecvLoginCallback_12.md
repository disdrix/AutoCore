# Review A (reconstruction fidelity): `aa_00821cb0` Client_RecvLoginCallback_12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821cb0` |
| **VA** | `0x00821cb0` |
| **Canonical name** | `Client_RecvLoginCallback_12` |
| **System** | auth-login-ui |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00821cb0_Client_RecvLoginCallback_12.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00821cb0_Client_RecvLoginCallback_12.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00821cb0_Client_RecvLoginCallback_12.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvLoginCallback_12.cpp` |
| String evidence | `RecvServerList` |

---

## 2. Purpose (from unit)

Server list received: set state byte +0x4a=3; SendAboutToPlay on auth object.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Login phase state at +0x4a (3=post server list) | **High** | LoginOk sets 2 |
| Chains to SendAboutToPlay | **High** |  |
| Uses session ids from LoginOk at +0x50/+0x54 | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| ODS RecvServerList | **Yes** (clean ≡ raw scaffold) |
| this+0x4a = 3 | **Yes** (clean ≡ raw scaffold) |
| if this+4: AuthClient_SendAboutToPlay(auth, +0x50, +0x54, +0x74) | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. byte +0x74 meaning
2. Server list data not stored in this small function

**Verdict:** **accept-with-gaps**
