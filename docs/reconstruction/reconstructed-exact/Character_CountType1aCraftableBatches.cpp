// =============================================================================
// Character_CountType1aCraftableBatches  (FUN_00522060)
// -----------------------------------------------------------------------------
// Stable ID: aa_00522060
// Address:   0x00522060–0x00522203 inclusive (420 B / 0x1A4); CC pad after
// Module:    autoassault.exe (image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 MEGA-002 dual seal
//            (decompile + disassemble_function + read_memory + callers/xrefs)
// Exactness: Behavior-preserving rewrite from decompile + body bytes.
//            Dual-grid this pointers restored from assembly (decompiler hides them).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Character method: count how many type-0x1a craft batches the player can
//   afford from cargo + locker inventories. Writes the batch total to *outBatches
//   and returns whether that total is positive.
//
//   Mode (param_4):
//     0 — primary bank (+0x4d0/+0x4d4) AND secondary list (+0x498…)
//     1 — skip primary; secondary only
//     2 — primary only; skip secondary
//   simpleFlag (param_5) ≠ 0:
//     early path — sum counts of blob+0x4c0 only (no floor-div batch math)
//
//   Primary contribution: floor( (cargo+locker count of CBID@+0x4d0) / cost@+0x4d4 )
//   Secondary contribution: min count across non-(-1) slots, ADDED to primary
//   (not min'd with it) — sealed retail behavior.
//
// Parent craft consumer: CVOGCharacter_TryType1aCraft_Inferred (0x005316c0).
// Retired scaffold name: Named_CalleeOf_Inv_Client_ValidateCraftAffordability_00522060.
//
// ABI: MSVC __thiscall, RET 0x10
//   ECX     character*
//   stack0  type1a object*   (type dword @ +0x38, blob* @ +0x3c)
//   stack1  int* outBatches
//   stack2  char mode
//   stack3  char simpleFlag
// Returns: bool in AL
// =============================================================================

#include <cstdint>

// aa_005711c0 — sum stack qty for CBID in one inventory grid (includeBroken=0)
extern int __thiscall InventoryGrid_CountItemsByCbid(void *grid, int itemCbid, char includeBroken);

// aa_00599dd0 — count of non-(-1) dwords in blob+0x498..+0x4a8 (0..5)
// Registry name: ItemDef_CountConfiguredModSlots_Inferred (craft reuses as secondary list)
extern char __fastcall ItemDef_CountConfiguredModSlots_Inferred(void *blob);

bool __thiscall Character_CountType1aCraftableBatches(
    void *self,
    void *type1aObject,
    int *outBatches,
    char mode,
    char simpleFlag)
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

  *outBatches = 0;

  cargoHolder = *reinterpret_cast<void **>(reinterpret_cast<char *>(self) + 0x250);
  if (cargoHolder == nullptr) {
    return false;
  }
  cargo = *reinterpret_cast<void **>(reinterpret_cast<char *>(cargoHolder) + 0x2b0);
  if (cargo == nullptr) {
    return false;
  }
  locker = *reinterpret_cast<void **>(reinterpret_cast<char *>(self) + 0xcbc);
  if (locker == nullptr) {
    return false;
  }
  if (*reinterpret_cast<int *>(reinterpret_cast<char *>(type1aObject) + 0x38) != 0x1a) {
    return false;
  }

  blob = *reinterpret_cast<std::uint8_t **>(reinterpret_cast<char *>(type1aObject) + 0x3c);
  if (blob == nullptr) {
    return false;
  }

  // Assembly: CMP mode,2 / SETNZ → stack slot used by secondary gate
  modeNot2 = static_cast<char>(mode != 2);

  // ---- simple path (simpleFlag ≠ 0): CBID at blob+0x4c0 only ----
  if (simpleFlag != 0) {
    int simpleCbid = *reinterpret_cast<int *>(blob + 0x4c0);
    *outBatches = InventoryGrid_CountItemsByCbid(cargo, simpleCbid, 0);
    *outBatches += InventoryGrid_CountItemsByCbid(locker, simpleCbid, 0);
    return *outBatches != 0;
  }

  // ---- primary bank: skip when mode == 1 or cost byte <= 0 ----
  if (mode != 1 && *reinterpret_cast<char *>(blob + 0x4d4) > 0) {
    primaryCbid = *reinterpret_cast<int *>(blob + 0x4d0);
    // First call often reuses cargo pointer left in ECX from the guard (asm).
    primaryHave = InventoryGrid_CountItemsByCbid(cargo, primaryCbid, 0);
    primaryHave += InventoryGrid_CountItemsByCbid(locker, primaryCbid, 0);
    cost = static_cast<int>(*reinterpret_cast<char *>(blob + 0x4d4));
    if (primaryHave >= cost) {
      *outBatches += primaryHave / cost;
    }
  }

  // ---- secondary list: skip when mode == 2 (modeNot2 == 0) ----
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
        *outBatches += minHave; // ADD with primary — not min(primary, secondary)
      }
    }
  }

  return *outBatches > 0;
}
