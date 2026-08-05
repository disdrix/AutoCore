// =============================================================================
// BitStream_HuffmanTree_EnsureCapacity
// -----------------------------------------------------------------------------
// Stable ID: aa_00433ba0
// Address:   0x00433ba0 – 0x00433bfe  (autoassault.exe, image base 0x400000)
// System:    net / TNL BitStream Huffman (tree container grow)
// Dual:      W26-C 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Ensure the Huffman tree container (8-byte nodes) has capacity >= needCount.
//   Exclusive caller: BitStream_HuffmanBuildTables (FUN_0077d520) — twice.
//   Parent loads this-pointer as EAX = 0x00d1eaa8 (count/cap/buf triple).
//
// ABI (machine):
//   this in EAX; one stack formal needCount; RET 4 (stdcall-style cleanup)
// =============================================================================

#include <cstdint>
#include <cstdlib>

// Copy old 8-byte elems into newly installed buffer (register-passing helper).
extern "C" void FUN_00433c60(void);

struct HuffmanTreeContainer {
  std::uint32_t count;     // +0  DAT_00d1eaa8
  std::uint32_t capacity;  // +4  DAT_00d1eaac
  void*         buf;       // +8  DAT_00d1eab0  (elements of 8 bytes)
};

// Ghidra: void FUN_00433ba0(uint param_1) with in_EAX this
extern "C" void BitStream_HuffmanTree_EnsureCapacity(
    /* EAX */ HuffmanTreeContainer* self,
    /* stack */ std::uint32_t needCount)
{
  if (self->capacity < needCount) {
    // newCap = need + (0x10 - (need & 0xf)) == (need & ~0xf) + 0x10
    std::uint32_t newCap =
        needCount + (0x10u - (needCount & 0xfu));
    void* neu = std::malloc(static_cast<std::size_t>(newCap) * 8u);
    void* old = self->buf;
    self->buf = neu;
    FUN_00433c60();  // copy via registers set by caller sequence
    self->buf = old;
    std::free(old);
    self->buf = neu;
    self->capacity = newCap;
  }
}

// FUN twin entry name for Ghidra symbol
extern "C" void FUN_00433ba0(
    /* EAX */ HuffmanTreeContainer* self,
    /* stack */ std::uint32_t needCount)
{
  BitStream_HuffmanTree_EnsureCapacity(self, needCount);
}
