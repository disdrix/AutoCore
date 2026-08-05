// =============================================================================
// CSoundManager_Ctor  (inferred product name)
// -----------------------------------------------------------------------------
// Stable ID: aa_00720a40
// Address:   0x00720a40  (autoassault.exe, image base 0x400000)
// Body:      0x00720a40–0x00720b44  (ret 4)
// System:    client audio / CSoundManager
// Twin file: FUN_00720a40.cpp
// Generated: 2026-07-29 W16-N dual seal
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================
//
// Sole caller: CSoundManager_GetInstance (0x00720d40):
//   if ((DAT_00d20200 & 1) == 0) {
//     DAT_00d20200 |= 1;
//     CSoundManager_Ctor(&DAT_00d20070);
//     atexit(LAB_009c3720);
//   }
//   return &DAT_00d20070;
// =============================================================================

#include <stdint.h>
#include <windows.h>

extern "C" float DAT_00aaa668; // 0x00aaa668 = -1.0f

extern "C" uint8_t * __stdcall CSoundManager_Ctor(uint8_t *self)
{
  int i;
  uint32_t *p;

  *(uint32_t *)(self + 0x0c) = 0;
  self[0x10] = 1;
  self[0x11] = 0;
  self[0x12] = 0;
  self[0x13] = 0;
  self[0x14] = 0;
  self[0x15] = 0;
  self[0x16] = 0;
  self[0x17] = 0;
  self[0x19] = 1;
  *(float *)(self + 0x1c) = 0.0f;
  *(float *)(self + 0x20) = DAT_00aaa668; // -1.0f
  *(float *)(self + 0x24) = DAT_00aaa668; // -1.0f
  *(uint32_t *)(self + 0x28) = 0;
  *(uint32_t *)(self + 0x30) = 0;
  *(uint32_t *)(self + 0x34) = 0;
  *(uint32_t *)(self + 0x38) = 0;
  *(uint32_t *)(self + 0x3c) = 0;
  *(uint32_t *)(self + 0x44) = 0;
  *(uint32_t *)(self + 0x48) = 0;
  *(uint32_t *)(self + 0x4c) = 0;
  *(uint32_t *)(self + 0x54) = 0;
  *(uint32_t *)(self + 0x58) = 0;
  *(uint32_t *)(self + 0x5c) = 0;
  *(uint32_t *)(self + 0x64) = 0;
  *(uint32_t *)(self + 0x68) = 0;
  *(uint32_t *)(self + 0x6c) = 0;
  *(uint32_t *)(self + 0x74) = 0;
  *(uint32_t *)(self + 0x78) = 0;
  *(uint32_t *)(self + 0x7c) = 0;
  *(uint32_t *)(self + 0x188) = 0;
  *(uint32_t *)(self + 0x80) = 0;
  *(uint32_t *)(self + 0x84) = 0;
  *(uint32_t *)(self + 0x88) = 0;
  *(uint32_t *)(self + 0x8c) = 0;

  p = (uint32_t *)(self + 0x90);
  for (i = 0x32; i != 0; --i) {
    *p++ = 0;
  }

  InitializeCriticalSection((LPCRITICAL_SECTION)(self + 0x158));
  InitializeCriticalSection((LPCRITICAL_SECTION)(self + 0x170));

  self[1] = 0;
  self[0] = 1;
  *(uint32_t *)(self + 4) = 0;
  *(uint32_t *)(self + 8) = 0;

  return self;
}
