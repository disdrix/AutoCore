# Review A (reconstruction fidelity): `aa_00728590` AuthClient_OnProtocolVer

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728590` |
| **VA** | `0x00728590` |
| **Canonical name** | `AuthClient_OnProtocolVer` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00728590_AuthClient_OnProtocolVer.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00728590_AuthClient_OnProtocolVer.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00728590_FUN_00728590.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_OnProtocolVer.cpp` |
| String evidence | `ProtocolVer/AuthServer` |

---

## 2. Purpose (from unit)

Inbound ProtocolVer negotiation handler; fastcall; shared shell + version handling.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| String "ProtocolVer" | **High** |  |
| fastcall framing | **Medium** | Decompiler-derived |
| Shared shell pattern | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Shared auth inbound shell | **Yes** (clean ≡ raw scaffold) |
| Log "ProtocolVer"/"AuthServer" | **Yes** (clean ≡ raw scaffold) |
| Protocol version logic beyond simple callback | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Version compare constants
2. Accept/reject path details in full body

**Verdict:** **accept-with-gaps**
