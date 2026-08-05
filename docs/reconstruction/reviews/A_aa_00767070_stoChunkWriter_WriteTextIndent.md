# Review A (reconstruction fidelity): `aa_00767070` stoChunkWriter_WriteTextIndent

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767070` |
| **VA** | `0x00767070`–`0x0076709d` |
| **Canonical name** | `stoChunkWriter_WriteTextIndent` |
| **Prior scaffold** | `FUN_00767070` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W17-R |
| **Counterpart** | `reviews/B_aa_00767070_stoChunkWriter_WriteTextIndent.md` |
| **System** | `storage` / arda2 `stoChunk` |
| **Verdict** | **accept-with-gaps** — ABI, indent math, DAT space, status OR sealed; product English open |

**Tools:** Ghidra `decompile_function` + `read_memory` (body, DAT_00a2a000, WriteFormatted call site) + `get_function_by_address` / callers / xrefs. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Emit **text-mode indentation** for a `stoChunkWriter` at the start of a line:

1. Read nest **depth** (`writer+0x18`).
2. `count = depth * 4` (4 spaces per nesting level).
3. Store `textCol = count` (`writer+0x20`) so subsequent WriteFormatted body text continues past the indent.
4. Write `count` single ASCII spaces through the stream write vfunc (`vtbl+0x18`).
5. Sticky-OR write statuses into `writer+0x04`; return that status.

Sole caller: `stoChunkWriter_WriteFormatted` (`0x00767160`) when `textCol == 0` after optional wrap.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00767070_FUN_00767070.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00767070_FUN_00767070.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkWriter_WriteTextIndent.cpp` |
| Function record | `docs/reconstruction/functions/aa_00767070_stoChunkWriter_WriteTextIndent.md` |
| Live decompile | Ghidra `decompile_function` `0x00767070` — **≡** raw |
| Live bytes | `read_memory` `0x00767070` length 96 (body ends `C3` @ `0x0076709d`) |
| DAT | `read_memory` `0x00a2a000` → `20 00 00 00` (`" "`) |
| Call site | `read_memory` `0x007671b0` — `cmp [esi+0x20],0` / `call FUN_00767070` / `or [esi+4],eax` |
| Sibling context (not owned) | WriteFormatted dual `A/B_aa_00767160`; EndChunk dual (depth/textCol layout) |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **Register**: writer in **ESI** |
| Stack args | **none** |
| Epilogue | plain **`RET`** (`C3`) |
| Return | **status** (`[esi+0x04]`) in **EAX** |
| Body | `0x00767070`–`0x0076709d` |

```c
// Canonical sealed signature (register ABI)
uint32_t stoChunkWriter_WriteTextIndent(/* ESI: StoChunkWriter* writer */);
```

Ghidra prototype `void` / no params — **ESI live-in** is not modeled; call site and body field accesses own the ABI.

**Entry / loop / ret (`read_memory`):**

```
8B 46 18          mov  eax, [esi+0x18]     ; depth
03 C0  03 C0      eax *= 4
89 46 20          mov  [esi+0x20], eax     ; textCol
83 E8 01  78 1B   sub eax,1 / js skip      ; count==0 → no loop
…                 loop: write(" ",1); or status; dec; jnz
8B 46 04  C3      mov eax,[esi+4] / ret
```

**Caller proof (`WriteFormatted` keeps writer in ESI from entry `mov esi,eax`):**

```
007671B4  837E2000        cmp  [esi+0x20], 0
007671B8  750A            jnz  mid_line_space
007671BA  E8B1FEFFFF      call FUN_00767070
007671BF  094604          or   [esi+0x04], eax   ; double-OR; idempotent
```

### 3.2 Indent math — **SEALED**

```
count   = depth * 4          // two add-eax,eax (= shl 2)
textCol = count              // always, even when count==0
spaces  = count writes of 1 byte from DAT_00a2a000
```

| Depth | Spaces written | textCol after |
|---:|---:|---:|
| 0 | 0 | 0 |
| 1 | 4 | 4 |
| 2 | 8 | 8 |
| n | 4n | 4n |

Zero-count path: `sub eax,1` then **`js`** skips the loop — matches decomp `if (-1 < iVar2 + -1)`.

### 3.3 Stream write — **SEALED**

```
ecx = [esi]           ; stream*
eax = [ecx]           ; vtbl
push 1
push DAT_00a2a000     ; " "
call [eax+0x18]       ; write(buf, len)
or [esi+4], eax       ; sticky status
```

Same `vt+0x18` write contract as WriteFormatted mid-line space and EndChunk text path.

### 3.4 DAT_00a2a000 — **SEALED**

`read_memory` @ `0x00a2a000`: first byte `0x20`, then zeros → C string `" "`. Shared with WriteFormatted mid-line separator.

### 3.5 Writer field map (this unit) — **SEALED**

| Off | Role | Confidence |
|---:|---|---|
| `+0x00` | stream* | **High** |
| `+0x04` | status sticky | **High** |
| `+0x18` | depth | **High** (bytes + EndChunk dual) |
| `+0x20` | textCol | **High** (bytes + WriteFormatted dual) |

### 3.6 Three-rep CF fidelity

| Pass | Source | Match |
|---|---|---|
| Raw 2026-07-23 | `raw/aa_00767070_FUN_00767070.md` | baseline |
| Live re-decompile 2026-07-29 | `decompile_function` | **≡** raw |
| Bytes | `read_memory` full body | ABI + math + DAT + RET sealed |
| Call site | WriteFormatted @ `0x007671ba` | ESI writer + status OR |

---

## 4. Call graph (inventory)

| Direction | Symbol | VA | Note |
|---|---|---|---|
| Callee | stream write `vt+0x18` | — | virtual |
| Caller | `stoChunkWriter_WriteFormatted` | `0x00767160` | sole xref |

---

## 5. Gaps / open

1. Product English name in retail source plate.
2. Whether any other call path loads ESI differently (currently **one** xref only).
3. Runtime / bit-exact image diff not run.
4. Full stream interface type (beyond write slot) — out of scope.

---

## 6. Verdict

**accept-with-gaps** — indent contract, ESI ABI, field offsets, and DAT space are High confidence; product naming + runtime open.
