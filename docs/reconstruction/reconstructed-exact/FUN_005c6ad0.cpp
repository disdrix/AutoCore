// =============================================================================
// FUN_005c6ad0  (twin of CLoadNode_WaitAssPreloadKeyRing_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6ad0
// Address:   0x005c6ad0–0x005c6b3e
// Dual:      W36-F 2026-07-29
// Prefer named clean: CLoadNode_WaitAssPreloadKeyRing_Inferred.cpp
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;
  int32_t  capacity;
  int32_t  begin;
  int32_t  size;
};

extern "C" uint8_t* DAT_00d1f050;
extern "C" uint32_t FUN_00971820(void* preloader /*ECX*/, GuardedVectorHeader* source);
extern "C" uint8_t  FUN_004ed310(GuardedVectorHeader* ring, char* flag, uint32_t* cursor);

uint32_t __thiscall FUN_005c6ad0(int param_1, GuardedVectorHeader* param_2)
{
  GuardedVectorHeader* ring = param_2;
  if (ring->size != 0) {
    int32_t iVar1 = *reinterpret_cast<int32_t*>(param_1 + 0x54);
    if (iVar1 < 1 || 6 < iVar1) {
      if (6 < iVar1) {
        *reinterpret_cast<uint32_t*>(param_1 + 0x54) = 0;
      }
      if (*reinterpret_cast<int32_t*>(DAT_00d1f050 + 0x6c) != 0) {
        FUN_00971820(*reinterpret_cast<void**>(DAT_00d1f050 + 0x6c), ring);
      }
    }
    char flag = 1;
    char cVar3 = static_cast<char>(FUN_004ed310(
        ring, &flag, reinterpret_cast<uint32_t*>(param_1 + 0x5c)));
    if (cVar3 == '\0') {
      *reinterpret_cast<int32_t*>(param_1 + 0x54) =
          *reinterpret_cast<int32_t*>(param_1 + 0x54) + 1;
      return 3;
    }
  }
  *reinterpret_cast<uint32_t*>(param_1 + 0x54) = 0;
  return 0;
}
