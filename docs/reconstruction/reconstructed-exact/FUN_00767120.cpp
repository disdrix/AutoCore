// =============================================================================
// stoChunkReader_SoftSkipIfBitSet  (FUN_00767120)
// -----------------------------------------------------------------------------
// Stable ID: aa_00767120
// Address:   0x00767120 – 0x0076715c  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-29 dual A/B seal (W17-L OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory body.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Soft-skip predicate used by gfx unserialize paths immediately after
//   stoChunkReader_EnterChunkScope. Reads reader[+0] as an id and tests bit
//   (id-related) in the bitset at reader[+8]. Nonzero → callers return 0
//   without reading the chunk body (soft success). Zero id → false (continue).
//
// ABI: __fastcall this-style, ECX = stoChunkReader*. Plain RET. Leaf.
// Return: 0 or 1 in EAX (callers TEST AL,AL).
// Name: inferred; Ghidra still FUN_00767120. Product field English OPEN.
// =============================================================================

#include <cstdint>

// Opaque: only +0 and +8 used here.
struct StoChunkReaderSoftSkipView {
  uint32_t id;       // +0x00
  uint32_t unused_4; // +0x04  (not read)
  uint32_t bitset;   // +0x08  treated as uint32_t* base address
};

// FUN_00767120
uint32_t __fastcall stoChunkReader_SoftSkipIfBitSet(StoChunkReaderSoftSkipView *reader)
{
  uint32_t id = reader->id;
  if (id == 0) {
    // retail: XOR AL,AL — boolean false; upper EAX preserved
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

// Ghidra export alias
uint32_t __fastcall FUN_00767120(uint32_t *param_1)
{
  return stoChunkReader_SoftSkipIfBitSet(
      reinterpret_cast<StoChunkReaderSoftSkipView *>(param_1));
}
