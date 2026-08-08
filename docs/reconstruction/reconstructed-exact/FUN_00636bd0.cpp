// =============================================================================
// FUN_00636bd0  — twin of CVOGHBMoveVehicle_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00636bd0
// Address:   0x00636bd0  (autoassault.exe, image base 0x400000)
// Body:      0x00636bd0 – 0x00636c49 inclusive (122 B / 0x7A)
// System:    input-drive-control
// Generated: 2026-08-05 R12-006 dual seal
// Preferred: CVOGHBMoveVehicle_ctor.cpp
// Exactness: Same CF as named clean; Ghidra symbol retained for inventory link.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: not claimed.
// =============================================================================

#include <cstdint>

extern void __thiscall CVOGHBBase_ctor(void *self);
extern void __thiscall CVOGHBBase_SetPeriodAndCounter(
    void *self, int nPeriodSentinel, bool bAlsoSetCounter);
extern void __thiscall CVOGHBBase_AttachOwnerObject(
    void *self, void *pOwnerObject);

extern float DAT_00aaa6c4; // 2.5f
extern float DAT_00aaa7a4; // 15.0f
extern void *PTR_FUN_009e3b70;

// Ghidra-facing twin (same body as CVOGHBMoveVehicle_ctor).
uint32_t *__thiscall FUN_00636bd0(uint32_t *param_1, int param_2)
{
  auto *const base = reinterpret_cast<char *>(param_1);

  CVOGHBBase_ctor(param_1);
  *reinterpret_cast<void **>(base + 0x00) = &PTR_FUN_009e3b70;
  CVOGHBBase_SetPeriodAndCounter(param_1, -1000, true);

  *reinterpret_cast<float *>(base + 0x2c) = DAT_00aaa6c4;
  *reinterpret_cast<float *>(base + 0x30) = 0.0f;
  *reinterpret_cast<float *>(base + 0x34) = DAT_00aaa7a4;
  *reinterpret_cast<uint32_t *>(base + 0x08) = 0x32;
  *reinterpret_cast<int *>(base + 0x24) = param_2;
  *reinterpret_cast<uint8_t *>(base + 0x29) = 0;

  if (param_2 == 0) {
    CVOGHBBase_AttachOwnerObject(param_1, nullptr);
    return param_1;
  }

  auto *const p = reinterpret_cast<char *>(param_2);
  auto *const mid = *reinterpret_cast<char **>(p + 4);
  const int adjust = *reinterpret_cast<int *>(mid + 4);
  CVOGHBBase_AttachOwnerObject(param_1, p + 4 + adjust);
  return param_1;
}
