// =============================================================================
// FUN_00433c00  (twin of BitStream_HuffmanAlphabetEnsureCapacity)
// -----------------------------------------------------------------------------
// Stable ID: aa_00433c00
// Address:   0x00433c00 – 0x00433c53  (autoassault.exe, image base 0x400000)
// System:    net / TNL BitStream Huffman alphabet buffer
// Dual:      W26-B 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern "C" void FUN_00433ca0(void);

// Machine ABI: ECX = container (int*/uint32_t* base), EAX = need (decompiler in_EAX).
// container[0]=size, [1]=capacity, [2]=data ptr. Element stride 0xC.
// Sole caller BitStream_HuffmanBuildTables: EAX=0x100, ECX=0x00d1eab4.

extern "C" void FUN_00433c00_with_need(std::uint32_t* param_1, std::uint32_t need)
{
  if (param_1[1] < need) {
    std::uint32_t iVar2 = need + (0x10u - (need & 0xFu));
    void* pvVar1 = std::malloc(static_cast<std::size_t>(iVar2) * 0xCu);
    void* oldMem = reinterpret_cast<void*>(
        static_cast<std::uintptr_t>(param_1[2]));
    param_1[2] = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(pvVar1));
    FUN_00433ca0();
    param_1[2] = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(oldMem));
    std::free(oldMem);
    param_1[2] = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(pvVar1));
    param_1[1] = iVar2;
  }
}

// Ghidra signature surface (need is EAX at real entry, not a stack formal).
extern "C" void __fastcall FUN_00433c00(std::uint32_t* param_1)
{
  (void)param_1;
  // Ports: call FUN_00433c00_with_need(param_1, need) with need from EAX ABI.
}
