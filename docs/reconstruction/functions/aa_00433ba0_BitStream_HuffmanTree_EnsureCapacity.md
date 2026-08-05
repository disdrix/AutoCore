# Function record: BitStream_HuffmanTree_EnsureCapacity

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433ba0` |
| **Canonical name** | `BitStream_HuffmanTree_EnsureCapacity` |
| **Ghidra name** | `FUN_00433ba0` |
| **Address** | `0x00433ba0`–`0x00433bfe` (94 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | net / TNL BitStream Huffman |
| **Completion status** | **Sealed** W26-C dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Ensure Huffman tree container capacity ≥ need (8-byte nodes). Nested helper of `BitStream_HuffmanBuildTables`.

## Signature

```c
// this-in-EAX; RET 4
void BitStream_HuffmanTree_EnsureCapacity(HuffmanTreeContainer* self /*EAX*/, uint32_t needCount);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23
- Parent call sites load `EAX = 0x00d1eaa8`
- Dual A/B accept

## Artifacts

See `aa_00433ba0_FUN_00433ba0.md` for full artifact table.
