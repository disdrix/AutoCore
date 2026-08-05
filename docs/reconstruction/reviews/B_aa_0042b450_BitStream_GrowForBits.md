# Review B (skeptical / adversarial): `aa_0042b450` BitStream_GrowForBits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b450` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0042b450_BitStream_GrowForBits.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is a pure `__fastcall(int)` with ECX=this | Decomp shows `__fastcall(int)` only; body uses **EDI** as object | **Over-narrow** — this is residual register ABI, not MSVC thiscall |
| 2 | NewSize = `(extra + 7 + (cap>>3)) + 0x5DC` | Literal C parse of decompiler | **Falsified** — bytes `((extra+cap+7)>>3)+0x5DC` |
| 3 | Always grows when called | Callers only call when bitCap exceeded; unit may still fail | **Survives** with fail paths |
| 4 | Return is full EAX bitCap masked | Decomp `return bitCap & 0xffffff00` | **Overstated** — bytes `XOR AL,AL` / `MOV AL,1`; bool in AL |
| 5 | CONCAT31 success return is meaningful | Decomp artifact | **Falsified** — only AL=1 matters |
| 6 | realloc failure handled | No test of EAX after call | **Falsified** if claimed safe — NULL stored, still returns 1 |
| 7 | +0x10 is bit capacity | Compared to byte NewSize; success sets bit caps elsewhere | **Falsified** — +0x10 is **bytes** |
| 8 | Name GrowForBits wrong | Matches writeBits/writeFlag “grow” role; only realloc grow in unit | **Survives** as role name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI this + ECX extraBits | **High** | Silent wrong buffer / wrong size math |
| Formula +0x5DC slack | **High** | Buffer underrun or over-alloc |
| Bool return AL | **High** | writeBits clamps bitPos on fail |
| owns (+0x14) gate | **High** | Crash realloc on foreign buffer |
| realloc NULL hole | **High** (bug-shaped) | Client crash on OOM if hit |
| Product name | **Tentative** | Naming only |

---

## 3. Cross-check against raw / bytes

```
raw decomp: NewSize=(param_1+7+cap>>3)+0x5dc; if byteSize<NewSize && owns: realloc; caps; return 1; else error return 0
bytes:      lea esi,[ecx+eax+7]; shr 3; add 0x5DC; jb realloc path; else fail
named clean: parenthesized formula + AL returns
```

Twin `FUN_0042b450.cpp` keeps decompiler surface **including** the precedence hazard (documented). Named plate is authoritative for ports.

---

## 4. Surviving contract for AutoCore

```csharp
// Not standard thiscall — stream in EDI-equivalent explicit arg:
static bool GrowForBits(BitStream stream, int extraBits)
{
    // bitCap from stream capacity field (+0x30)
    uint newSize = ((uint)(extraBits + stream.BitCapacity + 7) >> 3) + 0x5DCu;
    if (stream.ByteSize < newSize)
    {
        if (!stream.OwnsBuffer)
        {
            stream.ByteSize = newSize;
            stream.ErrorFlag = true;
            return false;
        }
        stream.ByteSize = newSize;
        stream.Buffer = Realloc(stream.Buffer, newSize); // retail does not null-check
        int bits = (int)(newSize * 8);
        stream.BitCapMirror = bits;
        stream.BitCapacity = bits;
        return true;
    }
    stream.ByteSize = newSize;
    stream.ErrorFlag = true;
    return false;
}
```

**Port traps to reject:**

- Using decompiler C formula without parentheses.
- Treating unit as `thiscall` with ECX=stream.
- Ignoring fail → writeBits clamps cursor to capacity.
- Assuming realloc failure returns 0 (retail does not check).

---

## 5. Residual gaps (do not block seal)

1. Live OOM / fixed-buffer capture.
2. TNL source symbol match.
3. Whether any caller expects non-bool EAX upper bits (none found).

---

## Verdict

**accept** — adversarial review breaks decompiler formula precedence and thiscall-looking surface, but strengthens the byte-sealed grow contract. Cannot break EDI/ECX/AL, +0x5DC slack, or owns-gated realloc path.
