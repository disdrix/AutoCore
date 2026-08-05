# Review A (reconstruction fidelity): `aa_00728ae0` AuthClient_SendLogout

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728ae0` |
| **VA** | `0x00728ae0` |
| **Canonical name** | `AuthClient_SendLogout` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00728ae0_AuthClient_SendLogout.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00728ae0_AuthClient_SendLogout.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00728ae0_FUN_00728ae0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_SendLogout.cpp` |
| String evidence | `Logout/AuthServer` |

---

## 2. Purpose (from unit)

Outbound Logout enqueue.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Outbound string "Logout" | **High** |  |
| Uses send-scope logger 00727c00 not inbound 00727b70 | **High** |  |
| Outbound send shell | **High** |  |
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

1. Whether close TCP follows in caller

**Verdict:** **accept-with-gaps**
