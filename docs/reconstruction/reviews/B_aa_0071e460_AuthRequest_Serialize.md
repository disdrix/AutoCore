# Review B (skeptical / adversarial): `AuthRequest_Serialize` @ `0x0071e460`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071e460` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0071e460_AuthRequest_Serialize.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Encrypts credentials here | **Falsified — encryption in EncryptAndPrepare** |
| 2 | Returns size | **Falsified — hard 0** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fixed serialize order of 5 helpers | High | Wrong → protocol/UI mismatch risk |
| Last field at this+0x34 | Medium | Wrong → protocol/UI mismatch risk |
| Always returns 0 | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
AuthRequest_Serialize(req) -> 0
  write stream fields via 4 generic helpers then field at +0x34
```

---

## 4. Open questions

1. FUN_* helpers are stream write primitives — field order not self-describing
2. Request object full layout only partial

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
