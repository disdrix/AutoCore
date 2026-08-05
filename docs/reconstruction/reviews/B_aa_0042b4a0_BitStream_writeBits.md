# Review B (skeptical / adversarial): `BitStream_writeBits` @ `0x0042b4a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b4a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0042b4a0_BitStream_writeBits.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | param_2 always pointer | **Weak — used as integer count** |
| 2 | Always grows OK | **Falsified — can fail** |
| 3 | Writes full bytes only | **Falsified** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Zero count success no-op | High | Wrong → protocol/UI mismatch risk |
| Capacity this+0x30 bits | High | Wrong → protocol/UI mismatch risk |
| Grow FUN_0042b450 | High | Wrong → protocol/UI mismatch risk |
| Partial-byte merge preserved | High | Wrong → protocol/UI mismatch risk |
| param_2 is bit count | Medium | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
BitStream_writeBits(bs, bitCount, src) -> 1/0; grow if needed; write bits LSB-first
```

---

## 4. Open questions

1. FUN_0042b450 grow not dual-reviewed here
2. Decomp types bit-count as byte*

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
