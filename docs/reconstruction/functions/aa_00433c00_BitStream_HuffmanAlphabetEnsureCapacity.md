# Function record (named): BitStream_HuffmanAlphabetEnsureCapacity

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433c00` |
| **Canonical name** | `BitStream_HuffmanAlphabetEnsureCapacity` |
| **Ghidra name** | `FUN_00433c00` |
| **Address** | `0x00433c00`–`0x00433c53` |
| **Dual** | W26-B 2026-07-29 **accept** / **accept** |

See `aa_00433c00_FUN_00433c00.md` for full sealed facts.

```c
// ECX=container @ DAT_00d1eab4, EAX=need (0x100 from HuffmanBuildTables)
void BitStream_HuffmanAlphabetEnsureCapacity(HuffmanAlphaContainer *c, uint32_t need);
```
