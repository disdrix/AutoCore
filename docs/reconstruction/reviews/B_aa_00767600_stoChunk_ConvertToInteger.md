# Review B (skeptical / adversarial): `aa_00767600` stoChunk_ConvertToInteger

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767600` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00767600_stoChunk_ConvertToInteger.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory`. No `disassemble_bytes`. Own VA `0x00767600` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | C-string in ECX / stack only | SSO via **`[eax+0x18]`** | **Falsified** — **EAX string** |
| 2 | `ret` / cdecl 0 | `C2 0C 00` on exits | **Falsified** — **RET 12** |
| 3 | Supports hex (`0x…`) | only `isdigit` loop | **Falsified** — decimal only |
| 4 | Signed allows full two's min (e.g. −128) | abs check `0xffffff80` before neg | **Falsified** — max abs 127 for i8 |
| 5 | byteLen free / any size | switch default → log + −1 | **Falsified** — {1,2,4,8} only |
| 6 | Name invented | plate `ConvertToInteger()` | **Falsified** — **High** |
| 7 | Returns bool in AL only | `xor eax,eax` / `or eax,-1` | **Falsified** — full int32 0/−1 |
| 8 | live ≠ raw | decompile ≡ raw + strings | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX string + 3 stack + RET 12 | **High** | Wrong text reader ABI |
| Decimal parse + empty/− rules | **High** | Bad chunk load |
| Signed/unsigned range tables | **High** | Silent wrap / false reject |
| Product name | **High** | Naming only |
| Runtime | **Open** | Edge tokens |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  SSO [eax+0x18]<0x10 ? eax+4 : *[eax+4]
  empty → -1
  '-' → require signedMode else -1
  isdigit loop; val = val*10 + dig
  switch ranges; optional neg; memcpy out; return 0

bytes:
  83 78 18 10     ; cmp [eax+0x18], 0x10
  3C 2D           ; cmp al, '-'
  … isdigit / __allmul …
  C2 0C 00        ; ret 12
strings:
  "Invalid integer length in ConvertToInteger()"
  "…\storage\stoChunk.cpp"
```

**No conflict** on owned CF.

---

## 4. Surviving contract for AutoCore

```csharp
// stoChunk_ConvertToInteger @ 0x00767600
// retail: EAX=std::string*, stack (out, byteLen, signedMode), RET 12

int ConvertToInteger(string text, Span<byte> out, int byteLen, bool signedMode)
{
    if (string.IsNullOrEmpty(text) /* empty C-str */) return -1;
    // parse decimal; optional leading '-' if signedMode
    // range-check; write little-endian byteLen bytes
    return 0; // or -1
}

// Call shape from TextReadU32:
//   ConvertToInteger(token, out u32, 4, signed:false)
```

---

## 5. Verdict

Adversarial attacks on ABI, base, range, and name all fail against live bytes + plate strings → **accept**.
