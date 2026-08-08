// =============================================================================
// FUN_005319d0  (twin of CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005319d0
// Address:   0x005319d0  (autoassault.exe, image base 0x400000)
// Body:      0x005319d0–0x00531afd inclusive (302 B / 0x12E)
// System:    missions-progression
// Generated: 2026-08-05 R10-012 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

// PURPOSE:
//   Character UseItem objective action + LogicUI type 0x0E notify.
//   See named twin for full plate / offsets / sole caller notes.
//
// Named twin: CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred.cpp

#include <cstdint>

extern "C" void* __thiscall CNDHash_LookupByKey(void* hash, std::uint32_t key);
extern "C" void* __cdecl __RTDynamicCast(
    void* obj, long vfDelta, void* srcType, void* targetType, int isRef);
extern "C" std::uint8_t __thiscall FUN_00522b30(
    void* targetObj,
    std::uint32_t a0, std::uint32_t a1, std::uint32_t a2, std::uint32_t a3,
    std::uint8_t flag);
extern "C" void __thiscall Client_SendLogicUiPacket(void* queueThis, void* packet);
extern "C" void CVOGObjectiveRequirement_RTTI_Type_Descriptor;
extern "C" void CVOGObjectiveRequirement_UseItem_RTTI_Type_Descriptor;

// Decompiler-shaped twin (names kept FUN_* for inventory lockstep)
std::uint32_t __thiscall FUN_005319d0(
    int param_1,
    std::uint32_t param_2,
    int param_3,
    std::uint32_t param_4,
    std::uint32_t param_5,
    std::uint32_t param_6,
    std::uint32_t param_7)
{
  int* piVar1;
  char cVar2;
  void* pvVar3;
  int iVar4;
  int local_138[7];
  std::uint32_t local_11c;
  std::uint32_t local_118;
  int local_114;

  if (*reinterpret_cast<char*>(
          *reinterpret_cast<int*>(
              *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 4) + 4) +
              0xa8 + param_1) +
          0x7e) != '\0') {
    pvVar3 = CNDHash_LookupByKey(
        *reinterpret_cast<void**>(param_1 + 0x548), param_2);
    if (pvVar3 != nullptr) {
      if (*reinterpret_cast<int*>(reinterpret_cast<int>(pvVar3) + 0x158) == 0) {
        iVar4 = 0;
      } else {
        iVar4 = (*reinterpret_cast<int*>(reinterpret_cast<int>(pvVar3) + 0x15c) -
                 *reinterpret_cast<int*>(reinterpret_cast<int>(pvVar3) + 0x158)) >> 2;
      }
      if (param_3 < iVar4) {
        piVar1 = *reinterpret_cast<int**>(
            *reinterpret_cast<int*>(reinterpret_cast<int>(pvVar3) + 0x158) +
            param_3 * 4);
        iVar4 = (*reinterpret_cast<int(__thiscall**)(int*)>(*piVar1 + 0x50))();
        if (iVar4 == 0xc) {
          iVar4 = reinterpret_cast<int>(__RTDynamicCast(
              piVar1, 0,
              &CVOGObjectiveRequirement_RTTI_Type_Descriptor,
              &CVOGObjectiveRequirement_UseItem_RTTI_Type_Descriptor,
              0));
          if (*reinterpret_cast<int*>(iVar4 + 0x34) != 0) {
            cVar2 = static_cast<char>(FUN_00522b30(
                *reinterpret_cast<void**>(iVar4 + 0x34),
                param_4, param_5, param_6, param_7,
                *reinterpret_cast<std::uint8_t*>(iVar4 + 0x3c)));
            if (cVar2 != '\0') {
              goto LAB_00531abb;
            }
          }
        }
      }
    }
    return 0;
  }
LAB_00531abb:
  local_114 = static_cast<int>(param_2) >> 0x1f;
  local_118 = param_2;
  local_11c = 0xe;
  local_138[0] = param_3;
  // Image adjusts ECX = dual-base + 0xE8B8 before call; decompiler omits this
  Client_SendLogicUiPacket(
      reinterpret_cast<void*>(
          *reinterpret_cast<int*>(
              *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 4) + 4) +
              0xa8 + param_1) +
          0xe8b8),
      local_138);
  return 1;
}
