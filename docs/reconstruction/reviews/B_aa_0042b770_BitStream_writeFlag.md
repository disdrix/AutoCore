# Review B (skeptical / adversarial): `BitStream_writeFlag` @ `0x0042b770`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b770` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0042b770_BitStream_writeFlag.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only sets never clears | **Falsified** |
| 2 | Reports failure | **Falsified — void** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single-bit write | High | Wrong → protocol/UI mismatch risk |
| Grow FUN_0042b450 | High | Wrong → protocol/UI mismatch risk |
| False clears bit | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
BitStream_writeFlag(bs, flag): write 1 bit; may silently fail grow
```

---

## 4. Open questions

1. Void return — grow failure silent

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
