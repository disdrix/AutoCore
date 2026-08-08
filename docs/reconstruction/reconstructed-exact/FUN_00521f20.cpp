// =============================================================================
// FUN_00521f20  (clean twin of Character_ComputeTinkerSuccessChance_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00521f20
// Address:   0x00521f20–0x00521fe7 inclusive (200 B / 0xC8)
// Module:    autoassault.exe (image base 0x400000)
// System:    inventory-transfer / tinker success chance
// Generated: 2026-08-05 R10-035 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named twin: Character_ComputeTinkerSuccessChance_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" std::uint8_t __thiscall FUN_00521eb0(void *character);

// Shared constants (see named twin / raw re-verify for VAs).
extern float g_flOne;              // 0x00a0f2a0 = 1.0
extern float g_flZero;             // 0x00a0f518 = 0.0
extern float DAT_00a0f720;         // 0.4
extern float DAT_00a0f728;         // 0.35
extern float g_flOverheatCoolFrac; // 0x00a0f714 = 0.3
extern float DAT_00a0f704;         // 0.25
extern float DAT_009ceea8;         // 0.2
extern float DAT_00aaa8f4;         // 0.04

// __thiscall ECX=character; stack item*, kit*; float ST0; RET 8
// (Ghidra may label params generically; roles sealed by caller+body.)
extern "C" float __thiscall FUN_00521f20(int character, int *item, int kit)
{
  char cVar1;
  int iVar2;
  // Not a true extra-out: machine keeps need (=slots+1) in DL across CALL.
  unsigned char need_dl;
  float local_4;

  if (0 < *(int *)(character + 0x6b4)) {
    // Assembly: CMP [this+0x6b4],1 / JL continue → return 1 when >= 1
    return g_flOne;
  }
  local_4 = 0.0f;
  cVar1 = (**(char (***)())(*(int *)item + 0x8c))();
  need_dl = static_cast<unsigned char>(cVar1 + 1);
  iVar2 = static_cast<int>(FUN_00521eb0(reinterpret_cast<void *>(character)));
  if (static_cast<int>(need_dl) <= iVar2) {
    switch (static_cast<unsigned>(need_dl)) {
    case 1:
      local_4 = DAT_00a0f720;
      break;
    case 2:
      local_4 = DAT_00a0f728;
      break;
    case 3:
      local_4 = g_flOverheatCoolFrac;
      break;
    case 4:
      local_4 = DAT_00a0f704;
      break;
    case 5:
      local_4 = DAT_009ceea8;
      break;
    default:
      break;
    }
    return static_cast<float>(static_cast<int>(static_cast<short>(
               static_cast<unsigned short>(*(unsigned char *)(character + 0x59b)) +
               static_cast<unsigned short>(need_dl) * static_cast<unsigned short>(-2) +
               *(short *)(kit + 0xb0)))) *
               DAT_00aaa8f4 +
           local_4;
  }
  return g_flZero;
}
