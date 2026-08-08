// =============================================================================
// FUN_0060df70  (twin of CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0060df70
// Address:   0x0060df70  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-08-05 MEGA-038 — Ghidra-named twin; prefer named clean for ports.
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// See: CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" std::uint8_t __thiscall FUN_0060d460(void* self, void* charCtx, void* worldObj);
extern "C" std::uint8_t __thiscall FUN_0060d630(void* self, void* charCtx, void* progress, void* worldObj);
extern "C" std::uint8_t __thiscall FUN_005319d0(
    void* charCtx,
    std::uint32_t missionKey,
    int reqIndex,
    std::uint32_t a,
    std::uint32_t b,
    std::uint32_t c,
    std::uint32_t d);

// Ghidra signature under-counted stack arity; image RET 0x1C = 7 dwords.
std::uint32_t __thiscall FUN_0060df70(
    int* param_1,
    int param_2,
    std::uint32_t param_3,
    int param_4,
    std::uint32_t /*param_5_unread_slot_group — image has 3 unread dwords before worldObj*/,
    int param_6_world_decompiler_map /* decompiler maps world here; image uses entry+0x1C */)
{
  // NOTE: Prefer named clean for correct 7-arg stack layout.
  // Body below mirrors Ghidra decompile CF (raw authoritative for CF, not arity).

  int iVar1;
  std::uint32_t in_EAX = 0;
  std::uint32_t uVar2;
  int iVar3;

  if ((param_4 == 9) || (param_4 == 10)) {
    using VFn = std::uint32_t(__thiscall*)(int*, int, std::uint32_t);
    in_EAX = (*reinterpret_cast<VFn*>(*param_1 + 8))(param_1, param_2, param_3);
    if (((char)in_EAX == '\0') &&
        ((in_EAX = param_1[0x15], in_EAX == 0xffffffffu ||
          (*(std::uint32_t*)(*(int*)(*(int*)(*(int*)(param_2 + 4) + 4) + 0xa8 + param_2) + 0xfc) ==
           in_EAX)))) {
      in_EAX = FUN_0060d460(param_1, reinterpret_cast<void*>(param_2),
                            reinterpret_cast<void*>(param_6_world_decompiler_map));
      if ((char)in_EAX != '\0') {
        if ((param_4 == 10) || (param_1[0xd] == 0)) {
          uVar2 = FUN_0060d630(param_1, reinterpret_cast<void*>(param_2),
                               reinterpret_cast<void*>(param_3),
                               reinterpret_cast<void*>(param_6_world_decompiler_map));
          return uVar2;
        }
        iVar1 = param_1[1];
        iVar3 = 0;
        while (true) {
          if (*(int*)(iVar1 + 0x158) == 0) {
            in_EAX = 0;
          } else {
            in_EAX = (*(int*)(iVar1 + 0x15c) - *(int*)(iVar1 + 0x158)) >> 2;
          }
          if ((int)in_EAX <= iVar3) {
            goto LAB_0060e04f;
          }
          if (param_1 == *(int**)(*(int*)(iVar1 + 0x158) + iVar3 * 4)) {
            break;
          }
          iVar3 = iVar3 + 1;
        }
        if (iVar3 != -1) {
          int w = param_6_world_decompiler_map;
          in_EAX = FUN_005319d0(
              reinterpret_cast<void*>(param_2),
              *(std::uint32_t*)(iVar1 + 0x10),
              iVar3,
              *(std::uint32_t*)(w + 0x160),
              *(std::uint32_t*)(w + 0x164),
              *(std::uint32_t*)(w + 0x168),
              *(std::uint32_t*)(w + 0x16c));
        }
      }
    }
  }
LAB_0060e04f:
  return in_EAX & 0xffffff00u;
}
