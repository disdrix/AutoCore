# Review B (skeptical / adversarial): `DES_EncryptBlock8` @ `0x0071c1b0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071c1b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0071c1b0_DES_EncryptBlock8.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on table dumps / bit-exact |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | CBC / IV chaining | **Falsified — pure per-block; caller loops 3 independent ECB blocks** |
| 2 | Encrypts full 30-byte creds | **Falsified — only 24 bytes (3 blocks); trailing 6 password bytes plain in request packing** |
| 3 | Key set inside this function | **Falsified — global schedule from InitializeCipher** |
| 4 | NETD key | **Contested/falsified — init uses TEST (see InitializeCipher dual)** |
| — | Param names / types are production-ready | **Overstated** — decompiler `in_EAX` / `unaff_*` remain |
| — | Runtime verified / bit-exact DES vs FIPS vectors | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| IP→16 rounds→swap→FP | High | auth password ciphertext wrong |
| ECB 3×8 from login path | High | wire layout |
| In-place result ABI | Medium | buffer corruption if ported wrong |
| Key material TEST | High | server reject if wrong key |
| Clean is CF-preserving scaffold | High | Low as map; high if treated as portable crypto library |

---

## 3. Surviving contract for AutoCore

```
DES_EncryptBlock8(block8):
  // requires DES_InitializeCipher already run (key "TEST")
  t = IP(block8)
  for i in 0..15: t = FeistelRound(t, K[i])
  t = swap_halves(t)
  block8 = FP(t)

# Auth login: 3× DES_EncryptBlock8 over creds[0..23]
```

---

## 4. Open questions

1. Known-answer: plaintext P, key TEST → ciphertext C match retail
2. Server-side decrypt twin location
3. Correct NETD→TEST in EncryptAndPrepare plate comments (out of dual OWN if not editing that unit)

**Verdict:** **accept-with-gaps** on CF — safe as behavioral map for auth DES-ECB path; do not ship as bit-exact crypto until table dumps + FIPS/known-answer tests pass.
