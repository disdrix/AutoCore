# Review B (skeptical / adversarial): `aa_004370b0` stoChunkReader_EnterChunkScope

| Field | Value |
|---|---|
| **Stable ID** | `aa_004370b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004370b0_stoChunkReader_EnterChunkScope.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` / `force_decompile` + `read_memory` (body + call sites). No `disassemble_bytes`. Own VA `0x004370b0` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `this` is the **reader** (name `stoChunkReader_Enter…` suggests method-on-reader) | Entry `mov esi,ecx` then `[esi]=reader` from stack; OpenChunk gets ECX=reader after reload | **Falsified** — **this = scope\***; reader is stack arg |
| 2 | Signature is freestanding `(reader)` only as Ghidra call sites print | Callers: `sub esp,0x14`; `push reader`; `lea ecx, scope`; `call`; epilogue **`RET 4`** | **Falsified** — **thiscall(scope, reader)** |
| 3 | Two stack args / stdcall | **`C2 04 00`** | **Falsified** — one stack dword |
| 4 | `okFlag` means “opened a nested child” vs OpenChunk success | `test eax,eax` / `setge al` / `mov [esi+8],al` immediately after OpenChunk | **Falsified alternate** — **ok = OpenChunk ≥ 0** (0 success, −1 fail) |
| 5 | Early return on OpenChunk fail skips ring fill | Linear CF; tag/version always written after OpenChunk | **Falsified** — **always fills** |
| 6 | `param_1[2]` as int write for okFlag | Byte store `88 46 08`; decompiler `*(bool*)(param_1+2)` is int*-index +2 = +8 | **Falsified as 32-bit store** — **u8 at +8** |
| 7 | Tag is FOURCC characters in file order from text path only | Tag = `*entry` dword 0 after OpenChunk (binary or text already normalized on ring) | **Falsified exclusivity** — this unit is **mode-agnostic** |
| 8 | Version at entry `+4` (next header word = size) | Bytes: `mov edx,[ecx+8]` after loading entry | **Falsified** — version at **entry+8** (matches OpenChunk header words tag/size/**version**/…) |
| 9 | Ring base is `reader+0x4034` | Bytes: `add eax, 0x4030` then `+4/+8/+c/+10` | **Partial** — bookkeeping at `+4034..4040`; **object base +4030** |
| 10 | Wrap uses signed compare | `cmp capacity, idx` / `ja` (unsigned above) then `sub` | **Sealed as unsigned wrap** |
| 11 | `endPos` is chunk end (size-inclusive) | Formula is **only** `+0x1c + +0x18` (no size word); leave seeks via entry `+0x10` | **Falsified as chunk-end** — absolute **cursor/base sum** at enter |
| 12 | Three-rep diverges | force_decompile ≡ raw ≡ first live decompile; bytes match | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall scope + reader + RET 4 | **High** | Stack smash / wrong ECX in every Unserialize |
| Scope size 0x14; fields +0/+4/+8/+c/+10 | **High** | Tag compares read wrong dword |
| okFlag = OpenChunk signed ≥ 0 (byte) | **High** | Skip leave → stream desync |
| Ring wrap index formula | **High** | Wrong tag/version on nested opens |
| Tag @ entry+0, version @ entry+8 | **High** | FOURCC / version gates fail |
| absPos = `+0x1c + +0x18` | **High** (formula) | Wrong seek if port uses field as chunk end |
| absPos English = “end of chunk” | **Low–Medium** | Doc-only; leave does not use this field for seek |
| Ring entry full layout | **Probable** (sibling OpenChunk) | Nested leave/size bugs |
| OpenChunk fail ring contents | **Medium** | Ports that still trust tag when okFlag=0 |
| Runtime / bit-exact | **Open** | Shipping asset load |

---

## 3. Cross-check against raw + bytes

```
raw / force_decompile:
  *scope = reader;
  ok = OpenChunk() >= 0;          // decomp: *(bool*)(scope+2) = -1 < hr
  absPos = reader[0x1c] + reader[0x18];
  idx = wrap( (0x4040)+(0x403c)-1 , capacity 0x4038 );
  tag = **(entries + idx);
  version = *(*(entries + idx) + 8);
  return scope;

bytes:
  entry: 56 8BF1 8B4C2408 57 890E E8… 85C0 0F9DC0 884608 …
  ring:  0530400000 (add eax,4030) then +10/+0c wrap vs +8, load [+4] array
  tag:   8B11 89560C
  ver:   8B5108 5F 895610 8BC6 5E C20400

call sites:
  push reader; lea ecx, [esp+scope]; call; cmp [esp+tag_slot], FOURCC
```

**No conflict** among raw, force_decompile, and body/call-site bytes on sealed CF.

---

## 4. Surviving contract for AutoCore

```csharp
// stoChunkReader_EnterChunkScope @ 0x004370b0
// this = scope (stack-allocated 0x14), stack arg = reader
// returns scope*

struct ChunkScope {
    StoChunkReader* Reader;  // +0x00
    int AbsPos;              // +0x04  // reader[+0x1c]+reader[+0x18]; not chunk-end
    byte OkFlag;             // +0x08  // OpenChunk() >= 0
    // pad 3
    uint TagFourCC;          // +0x0c
    uint Version;            // +0x10
}; // sizeof = 0x14

ChunkScope* EnterChunkScope(ChunkScope* scope, StoChunkReader* reader)
{
    scope->Reader = reader;
    int hr = OpenChunk(reader);          // 0 ok, -1 fail
    scope->OkFlag = (hr >= 0) ? 1 : 0;

    scope->AbsPos = reader.Base /*+0x1c*/ + reader.Cursor /*+0x18*/;

    // ring at reader+0x4030
    uint idx = (uint)(reader.RingWrite /*+4040*/ + reader.RingBase /*+403c*/ - 1);
    if (idx >= reader.RingCapacity /*+4038*/)
        idx -= reader.RingCapacity;

    var entry = reader.RingEntries /*+4034*/[idx];
    scope->TagFourCC = entry.Tag;        // +0
    scope->Version   = entry.Version;    // +8
    return scope;
}
```

Port notes:

- **Always** pair with leave when `OkFlag != 0` (retail uses `FUN_00769e40(reader)`).
- Do **not** treat Ghidra’s single-arg call prints as the full ABI.
- Do **not** use `AbsPos` as chunk-end without separate ring size/end evidence.
- Tag/version remain readable even when `OkFlag==0` — callers typically check tag first then leave only if ok.

---

## 5. Open questions

1. Exact retail name of `scope[+4]` (plate endPos vs bodyStart).
2. Full ring entry fields beyond tag@0 / version@8 (size, reserved, end@+0x10 from leave).
3. Guaranteed ring state when OpenChunk fails (empty capacity? sticky-only?).
4. Live runtime confirmation on `autoassault.exe`.

**Verdict:** **accept-with-gaps**
