// =============================================================================
// FUN_005244e0 — machine twin of Character_SumCommodityTfidFiveRowCosts_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005244e0
// Address:   0x005244e0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Ghidra:    FUN_005244e0
// Generated: 2026-08-05 R11-001 dual seal (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow + ABI seals.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// Canonical name: Character_SumCommodityTfidFiveRowCosts_Inferred
// See: Character_SumCommodityTfidFiveRowCosts_Inferred.cpp
//
// PURPOSE: Sum dualed Character_SumCommodityTfidRowCost over 5 table rows
// (stride 0x28), skipping rows whose head TFID is null (lo&hi == -1).
//
// ABI: __thiscall ECX=Character*; stack table*; RET 0x4; EAX=sum.
// Body: 0x005244e0–0x00524518 inclusive (57 B).

#include <cstdint>

struct Character;

// FUN_00522710 — dualed Character_SumCommodityTfidRowCost_Inferred
extern "C" int __thiscall FUN_00522710(Character* self,
                                       uint32_t unused,
                                       const uint32_t* row);

extern "C" int __thiscall FUN_005244e0(Character* self, const uint32_t* param_1)
{
  int iVar2 = 0; // sum (EBX)
  int iVar3 = 0; // row index (ESI)
  const uint32_t* row = param_1;

  do {
    if ((row[0] & row[1]) != 0xFFFFFFFFu) {
      int iVar1 = FUN_00522710(self, static_cast<uint32_t>(iVar3), row);
      iVar2 = iVar2 + iVar1;
    }
    iVar3 = iVar3 + 1;
    row = row + 10; // +0x28
  } while (iVar3 < 5);

  return iVar2;
}
