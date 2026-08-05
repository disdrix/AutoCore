# Review B (skeptical / adversarial): `aa_007673a0` stoChunkWriter_EndChunk

| Field | Value |
|---|---|
| **Stable ID** | `aa_007673a0` |
| **VA** | `0x007673a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007673a0_stoChunkWriter_EndChunk.md` |
| **Tools** | Ghidra `decompile_function`, `read_memory` (own VA + DATs); helper decompile only as residual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Size field includes the 16-byte header | Plate says excludes; asm does `sub 0x10` after `tell−headerPos` | **Falsified** — body size only |
| 2 | “Pops stack” means free/dealloc frame | Only depth-- and optional base clear; no free call in body | **Falsified as free** — logical pop only |
| 3 | Text mode writes only `}` | Also `write("\r\n", 2)` after helper; col zeroed | **Incomplete claim if only brace stated** |
| 4 | `FUN_00767160(&DAT_00a6bfd0)` is raw stream write of `}` | Helper is `_vsnprintf` + write path; writer passed in **EAX**, not ECX | **Partially true** — net effect writes `}`; ABI is special |
| 5 | Mode gate is if/else exclusive | Binary block is `if mode==0`; text is separate `if mode==1`; depth pop sits between and always runs when depth≠0 | **Nuanced** — not a pure if/else; both mode tests independent |
| 6 | Calling convention is plain `__fastcall(writer*)` for all callees | Stream methods use ECX=stream*; text helper uses EAX=writer + stack format | **Mixed ABI** — do not port as single convention |
| 7 | Header rewrite writes only the size field | `write(frame, 0x10)` rewrites full 16-byte header (tag/size/ver/res) | **Falsified as size-only write** — size is patched in memory, whole header flushed |
| 8 | Ring wrap is always applied | Wrap only when `capacity <= index` (`ja` skips sub) | **Conditional wrap** |
| 9 | EndChunk is no-op when depth==0 in binary | Binary path still indexes `depth+base-1` **before** depth test — empty stack is **UB / bad index** if mode==0 and depth==0 | **Risk** — no empty-stack guard on binary path |
| 10 | Scaffold clean is production-ready types | Still `param_1`, `FUN_*`, `code**` | **Scaffold only** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size excludes header (`−0x10`) | **High** | Corrupt .geo / chunk sizes off by 16 |
| Full 16-byte header rewrite | **High** | Partial-write ports leave stale tag/ver |
| Mode 0 vs 1 gates | **High** | Binary patching in text or vice versa |
| Depth pop + base clear | **High** | Nested chunk stack desync |
| Text `}` + CRLF constants | **High** | Wrong text dump format |
| Empty binary End without matching Begin | **Low safety** | Wild frame pointer / crash |
| Stream vtable product names | **Low** | Wrong adapter when rehosting I/O |
| Status OR semantics | **High** | Lost I/O errors if replaced with last-write-only |

---

## 3. Cross-check against raw / clean

```
stoChunkWriter_EndChunk(writer):   // ECX = writer
  if writer.mode == 0:             // +0x1c
    idx = writer.depth + writer.base - 1
    if writer.capacity <= idx: idx -= capacity
    frame = writer.stack[idx]
    endPos = stream.tell()         // vt+0x30
    frame.size = endPos - frame.headerPos - 0x10   // +4
    status |= stream.seek(frame.headerPos, 0)      // vt+0x04
    status |= stream.write(frame, 0x10)            // vt+0x18
    status |= stream.seek(endPos, 0)
  if writer.depth != 0:
    writer.depth--
    if writer.depth == 0: writer.base = 0
  if writer.mode == 1:
    status |= TextWrite(writer, "}")               // FUN_00767160; EAX=writer
    writer.textCol = 0                             // +0x20
    status |= stream.write("\r\n", 2)
  return status                                    // +0x04
```

Raw/clean match this control flow. Plate comment is **correct** on binary size formula and text `}`; it under-specifies CRLF, ring wrap, full-header rewrite, and empty-stack hazard.

String seals:

- `0x00a6bfd0` → `"}"`
- `0x00a97b84` → `"\r\n"` (length 2)

---

## 4. Surviving contract for AutoCore

```
EndChunk pairs with BeginChunk for nested RIFF-like chunks:

  Binary:
    header on disk = { tag:u32, size:u32, version:u32, reserved:u32 }
    size = (byte_offset_after_body - byte_offset_of_header) - 16
    End must seek back, rewrite all 16 header bytes, seek to end again.

  Text:
    emit "}" then "\r\n"; reset text column.

  Stack:
    depth--; if depth==0 reset ring base.
    Never End binary with depth==0 (retail assumes matching Begin).

  Errors:
    OR stream results into writer.status; return that dword (HRESULT-style).

AutoCore storage serializers that emit the same chunk container must preserve
the size-excludes-header rule or readers will disagree on body bounds.
```

---

## 5. Open questions

1. Seek origin `0` meaning (SEEK_SET assumed; not re-proven from stream impl).
2. Legal non-{0,1} mode values and whether depth pop alone is intentional.
3. Whether status bits are true HRESULTs or boolean OR flags.
4. Frame lifetime after pop (reused ring slots vs heap) — owned by Begin/push helpers.
5. Runtime differential vs retail binary image not run.

**Verdict:** **accept-with-gaps**
