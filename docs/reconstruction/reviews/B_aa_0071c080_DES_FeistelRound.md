# Review B (skeptical / adversarial): `DES_FeistelRound` @ `0x0071c080`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071c080` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0071c080_DES_FeistelRound.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on table dumps / bit-exact |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Does 16 rounds | **Falsified — single round; loop in EncryptBlock8** |
| 2 | Applies IP/FP | **Falsified — pure L/R swap+XOR** |
| 3 | Decrypt (reverse subkeys) | **Needs-more-evidence — only encrypt call path seen** |
| — | Param names / types are production-ready | **Overstated** — decompiler `in_EAX` / `unaff_*` remain |
| — | Runtime verified / bit-exact DES vs FIPS vectors | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| L'=R, R'=L⊕f | High | broken Feistel |
| f little-endian byte split | High | byte order |
| Buffer ping-pong via EBX/EDI | Medium | port aliasing bugs |
| Clean is CF-preserving scaffold | High | Low as map; high if treated as portable crypto library |

---

## 3. Surviving contract for AutoCore

```
FeistelRound(state_in=EDI, state_out=EBX, round=EAX):
  f = F(R, K[round])
  out = R || (L XOR f)
```

---

## 4. Open questions

1. Confirm in/out buffer locations inside EncryptBlock8 stack frame
2. Decrypt path if any

**Verdict:** **accept-with-gaps** on CF — safe as behavioral map for auth DES-ECB path; do not ship as bit-exact crypto until table dumps + FIPS/known-answer tests pass.
