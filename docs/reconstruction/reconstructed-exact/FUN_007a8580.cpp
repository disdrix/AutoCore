// =============================================================================
// FUN_007a8580  (Ghidra twin of CNDUIWindow_ClearOwnedObject_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_007a8580
// Address:   0x007a8580–0x007a85df inclusive (96 B / 0x60)
// Wave:      WQ9L-E OWN-ONLY dual 2026-08-05
// Named:     CNDUIWindow_ClearOwnedObject_Inferred
// =============================================================================

#include <cstdint>

extern "C" char DAT_00a1419b;

extern "C" void __fastcall FUN_007a8580(uint32_t* self)
{
  if (self[0xA6] != 0) {
    if (uint32_t* child = reinterpret_cast<uint32_t*>(self[0xAD])) {
      void** cvtbl = *reinterpret_cast<void***>(child);
      reinterpret_cast<void(__thiscall*)(void*, int)>(cvtbl[0])(child, 0);
    }
    {
      void** vtbl = *reinterpret_cast<void***>(self);
      reinterpret_cast<void(__thiscall*)(void*)>(vtbl[0x4C / 4])(self);
    }
    {
      void** vtbl = *reinterpret_cast<void***>(self);
      reinterpret_cast<void(__thiscall*)(void*, char*)>(vtbl[0x288 / 4])(
          self, &DAT_00a1419b);
    }
    auto* b = reinterpret_cast<uint8_t*>(self);
    if (b[0xBC] != 0) {
      if (uint32_t* owned = reinterpret_cast<uint32_t*>(self[0xA6])) {
        void** ovtbl = *reinterpret_cast<void***>(owned);
        reinterpret_cast<void(__thiscall*)(void*, int)>(ovtbl[0])(owned, 1);
      }
      self[0xA6] = 0;
      b[0xBC] = 0;
    }
  }
  self[0xA6] = 0;
}
