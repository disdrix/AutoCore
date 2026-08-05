# Review B (skeptical / adversarial): `BitStream_writeInt` @ `0x0042b8f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b8f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0042b8f0_BitStream_writeInt.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Endian swap | **Not present** |
| 2 | Checks write failure | **Falsified** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Thin wrapper on writeBits | High | Wrong → protocol/UI mismatch risk |
| Value by address of param | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
BitStream_writeInt(value, bitCount): writeBits(bitCount, &value)
```

---

## 4. Open questions

1. writeBits return discarded
2. this implicit

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
