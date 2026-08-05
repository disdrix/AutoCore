# Review A (reconstruction fidelity): `aa_008226f0` Client_RecvLoginCallback_7

| Field | Value |
|---|---|
| **Stable ID** | `aa_008226f0` |
| **VA** | `0x008226f0` |
| **Canonical name** | `Client_RecvLoginCallback_7` |
| **System** | auth-login-ui |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008226f0_Client_RecvLoginCallback_7.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_008226f0_Client_RecvLoginCallback_7.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_008226f0_Client_RecvLoginCallback_7.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvLoginCallback_7.cpp` |
| String evidence | `RecvPlayFail / Failed to login!` |

---

## 2. Purpose (from unit)

PlayFail UI: cleanup FUN_00944b20(1); reset login widgets; toast Failed to login.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| PlayFail uses same login-fail toast as other fails | **High** |  |
| Cleanup with arg 1 | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| ODS RecvPlayFail | **Yes** (clean ≡ raw scaffold) |
| gates on DAT_00d1b780 | **Yes** (clean ≡ raw scaffold) |
| FUN_00944b20(1) | **Yes** (clean ≡ raw scaffold) |
| widget reset + toast + vt+0x34c | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Difference FUN_00944b20() vs (1)

**Verdict:** **accept-with-gaps**
