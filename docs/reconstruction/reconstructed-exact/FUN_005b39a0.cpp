// =============================================================================
// FUN_005b39a0  (scaffold twin of CVOGEnvironmentReflect_Enable_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b39a0
// Address:   0x005b39a0  (autoassault.exe, image base 0x400000)
// Body:      0x005b39a0–0x005b39c1 exclusive (33 bytes / 0x21)
// System:    client / VOGEnvironmentSector / owned Reflect phase
// Generated: 2026-07-23 scaffold; 2026-07-29 W33-T dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Preferred name: CVOGEnvironmentReflect_Enable_Inferred
// =============================================================================

#include <cstdint>

extern std::uint32_t __thiscall FUN_00756320(void* self, std::uint32_t flag);
extern void __fastcall FUN_005b3520(void* self);
extern void __fastcall FUN_005b3420(void* self);

std::uint32_t __thiscall FUN_005b39a0(void* self, std::uint32_t param_1)
{
  FUN_00756320(self, param_1);
  FUN_005b3520(self);
  FUN_005b3420(self);
  return 0;
}
