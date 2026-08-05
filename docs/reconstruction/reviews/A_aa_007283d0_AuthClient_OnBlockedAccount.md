# Review A (reconstruction fidelity): `aa_007283d0` AuthClient_OnBlockedAccount

| Field | Value |
|---|---|
| **Stable ID** | `aa_007283d0` |
| **VA** | `0x007283d0` |
| **Canonical name** | `AuthClient_OnBlockedAccount` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007283d0_AuthClient_OnBlockedAccount.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_007283d0_AuthClient_OnBlockedAccount.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_007283d0_FUN_007283d0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_OnBlockedAccount.cpp` |
| String evidence | `BlockedAccount/AuthServer` |

---

## 2. Purpose (from unit)

Inbound BlockedAccount: log + callback vt+0x14 with u32 code at +0x10.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name from string "BlockedAccount" | **High** | AuthServer scope log |
| Shared auth inbound shell (scratch+log+callback) | **High** |  |
| unaff_EDI / param is AuthClient this | **Medium** | Register recovery |
| u32 block code | **High** |  |
| vt+0x14 | **High** |  |
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
| callback vt+0x14(*(u32*)(pkt+0x10)) | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Code meanings

**Verdict:** **accept-with-gaps**
