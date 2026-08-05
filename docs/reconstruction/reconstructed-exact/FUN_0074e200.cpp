// =============================================================================
// FUN_0074e200  (scaffold twin of EnvSlot_SetActiveBumpGen)
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e200
// Address:   0x0074e200  (autoassault.exe, image base 0x400000)
// Wave:      W31-Q OWN-ONLY dual 2026-07-29
// Canonical: EnvSlot_SetActiveBumpGen
// =============================================================================

#include <cstdint>

extern "C" uint8_t* DAT_00d1f048;

// ECX = slot; stack char enable; RET 4; void.
extern "C" void __thiscall FUN_0074e200(void* slot, char enable)
{
  auto* s = reinterpret_cast<uint8_t*>(slot);
  auto* related = *reinterpret_cast<uint8_t**>(s + 0x3c);
  if (related == nullptr) {
    return;
  }

  if (enable != 0 && DAT_00d1f048[0x0f] != 0) {
    *reinterpret_cast<int32_t*>(related + 0xdc) += 1;
    related[0xd1] = 1;
    return;
  }

  *reinterpret_cast<int32_t*>(related + 0xdc) += 1;
  related[0xd1] = 0;
}
