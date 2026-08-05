# Review A (reconstruction fidelity): `aa_00728e50` Client_EncryptAndPrepareAuthRequest

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728e50` |
| **VA** | `0x00728e50` |
| **Canonical name** | `Client_EncryptAndPrepareAuthRequest` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00728e50_Client_EncryptAndPrepareAuthRequest.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00728e50_Client_EncryptAndPrepareAuthRequest.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00728e50_Client_EncryptAndPrepareAuthRequest.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_EncryptAndPrepareAuthRequest.cpp` |


---

## 2. Purpose (from unit)

Validate user/pass lengths; pack 30-byte cred buffer; DES-ECB encrypt 3×8-byte blocks; fill 0x38 AuthRequest; hand to send.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| User max 14 chars (strlen < 15) | **High** | 0x0F bound |
| Pass max 16 chars (strlen < 17) | **High** | 0x11 bound |
| 30-byte staging (14+16) | **High** |  |
| DES block encrypt x3 on first 24 bytes | **High** | DES_EncryptBlock8 |
| AuthRequest size 0x38 | **High** |  |
| Return 0 success, 0xFFFFFFFF fail | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| socket scratch shell + log Login/AuthServer | **Yes** (clean ≡ raw scaffold) |
| reject empty user/pass (log line 0xc4) | **Yes** (clean ≡ raw scaffold) |
| reject user strlen>=0x0F (line 0xcb); pass >=0x11 (line 0xd2) | **Yes** (clean ≡ raw scaffold) |
| zero 30-byte staging; copy user+pass | **Yes** (clean ≡ raw scaffold) |
| new AuthRequest 0x38; DES_EncryptBlock8 on three blocks | **Yes** (clean ≡ raw scaffold) |
| store encrypted at +0x10..; param4 at +0x30; param5 at +0x34 | **Yes** (clean ≡ raw scaffold) |
| enqueue FUN_0046ebf0; return 0 / -1 | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. DES key material source not in this unit
2. Full post-encrypt enqueue path
3. Relationship to SendLoginInsecure

**Verdict:** **accept-with-gaps**
