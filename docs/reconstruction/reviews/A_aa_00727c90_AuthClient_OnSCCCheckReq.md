# Review A (reconstruction fidelity): `aa_00727c90` AuthClient_OnSCCCheckReq

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727c90` |
| **VA** | `0x00727c90` |
| **Canonical name** | `AuthClient_OnSCCCheckReq` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00727c90_AuthClient_OnSCCCheckReq.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00727c90_AuthClient_OnSCCCheckReq.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00727c90_FUN_00727c90.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_OnSCCCheckReq.cpp` |
| String evidence | `SCCCheckReq/AuthServer` |

---

## 2. Purpose (from unit)

Inbound AuthServer SCCCheckReq: scope log, socket scratch setup/teardown, optional callback.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name from string "SCCCheckReq" | **High** | AuthServer scope log |
| Shared auth inbound shell (scratch+log+callback) | **High** |  |
| unaff_EDI / param is AuthClient this | **Medium** | Register recovery |
| Primarily log+callback shell | **High** |  |
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
| callback dispatch if listener present | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Exact vtable slot for SCCCheck
2. Payload offsets if any

**Verdict:** **accept-with-gaps**
