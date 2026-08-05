# Review B (skeptical / adversarial): `aa_00767160` stoChunkWriter_WriteFormatted

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767160` |
| **VA** | `0x00767160` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00767160_stoChunkWriter_WriteFormatted.md` |
| **Tools** | Ghidra `decompile_function`, `read_memory` (own VA + DATs); indent decompile residual only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` / ECX = writer | Entry is `mov esi, eax` — no `ecx` writer load | **Falsified** — **EAX** ABI |
| 2 | Wrap threshold is `>= 0x78` | Asm: `cmp eax,0x78; jle skip` → wrap only when **>** 0x78 | **Falsified as ≥** — strict greater |
| 3 | Wrap includes the pending token length only | Predicate is `col + 1 + len` (the `+1` is the would-be space) | **Nuanced** — accounts for separator |
| 4 | Always emits a leading space | Only when `textCol != 0` after wrap check | **Falsified** — line start uses indent |
| 5 | Indent is spaces of fixed width 4 in **this** VA | Indent is `call FUN_00767070`; body not inlined | **Out of scope** — residual helper |
| 6 | `"\r\n"` and `" "` are the same DAT | Distinct: `0x00a97b84` vs `0x00a2a000` | **Falsified as same** |
| 7 | Status is last write only | Each path `or [esi+4], eax` | **Falsified** — cumulative OR |
| 8 | Buffer size 0x1000 like `Util_VsnprintfToStaticBuf4k` | Push `0x400` / `sub esp,0x400` | **Falsified** — **1024** local |
| 9 | Returns length written | `mov eax,[esi+4]` status | **Falsified** — returns **status** |
| 10 | Scaffold clean is production types | Still `in_EAX`, `code**`, `stack0x…` | **Scaffold only** for rehost |
| 11 | Safe when `vsnprintf` returns −1 | `push edi` as length with no check | **Risk** — residual |
| 12 | `EndChunk` forces col=0 so wrap never fires for `"}"` | EndChunk sets col=0 after helper returns; helper still runs full path with prior col | **Nuanced** — EndChunk zeros col **after** this call |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX writer ABI | **High** | Wrong thiscall ports corrupt ESI/ECX |
| Wrap at >0x78 with CRLF | **High** | Text dumps line-break wrong |
| Space vs indent branch | **High** | Missing/extra whitespace in .txt chunks |
| Status OR + return | **High** | Lost I/O errors |
| DAT string contents | **High** | Wrong bytes on disk |
| Indent depth semantics | **Low** (other VA) | Wrong nested text indentation |
| Negative length | **Low safety** | Huge write / AV |

---

## 3. Cross-check against raw / clean

```
stoChunkWriter_WriteFormatted(writer /*EAX*/, fmt, ...):
  len = _vsnprintf(stack_buf, 0x400, fmt, va)
  if textCol > 0 and textCol + 1 + len > 0x78:
    textCol = 0
    status |= stream.write("\r\n", 2)      // vt+0x18
  if textCol == 0:
    status |= Indent(writer)               // FUN_00767070
  else:
    status |= stream.write(" ", 1)
    textCol += 1
  status |= stream.write(stack_buf, len)
  textCol += len
  return status
```

Raw/live/clean match. Annotated documents DAT seals and ABI.

String seals:

- `0x00a97b84` → `"\r\n"` (length 2)
- `0x00a2a000` → `" "` (length 1)

---

## 4. Surviving contract for AutoCore

```
Text-mode stoChunkWriter output path:

  - Formatted tokens go through this helper (or equivalent).
  - Soft line width 120 (0x78): when a mid-line token would push
    col+1+len past 120, emit CRLF first and reset column.
  - Line starts are indented (indent helper); mid-line tokens are
    space-separated.
  - All stream write HRESULTs/flags OR into writer.status; callers
    typically OR the helper return into status again (double-OR ok).
  - ABI is special: writer in EAX, not ECX — do not invent thiscall.

AutoCore text serializers for the same chunk format must preserve
CRLF wrap + space separation or text dumps will not round-trip
whitespace against retail.
```

---

## 5. Open questions

1. Exact product symbol / plate in `stoChunk.cpp`.
2. Indent helper field map (`FUN_00767070` — dual not in this OWN set).
3. Truncation when formatted length ≥ 0x400 (null-term policy of CRT).
4. Runtime differential vs retail not run.
5. Interaction with `EndChunk` column force to 0 (ordering: helper then zero).

**Verdict:** **accept-with-gaps**
