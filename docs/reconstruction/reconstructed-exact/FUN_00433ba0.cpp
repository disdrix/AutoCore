// =============================================================================
// FUN_00433ba0  (twin of BitStream_HuffmanTree_EnsureCapacity)
// -----------------------------------------------------------------------------
// Stable ID: aa_00433ba0
// Address:   0x00433ba0 – 0x00433bfe  (autoassault.exe, image base 0x400000)
// System:    net / TNL BitStream Huffman (tree container grow)
// Dual:      W26-C 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================
//
// ABI: this-in-EAX (decompiler in_EAX); stack needCount; RET 4.
// Named clean: BitStream_HuffmanTree_EnsureCapacity.cpp
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern "C" void FUN_00433c60(void);

struct Cont8 {
  std::uint32_t count;     // +0
  std::uint32_t capacity;  // +4
  void* buf;               // +8  (8-byte elements)
};

// Decompiler signature shows only stack formal; retail passes container in EAX.
// Compilable port form takes explicit this (matches call-site contract).
extern "C" void FUN_00433ba0_with_this(Cont8* self, std::uint32_t needCount)
{
  if (self->capacity < needCount) {
    std::uint32_t newCap = needCount + (0x10u - (needCount & 0xfu));
    void* neu = std::malloc(static_cast<std::size_t>(newCap) * 8u);
    void* old = self->buf;
    self->buf = neu;
    FUN_00433c60();
    self->buf = old;
    std::free(old);
    self->buf = neu;
    self->capacity = newCap;
  }
}

// Ghidra symbol entry: single stack formal (this recovered from EAX at calls).
extern "C" void FUN_00433ba0(std::uint32_t needCount)
{
  // Call sites always: mov eax, &DAT_00d1eaa8; push need; call FUN_00433ba0
  // For host builds, forward via the image global container base:
  extern Cont8 DAT_00d1eaa8;
  FUN_00433ba0_with_this(&DAT_00d1eaa8, needCount);
}
