# Review B (skeptical / adversarial): `aa_0042ba90` BitStream_readStringCached

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042ba90` |
| **VA** | `0x0042ba90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0042ba90_BitStream_readStringCached.md` |
| **Evidence** | Live decompile + body; write twin; UnpackGhost |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Plain `readBits` C-string | **Falsified** | Flag + Huffman `FUN_0077daf0` |
| 2 | No stream-side cache | **Falsified** | `this+0x38` read/write |
| 3 | Flag=1 means full string | **Falsified** | Flag=1 = prefix residual; flag=0 = full |
| 4 | Overflow returns without write | **Falsified** | Sets error then full-decode path |
| 5 | Clean diverges from raw | **Falsified** | ≡ live |

---

## 2. Surviving contract

```
readStringCached(this, out):
  if bitPos > bitMax: error=1; fullDecode(out); cache=out; return
  flag = read1()
  if flag:
    prefix = readU8()
    huffmanContinue(this+0x38+prefix); strcpy(out, this+0x38)
  else:
    huffmanFull(out); strcpy(this+0x38, out)
```

**Verdict:** **accept-with-gaps**
