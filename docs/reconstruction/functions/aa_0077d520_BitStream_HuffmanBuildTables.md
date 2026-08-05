# Function record: BitStream_HuffmanBuildTables

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077d520` |
| **Canonical name** | `BitStream_HuffmanBuildTables` |
| **Ghidra name** | `FUN_0077d520` |
| **Address** | `0x0077d520`–`0x0077d952` (1074 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | net / TNL BitStream Huffman |
| **Completion status** | **Sealed** W25-T dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Build global Huffman tables for TNL BitStream string compression (write/read).

## Signature

```c
void BitStream_HuffmanBuildTables(void);
// side effects: DAT_00d17a28=1; DAT_00d1eab0 tree; DAT_00d1eabc alphabet codes
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23
- `read_memory` prologue stores flag; body size 1074 B
- Callers already dual-sealed as BitStream_writeString / readString (W21-C) — this unit fills their residual builder gap

## Artifacts

See `aa_0077d520_FUN_0077d520.md` for full artifact table.
