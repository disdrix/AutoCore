# Function record: BitStream_writeString

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077d960` |
| **Canonical name** | `BitStream_writeString` |
| **Ghidra name** | `FUN_0077d960` |
| **Address** | `0x0077d960`–`0x0077daec` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | net / TNL BitStream string |
| **Completion status** | **Dual A/B sealed** (W21-C 2026-07-29) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Status |
|---|---|
| `FUN_0077d960` | Ghidra scaffold |
| `Named_CalleeOf_Named_CalleeOf_Mission_Sending_Connect_Request_0077d960` | legacy chain alias — incomplete |
| `BitStream_writeString` | **Structural sealed** (TNL-style; PDB open) |

## Purpose

Length-prefixed C-string **write** to BitStream:

- Null string → flag 0 + u8 length 0.
- Lazy Huffman table init (`DAT_00d17a28` / `FUN_0077d520`).
- Cost compare: if `len*8 <= Σ alphabet[c].bitLen` → raw flag0 + bits; else Huffman flag1 + per-char codes.
- Always returns `1`.

Wrapped by `BitStream_writeStringCached` (`0x0042bb40`). Read twin `BitStream_readString` (`0x0077daf0`).

## Signature (machine)

```c
// EAX = BitStream* this; EBX = const char* str; stack maxLen; plain RET (caller cleans 4)
uint32_t BitStream_writeString(uint32_t maxLen);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0077d960_FUN_0077d960.md`
- Annotated: `docs/reconstruction/raw/aa_0077d960_FUN_0077d960.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BitStream_writeString.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0077d960.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0077d960_BitStream_writeString.md`
- Review B: `docs/reconstruction/reviews/B_aa_0077d960_BitStream_writeString.md`

## Callers / callees

| Dir | Symbol | VA / note |
|---|---|---|
| caller | `BitStream_writeStringCached` | `0x0042bb40` (only) |
| callee | `FUN_0077d520` | Huffman once-init |
| callee | `FUN_0042b450` | capacity grow |
| callee | `BitStream_writeBits` | `0x0042b4a0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow (null / raw / Huffman) | **High** |
| EAX=bs, EBX=str, stack maxLen, always-1, RET | **High** |
| Alphabet 0xc / bitLen@+4 / code@+8 | **High** |
| Capacity bound `+0x30` (write) | **High** |
| Product PDB name | **Open** (structural TNL) |
| Runtime table contents | **Open** |
