# Review A (reconstruction fidelity): `aa_0042b9d0` BitStream_readQuantizedSignedInt

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b9d0` |
| **VA** | `0x0042b9d0` |
| **Canonical name** | `BitStream_readQuantizedSignedInt` (inferred; Ghidra `FUN_0042b9d0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0042b9d0_BitStream_readQuantizedSignedInt.md` |
| **System** | network-bitstream |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` body; sole caller `BitStream_readQuantizedFloat` `0x0042b940` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Read a **signed quantized integer** from a TNL-style BitStream:

1. Consume **1 flag bit** (sign).
2. Consume **`bitCount - 1`** magnitude bits via `BitStream_readBits`.
3. Mask magnitude to `(1 << (bitCount-1)) - 1` when width ≠ 32; full dword when width == 32.
4. If sign flag was set → **negate** the magnitude and return; else return positive magnitude.

This is the integer stage for `BitStream_readQuantizedFloat` (`0x0042b940`), which divides the result by the signed-range max.

**Not** a float reader; **not** unsigned-only.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0042b9d0_FUN_0042b9d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0042b9d0_FUN_0042b9d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0042b9d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0042b9d0_FUN_0042b9d0.md` |
| Parent dual | `reviews/A_aa_0042b940_BitStream_readQuantizedFloat.md` |
| Live | Ghidra decompile ≡ raw; `read_memory` `0x0042b9d0` (96 B) |

**Three-rep:** present (no rewrite this pass).

---

## 3. Signature (sealed from image + decompiler)

```c
// Custom register ABI (decompiler: unaff_ESI + in_AL)
// ESI = BitStream* this
// AL  = bitCount (total bits including 1 sign flag)
// returns signed magnitude in EAX (uint display; treat as int)
int BitStream_readQuantizedSignedInt(BitStream *stream /*ESI*/, uint8_t bitCount /*AL*/);
```

| Formal | Source | Conf |
|---|---|---|
| Stream `this` | **ESI** (`unaff_ESI` in decomp; offsets `+0xc` buf, `+0x18` bitpos, `+0x1c` error, `+0x2c` max) | **High** |
| `bitCount` | **AL** (`in_AL`; used as `AL-1` magnitude width) | **High** |
| Stack formals | none observed in body prologue | **High** |
| Return | EAX; magnitude or negated magnitude | **High** |

Decompiler `void(void)` / free-func form is a **residual** — real formals are ESI+AL.

---

## 4. Control flow (clean ≡ raw ≡ live)

```
bitpos = stream->bitPos (+0x18)
if (stream->maxBits (+0x2c) < bitpos):
  stream->error (+0x1c) = 1
  // fall through to unsigned/positive path (no sign bit consumed)
else:
  byte = stream->buf[+0xc][bitpos >> 3]
  stream->bitPos = bitpos + 1          // consume sign flag bit
  if (byte & (1 << (bitpos & 7))) != 0:
    w = bitCount - 1
    mag = 0
    BitStream_readBits(w, &mag)
    if w == 0x20: return -mag
    return -((1 << (w & 0x1f)) - 1) & mag

// positive path (flag clear OR overflow error path)
w = bitCount - 1
mag = 0
BitStream_readBits(w, &mag)
if w == 0x20: return mag
return ((1 << (w & 0x1f)) - 1) & mag
```

| Stage | Match | Conf |
|---|---|---|
| Sign bit consume +1 bitPos | **Yes** | **High** |
| Overflow → set error flag `+0x1c`, skip sign | **Yes** | **High** |
| Magnitude width = bitCount−1 | **Yes** | **High** |
| Mask when width ≠ 32 | **Yes** | **High** |
| Negate when sign flag set | **Yes** | **High** |
| Sole callee `BitStream_readBits` | **Yes** | **High** |
| Sole caller `BitStream_readQuantizedFloat` | **Yes** (xref) | **High** |

### BitStream layout used here

| Off | Role |
|---:|---|
| `+0x0c` | byte buffer base |
| `+0x18` | current bit position |
| `+0x1c` | error / underflow sticky byte |
| `+0x2c` | max bit position (bound) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function exists @ `0x0042b9d0` | **Confirmed** | Ghidra + bytes |
| Role = signed quantized int read for dequant parent | **High** | sole parent dual + CF |
| 1 sign flag + (n−1) magnitude bits | **High** | decompile + parent scale `(1<<(n-1))-1` |
| ESI stream / AL bitCount ABI | **High** | decomp unaff + offsets |
| Overflow path sets `+0x1c` without consuming flag | **High** | CF |
| Product English name | **Tentative** | inferred; Ghidra still `FUN_*` |
| Bit-exact / runtime golden | **Open** | deferred |

---

## 6. Gaps

1. Product/PDB name (inferred `BitStream_readQuantizedSignedInt`).
2. Exact BitStream C++ type / full layout beyond offsets used here.
3. Whether overflow path intentionally drops sign (yes CF) is intentional wire protocol — sealed as written.
4. Symmetric write path (`FUN_0042b980` / write quant) not dual-owned in this unit.

**Verdict:** **accept-with-gaps**
