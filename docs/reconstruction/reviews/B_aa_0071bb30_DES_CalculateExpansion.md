# Review B (skeptical / adversarial): `DES_CalculateExpansion` @ `0x0071bb30`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bb30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0071bb30_DES_CalculateExpansion.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on table dumps / bit-exact |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Mission/progression logic | **Falsified — pure DES E expansion; inventory system tag is wrong** |
| 2 | Table-driven E | **Falsified — arithmetic-only body** |
| 3 | Expands full 64-bit block | **Falsified — 32→48 only** |
| — | Param names / types are production-ready | **Overstated** — decompiler `in_EAX` / `unaff_*` remain |
| — | Runtime verified / bit-exact DES vs FIPS vectors | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 4→6 expansion role in F | High | round XOR width wrong |
| Exact bit positions ≡ FIPS E | Medium | bit-exact fail if arithmetic rewritten incorrectly |
| Clean is CF-preserving scaffold | High | Low as map; high if treated as portable crypto library |

---

## 3. Surviving contract for AutoCore

```
DES_CalculateExpansion(R4) -> E6 in EAX:
  32-bit R expanded to 48-bit via fixed bit permutation E
```

---

## 4. Open questions

1. Derive full E bit table from arithmetic and match FIPS
2. Correct function-record system tag away from missions-progression

**Verdict:** **accept-with-gaps** on CF — safe as behavioral map for auth DES-ECB path; do not ship as bit-exact crypto until table dumps + FIPS/known-answer tests pass.
