# Review B (skeptical / adversarial): `aa_004368b0` stoChunkStreamWindow_ReadHeader16

| Field | Value |
|---|---|
| **Stable ID** | `aa_004368b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004368b0_stoChunkStreamWindow_ReadHeader16.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + OpenChunk call site). No `disassemble_bytes`. Own VA `0x004368b0` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` with window in **ECX** as sole arg | Body uses **ESI/EDI**; ECX only set for nested ensure call | **Falsified** as thiscall-of-self — **ESI/EDI register pair** |
| 2 | Reads 8 or 12 byte headers | Copy is exactly 4 dwords; cursor `+= 0x10` | **Falsified** — **16 bytes** |
| 3 | Copies via `memcpy` / byte loop | Four explicit dword loads/stores | **Falsified style** — still 16 B dword copy |
| 4 | Fail returns 0 / success returns 1 | Fail `or eax,-1` / success `xor eax,eax` | **Falsified** — **0 / −1** |
| 5 | Always calls ensure | Ensure only when `available < cursor+16` (`jle` skip) | **Falsified** — **conditional** |
| 6 | Ensure is stdcall with window on stack | `mov ecx,esi; push abs; call` | **Falsified** — **thiscall ensure** |
| 7 | Post-ensure re-check uses `cursor+16` again | Bytes: `cmp [esi+0xc], 0x10` only | **Partial note** — re-check is **available ≥ 16**, not `≥ cursor+16` |
| 8 | Used on text OpenChunk path | OpenChunk mode gate `jnz text` before lea esi/edi | **Falsified** — **binary only** |
| 9 | Multiple callers | xrefs/callers → sole OpenChunk | **Falsified multiplicity** |
| 10 | Window is full reader object | Caller `lea esi,[ebp+0x14]` | **Falsified** — **window @ reader+0x14** |
| 11 | Three-rep diverges | live decompile ≡ raw ≡ bytes CF | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI=window, EDI=out[4], RET, 0/−1 | **High** | Header parse / stack corruption |
| Conditional ensure + fail gates | **High** | Truncated chunk false success |
| 16 B copy + cursor+=16 | **High** | Stream desync |
| Window +4/+8/+c/+18 map | **High** | Wrong buffer/cursor |
| Header field English names | **Probable** | Doc-only mislabel (order sealed) |
| Post-ensure available≥16 vs cursor-relative | **High** (as coded) | Port that re-checks wrong predicate |
| Ensure body | **Out of scope** | Refill bugs belong to `FUN_00435df0` |
| Runtime / bit-exact | **Open** | Shipping binary load |

---

## 3. Cross-check against raw + bytes

```
raw / live decompile:
  if (avail < cursor+0x10) {
    hr = FUN_00435df0(base+cursor); // ECX=ESI
    if (hr < 0 || avail < 0x10) return -1;
  }
  copy 4 dwords from ESI+0x18+cursor → EDI
  cursor += 0x10
  return 0

bytes:
  8B4604 8D4810 3B4E0C 7E1B … E8… 85C0 7C06 837E0C10 7D04 83C8FF C3
  8B4604 8D4C0618 8B11 8917 8B4104 894704 8B5108 895708 8B410C 89470C
  83460410 33C0 C3

call site OpenChunk binary:
  lea esi,[ebp+14]; lea edi,[esp+18]; call; or sticky; jl fail
```

**No conflict** on owned CF. Ensure internals not re-proven here.

---

## 4. Surviving contract for AutoCore

```csharp
// stoChunkStreamWindow_ReadHeader16 @ 0x004368b0
// retail: ESI = window (reader+0x14), EDI = out u32[4]

int ReadHeader16(StoStreamWindow w, Span<uint> out4)
{
    if (w.Available < w.Cursor + 0x10)
    {
        int hr = EnsureWindow(w, w.Base + w.Cursor); // FUN_00435df0
        if (hr < 0 || w.Available < 0x10)
            return -1;
    }
    var src = MemoryMarshal.Cast<byte, uint>(
        w.Buffer.Slice(w.Cursor, 0x10)); // buffer @ window+0x18
    out4[0] = src[0];
    out4[1] = src[1];
    out4[2] = src[2];
    out4[3] = src[3];
    w.Cursor += 0x10;
    return 0;
}
```

Port notes:

- OpenChunk sticky-ORs return into `reader+0x402c` and treats signed &lt; 0 as fail.
- Do **not** call from text mode (text uses token path).
- After ensure, match retail re-check (`available < 16` → fail), not a re-run of `available < cursor+16`, unless ensure is proven to always zero cursor on success.
- Header words feed ring push as tag/size/version/reserved (sibling OpenChunk).

---

## 5. Gaps surviving review

1. Product plate name.
2. `FUN_00435df0` owned dual (ensure).
3. Runtime capture of short-buffer refill success/fail.
4. Bit-exact image diff.

---

## 6. Verdict

**accept-with-gaps** — adversarial ABI/size/path attacks fail; remaining risk is ensure callee + runtime only.
