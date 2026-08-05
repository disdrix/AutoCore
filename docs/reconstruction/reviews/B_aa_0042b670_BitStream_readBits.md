# Review B (skeptical / adversarial): `BitStream_readBits` @ `0x0042b670`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b670` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0042b670_BitStream_readBits.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Exact inverse of writeBits always | **Needs-more-evidence — harness** |
| 2 | Clears dest on failure | **Not shown** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| End bound this+0x2c | High | Wrong → protocol/UI mismatch risk |
| Error sticky on OOB | High | Wrong → protocol/UI mismatch risk |
| Return 1/0 | High | Wrong → protocol/UI mismatch risk |
| Unaligned extract preserved | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
BitStream_readBits(bs, bitCount, dst) -> 1/0; fail if past endBits
```

---

## 4. Open questions

1. Zero-count edge fallthrough
2. Dest buffer size not validated

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
