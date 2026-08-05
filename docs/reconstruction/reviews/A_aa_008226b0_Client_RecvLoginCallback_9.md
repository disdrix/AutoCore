# Review A (reconstruction fidelity): `aa_008226b0` Client_RecvLoginCallback_9

| Field | Value |
|---|---|
| **Stable ID** | `aa_008226b0` |
| **VA** | `0x008226b0` |
| **Canonical name** | `Client_RecvLoginCallback_9` |
| **System** | auth-login-ui |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008226b0_Client_RecvLoginCallback_9.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_008226b0_Client_RecvLoginCallback_9.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_008226b0_Client_RecvLoginCallback_9.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvLoginCallback_9.cpp` |
| String evidence | `RecvAccountKicked` |

---

## 2. Purpose (from unit)

AccountKicked UI: ODS; FUN_00944b20 cleanup.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Kick path calls shared cleanup FUN_00944b20 | **High** |  |
| No toast string in this unit | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| global gate | **Yes** (clean ≡ raw scaffold) |
| ODS | **Yes** (clean ≡ raw scaffold) |
| FUN_00944b20() | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. FUN_00944b20 full effects
2. argless vs PlayFail arg 1

**Verdict:** **accept-with-gaps**
