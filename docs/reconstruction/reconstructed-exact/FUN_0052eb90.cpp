// =============================================================================
// FUN_0052eb90  (scaffold twin of Character_Craft_HasMatchingStationInRange_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052eb90
// Address:   0x0052eb90  (autoassault.exe, image base 0x400000)
// Body:      0x0052eb90–0x0052ed73 exclusive (483 B / 0x1E3)
// System:    inventory-transfer — craft station proximity gate
// Generated: 2026-08-05 R12-021 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: NEVER claimed.
// Named clean: Character_Craft_HasMatchingStationInRange_Inferred.cpp
// =============================================================================

/*
 * Behavioral notes (R12-021):
 * - thiscall ECX=character, stack craftObject*, AL bool, RET 0x4.
 * - Bypass: character+0x6b4 > 0 OR DisciplineDef map miss → true.
 * - Else scan char-object TFID vector; surface distance <= 50.0f;
 *   subtype +0x3f4 in {0xD,0xE,0xF} with matching DisciplineDef tail flags.
 * - Callees: 0052b040 (dualed), 004e5810, CVOGReaction_ResolveObjectTarget,
 *   0053e510 (dualed SurfaceDistance3D), operator_delete.
 */

#include <cstdint>

extern "C" uint8_t __cdecl FUN_0052b040(uint32_t disciplineId, void* out0x1FC);
extern "C" int __thiscall FUN_004e5810(int object, void* outVec);
extern "C" int* __stdcall CVOGReaction_ResolveObjectTarget(int zero_or_ctx, uint32_t lo, uint32_t hi);
extern "C" long double __thiscall FUN_0053e510(void* other);
extern "C" void __cdecl operator_delete(void* p);
extern float DAT_00a0f524; // 50.0f

uint8_t __thiscall FUN_0052eb90(int param_1, int param_2)
{
  short sVar1;
  char cVar2;
  int iVar3;
  uint32_t uVar4;
  int* piVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  bool bVar8;
  long double fVar9;
  uint8_t local_21d;
  uint8_t local_21c[4];
  void* local_218;
  uint32_t local_214;
  uint32_t local_210;
  uint8_t local_20c[4];
  void* local_208;
  uint32_t local_204;
  uint32_t local_200;
  uint8_t local_1fc[496];
  int iStack_c; // DisciplineDef payload +0x1F0 (station flag 0xD)
  int iStack_8; // +0x1F4 (0xE)
  int iStack_4; // +0x1F8 (0xF)

  if ((*reinterpret_cast<int*>(
           *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 4) + 4) + 0xa8 + param_1) == 0) ||
      (param_2 == 0)) {
    return 0;
  }

  if ((0 < *reinterpret_cast<int*>(param_1 + 0x6b4)) ||
      (cVar2 = static_cast<char>(FUN_0052b040(
           *reinterpret_cast<uint32_t*>(
               *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_2 + 0xa8) + 0x3c) + 0x4ac),
           local_1fc)),
       cVar2 == '\0')) {
    return 1;
  }

  local_21d = 0;
  local_218 = nullptr;
  local_214 = 0;
  local_210 = 0;
  local_208 = nullptr;
  local_204 = 0;
  local_200 = 0;

  do {
    iVar3 = FUN_004e5810(
        *reinterpret_cast<int*>(
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 4) + 4) + 0xa8 + param_1),
        local_21c);
    if (*reinterpret_cast<int*>(iVar3 + 4) == 0) {
      uVar4 = 0;
    } else {
      uVar4 = static_cast<uint32_t>(
          (*reinterpret_cast<int*>(iVar3 + 8) - *reinterpret_cast<int*>(iVar3 + 4)) >> 3);
    }
    uVar7 = static_cast<uint32_t>(local_21d);
    if (local_218 != nullptr) {
      operator_delete(local_218);
    }
    local_218 = nullptr;
    local_214 = 0;
    local_210 = 0;
    if (uVar4 <= uVar7) {
      return 0;
    }

    iVar3 = FUN_004e5810(
        *reinterpret_cast<int*>(
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 4) + 4) + 0xa8 + param_1),
        local_20c);

    // Live: ECX = charObj+0xe4e8 before CALL; decompiler shows stack form.
    piVar5 = CVOGReaction_ResolveObjectTarget(
        0,
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(iVar3 + 4) + uVar7 * 8),
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(iVar3 + 4) + 4 + uVar7 * 8));

    if (local_208 != nullptr) {
      operator_delete(local_208);
    }
    local_208 = nullptr;
    local_204 = 0;
    local_200 = 0;

    if ((piVar5 != nullptr) &&
        (iVar3 = (**(int(__thiscall***)(int*))(*piVar5 + 0x1c8))(piVar5), iVar3 != 0)) {
      iVar3 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 4) + 4);
      uVar6 = (**(uint32_t(__thiscall***)(int*))(*piVar5 + 0x1c8))(piVar5);
      (**(void(__thiscall***)(int, uint32_t))(
          *reinterpret_cast<int*>(iVar3 + 4 + param_1) + 0x19c))(iVar3 + 4 + param_1, uVar6);
      // Live: ECX = return of vtbl+0x19c; stack = pose from vtbl+0x1c8
      fVar9 = FUN_0053e510(reinterpret_cast<void*>(static_cast<uintptr_t>(uVar6)));
      if (fVar9 <= static_cast<long double>(DAT_00a0f524)) {
        sVar1 = *reinterpret_cast<short*>(
            *reinterpret_cast<int*>(piVar5[0x2a] + 0x3c) + 0x3f4);
        if (sVar1 == 0xd) {
          bVar8 = (iStack_c == 0);
        } else if (sVar1 == 0xe) {
          bVar8 = (iStack_8 == 0);
        } else {
          if (sVar1 != 0xf) {
            goto LAB_0052ed3e;
          }
          bVar8 = (iStack_4 == 0);
        }
        if (!bVar8) {
          return 1;
        }
      }
    }
  LAB_0052ed3e:
    local_21d = static_cast<uint8_t>(local_21d + 1);
  } while (true);
}
