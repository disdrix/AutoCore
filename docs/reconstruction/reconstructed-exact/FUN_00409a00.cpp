// =============================================================================
// FUN_00409a00 — scaffold twin of HkArray_Elem8_FreeIfOwned_Inferred
// See: HkArray_Elem8_FreeIfOwned_Inferred.cpp (authoritative clean)
// Dual: WQ9J-J 2026-08-05
// =============================================================================

#include <cstdint>

extern int *DAT_00b05060;

void __fastcall FUN_00409a00(std::uint32_t *param_1)
{
  if (-1 < static_cast<int>(param_1[2])) {
    std::uint32_t nbytes = (param_1[2] & 0x7fffffffu) * 8u;
    (**(void (***)(std::uint32_t, std::uint32_t, int))(*DAT_00b05060 + 0x14))(
        param_1[0], nbytes, 0x12);
  }
}
