# Review A (reconstruction fidelity): `aa_00727d70` AuthClient_OnServerListEx

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727d70` |
| **VA** | `0x00727d70` |
| **Canonical name** | `AuthClient_OnServerListEx` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00727d70_AuthClient_OnServerListEx.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00727d70_AuthClient_OnServerListEx.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00727d70_FUN_00727d70.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_OnServerListEx.cpp` |
| String evidence | `ServerListEx/AuthServer` |

---

## 2. Purpose (from unit)

Inbound ServerListEx: log + callback vtable+0x1c with payload at packet+0x10.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name from string "ServerListEx" | **High** | AuthServer scope log |
| Shared auth inbound shell (scratch+log+callback) | **High** |  |
| unaff_EDI / param is AuthClient this | **Medium** | Register recovery |
| Payload starts packet+0x10 | **High** |  |
| Listener vtable slot +0x1c | **High** |  |
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
| callback +0x18 → vt+0x1c(param+0x10) | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Server list payload layout
2. Listener concrete type

**Verdict:** **accept-with-gaps**
