// =============================================================================
// FUN_00513fc0  →  Item_RequiresBindOrTradeLock
// -----------------------------------------------------------------------------
// Stable ID: aa_00513fc0
// Address:   0x00513fc0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-08-05 MEGA-050
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Scaffold twin of Item_RequiresBindOrTradeLock.
// See: docs/reconstruction/reconstructed-exact/Item_RequiresBindOrTradeLock.cpp
// Dual: docs/reconstruction/reviews/A|B_aa_00513fc0_Item_RequiresBindOrTradeLock.md
//
// Retires mis-seed: Named_CalleeOf_Client_OnVehicleSwitchFailure_00513fc0
// (that parent is only one of four callers; role is bind/trade-lock predicate).

// READABILITY:
//  - Control flow preserved from live Ghidra decompile 2026-08-05.
//  - ABI corrected from asm: thiscall ECX=item + 2 stack COID dwords + RET 8.

#include <cstdint>

extern "C" int *__thiscall CVOGReaction_ResolveObjectTarget(
    void *reaction, int mode, std::uint32_t coid_lo, std::uint32_t coid_hi);

// Decompiler-shaped entry (param order = stack after this):
//   FUN_00513fc0(coid_lo, coid_hi) with ECX=item
bool __thiscall FUN_00513fc0(int *item, std::uint32_t param_1, std::uint32_t param_2)
{
  short sVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  bool bVar5;

  void *host = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(item) + 0xa4);
  void *reaction =
      *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(host) + 0xe4e8);

  piVar3 = CVOGReaction_ResolveObjectTarget(reaction, 1, param_1, param_2);
  bVar5 = false;
  if (piVar3 == nullptr) {
    return false;
  }
  iVar4 = piVar3[0x2a];
  iVar2 = *reinterpret_cast<int *>(reinterpret_cast<std::uint8_t *>(iVar4) + 0x38);
  if (((((iVar2 == 0xc) || (iVar2 == 0x1c)) || (iVar2 == 10)) ||
       ((iVar2 == 0x10 || (iVar2 == 0xe)))) ||
      ((iVar2 == 6 &&
        ((sVar1 = *reinterpret_cast<short *>(
              *reinterpret_cast<int *>(reinterpret_cast<std::uint8_t *>(iVar4) + 0x3c) + 0x3f4),
          sVar1 == 10 || (sVar1 == 0xb)))))) {
    bVar5 = 1 < *reinterpret_cast<short *>(
                    *reinterpret_cast<int *>(reinterpret_cast<std::uint8_t *>(iVar4) + 0x3c) +
                    0x4b8);
    iVar4 = (*reinterpret_cast<int (__thiscall **)(int *)>(*piVar3 + 0x60))(piVar3);
    if (iVar4 != 0) {
      return true;
    }
  }
  return bVar5;
}
