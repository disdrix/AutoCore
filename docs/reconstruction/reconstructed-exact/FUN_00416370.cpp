// =============================================================================
// FUN_00416370 — scaffold twin of Mem_ZeroSixDwords_Ecx_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00416370
// Address:   0x00416370  (autoassault.exe, image base 0x400000)
// See:       Mem_ZeroSixDwords_Ecx_Inferred.cpp (named clean; dual WQ9I-I)
// =============================================================================

#include <cstdint>

extern "C" uint32_t* Mem_ZeroSixDwords_Ecx_Inferred(uint32_t* dest /*ECX*/);

extern "C" uint32_t* FUN_00416370(uint32_t* dest /*ECX*/)
{
  return Mem_ZeroSixDwords_Ecx_Inferred(dest);
}
