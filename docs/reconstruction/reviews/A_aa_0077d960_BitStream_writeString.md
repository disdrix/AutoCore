# Review A (reconstruction fidelity): `aa_0077d960` BitStream_writeString

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077d960` |
| **VA** | `0x0077d960`–`0x0077daec` |
| **Canonical name** | `BitStream_writeString` |
| **Prior scaffold** | `FUN_0077d960` |
| **Review date** | `2026-07-29` (W21-C OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction fidelity — Path A |
| **Counterpart** | `reviews/B_aa_0077d960_BitStream_writeString.md` |
| **System** | net / TNL BitStream string |
| **Verdict** | **accept-with-gaps** — ABI, CF, Huffman/raw arms, globals sealed; product English + runtime tables open |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + globals). No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Base **BitStream C-string encoder** (no cache) — write twin of sealed `BitStream_readString` (`0x0077daf0`):

1. Null `str` → flag bit **0**, u8 length **0**, return `1`.
2. Once-init Huffman when `DAT_00d17a28 == 0` → `FUN_0077d520`.
3. `len = min(strlen(str), maxLen)`.
4. Cost `Σ alphabet[c].bitLen` (`DAT_00d1eabc + c*0xc + 4`).
5. If `len*8 <= cost` → flag **0** + u8 len + raw `writeBits(len*8)`.
6. Else → flag **1** + u8 len + per-char Huffman `writeBits(bitLen, code@+8)`.
7. Always return `1`.

Wrapped by `BitStream_writeStringCached` (`0x0042bb40`) — **sole** static caller.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0077d960_FUN_0077d960.md` (+ W21-C live) |
| Annotated | `docs/reconstruction/raw/aa_0077d960_FUN_0077d960.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_writeString.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0077d960.cpp` |
| Function record | `docs/reconstruction/functions/aa_0077d960_BitStream_writeString.md` |
| Live decompile | `decompile_function` `0x0077d960` — **≡** raw |
| Live bytes | `read_memory` entry + null arm + Huffman exit; globals BSS |
| Twin | `BitStream_readString` dual (W20-K) |
| Caller | `get_function_callers` → only `0x0042bb40` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| EAX → EDI = BitStream* | `8B F8`; `[EDI+disp]` fields |
| EBX = const char* | `85 DB` null test; scans via EBX |
| Stack `maxLen` | `8B 6C 24 0C` after push ecx/ebp |
| Epilogue | `B0 01` + pops + **`C3` RET** (caller cleans 4) |
| Return | always **1** |
| Body | `0077d960`–`0077daec` |

```c
// EAX=bs; EBX=str; stack maxLen; RET caller-clean 4
uint32_t BitStream_writeString(uint32_t maxLen);
```

### 3.2 Stream / global map — **SEALED**

| Rel / symbol | Role | Conf |
|---|---|---|
| bs `+0xc` | buffer | **High** |
| bs `+0x18` | bitPos | **High** |
| bs `+0x30` | write capacity (grow `FUN_0042b450`) | **High** |
| `DAT_00d17a28` | once-init | **High** |
| `DAT_00d1eabc` | alphabet **0xc** stride; bitLen@+4; code@+8 | **High** |

### 3.3 Key CF arms — **SEALED**

| Arm | Behavior |
|---|---|
| Null str | flag=0, len=0, return 1 |
| Init | `DAT_00d17a28==0` → `FUN_0077d520` |
| Cost | sum bitLens; compare to `len*8` |
| Raw | flag=0, u8 len, raw bits |
| Huffman | flag=1, u8 len, per-char codes |
| Flag write | inline mask at `buf[bitPos>>3]` (clear OR set) |

### 3.4 Three-rep CF fidelity

| Pass | Match |
|---|---|
| Raw 2026-07-23 | baseline |
| Live re-decompile 2026-07-29 | **≡** raw |
| Bytes | null test, DAT cmp, always-1, RET |

---

## 4. Naming

| Name | Status |
|---|---|
| `BitStream_writeString` | **Structural sealed** (pairs with `BitStream_readString`) |
| `FUN_0077d960` | scaffold alias |
| PDB product name | **Open** |

---

## 5. Gaps

1. Product/PDB English.
2. Runtime Huffman alphabet contents (BSS until first call).
3. `FUN_0077d520` builder not dual-owned here.
4. maxLen vs buffer size contract (caller-owned).
5. Runtime / bit-exact / differential — open.

---

## 6. AutoCore port notes

- Port as TNL-compatible string encode under ghost/net pack.
- Do **not** merge with `writeStringCached` — prefix/cache is a separate layer.
- Preserve cost rule: raw when `len*8 <= huffmanCost` (equality → raw).
- Must map EAX/EBX register convention or convert to explicit parameters in C# ports.

**Verdict:** **accept-with-gaps**
