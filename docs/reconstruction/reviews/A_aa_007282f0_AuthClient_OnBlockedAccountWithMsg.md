# Review A (reconstruction fidelity): `aa_007282f0` AuthClient_OnBlockedAccountWithMsg

| Field | Value |
|---|---|
| **Stable ID** | `aa_007282f0` |
| **VA** | `0x007282f0` |
| **Canonical name** | `AuthClient_OnBlockedAccountWithMsg` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007282f0_AuthClient_OnBlockedAccountWithMsg.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_007282f0_AuthClient_OnBlockedAccountWithMsg.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_007282f0_FUN_007282f0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_OnBlockedAccountWithMsg.cpp` |
| String evidence | `BlockedAccountWithMsg/AuthServer` |

---

## 2. Purpose (from unit)

Inbound BlockedAccountWithMsg: log + callback vt+0x30 with message at packet+0x10.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name from string "BlockedAccountWithMsg" | **High** | AuthServer scope log |
| Shared auth inbound shell (scratch+log+callback) | **High** |  |
| unaff_EDI / param is AuthClient this | **Medium** | Register recovery |
| Message blob at +0x10 passed by address | **High** |  |
| vt+0x30 | **High** |  |
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
| callback vt+0x30(pkt+0x10) | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Message string encoding/length

**Verdict:** **accept-with-gaps**
