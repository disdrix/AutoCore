# Review B (skeptical / adversarial): `aa_0042b980` BitStream_writeQuantizedSignedInt

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b980` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0042b980_BitStream_writeQuantizedSignedInt.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This unit quantizes floats | No float ops; only flag + bits | **Falsified** — float math is parent `0x0042b910` |
| 2 | Plain `__fastcall(int)` complete ABI | Missing EDI this + AL bitCount | **Over-narrow** decompiler display |
| 3 | Writes full `bitCount` magnitude bits | Body uses `bitCount-1` | **Falsified** full-width claim |
| 4 | Masks magnitude like read path | No `(1<<w)-1` mask on write | **Falsified** symmetry — write unmasked |
| 5 | Multiple callers | Ghidra xrefs **1** (`writeQuantizedFloat`) | **Only one** call site |
| 6 | Returns written bit count / bool | Epilogue void; no result | **Falsified** if claimed return |
| 7 | `writeFlag` return ignored | `TEST AL` branches on return | **Falsified** ignore claim — branch uses return |
| 8 | Name `writeQuantizedSignedInt` wrong | Mirrors `readQuantizedSignedInt` @ `0x0042b9d0`; sign+magBits pattern | **Survives** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Sign flag + magBits write | **High** | Wire desync / prediction |
| ABI EDI/ECX/AL | **High** | Wrong call sites in ports |
| No write mask | **High** | Over-masking would alter packets if value out of range |
| Sole caller path | **High** | Missing alternate packers (none found) |
| INT_MIN edge | **Medium** | Rare pathological quantize |

---

## 3. Cross-check against raw / bytes

```
raw: writeFlag(param_1 < 0); if: neg; writeBits(in_AL-1,&local); else writeBits(in_AL-1,&local)
bytes: SETL; CALL writeFlag; SUB BL,1; JZ pos; NEG ESI; CALL writeBits; RET / pos path
```

Clean ≡ raw ≡ bytes. No modernization of CF.

---

## 4. Surviving contract for AutoCore

```csharp
// Integer stage only — parent must quantize float first:
//   max = (1 << (bitCount - 1)) - 1;
//   int q = (int)Truncate(value * max);
static void WriteQuantizedSignedInt(BitStream stream, int value, byte bitCount)
{
    bool neg = value < 0;
    stream.WriteFlag(neg);
    int mag = neg ? -value : value; // retail 2's complement NEG
    stream.WriteBits(checked((byte)(bitCount - 1)), mag);
    // do NOT mask mag on write
}
```

**Port traps to reject:**

- Implementing float scale inside this function.
- Using `bitCount` (not `bitCount-1`) for magnitude.
- Applying read-side mask on write.
- Assuming `thiscall` ECX=stream on entry (entry stream is **EDI**).

---

## 5. Residual gaps (do not block seal)

1. Live packet differential vs retail.
2. INT_MIN documentation only.
3. Parent `writeQuantizedFloat` dual refresh (out of ownership).

---

## Verdict

**accept** — adversarial review cannot break the sign-flag + `(bitCount-1)` magnitude write kernel. Main falsifications are “float writer” and “full ABI is single ECX int.”
