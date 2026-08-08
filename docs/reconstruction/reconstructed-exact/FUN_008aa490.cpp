// =============================================================================
// FUN_008aa490  (Ghidra twin of MissionDialog_SetTurnInReadyFlag_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa490
// Address:   0x008aa490–0x008aa4a6 inclusive (23 B / 0x17)
// Wave:      MEGA-078 OWN-ONLY dual 2026-08-05
// System:    missions-progression
// Exactness: Behavior-preserving rewrite. Prefer named clean:
//            MissionDialog_SetTurnInReadyFlag_Inferred.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

using VFunc_SetFlag = void(__thiscall*)(void* self, uint32_t flagArg);

// Retail ABI: EAX = dialog host, DL = flag char; bare RET.
extern "C" void FUN_008aa490(void /* EAX=dialog, DL=flag */)
{
  void* dialog;
  uint32_t flagEdx;

#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov dialog, eax
    mov flagEdx, edx
  }
#else
  dialog = nullptr;
  flagEdx = 0;
#endif

  auto* base = reinterpret_cast<uint8_t*>(dialog);
  void* child = *reinterpret_cast<void**>(base + 0x6e8);
  *(base + 0x580) = static_cast<uint8_t>(flagEdx & 0xFF);

  if (child != nullptr) {
    void** childVtbl = *reinterpret_cast<void***>(child);
    reinterpret_cast<VFunc_SetFlag>(childVtbl[1])(child, flagEdx);
  }
}
