# Review A (reconstruction fidelity): `aa_007284b0` AuthClient_OnAccountKicked

| Field | Value |
|---|---|
| **Stable ID** | `aa_007284b0` |
| **VA** | `0x007284b0` |
| **Canonical name** | `AuthClient_OnAccountKicked` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007284b0_AuthClient_OnAccountKicked.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_007284b0_AuthClient_OnAccountKicked.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_007284b0_FUN_007284b0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_OnAccountKicked.cpp` |
| String evidence | `AccountKicked/AuthServer` |

---

## 2. Purpose (from unit)

Inbound AccountKicked: shared shell + listener notify (kick).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name from string "AccountKicked" | **High** | AuthServer scope log |
| Shared auth inbound shell (scratch+log+callback) | **High** |  |
| unaff_EDI / param is AuthClient this | **Medium** | Register recovery |
| String AccountKicked | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Socket slot empty(+0x30 null or *==-1) vs live → scratch FUN_0046e280 vs FUN_0067ba30 | **Yes** (clean ≡ raw scaffold) |
| Scope log message/AuthServer | **Yes** (clean ≡ raw scaffold) |
| Destroy scratch flags via FUN_0067b110 | **Yes** (clean ≡ raw scaffold) |
| If listener at +0x18: vtable dispatch with packet fields | **Yes** (clean ≡ raw scaffold) |
| callback if listener | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Exact vtable offset in scaffold
2. Whether disconnect is in callee

**Verdict:** **accept-with-gaps**
