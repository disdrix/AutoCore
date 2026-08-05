# Review B (skeptical / adversarial): `aa_0077d960` BitStream_writeString

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077d960` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-C) |
| **Counterpart** | `reviews/A_aa_0077d960_BitStream_writeString.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role). No `disassemble_bytes`. Own VA `0x0077d960` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Plain fixed-length bit blob, no Huffman | Flag + alphabet cost + dual encode arms | **Falsified** — dual encoding |
| 2 | This **is** the cached string API | Sole caller is `FUN_0042bb40` which owns cache@+0x38 | **Falsified** — base helper only |
| 3 | `__thiscall` ECX this + ret 4 | Bytes: this in **EAX→EDI**; plain **`C3` RET**; stack maxLen | **Falsified** — register ABI |
| 4 | Can return 0 on error | All arms `MOV AL,1` | **Falsified** — always 1 |
| 5 | Always Huffman | Cost compare can select raw when `len*8 <= cost` | **Falsified always-Huffman** |
| 6 | Capacity bound is `+0x2c` like reads | Flag arm uses **`+0x30`** | **Falsified** read-bound mixup |
| 7 | Tables live in static image | `read_memory` BSS zeros | **Confirmed dynamic** |
| 8 | Three-rep diverges | live ≡ raw ≡ bytes | **Falsified** |
| 9 | Mission-chain alias is primary name | no product string in unit | **Rejected** as primary |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX bs + EBX str + stack maxLen + RET | **High** | stack/register corruption |
| Flag Huffman vs raw + cost rule | **High** | wrong wire encode |
| Alphabet 0xc / +4 / +8 | **High** | garbage bitstream |
| Always-return-1 | **High** | false error handling |
| Product name `BitStream_writeString` | **Probable** | doc mislabel only |
| Runtime / bit-exact | **Open** | shipping table drift |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  null → flag0 + u8 0
  DAT_00d17a28 == 0 → FUN_0077d520
  len = min(strlen, maxLen)
  if len*8 <= Σ bitLen: flag0 + raw
  else: flag1 + Huffman codes
  always return 1

bytes:
  85 DB                 TEST EBX,EBX
  8B F8                 MOV EDI,EAX
  8B 6C 24 0C           MOV EBP,[ESP+0C]  ; maxLen
  80 3D 28 7A D1 00 00  CMP [DAT_00d17a28],0
  8B 2D BC EA D1 00     alphabet DAT_00d1eabc (in cost loop)
  B0 01 … C3            return 1; RET
```

**No conflict** on owned CF. Completes gap noted in `BitStream_writeStringCached` dual (Huffman alphabet unit).

---

## 4. Surviving contract for AutoCore

```csharp
// BitStream_writeString @ 0x0077d960
// retail: EAX = BitStream, EBX = str, stack maxLen, RET (caller cleans 4)
// always returns 1

bool WriteString(BitStream bs, string? str, uint maxLen)
{
  // Implement flag + raw/Huffman exactly.
  // Do NOT treat as writeStringCached (no prefix/cache here).
  // Equality on cost → raw path.
}
```

---

## 5. Residual risks

1. `FUN_0077d520` builder correctness assumed, not dual-sealed here.
2. Interaction when cached wrapper passes residual `maxLen = len - prefixLen` — must not re-scan prefix (caller responsibility).
3. Inline flag-bit write vs sealed `writeFlag` helper — behaviorally equivalent if capacity/grow match; ports may call either if identical.
4. No runtime hit confirmation in this dual.

**Verdict:** **accept-with-gaps**
