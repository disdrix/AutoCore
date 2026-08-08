// =============================================================================
// CVOGObjectiveRequirement_Patrol_EventAction_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0060e800
// Address:   0x0060e800  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-08-05 MEGA-031 dual seal (live Ghidra decompile + disasm + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + ABI corrections.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Patrol requirement **event-driven Action** at vtable+0x04 (PTR_FUN_009e0404).
//   Handles AutoComplete / AutoFail distance (and AutoFail flag-only event):
//     event 0x0C: if AutoFail (req+0x18) → FailMission(missionId); return 0
//     event 0x0B: match current pad GenericTargetCOID to entity; 3D distance vs
//                 AutoCompleteDistance / AutoFailDistance with ±5.0 slop
//                 (DAT_00aaa688). AutoComplete success: slot float += 1.0, return 1.
//
// CLASS:  CVOGObjectiveRequirement_Patrol (ctor FUN_0060e090 installs vtable;
//         type dword req+0x0c = 9; GetFlags dual seals field dictionary)
// ABI:    __thiscall; 7 stack args; ret 0x1C; AL = 0|1
//
// DO NOT CONFUSE WITH:
//   CVOGObjectiveRequirement_Patrol_Action @ 0x0060e120 (vtable+0x10 progress fraction)
//   CVOGObjectiveRequirement_Patrol_Eval   @ 0x0060e0f0 (vtable+0x08 complete gate)
//   Shared progress toast Action            @ 0x00637de0 (vtable+0x20)
//
// CALLEES: CVOGReaction_FailMission (×2; no drain); entity vtbl+0x144;
//          character-complex vtbl+0x1a0 (pos), +0x198 (bool gate)
// =============================================================================

#include <cstdint>
#include <cmath>

// Image constants (read_memory 2026-08-05)
static constexpr float kDistanceSlop = 5.0f;  // DAT_00aaa688 @ 0x00aaa688
extern "C" float g_flOne;                     // 1.0f @ 0x00a0f2a0

extern "C" std::uint32_t __thiscall CVOGReaction_FailMission(int character, std::uint32_t missionId);

// this = Patrol requirement*
// character  = host for FailMission + position complex
// progress   = objective state node (slot floats at +4+slot*4)
// eventType  = 0x0B pad-proximity / 0x0C fail-flag (decomp typed float* — wrong)
// entity     = world object (COID @ +0x160/+0x164; pos @ +0x80/+0x84/+0x88)
std::uint8_t __thiscall CVOGObjectiveRequirement_Patrol_EventAction_Inferred(
    int* thisReq,
    int character,
    int progress,
    int eventType,
    int /*unused14*/,
    int /*unused18*/,
    int /*unused1c*/,
    int* entity)
{
  // ---- event 0x0C: AutoFail flag path (no distance) ----
  if (eventType == 0x0C) {
    if (*reinterpret_cast<char*>(reinterpret_cast<char*>(thisReq) + 0x18) != 0) {
      auto* nameNode = *reinterpret_cast<std::uint32_t**>(
          *reinterpret_cast<int*>(reinterpret_cast<char*>(thisReq) + 4) + 0x14c);
      CVOGReaction_FailMission(character, *nameNode);
      return 0;
    }
    return 0;
  }

  // ---- event 0x0B: pad proximity AutoComplete / AutoFail-distance ----
  if (eventType != 0x0B || entity == nullptr) {
    return 0;
  }

  const int targetCount = *reinterpret_cast<int*>(reinterpret_cast<char*>(thisReq) + 0xd0);
  const int laps        = *reinterpret_cast<int*>(reinterpret_cast<char*>(thisReq) + 0x24);
  const unsigned slot   = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(thisReq) + 8);
  float* slotFloat = reinterpret_cast<float*>(progress + 4 + static_cast<int>(slot) * 4);
  const int padCount = static_cast<int>(*slotFloat);

  if (padCount >= laps * targetCount) {
    return 0;
  }

  const int idx = padCount % targetCount;
  const auto* targetLo = reinterpret_cast<int*>(reinterpret_cast<char*>(thisReq) + 0x30 + idx * 8);
  const auto* targetHi = reinterpret_cast<int*>(reinterpret_cast<char*>(thisReq) + 0x34 + idx * 8);

  // entity COID pair at +0x160 / +0x164 (decomp entity[0x58]/[0x59])
  if (entity[0x58] != *targetLo || entity[0x59] != *targetHi) {
    return 0;
  }

  // entity virtual refresh
  (*(void(__thiscall**)(int*))(*entity + 0x144))(entity);

  const float ex = *reinterpret_cast<float*>(reinterpret_cast<char*>(entity) + 0x80);
  const float ey = *reinterpret_cast<float*>(reinterpret_cast<char*>(entity) + 0x84);
  const float ez = *reinterpret_cast<float*>(reinterpret_cast<char*>(entity) + 0x88);

  // character nested complex at (*( *(character+4)+4 ) + character + 4)
  int base = *reinterpret_cast<int*>(*reinterpret_cast<int*>(character + 4) + 4);
  int* complex = reinterpret_cast<int*>(base + 4 + character);
  float* playerPos =
      (*(float*(__thiscall**)(int*))(*complex + 0x1a0))(complex);

  const float dx = ex - playerPos[0];
  const float dy = ey - playerPos[1];
  const float dz = ez - playerPos[2];
  const float dist = std::sqrt(dx * dx + dy * dy + dz * dz);

  // AutoComplete: inside (AutoCompleteDistance + 5.0)
  if (*reinterpret_cast<char*>(reinterpret_cast<char*>(thisReq) + 0x10) != 0) {
    const float completeDist =
        *reinterpret_cast<float*>(reinterpret_cast<char*>(thisReq) + 0x14);
    if (dist < completeDist + kDistanceSlop) {
      *slotFloat = *slotFloat + g_flOne;
      return 1;
    }
  }

  // AutoFail: outside (AutoFailDistance - 5.0), or inside-band with complex+0x198
  if (*reinterpret_cast<char*>(reinterpret_cast<char*>(thisReq) + 0x18) != 0) {
    const float failDist =
        *reinterpret_cast<float*>(reinterpret_cast<char*>(thisReq) + 0x1c);
    bool doFail = false;
    if (dist > failDist - kDistanceSlop) {
      doFail = true;
    } else {
      char gate = (*(char(__thiscall**)(int*))(*complex + 0x198))(complex);
      if (gate != 0) {
        doFail = true;
      }
    }
    if (doFail) {
      auto* nameNode = *reinterpret_cast<std::uint32_t**>(
          *reinterpret_cast<int*>(reinterpret_cast<char*>(thisReq) + 4) + 0x14c);
      CVOGReaction_FailMission(character, *nameNode);
    }
  }

  return 0;
}
