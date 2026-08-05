// =============================================================================
// stoChunkReader_SoftSkipIfBitSet  — named clean plate
// -----------------------------------------------------------------------------
// Stable ID: aa_00767120
// Address:   0x00767120 – 0x0076715c
// See FUN_00767120.cpp for full plate + dual-seal notes.
// =============================================================================

#include <cstdint>

struct StoChunkReaderSoftSkipView {
  uint32_t id;
  uint32_t unused_4;
  uint32_t bitset;
};

uint32_t __fastcall stoChunkReader_SoftSkipIfBitSet(StoChunkReaderSoftSkipView *reader)
{
  uint32_t id = reader->id;
  if (id == 0) {
    return 0;
  }

  uint32_t base = reader->bitset;
  uint32_t low = id & 0x1fu;
  base += (id >> 5) * 4u;

  uint32_t idx = low - 1u;
  uint32_t word = *reinterpret_cast<uint32_t *>(base + ((idx >> 5) * 4u));
  uint32_t mask = 1u << (idx & 0x1fu);
  return (word & mask) != 0u ? 1u : 0u;
}
