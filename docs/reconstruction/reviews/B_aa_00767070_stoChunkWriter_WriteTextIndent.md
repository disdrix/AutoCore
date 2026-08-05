# Review B (skeptical / adversarial): `aa_00767070` stoChunkWriter_WriteTextIndent

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767070` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00767070_stoChunkWriter_WriteTextIndent.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + DAT + call site). No `disassemble_bytes`. Own VA `0x00767070` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is `__thiscall` with writer in **ECX** | Body never reads ECX; all fields via **ESI**; no `mov esi,ecx` | **Falsified** — **ESI register ABI** |
| 2 | Indent is fixed 4 spaces always | `mov eax,[esi+18]; add eax,eax; add eax,eax` → depth×4 | **Falsified** — **depth-scaled** |
| 3 | Indent uses tabs or 2-space policy | DAT + write len 1 of `0x20` only | **Falsified** — **ASCII space × 4×depth** |
| 4 | textCol is incremented per space write | Single store `mov [esi+20],eax` before loop; loop does not touch +0x20 | **Falsified** — **set once to count** |
| 5 | depth 0 still writes one space | `sub eax,1; js skip` when count was 0 | **Falsified** — **zero writes** |
| 6 | Return is void / write count | Tail `mov eax,[esi+4]; ret` | **Falsified** — **returns sticky status** |
| 7 | Status replaces (not ORs) | `or [esi+4],eax` each iteration | **Falsified** — **sticky OR** |
| 8 | Multiple callers / different ABIs | `get_function_xrefs` / callers → sole `FUN_00767160` @ `0x007671ba` | **Falsified multiplicity** — **1 caller** |
| 9 | DAT_00a2a000 is multi-char padding string | `read_memory`: `20 00 00 00` | **Falsified** — single `" "` (trailing zeros are alignment / next string area) |
| 10 | Three-rep diverges | live decompile ≡ raw; bytes match CF | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI = writer; plain RET | **High** | Wrong ABI in port / emulator |
| count = depth×4; textCol = count | **High** | Nested .txt chunk indent wrong |
| write `" "` × count via vt+0x18 | **High** | Corrupt stream / wrong whitespace |
| status sticky OR; return status | **High** | Silent write failures |
| Sole caller WriteFormatted @ col==0 | **High** | Missed alternate indent path |
| Product English name | **Low** | Doc-only |
| Runtime / bit-exact | **Open** | Shipping text serialize |

---

## 3. Cross-check against raw + bytes

```
raw / live decompile:
  count = ESI[6]*4;          // +0x18
  ESI[8] = count;            // +0x20 textCol
  if (count > 0) loop write(" ",1) | status
  return ESI[1];             // +0x04

bytes:
  8B4618 03C0 03C0 894620 83E801 781B …
  6A01 6800A0A200 FF5018 094604 83EF01 75EA
  8B4604 C3

call site WriteFormatted:
  cmp [esi+20],0; jz call indent; or [esi+4],eax
```

**No conflict** among raw, live decompile, body bytes, DAT, and call site.

---

## 4. Surviving contract for AutoCore

```csharp
// stoChunkWriter_WriteTextIndent @ 0x00767070
// retail: writer in ESI; clean ports may pass writer as arg

uint WriteTextIndent(StoChunkWriter w)
{
    int count = w.Depth /* +0x18 */ * 4;
    w.TextCol /* +0x20 */ = count;
    for (int i = 0; i < count; i++)
        w.Status |= w.Stream.Write(" ", 1); // vtbl+0x18
    return w.Status;
}
```

Port notes:

- Invoke only at **line start** (caller already enforces `textCol==0`); this unit does not re-check column.
- Setting `textCol = depth*4` **before** body write means WriteFormatted's later `textCol += len` continues from the indent width — do not also add indent length again.
- depth 0 is valid (no spaces; col stays 0).
- Double `status |=` in WriteFormatted after return is idempotent.

---

## 5. Gaps surviving review

1. Product plate identifier.
2. Live runtime capture of nested text serialize.
3. Stream interface beyond write slot.

---

## 6. Verdict

**accept-with-gaps** — adversarial attacks on ABI/math/DAT/status fail; remaining gaps are naming + runtime only.
