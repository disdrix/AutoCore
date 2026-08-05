# Review B (skeptical / adversarial): `aa_0077daf0` BitStream_readString

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077daf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-K) |
| **Counterpart** | `reviews/A_aa_0077daf0_BitStream_readString.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role). No `disassemble_bytes`. Own VA `0x0077daf0` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Plain fixed-length bit blob, no Huffman | Flag bit + tree walk `DAT_00d1eab0` + alphabet | **Falsified** — dual encoding |
| 2 | This **is** the cached string API | Only two callers, both inside `FUN_0042ba90` which owns cache@+0x38 | **Falsified** — base helper only |
| 3 | `__thiscall` ECX this + ret 4 | Bytes: no ECX this use; plain **`C3` RET**; ESI fields | **Falsified** — ESI + caller-clean |
| 4 | Can return 0 on error | Both arms `MOV AL,1` | **Falsified** — always 1; error is side flag |
| 5 | Overflow aborts decode | Overflow sets `+0x1c` then falls to raw (or left-child on mid-walk) | **Falsified hard-abort** |
| 6 | Tables live in static image | `read_memory` BSS zeros for tree/init; builder allocates | **Confirmed dynamic** |
| 7 | Three-rep diverges | live ≡ raw ≡ bytes | **Falsified** |
| 8 | Clean invents proven PDB name | no PDB string in unit | **Open English** — structural only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI BitStream + stack out + RET | **High** | stack/register corruption |
| Flag Huffman vs raw | **High** | wrong wire decode |
| Tree/alphabet strides | **High** | garbage characters |
| Always-return-1 | **High** | false error handling in ports |
| Product name `BitStream_readString` | **Probable** | doc mislabel only |
| Runtime / bit-exact | **Open** | shipping table drift |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  DAT_00d17a28 == 0 → FUN_0077d520
  flag bit from stream
  Huffman: u8 len + tree walk + alphabet char
  raw: u8 len + readBits(len*8)
  always return 1

bytes:
  80 3D 28 7A D1 00 00   CMP [DAT_00d17a28],0
  8B 5C 24 0C           MOV EBX,[ESP+0C]  ; out
  A1 B0 EA D1 00        tree DAT_00d1eab0
  8B 15 BC EA D1 00     alpha DAT_00d1eabc
  B0 01 … C3            return 1; RET
```

**No conflict** on owned CF. Mission-chain alias rejected as primary name.

---

## 4. Surviving contract for AutoCore

```csharp
// BitStream_readString @ 0x0077daf0
// retail: ESI = BitStream, stack char* out, RET (caller cleans 4)
// always returns 1; overflow sets stream.error

bool ReadString(BitStream bs, Span<byte> outBuf)
{
  // Implement flag + Huffman/raw exactly.
  // Do NOT treat as readStringCached (no prefix/cache here).
  // Do NOT invent a 0 return for errors — use bs.error side channel.
}
```

---

## 5. Residual risks

1. `FUN_0077d520` builder correctness assumed, not dual-sealed here.
2. Interaction when cached wrapper passes `this+0x38+prefix` mid-string — partial Huffman residual must write at that pointer without re-reading cache flag (owned by caller).
3. No runtime hit confirmation in this dual.
