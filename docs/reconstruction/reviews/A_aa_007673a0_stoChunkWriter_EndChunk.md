# Review A (reconstruction fidelity): `aa_007673a0` stoChunkWriter_EndChunk

| Field | Value |
|---|---|
| **Stable ID** | `aa_007673a0` |
| **VA** | `0x007673a0` |
| **Canonical name** | `stoChunkWriter_EndChunk` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_007673a0_stoChunkWriter_EndChunk.md` |
| **System** | `storage` / `arda2.stoChunk` |
| **Tools** | Ghidra `decompile_function`, `read_memory` (own VA + string DATs) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Closes the current open chunk on a **stoChunkWriter**. Retail plate (`arda2\storage\stoChunk.cpp`):

- **Binary mode** (`writer+0x1c == 0`): resolve top stack frame, compute body size = `tell() − headerPos − 0x10` (size **excludes** the 16-byte header), seek to header, rewrite 16-byte header, seek back to end.
- **Text mode** (`writer+0x1c == 1`): emit closing `}` then CRLF.
- **Always** (when depth ≠ 0): pop depth; if depth becomes 0, clear ring base.

Returns the writer’s accumulated status dword (`writer+0x04`), which is OR’d with each stream op result.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007673a0_stoChunkWriter_EndChunk.md` |
| Annotated | `docs/reconstruction/raw/aa_007673a0_stoChunkWriter_EndChunk.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkWriter_EndChunk.cpp` |
| Function record | `docs/reconstruction/functions/aa_007673a0_stoChunkWriter_EndChunk.md` |
| Sibling (context only) | `stoChunkWriter_BeginChunk` @ `0x00767460` |
| Live decompile | Ghidra `decompile_function` @ `0x007673a0` (matches raw) |

---

## 3. Assembly-sealed body (`read_memory` @ `0x007673a0`)

Prologue / mode branch:

```text
007673a0  56              push esi
007673a1  8BF1            mov  esi, ecx              ; this = writer*
007673a3  837E1C00        cmp  dword [esi+0x1c], 0   ; mode
007673a7  7560            jne  skip_binary           ; !=0 → skip binary patch path
```

Binary path (mode==0) — ring index, tell, patch size, seek/write/seek:

```text
007673a9  8B4E18          mov  ecx, [esi+0x18]       ; depth
007673ac  034E14          add  ecx, [esi+0x14]       ; + base
007673af  8D4608          lea  eax, [esi+0x08]
007673b2  83E901          sub  ecx, 1                ; index = depth+base-1
007673b5  8BD0            mov  edx, eax              ; edx → writer+0x08
007673b7  8BC1            mov  eax, ecx
007673b9  8B4A08          mov  ecx, [edx+0x08]       ; capacity @ writer+0x10
007673bc  3BC8            cmp  ecx, eax
007673be  7702            ja   no_wrap
007673c0  2BC1            sub  eax, ecx              ; index -= capacity
007673c2  8B4A04          mov  ecx, [edx+0x04]       ; stack[] @ writer+0x0c
007673c5  53              push ebx
007673c6  57              push edi
007673c7  8B3C81          mov  edi, [ecx+eax*4]      ; frame*
007673ca  8B0E            mov  ecx, [esi]            ; stream*
007673cc  8B11            mov  edx, [ecx]
007673ce  FF5230          call dword [edx+0x30]      ; tell()
007673d1  8BD8            mov  ebx, eax              ; endPos
007673d3  8B4710          mov  eax, [edi+0x10]       ; headerPos
007673d6  8BCB            mov  ecx, ebx
007673d8  2BC8            sub  ecx, eax
007673da  83E910          sub  ecx, 0x10             ; size = end-header-16
007673dd  894F04          mov  [edi+0x04], ecx       ; frame.size
007673e0  8B0E            mov  ecx, [esi]
007673e2  8B11            mov  edx, [ecx]
007673e4  6A00            push 0
007673e6  50              push eax                   ; seek(headerPos, 0)
007673e7  FF5204          call dword [edx+0x04]
007673ea  8B0E            mov  ecx, [esi]
007673ec  094604          or   [esi+0x04], eax       ; status |=
007673ef  8B01            mov  eax, [ecx]
007673f1  6A10            push 0x10
007673f3  57              push edi                   ; write(frame, 16)
007673f4  FF5018          call dword [eax+0x18]
007673f7  8B0E            mov  ecx, [esi]
007673f9  094604          or   [esi+0x04], eax
007673fc  8B11            mov  edx, [ecx]
007673fe  6A00            push 0
00767400  53              push ebx                   ; seek(endPos, 0)
00767401  FF5204          call dword [edx+0x04]
00767404  094604          or   [esi+0x04], eax
00767407  5F              pop  edi
00767408  5B              pop  ebx
```

Depth pop (both modes if depth was non-zero):

```text
00767409  8B4618          mov  eax, [esi+0x18]
0076740c  85C0            test eax, eax
0076740e  740F            jz   after_pop
00767410  83C0FF          add  eax, -1
00767413  894618          mov  [esi+0x18], eax       ; depth--
00767416  7507            jnz  after_pop
00767418  C7461400000000  mov  dword [esi+0x14], 0   ; base = 0 when empty
```

Text path (mode==1) + return:

