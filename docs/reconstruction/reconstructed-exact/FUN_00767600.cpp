// =============================================================================
// FUN_00767600  (alias plate → stoChunk_ConvertToInteger)
// -----------------------------------------------------------------------------
// Stable ID: aa_00767600
// Address:   0x00767600  (autoassault.exe, image base 0x400000)
// Prefer:    reconstructed-exact/stoChunk_ConvertToInteger.cpp
// Dual A/B:  2026-07-29 W25-R
// =============================================================================

// Canonical clean plate lives in stoChunk_ConvertToInteger.cpp.
// This file retained as Ghidra-name alias for path stability.

#include <cstdint>

// Retail ABI: EAX=const std::string*, stack (out, byteLen, signedMode), RET 12.
// See stoChunk_ConvertToInteger for full CF + range tables.

int32_t FUN_00767600(void* out, uint32_t byteLen, int32_t signedMode);
// implementation: stoChunk_ConvertToInteger (named plate; EAX=text)
