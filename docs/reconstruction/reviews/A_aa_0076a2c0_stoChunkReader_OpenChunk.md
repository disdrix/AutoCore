# Review A (reconstruction fidelity): `aa_0076a2c0` stoChunkReader_OpenChunk

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076a2c0` |
| **VA** | `0x0076a2c0` |
| **Body** | `0x0076a2c0`–`0x0076a8f9` |
| **Canonical name** | `stoChunkReader_OpenChunk` |
| **Review date** | `2026-07-29` (dual A/B seal; three-rep scaffold 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0076a2c0_stoChunkReader_OpenChunk.md` |
| **System** | `storage` / arda2 `stoChunk` (plate path) |
| **Verdict** | **accept-with-gaps** (CF + offsets + returns **High**; callee English / full ring element layout **Probable**) |

**Tools:** Ghidra `decompile_function` `0x0076a2c0` (+ callees `0x004368b0`, `0x00436340`, `0x00769b70` as context only) + `read_memory` prologue / success tail. No `disassemble_bytes`. No ledgers.

---

## 1. Purpose

Open the next **storage chunk** on a `stoChunkReader`: read the chunk **header**, then **push** it onto the reader's circular chunk ring. Two modes selected by `this+0x4044`:

| Mode | Gate | Header source | Success |
|---|---|---|---|
| **Binary** | `*(this+0x4044) == 0` | 16-byte LE header via `FUN_004368b0` | ring push + **return 0** |
| **Text** | `*(this+0x4044) != 0` | tokens `CHUNK` / FOURCC tag / version / `{` | same ring push + **return 0** |

Sticky error flag `this+0x402c` is OR'd with stage status; signed-negative sticky → fail paths return **`0xffffffff`** and log via `vog_LogMessage` (`stoChunk.cpp` line numbers in plate strings).

Plate (Ghidra):

```
stoChunkReader::OpenChunk()  [arda2\storage\stoChunk.cpp:~0x1d4]
Reads the next chunk header and pushes it on the reader's chunk ring (this+0x4034..0x4040).
Handles both binary (16-byte {tag,size,version,reserved} header) and text mode
(parses CHUNK "TAG" version { ...). this+0x4044 selects text mode; this+0x402c sticky error.
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0076a2c0_stoChunkReader_OpenChunk.md` |
| Annotated | `docs/reconstruction/raw/aa_0076a2c0_stoChunkReader_OpenChunk.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_OpenChunk.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076a2c0_stoChunkReader_OpenChunk.md` |
| Live decompile | Ghidra `decompile_function` `0x0076a2c0` — body ≡ raw 2026-07-23 |
| Prologue bytes | `read_memory` `0x0076a2c0` length 64 |
| Success tail | `read_memory` `0x0076a8d6` length 32 |
| Callers API | `get_function_callers` → `stoChunkReader_EnterChunkScope` `0x004370b0`, `FUN_0076a900`, `FUN_009615c0` |

---

## 3. Entry / layout seal

### 3.1 Calling convention — **High**

Prologue (`read_memory` @ `0x0076a2c0`):

```
6A FF                 push -1
64 A1 00 00 00 00     mov  eax, fs:[0]          ; SEH frame
68 38 0B 9B 00        push LAB_009b0b38
50                    push eax
64 89 25 00 00 00 00  mov  fs:[0], esp
83 EC 38              sub  esp, 0x38
53 55                 push ebx / ebp
8B E9                 mov  ebp, ecx             ; this = ECX
83 BD 44 40 00 00 00  cmp  dword [ebp+0x4044], 0
56 57                 push esi / edi
75 2B                 jnz  text_mode
8D 75 14              lea  esi, [ebp+0x14]      ; stream window base
8D 7C 24 18           lea  edi, [esp+0x18]      ; 16-byte header out
E8 …                  call FUN_004368b0
09 85 2C 40 00 00     or   [ebp+0x402c], eax    ; sticky |= status
0F 8C …               jl   fail                 ; signed sticky < 0
```

| Claim | Confidence | Evidence |
|---|---|---|
| `this` in **ECX** (`__fastcall` / thiscall-style) | **High** | `mov ebp, ecx` then all field access via `ebp` |
| Mode gate `this+0x4044` | **High** | `cmp [ebp+0x4044],0` / plate / text branch |
| Sticky error `this+0x402c` | **High** | `or [ebp+0x402c],eax`; text logs write `0xffffffff` same offset |
| Binary stream window base `this+0x14` | **High** | `lea esi,[ebp+0x14]` before header read |
| Header stack out @ `[esp+0x18]` after setup | **High** | `lea edi,[esp+0x18]`; shared with text FOURCC pack dest |

### 3.2 Stream window offsets (relative to `this+0x14` → absolute)

Matches callee `FUN_004368b0` (ESI = window) and text-path uses of the same fields:

| Window rel | Absolute | Role (from CF) | Confidence |
|---:|---:|---|---|
| `+0x4` | `this+0x18` | read cursor | **High** |
| `+0x8` | `this+0x1c` | base / file offset partner | **High** |
| `+0xc` | `this+0x20` | remaining / available | **High** |
| `+0x18` | `this+0x2c` | data buffer base (byte `*(this+0x2c + cursor)`) | **High** |

Binary read requires **16** free bytes (`FUN_004368b0`: compare remaining vs `cursor+0x10`, then copy 4 dwords and advance cursor by `0x10`).

### 3.3 Binary header — **High** (layout from plate + 16 B copy)

