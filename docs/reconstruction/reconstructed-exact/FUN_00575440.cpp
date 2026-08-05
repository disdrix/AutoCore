// =============================================================================
// FUN_00575440  (named: Object_009d33c4_Ctor)
// -----------------------------------------------------------------------------
// Stable ID: aa_00575440
// Address:   0x00575440  (autoassault.exe, image base 0x400000)
// Body:      0x00575440–0x00575528 exclusive (232 B / 0xE8)
// Generated: 2026-07-29 W29-H dual seal
// Exactness: Behavior-preserving rewrite. See Object_009d33c4_Ctor.cpp.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Twin of named clean. Prefer Object_009d33c4_Ctor for ports.
// See docs/reconstruction/functions/aa_00575440_Object_009d33c4_Ctor.md

#include <cstdint>

extern "C" void __thiscall Object_SharedBase_Ctor(void *self); // FUN_00518940
extern "C" void *FUN_00457c60(void);
extern "C" void *PTR_FUN_009d33c4;

void *__thiscall FUN_00575440(void *self)
{
  auto *base = reinterpret_cast<uint8_t *>(self);

  Object_SharedBase_Ctor(self);
  *reinterpret_cast<void **>(base + 0) = &PTR_FUN_009d33c4;

  void *sentinel = FUN_00457c60();
  *reinterpret_cast<void **>(base + 0x1E0) = sentinel;
  *reinterpret_cast<uint32_t *>(base + 0x1E4) = 0;

  *reinterpret_cast<uint32_t *>(base + 0x1F8) = 0;
  *reinterpret_cast<uint32_t *>(base + 0x1FC) = 0;
  *reinterpret_cast<uint32_t *>(base + 0x200) = 0;
  base[0x1F0] = 0;
  base[0x1F1] = 0;
  base[0x1D8] = 0;
  *reinterpret_cast<uint32_t *>(base + 0x194) = 0;
  *reinterpret_cast<void **>(base + 0x1EC) = nullptr;
  base[0x1F2] = 0;
  *reinterpret_cast<uint32_t *>(base + 0x190) = 1;
  *reinterpret_cast<uint32_t *>(base + 0x1E8) = 0xFFFFFFFFu;

  *reinterpret_cast<uint32_t *>(base + 0x198) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x19C) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1A8) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1AC) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1B8) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1BC) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1C8) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1CC) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1A0) = 0;
  *reinterpret_cast<uint32_t *>(base + 0x1B0) = 0;
  *reinterpret_cast<uint32_t *>(base + 0x1C0) = 0;
  *reinterpret_cast<uint32_t *>(base + 0x1D0) = 0;

  return self;
}
