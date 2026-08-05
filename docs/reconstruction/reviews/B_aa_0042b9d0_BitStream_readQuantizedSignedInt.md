# Review B (skeptical / adversarial): `aa_0042b9d0` BitStream_readQuantizedSignedInt

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b9d0` |
| **VA** | `0x0042b9d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0042b9d0_BitStream_readQuantizedSignedInt.md` |
| **Evidence** | Live decompile + `read_memory`; parent `aa_0042b940`; sole xref |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Free `void(void)` with no formals | **Falsified** | ESI stream + AL bitCount required; offsets on ESI |
| 2 | Reads full bitCount as unsigned | **Falsified** | 1 flag + (n−1) magnitude; optional negate |
| 3 | Always reads sign flag | **Falsified** | Overflow (`max < bitpos`) skips flag, sets error, positive path |
| 4 | Returns float | **Falsified** | Integer EAX; float only in parent dequant |
| 5 | Multiple callers / shared | **Falsified** | Single code xref: `BitStream_readQuantizedFloat` |
| 6 | Clean invents branches | **Falsified** | clean ≡ raw ≡ live |
| 7 | Sign = two's complement in-place | **Falsified** | Separate flag bit + arithmetic negate of magnitude |
| 8 | Mask always applied | **Falsified** | Full dword when width == 0x20 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Sign-flag + magnitude CF | **High** | Broken thr/steer/pose unpack |
| ESI/AL ABI | **High** | Port calling convention failure |
| Overflow error sticky | **High** | Silent stream desync |
| Product name | **Tentative** | Naming only |
| Runtime bit patterns | **Open** | Wire golden not captured |

---

## 3. Cross-check spine

```
if bitPos > max: error=1; read (n-1) positive
else:
  flag = read 1 bit
  mag = readBits(n-1) masked
  return flag ? -mag : mag
```

Parent scale `(1<<(n-1))-1` **requires** this signed magnitude width — matches dual A.

---

## 4. Surviving contract for AutoCore

```
readQuantizedSignedInt(stream, bitCount) -> int
  1 sign flag + (bitCount-1) magnitude bits
  overflow: sticky error, positive path only
```

Port: keep TNL BitStream signed-quant read semantics identical before dequant float divide.

---

## 5. Open questions

1. Official Torque/TNL symbol name.
2. Whether write mirror packs the same flag order (assumed yes via parent write chain).
3. Golden capture of thr/steer 6-bit values through this path.

**Verdict:** **accept-with-gaps**
