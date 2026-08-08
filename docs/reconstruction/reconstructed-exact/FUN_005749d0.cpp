// =============================================================================
// FUN_005749d0  (twin of VehicleCrew_ContainsMember_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005749d0
// Address:   0x005749d0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-04 WQ9R-A dual
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Named clean: VehicleCrew_ContainsMember_Inferred.cpp
// Dual: reviews/A|B_aa_005749d0_VehicleCrew_ContainsMember_Inferred.md
//
// Note: decompiler CONCAT31 / uint3 returns replaced with explicit 0/1 AL bool
// matching epilogue bytes (32 C0 / B0 01 + C2 04 00).

#include <cstdint>

extern "C" int __thiscall FUN_005749d0(int param_1, int param_2)
{
  int iVar1;
  int iVar2;
  unsigned char bVar4;
  unsigned uVar5;

  if (param_2 == 0) {
    return 0;
  }
  iVar1 = *(int*)(*(int*)(param_2 + 4) + 4);
  uVar5 = 0;
  for (;;) {
    iVar2 = static_cast<int>(uVar5 * 0x10);
    if ((*(int*)(iVar1 + 0x164 + param_2) == *(int*)(iVar2 + 0x198 + param_1)) &&
        (*(int*)(iVar1 + 0x168 + param_2) == *(int*)(iVar2 + 0x19c + param_1))) {
      return 1;
    }
    bVar4 = static_cast<unsigned char>(static_cast<unsigned char>(uVar5) + 1);
    uVar5 = bVar4;
    if (3 < bVar4) {
      return 0;
    }
  }
}
