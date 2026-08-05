// =============================================================================
// BitStream_HuffmanAlphabet_CopyRange
// -----------------------------------------------------------------------------
// Stable ID: aa_00433ca0
// Address:   0x00433ca0 – 0x00433cd3  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00433ca0
// System:    net / TNL BitStream Huffman (alphabet container element copy)
// Dual:      W28-A 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================
//
// Exclusive caller: BitStream_HuffmanAlphabetEnsureCapacity (FUN_00433c00).
// Sister tree path uses FUN_00433c60 (stride 8) — not this unit.
// =============================================================================

#include <cstdint>

struct HuffmanAlphaContainer {
  uint32_t size;      // +0
  uint32_t capacity;  // +4
  uint8_t* buf;       // +8  (12-byte alphabet entries)
};

// Retail: EDI=self, ESI=src, EAX=endIdx, EDX=startIdx; plain RET.
void BitStream_HuffmanAlphabet_CopyRange(HuffmanAlphaContainer* container /*EDI*/,
                                         const uint8_t* src /*ESI*/,
                                         uint32_t endIdx /*EAX*/,
                                         uint32_t startIdx /*EDX*/)
{
  if (startIdx >= endIdx) {
    return;
  }
  uint32_t off = startIdx * 0xCu;
  uint32_t n = endIdx - startIdx;
  do {
    uint32_t* dest = reinterpret_cast<uint32_t*>(container->buf + off);
    if (dest != nullptr) {
      const uint32_t* s = reinterpret_cast<const uint32_t*>(src + off);
      dest[0] = s[0];
      dest[1] = s[1];
      dest[2] = s[2];
    }
    off += 0xCu;
    n -= 1u;
  } while (n != 0u);
}
