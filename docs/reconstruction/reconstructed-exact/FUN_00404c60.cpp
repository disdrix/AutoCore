// =============================================================================
// FUN_00404c60  (machine-name twin of Object_Store16At80_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00404c60
// Address:   0x00404c60  (autoassault.exe, image base 0x400000)
// System:    skills-abilities (partition); generic object field store
// Dual:      2026-08-05 MEGA-053 OWN-ONLY
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Canonical name: Object_Store16At80_Inferred
void __thiscall FUN_00404c60(void *param_1, const std::uint32_t *param_2)
{
  *reinterpret_cast<std::uint32_t *>(reinterpret_cast<char *>(param_1) + 0x80) = param_2[0];
  *reinterpret_cast<std::uint32_t *>(reinterpret_cast<char *>(param_1) + 0x84) = param_2[1];
  *reinterpret_cast<std::uint32_t *>(reinterpret_cast<char *>(param_1) + 0x88) = param_2[2];
  *reinterpret_cast<std::uint32_t *>(reinterpret_cast<char *>(param_1) + 0x8c) = param_2[3];
}
