// =============================================================================
// BitStream_HuffmanAlphabetEnsureCapacity
// -----------------------------------------------------------------------------
// Stable ID: aa_00433c00
// Address:   0x00433c00 – 0x00433c53  (autoassault.exe, image base 0x400000)
// System:    net / TNL BitStream Huffman alphabet buffer
// Dual:      W26-B 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Ensure the Huffman alphabet dynarray (elem stride 0xC) has capacity
//   >= requested count. Sole caller BitStream_HuffmanBuildTables passes
//   need=0x100 with ECX = &DAT_00d1eab4.
//
// ABI (machine):
//   ECX = container* { uint32_t size@+0; uint32_t capacity@+4; void* data@+8 }
//   EAX = requested min capacity
//   void; plain RET after PUSH/POP EBX EDI (and EBP/ESI on grow path)
// =============================================================================

#include <cstdint>
#include <cstdlib>

struct HuffmanAlphaContainer {
  std::uint32_t size;      // +0  DAT_00d1eab4
  std::uint32_t capacity;  // +4
  void* data;              // +8  DAT_00d1eabc (entries × 0xC)
};

// Element copy helper @ 0x00433ca0 (not OWN W26-B).
// Call site registers: EDI=container, ESI=old buffer, EAX=live size, EDX=0.
extern "C" void FUN_00433ca0(void);

// Portable reconstruction of CF. Machine packs `need` in EAX at entry
// (Ghidra: in_EAX); ECX = container (fastcall this).
void BitStream_HuffmanAlphabetEnsureCapacity(HuffmanAlphaContainer* container,
                                             std::uint32_t need)
{
  if (container->capacity < need) {
    std::uint32_t newCap = need + (0x10u - (need & 0xFu));
    void* neu = std::malloc(static_cast<std::size_t>(newCap) * 0xCu);
    void* old = container->data;
    container->data = neu;
    FUN_00433ca0();  // copy container->size elems of 0xC from old → neu
    container->data = old;
    std::free(old);
    container->data = neu;
    container->capacity = newCap;
  }
}

// Ghidra symbol twin entry — same CF; need is EAX on the machine.
extern "C" void __fastcall FUN_00433c00(HuffmanAlphaContainer* container /*ecx*/)
{
  // Documented only: real entry reads need from EAX.
  // Ports should call BitStream_HuffmanAlphabetEnsureCapacity(container, need).
  (void)container;
}
