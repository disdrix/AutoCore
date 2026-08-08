// =============================================================================
// FUN_0090c700  — twin of MedalUI_PrepClearButtonSlots_Inferred (aa_0090c700)
// -----------------------------------------------------------------------------
// Address:   0x0090c700–0x0090c74c inclusive (77 B / 0x4D)
// Wave:      MEGA-102 OWN-ONLY dual 2026-08-05
// System:    missions-progression / Medal UI prep
// Exactness: Behavior-preserving rewrite. Prefer named clean source.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

using VFunc0_RetChar = char(__thiscall*)(void* self);
using VFunc1_Ptr     = void(__thiscall*)(void* self, void* child);
using ScalarDtor     = void(__thiscall*)(void* self, int flags);

// EDI = host (caller-seeded). Bare RET. void.
extern "C" void FUN_0090c700(void /* EDI = host */)
{
  void* host;
  uint32_t* slot;
  int remaining;

#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov host, edi
  }
#else
  host = nullptr;
#endif

  // LEA ESI,[EDI+0x540]; MOV EBX,0x18
  slot = reinterpret_cast<uint32_t*>(
      reinterpret_cast<uint8_t*>(host) + 0x540);
  remaining = 0x18;

  do {
    if (*slot != 0) {
      void** hostVtbl = *reinterpret_cast<void***>(host);
      char active = reinterpret_cast<VFunc0_RetChar>(hostVtbl[0x3d8 / 4])(host);
      if (active != 0) {
        reinterpret_cast<VFunc1_Ptr>(hostVtbl[0xb0 / 4])(
            host, reinterpret_cast<void*>(*slot));
      }
      if (*slot != 0) {
        void* widget = reinterpret_cast<void*>(*slot);
        void** wVtbl = *reinterpret_cast<void***>(widget);
        reinterpret_cast<ScalarDtor>(wVtbl[0])(widget, 1);
      }
      *slot = 0;
    }
    slot += 1;
    remaining -= 1;
  } while (remaining != 0);
}
