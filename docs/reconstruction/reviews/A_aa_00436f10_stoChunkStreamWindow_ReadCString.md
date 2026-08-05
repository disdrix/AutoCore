# Review A (reconstruction fidelity): `aa_00436f10` stoChunkStreamWindow_ReadCString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436f10` |
| **VA** | `0x00436f10`–`0x00436f7b` (**108 B** / `0x6C`) |
| **Canonical name** | `stoChunkStreamWindow_ReadCString` |
| **Prior scaffold** | `FUN_00436f10` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W38-D |
| **Counterpart** | `reviews/B_aa_00436f10_stoChunkStreamWindow_ReadCString.md` |
| **System** | `storage` / arda2 `stoChunk` stream window |
| **Verdict** | **accept-with-gaps** — ESI/EDI/bare-RET ABI, streamEnd loop, ensure, NUL consume, 0/−1 sealed; product English + ensure body open |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `force_decompile` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + assembly context on call sites. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Read a **NUL-terminated C-string** from a stoChunk **binary** stream window into a caller-owned `std::string`:

1. Clear dest via `string::resize(out, 0)`.
2. While `cursor + base < streamEnd`, ensure ≥1 byte, read, advance cursor.
3. On `NUL`: return 0 (terminator consumed, not stored).
4. Else append char and continue.
5. Hit streamEnd without NUL → −1.

Used on binary paths (mode `reader+0x4044 == 0`); text mode uses `FUN_0076a200` via wrappers.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00436f10_FUN_00436f10.md` (+ v2026-08-04 append) |
| Annotated | `docs/reconstruction/raw/aa_00436f10_FUN_00436f10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkStreamWindow_ReadCString.cpp` |
| Function record | `docs/reconstruction/functions/aa_00436f10_stoChunkStreamWindow_ReadCString.md` |
| Live decompile | Ghidra `decompile_function` `0x00436f10` — **≡** raw |
| Force decompile | `force_decompile` `0x00436f10` — **≡** live |
| Live bytes | `read_memory` `0x00436f10` length 256 (body ends dual `C3` before `CC` @ `0x00436f7c`) |
| Call sites | wrapper `FUN_00439a20`; direct `0x00458b88`, `0x00971d75`, … |
| Sibling context (not owned) | Ensure `FUN_00435df0`; text peer `FUN_0076a200`; ReadU8 `0x00437000` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Window | **ESI** on entry |
| Out string | **EDI** on entry |
| Epilogue | bare **`RET`** (`C3`) |
| Return | **0** success; **`0xffffffff`** fail |
| Body | `0x00436f10`–`0x00436f7b` |
| Stack args | none |

```c
int32_t stoChunkStreamWindow_ReadCString(
    /* ESI */ StoStreamWindow* window,
    /* EDI */ std::string* out);
```

**Caller proof (mode wrapper `FUN_00439a20`):**

```
cmp  dword [ebx+0x4044], 0
jnz  text
lea  esi, [ebx+0x14]     ; window
mov  edi, ecx            ; string*
call FUN_00436f10
```

**Caller proof (direct binary `0x00458b88`):**

```
lea  esi, [ebp+0x14]
lea  edi, [esp+0x30]
call FUN_00436f10
```

### 3.2 streamEnd gate + loop — **SEALED**

```
if (cursor + base >= streamEnd) return -1;
do {
  // ensure / read / append or NUL
} while (cursor + base < streamEnd);
return -1;
```

| Fact | Confidence |
|---|---|
| Pre-check and continue use `window+0x14` as streamEnd | **High** |
| Signed compares (`jge` / `jl`) | **High** |
| Fail if exhausted without NUL | **High** |

### 3.3 Ensure gate — **SEALED** (call shape); ensure body **out of scope**

```
if (available < cursor + 1) {
  push (base + cursor);
  mov  ecx, window;
  call FUN_00435df0;
  if (eax < 0 || available < 1) return -1;
}
```

### 3.4 NUL consume + append — **SEALED**

```
c = *(u8*)(window + 0x18 + cursor)
cursor += 1
if (c == 0) return 0
operator+=(out, c)
```

| Fact | Confidence |
|---|---|
| NUL advances cursor and returns 0 without append | **High** |
| Non-NUL uses IAT `operator+=` | **High** |
| `resize(out,0)` first | **High** |

### 3.5 Three-rep — **SEALED**

| Stage | Match |
|---|---|
| raw 2026-07-23 | Yes |
| live `decompile_function` | ≡ raw |
| `force_decompile` | ≡ live |
| body bytes CF | ≡ decompiler math |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF: clear → streamEnd loop → ensure → NUL/append → 0/−1 | **High** | raw ≡ force ≡ bytes |
| ESI=window, EDI=string*, bare RET | **High** | body + call sites |
| Window +4/+8/+c/+14/+18 map | **High** | matches Ensure / ReadHeader16 |
| Binary-mode role | **High** | wrappers gate +0x4044 |
| Product English CString vs StringZ | **Probable** | behavior sealed |
| Ensure body | **Out of scope** | other VA |
| Runtime / bit-exact | **Open** | not run |

---

## 5. Gaps / open

1. Product / PDB name.
2. Ensure full contract (`FUN_00435df0` — not owned).
3. streamEnd when length unknown (shared with Ensure).
4. Runtime live verification / bit-exact image diff.

**Verdict:** CF + ABI + streamEnd loop + NUL consume sealed. **accept-with-gaps.**
