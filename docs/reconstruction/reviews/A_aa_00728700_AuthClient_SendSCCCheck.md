# Review A (reconstruction fidelity): `aa_00728700` AuthClient_SendSCCCheck

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728700` |
| **VA** | `0x00728700` |
| **Canonical name** | `AuthClient_SendSCCCheck` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00728700_AuthClient_SendSCCCheck.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00728700_AuthClient_SendSCCCheck.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00728700_FUN_00728700.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_SendSCCCheck.cpp` |
| String evidence | `SCCCheck/AuthServer` |

---

## 2. Purpose (from unit)

Outbound enqueue SCCCheck packet to AuthServer.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Outbound string "SCCCheck" | **High** |  |
| Uses send-scope logger 00727c00 not inbound 00727b70 | **High** |  |
| Outbound counterpart to OnSCCCheckReq | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Socket scratch shell (empty vs live +0x30) | **Yes** (clean ≡ raw scaffold) |
| FUN_00727c00(message, AuthServer) send-scope log | **Yes** (clean ≡ raw scaffold) |
| Build/enqueue outbound packet | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Packet opcode/body layout
2. param roles

**Verdict:** **accept-with-gaps**
