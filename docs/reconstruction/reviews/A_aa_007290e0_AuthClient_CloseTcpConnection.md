# Review A (reconstruction fidelity): `aa_007290e0` AuthClient_CloseTcpConnection

| Field | Value |
|---|---|
| **Stable ID** | `aa_007290e0` |
| **VA** | `0x007290e0` |
| **Canonical name** | `AuthClient_CloseTcpConnection` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007290e0_AuthClient_CloseTcpConnection.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_007290e0_AuthClient_CloseTcpConnection.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_007290e0_FUN_007290e0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_CloseTcpConnection.cpp` |
| String evidence | `[Closing TCP Connection]` / `AuthServer` |

---

## 2. Purpose (from unit)

Close auth TCP if connected: log [Closing TCP Connection]; closesocket on slot +0x34; clear state +0x1c.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Socket pointer at +0x34 | **High** |  |
| Connected flag related to +0x1c | **High** |  |
| Called from RecvPlayOk path | **Medium** | Client_RecvLoginCallback_8 → DAT_00d1a90c |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| gate on connected state (+0x1c) | **Yes** (clean ≡ raw scaffold) |
| scratch + log Closing TCP Connection | **Yes** (clean ≡ raw scaffold) |
| SOCKET* at +0x34; if valid and not -1: close path | **Yes** (clean ≡ raw scaffold) |
| clear connection flags | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Full close sequence (shutdown vs closesocket order)
2. +0x30 vs +0x34 socket ownership

**Verdict:** **accept-with-gaps**
