# Review A (reconstruction fidelity): `aa_00821aa0` Client_RecvLoginCallback_10

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821aa0` |
| **VA** | `0x00821aa0` |
| **Canonical name** | `Client_RecvLoginCallback_10` |
| **System** | auth-login-ui |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00821aa0_Client_RecvLoginCallback_10.md` |
| **Verdict** | **needs-more-evidence** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00821aa0_Client_RecvLoginCallback_10.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00821aa0_Client_RecvLoginCallback_10.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvLoginCallback_10.cpp` |
| String evidence | `RecvBlockedAccountMsg` |

---

## 2. Purpose (from unit)

UI callback for BlockedAccountMsg; decomp recovered only ODS (jumptable warning).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| String RecvBlockedAccountMsg | **High** |  |
| Body may be incomplete (jumptable warning) | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| OutputDebugStringA; return (possible incomplete decompile) | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Possible missing switch/body due to decompiler jumptable failure
2. Re-decompile recommended

**Verdict:** **needs-more-evidence**
