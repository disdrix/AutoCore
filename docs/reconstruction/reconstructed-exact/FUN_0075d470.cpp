// =============================================================================
// FUN_0075d470 — twin of NDResourceCache_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d470
// Address:   0x0075d470  (autoassault.exe, image base 0x400000)
// Wave:      W35-B OWN-ONLY dual (2026-07-29)
// =============================================================================

#include <cstdint>
#include <windows.h>

extern "C" void* __stdcall FUN_0043bdf0(void* self);
extern "C" void* FUN_005ae2b0(void);
extern "C" void  __stdcall FUN_0075d3c0(void* host);
extern "C" void* DAT_00d1f050;

extern "C" void* __stdcall FUN_0075d470(void* self)
{
  // SEH LAB_009acd33 omitted
  DAT_00d1f050 = self;

  FUN_0043bdf0(self);

  *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x2c) = 0;
  *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x30) = 0;
  *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x34) = 0;
  *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x38) = 0;

  InitializeCriticalSection(
      reinterpret_cast<LPCRITICAL_SECTION>(static_cast<uint8_t*>(self) + 0x3c));
  *(static_cast<uint8_t*>(self) + 0x54) = 1;

  void* head = FUN_005ae2b0();
  *reinterpret_cast<void**>(static_cast<uint8_t*>(self) + 0x5c) = head;
  *(static_cast<uint8_t*>(head) + 0x19) = 1;
  *reinterpret_cast<void**>(static_cast<uint8_t*>(head) + 4) = head;
  *reinterpret_cast<void**>(head) = head;
  *reinterpret_cast<void**>(static_cast<uint8_t*>(head) + 8) = head;
  *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x60) = 0;

  *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x64) = 0;
  *(static_cast<uint8_t*>(self) + 0x68) = 0;
  *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x6c) = 0;
  FUN_0075d3c0(self);

  return self; // RET 4
}
