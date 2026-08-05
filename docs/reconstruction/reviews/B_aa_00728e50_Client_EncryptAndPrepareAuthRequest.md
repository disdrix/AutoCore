# Review B (skeptical / adversarial): `Client_EncryptAndPrepareAuthRequest` @ `0x00728e50`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728e50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00728e50_Client_EncryptAndPrepareAuthRequest.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Uses modern crypto (AES) | **Falsified — DES_EncryptBlock8** |
| 2 | Stores plaintext in request | **Falsified — encrypt before store** |
| 3 | Unlimited credential length | **Falsified — hard limits + log** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| User max 14 chars (strlen < 15) | High | Wrong → protocol/UI mismatch risk |
| Pass max 16 chars (strlen < 17) | High | Wrong → protocol/UI mismatch risk |
| 30-byte staging (14+16) | High | Wrong → protocol/UI mismatch risk |
| DES block encrypt x3 on first 24 bytes | High | Wrong → protocol/UI mismatch risk |
| AuthRequest size 0x38 | High | Wrong → protocol/UI mismatch risk |
| Return 0 success, 0xFFFFFFFF fail | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
EncryptAndPrepareAuthRequest(auth, user, pass, p4, p5) -> 0/-1
  validate lengths; pack 30B; DES-ECB 24B; AuthRequest+enqueue
```

---

## 4. Open questions

1. DES key material source not in this unit
2. Full post-encrypt enqueue path
3. Relationship to SendLoginInsecure

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
