// =============================================================================
// FUN_00769660  (alias → stoChunkReader_TextReadBool)
// -----------------------------------------------------------------------------
// Stable ID: aa_00769660
// Address:   0x00769660–0x007698d0  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-08-04 (W38-J)
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Ghidra alias. Prefer named clean:
//   docs/reconstruction/reconstructed-exact/stoChunkReader_TextReadBool.cpp

#include <cstdint>

struct StoChunkReader;

// Retail: EDI=reader, stack=uint8_t* out, RET 4. Returns 0 / −1.
extern int32_t stoChunkReader_TextReadBool(StoChunkReader* reader /*EDI*/,
                                           uint8_t* out /*stack*/);

int32_t FUN_00769660(uint8_t* out /*stack; reader in EDI*/)
{
  // Document-only shim — body lives in stoChunkReader_TextReadBool.cpp
  (void)out;
  return static_cast<int32_t>(0xffffffffu);
}
