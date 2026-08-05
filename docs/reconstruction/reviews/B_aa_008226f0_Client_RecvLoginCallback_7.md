# Review B (skeptical / adversarial): `Client_RecvLoginCallback_7` @ `0x008226f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008226f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008226f0_Client_RecvLoginCallback_7.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Silent fail | **Falsified — toast present** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| PlayFail uses same login-fail toast as other fails | High | Wrong → protocol/UI mismatch risk |
| Cleanup with arg 1 | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
RecvPlayFail: cleanup(1); reset login UI; toast try-again
```

---

## 4. Open questions

1. Difference FUN_00944b20() vs (1)

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
