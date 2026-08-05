# Review A (reconstruction fidelity): `aa_0077daf0` BitStream_readString

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077daf0` |
| **VA** | `0x0077daf0`–`0x0077dc13` |
| **Canonical name** | `BitStream_readString` |
| **Prior scaffold** | `FUN_0077daf0` |
| **Review date** | `2026-07-29` (W20-K OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction fidelity — Path A |
| **Counterpart** | `reviews/B_aa_0077daf0_BitStream_readString.md` |
| **System** | net / TNL BitStream string |
| **Verdict** | **accept-with-gaps** — ABI, CF, Huffman/raw arms, globals sealed; product English + runtime tables open |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + globals). No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Base **BitStream C-string decoder** (no cache):

1. Once-init Huffman tables when `DAT_00d17a28 == 0`.
2. Consume encoding flag bit:
   - **1:** Huffman — u8 length, per-char tree walk, alphabet leaf → byte, NUL.
   - **0 / overflow:** raw — u8 length, `readBits(len*8)`, NUL.
3. Always return `1`.

Wrapped by `BitStream_readStringCached` (`0x0042ba90`) for prefix-compressed strings.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0077daf0_FUN_0077daf0.md` (+ 2026-07-29 live) |
| Annotated | `docs/reconstruction/raw/aa_0077daf0_FUN_0077daf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_readString.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0077daf0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0077daf0_BitStream_readString.md` |
| Live decompile | `decompile_function` `0x0077daf0` — **≡** raw |
| Live bytes | `read_memory` `0x0077daf0` length 550; init/tree/alphabet globals |
| Callers | `BitStream_readStringCached` ×2 |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| ESI = BitStream* | field loads `[ESI+disp]` only; no ESI load |
| Stack `char* out` | `8B 5C 24 0C` |
| Epilogue | **`C3` RET** both arms (caller cleans 4) |
| Return | **`B0 01`** always |
| Body | Ghidra `0077daf0`–`0077dc13` |

```c
// ESI this; stack out; RET
uint32_t BitStream_readString(char* out);
```

### 3.2 Stream / global map — **SEALED**

| Rel / symbol | Role | Conf |
|---|---|---|
| bs `+0xc` | buffer | **High** |
| bs `+0x18` | bitPos | **High** |
| bs `+0x1c` | error | **High** |
| bs `+0x2c` | bitMax | **High** |
| `DAT_00d17a28` | once-init | **High** |
| `DAT_00d1eab0` | tree (8 B nodes, children +4/+6) | **High** |
| `DAT_00d1eabc` | alphabet (0xc stride, char +5) | **High** |

### 3.3 Key CF arms — **SEALED**

| Arm | Behavior |
|---|---|
| Init | `DAT_00d17a28==0` → `FUN_0077d520` |
| Overflow on flag | error=1 → raw path (no Huffman) |
| Flag 1 | u8 len + Huffman walk per char |
| Flag 0 | u8 len + raw bits |
| Leaf | negative node → alphabet byte |

### 3.4 Three-rep CF fidelity

| Pass | Match |
|---|---|
| Raw 2026-07-23 | baseline |
| Live re-decompile 2026-07-29 | **≡** raw |
| Bytes | RET, always-1, DAT ptrs, flag bit math |

---

## 4. Naming

| Name | Status |
|---|---|
| `BitStream_readString` | **Structural sealed** |
| `FUN_0077daf0` | scaffold alias |
| PDB product symbol | **Open** |

---

## 5. Gaps

1. Product/PDB English.
2. Runtime Huffman tree contents (BSS until first call).
3. Max string / buffer size contract (caller-owned).
4. Write twin `FUN_0077d960` not dual-sealed here.
5. Runtime / bit-exact / differential — open.

---

## 6. AutoCore port notes

- Port as TNL-compatible string decode under ghost/net unpack.
- Do **not** merge with `readStringCached` — cache flag + prefix is a separate layer.
- Must preserve ESI convention or convert to explicit `BitStream*` parameter in server ports.
