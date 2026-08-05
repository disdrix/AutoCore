// =============================================================================
// FUN_004363b0  (twin of BitVec_EnsureOneAndLocateRef_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004363b0
// Address:   0x004363b0
// Wave:      W38-C
// =============================================================================

#include <cstdint>

struct BitRef {
  uint32_t bit;
  uint32_t* word;
};

struct BitVecHost {
  uint8_t _pad[8];
  uint32_t* begin;
};

extern "C" void __thiscall FUN_004364b0(BitVecHost* host, int bitAdd, uint32_t* dwordPos, uint32_t param3);

extern "C" BitRef* FUN_004363b0(
    BitVecHost* host, int bitAdd, uint32_t* dwordPos, uint32_t param3, BitRef* out)
{
  uint32_t* old_begin = host->begin;
  FUN_004364b0(host, bitAdd, dwordPos, param3);
  uint32_t* begin = host->begin;
  uint32_t bitIndex =
      (static_cast<uint32_t>(reinterpret_cast<int>(dwordPos) - reinterpret_cast<int>(old_begin)) >> 2) * 32u
      + static_cast<uint32_t>(bitAdd);
  out->bit = bitIndex & 31u;
  out->word = begin + (bitIndex >> 5);
  return out;
}
