# Review B (skeptical / adversarial): `aa_00436f10` stoChunkStreamWindow_ReadCString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436f10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00436f10_stoChunkStreamWindow_ReadCString.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `force_decompile` + `read_memory` (body + call sites). No `disassemble_bytes`. Own VA `0x00436f10` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` with window in **ECX** | Body: `mov ecx,edi` only for string methods; window stays in ESI; no ECX-this for self | **Falsified** as thiscall-of-window — **ESI window + EDI string** |
| 2 | Full stoChunkReader* in ESI | Callers `lea esi, [reader+0x14]`; body uses window offsets (+4/+8/+c/+14/+18) | **Falsified** as full reader — **window*** |
| 3 | Length-prefixed string (u16/u32 len then bytes) | Loop until NUL or streamEnd; no length load | **Falsified** — **NUL-terminated** |
| 4 | NUL left in stream / not consumed | `cursor++` before `test cl,cl` / jz success | **Falsified** — **NUL consumed** |
| 5 | NUL appended to std::string | jz success **before** `operator+=` | **Falsified** — payload only |
| 6 | No streamEnd check (only available) | Pre-check + continue compare `cursor+base` vs `[esi+0x14]` | **Falsified** — **streamEnd gated** |
| 7 | Always calls ensure | Ensure only when `available < cursor+1` | **Falsified** — **conditional** |
| 8 | Fail returns 0 / success returns 1 | Fail `or eax,-1` / success `xor eax,eax` | **Falsified** — **0 / −1** |
| 9 | Stack args + RET n | Epilogue bare `C3` twice | **Falsified** — **bare RET** |
| 10 | Text-mode path uses this unit | Wrappers gate `+0x4044`; text → `FUN_0076a200` | **Falsified** as text leaf — **binary leaf** |
| 11 | Scaffold `Named_CalleeOf_Named_assId_*` is product name | No PDB/plate; structural name from CF | **Reject scaffold** |
| 12 | Three-rep diverges | live ≡ force ≡ raw ≡ bytes CF | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI=window, EDI=string*, bare RET, 0/−1 | **High** | Wrong dest / stack smash |
| streamEnd loop + NUL consume | **High** | Truncation / desync |
| Conditional ensure + fail gates | **High** | False success on short stream |
| Window field map | **High** | Wrong buffer/cursor |
| Product English CString label | **Probable** | Doc-only mislabel |
| Ensure body | **Out of scope** | Refill bugs → `FUN_00435df0` |
| Runtime / bit-exact | **Open** | Shipping binary load |

---

## 3. Cross-check against raw + bytes

```
raw / live / force decompile:
  resize(out, 0)
  if (cursor+base >= streamEnd) return -1
  do {
    if (avail < cursor+1) {
      hr = FUN_00435df0(base+cursor) // ECX=window
      if (hr < 0 || avail < 1) return -1
    }
    c = *(u8*)(window+0x18+cursor); cursor++
    if (c == 0) return 0
    out += c
  } while (cursor+base < streamEnd)
  return -1

bytes:
  51 6A00 8BCF FF15…resize
  8B4604 034608 3B4614 7D4D
  loop: ensure gate → 8A4C3018 83C001 … 74 success → operator+= → 7CB3
  83C8FF 59 C3 / 33C0 59 C3

call sites:
  lea esi, [reader+0x14]; lea/mov edi, string*; call
  mode: cmp [reader+4044],0
```

**No conflict** on owned CF. Ensure internals not re-proven here.

---

## 4. Surviving contract for AutoCore

```csharp
// stoChunkStreamWindow_ReadCString @ 0x00436f10
// retail: ESI = window, EDI = std::string*, bare RET

int ReadCString(StoStreamWindow w, out string value)
{
    value = "";
    if (w.Cursor + w.Base >= w.StreamEnd) return -1;
    do
    {
        if (w.Available < w.Cursor + 1)
        {
            int hr = EnsureWindow(w, w.Base + w.Cursor); // FUN_00435df0
            if (hr < 0 || w.Available < 1) return -1;
        }
        byte c = w.Buffer[w.Cursor++];
        if (c == 0) return 0; // NUL consumed
        value += (char)c;
    } while (w.Cursor + w.Base < w.StreamEnd);
    return -1;
}
```

---

## 5. Gaps that survive attack

1. Product/PDB English (CString vs String vs StringZ).
2. Ensure refill semantics — other VA.
3. streamEnd when unknown length.
4. Runtime / bit-exact / differential.

**Verdict after attack:** ABI + CF + NUL/streamEnd sealed. **accept-with-gaps.**
