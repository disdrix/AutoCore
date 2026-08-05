# Review A (reconstruction fidelity): `aa_00728990` AuthClient_SendAboutToPlay

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728990` |
| **VA** | `0x00728990` |
| **Canonical name** | `AuthClient_SendAboutToPlay` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00728990_AuthClient_SendAboutToPlay.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00728990_AuthClient_SendAboutToPlay.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00728990_FUN_00728990.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_SendAboutToPlay.cpp` |
| String evidence | `AboutToPlay/AuthServer` |

---

## 2. Purpose (from unit)

Outbound AboutToPlay; called from Client_RecvLoginCallback_12 after server list state.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Outbound string "AboutToPlay" | **High** |  |
| Uses send-scope logger 00727c00 not inbound 00727b70 | **High** |  |
| Triggered from RecvServerList callback path | **High** | Cross-unit Callback_12 |
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

1. param packing (server id / character selection)

**Verdict:** **accept-with-gaps**
