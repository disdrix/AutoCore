// =============================================================================
// FUN_0096efd0 — twin of RefCountedPtr_Dtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0096efd0
// Address:   0x0096efd0–0x0096f03a (107 B)
// Dual A/B:  2026-08-04 W38-P
// Prefer:    RefCountedPtr_Dtor_Inferred.cpp
// =============================================================================

#include <cstdint>

// Ghidra-named entry. ECX = handle*; ret; SEH-wrapped release of payload
// with refcount at +8 and release vfunc at *(payload+4)+8.
void __fastcall FUN_0096efd0(uint32_t* self /*ECX*/)
{
  uint32_t payload = *self;
  if (payload != 0) {
    int32_t* rc = reinterpret_cast<int32_t*>(payload + 8);
    *rc -= 1;
    if (*rc == 0) {
      void* iface = reinterpret_cast<void*>(payload + 4);
      void** vtbl = *reinterpret_cast<void***>(iface);
      using ReleaseFn = void(__fastcall*)(void*);
      reinterpret_cast<ReleaseFn>(vtbl[2])(iface);
    }
    *self = 0;
  }
}
