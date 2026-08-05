# Review B (skeptical / adversarial): `aa_00437050` stoChunkReader_ReadU32

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437050` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00437050_stoChunkReader_ReadU32.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `force_decompile` + `read_memory` (body + call sites). No `disassemble_bytes`. Own VA `0x00437050` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` with reader/window in **ECX** | Body: `mov esi,eax` then `add esi,0x14`; no ECX setup for self; stack out via `[esp+8]` | **Falsified** as thiscall-of-self — **EAX reader + stack out + RET 4** |
| 2 | Same ESI/EDI register ABI as ReadHeader16 | ReadHeader16 uses ESI=window, EDI=out[4], plain RET; this uses EAX + stack + RET 4 | **Falsified equality** — related window, **different ABI** |
| 3 | Reads 16 bytes / full header | Copy is one dword; cursor `+= 4`; `cmp available,4` | **Falsified** — **4 bytes** |
| 4 | Always calls ensure | Ensure only when `available < cursor+4` (`jle` skip) | **Falsified** — **conditional** |
| 5 | Ensure is stdcall with window on stack | `mov ecx,esi; push abs; call` | **Falsified** — **thiscall ensure** |
| 6 | Post-ensure re-check uses `cursor+4` again | Bytes: `cmp [esi+0xc], 4` only | **Partial note** — re-check is **available ≥ 4**, not `≥ cursor+4` |
| 7 | Fail returns 0 / success returns 1 | Fail `or eax,-1` / success `xor eax,eax` | **Falsified** — **0 / −1** |
| 8 | Plain `RET` (0 stack args) | Epilogue `C2 04 00` | **Falsified** — **`RET 4`** |
| 9 | Window is full reader object for ensure | `add esi,0x14` before ensure ECX | **Falsified** — **window @ reader+0x14** |
| 10 | Text-mode path also uses this unit directly | Dispatcher gates `reader+0x4044`; text → `FUN_007689e0` | **Falsified** as text leaf — **binary leaf** |
| 11 | Three-rep diverges | live ≡ force ≡ raw ≡ bytes CF | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX=reader, stack out, RET 4, 0/−1 | **High** | Stack smash / wrong out store |
| Conditional ensure + fail gates | **High** | Truncated stream false success |
| 4 B copy + cursor+=4 | **High** | Stream desync |
| Window +4/+8/+c/+18 via reader+0x14 | **High** | Wrong buffer/cursor |
| Post-ensure available≥4 vs cursor-relative | **High** (as coded) | Port re-check bug |
| Product English U32 vs I32 | **Probable** | Doc-only mislabel |
| Ensure body | **Out of scope** | Refill bugs → `FUN_00435df0` |
| Runtime / bit-exact | **Open** | Shipping binary load |

---

## 3. Cross-check against raw + bytes

```
raw / live / force decompile:
  if (avail < cursor+4) {
    hr = FUN_00435df0(base+cursor); // ECX=window
    if (hr < 0 || avail < 4) return -1;
  }
  *out = *(u32*)(reader + 0x2c + cursor)
  cursor += 4
  return 0

bytes:
  56 8BF0 8B4618 83C614 8D4804 3B4E0C 7E1E
  8B5608 03D0 52 8BCE E8… 85C0 7C06 837E0C04 7D07
  83C8FF 5E C20400
  8B4604 8B4C3018 8B542408 890A 83460404 33C0 5E C20400

call site dispatcher:
  cmp [eax+4044],0 / push out / call (EAX=reader)
call site OpenChunk binary:
  push stack out / mov eax,ebp / call / or sticky
```

**No conflict** on owned CF. Ensure internals not re-proven here.

---

## 4. Surviving contract for AutoCore

```csharp
// stoChunkReader_ReadU32 @ 0x00437050
// retail: EAX = reader, stack = out u32*, RET 4

int ReadU32(StoChunkReader reader, out uint value)
{
    var w = reader.Window; // reader+0x14
    int cursor = w.Cursor;
    if (w.Available < cursor + 4)
    {
        int hr = EnsureWindow(w, w.Base + cursor); // FUN_00435df0
        if (hr < 0 || w.Available < 4) { value = 0; return -1; }
        cursor = w.Cursor;
    }
    value = BitConverter.ToUInt32(w.Buffer, cursor); // window+0x18+cursor
    w.Cursor = cursor + 4;
    return 0;
}
```

---

## 5. Gaps that survive attack

1. Product English name / signedness.
2. Ensure body not owned.
3. No runtime / bit-exact seal.

**Verdict:** adversarial pass does not overturn A. **accept-with-gaps.**
