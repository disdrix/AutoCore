// =============================================================================
// FUN_00522060  — twin of Character_CountType1aCraftableBatches
// -----------------------------------------------------------------------------
// Stable ID: aa_00522060
// Address:   0x00522060–0x00522203 inclusive (420 B / 0x1A4)
// Module:    autoassault.exe (image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 MEGA-002 dual seal (machine-name twin)
// Exactness: Behavior-preserving; see named clean for full commentary.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Prefer: docs/reconstruction/reconstructed-exact/Character_CountType1aCraftableBatches.cpp
// Retired: Named_CalleeOf_Inv_Client_ValidateCraftAffordability_00522060.cpp
//
// ABI: __thiscall RET 0x10; ECX=character; stack item*, out*, mode, simpleFlag; AL bool.

#include <cstdint>

extern int __thiscall InventoryGrid_CountItemsByCbid(void *grid, int itemCbid, char includeBroken);
extern char __fastcall ItemDef_CountConfiguredModSlots_Inferred(void *blob);

bool __thiscall FUN_00522060(
    void *param_1,
    void *param_2,
    int *param_3,
    char param_4,
    char param_5)
{
  void *cargoHolder;
  void *cargo;
  void *locker;
  std::uint8_t *blob;
  int primaryCbid;
  int primaryHave;
  int cost;
  int nSlots;
  int minHave;
  int i;
  int slotCbid;
  int secondaryHave;
  char modeNot2;

  *param_3 = 0;

  cargoHolder = *reinterpret_cast<void **>(reinterpret_cast<char *>(param_1) + 0x250);
  if (cargoHolder == nullptr) {
    return false;
  }
  cargo = *reinterpret_cast<void **>(reinterpret_cast<char *>(cargoHolder) + 0x2b0);
  if (cargo == nullptr) {
    return false;
  }
  locker = *reinterpret_cast<void **>(reinterpret_cast<char *>(param_1) + 0xcbc);
  if (locker == nullptr) {
    return false;
  }
  if (*reinterpret_cast<int *>(reinterpret_cast<char *>(param_2) + 0x38) != 0x1a) {
    return false;
  }

  blob = *reinterpret_cast<std::uint8_t **>(reinterpret_cast<char *>(param_2) + 0x3c);
  if (blob == nullptr) {
    return false;
  }

  modeNot2 = static_cast<char>(param_4 != 2);

  if (param_5 != 0) {
    int simpleCbid = *reinterpret_cast<int *>(blob + 0x4c0);
    *param_3 = InventoryGrid_CountItemsByCbid(cargo, simpleCbid, 0);
    *param_3 += InventoryGrid_CountItemsByCbid(locker, simpleCbid, 0);
    return *param_3 != 0;
  }

  if (param_4 != 1 && *reinterpret_cast<char *>(blob + 0x4d4) > 0) {
    primaryCbid = *reinterpret_cast<int *>(blob + 0x4d0);
    primaryHave = InventoryGrid_CountItemsByCbid(cargo, primaryCbid, 0);
    primaryHave += InventoryGrid_CountItemsByCbid(locker, primaryCbid, 0);
    cost = static_cast<int>(*reinterpret_cast<char *>(blob + 0x4d4));
    if (primaryHave >= cost) {
      *param_3 += primaryHave / cost;
    }
  }

  if (modeNot2 != 0) {
    nSlots = static_cast<int>(ItemDef_CountConfiguredModSlots_Inferred(blob));
    if (nSlots > 0) {
      minHave = -1;
      for (i = 0; i < nSlots; ++i) {
        slotCbid = *reinterpret_cast<int *>(blob + 0x498 + 4 * i);
        if (slotCbid != -1) {
          secondaryHave = InventoryGrid_CountItemsByCbid(cargo, slotCbid, 0);
          secondaryHave += InventoryGrid_CountItemsByCbid(locker, slotCbid, 0);
          if (minHave == -1 || secondaryHave <= minHave) {
            minHave = secondaryHave;
          }
          if (secondaryHave < 1) {
            break;
          }
        }
      }
      if (minHave > 0) {
        *param_3 += minHave;
      }
    }
  }

  return *param_3 > 0;
}
