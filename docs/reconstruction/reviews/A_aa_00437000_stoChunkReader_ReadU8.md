# Review A (reconstruction fidelity): `aa_00437000` stoChunkReader_ReadU8

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437000` |
| **VA** | `0x00437000`–`0x00437048` (**73 B** / `0x49`) |
| **Canonical name** | `stoChunkReader_ReadU8` |
| **Prior scaffold** | `FUN_00437000` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W38-D |
| **Counterpart** | `reviews/B_aa_00437000_stoChunkReader_ReadU8.md` |
| **System** | `storage` / arda2 `stoChunk` |
| **Verdict** | **accept-with-gaps** — EAX/EDI/bare-RET ABI, 1 B copy, ensure gate, returns sealed; fail-path *out spill + product English open |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `force_decompile` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + assembly context on call sites. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Read the next **1-byte** value from a stoChunk **binary** stream into a caller-provided `uint8_t*`:

1. Ensure at least 1 byte remains from the current cursor (refill via `FUN_00435df0` if short).
2. Copy one byte from the window buffer.
3. Advance cursor by 1.
4. Return `0` or `−1`.

Used on binary paths (mode `reader+0x4044 == 0`); text mode uses `FUN_00769660` via dispatcher `FUN_00439a50`. Immediate neighbor is `stoChunkReader_ReadU32` @ `0x00437050`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00437000_FUN_00437000.md` (+ v2026-08-04 append) |
| Annotated | `docs/reconstruction/raw/aa_00437000_FUN_00437000.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_ReadU8.cpp` |
| Function record | `docs/reconstruction/functions/aa_00437000_stoChunkReader_ReadU8.md` |
| Live decompile | Ghidra `decompile_function` `0x00437000` — **≡** raw (ESI remap omitted in C view) |
| Force decompile | `force_decompile` `0x00437000` — **≡** live |
| Live bytes | `read_memory` `0x00437000` length 80 (body ends `C3` @ `0x00437048`) |
| Call sites | wrapper `FUN_00439a50`; direct `0x00765caa`, `0x00964054`, … |
| Sibling context (not owned) | ReadU32 `aa_00437050`; ensure `FUN_00435df0`; text peer `FUN_00769660` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Reader | **EAX** on entry |
| Out byte | **EDI** on entry |
| Epilogue | bare **`RET`** (`C3`) |
| Return | **0** success; **`0xffffffff`** fail |
| Body | `0x00437000`–`0x00437048` |
| Window remap | `add esi, 0x14` after `mov esi, eax` |

```c
int32_t stoChunkReader_ReadU8(
    /* EAX */ StoChunkReader* reader,
    /* EDI */ uint8_t* out);
```

**Contrast with ReadU32:** that sibling uses **stack** out + **`RET 4`**. This leaf uses **EDI** out + bare **RET**.

**Caller proof (mode wrapper `FUN_00439a50`):**

```
cmp  dword [eax+0x4044], 0
jnz  text
mov  edi, ecx              ; out*
call FUN_00437000          ; EAX = reader
```

**Caller proof (direct binary `0x00765caa`):**

```
lea  edi, [esp+0x74]
mov  eax, ebp              ; reader
call FUN_00437000
```

### 3.2 Ensure gate — **SEALED** (call shape); ensure body **out of scope**

```
if (available < cursor + 1) {
  push (base + cursor);
  mov  ecx, window;          // thiscall window = reader+0x14
  call FUN_00435df0;
  if (eax < 0 || available < 1) { /* fail */ }
}
```

| Fact | Confidence |
|---|---|
| Trigger: `available < cursor+1` | **High** |
| Ensure arg = `base + cursor` | **High** |
| Ensure thiscall ECX = window | **High** |
| Fail if `eax < 0` **or** `available < 1` after | **High** |
| Full refill semantics of `FUN_00435df0` | **Not owned** |

### 3.3 Copy + advance — **SEALED**

```
*out = *(u8*)(window + 0x18 + cursor)
cursor += 1
return 0
```

| Fact | Confidence |
|---|---|
| Single byte load | **High** |
| Buffer base = window+0x18 = reader+0x2c | **High** |
| Cursor field window+0x04 = reader+0x18 | **High** |

### 3.4 Fail-path *out write — **SEALED as coded** (product meaning open)

```
mov  cl, [esp+7]     ; high byte of entry-ECX push slot
or   eax, -1
mov  [edi], cl
```

| Fact | Confidence |
|---|---|
| Fail **does** store to `*out` before −1 | **High** (bytes) |
| Value is stack spill of entry ECX high byte | **High** |
| Product-intended default | **Reject** — treat as undefined |
| ReadU32 leaves *out untouched on fail | **Contrast sealed** (sibling, not owned body re-proof) |

### 3.5 Three-rep — **SEALED**

| Stage | Match |
|---|---|
| raw 2026-07-23 | Yes |
| live `decompile_function` | ≡ raw |
| `force_decompile` | ≡ live |
| body bytes CF | ≡ decompiler math (reader-relative); **bytes win** on ESI remap + EDI out |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF: ensure-if-short → copy 1 → cursor+=1 → 0/−1 | **High** | raw ≡ force ≡ bytes |
| EAX=reader, EDI=out, bare RET | **High** | body + call sites |
| Window @ +0x14 field map | **High** | matches ReadU32 |
| Binary-mode role | **High** | dispatcher + call sites |
| Fail *out spill non-product | **High** (as coded) | port may omit write |
| Product English U8 vs bool | **Probable** | width sealed; text peer says bool |
| Ensure body | **Out of scope** | other VA |
| Runtime / bit-exact | **Open** | not run |

---

## 5. Gaps / open

1. Product / PDB name (U8 vs bool).
2. Ensure full contract (`FUN_00435df0` — not owned).
3. Whether any caller reads `*out` after −1 (should not).
4. Runtime live verification / bit-exact image diff.

**Verdict:** CF + ABI + window map + role sealed. **accept-with-gaps.**
