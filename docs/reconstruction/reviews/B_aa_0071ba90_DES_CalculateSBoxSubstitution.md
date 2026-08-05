# Review B (skeptical / adversarial): `DES_CalculateSBoxSubstitution` @ `0x0071ba90`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071ba90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0071ba90_DES_CalculateSBoxSubstitution.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on table dumps / bit-exact |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Direct 8 classic S-box lookups | **Overstated — uses four precomputed banks; classic S boxes built at init** |
| 2 | Standalone without prior InitializeCipher tables | **Falsified for correct crypto — LUTs filled at init** |
| 3 | Outputs 6 bytes | **Falsified — 4-byte out** |
| — | Param names / types are production-ready | **Overstated** — decompiler `in_EAX` / `unaff_*` remain |
| — | Runtime verified / bit-exact DES vs FIPS vectors | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 4-byte out / 6-byte in contract | High | F pipeline broken |
| LUT base addresses | High | wrong S → ciphertext diverge |
| Index packing ≡ standard S-box nibble grouping | Medium | port mismatch if reimplemented from FIPS tables naively |
| Clean is CF-preserving scaffold | High | Low as map; high if treated as portable crypto library |

---

## 3. Surviving contract for AutoCore

```
DES_CalculateSBoxSubstitution(out4):
  in6 = EAX
  out4[0..3] = LUT_banks[index(in6)]
```

---

## 4. Open questions

1. Map four banks back to S1..S8 FIPS values
2. Confirm builder FUN_0071bdd0 / FUN_0071b5a0 roles

**Verdict:** **accept-with-gaps** on CF — safe as behavioral map for auth DES-ECB path; do not ship as bit-exact crypto until table dumps + FIPS/known-answer tests pass.
