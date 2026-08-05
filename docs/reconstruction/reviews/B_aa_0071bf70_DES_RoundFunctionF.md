# Review B (skeptical / adversarial): `DES_RoundFunctionF` @ `0x0071bf70`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bf70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0071bf70_DES_RoundFunctionF.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on table dumps / bit-exact |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Includes IP/FP | **Falsified — only E,XOR,S,P** |
| 2 | Uses 8-byte round keys | **Falsified — 6-byte** |
| 3 | Decrypt path / reverse schedule | **Needs-more-evidence — encrypt-only call chain observed** |
| — | Param names / types are production-ready | **Overstated** — decompiler `in_EAX` / `unaff_*` remain |
| — | Runtime verified / bit-exact DES vs FIPS vectors | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| E→XOR→S→P order | High | wrong F breaks all rounds |
| round*6 indexing | High | subkey mis-select |
| Full ABI of R/f through unaff registers | Medium | port wrong half |
| Clean is CF-preserving scaffold | High | Low as map; high if treated as portable crypto library |

---

## 3. Surviving contract for AutoCore

```
f(R, i) = P(S(E(R) XOR K[i]))
  K[i] = DAT_00d16e90 + 6*i
```

---

## 4. Open questions

1. Dual DES_CalculatePermutationP (0x0071bc40)
2. Seal register ABI from FeistelRound assembly

**Verdict:** **accept-with-gaps** on CF — safe as behavioral map for auth DES-ECB path; do not ship as bit-exact crypto until table dumps + FIPS/known-answer tests pass.
