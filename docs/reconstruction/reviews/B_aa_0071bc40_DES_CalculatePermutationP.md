# Review B (skeptical / adversarial): `DES_CalculatePermutationP` @ `0x0071bc40`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bc40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0071bc40_DES_CalculatePermutationP.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on table dumps / bit-exact |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Classic bit-by-bit FIPS P table walk in this unit | **Falsified** — four precomputed 256×4 OR banks only |
| 2 | Tables present and correct in offline EXE image | **Falsified** — `read_memory` shows all-zero at d11658..d12258; need post-init dump |
| 3 | Bank0 index differs from banks 1–3 (`base+b` vs `base+b*4`) | **Overstated** — Ghidra types bank0 as `undefined4*`, so `+b` scales by 4; equivalent |
| 4 | Return value is the 32-bit P result | **Overstated** — returns `in_EAX+3`; result lives in EAX buffer bytes |
| — | Param names / types are production-ready | **Overstated** — decompiler `in_EAX` remains |
| — | Runtime verified / bit-exact DES vs FIPS vectors | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 4-byte in / 4-byte out P role in F | High | Feistel f width wrong |
| LUT base addresses + stride 0x400 | High | wrong P → ciphertext diverge |
| Index packing ≡ standard P bit positions | Medium | port mismatch if reimplemented from FIPS table naively without matching banks |
| Clean is CF-preserving scaffold | High | Low as map; high if treated as portable crypto library |

---

## 3. Surviving contract for AutoCore

```
DES_CalculatePermutationP(in4 = SboxOut):
  out4 = EAX buffer
  out4 := 0
  for i in 0..3:
    out4 |= P_bank[i][in4[i]]   // 4-byte row, banks @ d11658 + i*0x400
  // return pointer tail (in_EAX+3); consumer uses out4 bytes
```

---

## 4. Open questions

1. Dump post-`DES_InitializeCipher` banks and match FIPS P
2. Confirm builder FUN_0071bdd0 vs FUN_0071b5a0 ownership of P tables
3. Full EAX/stack framing with RoundFunctionF S-box handoff (register reuse after 6-byte E⊕K buffer)

**Verdict:** **accept-with-gaps** on CF — safe as behavioral map for auth DES-ECB path; do not ship as bit-exact crypto until table dumps + FIPS/known-answer tests pass.
