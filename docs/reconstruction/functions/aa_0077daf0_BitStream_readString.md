# Function record: BitStream_readString

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077daf0` |
| **Canonical name** | `BitStream_readString` |
| **Address** | `0x0077daf0`–`0x0077dc13` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | net / TNL BitStream string |
| **Completion status** | **Dual-sealed accept-with-gaps** (W20-K 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Status |
|---|---|
| `FUN_0077daf0` | Ghidra scaffold |
| `Named_CalleeOf_Named_CalleeOf_Mission_Received_Connect_Request_0077daf0` | legacy chain alias — incomplete |
| `BitStream_readString` | **Structural sealed** (TNL-style; PDB open) |

## Purpose

Length-prefixed C-string read from BitStream:

- Lazy Huffman table init (`DAT_00d17a28` / `FUN_0077d520`).
- Flag bit selects **Huffman** (tree `DAT_00d1eab0`, alphabet `DAT_00d1eabc`) vs **raw** (`u8` len + `len*8` bits).
- Always returns `1`; overflow sets stream error `@+0x1c` then still decodes raw path when flag arm not taken.

## Signature (machine)

```c
// ESI = BitStream* this; stack char* out; plain RET (caller cleans 4)
uint32_t BitStream_readString(char* out);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0077daf0_FUN_0077daf0.md`
- Annotated: `docs/reconstruction/raw/aa_0077daf0_FUN_0077daf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BitStream_readString.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0077daf0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0077daf0_BitStream_readString.md`
- Review B: `docs/reconstruction/reviews/B_aa_0077daf0_BitStream_readString.md`

## Callers / callees

| Dir | Symbol | VA / note |
|---|---|---|
| caller | `BitStream_readStringCached` | `0x0042ba90` sites `0x0042baa6`, `0x0042bb12` |
| callee | `FUN_0077d520` | Huffman once-init |
| callee | `BitStream_readBits` | length + raw payload |

## Confidence

| Claim | Level |
|---|---|
| Control flow (flag / Huffman / raw) | **High** |
| ESI = BitStream*, stack out, RET | **High** |
| Tree 8 B / alphabet 0xc / char@+5 | **High** |
| Product PDB name | **Open** (structural TNL) |
| Runtime table contents | **Open** |
