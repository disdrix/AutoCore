# Review A (reconstruction fidelity): `aa_008227f0` Client_RecvLoginCallback_3

| Field | Value |
|---|---|
| **Stable ID** | `aa_008227f0` |
| **VA** | `0x008227f0` |
| **Canonical name** | `Client_RecvLoginCallback_3` |
| **System** | auth-login-ui |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008227f0_Client_RecvLoginCallback_3.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_008227f0_Client_RecvLoginCallback_3.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_008227f0_Client_RecvLoginCallback_3.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvLoginCallback_3.cpp` |
| String evidence | `RecvBlockedAccount / Blocked Account: code() / long unavailable message` |

---

## 2. Purpose (from unit)

BlockedAccount UI: log NDAuthClient.cpp; cleanup; long CS toast; reset widgets.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Source path NDAuthClient.cpp confirms auth UI layer | **High** |  |
| Block code param logged | **High** |  |
| Long customer-service message | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| global gate | **Yes** (clean ≡ raw scaffold) |
| ODS; format+log NDAuthClient.cpp line 0xb8 | **Yes** (clean ≡ raw scaffold) |
| FUN_00944b20(1) | **Yes** (clean ≡ raw scaffold) |
| widget reset + long toast + vt+0x34c | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. code→message variants

**Verdict:** **accept-with-gaps**
