# Review B (skeptical / adversarial): `AuthClient_OnLoginFail` @ `0x00728210`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728210` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00728210_AuthClient_OnLoginFail.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Closes TCP here | **Not in this unit — UI path elsewhere** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Name from string "LoginFail" | High | Wrong → protocol/UI mismatch risk |
| Shared auth inbound shell (scratch+log+callback) | High | Wrong → protocol/UI mismatch risk |
| unaff_EDI / param is AuthClient this | Medium | Wrong → protocol/UI mismatch risk |
| vt+0x10 for LoginFail | High | Wrong → protocol/UI mismatch risk |
| byte fail code | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
OnLoginFail: listener->vt+0x10(codeByte)
```

---

## 4. Open questions

1. Code enum mapping to UI strings in Client_RecvLoginFail

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
