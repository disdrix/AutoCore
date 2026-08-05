# Review B (skeptical / adversarial): `aa_007689e0` stoChunkReader_TextReadU32

| Field | Value |
|---|---|
| **Stable ID** | `aa_007689e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007689e0_stoChunkReader_TextReadU32.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + dispatcher). No `disassemble_bytes`. Own VA `0x007689e0` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same ABI as binary ReadU32 (EAX reader) | Dispatcher moves reader to **EDI** before call; body uses `unaff_EDI` | **Falsified** equality — **EDI reader** here; binary uses **EAX** |
| 2 | This is the binary dword reader | Body tokenizes chars, quotes, `isspace`, parse helper; error says uint32 string | **Falsified** as binary leaf — **text leaf** |
| 3 | `__thiscall` ECX=reader | No ECX this; EDI + stack out + RET 4 | **Falsified** |
| 4 | Always scans stream | `+0x4060` nonzero → assign from `+0x404c` pushback | **Falsified** as always-scan |
| 5 | Success returns 1 / bool | Success `xor eax,eax` / return 0; fail `or eax,-1` | **Falsified** — **0 / −1** |
| 6 | Plain RET (0 stack args) | `C2 04 00` | **Falsified** — **`RET 4`** |
| 7 | Reads 4 binary bytes | No 4-byte memcpy; char token + parse | **Falsified** |
| 8 | `"}"` is a valid uint32 zero | Special branch logs past-end, sticky −1 | **Falsified** as numeric zero |
| 9 | Product name is in EXE as symbol | Only path/error strings; name is peer-inferred | **Survives** as **Inferred** |
| 10 | Three-rep diverges | live ≡ raw ≡ bytes CF | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI reader, stack out, RET 4, 0/−1 | **High** | Stack smash / wrong status |
| Mode peer via `+0x4044` dispatcher | **High** | Wrong path selection |
| Token scan + quote/ws | **High** | Desync text stream |
| Pushback `+0x404c` / `+0x4060` | **High** | Double-consume / drop token |
| `FUN_00767600(out,4,0)` success≥0 | **High** (shape) | Bad out write |
| Parse radix / overflow rules | **Probable** | Wrong values |
| Product English | **Inferred** | Doc-only |
| Ensure / parse bodies | **Out of scope** | Shared helpers |
| Runtime | **Open** | Shipping load |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if status < 0 → fail
  if pushbackFlag==0: scan token (ensure, isspace, quotes)
  else: token = pushback; clear pushback
  if token=="}": log past-end; status=-1; pushback=token
  else if FUN_00767600(out,4,0) >= 0: return 0
  fail: format Expected uint32…; log; return -1

dispatcher bytes @ 0x00436900:
  83B84440000000 7507 51 E8… C3     ; binary if mode==0
  57 51 8BF8 E8… 5F C3               ; text: EDI=reader, push out

body epilogue:
  … C20400                           ; ret 4
```

**No conflict** on owned CF. Parse helper internals not re-proven.

---

## 4. Surviving contract for AutoCore

```csharp
// stoChunkReader_TextReadU32 @ 0x007689e0
// retail: EDI = reader, stack = out u32*, RET 4

int TextReadU32(StoChunkReader reader, out uint value)
{
    if (reader.Status < 0) goto fail;
    string token;
    if (reader.PushbackActive == 0)
        token = ScanToken(reader); // ws/quote; ensure via FUN_00435df0
    else {
        token = reader.Pushback;
        reader.Pushback = "";
    }
    if (token == "}") {
        Log("Attempt to read past end of chunk…");
        reader.Status = -1;
        reader.Pushback = token;
    } else if (TryParseU32(token, out value)) { // FUN_00767600
        return 0;
    }
fail:
    Log(Format("Expected uint32 but got \"{0}\" in chunk \"{1}\"", token, ChunkName(reader)));
    value = 0;
    return -1;
}
```

---

## 5. Gaps that survive attack

1. **`FUN_00767600`** — exact parse (hex/dec, overflow, empty token).
2. **Product method name** — inferred; binary only has path + format strings.
3. **Quote outer-loop edge cases** — decompiler `while(true)`; intent sealed via goto exits.
4. **Ensure body** — `FUN_00435df0` shared with binary path.
5. **Runtime** — no live text-chunk differential.

None overturn sealed ABI / peer role / token CF.

---

## 6. Verdict

**accept-with-gaps** — text uint32 contract High; parse helper + English name gaps remain.
