# Function record: BitStream_HuffmanTree_CopyRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433c60` |
| **Canonical name** | `BitStream_HuffmanTree_CopyRange` |
| **Ghidra name** | `FUN_00433c60` |
| **Address** | `0x00433c60`–`0x00433c92` (51 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | net / TNL BitStream Huffman |
| **Completion status** | **Sealed** W27-B dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Range-copy 8-byte tree nodes during Huffman tree buffer grow. Nested helper of `BitStream_HuffmanTree_EnsureCapacity`.

## Signature

```c
// EBX=self, ESI=src, EDI=endIdx, EDX=startIdx; plain RET
void BitStream_HuffmanTree_CopyRange(HuffmanTreeContainer* self /*EBX*/,
                                     const uint8_t* src /*ESI*/,
                                     uint32_t endIdx /*EDI*/,
                                     uint32_t startIdx /*EDX*/);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23
- Parent call-site register setup sealed from `FUN_00433ba0` bytes
- Dual A/B accept

## Artifacts

See `aa_00433c60_FUN_00433c60.md` for full artifact table.
