// =============================================================================
// FUN_0060e800 — twin of CVOGObjectiveRequirement_Patrol_EventAction_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0060e800
// Address:   0x0060e800  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-08-05 MEGA-031 (machine-name twin; prefer named clean)
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// Named clean:
//   docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_Patrol_EventAction_Inferred.cpp
//
// PURPOSE (brief): Patrol vtable+0x04 event Action — AutoComplete/AutoFail
// distance + AutoFail flag; events 0x0B / 0x0C; RET 0x1C; FailMission no drain.
// =============================================================================

#include <cstdint>
#include <cmath>

static constexpr float DAT_00aaa688 = 5.0f;
extern "C" float g_flOne;
extern "C" std::uint32_t __thiscall CVOGReaction_FailMission(int character, std::uint32_t missionId);

// Ghidra machine name twin — same body as named clean.
std::uint8_t __thiscall FUN_0060e800(
    int* param_1,
    int param_2,
    int param_3,
    int param_4,
    int /*param_5*/,
    int /*param_6*/,
    int /*param_7*/,
    int* in_stack_entity)
{
  if (param_4 == 0x0C) {
    if (*(char*)((char*)param_1 + 0x18) != 0) {
      auto* mid = *reinterpret_cast<std::uint32_t**>(*(int*)((char*)param_1 + 4) + 0x14c);
      CVOGReaction_FailMission(param_2, *mid);
      return 0;
    }
    return 0;
  }

  if (param_4 != 0x0B || in_stack_entity == nullptr) {
    return 0;
  }

  int targetCount = *(int*)((char*)param_1 + 0xd0);
  int laps = *(int*)((char*)param_1 + 0x24);
  unsigned slot = *(unsigned char*)((char*)param_1 + 8);
  float* pf = reinterpret_cast<float*>(param_3 + 4 + (int)slot * 4);
  int padCount = (int)*pf;
  if (padCount >= laps * targetCount) {
    return 0;
  }

  int idx = padCount % targetCount;
  if (in_stack_entity[0x58] != *(int*)((char*)param_1 + 0x30 + idx * 8) ||
      in_stack_entity[0x59] != *(int*)((char*)param_1 + 0x34 + idx * 8)) {
    return 0;
  }

  (*(void(__thiscall**)(int*))(*in_stack_entity + 0x144))(in_stack_entity);
  float fVar2 = *(float*)((char*)in_stack_entity + 0x80);
  float fVar3 = *(float*)((char*)in_stack_entity + 0x84);
  float fVar4 = *(float*)((char*)in_stack_entity + 0x88);

  int base = *(int*)(*(int*)(param_2 + 4) + 4);
  int* complex = reinterpret_cast<int*>(base + 4 + param_2);
  float* playerPos = (*(float*(__thiscall**)(int*))(*complex + 0x1a0))(complex);

  fVar2 = std::sqrt((fVar2 - playerPos[0]) * (fVar2 - playerPos[0]) +
                    (fVar3 - playerPos[1]) * (fVar3 - playerPos[1]) +
                    (fVar4 - playerPos[2]) * (fVar4 - playerPos[2]));

  if (*(char*)((char*)param_1 + 0x10) != 0 &&
      fVar2 < *(float*)((char*)param_1 + 0x14) + DAT_00aaa688) {
    *pf = *pf + g_flOne;
    return 1;
  }

  if (*(char*)((char*)param_1 + 0x18) != 0) {
    if (fVar2 > *(float*)((char*)param_1 + 0x1c) - DAT_00aaa688) {
      auto* mid = *reinterpret_cast<std::uint32_t**>(*(int*)((char*)param_1 + 4) + 0x14c);
      CVOGReaction_FailMission(param_2, *mid);
    } else {
      char gate = (*(char(__thiscall**)(int*))(*complex + 0x198))(complex);
      if (gate != 0) {
        auto* mid = *reinterpret_cast<std::uint32_t**>(*(int*)((char*)param_1 + 4) + 0x14c);
        CVOGReaction_FailMission(param_2, *mid);
      }
    }
  }
  return 0;
}
