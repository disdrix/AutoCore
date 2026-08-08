// =============================================================================
// FUN_00404c30  (machine twin of Object_Store16At90_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00404c30
// Address:   0x00404c30  (autoassault.exe, image base 0x400000)
// System:    skills-abilities (partition); generic object field store
// Dual:      2026-08-05 R10-022 OWN-ONLY
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Prefer Object_Store16At90_Inferred.cpp for the named clean unit.
void __thiscall FUN_00404c30(void *thisObj, const std::uint32_t *src16)
{
  auto *dst = reinterpret_cast<std::uint32_t *>(
      reinterpret_cast<char *>(thisObj) + 0x90);
  dst[0] = src16[0];
  dst[1] = src16[1];
  dst[2] = src16[2];
  dst[3] = src16[3];
}
