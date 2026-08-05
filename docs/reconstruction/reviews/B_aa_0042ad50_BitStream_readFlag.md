# Review B (skeptical / adversarial): `BitStream_readFlag` @ `0x0042ad50`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042ad50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0042ad50_BitStream_readFlag.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Reads a full byte | **Falsified — single bit** |
| 2 | Clears error on success | **Falsified — only sets on OOB** |
| 3 | OOB leaves out unchanged | **Falsified — forces 0** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bit cursor this+0x18 | High | Wrong → protocol/UI mismatch risk |
| End bound this+0x2c | High | Wrong → protocol/UI mismatch risk |
| Error sticky this+0x1c | High | Wrong → protocol/UI mismatch risk |
| Buffer base this+0xc | High | Wrong → protocol/UI mismatch risk |
| Return true means no error | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
BitStream_readFlag(bs, out): if OOB error=1 *out=0; else *out=bit; bitPos++; return !error
```

---

## 4. Open questions

1. Full BitStream class layout incomplete
2. thiscall confirmed by decompile only

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
