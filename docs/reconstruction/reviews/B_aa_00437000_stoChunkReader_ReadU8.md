# Review B (skeptical / adversarial): `aa_00437000` stoChunkReader_ReadU8

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437000` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00437000_stoChunkReader_ReadU8.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `force_decompile` + `read_memory` (body + call sites). No `disassemble_bytes`. Own VA `0x00437000` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` with reader/window in **ECX** | Body: `mov esi,eax` then `add esi,0x14`; ECX only for ensure thiscall | **Falsified** as thiscall-of-self — **EAX reader + EDI out** |
| 2 | Same stack-out + RET 4 ABI as ReadU32 | ReadU32: push out / `C2 04 00`; this: EDI / bare `C3` | **Falsified equality** — related window, **different ABI** |
| 3 | Same ESI=window entry as ReadCString / ReadHeader16 | This remaps from EAX reader; ReadCString takes ESI window directly | **Partial** — same window layout, **different entry reg** |
| 4 | Reads 4 bytes / dword | Copy is one byte; cursor `+= 1`; `cmp available,1` | **Falsified** — **1 byte** |
| 5 | Always calls ensure | Ensure only when `available < cursor+1` (`jle` skip) | **Falsified** — **conditional** |
| 6 | Ensure is stdcall with window on stack | `mov ecx,esi; push abs; call` | **Falsified** — **thiscall ensure** |
| 7 | Post-ensure re-check uses `cursor+1` again | Bytes: `cmp [esi+0xc], 1` only | **Partial note** — re-check is **available ≥ 1**, not `≥ cursor+1` |
| 8 | Fail leaves *out untouched | Fail: `mov cl,[esp+7]; mov [edi],cl` | **Falsified untouched** — **does write**; value is spill |
| 9 | Fail *out is intentional default 0 | Value is high byte of entry ECX push slot | **Falsified as default 0** — **unreliable spill** |
| 10 | Fail returns 0 / success returns 1 | Fail `or eax,-1` / success `xor eax,eax` | **Falsified** — **0 / −1** |
| 11 | Decompiler `__fastcall param_1` is real formal | Call sites pass out in EDI; param_1 is ECX spill artifact | **Falsified** as product arg |
| 12 | Text-mode path also uses this unit directly | Dispatcher gates `reader+0x4044`; text → `FUN_00769660` | **Falsified** as text leaf — **binary leaf** |
| 13 | Scaffold `Named_CalleeOf_Named_gfxBody_*` is product name | No PDB/plate; structural width name | **Reject scaffold** |
| 14 | Three-rep diverges | live ≡ force ≡ raw; bytes restore ESI remap | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX=reader, EDI=out, bare RET, 0/−1 | **High** | Wrong out / stack smash |
| Conditional ensure + fail gates | **High** | Truncated stream false success |
| 1 B copy + cursor+=1 | **High** | Stream desync |
| Window +4/+8/+c/+18 via reader+0x14 | **High** | Wrong buffer/cursor |
| Post-ensure available≥1 vs cursor-relative | **High** (as coded) | Port re-check bug |
| Fail *out is non-product spill | **High** | Port inventing defaults |
| Product English U8 vs bool | **Probable** | Doc-only mislabel |
| Ensure body | **Out of scope** | Refill bugs → `FUN_00435df0` |
| Runtime / bit-exact | **Open** | Shipping binary load |

---

## 3. Cross-check against raw + bytes

```
raw / live / force decompile:
  if (avail < cursor+1) {
    hr = FUN_00435df0(base+cursor); // ECX=window
    if (hr < 0 || avail < 1) { *out = spill; return -1; }
  }
  *out = *(u8*)(reader + 0x2c + cursor)
  cursor += 1
  return 0

bytes:
  51 56 8BF0 8B4618 83C614 8D4801 3B4E0C 7E23
  8B5608 03D0 52 8BCE E8… 85C0 7C06 837E0C01 7D0C
  8A4C2407 83C8FF 880F 5E 59 C3
  8B4604 8A4C3018 83C001 894604 33C0 880F 5E 59 C3

call site dispatcher:
  cmp [eax+4044],0 / mov edi,ecx / call (EAX=reader)
call site direct:
  lea edi, local / mov eax, reader / call
```

**No conflict** on owned CF. Ensure internals not re-proven here. Decompiler fastcall formal **rejected**.

---

## 4. Surviving contract for AutoCore

```csharp
// stoChunkReader_ReadU8 @ 0x00437000
// retail: EAX = reader, EDI = out u8*, bare RET

int ReadU8(StoChunkReader reader, out byte value)
{
    var w = reader.Window; // reader+0x14
    int cursor = w.Cursor;
    if (w.Available < cursor + 1)
    {
        int hr = EnsureWindow(w, w.Base + cursor); // FUN_00435df0
        if (hr < 0 || w.Available < 1)
        {
            // retail writes spill to *out; port: leave value unspecified
            value = 0;
            return -1;
        }
        cursor = w.Cursor;
    }
    value = w.Buffer[cursor];
    w.Cursor = cursor + 1;
    return 0;
}
```

---

## 5. Gaps that survive attack

1. Product/PDB English (U8 vs bool — text peer logs "Expected bool").
2. Ensure refill semantics — other VA.
3. Caller dependence on fail-path `*out` (none expected).
4. Runtime / bit-exact / differential.

**Verdict after attack:** ABI + CF + window map sealed; fail spill documented. **accept-with-gaps.**
