// =============================================================================
// Item_SumEquippedComponentValues  (FUN_00513580)
// -----------------------------------------------------------------------------
// Stable ID: aa_00513580
// Address:   0x00513580  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer (vendor / item value)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 W19-H
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Sum component/mod value fields (+0x94) for equipped slots on an item.
// Stable ID: aa_00513580
//
// Gate: FUN_004ce940() catalog singleton must be non-null.
// Loop: for i in [0, vtbl+0x60): resolve slot via vtbl+0x5c, lookup by host
//       clonebase type (+0x38), add *(comp+0x94) when found.
//
// Dual: docs/reconstruction/reviews/A|B_aa_00513580_Item_SumEquippedComponentValues.md
//
// Related (not this unit):
//   - Catalog singleton: FUN_004ce940 @ 0x004ce940
//   - Lookups: FUN_00508b60 / 508ac0 / 508bb0 / 508b10 / 508c50 / 508c00
//   - Store sell price: Item_GetStoreSellPrice_Inferred @ 0x005142a0
//   - Sibling price: FUN_00514250

// READABILITY:
//  - Body size: ~78 non-empty decompiler lines; body through 0x00513712.
//  - Control keywords: if×8, goto×5, return×2, do/while, switch.
//  - ABI: thiscall ECX=item, ret int in EAX.

/*
 * Behavioral notes:
 * - Live Ghidra decompile + read_memory 2026-07-29 ≡ raw 2026-07-23.
 * - Double lookup-per-hit preserved (compiler null-check then re-fetch).
 * - Type English and +0x94 product name: Probable / Open.
 * - Runtime / differential verification: OPEN.
 */

#include <cstdint>

extern "C" int FUN_004ce940();
extern "C" int __thiscall FUN_00508b60(int catalog, int slotId);
extern "C" int __thiscall FUN_00508ac0(int catalog, int slotId);
extern "C" int __thiscall FUN_00508bb0(int catalog, int slotId);
extern "C" int __thiscall FUN_00508b10(int catalog, int slotId);
extern "C" int __thiscall FUN_00508c50(int catalog, int slotId);
extern "C" int __thiscall FUN_00508c00(int catalog, int slotId);

// item: CVOG cloned inventory object (ECX / this)
// returns: int sum of resolved component value fields at +0x94
int __thiscall Item_SumEquippedComponentValues(int *item)
{
  // Ghidra: FUN_00513580
  int sum = 0;
  int catalog = FUN_004ce940();
  if (catalog == 0) {
    return 0;
  }

  std::uint32_t i = 0;
  int slotCount = (**(int (**)(void))(*item + 0x60))();
  if (slotCount != 0) {
    do {
      int itemType = *(int *)(item[0x2a] + 0x38); // clonebase+0x38
      std::uint16_t slotId;
      int comp;

      switch (itemType) {
      case 10:
        slotId = (std::uint16_t)(**(int (**)(std::uint32_t))(*item + 0x5c))(i);
        comp = FUN_00508b60(catalog, slotId);
        if (comp != 0) {
          slotId = (std::uint16_t)(**(int (**)(std::uint32_t))(*item + 0x5c))(i);
          comp = FUN_00508b60(catalog, slotId);
          goto ADD_VALUE;
        }
        break;
      case 0xc:
        slotId = (std::uint16_t)(**(int (**)(std::uint32_t))(*item + 0x5c))(i);
        comp = FUN_00508ac0(catalog, slotId);
        if (comp != 0) {
          slotId = (std::uint16_t)(**(int (**)(std::uint32_t))(*item + 0x5c))(i);
          comp = FUN_00508ac0(catalog, slotId);
          goto ADD_VALUE;
        }
        break;
      case 0xe:
        slotId = (std::uint16_t)(**(int (**)(std::uint32_t))(*item + 0x5c))(i);
        comp = FUN_00508bb0(catalog, slotId);
        if (comp != 0) {
          slotId = (std::uint16_t)(**(int (**)(std::uint32_t))(*item + 0x5c))(i);
          comp = FUN_00508bb0(catalog, slotId);
          goto ADD_VALUE;
        }
        break;
      case 0x1c:
        slotId = (std::uint16_t)(**(int (**)(std::uint32_t))(*item + 0x5c))(i);
        comp = FUN_00508b10(catalog, slotId);
        if (comp != 0) {
          slotId = (std::uint16_t)(**(int (**)(std::uint32_t))(*item + 0x5c))(i);
          comp = FUN_00508b10(catalog, slotId);
          goto ADD_VALUE;
        }
        break;
      case 0x44:
        slotId = (std::uint16_t)(**(int (**)(std::uint32_t))(*item + 0x5c))(i);
        comp = FUN_00508c50(catalog, slotId);
        if (comp != 0) {
          slotId = (std::uint16_t)(**(int (**)(std::uint32_t))(*item + 0x5c))(i);
          comp = FUN_00508c50(catalog, slotId);
          goto ADD_VALUE;
        }
        break;
      case 0x46:
        slotId = (std::uint16_t)(**(int (**)(std::uint32_t))(*item + 0x5c))(i);
        comp = FUN_00508c00(catalog, slotId);
        if (comp != 0) {
          slotId = (std::uint16_t)(**(int (**)(std::uint32_t))(*item + 0x5c))(i);
          comp = FUN_00508c00(catalog, slotId);
          goto ADD_VALUE;
        }
        break;
      default:
        break;
      ADD_VALUE:
        sum = sum + *(int *)(comp + 0x94);
        break;
      }

      i = i + 1;
      slotCount = (**(int (**)(void))(*item + 0x60))();
    } while (i < (std::uint32_t)slotCount);
  }
  return sum;
}

// Compatibility alias (scaffold name)
int __thiscall FUN_00513580(int *param_1)
{
  return Item_SumEquippedComponentValues(param_1);
}
