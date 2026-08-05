# Review A (reconstruction fidelity): `aa_00767160` stoChunkWriter_WriteFormatted

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767160` |
| **VA** | `0x00767160` |
| **Canonical name** | `stoChunkWriter_WriteFormatted` |
| **Prior scaffold** | `FUN_00767160` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) — OWN-ONLY W16-K |
| **Counterpart** | `reviews/B_aa_00767160_stoChunkWriter_WriteFormatted.md` |
| **System** | `storage` / `arda2.stoChunk` |
| **Tools** | Ghidra `decompile_function`, `read_memory` (own VA + string DATs) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Text-mode **formatted write** helper for `stoChunkWriter`:

1. `_vsnprintf(local, 0x400, format, va)` → length in EDI.
2. If `textCol > 0` and `textCol + 1 + len > 0x78`: set `textCol = 0`, `status |= write("\r\n", 2)`.
3. If `textCol == 0`: `status |= FUN_00767070()` (indent).
4. Else: `status |= write(" ", 1)`, `textCol++`.
5. `status |= write(local, len)`, `textCol += len`.
6. Return `status` (`writer+0x04`).

**ABI:** writer in **EAX**; format at `[esp+4]`; varargs follow. Confirmed by `mov esi, eax` at entry and by dual-reviewed `stoChunkWriter_EndChunk` call site (`mov eax, esi; call 0x00767160`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00767160_FUN_00767160.md` (+ 2026-07-29 re-verify) |
| Annotated | `docs/reconstruction/raw/aa_00767160_FUN_00767160.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00767160.cpp` |
| Function record | `docs/reconstruction/functions/aa_00767160_FUN_00767160.md` |
| Live decompile | Ghidra `decompile_function` @ `0x00767160` (matches raw) |
| Bytes | `read_memory` full body through `ret` |
| DAT | `0x00a97b84` → `"\r\n"`; `0x00a2a000` → `" "` |
| Sibling (context) | `stoChunkWriter_EndChunk` A/B dual (calls this for `"}"`) |
| Indent residual | `FUN_00767070` decompile (spaces × depth; ESI writer) |

---

## 3. Assembly-sealed body (`read_memory` @ `0x00767160`)

Prologue / vsnprintf:

```text
00767160  8B4C2404        mov  ecx, [esp+4]        ; format
00767164  81EC00040000    sub  esp, 0x400          ; local buf
0076716A  56              push esi
0076716B  57              push edi
0076716C  8BF0            mov  esi, eax            ; writer* ← EAX
0076716E  8D842410040000  lea  eax, [esp+0x410]    ; va_list
00767175  50              push eax
00767176  51              push ecx
00767177  8D542410        lea  edx, [esp+0x10]     ; buf after 2 pushes
0076717B  6800040000      push 0x400
00767180  52              push edx
00767181  FF15B4649C00    call [_vsnprintf]
00767187  8BF8            mov  edi, eax            ; len
00767189  8B4620          mov  eax, [esi+0x20]     ; textCol
0076718C  83C410          add  esp, 0x10
```

Wrap branch:

```text
0076718F  85C0            test eax, eax
00767191  7E21            jle  after_wrap          ; col <= 0 → skip
00767193  8D443801        lea  eax, [eax+edi+1]    ; col+len+1
00767197  83F878          cmp  eax, 0x78
0076719A  7E18            jle  after_wrap
0076719C  8B0E            mov  ecx, [esi]          ; stream*
0076719E  6A02            push 2
007671A0  C7462000000000  mov  dword [esi+0x20], 0
007671A7  8B11            mov  edx, [ecx]
007671A9  68847BA900      push DAT_00a97b84        ; "\r\n"
007671AE  FF5218          call dword [edx+0x18]    ; write
007671B1  094604          or   [esi+0x04], eax
```

Indent vs space + body write + return:

```text
007671B4  837E2000        cmp  dword [esi+0x20], 0
007671B8  750A            jnz  mid_line_space
007671BA  E8B1FEFFFF      call FUN_00767070        ; indent
007671BF  094604          or   [esi+0x04], eax
007671C2  EB15            jmp  write_body
; mid_line_space:
007671C4  8B0E            mov  ecx, [esi]
007671C6  8B01            mov  eax, [ecx]
007671C8  6A01            push 1
007671CA  6800A0A200      push DAT_00a2a000        ; " "
007671CF  FF5018          call dword [eax+0x18]
007671D2  094604          or   [esi+0x04], eax
007671D5  83462001        add  dword [esi+0x20], 1
; write_body:
007671D9  8B0E            mov  ecx, [esi]
007671DB  8B11            mov  edx, [ecx]
007671DD  57              push edi                 ; len
007671DE  8D44240C        lea  eax, [esp+0xC]      ; buf
007671E2  50              push eax
007671E3  FF5218          call dword [edx+0x18]
007671E6  094604          or   [esi+0x04], eax
007671E9  017E20          add  [esi+0x20], edi
007671EC  8B4604          mov  eax, [esi+0x04]
007671EF  5F              pop  edi
007671F0  5E              pop  esi
007671F1  81C400040000    add  esp, 0x400
007671F7  C3              ret
```

**String seals:**

| Address | Hex / ASCII | Role |
|---|---|---|
| `0x00a97b84` | `0d 0a 00 00` → `"\r\n"` | Wrap emit, len 2 |
| `0x00a2a000` | `20 00 00 00` → `" "` | Mid-line separator, len 1 |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Writer in **EAX** (`mov esi,eax`) | **High** | Entry + EndChunk call site |
| `textCol` @ `+0x20`, status @ `+0x04` | **High** | Matches writer layout from EndChunk dual |
| Wrap threshold **0x78** exclusive (`>`) | **High** | `cmp eax,0x78; jle skip` |
| Wrap writes CRLF then forces col=0 | **High** | DAT + `mov [esi+0x20],0` |
| Line-start indent via `FUN_00767070` | **High** | call when col==0 |
| Mid-line single space + col++ | **High** | DAT space, len 1 |
| Body write uses raw `vsnprintf` length | **High** | `push edi` |
| Status OR; return status | **High** | `or [esi+4]; mov eax,[esi+4]` |
| Stream write slot `vt+0x18` | **High** | same as EndChunk |
| Product English name | **Low** | structural name only |
| Safe on negative `vsnprintf` return | **Low** | no clamp |
| Indent policy details | **Medium** | owned by `FUN_00767070` residual |

---

## 5. Control flow: clean ≡ raw ≡ decompile ≡ asm

| Stage | Match |
|---|---|
| vsnprintf(buf, 0x400, fmt, va) | **Yes** |
| if col>0 && col+1+len>0x78: col=0; write CRLF | **Yes** |
| if col==0: indent else space+col++ | **Yes** |
| write(buf,len); col+=len; ret status | **Yes** |

Clean preserves decompiler CF and immediates; register ABI documented in header.

---

## 6. Call graph (this unit)

**Callees**

| Target | Role |
|---|---|
| `_vsnprintf` | format |
| stream `vt+0x18` | write |
| `FUN_00767070` | indent at column 0 |

**Callers (sample, out of scope):** `stoChunkWriter_EndChunk` text path; geometry/serialize text writers (`gfxGeometryPiece_Serialize` notes).

---

## 7. Gaps / open

1. Product plate name in `arda2/storage/stoChunk.cpp`.
2. Full indent helper contract (`FUN_00767070` — depth field, space count).
3. `_vsnprintf` truncation / negative return handling (none in body).
4. Runtime / bit-exact image diff not run.
5. Whether any binary-mode path ever reaches this helper.

**Verdict:** **accept-with-gaps**
