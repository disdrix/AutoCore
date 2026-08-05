// =============================================================================
// FUN_0076a200  (alias → stoChunkReader_TextReadString)
// -----------------------------------------------------------------------------
// Stable ID: aa_0076a200
// Address:   0x0076a200–0x0076a2b5  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-08-04 (W38-J)
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Ghidra alias. Prefer named clean:
//   docs/reconstruction/reconstructed-exact/stoChunkReader_TextReadString.cpp

#include <cstdint>
#include <string>

struct StoChunkReader;

// Retail leaf: ECX=std::string* out, EBX=reader*, plain RET. Returns 0 / −1.
extern int32_t stoChunkReader_TextReadString(std::string* out /*ECX*/,
                                             StoChunkReader* reader /*EBX*/);

int32_t FUN_0076a200(std::string* out /*ECX; reader in EBX*/)
{
  // Document-only shim — body lives in stoChunkReader_TextReadString.cpp
  (void)out;
  return static_cast<int32_t>(0xffffffffu);
}
