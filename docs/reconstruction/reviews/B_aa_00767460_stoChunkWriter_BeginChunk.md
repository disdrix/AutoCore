# Review B (skeptical / adversarial): `aa_00767460` stoChunkWriter_BeginChunk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767460` |
| **VA** | `0x00767460` |
| **Canonical name** | `stoChunkWriter_BeginChunk` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00767460_stoChunkWriter_BeginChunk.md` |
| **System** | storage / arda2 stoChunk |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Plate text is exactly `CHUNK "%s" %i {` | Body writes format, then `\r\n`, then `{`, then another `\r\n` | **Falsified** plate abbreviation — real text is multi-write with CRLFs |
| 2 | Size field in header is total chunk size including header | EndChunk: `size = tell - headerPos - 0x10` | **Falsified** include-header — size is **payload only** |
| 3 | Text mode skips stack push | `FUN_00436340` runs after **common** write for both arms | **Attack fails** — always push |
| 4 | Binary Tell is after writing header | Tell assigned **before** choosing writePtr/len | **Attack fails** — Tell first, then write 0x10 |
| 5 | `param_1[7]` nonzero means “any nonbinary”; EndChunk only closes text when `==1` | Begin uses `==0` vs else; End uses `==0` and `==1` | **Partial** — Begin treats any nonzero as text path; product mode is almost certainly **0/1** only |
| 6 | Tag FourCC on disk matches C string order | LE store of u32 `'VERT'` → file bytes `T R E V` | **Attack fails** on “string order on disk”; plate correctly notes byte-reverse vs ASCII mnemonic |
| 7 | `FUN_00436190` builds LE char order | Shifts `>>24, >>16, >>8, >>0` into char buffer | **Attack fails** — **MSB-first** string |
| 8 | `DAT_00a97b84` is generic padding / zero | `read_memory` → `0d 0a 00` | **Attack fails** — literal `"\r\n"` |
| 9 | `DAT_00a6c044` is a long format string | `read_memory` → `7b 00` | **Attack fails** — single `"{"` |
| 10 | Return is void / success bool | `return param_1[1]` after OR chain | **Attack fails** — sticky status dword |
| 11 | `param_1[8]` is a bool “in chunk” | Cleared in text; `FUN_00767160` uses it as **column width** / wrap counter (`0x78` threshold) | **Falsified** bool — **text column** |
| 12 | force_decompile would change CF | force ≡ first decompile 2026-07-29 | **Attack fails** |
| 13 | This VA owns EndChunk size math | Size math lives at `0x007673a0` | **Agree** not owned — only seals placeholder 0 here |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual-mode begin role | **Confirmed** | Wrong asset serialize path |
| 16-byte binary header layout | **Confirmed** | Corrupt every chunked file |
| Payload-only size (via EndChunk) | **High** | Off-by-16 readers/writers |
| Text multi-write sequence | **Confirmed** | Text dump parse fails |
| Sticky status OR + return | **Confirmed** | Silent I/O errors |
| Stream Write/Tell vtbl slots | **High** | Wrong interface port |
| Stack frame 0x14 push always | **High** | Nesting / EndChunk mismatch |
| FUN_00436340 this-adjust (writer vs +8) | **Open** | Wrong stack object if reimplemented from helper alone |
| Mode values beyond 0/1 | **Open** | Exotic mode would take text path in Begin |
| Runtime / bit-exact | **Open** | No live dump |

---

## 3. Cross-check against raw / live / constants

```
raw/annotated/clean scaffold CF ≡ live decompile ≡ force_decompile (2026-07-29).

Constants (read_memory):
  DAT_00a97b84: 0d 0a 00 00  …  → "\r\n"
  DAT_00a6c044: 7b 00 00 00  …  → "{"
  (EndChunk sibling) DAT_00a6bfd0: 7d 00 → "}"

Binary locals before write:
  local_3c = tag
  local_38 = 0          // size placeholder
  local_34 = version
  local_30 = 0          // reserved
  local_2c = Tell()     // binary only; text leaves 0

Text path writes (order):
  1) FUN_00767160("CHUNK \"%s\" %i", fourcc_str, version)
  2) Write("\r\n", 2)
  3) FUN_00767160("{")
  4) Write("\r\n", 2)   // shared tail with binary's Write

