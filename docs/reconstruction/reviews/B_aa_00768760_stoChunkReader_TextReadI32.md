# Review B (skeptical / adversarial): `aa_00768760` stoChunkReader_TextReadI32

| Field | Value |
|---|---|
| **Stable ID** | `aa_00768760` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00768760_stoChunkReader_TextReadI32.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + xrefs. No `disassemble_bytes`. Own VA `0x00768760` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as binary ReadU32 | Body tokenizes chars, quotes, `isspace`, signed parse | **Falsified** as binary leaf — **text leaf** |
| 2 | Same as TextReadU32 | `FUN_00767600(...,1)` + `"Expected int32"` | **Falsified** equality — **signed** |
| 3 | `__thiscall` ECX=reader | No ECX this; EDI + stack out + RET 4 | **Falsified** |
| 4 | Always scans stream | `+0x4060` nonzero → pushback path | **Falsified** as always-scan |
| 5 | Success returns 1 / bool | Success return 0; fail `OR EAX,-1` | **Falsified** — **0 / −1** |
| 6 | Plain RET (0 stack args) | `C2 04 00` | **Falsified** — **`RET 4`** |
| 7 | `"}"` is numeric zero | Special branch past-end sticky −1 | **Falsified** |
| 8 | Product name is in EXE as symbol | Only path/error strings | **Survives** as **Inferred** |
| 9 | Three-rep diverges | live ≡ raw ≡ bytes CF | **Falsified** |
| 10 | Only few callers | 98 xrefs | **Falsified** sparsity |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI reader, stack out, RET 4, 0/−1 | **High** | Stack smash / wrong status |
| signedMode=1 / int32 plate | **High** | Wrong signedness |
| Token scan + quote/ws | **High** | Desync text stream |
| Pushback `+0x404c` / `+0x4060` | **High** | Double-consume / drop token |
| Parse radix / overflow | **Probable** | Wrong values |
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
  else if FUN_00767600(out,4,1) >= 0: return 0
  fail: format Expected int32…; log line 0x414; return -1

epilogue bytes @ 0x007689C0:
  83C8FF           or  eax,-1
  5B               pop ebx
  64890D00000000   restore FS:ExceptionList
  83C44C           add esp,0x4C
  C20400           ret 4
```

**No conflict** on owned CF. Parse helper internals not re-proven.

---

## 4. Surviving contract for AutoCore

```csharp
// stoChunkReader_TextReadI32 @ 0x00768760
// retail: EDI = reader, stack = out i32*, RET 4

int TextReadI32(StoChunkReader reader, out int value)
{
    if (reader.Status < 0) goto fail;
    string token;
    if (!reader.PushbackActive)
        token = ScanToken(reader); // ws / quotes / ensure
    else {
        token = reader.Pushback;
        reader.Pushback = "";
    }
    if (token == "}") {
        LogPastEnd();
        reader.Status = -1;
        reader.Pushback = token;
        goto fail;
    }
    if (ConvertToInteger(token, out value, byteLen: 4, signedMode: 1) >= 0)
        return 0;
fail:
    Log($"Expected int32 but got \"{token}\" in chunk \"{ChunkName}\"");
    return -1;
}
```

---

## 5. Verdict

**accept-with-gaps** — CF sealed; name Inferred from plate; unowned helpers open.
