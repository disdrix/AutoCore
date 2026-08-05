# Function record: BitStream_HuffmanAlphabet_CopyRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433ca0` |
| **Canonical name** | `BitStream_HuffmanAlphabet_CopyRange` |
| **Ghidra name** | `FUN_00433ca0` |
| **Address** | `0x00433ca0`–`0x00433cd3` (52 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | net / TNL BitStream Huffman |
| **Completion status** | **Sealed** W28-A dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Range-copy 12-byte alphabet entries during Huffman alphabet buffer grow. Nested helper of `BitStream_HuffmanAlphabetEnsureCapacity`.

## Signature

```c
// EDI=self, ESI=src, EAX=endIdx, EDX=startIdx; plain RET
void BitStream_HuffmanAlphabet_CopyRange(HuffmanAlphaContainer* self /*EDI*/,
                                         const uint8_t* src /*ESI*/,
                                         uint32_t endIdx /*EAX*/,
                                         uint32_t startIdx /*EDX*/);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23
- Parent call-site register setup sealed from `FUN_00433c00` bytes (`xor edx,edx`; `mov eax,[edi]`; ESI=old; EDI=container)
- Dual A/B **accept**

## Artifacts

See `aa_00433ca0_FUN_00433ca0.md` for full artifact table.
