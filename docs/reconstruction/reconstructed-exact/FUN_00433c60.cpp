// =============================================================================
// FUN_00433c60  (twin of BitStream_HuffmanTree_CopyRange)
// -----------------------------------------------------------------------------
// Stable ID: aa_00433c60
// Address:   0x00433c60 – 0x00433c92  (autoassault.exe, image base 0x400000)
// System:    net / TNL BitStream Huffman (tree container element copy)
// Dual:      W27-B 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

struct Cont8 {
  uint32_t count;     // +0
  uint32_t capacity;  // +4
  uint8_t* buf;       // +8  (8-byte elements)
};

// Retail ABI: custom registers — EBX=container, ESI=src, EDI=end, EDX=start.
// No stack formals; plain RET. Decompiler "__fastcall" formals are incomplete.
// Named clean: BitStream_HuffmanTree_CopyRange.cpp

extern "C" void FUN_00433c60_with_regs(Cont8* container /*EBX*/,
                                       const uint8_t* src /*ESI*/,
                                       uint32_t endIdx /*EDI*/,
                                       uint32_t startIdx /*EDX*/)
{
  for (; startIdx < endIdx; startIdx++) {
    const uint32_t off = startIdx * 8u;
    uint32_t* dest = reinterpret_cast<uint32_t*>(container->buf + off);
    if (dest != nullptr) {
      dest[0] = *reinterpret_cast<const uint32_t*>(src + off);
      dest[1] = *reinterpret_cast<const uint32_t*>(src + off + 4u);
    }
  }
}

// Ghidra symbol entry: decompiler shows unused ECX formal + EDX as param_2.
extern "C" void FUN_00433c60(uint32_t /*unused_ecx*/, uint32_t startIdx)
{
  (void)startIdx;
  // Host builds must supply EBX/ESI/EDI via the with_regs form.
  // Retail: CALL after parent sets EBX/ESI/EDI/EDX.
}
