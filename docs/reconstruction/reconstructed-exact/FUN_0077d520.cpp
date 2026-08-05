// =============================================================================
// FUN_0077d520  (scaffold twin of BitStream_HuffmanBuildTables)
// -----------------------------------------------------------------------------
// Stable ID: aa_0077d520
// Address:   0x0077d520 – 0x0077d952  (autoassault.exe, image base 0x400000)
// System:    net / TNL BitStream Huffman
// Dual:      W25-T 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
//            Prefer BitStream_HuffmanBuildTables.cpp for named plate.
// =============================================================================

// PURPOSE: Once-init Huffman tree + alphabet for BitStream string codec.
// See BitStream_HuffmanBuildTables.cpp for full annotated reconstruction.
// This twin preserves Ghidra symbol FUN_0077d520 as the link name.

#include <cstdint>
#include <cstdlib>

extern "C" void FUN_00433c00(void);
extern "C" void FUN_00433ba0(std::uint32_t);
extern "C" void FUN_0077d440(void*, int, int);
extern "C" void* operator_new__(std::size_t);
extern "C" void operator_delete__(void*);

extern std::uint8_t DAT_00d17a28;
extern std::uint32_t DAT_00a1ea68[];
extern std::uint8_t* DAT_00d1eabc;
extern std::uint32_t* DAT_00d1eab0;
extern std::uint32_t DAT_00d1eaa8;
extern std::uint32_t DAT_00d1eaac;
extern std::uint32_t DAT_00d1eab4;
extern void* PTR_LAB_009d7b94;
extern void* PTR_LAB_009d7b00;

// Full body is large; named clean is authoritative. Twin entry:
extern "C" void BitStream_HuffmanBuildTables(void);

extern "C" void FUN_0077d520(void)
{
  // Forward to named reconstruction (same CF).
  BitStream_HuffmanBuildTables();
}