```text
0076741f  837E1C01        cmp  dword [esi+0x1c], 1
00767423  752A            jne  ret_status
00767425  68D0BFA600      push 0x00a6bfd0            ; "}"
0076742a  8BC6            mov  eax, esi              ; writer in EAX for helper
0076742c  E82FFDFFFF      call FUN_00767160          ; vsnprintf/write text
00767431  8B0E            mov  ecx, [esi]
00767433  094604          or   [esi+0x04], eax
00767436  83C404          add  esp, 4
00767439  6A02            push 2
0076743b  C7462000000000  mov  dword [esi+0x20], 0   ; text column = 0
; … write(DAT_00a97b84, 2) via stream vtable+0x18, OR status …
; ret [esi+0x04]
```

**String seals (`read_memory`):**

| Address | Hex / ASCII | Role |
|---|---|---|
| `0x00a6bfd0` | `7d 00 00 00` → `"}"` | Text close brace format/arg |
| `0x00a97b84` | `0d 0a 00 00` → `"\r\n"` | 2-byte CRLF write |

---

## 4. Writer / frame layout (this unit)

**stoChunkWriter** (dword indices as in decompiler `param_1[n]`):

| Off | Index | Field |
|---|---|---|
| `+0x00` | `[0]` | `stream*` (vtable object) |
| `+0x04` | `[1]` | accumulated status (OR of stream results) |
| `+0x0c` | `[3]` | chunk-stack base (`frame**`) |
| `+0x10` | `[4]` | stack capacity (ring wrap modulus) |
| `+0x14` | `[5]` | ring base index |
| `+0x18` | `[6]` | depth |
| `+0x1c` | `[7]` | mode: `0` binary, `1` text |
| `+0x20` | `[8]` | text column / line budget (cleared on text End) |

**Stack frame** (binary header patch target):

| Off | Field |
|---|---|
| `+0x00` | tag (u32 FourCC, byte-reversed on disk per BeginChunk plate) |
| `+0x04` | size (u32, **body only** — excludes 16-byte header) |
| `+0x08` | version |
| `+0x0c` | reserved |
| `+0x10` | header file position (not part of on-disk header rewrite length; write length is `0x10` from frame base) |

**Stream vtable slots used here:**

| Slot | Use |
|---|---|
| `+0x04` | seek(pos, origin=0) |
| `+0x18` | write(buf, len) |
| `+0x30` | tell() |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__fastcall` / `__thiscall`-style: `ECX = writer*` | **High** | `mov esi, ecx` |
| Binary mode only when `+0x1c == 0` | **High** | `cmp/jne` |
| Size formula `tell − headerPos − 0x10` | **High** | `sub ecx,eax; sub ecx,0x10; mov [edi+4],ecx` |
| Rewrite is exactly 16 bytes from frame base | **High** | `push 0x10; push edi; call [vt+0x18]` |
| Seek origin arg is `0` both times | **High** | `push 0` before each seek |
| Ring index wrap when `index >= capacity` | **High** | `cmp capacity,index; ja; sub` |
| Depth pop + clear base when empty | **High** | Always after binary block; independent of mode |
| Text mode writes `}` then `\r\n` | **High** | DAT seals + `push 2` write |
| Status OR into `+0x04`; return that dword | **High** | `or [esi+4],eax` pattern + ret value |
| `FUN_00767160` takes format on stack, writer in **EAX** | **High** | `mov eax,esi; call`; helper decompile uses `in_EAX` |
| Mode is only 0 or 1 (other values no-op body ops) | **Medium** | Only tests `==0` and `==1`; other modes still pop depth |
| Product type names for stream vtable | **Low** | Still anonymous `*(**stream+slot)` |
| Full ring-buffer invariants under concurrent misuse | **Low** | Not sealed; depends on BeginChunk push |

---

## 6. Control flow: clean ≡ raw ≡ decompile ≡ asm

| Stage | Match |
|---|---|
| if mode==0: index → frame → tell → size → seek → write16 → seek end | **Yes** |
| if depth≠0: depth--; if 0 clear base | **Yes** |
| if mode==1: write `}` via helper; col=0; write `\r\n` | **Yes** |
| return status | **Yes** |

Clean/raw remain scaffold naming (`param_1`, `FUN_*`) but **control flow and immediates match** live decompile and sealed asm.

---

## 7. Call graph (this unit only)

**Callees**

| Target | Role |
|---|---|
| `stream.vt+0x30` | tell |
| `stream.vt+0x04` | seek |
| `stream.vt+0x18` | write |
| `FUN_00767160` @ `0x00767160` | text `vsnprintf` + stream write of `"}"` |

**Callers:** 69 xrefs in inventory (`stoChunkWriter_EndChunk`) — serialize sites pair with `BeginChunk`; not expanded (own-VA scope).

---

## 8. Gaps / open

1. Product name / full type of stream interface and exact seek origin enum (always 0 here).
2. Whether mode values other than 0/1 are legal production states.
3. Frame allocator / push helper (`FUN_00436340` on Begin path) — ownership outside this VA.
4. Runtime / bit-exact image diff not run.
5. Text helper line-wrap policy (`FUN_00767160` column `0x78`) is callee residual; EndChunk only forces col=0 then CRLF.

**Verdict:** **accept-with-gaps**
