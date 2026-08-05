# Review A (reconstruction fidelity): `aa_00727f30` AuthClient_OnPlayOk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727f30` |
| **VA** | `0x00727f30` |
| **Canonical name** | `AuthClient_OnPlayOk` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00727f30_AuthClient_OnPlayOk.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00727f30_AuthClient_OnPlayOk.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00727f30_FUN_00727f30.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_OnPlayOk.cpp` |
| String evidence | `PlayOk/AuthServer` |

---

## 2. Purpose (from unit)

Inbound PlayOk: log + callback vt+0x28 with (u32,u32,u8) from packet+0x10/+0x14/+0x18.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name from string "PlayOk" | **High** | AuthServer scope log |
| Shared auth inbound shell (scratch+log+callback) | **High** |  |
| unaff_EDI / param is AuthClient this | **Medium** | Register recovery |
| PlayOk triple payload (2 dwords + byte) | **High** |  |
| vt+0x28 | **High** |  |
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
| callback vt+0x28(pkt+0x10, +0x14, +0x18) | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Semantic of three fields — see Client_RecvLoginCallback_8 stores

**Verdict:** **accept-with-gaps**
