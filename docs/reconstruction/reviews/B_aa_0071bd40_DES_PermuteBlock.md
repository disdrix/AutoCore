# Review B (skeptical / adversarial): `DES_PermuteBlock` @ `0x0071bd40`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bd40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0071bd40_DES_PermuteBlock.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on table dumps / bit-exact |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always IP (never FP) | **Falsified — two call sites; init builds two tables** |
| 2 | Self-contained with table inside function | **Falsified — EBX table base caller-owned** |
| 3 | In-place permute only | **Overstated — distinct out buffer in EAX** |
| — | Param names / types are production-ready | **Overstated** — decompiler `in_EAX` / `unaff_*` remain |
| — | Runtime verified / bit-exact DES vs FIPS vectors | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Nibble LUT OR accumulate | High | wrong IP/FP → total ciphertext fail |
| EBX = IP vs FP base | Medium | swap IP/FP if caller wrong |
| Portable C signature | Low | missing EBX/EAX in prototype |
| Clean is CF-preserving scaffold | High | Low as map; high if treated as portable crypto library |

---

## 3. Surviving contract for AutoCore

```
DES_PermuteBlock(in8, out8=EAX, table=EBX):
  out = OR over 8 bytes of precomputed IP/FP nibble contribs
```

---

## 4. Open questions

1. Dump IP/FP precomputed tables after FUN_0071b430
2. Prove ≡ FIPS IP / IP^-1

**Verdict:** **accept-with-gaps** on CF — safe as behavioral map for auth DES-ECB path; do not ship as bit-exact crypto until table dumps + FIPS/known-answer tests pass.
