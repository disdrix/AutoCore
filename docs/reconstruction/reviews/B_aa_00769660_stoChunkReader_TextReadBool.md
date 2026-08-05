# Review B (skeptical / adversarial): `aa_00769660` stoChunkReader_TextReadBool

| Field | Value |
|---|---|
| **Stable ID** | `aa_00769660` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00769660_stoChunkReader_TextReadBool.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + dispatcher). No `disassemble_bytes`. Own VA `0x00769660` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same ABI as binary bool reader (EAX reader) | Dispatcher moves reader to **EDI** before call; body uses `unaff_EDI` | **Falsified** equality — **EDI reader** here |
| 2 | This is a binary 1-byte reader | Body tokenizes chars, quotes, `isspace`, parse helper; error says bool string | **Falsified** as binary leaf — **text leaf** |
| 3 | `__thiscall` ECX=reader | No ECX this; EDI + stack out + RET 4 | **Falsified** |
| 4 | Always scans stream | `+0x4060` nonzero → assign from `+0x404c` pushback | **Falsified** as always-scan |
| 5 | Success returns 1 / C bool true | Success `xor eax,eax` / return 0; fail `or eax,-1` | **Falsified** — **0 / −1** |
| 6 | Plain RET (0 stack args) | `C2 04 00` | **Falsified** — **`RET 4`** |
| 7 | Parses via dedicated bool lexer (`true`/`false`) | Uses `ConvertToInteger(out,1,0)` — decimal integer byte | **Falsified** English "bool parser" — **integer-byte** |
| 8 | `"}"` is a valid false | Special branch logs past-end, sticky −1 | **Falsified** as numeric zero |
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
| `FUN_00767600(out,1,0)` success≥0 | **High** (shape) | Bad out write width |
| Accepts non-{0,1} decimal bytes | **Probable** | Surprising "bool" values |
| Product English | **Inferred** | Doc-only |
| Runtime | **Open** | Shipping load |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if status < 0 → fail
  if pushbackFlag==0: scan token (ensure, isspace, quotes)
  else: token = pushback; clear pushback
  if token=="}": log past-end; status=-1; pushback=token
  else if FUN_00767600(out,1,0) >= 0: return 0
  fail: format Expected bool…; log; return -1

dispatcher bytes @ 0x00439a50:
  83 B8 44 40 00 00 00   cmp [eax+0x4044],0
  57 8B F9               push edi / mov edi,ecx
  75 07                  jnz text
  E8 … C3                call binary FUN_00437000 / pop edi / ret
  57 8B F8 E8 … 5F C3    push out / mov edi,eax / call this / pop edi / ret

body epilogue:
  … C20400               ; ret 4
```

**No conflict** on owned CF. Parse helper internals not re-proven (owned by W25-R).

---

## 4. Surviving contract for AutoCore

```csharp
// stoChunkReader_TextReadBool @ 0x00769660
// retail: EDI = reader, stack = out byte*, RET 4

int TextReadBool(StoChunkReader reader, out byte value /* 0/1-style */)
{
    if (reader.Status < 0) goto fail;
    string token = reader.TakePushbackOrScanToken(); // quotes kept; same as TextReadU32
    if (token == "}") { reader.PastEndSticky(token); goto fail; }
    if (ConvertToInteger(token, out value, byteLen: 1, signed: false) >= 0)
        return 0;
fail:
    Log("Expected bool but got \"{0}\" in chunk \"{1}\"", token, reader.ChunkName);
    return -1;
}
```

Do **not** invent `true`/`false` keyword parsing unless ConvertToInteger is proven to accept them (it does not in W25-R seal — digits only).
