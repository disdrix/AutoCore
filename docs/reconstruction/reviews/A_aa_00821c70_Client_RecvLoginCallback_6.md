# Review A (reconstruction fidelity): `aa_00821c70` Client_RecvLoginCallback_6

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821c70` |
| **VA** | `0x00821c70` |
| **Canonical name** | `Client_RecvLoginCallback_6` |
| **System** | auth-login-ui |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00821c70_Client_RecvLoginCallback_6.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00821c70_Client_RecvLoginCallback_6.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00821c70_Client_RecvLoginCallback_6.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvLoginCallback_6.cpp` |
| String evidence | `RecvServerFail` |

---

## 2. Purpose (from unit)

Server list fail UI: gated globals; log RecvServerFail with code.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Global client identity gate | **High** |  |
| Fail code param | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| if DAT_00d1b77c && DAT_00d1b780 && *DAT_00d1b780==DAT_00d1b77c | **Yes** (clean ≡ raw scaffold) |
| ODS; FUN_007a4480(1,"RecvServerFail: code(%d)", code) | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. FUN_007a4480 is log vs UI toast
2. No UI reset unlike PlayFail

**Verdict:** **accept-with-gaps**
