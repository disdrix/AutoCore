# Review A (reconstruction fidelity): `aa_00727e50` AuthClient_OnServerListFail

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727e50` |
| **VA** | `0x00727e50` |
| **Canonical name** | `AuthClient_OnServerListFail` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00727e50_AuthClient_OnServerListFail.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00727e50_AuthClient_OnServerListFail.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00727e50_FUN_00727e50.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_OnServerListFail.cpp` |
| String evidence | `ServerListFail/AuthServer` |

---

## 2. Purpose (from unit)

Inbound ServerListFail: log + callback vt+0x20 with fail code byte at packet+0x10.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name from string "ServerListFail" | **High** | AuthServer scope log |
| Shared auth inbound shell (scratch+log+callback) | **High** |  |
| unaff_EDI / param is AuthClient this | **Medium** | Register recovery |
| Fail code single byte at +0x10 | **High** |  |
| vt+0x20 | **High** |  |
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
| callback vt+0x20(*(u8*)(pkt+0x10)) | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Code enum mapping

**Verdict:** **accept-with-gaps**
