# Review A (reconstruction fidelity): `aa_00437050` stoChunkReader_ReadU32

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437050` |
| **VA** | `0x00437050`–`0x00437095` |
| **Canonical name** | `stoChunkReader_ReadU32` |
| **Prior scaffold** | `FUN_00437050` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W18-N |
| **Counterpart** | `reviews/B_aa_00437050_stoChunkReader_ReadU32.md` |
| **System** | `storage` / arda2 `stoChunk` |
| **Verdict** | **accept-with-gaps** — EAX/stack/RET4 ABI, 4 B copy, ensure gate, returns sealed; ensure body + product English open |

**Tools:** Ghidra `decompile_function` + `force_decompile` + `read_memory` (body + call sites) + `get_function_by_address` / callers / callees / xrefs. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Read the next **4-byte little-endian dword** from a stoChunk **binary** stream into a caller-provided `uint32_t*`:

1. Ensure at least 4 bytes remain from the current cursor (refill via `FUN_00435df0` if short).
2. Copy one dword from the window buffer.
3. Advance cursor by 4.
4. Return `0` or `−1`.

Used on binary paths (mode `reader+0x4044 == 0`); text mode uses `FUN_007689e0` via dispatcher `FUN_00436900`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00437050_FUN_00437050.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00437050_FUN_00437050.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_ReadU32.cpp` |
| Function record | `docs/reconstruction/functions/aa_00437050_stoChunkReader_ReadU32.md` |
| Live decompile | Ghidra `decompile_function` `0x00437050` — **≡** raw |
| Force decompile | `force_decompile` `0x00437050` — **≡** live |
| Live bytes | `read_memory` `0x00437050` length 80 (body ends `C2 04 00` @ `0x00437093`) |
| Call sites | `FUN_00436900` entry; OpenChunk @ `0x0076a650` region |
| Sibling context (not owned) | ReadHeader16 `aa_004368b0`; ensure `FUN_00435df0`; text peer `FUN_007689e0` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Reader | **EAX** on entry |
| Out dword | stack arg (`[esp+8]` after `push esi`) |
| Epilogue | **`RET 4`** (`C2 04 00`) |
| Return | **0** success; **`0xffffffff`** fail |
| Body | `0x00437050`–`0x00437095` |
| Window remap | `add esi, 0x14` after `mov esi, eax` |

```c
int32_t stoChunkReader_ReadU32(
    /* EAX */ StoChunkReader* reader,
    /* stack */ uint32_t* out);
```

**Caller proof (mode dispatcher):**

```
cmp  dword [eax+0x4044], 0
jnz  text
push ecx                 ; out*
call FUN_00437050        ; EAX = reader
ret
```

**Caller proof (OpenChunk binary):**

```
lea  ecx, [esp+0x20]
push ecx
mov  eax, ebp            ; reader
call FUN_00437050
or   [ebp+0x402c], eax   ; sticky status
```

### 3.2 Ensure gate — **SEALED** (call shape); ensure body **out of scope**

```
if (available < cursor + 4) {
  push (base + cursor);
  mov  ecx, window;          // thiscall window = reader+0x14
  call FUN_00435df0;
  if (eax < 0 || available < 4) return -1;
}
```

| Fact | Confidence |
|---|---|
| Trigger: `available < cursor+4` (`jle` enough when `available >= cursor+4`) | **High** |
| Ensure arg = `base + cursor` | **High** |
| Ensure thiscall ECX = window | **High** |
| Fail if `eax < 0` **or** `available < 4` after | **High** |
| Full refill semantics of `FUN_00435df0` | **Not owned** |

### 3.3 Copy + advance — **SEALED**

```
*out = *(u32*)(window + 0x18 + cursor)
cursor += 4
return 0
```

| Fact | Confidence |
|---|---|
| Single dword LE load | **High** |
| Buffer base = window+0x18 = reader+0x2c | **High** |
| Cursor field window+0x04 = reader+0x18 | **High** |

### 3.4 Three-rep — **SEALED**

| Stage | Match |
|---|---|
| raw 2026-07-23 | Yes |
| live `decompile_function` | ≡ raw |
| `force_decompile` | ≡ live |
| body bytes CF | ≡ decompiler math (reader-relative) |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF: ensure-if-short → copy 4 → cursor+=4 → 0/−1 | **High** | raw ≡ force ≡ bytes |
| EAX=reader, stack out, RET 4 | **High** | body + call sites |
| Window @ +0x14 field map | **High** | matches ReadHeader16 |
| Binary-mode role | **High** | dispatcher + OpenChunk |
| Product English U32 vs I32 | **Probable** | width sealed; signedness call-site |
| Ensure body | **Out of scope** | other VA |
| Runtime / bit-exact | **Open** | not run |

---

## 5. Gaps / open

1. Product / PDB name.
2. Ensure full contract (`FUN_00435df0` — not owned).
3. Signed vs unsigned product typing of the dword.
4. Runtime live verification / bit-exact image diff.

**Verdict:** CF + ABI + window map + role sealed. **accept-with-gaps.**
