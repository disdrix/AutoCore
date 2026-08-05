# Review A (reconstruction fidelity): `aa_00729200` AuthClient_OnOpenedTcpConnection

| Field | Value |
|---|---|
| **Stable ID** | `aa_00729200` |
| **VA** | `0x00729200` |
| **Canonical name** | `AuthClient_OnOpenedTcpConnection` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00729200_AuthClient_OnOpenedTcpConnection.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00729200_AuthClient_OnOpenedTcpConnection.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00729200_FUN_00729200.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_OnOpenedTcpConnection.cpp` |


---

## 2. Purpose (from unit)

Open auth TCP: reject if already connected (+0x1c); alloc SOCKET slot at +0x30; socket(); connect path.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Refuses double-open via +0x1c | **High** |  |
| Allocates SOCKET heap cell at +0x30 | **High** |  |
| TCP stream socket | **High** | socket(2,1,0) |
| Connect helper FUN_0046e2a0 | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| if +0x1c != 0 return -1 | **Yes** (clean ≡ raw scaffold) |
| FUN_00415e90; FUN_0067b120 | **Yes** (clean ≡ raw scaffold) |
| new SOCKET(-1) at +0x30 | **Yes** (clean ≡ raw scaffold) |
| socket(AF_INET,SOCK_STREAM,0); connect helper FUN_0046e2a0 | **Yes** (clean ≡ raw scaffold) |
| scratch+log on success path | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Address resolution / host string source
2. Success flag write to +0x1c details

**Verdict:** **accept-with-gaps**
