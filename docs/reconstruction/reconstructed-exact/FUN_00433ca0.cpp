// =============================================================================
// FUN_00433ca0 — clean twin of BitStream_HuffmanAlphabet_CopyRange
// -----------------------------------------------------------------------------
// Stable ID: aa_00433ca0
// Address:   0x00433ca0 – 0x00433cd3
// Dual:      W28-A 2026-07-29
// =============================================================================

#include <cstdint>

// Custom-register ABI (not true __fastcall stack formals):
//   EDI = container*, ESI = src*, EAX = endIdx, EDX = startIdx; plain RET.
// Ghidra displays unused ECX formal + in_EAX — ignore for ports.
//
// Body (see BitStream_HuffmanAlphabet_CopyRange.cpp):
//   for i in [start,end): dest = *(EDI+8)+i*0xC; if dest: copy 3 dwords from ESI+i*0xC

extern "C" void FUN_00433ca0(void)
{
  // Ports must load EDI/ESI/EAX/EDX per parent BitStream_HuffmanAlphabetEnsureCapacity.
}