Xrefs: 54 (complete analysis). Callees: FUN_00436190, FUN_00767160, FUN_00436340, string dtor.
```

### Plate-comment trap

Do **not** implement text open as a single printf of `CHUNK "%s" %i {`. Retail order is:

```text
CHUNK "XXXX" <ver>\r\n
{\r\n
```

Closing is EndChunk’s `}` (+ another `\r\n` path), not this VA.

### Size-field trap

Do **not** store total bytes including the 16-byte header in `hdr.size`. Begin leaves **0**; EndChunk sets:

```text
size = Stream_Tell() - headerPos - 0x10
```

so size covers **body only** after the header.

### FourCC endian trap

- **In code / registers:** tag is a `u32` mnemonic (e.g. `0x494e4458` `'INDX'`).
- **On disk (binary):** little-endian dword bytes (file may show reversed ASCII).
- **In text mode:** `FUN_00436190` prints **big-endian character order** of that u32 (mnemonic readable as written in source).

### Column / `param_1[8]` trap

Clearing `param_1[8]` is **not** “exit chunk.” It resets the text **line column** so `FUN_00767160` does not insert a leading space / premature wrap. Both clears in the text arm are intentional before `\r\n` / `{` / final `\r\n`.

---

## 4. Surviving contract for AutoCore

```
stoChunkWriter_BeginChunk(writer, tag4cc, version) -> status

if writer.mode == 0:   // binary
  pos = stream.Tell()
  hdr = { tag4cc, size:0, version, reserved:0 }
  status |= stream.Write(&hdr, 16)
  stack.Push({ tag4cc, 0, version, 0, headerPos:pos })

else:                  // text (product: mode==1)
  status |= FormattedWrite(writer, "CHUNK \"%s\" %i", FourCC_BE_chars(tag4cc), version)
  writer.textColumn = 0
  status |= stream.Write("\r\n", 2)
  status |= FormattedWrite(writer, "{")
  writer.textColumn = 0
  status |= stream.Write("\r\n", 2)
  stack.Push({ tag4cc, 0, version, 0, headerPos:0 })

return status   // sticky OR at writer+4

// Pair: stoChunkWriter_EndChunk patches size (binary) / writes "}" (text) and pops stack.

AutoCore must NOT:
  - put total-with-header into size at Begin (leave 0; End owns formula)
  - emit single-line text open without CRLFs around "{"
  - skip stack push on text
  - reverse FourCC string chars relative to FUN_00436190 (MSB first)
  - treat writer+0x20 as a boolean chunk flag
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Signature thiscall tag/version → status | **Agree High** |
| Mode 0 binary / else text | **Agree Confirmed** (note: EndChunk tests `==1` for text close) |
| 16-byte header tag/size0/ver/res0 | **Agree Confirmed** |
| Tell before write → headerPos | **Agree High** |
| Text multi-write + constants | **Agree Confirmed** |
| Always stack push 0x14 frame | **Agree High** |
| Sticky status OR at +4 | **Agree Confirmed** |
| Plate text abbreviated | **Agree** — B emphasizes trap |
| FUN_00436340 this-adjust Open | **Agree Open** |
| clean ≡ raw ≡ live ≡ force | **Agree** |
| accept-with-gaps | **Agree** |

Disputes: none on sealed CF. Naming: prefer documenting **payload-only size** and **text multi-write** over plate one-liner.

---

## 6. Open questions

1. Does any caller set `mode` to a value other than 0/1?
2. Exact object base for `FUN_00436340` (writer vs embedded ring at +8).
3. Full stream vtbl (Seek at +4 used only in EndChunk).
4. Runtime binary header dump vs retail file.
5. Interaction of nested Begin/End with text indent (`FUN_00767070`).

**Verdict:** **accept-with-gaps** — agree with A; block plate-literal text, include-header size, skip-push-on-text, and bool-misread of `+0x20`.
