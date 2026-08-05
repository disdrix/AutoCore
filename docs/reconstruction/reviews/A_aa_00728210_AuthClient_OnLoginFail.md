# Review A (reconstruction fidelity): `aa_00728210` AuthClient_OnLoginFail

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728210` |
| **VA** | `0x00728210` |
| **Canonical name** | `AuthClient_OnLoginFail` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00728210_AuthClient_OnLoginFail.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00728210_AuthClient_OnLoginFail.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00728210_FUN_00728210.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_OnLoginFail.cpp` |
| String evidence | `LoginFail/AuthServer` |

---

## 2. Purpose (from unit)

Inbound LoginFail: log + callback vt+0x10 with fail byte +0x10.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name from string "LoginFail" | **High** | AuthServer scope log |
| Shared auth inbound shell (scratch+log+callback) | **High** |  |
| unaff_EDI / param is AuthClient this | **Medium** | Register recovery |
| vt+0x10 for LoginFail | **High** |  |
| byte fail code | **High** |  |
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
| callback vt+0x10(code) | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Code enum mapping to UI strings in Client_RecvLoginFail

**Verdict:** **accept-with-gaps**
