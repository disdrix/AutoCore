// =============================================================================
// EnvSlot_SetActiveBumpGen  (aa_0074e200)
// -----------------------------------------------------------------------------
// Address:   0x0074e200  (autoassault.exe, image base 0x400000)
// Body:      0x0074e200–0x0074e23c inclusive (61 B / 0x3D); pad CC; RET 4
// Wave:      W31-Q OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
// On an env-slot object (the pointer published as DAT_00d1a54c / *(env+4)):
//   related = *(slot+0x3c)
//   if related:
//     ++*(related+0xdc)                              // always bump gen
//     *(related+0xd1) = (enable && *(DAT_00d1f048+0xf)) ? 1 : 0
// Sole static callers: Client_InitPalantirViewBundle (disable old / enable new).
// Reject scaffold Named_CalleeOf_Named_* plate.

#include <cstdint>

extern "C" uint8_t* DAT_00d1f048; // graphics/env global state block

// ECX = slot; stack char enable; RET 4; void; leaf.
extern "C" void __thiscall EnvSlot_SetActiveBumpGen(void* slot, char enable)
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

// Scaffold / Ghidra-name twin
extern "C" void __thiscall FUN_0074e200(void* slot, char enable)
{
  EnvSlot_SetActiveBumpGen(slot, enable);
}
