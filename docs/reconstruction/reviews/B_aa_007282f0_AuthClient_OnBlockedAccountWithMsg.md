# Review B (skeptical / adversarial): `AuthClient_OnBlockedAccountWithMsg` @ `0x007282f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007282f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007282f0_AuthClient_OnBlockedAccountWithMsg.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same as BlockedAccount | **Falsified — vt+0x30 vs +0x14** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Name from string "BlockedAccountWithMsg" | High | Wrong → protocol/UI mismatch risk |
| Shared auth inbound shell (scratch+log+callback) | High | Wrong → protocol/UI mismatch risk |
| unaff_EDI / param is AuthClient this | Medium | Wrong → protocol/UI mismatch risk |
| Message blob at +0x10 passed by address | High | Wrong → protocol/UI mismatch risk |
| vt+0x30 | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
OnBlockedAccountWithMsg: listener->vt+0x30(&msgAt+0x10)
```

---

## 4. Open questions

1. Message string encoding/length

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
