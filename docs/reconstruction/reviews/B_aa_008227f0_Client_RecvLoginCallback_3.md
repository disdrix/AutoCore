# Review B (skeptical / adversarial): `Client_RecvLoginCallback_3` @ `0x008227f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008227f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008227f0_Client_RecvLoginCallback_3.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same short toast as PlayFail | **Falsified — distinct long string** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Source path NDAuthClient.cpp confirms auth UI layer | High | Wrong → protocol/UI mismatch risk |
| Block code param logged | High | Wrong → protocol/UI mismatch risk |
| Long customer-service message | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
RecvBlockedAccount(code): log; cleanup; toast blocked/unavailable; reset UI
```

---

## 4. Open questions

1. code→message variants

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