`FUN_004368b0` copies **4×u32** from `window+0x18+cursor` → EDI:

| Word | Plate field |
|---|---|
| 0 | tag (FOURCC) |
| 1 | size |
| 2 | version |
| 3 | reserved |

Exact field names beyond plate are **Probable**; width/order of the 16-byte block is **High**.

### 3.4 Chunk ring push — **High** (base), **Probable** (slot fields)

Success join `LAB_0076a8d6` (`read_memory` @ `0x0076a8d6`):

```
8D 85 30 40 00 00     lea  eax, [ebp+0x4030]    ; ring object base
8D 7C 24 18           lea  edi, [esp+0x18]      ; header in
E8 …                  call FUN_00436340
…                     xor  eax, eax             ; return 0
```

`FUN_00436340` treats `EAX` as ring with slots at `+4/+8/+c/+10` → absolute **`this+0x4034..0x4040`** (matches plate). Each ring element is **0x14** bytes (tag/size/version/reserved + one more dword from EDI[0..4]).

| Claim | Confidence |
|---|---|
| Ring object base `this+0x4030` | **High** (bytes) |
| Ring bookkeeping fields `+0x4034..0x4040` | **High** (plate + callee offsets) |
| Element size 0x14 / circular index math | **Probable** (callee body; not re-owned) |

---

## 4. Control flow stages

### 4.1 Binary path (`+0x4044 == 0`)

1. SEH setup; `FUN_004368b0` → 16 B header into stack; sticky `|=` status.
2. If sticky signed ≥ 0: compute end/cursor helper (`local_2c = *(this+0x1c)+*(this+0x18)+size_word`) then **goto** ring push.
3. Else fall through to shared fail: return `0xffffffff`.

No text tokenization, no `"CHUNK"` check on binary path.

### 4.2 Text path (`+0x4044 != 0`)

1. Construct local `std::string`; if sticky already negative → skip read with fail status.
2. **Token read** (or pending string at `this+0x404c` when `this+0x4060 != 0`):
   - Whitespace-skipping tokenizer; quote-aware (`'` / `"`); buffer fill from `this+0x2c+cursor`.
   - Token `"}"` → log *“Attempt to read past end of chunk…”* (line `0x2a0`), sticky fail, re-stash token into `+0x404c`.
3. Sticky fail after token → log *“Error finding chunk token”* (line `0x1d4`).
4. Else `_stricmp(token, "CHUNK")` must match; else log *Expected "CHUNK" keyword…* (line `0x1d9`) → `0xffffffff`.
5. `FUN_00769b70(this)` — read tag token (strips surrounding quotes when present); sticky fail → *Invalid chunk tag* (`0x1dd`).
6. Tag length must be **4** (`local_14 == 4`); else *Chunk tag not FOURCC* (`0x1e2`).
7. Pack 4 chars into u32 FOURCC (byte-reverse concat into `local_40` / `local_3c`).
8. Read version: dead-check of `+0x4044` again → text uses `FUN_007689e0`; binary helper `FUN_00437050` is **dead** on this entry branch unless mode flips mid-call (**does not** in body).
9. Second token must be `"{"`; errors: *Error reading text block marker* (`0x1f1`) / *Expected block marker "{"…* (`0x1f6`).
10. Destroy local string; **goto** ring push (same as binary success).

### 4.3 Returns — **High**

| Code | Meaning |
|---:|---|
| `0` | Header accepted and ring push invoked |
| `0xffffffff` (−1) | Any sticky-negative / parse error path |

Clean ≡ raw ≡ live decompile on all return sites.

---

## 5. CF fidelity: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Mode gate `+0x4044` | **Yes** |
| Binary 16 B read + sticky OR | **Yes** |
| Text CHUNK / FOURCC / `{` pipeline + logs | **Yes** |
| Ring push join + return 0 | **Yes** |
| Fail return −1 | **Yes** |
| Pending-token path `+0x404c` / `+0x4060` | **Yes** (CF present; English **Probable**) |

No plate-only drift found that invents behavior (unlike some heartbeat units). Clean remains a behavior-preserving scaffold of decompiler CF (not modernized).

---

## 6. Callers (owned unit only — inventory)

| Caller | VA | Note |
|---|---|---|
| `stoChunkReader_EnterChunkScope` | `0x004370b0` | Named sibling; typical open-scope entry |
| `FUN_0076a900` | `0x0076a900` | Unowned follow-up |
| `FUN_009615c0` | `0x009615c0` | Unowned follow-up |

`xref_count` inventory = 3 — matches `get_function_callers`. Full call-site register audit **not** required for accept-with-gaps on this leaf parser.

---

## 7. Gaps / open

1. Product English names for `FUN_004368b0` (binary ReadHeader), `FUN_00436340` (PushChunkRing), `FUN_00769b70` (text ReadQuotedTag), `FUN_007689e0` / `FUN_00437050` (read version), `FUN_0076cec0` (format string helper) — **not renamed in this unit**.
2. Exact semantic of `this+0x4060` (pending-token enable) beyond “non-zero uses `+0x404c` instead of stream”.
3. Full ring capacity / wrap formula (owned by `FUN_00436340`, not this VA).
4. Binary header word names beyond plate `{tag,size,version,reserved}`.
5. Runtime / bit-exact / differential — open.
6. Text-path re-check of `+0x4044` before version read is **dead on normal entry** — residual noise only.

**Verdict:** **accept-with-gaps**
