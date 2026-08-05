# Review B (skeptical / adversarial): `DES_InitializeCipher` @ `0x0071c000`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071c000` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0071c000_DES_InitializeCipher.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on table dumps / bit-exact |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Key is NETD\0\0\0\0 | ****Falsified** for this image — 0xaa7640 = 'TEST\0...' (read_memory)** |
| 2 | Encrypts a block here | **Falsified — setup only** |
| 3 | Reentrant / per-request rekey | **Overstated — called from auth client ctor once (observed)** |
| — | Param names / types are production-ready | **Overstated** — decompiler `in_EAX` / `unaff_*` remain |
| — | Runtime verified / bit-exact DES vs FIPS vectors | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Key='TEST' at 0xaa7640 | High | wrong auth wire password field if NETD used |
| Init order tables→schedule→S/P | High | use-before-init |
| FUN_* builders semantics | Medium | incomplete port of tables |
| Clean is CF-preserving scaffold | High | Low as map; high if treated as portable crypto library |

---

## 3. Surviving contract for AutoCore

```
DES_InitializeCipher(keyCString=EAX):
  key8 = xor_fold(keyCString, cap=40)
  build IP/FP nibble tables
  DES_KeySchedule(key8)
  build S/P LUTs
# auth ctor: keyCString = "TEST"
```

---

## 4. Open questions

1. Fix EncryptAndPrepare plate NETD → TEST
2. Dual FUN_0071b430 / FUN_0071bdd0 / FUN_0071b5a0
3. Confirm no other re-init path changes key

**Verdict:** **accept-with-gaps** on CF — safe as behavioral map for auth DES-ECB path; do not ship as bit-exact crypto until table dumps + FIPS/known-answer tests pass.
