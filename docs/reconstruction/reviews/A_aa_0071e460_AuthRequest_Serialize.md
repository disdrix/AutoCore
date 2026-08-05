# Review A (reconstruction fidelity): `aa_0071e460` AuthRequest_Serialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071e460` |
| **VA** | `0x0071e460` |
| **Canonical name** | `AuthRequest_Serialize` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0071e460_AuthRequest_Serialize.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0071e460_AuthRequest_Serialize.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_0071e460_AuthRequest_Serialize.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthRequest_Serialize.cpp` |


---

## 2. Purpose (from unit)

Serialize AuthRequest fields via helper chain; returns 0.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Fixed serialize order of 5 helpers | **High** |  |
| Last field at this+0x34 | **Medium** | Matches EncryptAndPrepare notes |
| Always returns 0 | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| FUN_0044cbd0(); FUN_00480af0(); FUN_00480af0(); FUN_00439810(); FUN_00480b50(this+0x34); return 0 | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. FUN_* helpers are stream write primitives — field order not self-describing
2. Request object full layout only partial

**Verdict:** **accept-with-gaps**
