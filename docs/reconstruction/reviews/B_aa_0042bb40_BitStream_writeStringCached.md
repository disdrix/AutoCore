# Review B (skeptical / adversarial): `aa_0042bb40` BitStream_writeStringCached

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042bb40` |
| **VA** | `0x0042bb40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0042bb40_BitStream_writeStringCached.md` |
| **Evidence** | Live decompile + body; read twin; PackUpdate |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always full Huffman write | **Falsified** | prefix>2 → compressed flag+u8 |
| 2 | Threshold ≥2 (include 2) | **Falsified** | `2 < prefix` strict |
| 3 | Null in crashes | **Falsified** | redirects to `DAT_00a1419b` |
| 4 | Grow amount 0x5dc bits | **Falsified** | **bytes** `+0x5dc` after `(bitMax+8)>>3` |
| 5 | Clean diverges from raw | **Falsified** | ≡ live |

---

## 2. Surviving contract

```
writeStringCached(this, in, len8):
  if !in: in = emptyDefault
  prefix = commonPrefix(this.cache@+0x38, in, len8)
  update cache to in[0..len8]
  ensure +1 bit capacity (else error)
  if prefix > 2:
    writeFlag(1); writeU8(prefix); huffman(len8-prefix)
  else:
    writeFlag(0); huffman(len8)
```

**Verdict:** **accept-with-gaps**
