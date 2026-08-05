// =============================================================================
// FUN_005be2b0  (scaffold twin of ObjectMotion_SlotReleaseToFreelist_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005be2b0
// Address:   0x005be2b0 – 0x005be2e9 exclusive  (57 B / 0x39)
// System:    client object motion / reaction slot freelist
// Generated: 2026-07-29 W28-I dual seal
// Prefer named clean: ObjectMotion_SlotReleaseToFreelist_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_004b0bd0(void *node_ecx);

void __thiscall FUN_005be2b0(int *param_1 /* freelist head */, int *param_2 /* slot */)
{
  int *piVar1;

  if (param_2[2] != 0) {
    FUN_004b0bd0(reinterpret_cast<void *>(param_2[2]));
    piVar1 = reinterpret_cast<int *>(param_2[2]);
    if (piVar1 != nullptr) {
      *piVar1 = *param_1;
      *param_1 = reinterpret_cast<int>(piVar1);
    }
    param_2[2] = 0;
  }
  FUN_004b0bd0(param_2);
  *param_2 = *param_1;
  *param_1 = reinterpret_cast<int>(param_2);
}
