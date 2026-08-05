# Review B (skeptical / adversarial): `DES_KeySchedule` @ `0x0071b740`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071b740` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0071b740_DES_KeySchedule.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on table dumps / bit-exact |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Custom / non-DES key schedule | **Falsified — PC-1 + rotation schedule match standard DES** |
| 2 | param_1 is a used key width argument | **Overstated — body never reads param_1** |
| 3 | Produces 8-byte subkeys | **Falsified — 6-byte (48-bit) subkeys × 16** |
| — | Param names / types are production-ready | **Overstated** — decompiler `in_EAX` / `unaff_*` remain |
| — | Runtime verified / bit-exact DES vs FIPS vectors | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| PC-1 / rotation tables | High | Wrong → auth password encrypt mismatch |
| Subkey layout 6×16 @ DAT_00d16e90 | High | F-function XOR misaligned |
| Readable rotate rewrite | Medium | port may fail bit-exact without table-driven path |
| Clean is CF-preserving scaffold | High | Low as map; high if treated as portable crypto library |

---

## 3. Surviving contract for AutoCore

```
DES_KeySchedule(key8):
  PC1(key) -> 56-bit CD bits @ DAT_00d176f0
  for r in 0..15:
    rotate CD by schedule[r]
    PC2 -> 6-byte subkey @ DAT_00d16e90 + 6*r
```

---

## 4. Open questions

1. Dump full PC-2 and prove ≡ FIPS 46-3
2. Known-answer: known DES key → 16 subkeys
3. Confirm endian/bit-order of DAT_00d16e90 vs OpenSSL DES_key_schedule

**Verdict:** **accept-with-gaps** on CF — safe as behavioral map for auth DES-ECB path; do not ship as bit-exact crypto until table dumps + FIPS/known-answer tests pass.
