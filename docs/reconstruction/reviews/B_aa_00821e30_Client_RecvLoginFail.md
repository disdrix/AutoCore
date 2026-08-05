# Review B (skeptical / adversarial): `Client_RecvLoginFail` @ `0x00821e30`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821e30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00821e30_Client_RecvLoginFail.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Single generic error | **Falsified — multi-case** |
| 2 | Never retries | **Falsified — cases 7/d/e retry after sleep** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Multi-case fail code switch | High | Wrong → protocol/UI mismatch risk |
| Some codes Sleep(0x5dc) then retry FUN_00729940 | High | Wrong → protocol/UI mismatch risk |
| User-visible strings via toast | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
RecvLoginFail(ui, code): map code→message/retry; reset login UI; toast
```

---

## 4. Open questions

1. Complete case→string map (large switch)
2. Exact widget indices 0x164/0x165

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
