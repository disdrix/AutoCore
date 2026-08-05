# Review A (reconstruction fidelity): `aa_00728010` AuthClient_OnPlayFail

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728010` |
| **VA** | `0x00728010` |
| **Canonical name** | `AuthClient_OnPlayFail` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00728010_AuthClient_OnPlayFail.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00728010_AuthClient_OnPlayFail.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00728010_FUN_00728010.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_OnPlayFail.cpp` |
| String evidence | `PlayFail/AuthServer` |

---

## 2. Purpose (from unit)

Inbound PlayFail: log + callback vt+0x24 with fail byte at +0x10.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name from string "PlayFail" | **High** | AuthServer scope log |
| Shared auth inbound shell (scratch+log+callback) | **High** |  |
| unaff_EDI / param is AuthClient this | **Medium** | Register recovery |
| PlayFail byte code | **High** |  |
| vt+0x24 | **High** |  |
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
| callback vt+0x24(code) | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Code enum

**Verdict:** **accept-with-gaps**
