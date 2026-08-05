# Function record: BitStream_HuffmanAssignCodes

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077d440` |
| **Canonical name** | `BitStream_HuffmanAssignCodes` |
| **Ghidra name** | `FUN_0077d440` |
| **Address** | `0x0077d440`–`0x0077d514` (212 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | net / TNL BitStream Huffman |
| **Completion status** | **Sealed** W26-C dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Walk Huffman tree; assign alphabet bit lengths and codes for BitStream string codec.

## Signature

```c
void BitStream_HuffmanAssignCodes(void* ctx, int nodeOrLeaf, int depth);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23
- Parent calls with `(scratch, 0, 0)` after tree merge
- Dual A/B accept

## Artifacts

See `aa_0077d440_FUN_0077d440.md` for full artifact table.
