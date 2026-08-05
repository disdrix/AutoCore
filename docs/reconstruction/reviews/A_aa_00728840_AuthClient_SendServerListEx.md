# Review A (reconstruction fidelity): `aa_00728840` AuthClient_SendServerListEx

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728840` |
| **VA** | `0x00728840` |
| **Canonical name** | `AuthClient_SendServerListEx` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00728840_AuthClient_SendServerListEx.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00728840_AuthClient_SendServerListEx.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00728840_FUN_00728840.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_SendServerListEx.cpp` |
| String evidence | `ServerListEx/AuthServer` |

---

## 2. Purpose (from unit)

Outbound ServerListEx request; called from Client_RecvLoginOk after storing session ids.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Outbound string "ServerListEx" | **High** |  |
| Uses send-scope logger 00727c00 not inbound 00727b70 | **High** |  |
| Called with (authClient, sessionA, sessionB) from RecvLoginOk | **High** | Cross-unit |
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

1. Exact packet fields

**Verdict:** **accept-with-gaps**
