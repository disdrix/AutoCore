# Review B (skeptical / adversarial): `BitStream_readInt` @ `0x0042b8b0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b8b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0042b8b0_BitStream_readInt.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always masks | **Falsified — skips for 0x20** |
| 2 | Signed int | **Overstated — uint path** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Thin wrapper on readBits | High | Wrong → protocol/UI mismatch risk |
| Mask omitted for 32-bit | High | Wrong → protocol/UI mismatch risk |
| Implicit this | Medium | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
BitStream_readInt(bitCount)->uint: readBits; mask if !=32
```

---

## 4. Open questions

1. Free-func form vs thiscall
2. readBits error not checked

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
