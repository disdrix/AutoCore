# Review B (skeptical / adversarial): `AuthClient_SendLoginInsecure` @ `0x00728c20`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728c20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00728c20_AuthClient_SendLoginInsecure.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Plaintext never encrypted | **Name says Insecure; encryption may be in EncryptAndPrepare sibling** |
| 2 | Unlimited username | **Falsified — too-long path exists** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Username/password params present | High | Wrong → protocol/UI mismatch risk |
| Length validation with log lines | High | Wrong → protocol/UI mismatch risk |
| Related but distinct from EncryptAndPrepare @ 0x00728e50 | Medium | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
SendLoginInsecure(auth, user, pass, p4, p5): validate; build LoginInsecure; enqueue
```

---

## 4. Open questions

1. Overlap with Client_EncryptAndPrepareAuthRequest — who calls which
2. DES path ownership

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
