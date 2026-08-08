// =============================================================================
// Character_SumCommodityTfidFiveRowCosts_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005244e0
// Address:   0x005244e0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Ghidra:    FUN_005244e0
// Generated: 2026-08-05 R11-001 dual seal (live decompile + disassemble + read_memory)
// Exactness: Behavior-preserving; not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Sum commodity TFID-row slot costs across a fixed 5-row table.
//   For rowIndex 0..4:
//     if head TFID non-null ((lo & hi) != 0xFFFFFFFF):
//       sum += Character_SumCommodityTfidRowCost_Inferred(this, rowIndex, row)
//     advance row by 0x28 bytes (5 × {lo,hi})
//   return sum (starts at 0; empty/null-head rows contribute 0)
//
// ABI: __thiscall (ECX = Character*); one stack dword (table*); ret 4.
//
// REJECT: scaffold FUN_005244e0 bare decompiler signature (drops this / ret 4);
//         claim that null-head rows still add base-1; claim pure cdecl; claim
//         outer rowIndex is used inside the per-row cost formula (it is dead).
//
// Callee (dualed WQ-008): Character_SumCommodityTfidRowCost_Inferred @ 0x00522710
// Sibling (dualed R10-036): Character_CalcCommodityTierFreeScore_Inferred @ 0x00522780
//   — free-score path for ONE tier row; this unit is multi-row cost sum only.

#include <cstdint>

struct Character;

// Parent dual @ 0x00522710 — thiscall Character*, ret 8
extern "C" int __thiscall Character_SumCommodityTfidRowCost_Inferred(
    Character* self,
    uint32_t /*unused_row_or_tier*/,
    const uint32_t* tfidRow /* 5 × {lo, hi} */);

int __thiscall Character_SumCommodityTfidFiveRowCosts_Inferred(
    Character* self,
    const uint32_t* table /* 5 rows × 10 dwords; stride 0x28 */)
{
  int sum = 0;
  int rowIndex = 0;
  const uint32_t* row = table;

  do {
    uint32_t lo = row[0];
    uint32_t hi = row[1];

    // null head TFID: both dwords 0xFFFFFFFF ⇔ (lo & hi) == 0xFFFFFFFF
    if ((lo & hi) != 0xFFFFFFFFu) {
      sum += Character_SumCommodityTfidRowCost_Inferred(
          self, static_cast<uint32_t>(rowIndex), row);
    }

    ++rowIndex;
    row += 10; // ADD EDI, 0x28
  } while (rowIndex < 5);

  return sum;
}
