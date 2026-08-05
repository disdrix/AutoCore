# Review A (reconstruction fidelity): `aa_00821c30` Client_RecvLoginCallback_8

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821c30` |
| **VA** | `0x00821c30` |
| **Canonical name** | `Client_RecvLoginCallback_8` |
| **System** | auth-login-ui |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00821c30_Client_RecvLoginCallback_8.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00821c30_Client_RecvLoginCallback_8.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00821c30_Client_RecvLoginCallback_8.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvLoginCallback_8.cpp` |
| String evidence | `RecvPlayOk` |

---

## 2. Purpose (from unit)

PlayOk UI: store session fields; set flag; advance state FUN_009332b0; close auth TCP.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Stores two session dwords at +0x6c/+0x70 | **High** |  |
| Sets ready flag +0x4b | **High** |  |
| Closes auth TCP after PlayOk | **High** |  |
| Matches Auth OnPlayOk payload shape | **Medium** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| ODS RecvPlayOk | **Yes** (clean ≡ raw scaffold) |
| this+0x6c=param2; this+0x4b=1; this+0x70=param3 | **Yes** (clean ≡ raw scaffold) |
| FUN_009332b0() | **Yes** (clean ≡ raw scaffold) |
| if DAT_00d1a90c: AuthClient_CloseTcpConnection | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. FUN_009332b0 state machine role
2. DAT_00d1a90c identity

**Verdict:** **accept-with-gaps**
