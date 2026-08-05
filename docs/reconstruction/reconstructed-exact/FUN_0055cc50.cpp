// =============================================================================
// FUN_0055cc50  (scaffold twin of CVOGEnvironmentDistort_Enable_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0055cc50
// Address:   0x0055cc50  (autoassault.exe, image base 0x400000)
// Body:      0x0055cc50–0x0055cc6a exclusive (26 bytes / 0x1A)
// System:    client / VOGEnvironmentSector / owned Distort phase
// Generated: 2026-07-23 scaffold; 2026-07-29 W33-T dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Preferred name: CVOGEnvironmentDistort_Enable_Inferred
// =============================================================================

#include <cstdint>

extern std::uint32_t __thiscall FUN_00756320(void* self, std::uint32_t flag);
extern void __fastcall FUN_0055ca90(void* self);

std::uint32_t __thiscall FUN_0055cc50(void* self, std::uint32_t param_1)
{
  FUN_00756320(self, param_1);
  FUN_0055ca90(self);
  return 0;
}
