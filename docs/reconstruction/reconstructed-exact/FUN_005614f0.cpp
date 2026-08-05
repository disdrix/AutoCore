// =============================================================================
// FUN_005614f0  (clean twin of WorldObj_UnbindOrDefer_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005614f0
// Address:   0x005614f0–0x00561571 (129 B / 0x81); ret 8
// Module:    autoassault.exe (image base 0x400000)
// Dual:      2026-07-29 W30-J OWN-ONLY
// Exactness: Behavior-preserving rewrite of decompiler + machine-sealed this-ptrs.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void FUN_005b3370(int *desc, int elemSize);
extern "C" void __thiscall FUN_00561320(int param_1);
extern "C" void __thiscall FUN_0055fbf0(int param_1, int param_2);
extern "C" void __fastcall FUN_0055f0b0(int param_1);
extern "C" void __thiscall FUN_0055fd80(int param_1, int param_2);

void __thiscall FUN_005614f0(int param_1, uint8_t *param_2, int param_3)
{
  if (*(char *)(param_1 + 300) == '\x01') {
    if (*(uint32_t *)(param_1 + 0xf4) ==
        (*(uint32_t *)(param_1 + 0xf8) & 0x7fffffffu)) {
      FUN_005b3370((int *)(param_1 + 0xf0), 4);
    }
    *(int *)(*(int *)(param_1 + 0xf0) + *(int *)(param_1 + 0xf4) * 4) = param_3;
    *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;
    *(int16_t *)(param_3 + 6) = (int16_t)(*(int16_t *)(param_3 + 6) + 1);
    *param_2 = 0;
    return;
  }
  if (0 < *(int *)(param_1 + 0x24)) {
    FUN_00561320(param_1);
  }
  FUN_0055fbf0(param_1, param_3);
  FUN_0055f0b0(param_3);
  FUN_0055fd80(param_1, param_3);
  *param_2 = 1;
  return;
}
