# Review A (reconstruction fidelity): `aa_00821df0` Client_RecvLoginOk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821df0` |
| **VA** | `0x00821df0` |
| **Canonical name** | `Client_RecvLoginOk` |
| **System** | auth-login-ui |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00821df0_Client_RecvLoginOk.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00821df0_Client_RecvLoginOk.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00821df0_Client_RecvLoginOk.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvLoginOk.cpp` |
| String evidence | `RecvLoginOk` |

---

## 2. Purpose (from unit)

LoginOk UI: phase=2; store session ids; SendServerListEx.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Phase 2 after login ok | **High** |  |
| Immediately requests server list | **High** |  |
| Session pair stored for later AboutToPlay | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| ODS RecvLoginOk | **Yes** (clean ≡ raw scaffold) |
| this+0x4a=2; +0x50=p2; +0x54=p3 | **Yes** (clean ≡ raw scaffold) |
| if this+4: AuthClient_SendServerListEx(auth,p2,p3) | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Session field names (account id / session key)

**Verdict:** **accept-with-gaps**
