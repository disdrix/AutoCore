# Review B (skeptical / adversarial): `Client_RecvLoginCallback_11` @ `0x00821a90`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821a90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00821a90_Client_RecvLoginCallback_11.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Handles SCC challenge | **Falsified — empty handler** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| No-op beyond debug log | High | Wrong → protocol/UI mismatch risk |
| Maps to SCC check request event | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
RecvLoginCallback_11: ODS RecvSCCheckReq only
```

---

## 4. Open questions

1. Whether retail build strips this
2. Real work may be elsewhere

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
