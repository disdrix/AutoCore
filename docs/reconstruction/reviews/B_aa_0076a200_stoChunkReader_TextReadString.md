# Review B (skeptical / adversarial): `aa_0076a200` stoChunkReader_TextReadString

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076a200` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0076a200_stoChunkReader_TextReadString.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + call-site assembly context. No `disassemble_bytes`. Own VA `0x0076a200` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` ECX=reader | ECX is **out string**; reader is **EBX** | **Falsified** |
| 2 | Same EDI-out convention as ReadQuotedTag as the public ABI | Leaf uses ECX→EDI; public callers set EBX=reader | **Nuanced** — leaf register ABI ≠ helper's EDI/stack naming |
| 3 | Stack out + RET 4 like TextReadU32 | Body ends **`C3`**; no stack arg cleanup | **Falsified** for this leaf |
| 4 | Scans tokens itself | Only calls `FUN_00769b70` then maybe format | **Falsified** as scanner — **wrapper** |
| 5 | Accepts bare unquoted strings | ReadQuotedTag requires surrounding `"` | **Falsified** bare success |
| 6 | Success returns pointer / length | `xor eax,eax` → **0** | **Falsified** |
| 7 | Decompiler `__fastcall param_1` is complete ABI | Misses **EBX** reader; `unaff_EBX` is real | **Falsified** as complete — **ECX+EBX** |
| 8 | Mode dispatcher ABI equals leaf ABI | Dispatcher `00439a20` has stack reader + `ret 4` | **Falsified** equality — **dispatcher wider** |
| 9 | Product symbol present | Error string only | **Survives** as **Inferred** |
| 10 | Three-rep diverges | live ≡ raw ≡ bytes | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX out, EBX reader, C3, 0/−1 | **High** | Wrong registers at call sites |
| ReadQuotedTag-only body | **High** | Missed alternate path |
| Expected-string fail log | **High** | Wrong diagnostics |
| Double-quote-only success | **High** (via W25-S) | Accept bare tags incorrectly |
| Product English | **Inferred** | Doc-only |
| Runtime | **Open** | Shipping load |

---

## 3. Cross-check against raw + bytes

```
prologue:
  SEH / sub esp,0x20
  push edi / mov edi, ecx     ; out
  push ebx                    ; reader for callee
  call FUN_00769b70
  test eax,eax / jl fail
  xor eax,eax / … / ret       ; C3

fail:
  FUN_00436250
  c_str(out), c_str(chunk)
  FUN_0076cec0("Expected string but got \"%s\" in chunk \"%s\"", ...)
  vog_LogMessage(stoChunk.cpp, 0x44a, 3, msg)
  or eax,-1 / … / ret         ; C3

call sites:
  mov ebx, <reader>
  lea ecx, <local string>
  call 0076a200
```

**No conflict.** Dispatcher `00439a20` is a separate public dual-mode entry (not this VA).

---

## 4. Surviving contract for AutoCore

```csharp
// stoChunkReader_TextReadString @ 0x0076a200
// retail leaf: ECX = out string, EBX = reader, plain ret

int TextReadString(StoChunkReader reader, out string value)
{
    // equivalent to ReadQuotedTag into value
    if (ReadQuotedTag(reader, out value) >= 0)
        return 0;
    Log("Expected string but got \"{0}\" in chunk \"{1}\"", value, reader.ChunkName);
    return -1;
}
```

Port note: expose a normal managed API; map retail ECX/EBX when calling from dual-mode dispatcher. Do not accept bare tokens if parity with retail text loaders is required.
