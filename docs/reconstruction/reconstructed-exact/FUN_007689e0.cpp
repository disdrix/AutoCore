// =============================================================================
// FUN_007689e0  (alias plate → stoChunkReader_TextReadU32)
// -----------------------------------------------------------------------------
// Stable ID: aa_007689e0
// Address:   0x007689e0  (autoassault.exe, image base 0x400000)
// Prefer:    reconstructed-exact/stoChunkReader_TextReadU32.cpp
// Dual A/B:  2026-07-29 W22-Q
// =============================================================================

// Canonical clean plate lives in stoChunkReader_TextReadU32.cpp.
// Prior scaffolds: Named_stoChunk_007689e0.cpp (string-driven).

#include <cstdint>

// Retail ABI: EDI=stoChunkReader*, stack=uint32_t* out, RET 4.
// Returns 0 success / 0xffffffff fail.
// See stoChunkReader_TextReadU32 for full CF + offsets.

int32_t FUN_007689e0(uint32_t* out);
// implementation: stoChunkReader_TextReadU32 (named plate)
