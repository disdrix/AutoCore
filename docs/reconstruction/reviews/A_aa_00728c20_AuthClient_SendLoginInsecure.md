# Review A (reconstruction fidelity): `aa_00728c20` AuthClient_SendLoginInsecure

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728c20` |
| **VA** | `0x00728c20` |
| **Canonical name** | `AuthClient_SendLoginInsecure` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00728c20_AuthClient_SendLoginInsecure.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00728c20_AuthClient_SendLoginInsecure.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00728c20_FUN_00728c20.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_SendLoginInsecure.cpp` |
| String evidence | `LoginInsecure / username string too long` |

---

## 2. Purpose (from unit)

Outbound LoginInsecure: validate username length; pack/send login; cites AuthClientImpl.cpp strings.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Username/password params present | **High** |  |
| Length validation with log lines | **High** | String evidence |
| Related but distinct from EncryptAndPrepare @ 0x00728e50 | **Medium** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| socket scratch shell | **Yes** (clean ≡ raw scaffold) |
| log LoginInsecure | **Yes** (clean ≡ raw scaffold) |
| length checks + pack credentials path | **Yes** (clean ≡ raw scaffold) |
| enqueue | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Overlap with Client_EncryptAndPrepareAuthRequest — who calls which
2. DES path ownership

**Verdict:** **accept-with-gaps**
