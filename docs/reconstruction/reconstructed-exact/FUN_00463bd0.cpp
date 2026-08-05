// =============================================================================
// FUN_00463bd0  (twin of NestedHash_Ctor_Sentinel0x30_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00463bd0
// Address:   0x00463bd0–0x00463c31  (autoassault.exe, image base 0x400000)
// System:    shared nested hash/map shell
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W34-F)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// Canonical: NestedHash_Ctor_Sentinel0x30_Inferred
// =============================================================================

#include <cstdint>

extern "C" void* FUN_005b43b0(void);
extern "C" void  FUN_004646e0(void* shell, uint32_t count, void** fill_src);

// Ghidra-facing symbol; retail stack(self*) RET 4
extern "C" void* FUN_00463bd0(void* self /*stack*/)
{
  // SEH LAB_009bd31b
  void* node = FUN_005b43b0();
  *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(self) + 0x08) = node;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x0c) = 0;

  void* fill = node;
  FUN_004646e0(reinterpret_cast<uint8_t*>(self) + 0x10, 9, &fill);

  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x20) = 1;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x24) = 1;
  return self;
}
