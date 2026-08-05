# Review A (reconstruction fidelity): `aa_00767460` stoChunkWriter_BeginChunk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767460` |
| **VA** | `0x00767460` |
| **Canonical name** | `stoChunkWriter_BeginChunk` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00767460_stoChunkWriter_BeginChunk.md` |
| **System** | storage / arda2 stoChunk (writer open-chunk) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`__thiscall` **begin a nested named chunk** on `stoChunkWriter`:

1. Branch on **mode** `this+0x1c` (`param_1[7]`):
   - **0 = binary**: record stream position (`vtbl+0x30` Tell), then write a **16-byte header** `{tag, size=0, version, reserved=0}`.
   - **≠0 = text**: format `CHUNK "%s" %i` with tag as 4-char string + version, write `\r\n`, write `{`, write `\r\n` again; clear text column `this+0x20`.
2. OR each I/O / format result into sticky status `this+0x04`.
3. **Push** a 5-dword frame onto the writer's chunk stack via `FUN_00436340` so `stoChunkWriter_EndChunk` (`0x007673a0`) can pop and (binary) patch size.
4. **Return** sticky status (`this+0x04` / `param_1[1]`).

Plate / source path: `arda2\storage\stoChunk.cpp`. Call volume: **54** xrefs (geometry, animation, GFX buffers, keyframe tracks, etc.).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00767460_stoChunkWriter_BeginChunk.md` |
| Annotated | `docs/reconstruction/raw/aa_00767460_stoChunkWriter_BeginChunk.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkWriter_BeginChunk.cpp` |
| Function record | `docs/reconstruction/functions/aa_00767460_stoChunkWriter_BeginChunk.md` |
| Live decompile | Ghidra `decompile_function` @ `0x00767460` (2026-07-29) |
| Force redecompile | Ghidra `force_decompile` @ `0x00767460` — **identical CF** |
| Complete analysis | `analyze_function_complete` — 54 xrefs; callees `FUN_00436190`, `FUN_00767160`, `FUN_00436340`, `~basic_string` |
| Constants | `read_memory` `DAT_00a97b84` → `0d 0a 00` (`"\r\n"`); `DAT_00a6c044` → `7b 00` (`"{"`) |
| Tag→string helper (callee evidence) | `FUN_00436190` — 4CC big-endian char order into `std::string` |
| Stack push helper (callee evidence) | `FUN_00436340` — ring push of **5 dwords / 0x14** |
| Pair EndChunk (sibling CF only) | `0x007673a0` — size = tell − headerPos − **0x10**; text closes `}` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `uint __thiscall(this, u32 tag4cc, u32 version)` → sticky status | **High** | thiscall ECX; stack+4 tag, +8 version; `return param_1[1]` |
| Mode gate `this+0x1c` / `param_1[7]`: **0 binary**, else text | **Confirmed** | body; EndChunk uses `==0` / `==1` |
| Binary header 16 B: tag, size=0, version, reserved=0 | **Confirmed** | locals `local_3c..local_30`; write length `0x10` |
| Binary headerPos = Tell **before** header write (`vtbl+0x30`) | **High** | `local_2c = (*stream+0x30)()` then write |
| Stream vtbl: `+0x18` Write(buf,len), `+0x30` Tell | **High** | both arms + EndChunk seek at `+4` |
| Sticky status OR into `this+0x04` | **Confirmed** | every write/format path |
| Text format `"CHUNK \"%s\" %i"` + tag c_str + version | **Confirmed** | literal + `FUN_00767160` |
| Tag string = 4 bytes of u32 **MSB-first** (e.g. `0x56455254` → `"VERT"`) | **High** | `FUN_00436190` shifts `>>24..>>0` |
| Disk binary tag is LE dword → code `'VERT'` appears as file bytes `"TREV"` | **High** | plate + LE store of same u32 |
| Text trailer: Write `"\r\n"` (2), format `"{"`, common-path Write `"\r\n"` (2) | **Confirmed** | `DAT_00a97b84` / `DAT_00a6c044` + shared write |
| Text clears `this+0x20` (`param_1[8]`) twice before brace / shared write | **High** | column counter used by `FUN_00767160` wrap logic |
| Stack push always (both modes) via `FUN_00436340` | **Confirmed** | after common write |
| Frame fields: `+0 tag, +4 size, +8 ver, +0c reserved, +10 headerPos` | **High** | 5 dwords copied; EndChunk patches `frame+4` size from `frame+0x10` pos |
| Size semantics (EndChunk): **payload only** = tell − headerPos − 0x10 | **High** (sibling) | not owned here; seals why size starts 0 |
| Plate text `'CHUNK "%s" %i {'` is abbreviated | **High** | real text inserts `\r\n` around `{` |
| clean ≡ raw ≡ live ≡ force CF | **High** | 2026-07-29 spot-check |
| Runtime / bit-exact vs retail | **Open** | no live capture |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ force

| Stage | Raw | Clean | Live/force |
|---|---|---|---|
| SEH frame + init size/reserved/headerPos = 0 | Y | Y | Y |
| header.tag = tag; header.version = version | Y | Y | Y |
| if mode==0: Tell → headerPos; writePtr=&header; len=0x10 | Y | Y | Y |
| else: tag→string; `CHUNK "%s" %i`; dtor string | Y | Y | Y |
| else: clear col; Write `\r\n`(2); format `{`; clear col; writePtr=`\r\n`; len=2 | Y | Y | Y |
| common: Write(writePtr,len); OR status | Y | Y | Y |
| FUN_00436340 push frame | Y | Y | Y |
| return status | Y | Y | Y |
| Invented / deleted arms | — | **None** | **None** |

### Recovered CF (authoritative)

```c
// uint __thiscall stoChunkWriter_BeginChunk(stoChunkWriter *w, uint tag4cc, uint version)
// returns w->status (sticky OR of stream errors)

ChunkFrame frame = { tag4cc, /*size*/0, version, /*reserved*/0, /*headerPos*/0 };

if (w->mode /* +0x1c */ == 0) {
  // binary
  frame.headerPos = Stream_Tell(w->stream);          // vtbl+0x30
  writePtr = &frame;  writeLen = 0x10;               // tag,size,ver,reserved
} else {
  // text
  string s = FourCC_ToString(tag4cc);                // FUN_00436190, MSB-first chars
  status |= FormattedWrite(w, "CHUNK \"%s\" %i", s.c_str(), version); // FUN_00767160
  w->textColumn /* +0x20 */ = 0;
  status |= Stream_Write(w->stream, "\r\n", 2);      // vtbl+0x18, DAT_00a97b84
  status |= FormattedWrite(w, "{");                  // DAT_00a6c044
  w->textColumn = 0;
  writePtr = "\r\n";  writeLen = 2;
}

status |= Stream_Write(w->stream, writePtr, writeLen);
ChunkStack_Push(/*frame*/);                          // FUN_00436340 — 0x14-byte slot
return status;
```

---

## 5. Param / local renames (evidence only)

| Raw / Ghidra | Preferred | Evidence |
|---|---|---|
| `param_1` | `writer` / `stoChunkWriter*` | thiscall; fields +0 stream, +4 status, +0x1c mode, +0x20 col |
| `param_2` | `tag4cc` | header dword0; text FourCC; plate |
| `param_3` | `version` | header dword2; text `%i` |
| `local_3c` | `hdr.tag` | = param_2 |
| `local_38` | `hdr.size` | forced 0; EndChunk rewrites |
| `local_34` | `hdr.version` | = param_3 |
| `local_30` | `hdr.reserved` | forced 0 |
| `local_2c` | `hdr.headerPos` | Tell() binary; 0 text |
| `puVar3` / `uVar4` | write buffer / length | binary &hdr,0x10; text `\r\n`,2 |
| `FUN_00436190` | FourCC→`std::string` | callee body |
| `FUN_00767160` | FormattedWrite / vsnprintf+Write | callee body |
| `FUN_00436340` | ChunkStack_Push | callee body; 5 dwords |

---

## 6. Writer layout (partial; sealed from this body)

| Off | Field | Evidence |
|---|---|---|
| +0x00 | `stream*` (interface w/ vtbl) | `*param_1`; methods at +0x18 / +0x30 |
| +0x04 | `status` (OR of write results) | `param_1[1]`; return value |
| +0x0c..+0x18 | chunk **stack ring** (array*, cap, start, count) | EndChunk + push helper (see sibling) |
| +0x1c | `mode` (0 binary, 1 text) | `param_1[7]` branch |
| +0x20 | `textColumn` / line position | `param_1[8]` cleared in text; used by `FUN_00767160` |

### Binary on-disk header (16 bytes)

| Off | Type | Value at Begin |
|---|---|---|
| +0x00 | u32 | `tag4cc` (LE bytes on disk) |
| +0x04 | u32 | **0** (placeholder; EndChunk patches payload size) |
| +0x08 | u32 | `version` |
| +0x0c | u32 | **0** reserved |

### Stack frame (0x14) pushed for EndChunk

| Off | Field |
|---|---|
| +0x00 | tag |
| +0x04 | size (0 until End) |
| +0x08 | version |
| +0x0c | reserved |
| +0x10 | headerPos (binary Tell before write) |

---

## 7. Callers (summary; this VA only)

54 xrefs. Named / high-signal examples (not exhaustive):

- `gfxIndexBufferImpl_Serialize` / `gfxVertexBufferImpl_Serialize` / `gfxGeometryPiece_Serialize`
- Keyframe track writers (`FUN_00458770` family — tags like `0x5452414b` `"TRAK"`)
- Anim / asset serialize (`FUN_0073f8a0` `TEVA`, `FUN_00989350` `FDPC`, `FUN_00999040` `NKSG`, …)

All pass `(tag4cc, version)` and pair with `stoChunkWriter_EndChunk`.

---

## 8. Gaps / open

1. Exact **this-adjust** when calling `FUN_00436340` (writer base vs `writer+8` subobject) — ring field offsets differ by 8 between helper and EndChunk’s `param_1[3..6]`; role sealed, subobject base **Open**.
2. Full stream interface vtbl (Seek signature, error codes for Write).
3. Text-mode nesting indent (`FUN_00767070`) — used by FormattedWrite, not by this body directly after col clear.
4. Runtime capture of a retail binary header + text dump.
5. Bit-exact vs retail EXE.

**Verdict:** **accept-with-gaps** — CF sealed for binary header + text open sequence + stack push; mode/status/layout High; stack-helper this-adjust and runtime Open.
