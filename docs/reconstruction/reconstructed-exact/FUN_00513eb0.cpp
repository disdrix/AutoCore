// =============================================================================
// FUN_00513eb0  (machine twin of Item_TryConcatStackWithPeer)
// -----------------------------------------------------------------------------
// Stable ID: aa_00513eb0
// Address:   0x00513eb0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 MEGA-012 — keep FUN_* twin for ID lookup
// Canonical: Item_TryConcatStackWithPeer.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_00512670(int* item);

// Ghidra signature shape preserved (int* thiscall + peer).
uint32_t __thiscall FUN_00513eb0(int* param_1, int* param_2)
{
  uint16_t uVar1;
  int iVar2;
  uint32_t uVar4;
  int iVar5;
  int iVar6;
  uint16_t uVar7;

  if ((param_2 != nullptr) &&
      (*(int*)(param_2[0x2a] + 0x34) == *(int*)(param_1[0x2a] + 0x34))) {
    uVar1 = *(uint16_t*)(*(int*)(param_1[0x2a] + 0x3c) + 0x4bc);
    if ((uVar1 != 0) && (uVar1 != 0xffff)) {
      uVar4 = (uint32_t)*(uint16_t*)(param_2 + 0x60) +
              (uint32_t)*(uint16_t*)(param_1 + 0x60);
      if (uVar4 <= uVar1) {
        *(int16_t*)(param_1 + 0x60) = (int16_t)uVar4;
        FUN_00512670(param_1);
        return 1;
      }
      // retail: CDQ; IDIV limit → remainder; 0 → full limit
      uVar7 = (uint16_t)(uVar4 % (uint32_t)uVar1);
      if ((int)(uVar4 % (uint32_t)uVar1) == 0) {
        uVar7 = uVar1;
      }
      *(uint16_t*)(param_1 + 0x60) = uVar7;
    }
    iVar2 = *param_1;
    iVar5 = (*(int(__thiscall**)(int*))(*param_2 + 0x25c))(param_2);
    iVar6 = (*(int(__thiscall**)(int*))(*param_1 + 0x25c))(param_1);
    (*(void(__thiscall**)(int*, int))(iVar2 + 0x260))(param_1, iVar5 + iVar6);
    FUN_00512670(param_1);
    return 1;
  }
  return 0;
}
