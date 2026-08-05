# Review B (skeptical / adversarial): `Client_RecvLoginCallback_6` @ `0x00821c70`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821c70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00821c70_Client_RecvLoginCallback_6.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same heavy UI reset as LoginFail | **Falsified — log only** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Global client identity gate | High | Wrong → protocol/UI mismatch risk |
| Fail code param | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
RecvServerFail(code): if client live, log fail code
```

---

## 4. Open questions

1. FUN_007a4480 is log vs UI toast
2. No UI reset unlike PlayFail

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
